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
