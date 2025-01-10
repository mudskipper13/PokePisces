.set LOCALID_ROXANNE, 8
.set LOCALID_DIOGENES, 7
.set LOCALID_PEON1, 2
.set LOCALID_PEON2, 1
.set LOCALID_PEON3, 6
.set LOCALID_PEON4, 5
.set LOCALID_PEON5, 4
.set LOCALID_PEON6, 3

RustGymDarkCafeteria_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, RustGymDarkCafeteria_OnLoad
	.byte 0

RustGymDarkCafeteria_OnLoad:
	call RustGymDarkCafeteria_EventScript_RemoveRoxanne
	call_if_lt VAR_RUST_GYM_STATE, 12, RustGymDarkCafeteria_EventScript_RemoveDiogenes
	end

RustGymDarkCafeteria_EventScript_RemoveRoxanne::
	removeobject LOCALID_ROXANNE
	setflag FLAG_TEMP_14
	return

RustGymDarkCafeteria_EventScript_RemoveDiogenes::
	removeobject LOCALID_DIOGENES
	setflag FLAG_TEMP_15
	return

RustGymDarkCafeteria_EventScript_StartGangWarLeft::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, RustGymDarkCafeteria_Movement_PlayerWalkRight
	waitmovement 0
	goto RustGymDarkCafeteria_EventScript_GangWar
	release
	end

RustGymDarkCafeteria_EventScript_StartGangWarRight::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, RustGymDarkCafeteria_Movement_PlayerWalkLeft
	waitmovement 0
	goto RustGymDarkCafeteria_EventScript_GangWar
	release
	end

RustGymDarkCafeteria_Movement_PlayerWalkLeft:
	walk_left
	step_end

RustGymDarkCafeteria_Movement_PlayerWalkRight:
	walk_right
	step_end

RustGymDarkCafeteria_EventScript_GangWar::
	lock
	delay 4
	applymovement OBJ_EVENT_ID_PLAYER, RustGymDarkCafeteria_Movement_PlayerGoToCenter
	waitmovement 0
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	msgbox RustGymDarkCafeteria_Text_ImTakingOver, MSGBOX_DEFAULT
	closemessage
	playmoncry SPECIES_FOONGUS, CRY_MODE_NORMAL
	waitmoncry
	applymovement LOCALID_PEON1, RustGymDarkCafeteria_Movement_Peon1GoToCenter
	applymovement LOCALID_PEON2, RustGymDarkCafeteria_Movement_Peon2GoToCenter
	applymovement LOCALID_PEON3, RustGymDarkCafeteria_Movement_Peon3GoToCenter
	applymovement LOCALID_PEON4, RustGymDarkCafeteria_Movement_Peon4GoToCenter
	applymovement LOCALID_PEON5, RustGymDarkCafeteria_Movement_Peon5GoToCenter
	applymovement LOCALID_PEON6, RustGymDarkCafeteria_Movement_Peon6GoToCenter
	waitmovement 0
	delay 32
	trainerbattle_single TRAINER_P_DIOGENES, RustGymDarkCafeteria_Text_DiogenesIntro, RustGymDarkCafeteria_Text_DiogenesDefeated, RustGymDarkCafeteria_EventScript_DiogenesDefeat
	goto RustGymDarkCafeteria_EventScript_DiogenesDefeat
	release
	end

RustGymDarkCafeteria_Movement_PlayerGoToCenter:
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

RustGymDarkCafeteria_Movement_Peon1GoToCenter:
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fast_right
	face_up
	step_end

RustGymDarkCafeteria_Movement_Peon2GoToCenter:
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_right
	step_end

RustGymDarkCafeteria_Movement_Peon3GoToCenter:
	walk_fast_left
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_right
	walk_fast_down
	walk_fast_right
	face_down
	step_end

RustGymDarkCafeteria_Movement_Peon4GoToCenter:
	jump_2_down
	step_end

RustGymDarkCafeteria_Movement_Peon5GoToCenter:
	walk_fast_left
	walk_fast_left
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_left
	step_end

RustGymDarkCafeteria_Movement_Peon6GoToCenter:
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	face_up
	step_end

RustGymDarkCafeteria_EventScript_DiogenesDefeat::
	setvar VAR_RUST_GYM_STATE, 13
	delay 8
	msgbox RustGymDarkCafeteria_Text_ThisIsntOver, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_NONE, FALSE
	clearflag FLAG_TEMP_14
	addobject LOCALID_ROXANNE
	playse SE_M_STRENGTH
	waitse
	removeobject LOCALID_DIOGENES
	setflag FLAG_TEMP_15
	setmetatile 6, 6, METATILE_RustboroGymNew_DiogenesLeft, TRUE
	setmetatile 7, 6, METATILE_RustboroGymNew_DiogenesRight, TRUE
	special DrawWholeMapView
	delay 16
	speakername RustGymDarkCafeteria_Text_NameRoxanne
	msgbox RustGymDarkCafeteria_Text_ThatsEnoughOfThat, MSGBOX_DEFAULT
	closemessage
	warp MAP_RUST_GYM_DARK_CAFE_ARENA, 6, 8
	waitstate
	release
	end

RustGymDarkCafeteria_Text_NameRoxanne:
	.string "Roxanne$"

RustGymDarkCafeteria_Text_ImTakingOver:
	.string "$"

RustGymDarkCafeteria_Text_DiogenesIntro:
	.string "$"

RustGymDarkCafeteria_Text_DiogenesDefeated:
	.string "$"

RustGymDarkCafeteria_Text_ThisIsntOver:
	.string "$"

RustGymDarkCafeteria_Text_ThatsEnoughOfThat:
	.string "$"
