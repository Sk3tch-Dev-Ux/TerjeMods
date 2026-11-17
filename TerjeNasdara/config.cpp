class CfgPatches
{
	class TerjeNasdara
	{
		units[]=
		{
			"TerjeInjectorAminophylline",
			"TerjeSalveEyeOintment",
			"TerjePillsElectrolytes"
		};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"TerjeCore",
			"TerjeMedicine",
			"TerjeMedicine_Injectors",
			"TerjeMedicine_Pills",
			"TerjeMedicine_Salves",
			"TerjeSkills",
			"TerjeSkills_Animals",
			"DZ_Animals_Nasdara",
			"Animal_Canis_Familiaris_Dobermann_ColorBase",
			"Animal_Canis_Familiaris_German_Shepherd_ColorBase",
			"DZ_Animals_ovis_gmelini",
			"DZ_Animals_varanus_griseus"
		};
	};
};

class CfgMods
{
	class TerjeNasdara
	{
		dir="TerjeNasdara";
		hideName=1;
		hidePicture=1;
		version="1.0.0";
		extra=0;

		defines[]={"TERJE_NASDARA_MOD"};
		type="mod";
		dependencies[]={"World"};

		class defs
		{
			class worldScriptModule
			{
				value="";
				files[]={"TerjeNasdara/Scripts/4_World"};
			};
		};
	};
};

// New perks are appended to the existing skills. Terje stores perks by id, so saves stay compatible.
class CfgTerjeSkills
{
	class SkillsBase;

	class Survival: SkillsBase
	{
		class Perks
		{
			class HeatResistance
			{
				id="heatres";
				enabled=1;
				displayName="#STR_TERJENAS_PERK_HEATRES";
				description="#STR_TERJENAS_PERK_HEATRES_DES";
				stagesCount=6;
				disabledIcon="set:TerjePerkBlack_icon image:tp_thermoregulation";
				enabledIcon="set:TerjePerk_icon image:tp_thermoregulation";
				requiredSkillLevels[]={1,5,10,15,20,25};
				requiredPerkPoints[]={1,1,1,1,1,2};
				values[]={0.05,0.1,0.2,0.3,0.4,0.5};
			};
			class DustWise
			{
				id="dustwise";
				enabled=1;
				displayName="#STR_TERJENAS_PERK_DUSTWISE";
				description="#STR_TERJENAS_PERK_DUSTWISE_DES";
				stagesCount=5;
				disabledIcon="set:TerjePerkBlack_icon image:tp_properbreathing";
				enabledIcon="set:TerjePerk_icon image:tp_properbreathing";
				requiredSkillLevels[]={3,8,14,20,30};
				requiredPerkPoints[]={1,1,1,1,2};
				values[]={-0.1,-0.2,-0.35,-0.5,-0.7};
			};
		};
	};

	class Metabolism: SkillsBase
	{
		class Perks
		{
			class Acclimatised
			{
				id="acclim";
				enabled=1;
				displayName="#STR_TERJENAS_PERK_ACCLIM";
				description="#STR_TERJENAS_PERK_ACCLIM_DES";
				stagesCount=5;
				disabledIcon="set:TerjePerkBlack_icon image:tp_hydrationcontrol";
				enabledIcon="set:TerjePerk_icon image:tp_hydrationcontrol";
				requiredSkillLevels[]={2,6,12,18,28};
				requiredPerkPoints[]={1,1,1,1,2};
				values[]={-0.1,-0.2,-0.3,-0.45,-0.6};
			};
		};
	};

	class Stealth: SkillsBase
	{
		class Perks
		{
			class DogWhisperer
			{
				id="dogwhisp";
				enabled=1;
				displayName="#STR_TERJENAS_PERK_DOGWHISP";
				description="#STR_TERJENAS_PERK_DOGWHISP_DES";
				stagesCount=5;
				disabledIcon="set:TerjePerkBlack_icon image:tp_wolfinstinct";
				enabledIcon="set:TerjePerk_icon image:tp_wolfinstinct";
				requiredSkillLevels[]={1,5,10,15,25};
				requiredPerkPoints[]={1,1,1,1,2};
				values[]={-0.1,-0.2,-0.3,-0.6,-0.9};
			};
		};
	};
};

class CfgVehicles
{
	class AnimalBase;
	class TerjeInjectorBase;
	class TerjeSalveBase;
	class TerjePills_Circle;

	// Hunting experience for the Nasdara animals. Without these entries Terje reads 0 and gives no XP.
	class Animal_CanisFamiliaris_Dobermann_ColorBase: AnimalBase
	{
		terjeOnKillHuntingExp=25;
		terjeOnHeadshotHuntingExp=25;
		terjeOnButchHuntingExp=50;
		terjeHighlightWithPathfinder=0;
		terjeSkinningTimeModifier=0.75;
		terjeSkinningKnifeDamageModifier=0.75;
	};

	class Animal_CanisFamiliaris_GermanShepherd_ColorBase: AnimalBase
	{
		terjeOnKillHuntingExp=25;
		terjeOnHeadshotHuntingExp=25;
		terjeOnButchHuntingExp=50;
		terjeHighlightWithPathfinder=0;
		terjeSkinningTimeModifier=0.75;
		terjeSkinningKnifeDamageModifier=0.75;
	};

	class Animal_OvisGmelini: AnimalBase
	{
		terjeOnKillHuntingExp=50;
		terjeOnHeadshotHuntingExp=75;
		terjeOnButchHuntingExp=100;
		terjeHighlightWithPathfinder=1;
		terjeSkinningTimeModifier=1.0;
		terjeSkinningKnifeDamageModifier=1.0;
	};

	class Animal_VaranusGriseus: AnimalBase
	{
		terjeOnKillHuntingExp=25;
		terjeOnHeadshotHuntingExp=50;
		terjeOnButchHuntingExp=25;
		terjeHighlightWithPathfinder=1;
		terjeSkinningTimeModifier=0.25;
		terjeSkinningKnifeDamageModifier=0.3;
	};

	// Medicine for the vanilla 1.30 desert conditions. Effect keys are handled in TerjeConsumableEffects.c of this mod.
	class TerjeInjectorAminophylline: TerjeInjectorBase
	{
		scope=2;
		displayName="#STR_TERJENAS_AMINOPHYLLINE";
		descriptionShort="#STR_TERJENAS_AMINOPHYLLINE_DESC";
		medSilicosisRemove=400;
		overdosedIncrement=0.5;
		medSkillExpAddToSelf=100;
		hiddenSelectionsTextures[]={"TerjeMedicine\Injectors\data\injector_green_co.paa"};
	};

	class TerjeSalveEyeOintment: TerjeSalveBase
	{
		scope=2;
		displayName="#STR_TERJENAS_EYEOINTMENT";
		descriptionShort="#STR_TERJENAS_EYEOINTMENT_DESC";
		medEyeIrritationRemove=60;
		hiddenSelectionsTextures[]={"TerjeMedicine\Salves\data\viprosal_co.paa"};
	};

	class TerjePillsElectrolytes: TerjePills_Circle
	{
		scope=2;
		displayName="#STR_TERJENAS_ELECTROLYTES";
		descriptionShort="#STR_TERJENAS_ELECTROLYTES_DESC";
		medThermalBiasRemove=0.2;
		medThermalBiasResistSec=60;
		terjeAddWater=25;
		overdosedIncrement=0.05;
		hiddenSelectionsTextures[]={"TerjeMedicine\Pills\data\circle_12_co.paa"};
	};
};
