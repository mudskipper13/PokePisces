RustGymClassroom_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, RustGymClassroom_OnFrame
	.byte 0

RustGymClassroom_OnFrame:
	map_script_2 VAR_RUST_GYM_STATE, 2, RustGymClassroom_EventScript_Class1
	.2byte 0

RustGymClassroom_EventScript_Class1::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, RustGymClassroom_Movement_WalkToSeat
	waitmovement 0
	release
	end

RustGymClassroom_Movement_WalkToSeat:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	face_up
	step_end
