#include "Configuration.hpp"
#include "Variables.h"
#include <winerror.h>
#pragma warning( disable : 4091)
#include <ShlObj.h>
#include <string>
#include <sstream>


void CConfig::Setup()
{
	SetupValue(g_Options.Legitbot.MainSwitch, false, ("Legitbot"), ("LegitToggle"));
	SetupValue(g_Options.Legitbot.Aimbot.Enabled, false, ("Legitbot"), ("Enabled"));
	SetupValue(g_Options.Legitbot.backtrack, false, ("Legitbot"), ("Backtrack"));
	SetupValue(g_Options.Legitbot.backtrackTicks, 0, ("Legitbot"), ("BacktrackTicks"));

	SetupValue(g_Options.Legitbot.AutoPistol, false, ("Legitbot"), ("AutoPistol"));
	SetupValue(g_Options.Legitbot.MainKey, 1, ("Legitbot"), ("Key"));
	SetupValue(g_Options.Legitbot.Mainfov, 0.f, ("Legitbot"), ("FOV"));
	SetupValue(g_Options.Legitbot.MainSmooth, 1.f, ("Legitbot"), ("Speed"));
	SetupValue(g_Options.Legitbot.main_recoil_min, 0, ("Legitbot"), ("RCS-min"));
	SetupValue(g_Options.Legitbot.main_recoil_max, 0, ("Legitbot"), ("RCS-max"));

	SetupValue(g_Options.Legitbot.PistolKey, 6, ("Legitbot"), ("Key-Pistol"));
	SetupValue(g_Options.Legitbot.Pistolfov, 0.f, ("Legitbot"), ("FOV-Pistol"));
	SetupValue(g_Options.Legitbot.PistolSmooth, 1.f, ("Legitbot"), ("Speed-Pistol"));
	SetupValue(g_Options.Legitbot.pistol_recoil_min, 0, ("Legitbot"), ("RCS-min-pistol"));
	SetupValue(g_Options.Legitbot.pistol_recoil_max, 0, ("Legitbot"), ("RCS-max-pistol"));

	SetupValue(g_Options.Legitbot.SniperKey, 6, ("Legitbot"), ("Key-Sniper"));
	SetupValue(g_Options.Legitbot.Sniperfov, 0.f, ("Legitbot"), ("FOV-Sniper"));
	SetupValue(g_Options.Legitbot.SniperSmooth, 0.f, ("Legitbot"), ("Speed-Sniper"));
	SetupValue(g_Options.Legitbot.sniper_recoil_min, 0, ("Legitbot"), ("RCS-min-sniper"));
	SetupValue(g_Options.Legitbot.sniper_recoil_max, 0, ("Legitbot"), ("RCS-max-sniper"));

	SetupValue(g_Options.Legitbot.Triggerbot.Enabled, false, ("Legitbot"), ("TriggerBot"));
	SetupValue(g_Options.Legitbot.Triggerbot.Delay, 0.f, ("Legitbot"), ("TriggerBot delay"));
	SetupValue(g_Options.Legitbot.Triggerbot.Key, 6, ("Legitbot"), ("Key-Trigger"));
	SetupValue(g_Options.Legitbot.Triggerbot.hitchance, 0.f, ("LegitBot"), ("Trigger hitchance"));
	SetupValue(g_Options.Legitbot.Triggerbot.Filter.Head, false, ("LegitBot"), ("triggerHead"));
	SetupValue(g_Options.Legitbot.Triggerbot.Filter.Arms, false, ("LegitBot"), ("triggerArms"));
	SetupValue(g_Options.Legitbot.Triggerbot.Filter.Chest, false, ("LegitBot"), ("triggerChest"));
	SetupValue(g_Options.Legitbot.Triggerbot.Filter.Stomach, false, ("LegitBot"), ("triggerStomach"));
	SetupValue(g_Options.Legitbot.Triggerbot.Filter.Legs, false, ("LegitBot"), ("triggerLegs"));

	SetupValue(g_Options.Visuals.Skeleton, false, ("Visuals"), ("Skeleton"));
	SetupValue(g_Options.Visuals.HasDefuser, false, ("Visuals"), ("HasDefuser"));
	SetupValue(g_Options.Visuals.IsScoped, false, ("Visuals"), ("IsScoped"));
	SetupValue(g_Options.Visuals.Enabled, false, ("Visuals"), ("VisualsEnabled"));
	SetupValue(g_Options.Visuals.Box, false, ("Visuals"), ("Box"));
	SetupValue(g_Options.Visuals.Name, false, ("Visuals"), ("Name"));
	SetupValue(g_Options.Visuals.HP, false, ("Visuals"), ("HP"));
	SetupValue(g_Options.Visuals.Weapon, false, ("Visuals"), ("Weapon"));
	SetupValue(g_Options.Visuals.backtrackline, false, ("Visuals"), ("backtrackline"));
	SetupValue(g_Options.Visuals.Glow, false, ("Visuals"), ("Glow"));
	SetupValue(g_Options.Visuals.GrenadeESP, false, ("Visuals"), ("GranadeESP"));
	SetupValue(g_Options.Visuals.GrenadePrediction, false, ("Visuals"), ("Granade Prediction"));
	SetupValue(g_Options.Visuals.RecoilCrosshair, false, ("Visuals"), ("RecoilCrosshair"));
	SetupValue(g_Options.Visuals.SpreadCrosshair, false, ("Visuals"), ("SpreadCrosshair"));
	SetupValue(g_Options.Visuals.NoVisualRecoil, false, ("Visuals"), ("NoVisualRecoil"));
	SetupValue(g_Options.Visuals.FOVChanger, 0.f, ("Visuals"), ("fovchanger"));
	SetupValue(g_Options.Visuals.viewmodelChanger, 68.f, ("Visuals"), ("viewmodel_fov"));
	SetupValue(g_Options.Visuals.Time, false, ("Visuals"), ("Time"));
	SetupValue(g_Options.Visuals.DLight, false, ("Visuals"), ("DLight"));
	SetupValue(g_Options.Visuals.C4, false, ("Visuals"), ("C4"));
	SetupValue(g_Options.Visuals.money, false, ("Visuals"), ("Money"));
	SetupValue(g_Options.Visuals.NoFlash, false, ("Visuals"), ("NoFlash"));
	SetupValue(g_Options.Visuals.NoSmoke, false, ("Visuals"), ("NoSmoke"));
	SetupValue(g_Options.Visuals.noscopeborder, false, ("Visuals"), ("1tapNoScope360"));
	
	SetupValue(g_Options.Colors.hands_alpha, 1.f, ("Visuals"), ("HandsAlpha"));
	SetupValue(g_Options.Visuals.Hands, 0, ("Visuals"), ("Hands"));
	
	SetupValue(g_Options.Colors.hands_color[0], 1.f, ("Colors"), ("HandsChams1Color"));
	SetupValue(g_Options.Colors.hands_color[1], 1.f, ("Colors"), ("HandsChams2Color"));
	SetupValue(g_Options.Colors.hands_color[2], 1.f, ("Colors"), ("HandsChams3Color"));

	SetupValue(g_Options.Visuals.Chams, false, ("Visuals"), ("PlayerChams"));
	SetupValue(g_Options.Visuals.Teamchams, false, ("Visuals"), ("Teamchams"));
	SetupValue(g_Options.Visuals.Chamweapon, false, ("Visuals"), ("WeaponChams"));
	SetupValue(g_Options.Visuals.XQZ, false, ("Visuals"), ("XQZ Chams"));
	SetupValue(g_Options.Visuals.champlayeralpha, 0, ("Visuals"), ("PlayerCham Alpha"));
	SetupValue(g_Options.Visuals.matierial, 0, ("Visuals"), ("PlayerCham Material"));
	SetupValue(g_Options.Visuals.weaponviewcham, false, ("Visuals"), ("Weapon Chams"));
	SetupValue(g_Options.Visuals.weaponhandalpha, 0, ("Visuals"), ("Weapon Chams Alpha"));
	
	SetupValue(g_Options.Colors.EnemyChamsNVis[0], 1.f, ("Colors"), ("EnemyChamsNVisRed"));
	SetupValue(g_Options.Colors.EnemyChamsNVis[1], 0.f, ("Colors"), ("EnemyChamsNVisGreen"));
	SetupValue(g_Options.Colors.EnemyChamsNVis[2], 0.f, ("Colors"), ("EnemyChamsNVisBlue"));

	SetupValue(g_Options.Colors.EnemyChamsVis[0], 0.f, ("Colors"), ("EnemyChamsVisRed"));
	SetupValue(g_Options.Colors.EnemyChamsVis[1], 1.f, ("Colors"), ("EnemyChamsVisGreen"));
	SetupValue(g_Options.Colors.EnemyChamsVis[2], 0.f, ("Colors"), ("EnemyChamsVisBlue"));
	
	SetupValue(g_Options.Colors.color_skeleton[0], 1.f, ("Colors"), ("Skeleton1Color"));
	SetupValue(g_Options.Colors.color_skeleton[1], 1.f, ("Colors"), ("Skeleton2Color"));
	SetupValue(g_Options.Colors.color_skeleton[2], 1.f, ("Colors"), ("Skeleton3Color"));
	
	SetupValue(g_Options.Colors.tracer_color[0], 0.f, ("Colors"), ("Tracer1Color"));
	SetupValue(g_Options.Colors.tracer_color[1], 1.f, ("Colors"), ("Tracer2Color"));
	SetupValue(g_Options.Colors.tracer_color[2], 0.f, ("Colors"), ("Tracer3Color"));
	
	SetupValue(g_Options.Colors.box_color_t[0], 1.f, ("Colors"), ("ColorBoxTR1Color"));
	SetupValue(g_Options.Colors.box_color_t[1], 0.f, ("Colors"), ("ColorBoxTR2Color"));
	SetupValue(g_Options.Colors.box_color_t[2], 0.f, ("Colors"), ("ColorBoxTR3Color"));

	SetupValue(g_Options.Colors.box_color_ct[0], 0.f, ("Colors"), ("ColorBoxCT1Color"));
	SetupValue(g_Options.Colors.box_color_ct[1], 0.f, ("Colors"), ("ColorBoxCT2Color"));
	SetupValue(g_Options.Colors.box_color_ct[2], 1.f, ("Colors"), ("ColorBoxCT3Color"));

	SetupValue(g_Options.Colors.color_spread[0], 0.f, ("Colors"), ("SpreadCrosshair1Color"));
	SetupValue(g_Options.Colors.color_spread[1], 1.f, ("Colors"), ("SpreadCrosshair2Color"));
	SetupValue(g_Options.Colors.color_spread[2], 0.f, ("Colors"), ("SpreadCrosshair3Color"));

	SetupValue(g_Options.Colors.color_recoil[0], 1.f, ("Colors"), ("RecoilCrosshair1Color"));
	SetupValue(g_Options.Colors.color_recoil[1], 0.f, ("Colors"), ("RecoilCrosshair2Color"));
	SetupValue(g_Options.Colors.color_recoil[2], 0.f, ("Colors"), ("RecoilCrosshair3Color"));

	SetupValue(g_Options.Colors.dlight_color[0], 0.f, ("Colors"), ("DynamicLight1Color"));
	SetupValue(g_Options.Colors.dlight_color[1], 1.f, ("Colors"), ("DynamicLight2Color"));
	SetupValue(g_Options.Colors.dlight_color[2], 0.f, ("Colors"), ("DynamicLight3Color"));

	SetupValue(g_Options.Colors.hitmark_color[0], 0.f, ("Colors"), ("hitmarker1Color"));
	SetupValue(g_Options.Colors.hitmark_color[1], 1.f, ("Colors"), ("hitmarker2Color"));
	SetupValue(g_Options.Colors.hitmark_color[2], 0.f, ("Colors"), ("hitmarker3Color"));

	SetupValue(g_Options.Colors.backtrackdots_color[0], 1.f, ("Colors"), ("backtrackdots1Color"));
	SetupValue(g_Options.Colors.backtrackdots_color[1], 0.f, ("Colors"), ("backtrackdots2Color"));
	SetupValue(g_Options.Colors.backtrackdots_color[2], 0.f, ("Colors"), ("backtrackdots3Color"));

	SetupValue(g_Options.Visuals.tpdist, false, ("Visuals"), ("thirdperson distance"));
	SetupValue(g_Options.Visuals.TPKey, false, ("Visuals"), ("thirdperson key"));
	SetupValue(g_Options.Visuals.ThirdPerson, false, ("Visuals"), ("thirdperson switch"));

	SetupValue(g_Options.Misc.fps, false, ("Visuals"), ("fpsboost"));
	SetupValue(g_Options.Misc.Gray, false, ("Visuals"), ("GrayMode"));
	SetupValue(g_Options.Misc.crack, false, ("Visuals"), ("lsdMode"));
	SetupValue(g_Options.Misc.chromatic, false, ("Visuals"), ("ChromeMode"));

	SetupValue(g_Options.Visuals.Filter.Players, false, ("Visuals"), ("Players"));
	SetupValue(g_Options.Visuals.Filter.EnemyOnly, false, ("Visuals"), ("EnemyOnly"));
	SetupValue(g_Options.Visuals.WeaponsWorld, false, ("Visuals"), ("WeaponsWorld"));
	SetupValue(g_Options.Visuals.C4World, false, ("Visuals"), ("C4World"));
	SetupValue(g_Options.Visuals.Flashed, false, ("Visuals"), ("EnemyState"));

	SetupValue(g_Options.Misc.Hitmarker, false, ("Misc"), ("Hitmarker"));
	SetupValue(g_Options.Misc.hitsound, 0, ("Misc"), ("Hitmarker Sound"));

	SetupValue(g_Options.Misc.Skybox, 0, ("Misc"), ("Skybox"));
	SetupValue(g_Options.Misc.Watermark, true, ("Misc"), ("Watermark"));
	SetupValue(g_Options.Menu.Theme, 0, ("themes"), ("themes"));
	SetupValue(g_Options.Misc.AutoStrafe, false, ("Misc"), ("AutoStafe"));
	SetupValue(g_Options.Misc.nightMode, false, ("Misc"), ("NightMode"));
	SetupValue(g_Options.Misc.Bhop, false, ("Misc"), ("Bhop"));
	SetupValue(g_Options.Misc.ServerRankRevealAll, false, ("Misc"), ("Reveal Ranks"));
	SetupValue(g_Options.Misc.AutoAccept, false, ("Misc"), ("AutoAccept"));
	SetupValue(g_Options.Misc.bought, false, ("Misc"), ("Show enemies purchases"));
	SetupValue(g_Options.Misc.SpecList, false, ("Misc"), ("SpecList"));

	SetupValue(g_Options.Skinchanger.Enabled, false, ("Skinchanger"), ("Enabled"));
	SetupValue(g_Options.Skinchanger.Knife, 0, ("SkinChanger"), ("Knife"));
	SetupValue(g_Options.Skinchanger.KnifeSkin, 0, ("SkinChanger"), ("KnifeSkin"));
	SetupValue(g_Options.Skinchanger.gloves, 0, ("SkinChanger"), ("gloves"));

	SetupValue(g_Options.Skinchanger.AK47Skin, 0, ("SkinChanger"), ("AK47Skin"));
	SetupValue(g_Options.Skinchanger.M4A1SSkin, 0, ("SkinChanger"), ("M4A1SSkin"));
	SetupValue(g_Options.Skinchanger.M4A4Skin, 0, ("SkinChanger"), ("M4A4Skin"));
	SetupValue(g_Options.Skinchanger.AUGSkin, 0, ("SkinChanger"), ("AUGSkin"));
	SetupValue(g_Options.Skinchanger.FAMASSkin, 0, ("SkinChanger"), ("FAMASSkin"));
	SetupValue(g_Options.Skinchanger.GalilSkin, 0, ("SkinChanger"), ("GalilSkin"));
	SetupValue(g_Options.Skinchanger.Sg553Skin, 0, ("SkinChanger"), ("Sg553Skin"));

	SetupValue(g_Options.Skinchanger.AWPSkin, 0, ("SkinChanger"), ("AWPSkin"));
	SetupValue(g_Options.Skinchanger.SSG08Skin, 0, ("SkinChanger"), ("SSG08Skin"));
	SetupValue(g_Options.Skinchanger.SCAR20Skin, 0, ("SkinChanger"), ("SCAR20Skin"));
	SetupValue(g_Options.Skinchanger.G3sg1Skin, 0, ("SkinChanger"), ("G3sg1Skin"));

	SetupValue(g_Options.Skinchanger.P90Skin, 0, ("SkinChanger"), ("P90Skin"));
	SetupValue(g_Options.Skinchanger.UMP45Skin, 0, ("SkinChanger"), ("UMP45Skin"));
	SetupValue(g_Options.Skinchanger.Mp7Skin, 0, ("SkinChanger"), ("Mp7Skin"));
	SetupValue(g_Options.Skinchanger.Mac10Skin, 0, ("SkinChanger"), ("Mac10Skin"));
	SetupValue(g_Options.Skinchanger.Mp9Skin, 0, ("SkinChanger"), ("Mp9Skin"));
	SetupValue(g_Options.Skinchanger.BizonSkin, 0, ("SkinChanger"), ("BizonSkin"));

	SetupValue(g_Options.Skinchanger.GlockSkin, 0, ("SkinChanger"), ("GlockSkin"));
	SetupValue(g_Options.Skinchanger.USPSkin, 0, ("SkinChanger"), ("USPSkin"));
	SetupValue(g_Options.Skinchanger.DeagleSkin, 0, ("SkinChanger"), ("DeagleSkin"));
	SetupValue(g_Options.Skinchanger.RevolverSkin, 0, ("SkinChanger"), ("RevolverSkin"));
	SetupValue(g_Options.Skinchanger.DualSkin, 0, ("SkinChanger"), ("DualSkin"));

	SetupValue(g_Options.Skinchanger.MagSkin, 0, ("SkinChanger"), ("MagSkin"));
	SetupValue(g_Options.Skinchanger.NovaSkin, 0, ("SkinChanger"), ("NovaSkin"));
	SetupValue(g_Options.Skinchanger.SawedSkin, 0, ("SkinChanger"), ("SawedSkin"));
	SetupValue(g_Options.Skinchanger.XmSkin, 0, ("SkinChanger"), ("XmSkin"));

	SetupValue(g_Options.Skinchanger.Cz75Skin, 0, ("SkinChanger"), ("Cz75Skin"));
	SetupValue(g_Options.Skinchanger.tec9Skin, 0, ("SkinChanger"), ("tec9Skin"));
	SetupValue(g_Options.Skinchanger.P2000Skin, 0, ("SkinChanger"), ("P2000Skin"));
	SetupValue(g_Options.Skinchanger.P250Skin, 0, ("SkinChanger"), ("P250Skin"));
	SetupValue(g_Options.Skinchanger.FiveSkin, 0, ("SkinChanger"), ("FiveSkin"));

	SetupValue(g_Options.Skinchanger.NegevSkin, 0, ("SkinChanger"), ("NegevSkin"));
	SetupValue(g_Options.Skinchanger.M249Skin, 0, ("SkinChanger"), ("M249Skin"));
}

void CConfig::SetupValue(int &value, int def, std::string category, std::string name)
{
	value = def;
	ints.push_back(new ConfigValue<int>(category, name, &value));
}

void CConfig::SetupValue(float &value, float def, std::string category, std::string name)
{
	value = def;
	floats.push_back(new ConfigValue<float>(category, name, &value));
}

void CConfig::SetupValue(bool &value, bool def, std::string category, std::string name)
{
	value = def;
	bools.push_back(new ConfigValue<bool>(category, name, &value));
}

void CConfig::Save()
{
	static TCHAR path[MAX_PATH];
	std::string folder, file;

	if (SUCCEEDED(SHGetFolderPath(NULL, CSIDL_APPDATA, NULL, 0, path)))
	{

        folder = std::string(path) + ("GodLike");
		switch (g_Options.Menu.ConfigFile)
		{
		case 0:
			file = std::string(path) + ("legit.ini");
			break;
		case 1:
			file = std::string(path) + ("rage.ini");
			break;
		case 2:
			file = std::string(path) + ("custom.ini");
			break;
		case 3:
			file = std::string(path) + ("custom2.ini");
			break;
		}

	}


	CreateDirectory(folder.c_str(), NULL);

	for (auto value : ints)
		WritePrivateProfileString(value->category.c_str(), value->name.c_str(), std::to_string(*value->value).c_str(), file.c_str());

	for (auto value : floats)
		WritePrivateProfileString(value->category.c_str(), value->name.c_str(), std::to_string(*value->value).c_str(), file.c_str());

	for (auto value : bools)
		WritePrivateProfileString(value->category.c_str(), value->name.c_str(), *value->value ? "true" : "false", file.c_str());
}


void CConfig::Load()
{
	static TCHAR path[MAX_PATH];
	std::string folder, file;

	if (SUCCEEDED(SHGetFolderPath(NULL, CSIDL_APPDATA, NULL, 0, path)))
	{
		folder = std::string(path) + ("GodLike");
		switch (g_Options.Menu.ConfigFile)
		{
		case 0:
			file = std::string(path) + ("legit.ini");
			break;
		case 1:
			file = std::string(path) + ("rage.ini");
			break;
		case 2:
			file = std::string(path) + ("custom.ini");
			break;
		case 3:
			file = std::string(path) + ("custom2.ini");
			break;
		}
	}

	CreateDirectory(folder.c_str(), NULL);

	char value_l[32] = { '\0' };

	for (auto value : ints)
	{
		GetPrivateProfileString(value->category.c_str(), value->name.c_str(), "", value_l, 32, file.c_str());
		*value->value = atoi(value_l);
	}

	for (auto value : floats)
	{
		GetPrivateProfileString(value->category.c_str(), value->name.c_str(), "", value_l, 32, file.c_str());
		*value->value = (float)atof(value_l);
	}

	for (auto value : bools)
	{
		GetPrivateProfileString(value->category.c_str(), value->name.c_str(), "", value_l, 32, file.c_str());
		*value->value = !strcmp(value_l, "true");
	}
}


CConfig* Config = new CConfig();
Variables g_Options;
