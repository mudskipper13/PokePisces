CrimneyCaldera_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, CrimneyCaldera_OnLoad
	.byte 0

CrimneyCaldera_OnLoad:
	call_if_set FLAG_DEFEATED_SHA_GROU, CrimneyCaldera_EventScript_RemoveShaGrou
	end

CrimneyCaldera_EventScript_RemoveShaGrou::
	setvar VAR_TEMP_4, 1
	setmetatile 17, 5, METATILE_Lavaridge_LavaBubbleTile, FALSE
	setmetatile 18, 5, METATILE_Lavaridge_LavaTile, FALSE
	setmetatile 19, 5, METATILE_Lavaridge_LavaTile, FALSE
	setmetatile 20, 5, METATILE_Lavaridge_LavaTile, FALSE
	setmetatile 21, 5, METATILE_Lavaridge_LavaTile, FALSE
	setmetatile 17, 6, METATILE_Lavaridge_LavaTile, FALSE
	setmetatile 18, 6, METATILE_Lavaridge_LavaTile, FALSE
	setmetatile 19, 6, METATILE_Lavaridge_LavaTile, FALSE
	setmetatile 20, 6, METATILE_Lavaridge_LavaTile, FALSE
	setmetatile 21, 6, METATILE_Lavaridge_LavaBubbleTile, FALSE
	special DrawWholeMapView
	return

CrimneyCaldera_EventScript_LegendaryEncounter::
	lock
	msgbox CrimneyCaldera_Text_TheyreFighting, MSGBOX_DEFAULT
	closemessage
	playmoncry SPECIES_SHAYON, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	playmoncry SPECIES_GROUDON, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	msgbox CrimneyCaldera_Text_TimeToStepIn, MSGBOX_DEFAULT
	closemessage
	setwildbattle SPECIES_SHAYON, 80, ITEM_NONE, SPECIES_GROUDON, 80, ITEM_NONE
	setflag FLAG_WILD_NO_CATCHING_FLAG
	setflag FLAG_WILD_NO_RUNNING_FLAG
	setflag FLAG_SMART_WILD_AI_FLAG
	delay 4
	dowildbattle
	delay 8
	clearflag FLAG_WILD_NO_CATCHING_FLAG
	clearflag FLAG_WILD_NO_RUNNING_FLAG
	clearflag FLAG_SMART_WILD_AI_FLAG
	playmoncry SPECIES_SHAYON, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	playmoncry SPECIES_GROUDON, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	msgbox CrimneyCaldera_Text_BreakThemUp, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_DEFEATED_SHA_GROU
	delay 16
	setvar VAR_NEW_COO_STATE, 7
	warp MAP_CRIMNEY_CALDERA, 19, 9
	waitstate
	release
	end

CrimneyCaldera_EventScript_WallaceIdle::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_LUO_KYO, CrimneyCaldera_EventScript_WallaceIdleBeatSha
	speakername CrimneyCaldera_Text_NameWallace
	msgbox CrimneyCaldera_Text_ISenseOneNearby, MSGBOX_AUTOCLOSE
	release
	end

CrimneyCaldera_EventScript_WallaceIdleBeatSha::
	goto_if_set FLAG_DEFEATED_SHA_GROU, CrimneyCaldera_EventScript_WallaceIdleBeatBoth
	speakername CrimneyCaldera_Text_NameWallace
	msgbox CrimneyCaldera_Text_GoToLuoshan, MSGBOX_AUTOCLOSE
	release
	end

CrimneyCaldera_EventScript_WallaceIdleBeatBoth::
	speakername CrimneyCaldera_Text_NameWallace
	msgbox CrimneyCaldera_Text_TheFishWentToEGR, MSGBOX_AUTOCLOSE
	release
	end

CrimneyCaldera_EventScript_WallaceTalk::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, CrimneyCaldera_Movement_WalkToWallace
	goto_if_set FLAG_DEFEATED_LUO_KYO, CrimneyCaldera_EventScript_BeatBothLegends
	setvar VAR_NEW_COO_STATE, 6
	speakername CrimneyCaldera_Text_NameWallace
	msgbox CrimneyCaldera_Text_GoToLuoshan, MSGBOX_DEFAULT
	release
	end

CrimneyCaldera_Movement_WalkToWallace:
	walk_down
	walk_right
	step_end

CrimneyCaldera_EventScript_BeatBothLegends::
	speakername CrimneyCaldera_Text_NameWallace
	msgbox CrimneyCaldera_Text_TheFishWentToEGR, MSGBOX_DEFAULT
	closemessage
	setvar VAR_NEW_COO_STATE, 9
	clearflag FLAG_HIDE_MAXIE_OZONE
	release
	end

CrimneyCaldera_EventScript_Meiyu::
    trainerbattle_single TRAINER_P_MEIYU, CrimneyCaldera_Text_MeiyuIntro, CrimneyCaldera_Text_MeiyuDefeated
    msgbox CrimneyCaldera_Text_MeiyuPostBattle, MSGBOX_AUTOCLOSE
    end

CrimneyCaldera_EventScript_Centauri::
    trainerbattle_single TRAINER_P_CENTAURI, CrimneyCaldera_Text_CentauriIntro, CrimneyCaldera_Text_CentauriDefeated
    msgbox CrimneyCaldera_Text_CentauriPostBattle, MSGBOX_AUTOCLOSE
    end

CrimneyCaldera_Text_MeiyuIntro:
	.string "intro$"

CrimneyCaldera_Text_MeiyuDefeated:
	.string "defeat$"

CrimneyCaldera_Text_MeiyuPostBattle:
	.string "post$"

CrimneyCaldera_Text_CentauriIntro:
	.string "intro$"

CrimneyCaldera_Text_CentauriDefeated:
	.string "defeat$"

CrimneyCaldera_Text_CentauriPostBattle:
	.string "post$"

CrimneyCaldera_Text_TheyreFighting:
	.string "$"

CrimneyCaldera_Text_TimeToStepIn:
	.string "$"

CrimneyCaldera_Text_BreakThemUp:
	.string "$"

CrimneyCaldera_Text_NameWallace:
	.string "$"

CrimneyCaldera_Text_ISenseOneNearby:
	.string "$"

CrimneyCaldera_Text_GoToLuoshan:
	.string "$"

CrimneyCaldera_Text_TheFishWentToEGR:
	.string "$"
