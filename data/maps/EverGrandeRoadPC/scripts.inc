.set LOCALID_BREAD, 1

EverGrandeRoadPC_MapScripts::
	.byte 0

EverGrandeRoadPC_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_BREAD
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end
