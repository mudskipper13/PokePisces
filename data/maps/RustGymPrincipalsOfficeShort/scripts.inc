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
	.string "Pleased to make your acquaintance.\n"
	.string "I personally oversee all that goes\l"
	.string "on in this institution's halls,\l"
	.string "so it will do you well to follow\l"
	.string "the rules and stay in line.\p"
	.string "Let's see here... ah. Here's\n"
	.string "your record... {PLAYER}?\p"
	.string "You are in for the one-day\n"
	.string "accelerated course. In that case,\l"
	.string "there is not much time for delay.\l"
	.string "You will be reporting to\l"
	.string "Classroom B, in the hallway you\l"
	.string "arrived in, for your first lesson.\p"
	.string "Take care, and don't disappoint.$"
