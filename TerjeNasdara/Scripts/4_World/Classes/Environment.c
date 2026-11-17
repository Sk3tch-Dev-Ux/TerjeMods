// Heat Resistance perk: the hot-side mirror of the Survival cold resistance perk in TerjeSkills.
// The vanilla sun heating is added inside GetEnvironmentTemperature, so the perk covers it too.

modded class Environment
{
	override protected float GetEnvironmentTemperature()
	{
		float result = super.GetEnvironmentTemperature();

		// Skip the perk while a warm heat source (fire, stove, heat pack) is in range, so it never makes a fire
		// warm the player less. Vanilla sets m_UTSAverageTemperature to 0 when there are no sources.
		// This test does not depend on 'result', which TerjeSkills (survtempmod) has already scaled inside super.
		bool nearHeatSource = (m_HasTemperatureSources && m_UTSAverageTemperature > 0);

		if (!nearHeatSource && m_Player && m_Player.IsAlive() && m_Player.GetTerjeSkills())
		{
			float perkHeatresValue;
			if (m_Player.GetTerjeSkills().GetPerkValue("surv", "heatres", perkHeatresValue))
			{
				float relativeTemp = result - GameConstants.ENVIRO_PLAYER_COMFORT_TEMP;
				if (relativeTemp > 0)
				{
					relativeTemp *= Math.Clamp(1.0 - perkHeatresValue, 0, 1);
				}

				result = relativeTemp + GameConstants.ENVIRO_PLAYER_COMFORT_TEMP;
			}
		}

		return result;
	}
}
