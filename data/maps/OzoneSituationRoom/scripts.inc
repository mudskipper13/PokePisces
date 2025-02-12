.set LOCALID_MAXIE, 2
.set LOCALID_ARCHIE, 1
.set LOCALID_RAY, 3
.set LOCALID_COURTNEY, 4
.set LOCALID_TABITHA, 5
.set LOCALID_MATT, 6

OzoneSituationRoom_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, OzoneSituationRoom_OnFrame
	.byte 0

OzoneSituationRoom_OnFrame:
	map_script_2 VAR_TEMP_4, 0, OzoneSituationRoom_EventScript_Situation
	.2byte 0

OzoneSituationRoom_EventScript_Situation::
	lock
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	speakername OzoneSituationRoom_Text_NameMaxie
	msgbox OzoneSituationRoom_Text_GroudonAndKyogreAreFighting, MSGBOX_DEFAULT
	speakername OzoneSituationRoom_Text_NameTabitha
	msgbox OzoneSituationRoom_Text_WhatCourseOfAction, MSGBOX_DEFAULT
	speakername OzoneSituationRoom_Text_NameMaxie
	msgbox OzoneSituationRoom_Text_ToTheCaveOfOrigin, MSGBOX_DEFAULT
	closemessage
	setvar VAR_NEW_COO_STATE, 6
	setvar VAR_TEMP_4, 1
	release
	end

OzoneSituationRoom_EventScript_MaxieIdle::
	lock
	faceplayer
	speakername OzoneSituationRoom_Text_NameMaxie
	msgbox OzoneSituationRoom_Text_GetReady, MSGBOX_AUTOCLOSE
	release
	end

OzoneSituationRoom_EventScript_ArchieIdle::
	lock
	speakername OzoneSituationRoom_Text_NameArchie
	msgbox OzoneSituationRoom_Text_NeverThoughtThisWouldHappen, MSGBOX_AUTOCLOSE
	release
	end

OzoneSituationRoom_EventScript_RayIdle::
	lock
	faceplayer
	speakername OzoneSituationRoom_Text_NameRay
	msgbox OzoneSituationRoom_Text_YouAlwaysCauseTrouble, MSGBOX_AUTOCLOSE
	release
	end

OzoneSituationRoom_EventScript_CourtneyIdle::
	lock
	faceplayer
	speakername OzoneSituationRoom_Text_NameCourtney
	msgbox OzoneSituationRoom_Text_TheCrops, MSGBOX_AUTOCLOSE
	release
	end

OzoneSituationRoom_EventScript_TabithaIdle::
	lock
	faceplayer
	speakername OzoneSituationRoom_Text_NameTabitha
	msgbox OzoneSituationRoom_Text_MakingAPlan, MSGBOX_AUTOCLOSE
	release
	end

OzoneSituationRoom_EventScript_MattIdle::
	lock
	faceplayer
	speakername OzoneSituationRoom_Text_NameMatt
	msgbox OzoneSituationRoom_Text_ThisRilesMeUp, MSGBOX_AUTOCLOSE
	release
	end

OzoneSituationRoom_Text_NameMaxie:
	.string "Maxie$"

OzoneSituationRoom_Text_NameArchie:
	.string "Archie$"

OzoneSituationRoom_Text_NameRay:
	.string "Ray$"

OzoneSituationRoom_Text_NameCourtney:
	.string "Courtney$"

OzoneSituationRoom_Text_NameTabitha:
	.string "Tabitha$"

OzoneSituationRoom_Text_NameMatt:
	.string "Matt$"

OzoneSituationRoom_Text_GroudonAndKyogreAreFighting:
	.string "$"

OzoneSituationRoom_Text_WhatCourseOfAction:
	.string "$"

OzoneSituationRoom_Text_ToTheCaveOfOrigin:
	.string "$"

OzoneSituationRoom_Text_GetReady:
	.string "$"

OzoneSituationRoom_Text_NeverThoughtThisWouldHappen:
	.string "$"

OzoneSituationRoom_Text_YouAlwaysCauseTrouble:
	.string "$"

OzoneSituationRoom_Text_TheCrops:
	.string "$"

OzoneSituationRoom_Text_MakingAPlan:
	.string "$"

OzoneSituationRoom_Text_ThisRilesMeUp:
	.string "$"
