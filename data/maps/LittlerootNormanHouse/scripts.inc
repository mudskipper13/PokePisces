.set LOCALID_STEVEN, 3
.set LOCALID_NORMAN, 1
.set LOCALID_NORMANWIFE, 2

LittlerootNormanHouse_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, LittlerootNormanHouse_OnLoad
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LittlerootNormanHouse_OnFrame
	.byte 0

LittlerootNormanHouse_OnLoad:
	call_if_lt VAR_WALLY_QUEST_STATE, 3, LittlerootNormanHouse_EventScript_RemoveSteven
	call_if_gt VAR_WALLY_QUEST_STATE, 3, LittlerootNormanHouse_EventScript_RemoveSteven
	end

LittlerootNormanHouse_EventScript_RemoveSteven::
	removeobject LOCALID_STEVEN
	setflag FLAG_TEMP_11
	return

LittlerootNormanHouse_OnFrame:
	map_script_2 VAR_WALLY_QUEST_STATE, 3, LittlerootNormanHouse_EventScript_NormanBattle
	.2byte 0

LittlerootNormanHouse_EventScript_NormanBattle::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootNormanHouse_Movement_PlayerWalkIntoHouse
	applymovement LOCALID_STEVEN, LittlerootNormanHouse_Movement_StevenWalkIntoHouse
	waitmovement 0
	delay 8
	playse SE_PIN
	applymovement LOCALID_NORMAN, LittlerootNormanHouse_Movement_NormanShocked
	waitmovement 0
	speakername LittlerootNormanHouse_Text_NameNorman
	msgbox LittlerootNormanHouse_Text_WhatsUp, MSGBOX_DEFAULT
	speakername LittlerootNormanHouse_Text_NameSteven
	msgbox LittlerootNormanHouse_Text_WereHereRegarding, MSGBOX_DEFAULT
	applymovement LOCALID_NORMAN, LittlerootNormanHouse_Movement_NormanWalkUpToPlayer
	waitmovement 0
	speakername NULL
	msgbox LittlerootNormanHouse_Text_YouLookHimInTheEye, MSGBOX_DEFAULT
	speakername LittlerootNormanHouse_Text_NameNorman
	msgbox LittlerootNormanHouse_Text_SoImBeingAccused, MSGBOX_DEFAULT
	speakername LittlerootNormanHouse_Text_NameSteven
	msgbox LittlerootNormanHouse_Text_ThatShouldBeFine, MSGBOX_DEFAULT
	speakername LittlerootNormanHouse_Text_NameNorman
	trainerbattle_single TRAINER_P_NORMAN, LittlerootNormanHouse_Text_NormanIntro, LittlerootNormanHouse_Text_NormanDefeated, LittlerootNormanHouse_EventScript_NormanBeaten
	goto LittlerootNormanHouse_EventScript_NormanBeaten
	release
	end

LittlerootNormanHouse_Movement_PlayerWalkIntoHouse:
	walk_up
	walk_up
	face_left
	step_end

LittlerootNormanHouse_Movement_StevenWalkIntoHouse:
	walk_up
	face_left
	step_end

LittlerootNormanHouse_Movement_NormanShocked:
	emote_exclamation_mark
	step_end

LittlerootNormanHouse_Movement_NormanWalkUpToPlayer:
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	face_right
	step_end

LittlerootNormanHouse_EventScript_NormanBeaten::
	setvar VAR_WALLY_QUEST_STATE, 4
	speakername LittlerootNormanHouse_Text_NameNorman
	msgbox LittlerootNormanHouse_Text_YouSeemAngered, MSGBOX_DEFAULT
	speakername NULL
	msgbox LittlerootNormanHouse_Text_Reflection, MSGBOX_DEFAULT
	speakername LittlerootNormanHouse_Text_NameSteven
	msgbox LittlerootNormanHouse_Text_FoulPlay, MSGBOX_DEFAULT
	speakername LittlerootNormanHouse_Text_NameNorman
	msgbox LittlerootNormanHouse_Text_ShouldCheckOutCasino, MSGBOX_DEFAULT
	warp MAP_LITTLEROOT_NEW, 11, 15
	waitstate
	release
	end

LittlerootNormanHouse_Text_NameNorman:
	.string "$"

LittlerootNormanHouse_Text_NameSteven:
	.string "$"

LittlerootNormanHouse_Text_WhatsUp:
	.string "$"

LittlerootNormanHouse_Text_WereHereRegarding:
	.string "$"

LittlerootNormanHouse_Text_YouLookHimInTheEye:
	.string "$"

LittlerootNormanHouse_Text_SoImBeingAccused:
	.string "$"

LittlerootNormanHouse_Text_ThatShouldBeFine:
	.string "$"

LittlerootNormanHouse_Text_NormanIntro:
	.string "$"

LittlerootNormanHouse_Text_NormanDefeated:
	.string "$"

LittlerootNormanHouse_Text_YouSeemAngered:
	.string "$"

LittlerootNormanHouse_Text_Reflection:
	.string "$"

LittlerootNormanHouse_Text_FoulPlay:
	.string "$"

LittlerootNormanHouse_Text_ShouldCheckOutCasino:
	.string "$"








