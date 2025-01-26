.set LOCALID_STEVEN, 1

PetalburgNew_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, PetalburgNew_OnLoad
	.byte 0

PetalburgNew_OnLoad:
	call_if_lt VAR_WALLY_QUEST_STATE, 2, PetalburgNew_EventScript_RemoveSteven
	call_if_gt VAR_WALLY_QUEST_STATE, 2, PetalburgNew_EventScript_RemoveSteven
	end

PetalburgNew_EventScript_RemoveSteven::
	removeobject LOCALID_STEVEN
	setflag FLAG_TEMP_11
	return

PetalburgNew_EventScript_StevenEncounter1::
	lock
	applymovement LOCALID_STEVEN, PetalburgNew_Movement_StevenEncounter1
	waitmovement 0
	delay 4
	goto PetalburgNew_EventScript_NormanNotHere
	release
	end

PetalburgNew_Movement_StevenEncounter1:
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

PetalburgNew_EventScript_StevenEncounter2::
	lock
	applymovement LOCALID_STEVEN, PetalburgNew_Movement_StevenEncounter2
	waitmovement 0
	delay 4
	goto PetalburgNew_EventScript_NormanNotHere
	release
	end

PetalburgNew_Movement_StevenEncounter2:
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

PetalburgNew_EventScript_StevenEncounter3::
	lock
	applymovement LOCALID_STEVEN, PetalburgNew_Movement_StevenEncounter3
	waitmovement 0
	delay 4
	goto PetalburgNew_EventScript_NormanNotHere
	release
	end

PetalburgNew_Movement_StevenEncounter3:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

PetalburgNew_EventScript_StevenEncounter4::
	lock
	applymovement LOCALID_STEVEN, PetalburgNew_Movement_StevenEncounter4
	waitmovement 0
	delay 4
	goto PetalburgNew_EventScript_NormanNotHere
	release
	end

PetalburgNew_Movement_StevenEncounter4:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

PetalburgNew_EventScript_NormanNotHere::
	setvar VAR_WALLY_QUEST_STATE, 3
	speakername PetalburgNew_Text_NameSteven
	msgbox PetalburgNew_Text_NormanNotHere, MSGBOX_AUTOCLOSE
	release
	end

PetalburgNew_EventScript_StevenIdle::
	lock
	faceplayer
	speakername PetalburgNew_Text_NameSteven
	msgbox PetalburgNew_Text_StevenIdle, MSGBOX_AUTOCLOSE
	release
	end

PetalburgNew_EventScript_ShouldntGoHere::
	lock
	delay 4
	msgbox PetalburgNew_Text_ShouldntGoHere, MSGBOX_AUTOCLOSE
	applymovement OBJ_EVENT_ID_PLAYER, PetalburgNew_Movement_BackUp
	waitmovement 0
	release
	end

PetalburgNew_Movement_BackUp:
	walk_down
	step_end

PetalburgNew_Text_NameSteven:
	.string "Steven$"

PetalburgNew_Text_NormanNotHere:
	.string "norman aint here dood$"

PetalburgNew_Text_StevenIdle:
	.string "y u still here go to\n"
	.string "da woods$"

PetalburgNew_Text_ShouldntGoHere:
	.string "(You have business in\n"
	.string "Rustboro; probably shouldn't\l"
	.string "get too sidetracked.)$"
