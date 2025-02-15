CaveOfOriginCutscene_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CaveOfOriginCutscene_OnFrame
	.byte 0

CaveOfOriginCutscene_OnFrame:
	map_script_2 VAR_NEW_COO_STATE, 6, CaveOfOriginCutscene_EventScript_FishMissing
	.2byte 0

CaveOfOriginCutscene_EventScript_FishMissing::
	lock
	speakername CaveOfOriginCutscene_Text_NameWallace
	msgbox CaveOfOriginCutscene_Text_WereTooLate, MSGBOX_DEFAULT
	speakername CaveOfOriginCutscene_Text_NameMaxie
	msgbox CaveOfOriginCutscene_Text_WhatCanWeDoNow, MSGBOX_DEFAULT
	speakername CaveOfOriginCutscene_Text_NameWallace
	msgbox CaveOfOriginCutscene_Text_TrackThemDown, MSGBOX_DEFAULT
	speakername CaveOfOriginCutscene_Text_NameArchie
	msgbox CaveOfOriginCutscene_Text_HighestAndLowest, MSGBOX_DEFAULT
	speakername CaveOfOriginCutscene_Text_NameWallace
	msgbox CaveOfOriginCutscene_Text_YouMayComePlayer, MSGBOX_DEFAULT
	warp MAP_NEW_SOOTO, 31, 31
	waitstate
	release
	end

CaveOfOriginCutscene_Text_NameWallace:
	.string "Wallace$"

CaveOfOriginCutscene_Text_NameMaxie:
	.string "Maxie$"

CaveOfOriginCutscene_Text_NameArchie:
	.string "Archie$"

CaveOfOriginCutscene_Text_WereTooLate:
	.string "$"

CaveOfOriginCutscene_Text_WhatCanWeDoNow:
	.string "$"

CaveOfOriginCutscene_Text_TrackThemDown:
	.string "$"

CaveOfOriginCutscene_Text_HighestAndLowest:
	.string "$"

CaveOfOriginCutscene_Text_YouMayComePlayer:
	.string "$"
