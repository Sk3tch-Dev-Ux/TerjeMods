// Stethoscope inspection of the vanilla 1.30 desert conditions.
// The stats are built on the dedicated server (ActionStethoscopeInspect.SetupAction),
// which is the only place thermal bias and agent counts exist.

modded class TerjePlayerInspectableStats
{
	override void OnInit(PlayerBase player, int level)
	{
		super.OnInit(player, level);

		if (!player || !player.IsAlive())
		{
			return;
		}

		ThermalBiasHandler thermalBias = player.GetThermalBiasHandler();
		if (thermalBias)
		{
			// Vanilla has four heat stroke phases (above 0.0, 0.4, 0.6, 0.85); Terje shows three stages.
			// Phase 1 (water drain only) maps to L1 once the bias is noticeable, phase 2 to L2, phases 3 and 4 to L3.
			float bias = thermalBias.Get();
			if (bias > 0.05)
			{
				if (level >= 2)
				{
					if (bias > HeatStrokeMdfr.STAGE_THRESHOLDS[2])
					{
						AddInspectableStat("#STR_TERJENAS_PIS_HEATSTROKE", "set:TerjeMedicine_icon image:tm_burn", "#STR_TERJEMED_PIS_L3");
					}
					else if (bias > HeatStrokeMdfr.STAGE_THRESHOLDS[1])
					{
						AddInspectableStat("#STR_TERJENAS_PIS_HEATSTROKE", "set:TerjeMedicine_icon image:tm_burn", "#STR_TERJEMED_PIS_L2");
					}
					else
					{
						AddInspectableStat("#STR_TERJENAS_PIS_HEATSTROKE", "set:TerjeMedicine_icon image:tm_burn", "#STR_TERJEMED_PIS_L1");
					}
				}
				else if (level == 1)
				{
					AddInspectableStat("#STR_TERJENAS_PIS_HEATSTROKE", "set:TerjeMedicine_icon image:tm_burn", "");
				}
			}
		}

		// Vanilla silicosis thresholds: heavy breathing 200, stamina cap 600, unconsciousness 800.
		int silicosis = player.GetSingleAgentCount(eAgents.SILICOSIS);
		if (silicosis > 0)
		{
			if (level >= 2)
			{
				if (silicosis >= 800)
				{
					AddInspectableStat("#STR_TERJENAS_PIS_SILICOSIS", "set:TerjeMedicine_icon image:tm_biohazard", "#STR_TERJEMED_PIS_L3");
				}
				else if (silicosis >= 600)
				{
					AddInspectableStat("#STR_TERJENAS_PIS_SILICOSIS", "set:TerjeMedicine_icon image:tm_biohazard", "#STR_TERJEMED_PIS_L2");
				}
				else if (silicosis >= 200)
				{
					AddInspectableStat("#STR_TERJENAS_PIS_SILICOSIS", "set:TerjeMedicine_icon image:tm_biohazard", "#STR_TERJEMED_PIS_L1");
				}
				else if (level >= 3)
				{
					AddInspectableStat("#STR_TERJENAS_PIS_SILICOSIS", "set:TerjeMedicine_icon image:tm_biohazard", "#STR_TERJECORE_PIS_INCUBATION");
				}
			}
			else if (level == 1 && silicosis >= 200)
			{
				AddInspectableStat("#STR_TERJENAS_PIS_SILICOSIS", "set:TerjeMedicine_icon image:tm_biohazard", "");
			}
		}

		// Vanilla eye irritation tops out at 100 agents.
		int eyes = player.GetSingleAgentCount(eAgents.EYES_IRRITATION);
		if (eyes > 0)
		{
			if (level >= 2)
			{
				if (eyes >= 66)
				{
					AddInspectableStat("#STR_TERJENAS_PIS_EYES", "set:TerjeMedicine_icon image:tm_scratch", "#STR_TERJEMED_PIS_L3");
				}
				else if (eyes >= 33)
				{
					AddInspectableStat("#STR_TERJENAS_PIS_EYES", "set:TerjeMedicine_icon image:tm_scratch", "#STR_TERJEMED_PIS_L2");
				}
				else
				{
					AddInspectableStat("#STR_TERJENAS_PIS_EYES", "set:TerjeMedicine_icon image:tm_scratch", "#STR_TERJEMED_PIS_L1");
				}
			}
			else if (level == 1)
			{
				AddInspectableStat("#STR_TERJENAS_PIS_EYES", "set:TerjeMedicine_icon image:tm_scratch", "");
			}
		}
	}
}
