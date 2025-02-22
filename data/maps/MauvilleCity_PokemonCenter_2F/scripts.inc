.set LOCALID_NURSE, 1

MauvilleCity_PokemonCenter_2F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MauvilleCity_PokemonCenter_2F_OnTransition
	.byte 0

MauvilleCity_PokemonCenter_2F_OnTransition:
	setrespawn HEAL_LOCATION_SEA_MAUVILLE
	end

MauvilleCity_PokemonCenter_2F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end
