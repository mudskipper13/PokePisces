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

RustGymEntryHallways_EventScript_PassTheTest::
	msgbox RustGymEntryHallways_Text_PassTheTest, MSGBOX_NPC
	end

RustGymEntryHallways_EventScript_BrainAgeKid::
	msgbox RustGymEntryHallways_Text_BrainAgeKid, MSGBOX_NPC
	end

RustGymEntryHallways_EventScript_TetrisKid::
	msgbox RustGymEntryHallways_Text_TetrisKid, MSGBOX_NPC
	end

RustGymEntryHallways_EventScript_ClassroomASign::
	msgbox RustGymEntryHallways_Text_ClassroomASign, MSGBOX_SIGN
	end

RustGymEntryHallways_EventScript_ClassroomCSign::
	msgbox RustGymEntryHallways_Text_ClassroomCSign, MSGBOX_SIGN
	end

RustGymEntryHallways_EventScript_ClassroomDSign::
	msgbox RustGymEntryHallways_Text_ClassroomDSign, MSGBOX_SIGN
	end

RustGymEntryHallways_Text_WelcomeToRustboroUniversity:
	.string "Welcome to Rustboro University!\p"
	.string "I assume you are here as a Gym\n"
	.string "Challenger, hoping to enroll in\l"
	.string "a one-day accelerated course?\p"
	.string "In that case, let me send you to\n"
	.string "meet Principal Roxanne to get\l"
	.string "all your ducks in a row.$"

RustGymEntryHallways_Text_PassTheTest:
	.string "After a few classroom lessons\n"
	.string "and a lunch period, you gotta\l"
	.string "be ready to pass a multiple\l"
	.string "choice test at the end.\l"
	.string "Study up! Anything can\l"
	.string "be on that bad boy.$"

RustGymEntryHallways_Text_BrainAgeKid:
	.string "I'm playing Brain Age to\n"
	.string "help my noggin get supercharged!\p"
	.string "I hear it actually helps you\n"
	.string "stay sharp!$"

RustGymEntryHallways_Text_TetrisKid:
	.string "I'm playing Tetris a bunch\n"
	.string "to help my brain feel good.\l"
	.string "Or so that study I read the\l"
	.string "title of once said.$"

RustGymEntryHallways_Text_ClassroomASign:
	.string "Classroom A$"

RustGymEntryHallways_Text_ClassroomCSign:
	.string "Classroom C$"

RustGymEntryHallways_Text_ClassroomDSign:
	.string "Classroom D$"
