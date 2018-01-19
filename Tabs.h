#pragma once
#include "IDirect3DDevice9.h"
#include "Themes.h"

typedef void(*CL_FullUpdate_t) (void);
CL_FullUpdate_t CL_FullUpdate = nullptr;

void KnifeApplyCallbk()
{
	static auto CL_FullUpdate = reinterpret_cast<CL_FullUpdate_t>(U::FindPattern("engine.dll", reinterpret_cast<PBYTE>("\xA1\x00\x00\x00\x00\xB9\x00\x00\x00\x00\x56\xFF\x50\x14\x8B\x34\x85"), "x????x????xxxxxxx"));
	CL_FullUpdate();
}
void dankestSetClanTag(const char* tag, const char* name)
{
	static auto ClanTagOffset = U::FindPattern("engine.dll", (PBYTE)"\x53\x56\x57\x8B\xDA\x8B\xF9\xFF\x15", "xxxxxxxxx");
	if (ClanTagOffset)
	{
		if (strlen(name) > 0) {
			auto name_ = std::string(name);
			auto newline = name_.find("\\n");
			auto tab = name_.find("\\t");
			if (newline != std::string::npos) {
				name_.replace(newline, newline + 2, "\n");
			}
			if (tab != std::string::npos) {
				name_.replace(tab, tab + 2, "\t");
			}
		}
		auto tag_ = std::string(tag);
		if (strlen(tag) > 0) {
			auto newline = tag_.find("\\n");
			auto tab = tag_.find("\\t");
			if (newline != std::string::npos) {
				tag_.replace(newline, newline + 2, "\n");
			}
			if (tab != std::string::npos) {
				tag_.replace(tab, tab + 2, "\t");
			}
		}
		static auto dankesttSetClanTag = reinterpret_cast<void(__fastcall*)(const char*, const char*)>(ClanTagOffset);
		dankesttSetClanTag(tag_.data(), tag_.data());
	}
}

namespace ImGui
{
	class Tab
	{
	private:

		std::vector<std::string> labels;

	public:

		void add(std::string name)
		{
			labels.push_back(name);
		}

		void draw(int *selected)
		{
			ImGuiStyle &style = GetStyle();
			ImVec4 color = style.Colors[ImGuiCol_Button];
			ImVec4 colorActive = style.Colors[ImGuiCol_ButtonActive];
			ImVec4 colorHover = style.Colors[ImGuiCol_ButtonHovered];
			ImVec2 max = GetContentRegionMax();
			float size_x = max.x / labels.size() - 0.f;
			float size_y = max.y / labels.size() - 30.f;

			for (size_t i = 0; i < labels.size(); i++)
			{
				if (i == *selected)
				{
					style.Colors[ImGuiCol_Button] = colorActive;
					style.Colors[ImGuiCol_ButtonActive] = colorActive;
					style.Colors[ImGuiCol_ButtonHovered] = colorActive;
				}
				else
				{
					style.Colors[ImGuiCol_Button] = color;
					style.Colors[ImGuiCol_ButtonActive] = colorActive;
					style.Colors[ImGuiCol_ButtonHovered] = colorHover;
				}

				if (Button(labels.at(i).c_str(), { size_x, size_y }))
					*selected = i;
			}

			style.Colors[ImGuiCol_Button] = color;
			style.Colors[ImGuiCol_ButtonActive] = colorActive;
			style.Colors[ImGuiCol_ButtonHovered] = colorHover;
		}
	};
}

const char* hitsound[] =
{
	"Disabled",
	"Default",
	"Trump",
	"Skeet"
};

void drawConfig()
{
	ImGui::PushItemWidth(10);
	ImGui::Combo("Config", &g_Options.Menu.ConfigFile, configFiles, ARRAYSIZE(configFiles));
	ImGui::PopItemWidth();
	if (ImGui::Button("Save")) Config->Save();
	ImGui::SameLine();
	if (ImGui::Button("Load")) Config->Load();
	ImGui::SameLine();
	if (ImGui::Button("Reset")) Config->Setup();
}

void RenderLegit()
{
	ImGui::Checkbox(("Active"), &g_Options.Legitbot.MainSwitch);
	ImGui::Columns(5, nullptr, true);
	{
		ImGui::Text("General"); ImGui::NextColumn(); ImGui::Text("Rifles"); ImGui::NextColumn(); ImGui::Text("Pistol"); ImGui::NextColumn(); ImGui::Text("Sniper"); ImGui::NextColumn(); ImGui::Text("Triggerbot"); ImGui::NextColumn(); ImGui::Separator();

		ImGui::Checkbox(("Enable Aimbot"), &g_Options.Legitbot.Aimbot.Enabled);
		ImGui::Checkbox(("Legit Backtrack"), &g_Options.Legitbot.backtrack);
		ImGui::SliderFloat(("Ticks"), &g_Options.Legitbot.backtrackTicks, 0, 12, "%1.f");
		ImGui::Checkbox(("Backtrack line"), &g_Options.Visuals.backtrackline);
		ImGui::SameLine();
		ImGui::MyColorEdit3(XorStr("##232gd"), (float*)&g_Options.Colors.backtrackdots_color, 1 << 7);
		ImGui::Checkbox(("Auto Pistol"), &g_Options.Legitbot.AutoPistol);
		/*ImGui::BeginChild(("HitboxFilter"), ImVec2(ImGui::GetWindowContentRegionWidth() * 0.5f, 19 * 5));
		{
			ImGui::Selectable((" Head"), &g_Options.Legitbot.Filter.Head);
			ImGui::Selectable((" Arms"), &g_Options.Legitbot.Filter.Arms);
			ImGui::Selectable((" Chest"), &g_Options.Legitbot.Filter.Chest);
			ImGui::Selectable((" Stomach"), &g_Options.Legitbot.Filter.Stomach);
			ImGui::Selectable((" Legs"), &g_Options.Legitbot.Filter.Legs);
		} ImGui::EndChild();*/
	}
	//ImGui::Separator();
	ImGui::NextColumn();

	{
		ImGui::PushItemWidth(110);
		ImGui::Hotkey("Key##0", &g_Options.Legitbot.MainKey);
        //ImGui::Combo(("Key##0"), &menu.Legitbot.MainKey, keyNames, ARRAYSIZE(keyNames));
        ImGui::SliderFloat("Smooth##0", &g_Options.Legitbot.MainSmooth, 1.00f, 100.00f, "%.2f");
        ImGui::SliderFloat("FOV##0", &g_Options.Legitbot.Mainfov, 0.00f, 30.00f, "%.2f");
        ImGui::SliderFloat("Min RCS##0", &g_Options.Legitbot.main_recoil_min, 1.00f, 100.00f, "%.2f");
        ImGui::SliderFloat("Max RCS##0", &g_Options.Legitbot.main_recoil_max, 1.00f, 100.00f, "%.2f");
	}

	ImGui::NextColumn();

	{
		ImGui::PushItemWidth(110);
        ImGui::Hotkey("Key##1", &g_Options.Legitbot.PistolKey);
        //ImGui::Combo(("Key##1"), &menu.Legitbot.PistolKey, keyNames, ARRAYSIZE(keyNames));
        ImGui::SliderFloat("Smooth##1", &g_Options.Legitbot.PistolSmooth, 1.00f, 100.00f, "%.2f");
        ImGui::SliderFloat("FOV##1", &g_Options.Legitbot.Pistolfov, 0.00f, 30.00f, "%.2f");
        ImGui::SliderFloat("Min RCS##1", &g_Options.Legitbot.pistol_recoil_min, 1.00f, 100.00f, "%.2f");
        ImGui::SliderFloat("Max RCS##1", &g_Options.Legitbot.pistol_recoil_max, 1.00f, 100.00f, "%.2f");
	}
	ImGui::NextColumn();

	{
		ImGui::PushItemWidth(110);
        ImGui::Hotkey("Key##2", &g_Options.Legitbot.SniperKey);
        //ImGui::Combo(("Key##2"), &menu.Legitbot.SniperKey, keyNames, ARRAYSIZE(keyNames));
        ImGui::SliderFloat("Smooth##2", &g_Options.Legitbot.SniperSmooth, 1.00f, 100.00f, "%.2f");
        ImGui::SliderFloat("FOV##2", &g_Options.Legitbot.Sniperfov, 0.00f, 30.00f, "%.2f");
        ImGui::SliderFloat("Min RCS##2", &g_Options.Legitbot.sniper_recoil_min, 1.00f, 100.00f, "%.2f");
        ImGui::SliderFloat("Max RCS##2", &g_Options.Legitbot.sniper_recoil_max, 1.00f, 100.00f, "%.2f");
	}

	ImGui::NextColumn();

	{
		//ImGui::Separator();
		ImGui::Checkbox(("Enable Triggerbot"), &g_Options.Legitbot.Triggerbot.Enabled);
		ImGui::PushItemWidth(110);
		ImGui::SliderFloat(("Delay"), &g_Options.Legitbot.Triggerbot.Delay, 1.f, 150.f, "%.0f");
		ImGui::Hotkey("Key##3", &g_Options.Legitbot.Triggerbot.Key);
        //ImGui::Combo(("Triggerbot key"), &menu.Legitbot.Triggerbot.Key, keyNames, ARRAYSIZE(keyNames));
		ImGui::SliderFloat(("Hitchance"), &g_Options.Legitbot.Triggerbot.hitchance, 1.f, 100.f, "%.0f");

		ImGui::Text(("Filter"));

		ImGui::BeginChild(("Filter"), ImVec2(ImGui::GetWindowContentRegionWidth() * 0.5f, 19 * 5));
		{
			ImGui::Selectable((" Head"), &g_Options.Legitbot.Triggerbot.Filter.Head);
			ImGui::Selectable((" Arms"), &g_Options.Legitbot.Triggerbot.Filter.Arms);
			ImGui::Selectable((" Chest"), &g_Options.Legitbot.Triggerbot.Filter.Chest);
			ImGui::Selectable((" Stomach"), &g_Options.Legitbot.Triggerbot.Filter.Stomach);
			ImGui::Selectable((" Legs"), &g_Options.Legitbot.Triggerbot.Filter.Legs);
		} ImGui::EndChild();
	}
}

void RenderVisuals()
{
	ImGui::Checkbox(("Active"), &g_Options.Visuals.Enabled);

	ImGui::Columns(4, NULL, true);
	{
		ImGui::Text("Player"); ImGui::NextColumn(); ImGui::Text("Chams"); ImGui::NextColumn(); ImGui::Text("Filter"); ImGui::NextColumn(); ImGui::Text("Misc"); ImGui::NextColumn(); ImGui::Separator();
		ImGui::Checkbox(("Box  "), &g_Options.Visuals.Box);
		ImGui::SameLine();
		ImGui::MyColorEdit3(XorStr("CT"), (float*)&g_Options.Colors.box_color_ct, 1 << 7);
		ImGui::SameLine();
		ImGui::MyColorEdit3(XorStr("TR"), (float*)&g_Options.Colors.box_color_t, 1 << 7);
		ImGui::Checkbox(("Name"), &g_Options.Visuals.Name);
		ImGui::Checkbox(("HP"), &g_Options.Visuals.HP);
		ImGui::Checkbox(("Skeleton"), &g_Options.Visuals.Skeleton);
		ImGui::SameLine();
		ImGui::MyColorEdit3(XorStr("##04593"), (float*)&g_Options.Colors.color_skeleton, 1 << 7);
		ImGui::Checkbox(("Weapon"), &g_Options.Visuals.Weapon);		
		ImGui::Checkbox("Glow", &g_Options.Visuals.Glow);
		ImGui::Checkbox(("Dynamic Light"), &g_Options.Visuals.DLight);
		ImGui::SameLine();
		ImGui::MyColorEdit3(XorStr("##63456"), (float*)&g_Options.Colors.dlight_color, 1 << 7);
		ImGui::Checkbox(("GrenadeESP"), &g_Options.Visuals.GrenadeESP);
		ImGui::Checkbox(("Grenade Prediction"), &g_Options.Visuals.GrenadePrediction);
		ImGui::SameLine();
		ImGui::MyColorEdit3(XorStr("##1234"), (float*)&g_Options.Colors.tracer_color, 1 << 7);
		ImGui::Checkbox(("C4"), &g_Options.Visuals.C4);
		ImGui::Checkbox(("Money"), &g_Options.Visuals.money);
	}
	ImGui::NextColumn();
	{
		ImGui::PushItemWidth(130);
		ImGui::Checkbox(XorStr("Cham Players"), &g_Options.Visuals.Chams);
		ImGui::SameLine();
		ImGui::MyColorEdit3("##42ESP", g_Options.Colors.EnemyChamsVis, 1 << 7);
		ImGui::Checkbox(XorStr("Cham Team"), &g_Options.Visuals.Teamchams);
		ImGui::SameLine();
		ImGui::MyColorEdit3("##E772SP", g_Options.Colors.TeamChamsVis, 1 << 7);
		ImGui::Checkbox(XorStr("XQZ/Glow color"), &g_Options.Visuals.XQZ);
		ImGui::SameLine();
		ImGui::MyColorEdit3("##43ESP", g_Options.Colors.EnemyChamsNVis, 1 << 7);
		ImGui::PushItemWidth(184);
		ImGui::SliderInt(XorStr("Chams Alpha"), &g_Options.Visuals.champlayeralpha, 0, 100);
		ImGui::Combo("##sdgl", &g_Options.Visuals.matierial, "Normal\0\rFlat\0\rWireframe\0\rGlass\0\rGold\0\rPlatinum\0\rPlastic\0\rCrystal\0\0", -1);
		ImGui::PushItemWidth(80);
		ImGui::Combo(XorStr("Hands"), &g_Options.Visuals.Hands, handd, ARRAYSIZE(handd));
		ImGui::SameLine();
		ImGui::MyColorEdit3(("##47ESP"), g_Options.Colors.hands_color, 1 << 7);
		ImGui::PushItemWidth(130);
		ImGui::SliderFloat(XorStr("Hands Alpha"), &g_Options.Colors.hands_alpha, 0.f, 1.f);
		ImGui::Text("Status");
		ImGui::Checkbox(("HasDefuser"), &g_Options.Visuals.HasDefuser);
		ImGui::Checkbox(("IsScoped"), &g_Options.Visuals.IsScoped);
		ImGui::Checkbox(("IsFlashed"), &g_Options.Visuals.Flashed);
	}
	ImGui::NextColumn();
	{
		ImGui::BeginChild(("Filter"), ImVec2(ImGui::GetWindowContentRegionWidth() * 0.5f, 19 * 2));
		{
			ImGui::Selectable((" Players"), &g_Options.Visuals.Filter.Players);
			ImGui::Selectable((" Enemy Only"), &g_Options.Visuals.Filter.EnemyOnly);
		} ImGui::EndChild();
		ImGui::Text("World");
		ImGui::Checkbox(("C4 - World"), &g_Options.Visuals.C4World);
		ImGui::Checkbox(("Weapons - World"), &g_Options.Visuals.WeaponsWorld);
		ImGui::Text("Crosshair Types");
		ImGui::Checkbox(("Spread Crosshair"), &g_Options.Visuals.SpreadCrosshair);
		ImGui::SameLine();
		ImGui::MyColorEdit3(XorStr("##23452"), (float*)&g_Options.Colors.color_spread, 1 << 7);
		ImGui::Checkbox(("Recoil Crosshair"), &g_Options.Visuals.RecoilCrosshair);
		ImGui::SameLine();
		ImGui::MyColorEdit3(XorStr("##95340"), (float*)&g_Options.Colors.color_recoil, 1 << 7);
	}
	ImGui::NextColumn();
	{

		ImGui::Checkbox(("No Post-Processing"), &g_Options.Misc.fps);
		ImGui::Checkbox(("No Visual Recoil"), &g_Options.Visuals.NoVisualRecoil);
		ImGui::SliderFloat(("FOV"), &g_Options.Visuals.FOVChanger, 0.f, 60.f, "%.0f");
		ImGui::SliderFloat(("viewmodel FOV"), &g_Options.Visuals.viewmodelChanger, 0.f, 120.f, "%.0f");
		ImGui::Checkbox(("NoFlash"), &g_Options.Visuals.NoFlash);
        ImGui::Checkbox(("NoSmoke"), &g_Options.Visuals.NoSmoke);
		ImGui::Checkbox(("Time"), &g_Options.Visuals.Time);
		ImGui::Checkbox(("Scope Border"), &g_Options.Visuals.noscopeborder);
		ImGui::PushItemWidth(80);
		ImGui::Checkbox(XorStr("Thirdperson"), &g_Options.Visuals.ThirdPerson);
		ImGui::PushItemWidth(125);
		ImGui::SliderFloat(XorStr("##tpdist"), &g_Options.Visuals.tpdist, 50.f, 450.f, "%.0f");
		ImGui::Hotkey(XorStr("Key##273"), &g_Options.Visuals.TPKey);
	}
}
bool memesaredank;

void RenderMisc()
{

	ImGui::Columns(3, NULL, true);
	{
		ImGui::Text("Misc"); ImGui::NextColumn(); ImGui::Text("Configuration"); ImGui::NextColumn(); ImGui::Text("Spammers"); ImGui::NextColumn(); ImGui::Separator();
		ImGui::Checkbox(XorStr("Show Competitive Ranks"), &g_Options.Misc.ServerRankRevealAll);
		ImGui::Checkbox(("Auto-Accept"), &g_Options.Misc.AutoAccept);
		ImGui::Checkbox(("Bunny Hop"), &g_Options.Misc.Bhop);
		ImGui::Checkbox(("AutoStrafe"), &g_Options.Misc.AutoStrafe);
		ImGui::Checkbox(("Watermark"), &g_Options.Misc.Watermark);
		ImGui::Checkbox(("SpecList"), &g_Options.Misc.SpecList);
	    ImGui::Checkbox(("Hitmarker"), &g_Options.Misc.Hitmarker); 
		ImGui::SameLine();
		ImGui::MyColorEdit3(("##fd5432"), g_Options.Colors.hitmark_color, 1 << 7);
		ImGui::PushItemWidth(146);
		ImGui::Combo(XorStr("HitSound"), &g_Options.Misc.hitsound, hitsound, _ARRAYSIZE(hitsound));
		ImGui::Text("Custom-Skybox:");
		ImGui::PushItemWidth(146);
		ImGui::Combo(("##aadk342"), &g_Options.Misc.Skybox, skybox_items, _ARRAYSIZE(skybox_items));
	}
	ImGui::NextColumn();
	{
		ImGui::PushItemWidth(100);
		ImGui::Combo(("File"), &g_Options.Menu.ConfigFile, configFiles, ARRAYSIZE(configFiles));
		if (ImGui::Button("Save Config")) Config->Save();
		ImGui::SameLine();
		if (ImGui::Button("Load Config")) Config->Load();
		ImGui::SameLine();
		if (ImGui::Button(XorStr("Unhook")))
		{
			g_Engine->ClientCmd_Unrestricted("cl_mouseenable 1");
			unload = true;
		}
		ImGui::Text("Themes");
		ImGui::Combo((""), &g_Options.Menu.Theme, themes, ARRAYSIZE(themes));
		ImGui::Text("World-Modes");
		ImGui::Checkbox(("NightMode"), &g_Options.Misc.nightMode);
		ImGui::Checkbox(("GrayMode"), &g_Options.Misc.Gray);
		ImGui::Checkbox(("LsdMode"), &g_Options.Misc.crack);
		ImGui::Checkbox(("ChromeMode"), &g_Options.Misc.chromatic);
		/*ImGui::ColorEditMode(ImGuiColorEditMode_RGB);
		ImGuiStyle &style = ImGui::GetStyle();
		ImGui::ColorEdit3("background", (float*)&g_Options.Colors.window_bg);*/
	}
	ImGui::NextColumn();
	{
		ImGui::Checkbox("Name Stealer", &g_Options.Misc.silentstealer);
		ImGui::SameLine();
		if (ImGui::Button("Silent exploit"))
		{
			static ConVar* name = g_CVar->FindVar("name");
			if (name)
			{
				*(int*)((DWORD)&name->fnChangeCallback + 0xC) = NULL;
				name->SetValue("\n");
			}
		}
		ImGui::Checkbox("NameSpammer", &g_Options.Misc.namespam);
		ImGui::Checkbox("GodLike Clantag", &g_Options.Misc.syncclantag);
		ImGui::Text(("Custom Name"));
		ImGui::PushItemWidth(150);
		static char buf1[128] = ""; ImGui::InputText(("##Name"), buf1, 128, ImGuiInputTextFlags_AllowTabInput);
		ImGui::SameLine();
		ImGui::PushItemWidth(50);
		if (ImGui::Button(("Change Name")))
		{
			ConVar* name = g_CVar->FindVar("name");
			if (name)
			{
				*(int*)((DWORD)&name->fnChangeCallback + 0xC) = NULL;
				name->SetValue(buf1);
			}
		}
		ImGui::Text(("Custom ClanTag"));
		ImGui::PushItemWidth(150);
		static char buf2[128] = ""; ImGui::InputText(("##Clantag"), buf2, 16, ImGuiInputTextFlags_AllowTabInput);
		ImGui::SameLine();
		ImGui::PushItemWidth(50);

		if (ImGui::Button(("Change Clantag")))
		{
			dankestSetClanTag(buf2, buf2);
		}
		ImGui::Text(("Animated ClanTag"));
		ImGui::PushItemWidth(150);
		ImGui::InputText(("##AnimatedClantag"), G::AnimatedClantag, 16, ImGuiInputTextFlags_AllowTabInput);
		ImGui::SameLine();
		ImGui::PushItemWidth(50);
		if (ImGui::Button(("Start")))
		{
			g_Options.Misc.animatedclantag = true;
		}
		ImGui::SameLine();
		ImGui::PushItemWidth(85);
		if (ImGui::Button(("Stop")))
		{
			g_Options.Misc.animatedclantag = false;
		}
		ImGui::Combo(("ChatSpammer"), &g_Options.Misc.spammer, spammers, ARRAYSIZE(spammers));
	}
}

void RenderSkinChanger()
{
	{
		ImGui::Checkbox(("Enabled"), &g_Options.Skinchanger.Enabled);
		ImGui::SameLine();
		ImGui::PushItemWidth(150);
		if (ImGui::Button(("Force Update")))
		{
			KnifeApplyCallbk();
		}


		ImGui::Separator();

		ImGui::Text("General");
		ImGui::Combo(("Knife Model"), &g_Options.Skinchanger.Knife, knives, ARRAYSIZE(knives));
		ImGui::Combo(("Knife Skin"), &g_Options.Skinchanger.KnifeSkin, knifeskins, ARRAYSIZE(knifeskins));
		ImGui::Combo(("Gloves"), &g_Options.Skinchanger.gloves, gloves, _ARRAYSIZE(gloves));


		ImGui::Columns(1);
		ImGui::Separator();
		ImGui::Text("Rifles");
		ImGui::Columns(2, NULL, false);
		ImGui::Combo(("AK-47"), &g_Options.Skinchanger.AK47Skin, ak47, ARRAYSIZE(ak47));
		ImGui::Combo(("M4A1-S"), &g_Options.Skinchanger.M4A1SSkin, m4a1s, ARRAYSIZE(m4a1s));
		ImGui::Combo(("M4A4"), &g_Options.Skinchanger.M4A4Skin, m4a4, ARRAYSIZE(m4a4));
		ImGui::Combo(("Galil AR"), &g_Options.Skinchanger.GalilSkin, galil, ARRAYSIZE(galil));
		ImGui::NextColumn();
		ImGui::Combo(("AUG"), &g_Options.Skinchanger.AUGSkin, aug, ARRAYSIZE(aug));
		ImGui::Combo(("FAMAS"), &g_Options.Skinchanger.FAMASSkin, famas, ARRAYSIZE(famas));
		ImGui::Combo(("Sg553"), &g_Options.Skinchanger.Sg553Skin, sg553, ARRAYSIZE(sg553));

		ImGui::Columns(1);
		ImGui::Separator();
		ImGui::Text("Snipers");
		ImGui::Columns(2, NULL, false);
		ImGui::Combo(("AWP"), &g_Options.Skinchanger.AWPSkin, awp, ARRAYSIZE(awp));
		ImGui::Combo(("SSG08"), &g_Options.Skinchanger.SSG08Skin, ssg08, ARRAYSIZE(ssg08));
		ImGui::NextColumn();
		ImGui::Combo(("SCAR20"), &g_Options.Skinchanger.SCAR20Skin, scar20, ARRAYSIZE(scar20));
		ImGui::Combo(("G3SG1"), &g_Options.Skinchanger.G3sg1Skin, g3sg1, ARRAYSIZE(g3sg1));

		ImGui::Columns(1);
		ImGui::Separator();
		ImGui::Text("SMG's");
		ImGui::Columns(2, NULL, false);
		ImGui::Combo(("P90"), &g_Options.Skinchanger.P90Skin, p90, ARRAYSIZE(p90));
		ImGui::Combo(("MP7"), &g_Options.Skinchanger.Mp7Skin, mp7, ARRAYSIZE(mp7));
		ImGui::Combo(("MP9"), &g_Options.Skinchanger.Mp9Skin, mp9, ARRAYSIZE(mp9));
		ImGui::NextColumn();
		ImGui::Combo(("UMP45"), &g_Options.Skinchanger.UMP45Skin, ump45, ARRAYSIZE(ump45));
		ImGui::Combo(("MAC-10"), &g_Options.Skinchanger.Mac10Skin, mac10, ARRAYSIZE(mac10));
		ImGui::Combo(("PP-Bizon"), &g_Options.Skinchanger.BizonSkin, bizon, ARRAYSIZE(bizon));

		ImGui::Columns(1);
		ImGui::Separator();
		ImGui::Text("Pistols");
		ImGui::Columns(2, NULL, false);
		ImGui::Combo(("Glock-18"), &g_Options.Skinchanger.GlockSkin, glock, ARRAYSIZE(glock));
		ImGui::Combo(("USP-S"), &g_Options.Skinchanger.USPSkin, usp, ARRAYSIZE(usp));
		ImGui::Combo(("Deagle"), &g_Options.Skinchanger.DeagleSkin, deagle, ARRAYSIZE(deagle));
		ImGui::Combo(("Five-Seven"), &g_Options.Skinchanger.FiveSkin, five, ARRAYSIZE(five));
		ImGui::Combo(("Revolver"), &g_Options.Skinchanger.RevolverSkin, revolver, ARRAYSIZE(revolver));

		ImGui::NextColumn();
		ImGui::Combo(("TEC-9"), &g_Options.Skinchanger.tec9Skin, tec9, ARRAYSIZE(tec9));
		ImGui::Combo(("P2000"), &g_Options.Skinchanger.P2000Skin, p2000, ARRAYSIZE(p2000));
		ImGui::Combo(("P250"), &g_Options.Skinchanger.P250Skin, p250, ARRAYSIZE(p250));
		ImGui::Combo(("Dual-Barettas"), &g_Options.Skinchanger.DualSkin, dual, ARRAYSIZE(dual));
		ImGui::Combo(("Cz75-Auto"), &g_Options.Skinchanger.Cz75Skin, cz75, ARRAYSIZE(cz75));

		ImGui::Columns(1);
		ImGui::Separator();
		ImGui::Text("Shotguns");
		ImGui::Columns(2, NULL, false);
		ImGui::Combo(("Nova"), &g_Options.Skinchanger.NovaSkin, nova, ARRAYSIZE(nova));
		ImGui::Combo(("Sawed-Off"), &g_Options.Skinchanger.SawedSkin, sawed, ARRAYSIZE(sawed));

		ImGui::NextColumn();
		ImGui::Combo(("Mag-7"), &g_Options.Skinchanger.MagSkin, mag, ARRAYSIZE(mag));
		ImGui::Combo(("XM1014"), &g_Options.Skinchanger.XmSkin, xm, ARRAYSIZE(xm));

		ImGui::Columns(1);
		ImGui::Separator();
		ImGui::Text("Machine Guns");
		ImGui::Columns(2, NULL, false);
		ImGui::Combo(("Negev"), &g_Options.Skinchanger.NegevSkin, negev, ARRAYSIZE(negev));

		ImGui::NextColumn();
		ImGui::Combo(("M249"), &g_Options.Skinchanger.M249Skin, m249, ARRAYSIZE(m249));
	}
}

