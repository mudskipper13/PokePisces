.set LOCALID_NURSE, 1

EverGrandeRoadPC_MapScripts::
	.byte 0

EverGrandeRoadPC_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end
