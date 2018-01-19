#pragma once
#include "Interface.h"

void RenderDefault()
{
	ImGuiStyle& style = ImGui::GetStyle();


	style.Alpha = 1.0f;
	style.WindowPadding = ImVec2(8, 8);
	style.WindowRounding = 0.0f;
	style.WindowTitleAlign = ImVec2(0.5f, 0.5f);
	style.ChildWindowRounding = 3.0f;
	style.FramePadding = ImVec2(4, 3);
	style.FrameRounding = 0.0f;
	style.ItemSpacing = ImVec2(8, 4);
	style.ItemInnerSpacing = ImVec2(4, 4);
	style.TouchExtraPadding = ImVec2(0, 0);
	style.IndentSpacing = 21.0f;
	style.ColumnsMinSpacing = 6.0f;
	style.ScrollbarSize = 10.0f;
	style.ScrollbarRounding = 3.0f;
	style.GrabMinSize = 10.0f;
	style.GrabRounding = 0.0f;
	style.ButtonTextAlign = ImVec2(0.5f, 0.5f);
	style.DisplayWindowPadding = ImVec2(22, 22);
	style.DisplaySafeAreaPadding = ImVec2(4, 4);
	style.AntiAliasedLines = true;
	style.AntiAliasedShapes = true;
	style.CurveTessellationTol = 1.25f;
	style.AntiAliasedLines = true;
	style.AntiAliasedShapes = true;
	style.CurveTessellationTol = 1.25f;
	
	ImVec4 window_bg = ImColor(0.15f, 0.14f, 0.15f);

	style.Colors[ImGuiCol_Text] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
	style.Colors[ImGuiCol_TextDisabled] = ImVec4(0.60f, 0.60f, 0.60f, 1.00f);
	style.Colors[ImGuiCol_WindowBg] = ImVec4(0.11f, 0.10f, 0.11f, 1.00f);
	style.Colors[ImGuiCol_ChildWindowBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
	style.Colors[ImGuiCol_PopupBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
	style.Colors[ImGuiCol_Border] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
	style.Colors[ImGuiCol_BorderShadow] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
	style.Colors[ImGuiCol_FrameBg] = ImVec4(0.21f, 0.20f, 0.21f, 0.60f);
	style.Colors[ImGuiCol_FrameBgHovered] = ImVec4(0.00f, 0.46f, 0.65f, 1.00f);
	style.Colors[ImGuiCol_FrameBgActive] = ImVec4(0.00f, 0.46f, 0.65f, 1.00f);
	style.Colors[ImGuiCol_TitleBg] = ImVec4(0.00f, 0.46f, 0.65f, 0.91f);
	style.Colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.00f, 0.46f, 0.65f, 0.91f);
	style.Colors[ImGuiCol_TitleBgActive] = ImVec4(0.00f, 0.46f, 0.65f, 0.91f);
	style.Colors[ImGuiCol_MenuBarBg] = ImVec4(0.00f, 0.46f, 0.65f, 1.00f);
	style.Colors[ImGuiCol_ScrollbarBg] = ImVec4(0.00f, 0.46f, 0.65f, 0.00f);
	style.Colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.00f, 0.46f, 0.65f, 0.44f);
	style.Colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.00f, 0.46f, 0.65f, 0.74f);
	style.Colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.00f, 0.46f, 0.65f, 1.00f);
	style.Colors[ImGuiCol_ComboBg] = ImVec4(window_bg.x, window_bg.y, window_bg.z, 1.00f);
	//style.Colors[ImGuiCol_ComboBg] = ImVec4(0.15f, 0.14f, 0.15f, 1.00f);
	style.Colors[ImGuiCol_CheckMark] = ImVec4(0.00f, 0.46f, 0.65f, 1.00f);
	style.Colors[ImGuiCol_SliderGrab] = ImVec4(0.00f, 0.46f, 0.65f, 1.00f);
	style.Colors[ImGuiCol_SliderGrabActive] = ImVec4(0.00f, 0.46f, 0.65f, 1.00f);
	style.Colors[ImGuiCol_Button] = ImVec4(0.00f, 0.46f, 0.65f, 1.00f);
	style.Colors[ImGuiCol_ButtonHovered] = ImVec4(0.00f, 0.46f, 0.65f, 1.00f);
	style.Colors[ImGuiCol_ButtonActive] = ImVec4(0.00f, 0.46f, 0.65f, 1.00f);
	style.Colors[ImGuiCol_Header] = ImVec4(0.00f, 0.46f, 0.65f, 1.00f);
	style.Colors[ImGuiCol_HeaderHovered] = ImVec4(0.00f, 0.46f, 0.65f, 1.00f);
	style.Colors[ImGuiCol_HeaderActive] = ImVec4(0.00f, 0.46f, 0.65f, 1.00f);
	style.Colors[ImGuiCol_Column] = ImVec4(0.50f, 0.50f, 0.50f, 0.33f);
	style.Colors[ImGuiCol_ColumnHovered] = ImVec4(0.50f, 0.50f, 0.50f, 0.47f);
	style.Colors[ImGuiCol_ColumnActive] = ImVec4(0.70f, 0.70f, 0.70f, 1.00f);
	style.Colors[ImGuiCol_ResizeGrip] = ImVec4(1.00f, 1.00f, 1.00f, 0.30f);
	style.Colors[ImGuiCol_ResizeGripHovered] = ImVec4(1.00f, 1.00f, 1.00f, 0.60f);
	style.Colors[ImGuiCol_ResizeGripActive] = ImVec4(1.00f, 1.00f, 1.00f, 0.90f);
	style.Colors[ImGuiCol_CloseButton] = ImVec4(1.00f, 0.10f, 0.24f, 0.00f);
	style.Colors[ImGuiCol_CloseButtonHovered] = ImVec4(0.00f, 0.10f, 0.24f, 0.00f);
	style.Colors[ImGuiCol_CloseButtonActive] = ImVec4(1.00f, 0.10f, 0.24f, 0.00f);
	style.Colors[ImGuiCol_PlotLines] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
	style.Colors[ImGuiCol_PlotLinesHovered] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
	style.Colors[ImGuiCol_PlotHistogram] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
	style.Colors[ImGuiCol_PlotHistogramHovered] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
	style.Colors[ImGuiCol_TextSelectedBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
	style.Colors[ImGuiCol_ModalWindowDarkening] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
}

void RenderOld()
{
	ImGuiStyle& style = ImGui::GetStyle();


	style.Alpha = 1.0f;
	style.WindowPadding = ImVec2(8, 8);
	style.WindowRounding = 0.0f;
	style.WindowTitleAlign = ImVec2(0.5f, 0.5f);
	style.ChildWindowRounding = 3.0f;
	style.FramePadding = ImVec2(4, 3);
	style.FrameRounding = 0.0f;
	style.ItemSpacing = ImVec2(8, 4);
	style.ItemInnerSpacing = ImVec2(4, 4);
	style.TouchExtraPadding = ImVec2(0, 0);
	style.IndentSpacing = 21.0f;
	style.ColumnsMinSpacing = 6.0f;
	style.ScrollbarSize = 10.0f;
	style.ScrollbarRounding = 3.0f;
	style.GrabMinSize = 10.0f;
	style.GrabRounding = 0.0f;
	style.ButtonTextAlign = ImVec2(0.5f, 0.5f);
	style.DisplayWindowPadding = ImVec2(22, 22);
	style.DisplaySafeAreaPadding = ImVec2(4, 4);
	style.AntiAliasedLines = true;
	style.AntiAliasedShapes = true;
	style.CurveTessellationTol = 1.25f;

	style.Colors[ImGuiCol_Text] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
	style.Colors[ImGuiCol_TextDisabled] = ImVec4(0.60f, 0.60f, 0.60f, 1.00f);
	style.Colors[ImGuiCol_WindowBg] = ImVec4(0.11f, 0.10f, 0.11f, 1.00f);
	style.Colors[ImGuiCol_ChildWindowBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
	style.Colors[ImGuiCol_PopupBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
	style.Colors[ImGuiCol_Border] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
	style.Colors[ImGuiCol_BorderShadow] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
	style.Colors[ImGuiCol_FrameBg] = ImVec4(0.21f, 0.20f, 0.21f, 1.00f);
	style.Colors[ImGuiCol_FrameBgHovered] = ImVec4(0.39f, 0.20f, 0.21f, 1.00f);
	style.Colors[ImGuiCol_FrameBgActive] = ImVec4(0.90f, 0.20f, 0.21f, 1.00f);
	style.Colors[ImGuiCol_TitleBg] = ImVec4(0.75f, 0.11f, 0.22f, 0.91f);
	style.Colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.75f, 0.11f, 0.22f, 0.91f);
	style.Colors[ImGuiCol_TitleBgActive] = ImVec4(0.75f, 0.11f, 0.22f, 0.91f);
	style.Colors[ImGuiCol_MenuBarBg] = ImVec4(0.75f, 0.11f, 0.22f, 1.00f);
	style.Colors[ImGuiCol_ScrollbarBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
	style.Colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.75f, 0.11f, 0.22f, 1.00f);
	style.Colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.51f, 0.11f, 0.17f, 1.00f);
	style.Colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.35f, 0.10f, 0.17f, 1.00f);
	style.Colors[ImGuiCol_ComboBg] = ImVec4(0.00f, 0.00f, 0.00f, 1.00f);
	style.Colors[ImGuiCol_CheckMark] = ImVec4(0.83f, 0.11f, 0.28f, 1.00f);
	style.Colors[ImGuiCol_SliderGrab] = ImVec4(0.75f, 0.11f, 0.22f, 1.00f);
	style.Colors[ImGuiCol_SliderGrabActive] = ImVec4(0.51f, 0.10f, 0.17f, 1.00f);
	style.Colors[ImGuiCol_Button] = ImVec4(0.76f, 0.10f, 0.24f, 1.00f);
	style.Colors[ImGuiCol_ButtonHovered] = ImVec4(0.63f, 0.10f, 0.24f, 1.00f);
	style.Colors[ImGuiCol_ButtonActive] = ImVec4(0.55f, 0.10f, 0.24f, 1.00f);
	style.Colors[ImGuiCol_Header] = ImVec4(0.75f, 0.11f, 0.22f, 1.00f);
	style.Colors[ImGuiCol_HeaderHovered] = ImVec4(0.51f, 0.11f, 0.17f, 1.00f);
	style.Colors[ImGuiCol_HeaderActive] = ImVec4(0.40f, 0.11f, 0.17f, 1.00f);
	style.Colors[ImGuiCol_Column] = ImVec4(0.75f, 0.10f, 0.24f, 1.00f);
	style.Colors[ImGuiCol_ColumnHovered] = ImVec4(0.51f, 0.11f, 0.17f, 1.00f);
	style.Colors[ImGuiCol_ColumnActive] = ImVec4(0.40f, 0.11f, 0.17f, 1.00f);
	style.Colors[ImGuiCol_ResizeGrip] = ImVec4(1.00f, 1.00f, 1.00f, 0.30f);
	style.Colors[ImGuiCol_ResizeGripHovered] = ImVec4(1.00f, 1.00f, 1.00f, 0.60f);
	style.Colors[ImGuiCol_ResizeGripActive] = ImVec4(1.00f, 1.00f, 1.00f, 0.90f);
	style.Colors[ImGuiCol_CloseButton] = ImVec4(1.00f, 0.10f, 0.24f, 1.00f);
	style.Colors[ImGuiCol_CloseButtonHovered] = ImVec4(1.00f, 0.10f, 0.24f, 1.00f);
	style.Colors[ImGuiCol_CloseButtonActive] = ImVec4(1.00f, 0.10f, 0.24f, 1.00f);
	style.Colors[ImGuiCol_PlotLines] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
	style.Colors[ImGuiCol_PlotLinesHovered] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
	style.Colors[ImGuiCol_PlotHistogram] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
	style.Colors[ImGuiCol_PlotHistogramHovered] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
	style.Colors[ImGuiCol_TextSelectedBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
	style.Colors[ImGuiCol_ModalWindowDarkening] = ImVec4(0.00f, 0.00f, 0.00f, 0.35f);
}