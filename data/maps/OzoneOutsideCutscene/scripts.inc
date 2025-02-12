.set LOCALID_MAXIE, 2
.set LOCALID_ARCHIE, 1
.set LOCALID_WALLACE, 3

OzoneOutsideCutscene_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, OzoneOutsideCutscene_OnFrame
	.byte 0

OzoneOutsideCutscene_OnFrame:
	map_script_2 VAR_TEMP_4, 0, OzoneOutsideCutscene_EventScript_MeetWallace
	.2byte 0

OzoneOutsideCutscene_EventScript_MeetWallace::
	lock
	setvar VAR_TEMP_4, 1
	applymovement OBJ_EVENT_ID_PLAYER, OzoneOutsideCutscene_Movement_PlayerWalkToWallace
	applymovement LOCALID_MAXIE, OzoneOutsideCutscene_Movement_MaxieWalkToWallace
	applymovement LOCALID_ARCHIE, OzoneOutsideCutscene_Movement_ArchieWalkToWallace
	waitmovement 0
	applymovement LOCALID_WALLACE, OzoneOutsideCutscene_Movement_WallaceWalksIn
	waitmovement 0
	delay 8
	speakername OzoneOutsideCutscene_Text_NameArchie
	msgbox OzoneOutsideCutscene_Text_HeyWallace, MSGBOX_DEFAULT
	speakername OzoneOutsideCutscene_Text_NameWallace
	msgbox OzoneOutsideCutscene_Text_OriginIsUnderSiege, MSGBOX_DEFAULT
	speakername OzoneOutsideCutscene_Text_NameMaxie
	msgbox OzoneOutsideCutscene_Text_LetsGetTherePostHaste, MSGBOX_DEFAULT
	closemessage
	warp MAP_CAVE_OF_ORIGIN_CUTSCENE, 8, 7
	waitstate
	release
	end

OzoneOutsideCutscene_Movement_PlayerWalkToWallace:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

OzoneOutsideCutscene_Movement_MaxieWalkToWallace:
	walk_left
	walk_left
	walk_left
	walk_up
	walk_left
	walk_left
	step_end

OzoneOutsideCutscene_Movement_ArchieWalkToWallace:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

OzoneOutsideCutscene_Movement_WallaceWalksIn:
	walk_right
	walk_right
	step_end

OzoneOutsideCutscene_Text_NameMaxie:
	.string "Maxie$"

OzoneOutsideCutscene_Text_NameArchie:
	.string "Archie$"

OzoneOutsideCutscene_Text_NameWallace:
	.string "Wallace$"

OzoneOutsideCutscene_Text_HeyWallace:
	.string "$"

OzoneOutsideCutscene_Text_OriginIsUnderSiege:
	.string "$"

OzoneOutsideCutscene_Text_LetsGetTherePostHaste:
	.string "$"
