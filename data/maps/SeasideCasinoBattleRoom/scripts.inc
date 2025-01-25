.set LOCALID_STEVEN, 3
.set LOCALID_SIDNEY, 1
.set LOCALID_LUCY, 2

SeasideCasinoBattleRoom_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, SeasideCasinoBattleRoom_OnLoad
	.byte 0

SeasideCasinoBattleRoom_OnLoad:
	call_if_gt VAR_WALLY_QUEST_STATE, 6, SeasideCasinoBattleRoom_EventScript_RemoveSteven
	end

SeasideCasinoBattleRoom_EventScript_RemoveSteven::
	removeobject LOCALID_STEVEN
	setflag FLAG_TEMP_11
	return

SeasideCasinoBattleRoom_EventScript_SidneyLucyBattle::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, SeasideCasinoBattleRoom_Movement_PlayerMeetSidney
	waitmovement 0
	turnobject LOCALID_STEVEN, DIR_WEST
	speakername SeasideCasinoBattleRoom_Text_NameSteven
	msgbox SeasideCasinoBattleRoom_Text_HelloPlayer, MSGBOX_DEFAULT
	turnobject LOCALID_STEVEN, DIR_NORTH
	speakername SeasideCasinoBattleRoom_Text_NameSidney
	msgbox SeasideCasinoBattleRoom_Text_WhatDoYouWant, MSGBOX_DEFAULT
	speakername SeasideCasinoBattleRoom_Text_NameSteven
	msgbox SeasideCasinoBattleRoom_Text_TheresBeenAForgery, MSGBOX_DEFAULT
	speakername SeasideCasinoBattleRoom_Text_NameSidney
	msgbox SeasideCasinoBattleRoom_Text_HowBoutAWager, MSGBOX_DEFAULT
	turnobject LOCALID_SIDNEY, DIR_WEST
	speakername SeasideCasinoBattleRoom_Text_NameSidney
	msgbox SeasideCasinoBattleRoom_Text_LucyComeOver, MSGBOX_DEFAULT
	applymovement LOCALID_LUCY, SeasideCasinoBattleRoom_Movement_LucyComeToChair
	waitmovement 0
	turnobject LOCALID_SIDNEY, DIR_SOUTH
	speakername SeasideCasinoBattleRoom_Text_NameLucy
	msgbox SeasideCasinoBattleRoom_Text_AreWeBattling, MSGBOX_DEFAULT
	speakername SeasideCasinoBattleRoom_Text_NameSidney
	msgbox SeasideCasinoBattleRoom_Text_LetsTussleWinnerGetsInfo, MSGBOX_DEFAULT
	speakername NULL
	trainerbattle_two_trainers TRAINER_P_SIDNEY, SeasideCasinoBattleRoom_Text_SidneyDefeat, TRAINER_P_LUCY, SeasideCasinoBattleRoom_Text_LucyDefeat, SeasideCasinoBattleRoom_EventScript_LeadersDefeated, NO_MUSIC
	goto SeasideCasinoBattleRoom_EventScript_LeadersDefeated
	release
	end

SeasideCasinoBattleRoom_EventScript_LeadersDefeated::
	setvar VAR_WALLY_QUEST_STATE, 7
	speakername SeasideCasinoBattleRoom_Text_NameSidney
	msgbox SeasideCasinoBattleRoom_Text_AlrightThen, MSGBOX_DEFAULT
	speakername SeasideCasinoBattleRoom_Text_NameLucy
	msgbox SeasideCasinoBattleRoom_Text_DoctorInfoDump, MSGBOX_DEFAULT
	turnobject LOCALID_STEVEN, DIR_WEST
	speakername SeasideCasinoBattleRoom_Text_NameSteven
	msgbox SeasideCasinoBattleRoom_Text_LetsGetOutOfHereAndRegroup, MSGBOX_DEFAULT
	warp MAP_SEASIDE_CASINO, 18, 8
	waitstate
	release
	end

SeasideCasinoBattleRoom_Movement_PlayerMeetSidney:
	walk_up
	walk_up
	walk_left
	face_up
	step_end

SeasideCasinoBattleRoom_Movement_LucyComeToChair:
	walk_down
	walk_down
	step_end

SeasideCasinoBattleRoom_Text_NameSteven:
	.string "Steven$"

SeasideCasinoBattleRoom_Text_NameSidney:
	.string "Sidney$"

SeasideCasinoBattleRoom_Text_NameLucy:
	.string "Lucy$"

SeasideCasinoBattleRoom_Text_HelloPlayer:
	.string "$"

SeasideCasinoBattleRoom_Text_WhatDoYouWant:
	.string "$"

SeasideCasinoBattleRoom_Text_TheresBeenAForgery:
	.string "$"

SeasideCasinoBattleRoom_Text_HowBoutAWager:
	.string "$"

SeasideCasinoBattleRoom_Text_LucyComeOver:
	.string "$"

SeasideCasinoBattleRoom_Text_AreWeBattling:
	.string "$"

SeasideCasinoBattleRoom_Text_LetsTussleWinnerGetsInfo:
	.string "$"

SeasideCasinoBattleRoom_Text_SidneyDefeat:
	.string "$"

SeasideCasinoBattleRoom_Text_LucyDefeat:
	.string "$"

SeasideCasinoBattleRoom_Text_AlrightThen:
	.string "$"

SeasideCasinoBattleRoom_Text_DoctorInfoDump:
	.string "$"

SeasideCasinoBattleRoom_Text_LetsGetOutOfHereAndRegroup:
	.string "$"
