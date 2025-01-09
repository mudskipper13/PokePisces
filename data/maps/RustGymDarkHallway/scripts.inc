.set LOCALID_GANGMEMBER1, 7
.set LOCALID_GANGMEMBER2, 6
.set LOCALID_GANGMEMBER3, 9
.set LOCALID_BLOCKER, 8

RustGymDarkHallway_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, RustGymDarkHallway_OnLoad
	.byte 0

RustGymDarkHallway_OnLoad:
	call_if_gt VAR_RUST_GYM_STATE, 11, RustGymDarkHallway_EventScript_RemoveBlocker
	end

RustGymDarkHallway_EventScript_RemoveBlocker::
	removeobject LOCALID_BLOCKER
	setflag FLAG_TEMP_14
	return

RustGymDarkHallway_EventScript_LunchMoney1Left::
	lock
	delay 4
	applymovement LOCALID_GANGMEMBER1, RustGymDarkHallway_Movement_LunchAttack1Left
	waitmovement 0
	call RustGymDarkHallway_EventScript_StealLunchMoney1
	applymovement OBJ_EVENT_ID_PLAYER, RustGymDarkHallway_Movement_LunchLeave1Left
	waitmovement 0
	applymovement LOCALID_GANGMEMBER1, RustGymDarkHallway_Movement_LunchReturn1Left
	waitmovement 0
	release
	end

RustGymDarkHallway_Movement_LunchAttack1Left:
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	step_end

RustGymDarkHallway_Movement_LunchLeave1Left:
	walk_left
	step_end

RustGymDarkHallway_Movement_LunchReturn1Left:
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	step_end

RustGymDarkHallway_EventScript_LunchMoney1Right::
	lock
	delay 4
	applymovement LOCALID_GANGMEMBER1, RustGymDarkHallway_Movement_LunchAttack1Right
	waitmovement 0
	call RustGymDarkHallway_EventScript_StealLunchMoney1
	applymovement OBJ_EVENT_ID_PLAYER, RustGymDarkHallway_Movement_LunchLeave1Right
	waitmovement 0
	applymovement LOCALID_GANGMEMBER1, RustGymDarkHallway_Movement_LunchReturn1Right
	waitmovement 0
	release
	end

RustGymDarkHallway_Movement_LunchAttack1Right:
	walk_fast_down
	walk_fast_down
	face_right
	step_end

RustGymDarkHallway_Movement_LunchLeave1Right:
	walk_right
	step_end

RustGymDarkHallway_Movement_LunchReturn1Right:
	walk_fast_up
	walk_fast_up
	step_end

RustGymDarkHallway_EventScript_StealLunchMoney1::
	showmoneybox 0, 0
	msgbox RustGymDarkHallway_Text_StealLunchMoney1, MSGBOX_DEFAULT
	checkmoney 2000
	goto_if_eq VAR_RESULT, FALSE, RustGymDarkHallway_EventScript_PoorLol
	playse SE_M_PAY_DAY
	removemoney 2000
	updatemoneybox
	delay 40
	hidemoneybox
	msgbox RustGymDarkHallway_Text_Loser1, MSGBOX_DEFAULT
	closemessage
	return

RustGymDarkHallway_EventScript_PoorLol::
	msgbox RustGymDarkHallway_Text_NoMoney, MSGBOX_DEFAULT
	closemessage
	delay 40
	hidemoneybox
	return

RustGymDarkHallway_EventScript_LunchMoney2North::
	lock
	delay 4
	applymovement LOCALID_GANGMEMBER2, RustGymDarkHallway_Movement_LunchAttack2North
	waitmovement 0
	call RustGymDarkHallway_EventScript_StealLunchMoney2
	applymovement OBJ_EVENT_ID_PLAYER, RustGymDarkHallway_Movement_LunchLeave2North
	waitmovement 0
	applymovement LOCALID_GANGMEMBER2, RustGymDarkHallway_Movement_LunchReturn2North
	waitmovement 0
	release
	end

RustGymDarkHallway_Movement_LunchAttack2North:
	walk_fast_up
	walk_fast_up
	step_end

RustGymDarkHallway_Movement_LunchLeave2North:
	walk_up
	step_end

RustGymDarkHallway_Movement_LunchReturn2North:
	walk_fast_down
	walk_fast_down
	face_up
	step_end

RustGymDarkHallway_EventScript_LunchMoney2East::
	lock
	delay 4
	applymovement LOCALID_GANGMEMBER2, RustGymDarkHallway_Movement_LunchAttack2East
	waitmovement 0
	call RustGymDarkHallway_EventScript_StealLunchMoney2
	applymovement OBJ_EVENT_ID_PLAYER, RustGymDarkHallway_Movement_LunchLeave2East
	waitmovement 0
	applymovement LOCALID_GANGMEMBER2, RustGymDarkHallway_Movement_LunchReturn2East
	waitmovement 0
	release
	end

RustGymDarkHallway_Movement_LunchAttack2East:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

RustGymDarkHallway_Movement_LunchLeave2East:
	walk_right
	step_end

RustGymDarkHallway_Movement_LunchReturn2East:
	walk_fast_left
	walk_fast_left
	walk_fast_left
	face_up
	step_end

RustGymDarkHallway_EventScript_LunchMoney2South::
	lock
	delay 4
	applymovement LOCALID_GANGMEMBER2, RustGymDarkHallway_Movement_LunchAttack2South
	waitmovement 0
	call RustGymDarkHallway_EventScript_StealLunchMoney2
	applymovement OBJ_EVENT_ID_PLAYER, RustGymDarkHallway_Movement_LunchLeave2South
	waitmovement 0
	applymovement LOCALID_GANGMEMBER2, RustGymDarkHallway_Movement_LunchReturn2South
	waitmovement 0
	release
	end

RustGymDarkHallway_Movement_LunchAttack2South:
	walk_fast_left
	walk_fast_left
	walk_fast_left
	face_down
	step_end

RustGymDarkHallway_Movement_LunchLeave2South:
	walk_down
	step_end

RustGymDarkHallway_Movement_LunchReturn2South:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	face_up
	step_end

RustGymDarkHallway_EventScript_LunchMoney2West::
	lock
	delay 4
	applymovement LOCALID_GANGMEMBER2, RustGymDarkHallway_Movement_LunchAttack2West
	waitmovement 0
	call RustGymDarkHallway_EventScript_StealLunchMoney2
	applymovement OBJ_EVENT_ID_PLAYER, RustGymDarkHallway_Movement_LunchLeave2West
	waitmovement 0
	applymovement LOCALID_GANGMEMBER2, RustGymDarkHallway_Movement_LunchReturn2West
	waitmovement 0
	release
	end

RustGymDarkHallway_Movement_LunchAttack2West:
	walk_fast_left
	walk_fast_left
	step_end

RustGymDarkHallway_Movement_LunchLeave2West:
	walk_left
	step_end

RustGymDarkHallway_Movement_LunchReturn2West:
	walk_fast_right
	walk_fast_right
	face_up
	step_end

RustGymDarkHallway_EventScript_StealLunchMoney2::
	showmoneybox 0, 0
	msgbox RustGymDarkHallway_Text_StealLunchMoney2, MSGBOX_DEFAULT
	checkmoney 2000
	goto_if_eq VAR_RESULT, FALSE, RustGymDarkHallway_EventScript_PoorLol
	playse SE_M_PAY_DAY
	removemoney 2000
	updatemoneybox
	delay 40
	hidemoneybox
	msgbox RustGymDarkHallway_Text_Loser2, MSGBOX_DEFAULT
	closemessage
	return

RustGymDarkHallway_EventScript_LunchMoney3North::
	lock
	delay 4
	applymovement LOCALID_GANGMEMBER3, RustGymDarkHallway_Movement_LunchAttack3North
	waitmovement 0
	call RustGymDarkHallway_EventScript_StealLunchMoney3
	applymovement OBJ_EVENT_ID_PLAYER, RustGymDarkHallway_Movement_LunchLeave3North
	waitmovement 0
	applymovement LOCALID_GANGMEMBER3, RustGymDarkHallway_Movement_LunchReturn3North
	waitmovement 0
	release
	end

RustGymDarkHallway_Movement_LunchAttack3North:
	walk_fast_left
	walk_fast_left
	walk_fast_up
	step_end

RustGymDarkHallway_Movement_LunchLeave3North:
	walk_up
	step_end

RustGymDarkHallway_Movement_LunchReturn3North:
	walk_fast_down
	walk_fast_right
	walk_fast_right
	face_down
	step_end

RustGymDarkHallway_EventScript_LunchMoney3East::
	lock
	delay 4
	applymovement LOCALID_GANGMEMBER3, RustGymDarkHallway_Movement_LunchAttack3East
	waitmovement 0
	call RustGymDarkHallway_EventScript_StealLunchMoney3
	applymovement OBJ_EVENT_ID_PLAYER, RustGymDarkHallway_Movement_LunchLeave3East
	waitmovement 0
	applymovement LOCALID_GANGMEMBER3, RustGymDarkHallway_Movement_LunchReturn3East
	waitmovement 0
	release
	end

RustGymDarkHallway_Movement_LunchAttack3East:
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

RustGymDarkHallway_Movement_LunchLeave3East:
	walk_right
	step_end

RustGymDarkHallway_Movement_LunchReturn3East:
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_up
	face_down
	step_end

RustGymDarkHallway_EventScript_LunchMoney3South::
	lock
	delay 4
	applymovement LOCALID_GANGMEMBER3, RustGymDarkHallway_Movement_LunchAttack3South
	waitmovement 0
	call RustGymDarkHallway_EventScript_StealLunchMoney3
	applymovement OBJ_EVENT_ID_PLAYER, RustGymDarkHallway_Movement_LunchLeave3South
	waitmovement 0
	applymovement LOCALID_GANGMEMBER3, RustGymDarkHallway_Movement_LunchReturn3South
	waitmovement 0
	release
	end

RustGymDarkHallway_Movement_LunchAttack3South:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	face_down
	step_end

RustGymDarkHallway_Movement_LunchLeave3South:
	walk_down
	step_end

RustGymDarkHallway_Movement_LunchReturn3South:
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	face_down
	step_end

RustGymDarkHallway_EventScript_StealLunchMoney3::
	showmoneybox 0, 0
	msgbox RustGymDarkHallway_Text_StealLunchMoney3, MSGBOX_DEFAULT
	checkmoney 2000
	goto_if_eq VAR_RESULT, FALSE, RustGymDarkHallway_EventScript_PoorLol
	playse SE_M_PAY_DAY
	removemoney 2000
	updatemoneybox
	delay 40
	hidemoneybox
	msgbox RustGymDarkHallway_Text_Loser3, MSGBOX_DEFAULT
	closemessage
	return

RustGymDarkHallway_EventScript_Goombella::
    trainerbattle_single TRAINER_P_GOOMBELLA, RustGymDarkHallway_Text_GoombellaIntro, RustGymDarkHallway_Text_GoombellaDefeated
    msgbox RustGymDarkHallway_Text_GoombellaPostBattle, MSGBOX_AUTOCLOSE
    end

RustGymDarkHallway_EventScript_Timpani::
    trainerbattle_single TRAINER_P_TIMPANI, RustGymDarkHallway_Text_TimpaniIntro, RustGymDarkHallway_Text_TimpaniDefeated
    msgbox RustGymDarkHallway_Text_TimpaniPostBattle, MSGBOX_AUTOCLOSE
    end

RustGymDarkHallway_EventScript_PlatoAndAris::
    trainerbattle_double TRAINER_P_PLATO_AND_ARIS, RustGymDarkHallway_Text_PlatoAndArisIntro, RustGymDarkHallway_Text_PlatoAndArisDefeated, RustGymDarkHallway_Text_PlatoAndArisNeedTwoMons
    msgbox RustGymDarkHallway_Text_PlatoAndArisPostBattle, MSGBOX_AUTOCLOSE
    end

RustGymDarkHallway_Text_GoombellaIntro:
	.string "intro$"

RustGymDarkHallway_Text_GoombellaDefeated:
	.string "defeat$"

RustGymDarkHallway_Text_GoombellaPostBattle:
	.string "post$"

RustGymDarkHallway_Text_TimpaniIntro:
	.string "intro$"

RustGymDarkHallway_Text_TimpaniDefeated:
	.string "defeat$"

RustGymDarkHallway_Text_TimpaniPostBattle:
	.string "post$"

RustGymDarkHallway_Text_PlatoAndArisIntro:
	.string "intro$"

RustGymDarkHallway_Text_PlatoAndArisDefeated:
	.string "defeat$"

RustGymDarkHallway_Text_PlatoAndArisPostBattle:
	.string "post$"

RustGymDarkHallway_Text_PlatoAndArisNeedTwoMons:
	.string "need 2 dood$"

RustGymDarkHallway_Text_StealLunchMoney1:
	.string "$"

RustGymDarkHallway_Text_Loser1:
	.string "$"

RustGymDarkHallway_Text_NoMoney:
	.string "$"

RustGymDarkHallway_Text_StealLunchMoney2:
	.string "$"

RustGymDarkHallway_Text_Loser2:
	.string "$"

RustGymDarkHallway_Text_StealLunchMoney3:
	.string "$"

RustGymDarkHallway_Text_Loser3:
	.string "$"
