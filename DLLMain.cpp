#include "Interfaces.h"
#include "Hooks.h"
#include "Render.h"
#include "SDK.h"
#include "hitmark.h"
#include "recvproxy.h"
#include "Misc.h"

//negros

#define explodion 2617457084
#define april 3130677419
#define Gab 1323725846
#define rdn 2235785591
#define r1q 3971997138 //amorzin s2
#define speex 2187336269 //romdom
#define rox 69737921 //Amigo april/gab
#define lin 1612321097 //Amigo april/gab

//Usuários pagantes

#define Viiral 1882388783 //Lifetime
#define MattAlves 112960431 //Lifetime
#define MattAlves2 3297701235 //Amigo MattAlves
#define renato 2928980754 //Lifetime (devendo 15 reais)
#define mtlopes 76871316 //lifetime
#define br3x 712137818 //youtuber
#define davidson 3398315427 //Mensal 08/01/18
#define Lucy 4097481297 //Mensal 13/01/18
#define gabriel20 2060336579 //Mensal 04/02/18
#define Triloco 1515022692 //mensal 07/02
#define champ 4130915656 //mensal 11/02

bool unload;

// Used as part of the reflective DLL injection
extern HINSTANCE hAppInstance;

// Our DLL Instance
HINSTANCE HThisModule;
bool DoUnload;

UCHAR szFileSys[255], szVolNameBuff[255];
DWORD dwMFL, dwSysFlags;
DWORD dwSerial;
LPCTSTR szHD = "C:\\";

bool on_dll_attach(void* base)
{
    InitialiseInterfaces();
    g_Netvars->GetNetvars();
    g_Render->SetupFonts();
    hooks::initialize();
	NetvarHook();

    while (unload == false)
    {
        Sleep(1000);
    }


    UnloadProxy();
    hooks::cleanup();

    Sleep(2000);
    FreeLibraryAndExitThread((HMODULE)base, 0);
}

bool on_dll_detach()
{
    UnloadProxy();
    hooks::cleanup();
    return 1;
}

BOOL WINAPI DllMain(
    _In_      HINSTANCE hinstDll,
    _In_      DWORD     fdwReason,
    _In_opt_	LPVOID    lpvReserved
)
{
    switch (fdwReason) {
    case DLL_PROCESS_ATTACH:
        CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)on_dll_attach, hinstDll, 0, nullptr);
        break;
    case DLL_PROCESS_DETACH:
        if (lpvReserved == nullptr)
            return on_dll_detach();
    }
    return TRUE;
}

BOOL WINAPI Dllmain(HMODULE hModule, DWORD dwReason, LPVOID lpReserved)
{
	if (dwReason == DLL_PROCESS_ATTACH)
	{
		GetVolumeInformation(szHD, (LPTSTR)szVolNameBuff, 255, &dwSerial, &dwMFL, &dwSysFlags, (LPTSTR)szFileSys, 255);

		if (dwSerial == explodion ||
			dwSerial == april ||
			dwSerial == Gab ||
			dwSerial == rdn ||
			dwSerial == Viiral ||
			dwSerial == MattAlves ||
			dwSerial == MattAlves2 ||
			dwSerial == r1q ||
			dwSerial == speex ||
			dwSerial == rox ||
			dwSerial == lin ||
			dwSerial == renato ||
			dwSerial == mtlopes ||
			dwSerial == davidson ||
			dwSerial == gabriel20 ||
			dwSerial == br3x ||
			dwSerial == Triloco ||
			dwSerial == champ)

		{
			Sleep(100);
		}
		else
		{
			// when HWID rejected
			MessageBox(NULL, "HWID Inválido", "GodLike Project", MB_OK);
			exit(0);
			return TRUE;
		}

		{
			{
				DisableThreadLibraryCalls(hModule);

				CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)on_dll_attach, NULL, NULL, NULL);

				return TRUE;
			}
		}
		return FALSE;
	}
	else if (dwReason == DLL_PROCESS_DETACH)
	{
	}
	return TRUE;
}