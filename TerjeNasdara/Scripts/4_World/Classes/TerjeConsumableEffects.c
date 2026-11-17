// Instant effects for the vanilla 1.30 desert conditions. No new player records are stored.
//   medSilicosisRemove       agents of eAgents.SILICOSIS removed per unit (vanilla has no cure)
//   medEyeIrritationRemove   agents of eAgents.EYES_IRRITATION removed per unit
//   medThermalBiasRemove     thermal bias (heat stroke driver, 0..1) removed per unit
//   medThermalBiasResistSec  seconds during which thermal bias cannot rise
// The removal amounts scale with the pharmacology perk, like Terje's timed medicines.

modded class TerjeConsumableEffects
{
	override void TerjeApplyPositiveEffects(string classname, PlayerBase player, float amount, float perkPharmacMod)
	{
		super.TerjeApplyPositiveEffects(classname, player, amount, perkPharmacMod);

		if (!player || !player.IsAlive())
		{
			return;
		}

		float medValue;

		medValue = GetTerjeGameConfig().ConfigGetFloat( classname + " medSilicosisRemove" );
		if (medValue > 0)
		{
			TerjeNasdaraRemoveAgents(player, eAgents.SILICOSIS, medValue * amount * perkPharmacMod);
		}

		medValue = GetTerjeGameConfig().ConfigGetFloat( classname + " medEyeIrritationRemove" );
		if (medValue > 0)
		{
			TerjeNasdaraRemoveAgents(player, eAgents.EYES_IRRITATION, medValue * amount * perkPharmacMod);
		}

		ThermalBiasHandler thermalBias = player.GetThermalBiasHandler();
		if (thermalBias)
		{
			medValue = GetTerjeGameConfig().ConfigGetFloat( classname + " medThermalBiasRemove" );
			if (medValue > 0)
			{
				// Lower first, then set resistance: resistance blocks every Add, including negative ones.
				thermalBias.Set(Math.Max(0, thermalBias.Get() - (medValue * amount * perkPharmacMod)));
			}

			medValue = GetTerjeGameConfig().ConfigGetFloat( classname + " medThermalBiasResistSec" );
			if (medValue > 0)
			{
				thermalBias.SetTemporaryResistance(Math.Max(thermalBias.GetTemporaryResistance(), medValue * perkPharmacMod));
			}
		}
	}

	// Effect lines in the item tooltip, in the same style as TerjeRadiation.
	override private string DescribePositiveEffects(string classname)
	{
		string result = super.DescribePositiveEffects(classname);

		if (GetTerjeGameConfig().ConfigGetFloat( classname + " medSilicosisRemove" ) > 0)
		{
			result += "   #STR_TERJENAS_EFFECT_SILICOSIS " + NEXT_LINE;
		}

		if (GetTerjeGameConfig().ConfigGetFloat( classname + " medEyeIrritationRemove" ) > 0)
		{
			result += "   #STR_TERJENAS_EFFECT_EYES " + NEXT_LINE;
		}

		if (GetTerjeGameConfig().ConfigGetFloat( classname + " medThermalBiasRemove" ) > 0)
		{
			result += "   #STR_TERJENAS_EFFECT_COOLING " + NEXT_LINE;
		}

		float resistSec = GetTerjeGameConfig().ConfigGetFloat( classname + " medThermalBiasResistSec" );
		if (resistSec > 0)
		{
			result += "   #STR_TERJENAS_EFFECT_HEATPROTECT " + TimeValue(resistSec);
		}

		return result;
	}

	// Removes a flat number of agents. Vanilla ReduceAgent takes a percentage, which is not what these keys mean.
	protected void TerjeNasdaraRemoveAgents(PlayerBase player, int agentId, float count)
	{
		if (!player.m_AgentPool)
		{
			return;
		}

		float current = player.m_AgentPool.GetSingleAgentCount(agentId);
		if (current > 0)
		{
			player.m_AgentPool.SetAgentCount(agentId, Math.Max(0, current - count));
		}
	}
}
