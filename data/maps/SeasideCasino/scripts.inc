.set LOCALID_STEVEN, 2
.set LOCALID_STEVEN2, 4
.set LOCALID_DOORGUARD, 1

SeasideCasino_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, SeasideCasino_OnLoad
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SeasideCasino_OnFrame
	.byte 0

SeasideCasino_OnLoad:
	call SeasideCasino_EventScript_RemoveSteven
	call_if_eq VAR_WALLY_QUEST_STATE, 5, SeasideCasino_EventScript_RemoveDoorGuard
	call_if_eq VAR_WALLY_QUEST_STATE, 6, SeasideCasino_EventScript_RemoveDoorGuard
	end

SeasideCasino_OnFrame:
	map_script_2 VAR_WALLY_QUEST_STATE, 7, SeasideCasino_EventScript_StevenDiscussion
	.2byte 0

SeasideCasino_EventScript_RemoveSteven::
	removeobject LOCALID_STEVEN
	removeobject LOCALID_STEVEN2
	setflag FLAG_TEMP_11
	setflag FLAG_TEMP_13
	return

SeasideCasino_EventScript_RemoveDoorGuard::
	removeobject LOCALID_DOORGUARD
	setflag FLAG_TEMP_12
	return

SeasideCasino_EventScript_StevenDiscussion::
	lock
	clearflag FLAG_TEMP_13
	addobject LOCALID_STEVEN2
	speakername SeasideCasino_Text_NameSteven
	msgbox SeasideCasino_Text_WhatAreOurOptions, MSGBOX_DEFAULT
	speakername NULL
	msgbox SeasideCasino_Text_ThinkingItOver, MSGBOX_DEFAULT
	multichoice 19, 4, MULTI_WHODUNNIT, FALSE
	copyvar VAR_TEMP_1, VAR_RESULT
	switch VAR_TEMP_1
	case 0, SeasideCasino_EventScript_AnswerNorman
	case 1, SeasideCasino_EventScript_AnswerWally
	case 2, SeasideCasino_EventScript_AnswerLiza
	case 3, SeasideCasino_EventScript_AnswerTate
	case 4, SeasideCasino_EventScript_AnswerMrBonding
	release
	end

SeasideCasino_EventScript_AnswerNorman::
	speakername SeasideCasino_Text_NameSteven
	msgbox SeasideCasino_Text_CantBeNorman, MSGBOX_DEFAULT
	speakername NULL
	msgbox SeasideCasino_Text_ThinkingItOverAgain, MSGBOX_DEFAULT
	multichoice 19, 4, MULTI_WHODUNNIT, FALSE
	copyvar VAR_TEMP_1, VAR_RESULT
	switch VAR_TEMP_1
	case 0, SeasideCasino_EventScript_AnswerNorman
	case 1, SeasideCasino_EventScript_AnswerWally
	case 2, SeasideCasino_EventScript_AnswerLiza
	case 3, SeasideCasino_EventScript_AnswerTate
	case 4, SeasideCasino_EventScript_AnswerMrBonding
	release
	end

SeasideCasino_EventScript_AnswerLiza::
	speakername SeasideCasino_Text_NameSteven
	msgbox SeasideCasino_Text_CantBeLiza, MSGBOX_DEFAULT
	speakername NULL
	msgbox SeasideCasino_Text_ThinkingItOverAgain, MSGBOX_DEFAULT
	multichoice 19, 4, MULTI_WHODUNNIT, FALSE
	copyvar VAR_TEMP_1, VAR_RESULT
	switch VAR_TEMP_1
	case 0, SeasideCasino_EventScript_AnswerNorman
	case 1, SeasideCasino_EventScript_AnswerWally
	case 2, SeasideCasino_EventScript_AnswerLiza
	case 3, SeasideCasino_EventScript_AnswerTate
	case 4, SeasideCasino_EventScript_AnswerMrBonding
	release
	end

SeasideCasino_EventScript_AnswerTate::
	speakername SeasideCasino_Text_NameSteven
	msgbox SeasideCasino_Text_CantBeTate, MSGBOX_DEFAULT
	speakername NULL
	msgbox SeasideCasino_Text_ThinkingItOverAgain, MSGBOX_DEFAULT
	multichoice 19, 4, MULTI_WHODUNNIT, FALSE
	copyvar VAR_TEMP_1, VAR_RESULT
	switch VAR_TEMP_1
	case 0, SeasideCasino_EventScript_AnswerNorman
	case 1, SeasideCasino_EventScript_AnswerWally
	case 2, SeasideCasino_EventScript_AnswerLiza
	case 3, SeasideCasino_EventScript_AnswerTate
	case 4, SeasideCasino_EventScript_AnswerMrBonding
	release
	end

SeasideCasino_EventScript_AnswerMrBonding::
	speakername SeasideCasino_Text_NameSteven
	msgbox SeasideCasino_Text_CantBeMrBonding, MSGBOX_DEFAULT
	speakername NULL
	msgbox SeasideCasino_Text_ThinkingItOverAgain, MSGBOX_DEFAULT
	multichoice 19, 4, MULTI_WHODUNNIT, FALSE
	copyvar VAR_TEMP_1, VAR_RESULT
	switch VAR_TEMP_1
	case 0, SeasideCasino_EventScript_AnswerNorman
	case 1, SeasideCasino_EventScript_AnswerWally
	case 2, SeasideCasino_EventScript_AnswerLiza
	case 3, SeasideCasino_EventScript_AnswerTate
	case 4, SeasideCasino_EventScript_AnswerMrBonding
	release
	end

SeasideCasino_EventScript_AnswerWally::
	speakername NULL
	msgbox SeasideCasino_Text_IsItReallyHim, MSGBOX_DEFAULT
	speakername SeasideCasino_Text_NameSteven
	msgbox SeasideCasino_Text_WallyIsOurMan, MSGBOX_DEFAULT
	applymovement LOCALID_STEVEN2, SeasideCasino_Movement_StevenReadyToLeave
	waitmovement 0
	speakername SeasideCasino_Text_NameSteven
	msgbox SeasideCasino_Text_MeetMeInMossdeep, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_STEVEN2, SeasideCasino_Movement_StevenLeavesFinal
	waitmovement 0
	removeobject LOCALID_STEVEN2
	setflag FLAG_TEMP_13
	setvar VAR_WALLY_QUEST_STATE, 8
	delay 4
	release
	end

SeasideCasino_Movement_StevenReadyToLeave:
	walk_down
	walk_left
	face_up
	step_end

SeasideCasino_Movement_StevenLeavesFinal:
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

SeasideCasino_EventScript_BackroomGuard::
	lock
	goto_if_lt VAR_WALLY_QUEST_STATE, 4, SeasideCasino_EventScript_CantGoPast
	goto_if_eq VAR_FACING, DIR_NORTH, SeasideCasino_EventScript_StevenApproachFromSide
	goto SeasideCasino_EventScript_StevenApproach
	release
	end

SeasideCasino_EventScript_CantGoPast::
	faceplayer
	msgbox SeasideCasino_Text_CantGoPast, MSGBOX_AUTOCLOSE
	release
	end

SeasideCasino_EventScript_StevenApproach::
	faceplayer
	msgbox SeasideCasino_Text_CantGoPast, MSGBOX_DEFAULT
	applymovement LOCALID_STEVEN, SeasideCasino_Movement_StevenApproach
	waitmovement 0
	turnobject LOCALID_DOORGUARD, DIR_SOUTH
	speakername SeasideCasino_Text_NameSteven
	msgbox SeasideCasino_Text_YouShouldLetUsIn, MSGBOX_DEFAULT
	speakername NULL
	msgbox SeasideCasino_Text_CantLetInPlayer, MSGBOX_DEFAULT
	speakername SeasideCasino_Text_NameSteven
	msgbox SeasideCasino_Text_ComeWithMe, MSGBOX_DEFAULT
	applymovement LOCALID_STEVEN, SeasideCasino_Movement_StevenWalkAway
	applymovement LOCALID_DOORGUARD, SeasideCasino_Movement_DoorGuardWalkAway
	waitmovement 0
	removeobject LOCALID_STEVEN
	setflag FLAG_TEMP_11
	removeobject LOCALID_DOORGUARD
	setflag FLAG_TEMP_12
	setvar VAR_WALLY_QUEST_STATE, 5
	release
	end

SeasideCasino_Movement_StevenApproach:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_up
	step_end

SeasideCasino_Movement_StevenWalkAway:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

SeasideCasino_Movement_DoorGuardWalkAway:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

SeasideCasino_EventScript_StevenApproachFromSide::
	faceplayer
	msgbox SeasideCasino_Text_CantGoPast, MSGBOX_DEFAULT
	applymovement LOCALID_STEVEN, SeasideCasino_Movement_StevenApproachFromSide
	waitmovement 0
	turnobject LOCALID_DOORGUARD, DIR_WEST
	speakername SeasideCasino_Text_NameSteven
	msgbox SeasideCasino_Text_YouShouldLetUsIn, MSGBOX_DEFAULT
	speakername NULL
	msgbox SeasideCasino_Text_CantLetInPlayer, MSGBOX_DEFAULT
	speakername SeasideCasino_Text_NameSteven
	msgbox SeasideCasino_Text_ComeWithMe, MSGBOX_DEFAULT
	applymovement LOCALID_STEVEN, SeasideCasino_Movement_StevenWalkAwayFromSide
	applymovement LOCALID_DOORGUARD, SeasideCasino_Movement_DoorGuardWalkAwayFromSide
	waitmovement 0
	removeobject LOCALID_STEVEN
	setflag FLAG_TEMP_11
	removeobject LOCALID_DOORGUARD
	setflag FLAG_TEMP_12
	setvar VAR_WALLY_QUEST_STATE, 5
	release
	end

SeasideCasino_Movement_StevenApproachFromSide:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_right
	walk_right
	walk_up
	walk_up
	face_right
	step_end

SeasideCasino_Movement_StevenWalkAwayFromSide:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

SeasideCasino_Movement_DoorGuardWalkAwayFromSide:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

SeasideCasino_EventScript_SlotMachine0::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, SeasideCasino_EventScript_NoCoinCase
	setvar VAR_0x8004, 0
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

SeasideCasino_EventScript_SlotMachine1::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, SeasideCasino_EventScript_NoCoinCase
	setvar VAR_0x8004, 1
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

SeasideCasino_EventScript_SlotMachine2::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, SeasideCasino_EventScript_NoCoinCase
	setvar VAR_0x8004, 2
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

SeasideCasino_EventScript_SlotMachine3::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, SeasideCasino_EventScript_NoCoinCase
	setvar VAR_0x8004, 3
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

SeasideCasino_EventScript_SlotMachine4::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, SeasideCasino_EventScript_NoCoinCase
	setvar VAR_0x8004, 4
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

SeasideCasino_EventScript_SlotMachine5::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, SeasideCasino_EventScript_NoCoinCase
	setvar VAR_0x8004, 5
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

SeasideCasino_EventScript_SlotMachine6::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, SeasideCasino_EventScript_NoCoinCase
	setvar VAR_0x8004, 6
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

SeasideCasino_EventScript_SlotMachine7::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, SeasideCasino_EventScript_NoCoinCase
	setvar VAR_0x8004, 7
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

SeasideCasino_EventScript_SlotMachine8::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, SeasideCasino_EventScript_NoCoinCase
	setvar VAR_0x8004, 8
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

SeasideCasino_EventScript_SlotMachine9::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, SeasideCasino_EventScript_NoCoinCase
	setvar VAR_0x8004, 9
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

SeasideCasino_EventScript_SlotMachine10::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, SeasideCasino_EventScript_NoCoinCase
	setvar VAR_0x8004, 10
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

SeasideCasino_EventScript_SlotMachine11::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, SeasideCasino_EventScript_NoCoinCase
	setvar VAR_0x8004, 11
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

SeasideCasino_EventScript_NoCoinCase::
	msgbox SeasideCasino_Text_CantPlayWithNoCoinCase, MSGBOX_DEFAULT
	releaseall
	end

SeasideCasino_Text_NameSteven:
	.string "Steven$"

SeasideCasino_Text_CantPlayWithNoCoinCase:
	.string "$"

SeasideCasino_Text_CantGoPast:
	.string "$"

SeasideCasino_Text_YouShouldLetUsIn:
	.string "$"

SeasideCasino_Text_CantLetInPlayer:
	.string "$"

SeasideCasino_Text_ComeWithMe:
	.string "$"

SeasideCasino_Text_WhatAreOurOptions:
	.string "$"

SeasideCasino_Text_ThinkingItOver:
	.string "$"

SeasideCasino_Text_ThinkingItOverAgain:
	.string "$"

SeasideCasino_Text_CantBeNorman:
	.string "$"

SeasideCasino_Text_CantBeLiza:
	.string "$"

SeasideCasino_Text_CantBeTate:
	.string "$"

SeasideCasino_Text_CantBeMrBonding:
	.string "$"

SeasideCasino_Text_IsItReallyHim:
	.string "$"

SeasideCasino_Text_WallyIsOurMan:
	.string "$"

SeasideCasino_Text_MeetMeInMossdeep:
	.string "$"
