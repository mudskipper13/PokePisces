RustGymPrincipalsOfficeShort_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, RustGymPrincipalsOfficeShort_OnFrame
	.byte 0

RustGymPrincipalsOfficeShort_OnFrame:
	map_script_2 VAR_RUST_GYM_STATE, 1, RustGymPrincipalsOfficeShort_EventScript_Enroll
	.2byte 0

RustGymPrincipalsOfficeShort_EventScript_Enroll::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, RustGymPrincipalsOfficeShort_Movement_WalkUpToRox
	waitmovement 0
	speakername RustGymPrincipalsOfficeShort_Text_NameRoxanne
	msgbox RustGymPrincipalsOfficeShort_Text_EnrollInTheUniversity, MSGBOX_DEFAULT
	closemessage
	delay 8
	setvar VAR_RUST_GYM_STATE, 2
	applymovement OBJ_EVENT_ID_PLAYER, RustGymPrincipalsOfficeShort_Movement_GoToClass
	waitmovement 0
	warp MAP_RUST_GYM_EXTRACURRICULAR_HALLWAY, 18, 2
	waitstate
	release
	end

RustGymPrincipalsOfficeShort_Movement_WalkUpToRox:
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

RustGymPrincipalsOfficeShort_Movement_GoToClass:
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

RustGymPrincipalsOfficeShort_Text_NameRoxanne:
	.string "Roxanne$"

RustGymPrincipalsOfficeShort_Text_EnrollInTheUniversity:
	.string "$"
