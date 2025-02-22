.set LOCALID_YANDEMIC, 1

FortreeCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FortreeCity_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, FortreeCity_OnResume
	.byte 0

FortreeCity_OnTransition:
	setflag FLAG_VISITED_FORTREE_CITY
	call_if_ge VAR_NOTICED_BY_YANDEMIC, 5, FortreeCity_EventScript_RemoveYandemic
	end

FortreeCity_EventScript_RemoveYandemic::
	removeobject LOCALID_YANDEMIC
	setflag FLAG_TEMP_11
	return

FortreeCity_OnResume:
	setstepcallback STEP_CB_FORTREE_BRIDGE
	end
