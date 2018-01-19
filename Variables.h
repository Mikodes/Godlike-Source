#pragma once

extern void RenderInterface();

struct Variables
{
	Variables()
	{

	}

	struct Ragebot_s
	{
		bool MainSwitch;
		bool 	Enabled;
		bool 	AutoFire;
		float 	FOV;
		bool 	Silent;
		bool AutoPistol;
		int KeyPress;
		bool AimStep;
		

			bool	EnabledAntiAim;
			int		Pitch;
			int		YawTrue;
			int		YawFake;
			bool	AtTarget;
			bool	Edge;
			bool KnifeAA;


			bool FriendlyFire;
			int		Hitbox;
			int		Hitscan;
			float Pointscale;
			bool Multipoint;
			float Multipoints;


			bool AntiRecoil;
			bool AutoWall;
			bool AutoStop;
			bool AutoCrouch;
			bool AutoScope;
			float MinimumDamage;
			bool Hitchance;
			float HitchanceAmount;
			bool Resolver;
			bool FakeLagFix;
			bool playerlist;
            int BAIMkey;
	} Ragebot;

	struct
	{
		bool MainSwitch;
        bool backtrack;
		float backtrackTicks;
		bool AutoPistol;
		
		struct
		{
			bool 	Enabled;
			bool AutoPistol;
			bool	Resolver;
            
		} Aimbot;


			int MainKey = 1;
            float MainSmooth;
			float Mainfov;
            float main_random_smooth;
            float main_recoil_min;
            float main_recoil_max;
            float main_randomized_angle;



			int PistolKey = 6;
			float Pistolfov;
			float PistolSmooth;
            float pistol_random_smooth;
            float pistol_recoil_min;
            float pistol_recoil_max;
            float pistol_randomized_angle;



			int SniperKey = 6;
			float Sniperfov;
			float SniperSmooth;
            float sniper_random_smooth;
            float sniper_recoil_min;
            float sniper_recoil_max;
            float sniper_randomized_angle;
			
			struct
			{
				bool Head;
				bool Arms;
				bool Chest;
				bool Stomach;
				bool Legs;
			}Filter;

		struct
		{
			bool	Enabled;
			float Delay;
			int Key = 6;
			float hitchance;
			struct
			{
				bool Head;
				bool Arms;
				bool Chest;
				bool Stomach;
				bool Legs;
			} Filter;

		} Triggerbot;

	} Legitbot;

	struct 
	{
		bool 	Enabled;

		bool Box;
		bool Name;
		bool HP;
		bool Weapon;
		bool Info;
		bool Chams;
		bool Skeleton;
		bool DrawSkeleton;
		bool AimSpot;
		bool DLight;
		bool SpreadCrosshair;
		bool GrenadeESP;
		bool C4;
		bool backtrackline;
		bool RecoilCrosshair;
		bool Glow;
		bool IsScoped;
		bool HasDefuser;
		bool NoVisualRecoil;
		int Hands;
		int Weapons;
		float FOVChanger;
		float viewmodelChanger;
		bool NoFlash;
		bool NoSmoke;
		int TPKey;
		float tpdist = 200;
		bool ThirdPerson;
		bool Time;
		bool Flashed;
		bool money;
		bool C4World;
		bool WeaponsWorld;
		bool noscopeborder;
		bool GrenadePrediction;

		bool handcham;
		bool weaponviewcham;
		int chamhandalpha;

		int weaponmat;
		int handmat;
		int weaponhandalpha;

		int matierial;
		bool outline;
		bool Teamchams;
		int champlayeralpha;

		bool Chamweapon;
		bool XQZ;

		int HitmarkerSound;

		bool DrawAwall;

		struct
		{
			bool Players;
			bool EnemyOnly;
		} Filter;

		struct
		{
			bool Players;
			bool EnemyOnly;
			bool Weapons;
			bool DynamicBox;
		} GlowFilter;

	} Visuals;

	struct misc_s
	{
        bool silentstealer;
        int ragequit;
		bool 	Bhop;
		bool 	AutoStrafe;
		float MinVel;
		int		AirStuckKey;
		int lagexploit;
		int lagexploitmultiplier = 3;
		float lagexploitvalue;
		float FakeLag;
		bool AdaptiveFakeLag;
        bool nightMode;
		int NameSpammer;
		bool NameChangerFix;
		bool NoName;
		int		ChatSpamMode;
		bool ClantagChanger;
		int ClanTagSpeed;
        bool syncclantag;
		bool SpecList;
		bool FPSBooster;
		int SkyBoxChanger;
        bool namespam;
        int spammer;
		int AutoDefuse;
		bool Spam;
		bool isRecording;
		bool isReplaying;
		bool RecordPath;
		bool AutoAccept;
		bool SpoofConfirmation = false;
		bool animatedclantag = false;
		int customtab;
		bool fps;
		bool ServerRankRevealAll;
        bool niggatest;
		bool Hitmarker;
		int hitsound;
		int HitMarkerColor;
		bool Watermark;
		int Skybox;
		int CurrentSky;
		bool bought;

		bool Gray;
		bool crack;
		bool chromatic;
	} Misc;
	struct
	{
		bool Enabled;
		int Knife;
		int gloves;
		int KnifeSkin;
		int AK47Skin;
		int GalilSkin;
		int M4A1SSkin;
		int M4A4Skin;
		int AUGSkin;
		int FAMASSkin;
		int AWPSkin;
		int SSG08Skin;
		int SCAR20Skin;
		int P90Skin;
		int Mp7Skin;
		int NovaSkin;
		int UMP45Skin;
		int GlockSkin;
		int SawedSkin;
		int USPSkin;
		int MagSkin;
		int XmSkin;
		int DeagleSkin;
		int DualSkin;
		int FiveSkin;
		int RevolverSkin;
		int Mac10Skin;
		int tec9Skin;
		int Cz75Skin;
		int NegevSkin;
		int M249Skin;
		int Mp9Skin;
		int P2000Skin;
		int BizonSkin;
		int Sg553Skin;
		int P250Skin;
		int G3sg1Skin;
		bool activeknife;
	} Skinchanger;

	struct
	{
		bool	Opened = true;
		int 	Key;
		bool	Ragebot = false;
		bool	Legitbot = false;
		bool	Visual = false;
		bool	Misc = false;
		int		ConfigFile = 0;
		int		Theme = 0;
		bool	Colors = false;
		int     menu_hitbox_select;
	} Menu;

	struct
	{
		float TeamESP[3] = { 0, 1.f, 0 };
		float EnemyESP[3] = { 1.f, 0, 0 };
		float TeamDLights[3] = { 0, 1.f, 0 };
		float EnemyDLights[3] = { 1.f, 0, 0 };
		float EnemyGlow[3] = { 1.f, 0, 0 };
		float TeamGlow[3] = { 0, 1.f, 0 };
		float WeaponGlow[3] = { 1.f, 0, 0 };
		float C4glow[3] = { 1.f, 0, 0 };
		float EnemyChamsVis[3] = { 1.f, 0, 0 };
		float EnemyChamsNVis[3] = { 1.f, 0, 0 };
		float TeamChamsVis[3] = { 0, 1.f, 0 };
		float TeamChamsNVis[3] = { 0, 1.f, 0 };
		float WeaponCham[3] = { 1.f, 0, 0 };
		float HandCham[3] = { 1.f, 0, 0 };
		float WeaponViewCham[3] = { 1.f, 0, 0 };
		float hands_color[3] = { 1.f, 0, 0 };
		float hands_alpha;
		float tracer_color[3] = { 1.f, 0, 0 };
		float box_color_t[3] = { 1.f, 0, 0 };
		float box_color_ct[3] = { 1.f, 0, 0 };
		float color_skeleton[3] = { 1.f, 1.f, 1.f };
		float color_spread[3] = { 0, 1.f, 0 };
		float color_recoil[3] = { 0, 0, 1.f };
		float dlight_color[3] = { 0, 1.f, 0 };
		float hitmark_color[3] = { 0, 0, 1.f };
		float backtrackdots_color[3] = { 1.f, 0, 0 };
		float window_bg[3] = { 0.15f, 0.14f, 0.15f };
	}Colors;
};

extern Variables g_Options;