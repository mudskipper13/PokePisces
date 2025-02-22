.set LOCALID_BREAD, 26

EverGrandeRoad_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, EverGrandeRoad_OnLoad
	.byte 0

EverGrandeRoad_OnLoad:
	call EverGrandeRoad_EventScript_RemoveBreadwinner
	call_if_gt VAR_BREADWINNER_STATE, 5, EverGrandeRoad_EventScript_SetTempVar
	end

EverGrandeRoad_EventScript_RemoveBreadwinner::
	removeobject LOCALID_BREAD
	setflag FLAG_TEMP_13
	return

EverGrandeRoad_EventScript_SetTempVar::
	setvar VAR_TEMP_4, 1
	return

EverGrandeRoad_EventScript_MusicTrigger::
	end

EverGrandeRoad_EventScript_BreadEncounter1::
	lock
	clearflag FLAG_TEMP_13
	addobject LOCALID_BREAD
	delay 4
	applymovement LOCALID_BREAD, EverGrandeRoad_Movement_PlayerNotice
	waitmovement 0
	applymovement LOCALID_BREAD, EverGrandeRoad_Movement_BreadWalkUp
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, EverGrandeRoad_Movement_PlayerChaseBread1
	waitmovement 0
	goto EverGrandeRoad_EventScript_BreadwinnerBattle
	release
	end

EverGrandeRoad_Movement_PlayerNotice:
	face_down
	emote_exclamation_mark
	step_end

EverGrandeRoad_Movement_BreadWalkUp:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

EverGrandeRoad_Movement_PlayerChaseBread1:
	walk_down
	walk_right
	face_down
	step_end

EverGrandeRoad_EventScript_BreadEncounter2::
	lock
	clearflag FLAG_TEMP_13
	addobject LOCALID_BREAD
	delay 4
	applymovement LOCALID_BREAD, EverGrandeRoad_Movement_PlayerNotice
	waitmovement 0
	applymovement LOCALID_BREAD, EverGrandeRoad_Movement_BreadWalkUp
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, EverGrandeRoad_Movement_PlayerChaseBread2
	waitmovement 0
	goto EverGrandeRoad_EventScript_BreadwinnerBattle
	release
	end

EverGrandeRoad_Movement_PlayerChaseBread2:
	walk_down
	walk_left
	face_down
	step_end

EverGrandeRoad_EventScript_BreadEncounter3::
	lock
	clearflag FLAG_TEMP_13
	addobject LOCALID_BREAD
	delay 4
	applymovement LOCALID_BREAD, EverGrandeRoad_Movement_PlayerNotice
	waitmovement 0
	applymovement LOCALID_BREAD, EverGrandeRoad_Movement_BreadWalkUp
	waitmovement 0
	delay 4
	goto EverGrandeRoad_EventScript_BreadwinnerBattle
	release
	end

EverGrandeRoad_EventScript_BreadwinnerBattle::
	delay 8
	setvar VAR_TEMP_4, 1
	speakername EverGrandeRoad_Text_NamePandou
	msgbox EverGrandeRoad_Text_BreadwinnerIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_P_PANDOU_6, EverGrandeRoad_Text_BreadwinnerDefeat
	goto EverGrandeRoad_EventScript_BreadRun
	release
	end

EverGrandeRoad_EventScript_BreadRun::
	setvar VAR_BREADWINNER_STATE, 6
	speakername EverGrandeRoad_Text_NamePandou
	msgbox EverGrandeRoad_Text_BreadwinnerRunAway, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BREAD, EverGrandeRoad_Movement_BreadEscape
	waitmovement 0
	opendoor 79, 5
	applymovement LOCALID_BREAD, EverGrandeRoad_Movement_BreadGoThruDoor
	waitmovement 0
	closedoor 79, 5
	removeobject LOCALID_BREAD
	setflag FLAG_TEMP_13
	release
	end

EverGrandeRoad_Movement_BreadEscape:
	walk_left
	walk_up
	walk_up
	walk_up
	walk_right
	face_up
	step_end

EverGrandeRoad_Movement_BreadGoThruDoor:
	walk_up
	step_end

EverGrandeRoad_EventScript_RaoTwunne::
    trainerbattle_single TRAINER_P_RAO_TWUNNE, EverGrandeRoad_Text_RaoTwunneIntro, EverGrandeRoad_Text_RaoTwunneDefeated
    msgbox EverGrandeRoad_Text_RaoTwunnePostBattle, MSGBOX_AUTOCLOSE
    end

EverGrandeRoad_EventScript_Jamiroquai::
    trainerbattle_single TRAINER_P_JAMIROQUAI, EverGrandeRoad_Text_JamiroquaiIntro, EverGrandeRoad_Text_JamiroquaiDefeated
    msgbox EverGrandeRoad_Text_JamiroquaiPostBattle, MSGBOX_AUTOCLOSE
    end

EverGrandeRoad_EventScript_Kumqot::
    trainerbattle_single TRAINER_P_KUMQOT, EverGrandeRoad_Text_KumqotIntro, EverGrandeRoad_Text_KumqotDefeated
    msgbox EverGrandeRoad_Text_KumqotPostBattle, MSGBOX_AUTOCLOSE
    end

EverGrandeRoad_EventScript_Dorian::
    trainerbattle_single TRAINER_P_DORIAN, EverGrandeRoad_Text_DorianIntro, EverGrandeRoad_Text_DorianDefeated
    msgbox EverGrandeRoad_Text_DorianPostBattle, MSGBOX_AUTOCLOSE
    end

EverGrandeRoad_EventScript_Lytxi::
    trainerbattle_single TRAINER_P_LYTXI, EverGrandeRoad_Text_LytxiIntro, EverGrandeRoad_Text_LytxiDefeated
    msgbox EverGrandeRoad_Text_LytxiPostBattle, MSGBOX_AUTOCLOSE
    end

EverGrandeRoad_EventScript_Sherimoya::
    trainerbattle_single TRAINER_P_SHERIMOYA, EverGrandeRoad_Text_SherimoyaIntro, EverGrandeRoad_Text_SherimoyaDefeated
    msgbox EverGrandeRoad_Text_SherimoyaPostBattle, MSGBOX_AUTOCLOSE
    end

EverGrandeRoad_EventScript_Melulu::
    trainerbattle_single TRAINER_P_MELULU, EverGrandeRoad_Text_MeluluIntro, EverGrandeRoad_Text_MeluluDefeated
    msgbox EverGrandeRoad_Text_MeluluPostBattle, MSGBOX_AUTOCLOSE
    end

EverGrandeRoad_EventScript_PyoRin::
    trainerbattle_single TRAINER_P_PYORIN, EverGrandeRoad_Text_PyoRinIntro, EverGrandeRoad_Text_PyoRinDefeated
    msgbox EverGrandeRoad_Text_PyoRinPostBattle, MSGBOX_AUTOCLOSE
    end

EverGrandeRoad_EventScript_Min::
    trainerbattle_single TRAINER_P_MIN, EverGrandeRoad_Text_MinIntro, EverGrandeRoad_Text_MinDefeated
    msgbox EverGrandeRoad_Text_MinPostBattle, MSGBOX_AUTOCLOSE
    end

EverGrandeRoad_EventScript_Max::
    trainerbattle_single TRAINER_P_MAX, EverGrandeRoad_Text_MaxIntro, EverGrandeRoad_Text_MaxDefeated
    msgbox EverGrandeRoad_Text_MaxPostBattle, MSGBOX_AUTOCLOSE
    end

EverGrandeRoad_EventScript_Artemis::
    trainerbattle_single TRAINER_P_ARTEMIS, EverGrandeRoad_Text_ArtemisIntro, EverGrandeRoad_Text_ArtemisDefeated
    msgbox EverGrandeRoad_Text_ArtemisPostBattle, MSGBOX_AUTOCLOSE
    end

EverGrandeRoad_EventScript_Garena::
    trainerbattle_single TRAINER_P_GARENA, EverGrandeRoad_Text_GarenaIntro, EverGrandeRoad_Text_GarenaDefeated
    msgbox EverGrandeRoad_Text_GarenaPostBattle, MSGBOX_AUTOCLOSE
    end

EverGrandeRoad_EventScript_Goro::
    trainerbattle_single TRAINER_P_GORO, EverGrandeRoad_Text_GoroIntro, EverGrandeRoad_Text_GoroDefeated
    msgbox EverGrandeRoad_Text_GoroPostBattle, MSGBOX_AUTOCLOSE
    end

EverGrandeRoad_EventScript_Miernie::
    trainerbattle_single TRAINER_P_MIERNIE, EverGrandeRoad_Text_MiernieIntro, EverGrandeRoad_Text_MiernieDefeated
    msgbox EverGrandeRoad_Text_MierniePostBattle, MSGBOX_AUTOCLOSE
    end

EverGrandeRoad_EventScript_Badumka::
    trainerbattle_single TRAINER_P_BADUMKA, EverGrandeRoad_Text_BadumkaIntro, EverGrandeRoad_Text_BadumkaDefeated
    msgbox EverGrandeRoad_Text_BadumkaPostBattle, MSGBOX_AUTOCLOSE
    end

EverGrandeRoad_EventScript_Anatina::
    trainerbattle_single TRAINER_P_ANATINA, EverGrandeRoad_Text_AnatinaIntro, EverGrandeRoad_Text_AnatinaDefeated
    msgbox EverGrandeRoad_Text_AnatinaPostBattle, MSGBOX_AUTOCLOSE
    end

EverGrandeRoad_EventScript_Taipus::
    trainerbattle_single TRAINER_P_TAIPUS, EverGrandeRoad_Text_TaipusIntro, EverGrandeRoad_Text_TaipusDefeated
    msgbox EverGrandeRoad_Text_TaipusPostBattle, MSGBOX_AUTOCLOSE
    end

EverGrandeRoad_EventScript_Marcelus::
    trainerbattle_single TRAINER_P_MARCELUS, EverGrandeRoad_Text_MarcelusIntro, EverGrandeRoad_Text_MarcelusDefeated
    msgbox EverGrandeRoad_Text_MarcelusPostBattle, MSGBOX_AUTOCLOSE
    end

EverGrandeRoad_EventScript_Devia::
    trainerbattle_single TRAINER_P_DEVIA, EverGrandeRoad_Text_DeviaIntro, EverGrandeRoad_Text_DeviaDefeated
    msgbox EverGrandeRoad_Text_DeviaPostBattle, MSGBOX_AUTOCLOSE
    end

EverGrandeRoad_EventScript_Unseld::
    trainerbattle_single TRAINER_P_UNSELD, EverGrandeRoad_Text_UnseldIntro, EverGrandeRoad_Text_UnseldDefeated
    msgbox EverGrandeRoad_Text_UnseldPostBattle, MSGBOX_AUTOCLOSE
    end

EverGrandeRoad_EventScript_Immy::
    trainerbattle_single TRAINER_P_IMMY, EverGrandeRoad_Text_ImmyIntro, EverGrandeRoad_Text_ImmyDefeated
    msgbox EverGrandeRoad_Text_ImmyPostBattle, MSGBOX_AUTOCLOSE
    end

EverGrandeRoad_EventScript_Parponix::
    trainerbattle_single TRAINER_P_PARPONIX, EverGrandeRoad_Text_ParponixIntro, EverGrandeRoad_Text_ParponixDefeated
    msgbox EverGrandeRoad_Text_ParponixPostBattle, MSGBOX_AUTOCLOSE
    end

EverGrandeRoad_EventScript_Lanaya::
    trainerbattle_single TRAINER_P_LANAYA, EverGrandeRoad_Text_LanayaIntro, EverGrandeRoad_Text_LanayaDefeated
    msgbox EverGrandeRoad_Text_LanayaPostBattle, MSGBOX_AUTOCLOSE
    end

EverGrandeRoad_EventScript_Ophelia::
    trainerbattle_single TRAINER_P_OPHELIA, EverGrandeRoad_Text_OpheliaIntro, EverGrandeRoad_Text_OpheliaDefeated
    msgbox EverGrandeRoad_Text_OpheliaPostBattle, MSGBOX_AUTOCLOSE
    end

EverGrandeRoad_Text_RaoTwunneIntro:
	.string "intro$"

EverGrandeRoad_Text_RaoTwunneDefeated:
	.string "defeat$"

EverGrandeRoad_Text_RaoTwunnePostBattle:
	.string "post$"

EverGrandeRoad_Text_JamiroquaiIntro:
	.string "intro$"

EverGrandeRoad_Text_JamiroquaiDefeated:
	.string "defeat$"

EverGrandeRoad_Text_JamiroquaiPostBattle:
	.string "post$"

EverGrandeRoad_Text_KumqotIntro:
	.string "intro$"

EverGrandeRoad_Text_KumqotDefeated:
	.string "defeat$"

EverGrandeRoad_Text_KumqotPostBattle:
	.string "post$"

EverGrandeRoad_Text_DorianIntro:
	.string "intro$"

EverGrandeRoad_Text_DorianDefeated:
	.string "defeat$"

EverGrandeRoad_Text_DorianPostBattle:
	.string "post$"

EverGrandeRoad_Text_LytxiIntro:
	.string "intro$"

EverGrandeRoad_Text_LytxiDefeated:
	.string "defeat$"

EverGrandeRoad_Text_LytxiPostBattle:
	.string "post$"

EverGrandeRoad_Text_SherimoyaIntro:
	.string "intro$"

EverGrandeRoad_Text_SherimoyaDefeated:
	.string "defeat$"

EverGrandeRoad_Text_SherimoyaPostBattle:
	.string "post$"

EverGrandeRoad_Text_MeluluIntro:
	.string "intro$"

EverGrandeRoad_Text_MeluluDefeated:
	.string "defeat$"

EverGrandeRoad_Text_MeluluPostBattle:
	.string "post$"

EverGrandeRoad_Text_PyoRinIntro:
	.string "intro$"

EverGrandeRoad_Text_PyoRinDefeated:
	.string "defeat$"

EverGrandeRoad_Text_PyoRinPostBattle:
	.string "post$"

EverGrandeRoad_Text_MinIntro:
	.string "intro$"

EverGrandeRoad_Text_MinDefeated:
	.string "defeat$"

EverGrandeRoad_Text_MinPostBattle:
	.string "post$"

EverGrandeRoad_Text_MaxIntro:
	.string "intro$"

EverGrandeRoad_Text_MaxDefeated:
	.string "defeat$"

EverGrandeRoad_Text_MaxPostBattle:
	.string "post$"

EverGrandeRoad_Text_ArtemisIntro:
	.string "intro$"

EverGrandeRoad_Text_ArtemisDefeated:
	.string "defeat$"

EverGrandeRoad_Text_ArtemisPostBattle:
	.string "post$"

EverGrandeRoad_Text_GarenaIntro:
	.string "intro$"

EverGrandeRoad_Text_GarenaDefeated:
	.string "defeat$"

EverGrandeRoad_Text_GarenaPostBattle:
	.string "post$"

EverGrandeRoad_Text_GoroIntro:
	.string "intro$"

EverGrandeRoad_Text_GoroDefeated:
	.string "defeat$"

EverGrandeRoad_Text_GoroPostBattle:
	.string "post$"

EverGrandeRoad_Text_MiernieIntro:
	.string "intro$"

EverGrandeRoad_Text_MiernieDefeated:
	.string "defeat$"

EverGrandeRoad_Text_MierniePostBattle:
	.string "post$"

EverGrandeRoad_Text_BadumkaIntro:
	.string "intro$"

EverGrandeRoad_Text_BadumkaDefeated:
	.string "defeat$"

EverGrandeRoad_Text_BadumkaPostBattle:
	.string "post$"

EverGrandeRoad_Text_AnatinaIntro:
	.string "intro$"

EverGrandeRoad_Text_AnatinaDefeated:
	.string "defeat$"

EverGrandeRoad_Text_AnatinaPostBattle:
	.string "post$"

EverGrandeRoad_Text_TaipusIntro:
	.string "intro$"

EverGrandeRoad_Text_TaipusDefeated:
	.string "defeat$"

EverGrandeRoad_Text_TaipusPostBattle:
	.string "post$"

EverGrandeRoad_Text_MarcelusIntro:
	.string "intro$"

EverGrandeRoad_Text_MarcelusDefeated:
	.string "defeat$"

EverGrandeRoad_Text_MarcelusPostBattle:
	.string "post$"

EverGrandeRoad_Text_DeviaIntro:
	.string "intro$"

EverGrandeRoad_Text_DeviaDefeated:
	.string "defeat$"

EverGrandeRoad_Text_DeviaPostBattle:
	.string "post$"

EverGrandeRoad_Text_UnseldIntro:
	.string "intro$"

EverGrandeRoad_Text_UnseldDefeated:
	.string "defeat$"

EverGrandeRoad_Text_UnseldPostBattle:
	.string "post$"

EverGrandeRoad_Text_ImmyIntro:
	.string "intro$"

EverGrandeRoad_Text_ImmyDefeated:
	.string "defeat$"

EverGrandeRoad_Text_ImmyPostBattle:
	.string "post$"

EverGrandeRoad_Text_ParponixIntro:
	.string "intro$"

EverGrandeRoad_Text_ParponixDefeated:
	.string "defeat$"

EverGrandeRoad_Text_ParponixPostBattle:
	.string "post$"

EverGrandeRoad_Text_LanayaIntro:
	.string "intro$"

EverGrandeRoad_Text_LanayaDefeated:
	.string "defeat$"

EverGrandeRoad_Text_LanayaPostBattle:
	.string "post$"

EverGrandeRoad_Text_OpheliaIntro:
	.string "intro$"

EverGrandeRoad_Text_OpheliaDefeated:
	.string "defeat$"

EverGrandeRoad_Text_OpheliaPostBattle:
	.string "post$"

EverGrandeRoad_Text_NamePandou:
	.string "Pandou$"

EverGrandeRoad_Text_BreadwinnerIntro:
	.string "$"

EverGrandeRoad_Text_BreadwinnerDefeat:
	.string "$"

EverGrandeRoad_Text_BreadwinnerRunAway:
	.string "$"
