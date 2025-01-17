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
