.set LOCALID_RYDEL1, 16
.set LOCALID_RYDEL2, 17

CyclingRoad_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CyclingRoad_OnTransition
	.byte 0

CyclingRoad_OnTransition:
	call CyclingRoad_EventScript_RemoveRydel
	call_if_eq VAR_OLD_GUYS_STATE, 6, CyclingRoad_EventScript_SetRydel
	end

CyclingRoad_EventScript_RemoveRydel::
	removeobject LOCALID_RYDEL1
	removeobject LOCALID_RYDEL2
	setflag FLAG_TEMP_11
	setflag FLAG_TEMP_12
	setvar VAR_TEMP_3, 1
	setvar VAR_TEMP_4, 1
	return

CyclingRoad_EventScript_SetRydel::
	clearflag FLAG_TEMP_11
	clearflag FLAG_TEMP_12
	addobject LOCALID_RYDEL1
	addobject LOCALID_RYDEL2
	setvar VAR_TEMP_3, 0
	setvar VAR_TEMP_4, 0
	setvar VAR_BARD_COLOR, MAUVILLE_MAN_HIPSTER
	special SetMauvilleOldManObjEventGfx
	return	

CyclingRoad_EventScript_RydelHype1::
	playse SE_APPLAUSE
	applymovement LOCALID_RYDEL1, CyclingRoad_Movement_HopUp
	message CyclingRoad_Text_RydelHype1
	setvar VAR_TEMP_3, 1
	end

CyclingRoad_EventScript_RydelHype2::
	playse SE_APPLAUSE
	applymovement LOCALID_RYDEL2, CyclingRoad_Movement_HopUp
	message CyclingRoad_Text_RydelHype2
	setvar VAR_TEMP_4, 1
	end

CyclingRoad_Movement_HopUp:
	jump_in_place_left
	jump_in_place_right
	jump_in_place_down
	step_end

CyclingRoad_EventScript_Rhode::
    trainerbattle_single TRAINER_P_RHODE, CyclingRoad_Text_RhodeIntro, CyclingRoad_Text_RhodeDefeated
    msgbox CyclingRoad_Text_RhodePostBattle, MSGBOX_AUTOCLOSE
    end

CyclingRoad_EventScript_Cruz::
    trainerbattle_single TRAINER_P_CRUZ, CyclingRoad_Text_CruzIntro, CyclingRoad_Text_CruzDefeated
    msgbox CyclingRoad_Text_CruzPostBattle, MSGBOX_AUTOCLOSE
    end

CyclingRoad_EventScript_Mona::
    trainerbattle_single TRAINER_P_MONA, CyclingRoad_Text_MonaIntro, CyclingRoad_Text_MonaDefeated
    msgbox CyclingRoad_Text_MonaPostBattle, MSGBOX_AUTOCLOSE
    end

CyclingRoad_EventScript_Solo::
    trainerbattle_single TRAINER_P_SOLO, CyclingRoad_Text_SoloIntro, CyclingRoad_Text_SoloDefeated
    msgbox CyclingRoad_Text_SoloPostBattle, MSGBOX_AUTOCLOSE
    end

CyclingRoad_EventScript_Hichael::
    trainerbattle_single TRAINER_P_HICHAEL, CyclingRoad_Text_HichaelIntro, CyclingRoad_Text_HichaelDefeated
    msgbox CyclingRoad_Text_HichaelPostBattle, MSGBOX_AUTOCLOSE
    end

CyclingRoad_EventScript_Penny::
    trainerbattle_single TRAINER_P_PENNY, CyclingRoad_Text_PennyIntro, CyclingRoad_Text_PennyDefeated
    msgbox CyclingRoad_Text_PennyPostBattle, MSGBOX_AUTOCLOSE
    end

CyclingRoad_EventScript_Junior::
    trainerbattle_single TRAINER_P_JUNIOR, CyclingRoad_Text_JuniorIntro, CyclingRoad_Text_JuniorDefeated
    msgbox CyclingRoad_Text_JuniorPostBattle, MSGBOX_AUTOCLOSE
    end

CyclingRoad_EventScript_Hichaelson::
    trainerbattle_single TRAINER_P_HICHAELSON, CyclingRoad_Text_HichaelsonIntro, CyclingRoad_Text_HichaelsonDefeated
    msgbox CyclingRoad_Text_HichaelsonPostBattle, MSGBOX_AUTOCLOSE
    end

CyclingRoad_EventScript_Lulu::
    trainerbattle_single TRAINER_P_LULU, CyclingRoad_Text_LuluIntro, CyclingRoad_Text_LuluDefeated
    msgbox CyclingRoad_Text_LuluPostBattle, MSGBOX_AUTOCLOSE
    end

CyclingRoad_EventScript_Kaira::
    trainerbattle_single TRAINER_P_KAIRA, CyclingRoad_Text_KairaIntro, CyclingRoad_Text_KairaDefeated
    msgbox CyclingRoad_Text_KairaPostBattle, MSGBOX_AUTOCLOSE
    end

CyclingRoad_EventScript_Woody::
    trainerbattle_single TRAINER_P_WOODY, CyclingRoad_Text_WoodyIntro, CyclingRoad_Text_WoodyDefeated
    msgbox CyclingRoad_Text_WoodyPostBattle, MSGBOX_AUTOCLOSE
    end

CyclingRoad_EventScript_Ana::
    trainerbattle_single TRAINER_P_ANA, CyclingRoad_Text_AnaIntro, CyclingRoad_Text_AnaDefeated
    msgbox CyclingRoad_Text_AnaPostBattle, MSGBOX_AUTOCLOSE
    end

CyclingRoad_EventScript_Yoko::
    trainerbattle_single TRAINER_P_YOKO, CyclingRoad_Text_YokoIntro, CyclingRoad_Text_YokoDefeated
    msgbox CyclingRoad_Text_YokoPostBattle, MSGBOX_AUTOCLOSE
    end

CyclingRoad_EventScript_Flats::
    trainerbattle_single TRAINER_P_FLATS, CyclingRoad_Text_FlatsIntro, CyclingRoad_Text_FlatsDefeated
    msgbox CyclingRoad_Text_FlatsPostBattle, MSGBOX_AUTOCLOSE
    end

CyclingRoad_EventScript_Phillip::
    trainerbattle_single TRAINER_P_PHILLIP, CyclingRoad_Text_PhillipIntro, CyclingRoad_Text_PhillipDefeated
    msgbox CyclingRoad_Text_PhillipPostBattle, MSGBOX_AUTOCLOSE
    end

CyclingRoad_Text_RhodeIntro:
	.string "Cycling Road isn't for newbs!\n"
	.string "Show me what you got!$"

CyclingRoad_Text_RhodeDefeated:
	.string "I guess the training wheels are off...$"

CyclingRoad_Text_RhodePostBattle:
	.string "It's way too easy to bump into other\n"
	.string "people here.\p"
	.string "I've got bruises the size of Poké Balls.$"

CyclingRoad_Text_CruzIntro:
	.string "Care for an uphill battle?$"

CyclingRoad_Text_CruzDefeated:
	.string "It's all downhill from here...$"

CyclingRoad_Text_CruzPostBattle:
	.string "Biking uphill is slow, but once you reach\n"
	.string "downhill, you can zoom on by!\p"
	.string "So long as you don't hit anything...$"

CyclingRoad_Text_MonaIntro:
	.string " Hey, you're blocking the way!\n"
	.string "No matter what, I'll push through!$"

CyclingRoad_Text_MonaDefeated:
	.string "You've stopped me dead in my tracks.\n"
	.string "But that doesn't matter!$"

CyclingRoad_Text_MonaPostBattle:
	.string "Blocking my path...\n"
	.string "are walls, mountains, and even planets!\p"
	.string "I'll carve a road through them and move\n"
	.string "forward!$"

CyclingRoad_Text_SoloIntro:
	.string "On your left! On your right!\n"
	.string "Hey, why aren't you moving!?$"

CyclingRoad_Text_SoloDefeated:
	.string "What hand signal do you use if you're\n"
	.string "turning all the way down?$"

CyclingRoad_Text_SoloPostBattle:
	.string "(Huff, puff...)\n"
	.string "Just gotta... regain my strength.$"

CyclingRoad_Text_HichaelIntro:
	.string "I seem to be lost... Can you help me?$"

CyclingRoad_Text_HichaelDefeated:
	.string "Whoops.$"

CyclingRoad_Text_HichaelPostBattle:
	.string "I come from a family of hiking\n"
	.string "enthusiasts.\p"
	.string "I'm so glad they gave me this cool and\n"
	.string "unique name!$"

CyclingRoad_Text_PennyIntro:
	.string "Whoa! I'm jealous of how fast you\n"
	.string "cycle...$"

CyclingRoad_Text_PennyDefeated:
	.string "Nice hustle! I'm not even winded!$"

CyclingRoad_Text_PennyPostBattle:
	.string "Yeah, that's right.\n"
	.string "I'm using an electric bike!\p"
	.string "What's wrong with that, huh!? HUH!?$"

CyclingRoad_Text_JuniorIntro:
	.string "I'm using tilt controls!$"

CyclingRoad_Text_JuniorDefeated:
	.string "I'm using tilt controls!$"

CyclingRoad_Text_JuniorPostBattle:
	.string "I'm using tilt controls!$"

CyclingRoad_Text_HichaelsonIntro:
	.string "Im looking for my father, I heard he has\n"
	.string "a unique name like mine.$"

CyclingRoad_Text_HichaelsonDefeated:
	.string "I swear on my name... I will find you...\n"
	.string "Dad.$"

CyclingRoad_Text_HichaelsonPostBattle:
	.string "I've been on a journey to find my dad,\n"
	.string "whom I have not seen since I was a\n"
	.string "child.$"

CyclingRoad_Text_LuluIntro:
	.string "Woof...\n"
	.string "I feel like I'm melting in this parka.$"

CyclingRoad_Text_LuluDefeated:
	.string "Now I'm only heating up more...$"

CyclingRoad_Text_LuluPostBattle:
	.string "Am I crazy? Or am I just a cycle path?$"

CyclingRoad_Text_KairaIntro:
	.string "It has taken me years to master the\n"
	.string "bow.\p"
	.string "Similarly, it also takes many years to\n"
	.string "master the art of Pokémon battling!$"

CyclingRoad_Text_KairaDefeated:
	.string "Amazing... so young, yet so skilled.$"

CyclingRoad_Text_KairaPostBattle:
	.string "It isn't very often the world is blessed\n"
	.string "with a prodigy, so I shall give you some\l"
	.string "advice.\p"
	.string "Hone your skills to perfection, no\n"
	.string "matter how difficult the process may be..$"

CyclingRoad_Text_WoodyIntro:
	.string "Be kind to me, I'm just a little\n"
	.string "acoustic.$"

CyclingRoad_Text_WoodyDefeated:
	.string "That resonated with me.$"

CyclingRoad_Text_WoodyPostBattle:
	.string "This Poké Ball kills fascists.$"

CyclingRoad_Text_AnaIntro:
	.string "intro$"

CyclingRoad_Text_AnaDefeated:
	.string "defeat$"

CyclingRoad_Text_AnaPostBattle:
	.string "post$"

CyclingRoad_Text_YokoIntro:
	.string "intro$"

CyclingRoad_Text_YokoDefeated:
	.string "defeat$"

CyclingRoad_Text_YokoPostBattle:
	.string "post$"

CyclingRoad_Text_FlatsIntro:
	.string "Oh, I'll fix you up REAL good.$"

CyclingRoad_Text_FlatsDefeated:
	.string "Keep it together...$"

CyclingRoad_Text_FlatsPostBattle:
	.string "My business partner here has a few\n"
	.string "screws missing.$"

CyclingRoad_Text_PhillipIntro:
	.string "Don't get it twisted...$"

CyclingRoad_Text_PhillipDefeated:
	.string "Ah! I've been screwed...$"

CyclingRoad_Text_PhillipPostBattle:
	.string "Maybe I need more than a screwdriver...\n"
	.string "You know the drill.$"

CyclingRoad_Text_RydelHype1:
	.string "Folks, we have the quickest wheels\n"
	.string "in Hoenn on the track! {PLAYER}!!!$"

CyclingRoad_Text_RydelHype2:
	.string "{PLAYER} is rounding the final\n"
	.string "stretch! A true nail biter!!!$"
