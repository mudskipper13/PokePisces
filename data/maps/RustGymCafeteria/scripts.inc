.set LOCALID_MARX, 1
.set LOCALID_QIU, 2

RustGymCafeteria_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, RustGymCafeteria_OnFrame
	.byte 0

RustGymCafeteria_OnFrame:
	map_script_2 VAR_RUST_GYM_STATE, 4, RustGymCafeteria_EventScript_CafeteriaAutoScript
	.2byte 0

RustGymCafeteria_EventScript_CafeteriaAutoScript::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, RustGymCafeteria_Movement_WalkToSeat
	waitmovement 0
	delay 16
	msgbox RustGymCafeteria_Text_LunchByYourself, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MARX, RustGymCafeteria_Movement_MarxWalkToTable
	applymovement LOCALID_QIU, RustGymCafeteria_Movement_QiuWalkToTable
	waitmovement 0
	msgbox RustGymCafeteria_Text_WeAreHavingADiscussion, MSGBOX_DEFAULT
	trainerbattle_two_trainers TRAINER_P_MARX, RustGymCafeteria_Text_MarxDefeat, TRAINER_P_QIU, RustGymCafeteria_Text_QiuDefeat, RustGymCafeteria_EventScript_CafeteriaPostBattle
	goto RustGymCafeteria_EventScript_CafeteriaPostBattle
	release
	end

RustGymCafeteria_EventScript_CafeteriaPostBattle::
	msgbox RustGymCafeteria_Text_TaughtUsNothingActually, MSGBOX_DEFAULT
	playse SE_BIKE_BELL
	applymovement LOCALID_MARX, RustGymCafeteria_Movement_Exclamation
	applymovement LOCALID_QIU, RustGymCafeteria_Movement_Exclamation
	waitmovement 0
	msgbox RustGymCafeteria_Text_BackToClass, MSGBOX_DEFAULT
	closemessage
	setvar VAR_RUST_GYM_STATE, 5
	release
	end

RustGymCafeteria_Movement_WalkToSeat:
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	face_up
	step_end

RustGymCafeteria_Movement_MarxWalkToTable:
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	face_down
	step_end

RustGymCafeteria_Movement_QiuWalkToTable:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	face_down
	step_end

RustGymCafeteria_Movement_Exclamation:
	emote_exclamation_mark
	step_end

RustGymCafeteria_Text_LunchByYourself:
	.string "(You recline in the bench\n"
	.string "to prep for some alone time.)$"

RustGymCafeteria_Text_WeAreHavingADiscussion:
	.string "You seem a little lonely there,\n"
	.string "random person! Hey, want to\l"
	.string "join in on our discussion?\p"
	.string "(You nod your head no.)\p"
	.string "Great! So, we were just\n"
	.string "pontificating about releasing\l"
	.string "our Pokemon from their balls\l"
	.string "for good. Would that not be\l"
	.string "the best thing for them?\l"
	.string "Complete Pokemon Liberation?\p"
	.string "(You shrug with a very\n"
	.string "annoyed expression on your face.)\p"
	.string "You know, you're awfully quiet.\n"
	.string "I wonder if your Pokemon wish\l"
	.string "to be let go into the wild, too.\p"
	.string "Let's send 'em all out and see\n"
	.string "what they end up choosing!$"

RustGymCafeteria_Text_MarxDefeat:
	.string "Your Pokemon started a violent\n"
	.string "insurrection... against us???$"

RustGymCafeteria_Text_QiuDefeat:
	.string "W-We get it now!\n"
	.string "We'll leave you be!$"

RustGymCafeteria_Text_TaughtUsNothingActually:
	.string "(You feel you've learned\n"
	.string "absolutely nothing from this\l"
	.string "interaction.)$"

RustGymCafeteria_Text_BackToClass:
	.string "(Back to Classroom B.)$"
