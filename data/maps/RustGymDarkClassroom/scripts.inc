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

RustGymDarkClassroom_EventScript_DidntLikeThatTeacher::
	msgbox RustGymDarkClassroom_Text_DidntLikeThatTeacher, MSGBOX_NPC
	end

RustGymDarkClassroom_EventScript_GoCrabberbabber::
	lock
	msgbox RustGymDarkClassroom_Text_GoCrabberbabber, MSGBOX_AUTOCLOSE
	release
	end

RustGymDarkClassroom_EventScript_MyCoffiddleCheats::
	lock
	msgbox RustGymDarkClassroom_Text_MyCoffiddleCheats, MSGBOX_AUTOCLOSE
	release
	end

RustGymDarkClassroom_EventScript_Coffiddle1::
	msgbox RustGymDarkClassroom_Text_Coffiddle1, MSGBOX_NPC
	end

RustGymDarkClassroom_EventScript_Coffiddle2::
	msgbox RustGymDarkClassroom_Text_Coffiddle2, MSGBOX_NPC
	end

RustGymDarkClassroom_EventScript_IWantedToLearn::
	msgbox RustGymDarkClassroom_Text_IWantedToLearn, MSGBOX_NPC
	end

RustGymDarkClassroom_Text_ClassCancelled:
	.string "Sup. Sorry if you're here\n"
	.string "for remedial classes.\l"
	.string "We ATE the teacher.\p"
	.string "Nah, just playin'. Teach left\n"
	.string "just a bit ago. Think\l"
	.string "he was headed to the cafeteria.\p"
	.string "Hope class gets cancelled!$"

RustGymDarkClassroom_Text_DidntLikeThatTeacher:
	.string "Teach? Didn't really get good\n"
	.string "vibes from him. That dude had\l"
	.string "serious power-hungry-middle-\l"
	.string "management energy.$"

RustGymDarkClassroom_Text_GoCrabberbabber:
	.string "Go! Keep on racing, my lil'\n"
	.string "Crabberbabber! Momma's gotta\l"
	.string "buy herself some new hairpins!$"

RustGymDarkClassroom_Text_MyCoffiddleCheats:
	.string "That girl's a nitwit.\n"
	.string "She ain't even recognize my\l"
	.string "Pokemon's been cheatin' the\l"
	.string "whole race. Layin' small fibers\l"
	.string "down to slow down the other\l"
	.string "over time. Easy money!$"

RustGymDarkClassroom_Text_Coffiddle1:
	.string "Cofico! Coffi...!$"

RustGymDarkClassroom_Text_Coffiddle2:
	.string "Fifi...figarrooo!$"

RustGymDarkClassroom_Text_IWantedToLearn:
	.string "Am I the only one here who\n"
	.string "ACTUALLY wanted to learn today?\p"
	.string "The lecture was gonna be on\n"
	.string "chemical reactions. I'm trying\l"
	.string "to make a REAL good bomb.\l"
	.string "This'll delay its completion\l"
	.string "by quite a bit...$"
