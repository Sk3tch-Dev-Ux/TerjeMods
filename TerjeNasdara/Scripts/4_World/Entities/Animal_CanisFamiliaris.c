// Feral dogs on Nasdara can carry rabies, the same way wolves do in TerjeMedicine.
// Their bites use the MeleeWolf ammo, so they already reach the rabies check in BleedingSourcesManagerServer.

modded class Animal_CanisFamiliaris_Dobermann_ColorBase
{
	private bool m_HasTerjeRabies;

	override bool HasTerjeRabies()
	{
		return m_HasTerjeRabies;
	}

	override void EEInit()
	{
		super.EEInit();

		if (g_Game.IsDedicatedServer())
		{
			float rabiesChance;
			if (GetTerjeSettingFloat(TerjeSettingsCollection.NASDARA_RABIES_DOG_INFECTED_CHANCE, rabiesChance))
			{
				m_HasTerjeRabies = (Math.RandomFloat01() < rabiesChance);
			}
		}
	}
}

modded class Animal_CanisFamiliaris_GermanShepherd_ColorBase
{
	private bool m_HasTerjeRabies;

	override bool HasTerjeRabies()
	{
		return m_HasTerjeRabies;
	}

	override void EEInit()
	{
		super.EEInit();

		if (g_Game.IsDedicatedServer())
		{
			float rabiesChance;
			if (GetTerjeSettingFloat(TerjeSettingsCollection.NASDARA_RABIES_DOG_INFECTED_CHANCE, rabiesChance))
			{
				m_HasTerjeRabies = (Math.RandomFloat01() < rabiesChance);
			}
		}
	}
}
