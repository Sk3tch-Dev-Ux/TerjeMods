// Feral dogs on Nasdara: global visibility setting plus the Dog Whisperer stealth perk.
// Mirrors the wolf and bear branches in TerjeSkills.

modded class AITargetCallbacksPlayer
{
	override float GetMaxVisionRangeModifier(EntityAI pApplicant)
	{
		float result = super.GetMaxVisionRangeModifier(pApplicant);

		if (g_Game && g_Game.IsDedicatedServer() && m_Player && pApplicant && m_Player.GetTerjeSkills() != null && pApplicant.IsAnimal())
		{
			AnimalBase animal = AnimalBase.Cast(pApplicant);
			if (animal && (animal.IsInherited(Animal_CanisFamiliaris_Dobermann_ColorBase) || animal.IsInherited(Animal_CanisFamiliaris_GermanShepherd_ColorBase)))
			{
				float settingValue;
				if (GetTerjeSettingFloat(TerjeSettingsCollection.NASDARA_STEALTH_DOGS_VISIBLE_MODIFIER, settingValue))
				{
					result *= Math.Max(0, settingValue);
				}

				float perkValue;
				if (!animal.HasTerjeReceivedDamage() && m_Player.GetTerjeSkills().IsPerkRegistered("stlth", "dogwhisp") && m_Player.GetTerjeSkills().GetPerkValue("stlth", "dogwhisp", perkValue))
				{
					result *= Math.Clamp(1.0 + perkValue, 0, 1);
				}
			}
		}

		return result;
	}
}
