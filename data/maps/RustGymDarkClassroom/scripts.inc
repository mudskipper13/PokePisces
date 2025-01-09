.set LOCALID_STUDENT, 4

RustGymDarkClassroom_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, RustGymDarkClassroom_OnFrame
	.byte 0

RustGymDarkClassroom_OnFrame:
	map_script_2 VAR_RUST_GYM_STATE, 11, RustGymDarkClassroom_EventScript_ClassCancelled
	.2byte 0

RustGymDarkClassroom_EventScript_ClassCancelled::
	lock
	delay 4
	applymovement LOCALID_STUDENT, RustGymDarkClassroom_Movement_TurnRight
	applymovement OBJ_EVENT_ID_PLAYER, RustGymDarkClassroom_Movement_PlayerWalkToStudent
	waitmovement 0
	delay 8
	setvar VAR_RUST_GYM_STATE, 12
	msgbox RustGymDarkClassroom_Text_ClassCancelled, MSGBOX_DEFAULT
	closemessage
	release
	end

RustGymDarkClassroom_Movement_TurnRight:
	face_right
	step_end

RustGymDarkClassroom_Movement_PlayerWalkToStudent:
	walk_up
	walk_up
	walk_up
	walk_up
	face_left
	step_end

RustGymDarkClassroom_Text_ClassCancelled:
	.string "$"
