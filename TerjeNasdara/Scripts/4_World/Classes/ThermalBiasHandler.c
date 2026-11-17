// Acclimatised perk: slows how fast thermal bias (the vanilla heat stroke driver) builds up.
// Only gains are scaled. Losses from washing or medicine pass through unchanged.
// Thermal bias is a server-only stat, so this only matters on the server.

modded class ThermalBiasHandler
{
	override void Add(float value)
	{
		if (value > 0 && m_Player && m_Player.GetTerjeSkills())
		{
			float perkAcclimValue;
			if (m_Player.GetTerjeSkills().GetPerkValue("mtblsm", "acclim", perkAcclimValue))
			{
				value *= Math.Clamp(1.0 + perkAcclimValue, 0, 1);
			}
		}

		super.Add(value);
	}
}
