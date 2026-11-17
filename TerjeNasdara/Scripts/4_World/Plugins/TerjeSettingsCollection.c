modded class TerjeSettingsCollection
{
	static int NASDARA_RABIES_DOG_INFECTED_CHANCE;
	static int NASDARA_STEALTH_DOGS_VISIBLE_MODIFIER;

	override void OnInit()
	{
		super.OnInit();

		RegisterRegion("Nasdara", "Nasdara map settings");
		NASDARA_RABIES_DOG_INFECTED_CHANCE = RegisterSettingFloat("Nasdara.RabiesDogInfectedChance", "Nasdara", "The chance of a feral dog (Dobermann or German Shepherd) being infected with rabies (determined when the dog is spawned).", 0.1, true);
		NASDARA_STEALTH_DOGS_VISIBLE_MODIFIER = RegisterSettingFloat("Nasdara.StealthDogsVisibilityModifier", "Nasdara", "Sets global player visibility modifier for targeting by feral dogs.", 1.0, true);
	}
}
