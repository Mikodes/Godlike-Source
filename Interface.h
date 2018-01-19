#pragma once
#include "Configuration.hpp"
#include "dropboxes.h"
#include "Variables.h"
#include "Tabs.h"
#include <chrono>
#include "Themes.h"

#define IM_ARRAYSIZE(_ARR)  ((int)(sizeof(_ARR)/sizeof(*_ARR)))


void RenderInterface() {
	// Place all item settings under a collapsing header.


		static int page = 0;

		switch(g_Options.Menu.Theme)
		{
		case 0:
			RenderDefault();
			break;
		case 1:
			RenderOld();
			break;
		}
		ImGui::SetNextWindowSize(ImVec2(960, 446), ImGuiSetCond_FirstUseEver);
		if (ImGui::Begin(XorStr("JUNKCODE?!!?"), &g_Options.Menu.Opened, ImGuiWindowFlags_NoCollapse | G::extra_flags))
		{
			const char* tabs[] = {
				"Legit",
				"Visuals",
				"Miscellaneous",
                "Skinchanger"
			};

			for (int i = 0; i < IM_ARRAYSIZE(tabs); i++)
			{

				//ImGui::GetStyle().Colors[ImGuiCol_Button] = ImColor(54, 54, 54, 255);

				if (ImGui::Button(tabs[i], ImVec2(ImGui::GetWindowSize().x / IM_ARRAYSIZE(tabs) - 9, 0)))
					page = i;

				//ImGui::GetStyle().Colors[ImGuiCol_Button] = ImColor(54, 54, 54, 255);

				if (i < IM_ARRAYSIZE(tabs) - 1)
					ImGui::SameLine();
			}

			ImGui::Separator();

			switch (page)
			{
			case 0:
                RenderLegit();
				break;
			case 1:
                RenderVisuals();
				break;
			case 2:
                RenderMisc();
				break;
			case 3:
                RenderSkinChanger();
				break;
			}
			ImGui::End();
		}
}
