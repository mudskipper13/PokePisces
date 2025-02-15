LittlerootNew_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootNew_OnTransition
	.byte 0

LittlerootNew_OnTransition:
	setflag FLAG_VISITED_LITTLEROOT_TOWN
	end
