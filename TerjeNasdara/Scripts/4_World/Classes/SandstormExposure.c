// Dust Wise perk: fewer silicosis and eye irritation agents taken in from sandstorms.

modded class SandstormExposureMdfrBase
{
	override protected float TransmitAgents(int type, PlayerBase player, float count)
	{
		if (player && player.GetTerjeSkills() && (type == eAgents.SILICOSIS || type == eAgents.EYES_IRRITATION))
		{
			float perkDustwiseValue;
			if (player.GetTerjeSkills().GetPerkValue("surv", "dustwise", perkDustwiseValue))
			{
				count *= Math.Clamp(1.0 + perkDustwiseValue, 0, 1);
			}
		}

		return super.TransmitAgents(type, player, count);
	}
}
