.set LOCALID_RYDEL, 1
.set LOCALID_TABITHA, 2

FallarborNew_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, FallarborNew_OnLoad
	.byte 0

FallarborNew_OnLoad:
	setflag FLAG_VISITED_FALLARBOR_TOWN
	call_if_lt VAR_OLD_GUYS_STATE, 5, FallarborNew_EventScript_SetRydelGfx
	call_if_ge VAR_OLD_GUYS_STATE, 5, FallarborNew_EventScript_RemoveRydel
	call FallarborNew_EventScript_RemoveTabitha
	end

FallarborNew_EventScript_SetRydelGfx::
	setvar VAR_BARD_COLOR, MAUVILLE_MAN_HIPSTER
	special SetMauvilleOldManObjEventGfx
	return

FallarborNew_EventScript_RemoveRydel::
	removeobject LOCALID_RYDEL
	setflag FLAG_TEMP_12
	return

FallarborNew_EventScript_RemoveTabitha::
	removeobject LOCALID_TABITHA
	setflag FLAG_TEMP_11
	return

FallarborNew_EventScript_TabithaEncounter1::
	lock
	opendoor 29, 34
	waitdooranim
	clearflag FLAG_TEMP_11
	addobject LOCALID_TABITHA
	applymovement LOCALID_TABITHA, FallarborNew_Movement_TabOutOfDoor
	waitmovement 0
	closedoor 29, 34
	waitdooranim
	applymovement OBJ_EVENT_ID_PLAYER, FallarborNew_Movement_PlayerMeetTab1
	waitmovement 0
	goto FallarborNew_EventScript_TabithaBattle
	release
	end

FallarborNew_Movement_TabOutOfDoor:
	walk_down
	step_end

FallarborNew_Movement_PlayerMeetTab1:
	walk_down
	walk_right
	walk_down
	walk_right
	face_up
	step_end

FallarborNew_EventScript_TabithaEncounter2::
	lock
	opendoor 29, 34
	waitdooranim
	clearflag FLAG_TEMP_11
	addobject LOCALID_TABITHA
	applymovement LOCALID_TABITHA, FallarborNew_Movement_TabOutOfDoor
	waitmovement 0
	closedoor 29, 34
	waitdooranim
	applymovement OBJ_EVENT_ID_PLAYER, FallarborNew_Movement_PlayerMeetTab2
	waitmovement 0
	goto FallarborNew_EventScript_TabithaBattle
	release
	end

FallarborNew_Movement_PlayerMeetTab2:
	walk_right
	walk_down
	walk_right
	face_up
	step_end

FallarborNew_EventScript_TabithaEncounter3::
	lock
	opendoor 29, 34
	waitdooranim
	clearflag FLAG_TEMP_11
	addobject LOCALID_TABITHA
	applymovement LOCALID_TABITHA, FallarborNew_Movement_TabOutOfDoor
	waitmovement 0
	closedoor 29, 34
	waitdooranim
	applymovement OBJ_EVENT_ID_PLAYER, FallarborNew_Movement_PlayerMeetTab3
	waitmovement 0
	goto FallarborNew_EventScript_TabithaBattle
	release
	end

FallarborNew_Movement_PlayerMeetTab3:
	walk_right
	walk_right
	face_up
	step_end

FallarborNew_EventScript_TabithaBattle::
	speakername FallarborNew_Text_NameTabitha
	msgbox FallarborNew_Text_JustVisitedCosmo, MSGBOX_DEFAULT
	speakername FallarborNew_Text_NameTabitha
	msgbox FallarborNew_Text_TabithaIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_P_TABITHA_2, FallarborNew_Text_TabithaDefeated
	goto FallarborNew_EventScript_TabithaPostBattle
	release
	end

FallarborNew_EventScript_TabithaPostBattle::
	speakername FallarborNew_Text_NameTabitha
	msgbox FallarborNew_Text_GoodBattle, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_TABITHA, FallarborNew_Movement_TabWalkToRydel
	applymovement OBJ_EVENT_ID_PLAYER, FallarborNew_Movement_PlayerWalkToRydel
	waitmovement 0
	delay 32
	speakername FallarborNew_Text_NameRydel
	msgbox FallarborNew_Text_WhatsUp, MSGBOX_DEFAULT
	speakername FallarborNew_Text_NameTabitha
	msgbox FallarborNew_Text_PlayerNeedsABike, MSGBOX_DEFAULT
	speakername FallarborNew_Text_NameRydel
	msgbox FallarborNew_Text_FineByMe, MSGBOX_DEFAULT
	giveitem ITEM_ACRO_BIKE
	speakername FallarborNew_Text_NameRydel
	msgbox FallarborNew_Text_ThatShouldGetYouUpMt, MSGBOX_DEFAULT
	turnobject LOCALID_TABITHA, DIR_WEST
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	delay 4
	speakername FallarborNew_Text_NameTabitha
	msgbox FallarborNew_Text_HopeThatHelpsSeeYa, MSGBOX_DEFAULT
	closemessage
	setvar VAR_OZONE_ADMINS_STATE, 8
	applymovement LOCALID_TABITHA, FallarborNew_Movement_TabLeaves
	waitmovement 0
	removeobject LOCALID_TABITHA
	setflag FLAG_TEMP_11
	release
	end

FallarborNew_Movement_TabWalkToRydel:
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

FallarborNew_Movement_PlayerWalkToRydel:
	walk_left
	walk_left
	walk_left
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
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_up
	step_end

FallarborNew_Movement_TabLeaves:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

FallarborNew_EventScript_Rydel::
	lock
	faceplayer
	goto_if_lt VAR_OZONE_ADMINS_STATE, 8, FallarborNew_EventScript_RydelPreTab
	speakername FallarborNew_Text_NameRydel
	msgbox FallarborNew_Text_HowsTheAcroBike, MSGBOX_AUTOCLOSE
	release
	end

FallarborNew_EventScript_RydelPreTab::
	msgbox FallarborNew_Text_StrangeBikeMan, MSGBOX_AUTOCLOSE
	release
	end

FallarborNew_Text_NameTabitha:
	.string "$"

FallarborNew_Text_NameRydel:
	.string "$"

FallarborNew_Text_JustVisitedCosmo:
	.string "$"

FallarborNew_Text_TabithaIntro:
	.string "$"

FallarborNew_Text_TabithaDefeated:
	.string "$"

FallarborNew_Text_GoodBattle:
	.string "$"

FallarborNew_Text_WhatsUp:
	.string "$"

FallarborNew_Text_PlayerNeedsABike:
	.string "$"

FallarborNew_Text_FineByMe:
	.string "$"

FallarborNew_Text_ThatShouldGetYouUpMt:
	.string "$"

FallarborNew_Text_HopeThatHelpsSeeYa:
	.string "$"

FallarborNew_Text_StrangeBikeMan:
	.string "$"

FallarborNew_Text_HowsTheAcroBike:
	.string "$"
