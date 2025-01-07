.set LOCALID_LANETTE, 1

RustGymComputerLab_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, RustGymComputerLab_OnFrame
	.byte 0

RustGymComputerLab_OnFrame:
	map_script_2 VAR_RUST_GYM_STATE, 3, RustGymComputerLab_EventScript_ComputerClass
	.2byte 0

RustGymComputerLab_EventScript_ComputerClass::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, RustGymComputerLab_Movement_WalkToSeat
	waitmovement 0
	delay 16
	applymovement LOCALID_LANETTE, RustGymComputerLab_Movement_LanetteAddressClass
	waitmovement 0
	msgbox RustGymComputerLab_Text_MyNameIsLanette, MSGBOX_DEFAULT
	speakername RustGymComputerLab_Text_NameLanette
	msgbox RustGymComputerLab_Text_ComputerClass1, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_LANETTE, RustGymComputerLab_Movement_LanetteBackToComputer
	waitmovement 0
	playse SE_PC_ON
	waitse
	msgbox RustGymComputerLab_Text_BootingUpComputer, MSGBOX_DEFAULT
	playse SE_PC_LOGIN
	waitse
	msgbox RustGymComputerLab_Text_ComputerClass2, MSGBOX_DEFAULT
	playse SE_BIKE_BELL
	waitse
	applymovement LOCALID_LANETTE, RustGymComputerLab_Movement_LanetteAddressClass
	waitmovement 0
	setvar VAR_RUST_GYM_STATE, 4
	speakername RustGymComputerLab_Text_NameLanette
	msgbox RustGymComputerLab_Text_ComputerClassOver, MSGBOX_DEFAULT
	closemessage
	release
	end

RustGymComputerLab_Movement_WalkToSeat:
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
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

RustGymComputerLab_Movement_LanetteAddressClass:
	face_left
	step_end

RustGymComputerLab_Movement_LanetteBackToComputer:
	face_right
	step_end

RustGymComputerLab_Text_NameLanette:
	.string "Lanette$"

RustGymComputerLab_Text_MyNameIsLanette:
	.string "$"

RustGymComputerLab_Text_ComputerClass1:
	.string "$"

RustGymComputerLab_Text_BootingUpComputer:
	.string "$"

RustGymComputerLab_Text_ComputerClass2:
	.string "$"

RustGymComputerLab_Text_ComputerClassOver:
	.string "$"
