.set LOCALID_GREETER, 1

RustGymEntryHallways_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, RustGymEntryHallways_OnLoad
	.byte 0

RustGymEntryHallways_OnLoad:
	call_if_gt VAR_RUST_GYM_STATE, 0, RustGymEntryHallways_EventScript_RemoveGreeter
	end

RustGymEntryHallways_EventScript_RemoveGreeter::
	removeobject LOCALID_GREETER
	setflag FLAG_TEMP_14
	return

RustGymEntryHallways_EventScript_GreeterLeft::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, RustGymEntryHallways_Movement_PlayerFormUpToGreet
	waitmovement 0
	goto RustGymEntryHallways_EventScript_Greeter
	release
	end

RustGymEntryHallways_EventScript_Greeter::
	lock
	applymovement LOCALID_GREETER, RustGymEntryHallways_Movement_GreeterFormUpToGreet
	waitmovement 0
	setvar VAR_RUST_GYM_STATE, 1
	msgbox RustGymEntryHallways_Text_WelcomeToRustboroUniversity, MSGBOX_DEFAULT
	closemessage
	delay 4
	warp MAP_RUST_GYM_PRINCIPALS_OFFICE_SHORT, 2, 10
	waitstate
	release
	end

RustGymEntryHallways_Movement_PlayerFormUpToGreet:
	walk_right
	face_up
	step_end

RustGymEntryHallways_Movement_GreeterFormUpToGreet:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

RustGymEntryHallways_Text_WelcomeToRustboroUniversity:
	.string "$"
