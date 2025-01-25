.set LOCALID_WALLY, 1
.set LOCALID_STEVEN, 2
.set LOCALID_NORMAN, 3

WallyArena_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, WallyArena_OnLoad
	.byte 0

WallyArena_OnLoad:
	call WallyArena_EventScript_RemoveStevenNorman
	end

WallyArena_EventScript_RemoveStevenNorman::
	removeobject LOCALID_STEVEN
	setflag FLAG_TEMP_11
	removeobject LOCALID_NORMAN
	setflag FLAG_TEMP_12
	return

WallyArena_EventScript_WallyBattle::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, WallyArena_Movement_PlayerMoveToWally
	waitmovement 0
	delay 8
	turnobject LOCALID_WALLY, DIR_EAST
	delay 16
	turnobject LOCALID_WALLY, DIR_SOUTH
	delay 16
	speakername WallyArena_Text_NameWally
	msgbox WallyArena_Text_HelloPlayerKun, MSGBOX_DEFAULT
	playbgm MUS_VICTORY_ROAD, FALSE
	speakername WallyArena_Text_NameWally
	msgbox WallyArena_Text_FullVillainMonologue, MSGBOX_DEFAULT
	trainerbattle_single TRAINER_P_WALLY, WallyArena_Text_WallyIntro, WallyArena_Text_WallyDefeated, WallyArena_EventScript_WallyBeaten
	goto WallyArena_EventScript_WallyBeaten
	release
	end

WallyArena_EventScript_WallyBeaten::
	lock
	setvar VAR_WALLY_QUEST_STATE, 9
	setflag FLAG_DEFEATED_EVIL_WALLY
	setvar VAR_PISCES_STORY_PROGRESS, 10
	playbgm MUS_RG_VICTORY_ROAD, FALSE
	speakername WallyArena_Text_NameWally
	msgbox WallyArena_Text_HowCouldThisBe, MSGBOX_DEFAULT
	clearflag FLAG_TEMP_11
	addobject LOCALID_STEVEN
	clearflag FLAG_TEMP_12
	addobject LOCALID_NORMAN
	delay 4
	closemessage
	applymovement LOCALID_STEVEN, WallyArena_Movement_StevenMoveToWally
	applymovement LOCALID_NORMAN, WallyArena_Movement_NormanMoveToWally
	waitmovement 0
	speakername WallyArena_Text_NameNorman
	msgbox WallyArena_Text_ThatsEnoughWally, MSGBOX_DEFAULT
	speakername WallyArena_Text_NameWally
	msgbox WallyArena_Text_HowDidYouFindMe, MSGBOX_DEFAULT
	speakername WallyArena_Text_NameSteven
	msgbox WallyArena_Text_TrackedTheScent, MSGBOX_DEFAULT
	speakername WallyArena_Text_NameWally
	msgbox WallyArena_Text_WhatsGonnaHappenNow, MSGBOX_DEFAULT
	speakername WallyArena_Text_NameNorman
	msgbox WallyArena_Text_ISeeTheGoodInYou, MSGBOX_DEFAULT
	speakername WallyArena_Text_NameWally
	msgbox WallyArena_Text_AnUnwiseChoice, MSGBOX_DEFAULT
	applymovement LOCALID_WALLY, WallyArena_Movement_WallyRunAway
	waitmovement 0
	speakername WallyArena_Text_NameNorman
	msgbox WallyArena_Text_ThatShouldSettleIt, MSGBOX_DEFAULT
	speakername WallyArena_Text_NameSteven
	msgbox WallyArena_Text_LetsGoToDevonCorp, MSGBOX_DEFAULT
	closemessage
	delay 4
	warp MAP_DEVON_CORP, 12, 19
	waitstate
	release
	end

WallyArena_Movement_PlayerMoveToWally:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

WallyArena_Movement_StevenMoveToWally:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	face_up
	step_end

WallyArena_Movement_NormanMoveToWally:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	face_up
	step_end

WallyArena_Movement_WallyRunAway:
	walk_fast_down
	walk_fast_left
	walk_fast_down
	walk_fast_down
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

WallyArena_Text_NameWally:
	.string "$"

WallyArena_Text_NameNorman:
	.string "$"

WallyArena_Text_NameSteven:
	.string "$"

WallyArena_Text_HelloPlayerKun:
	.string "$"

WallyArena_Text_FullVillainMonologue:
	.string "$"

WallyArena_Text_WallyIntro:
	.string "$"

WallyArena_Text_WallyDefeated:
	.string "$"

WallyArena_Text_HowCouldThisBe:
	.string "$"

WallyArena_Text_ThatsEnoughWally:
	.string "$"

WallyArena_Text_HowDidYouFindMe:
	.string "$"

WallyArena_Text_TrackedTheScent:
	.string "$"

WallyArena_Text_WhatsGonnaHappenNow:
	.string "$"

WallyArena_Text_ISeeTheGoodInYou:
	.string "$"

WallyArena_Text_AnUnwiseChoice:
	.string "$"

WallyArena_Text_ThatShouldSettleIt:
	.string "$"

WallyArena_Text_LetsGoToDevonCorp:
	.string "$"
