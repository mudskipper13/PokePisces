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
	.string "Welcome to computer lab...\n"
	.string "My name is Lanette. You could\l"
	.string "call me Ms. Lanette. Or you\l"
	.string "could not. Neither way really\l"
	.string "changes our roles here.$"

RustGymComputerLab_Text_ComputerClass1:
	.string "Some of you may know me as\n"
	.string "having developed Hoenn's\l"
	.string "PC box system. You would be\l"
	.string "correct.\p"
	.string "After working with Pokemon storage\n"
	.string "for so long, I came to take an\l"
	.string "interest in battling. Hence,\l"
	.string "I have been hard at work\l"
	.string "on a battle simulator program.\p"
	.string "A micro-version of my program\n"
	.string "has been loaded onto your\l"
	.string "systems. Watch what happens\l"
	.string "closely... there will be questions\l"
	.string "about battling mechanics\l"
	.string "on your final exam.$"

RustGymComputerLab_Text_BootingUpComputer:
	.string "(The computer boots up,\n"
	.string "opening a program titled\l"
	.string "simply HHP.exe.)$"

RustGymComputerLab_Text_ComputerClass2:
	.string "(In the simulation, you\n"
	.string "control a person in grey\l"
	.string "militaristic clothing, carrying\l"
	.string "a sword, as they start a\l"
	.string "Pokemon Battle.\p"
	.string "A long-necked bird of prey\n"
	.string "Pokemon is sent out to fight\l"
	.string "a mono-eyed barnacle Pokemon\l"
	.string "that is wrapped around a glacier.\p"
	.string "The bird uses Dire Claw, damaging\n"
	.string "the barnacle and poisoning it.\p"
	.string "The barnacle uses Laser Focus,\n"
	.string "which guarantees its next move\l"
	.string "will land a critical hit.\p"
	.string "Next turn.\p"
	.string "The bird uses Lock-On, which\n"
	.string "guarantees its next move will\l"
	.string "hit its foe.\p"
	.string "The barnacle predicts its\n"
	.string "opponent will set up, so it\l"
	.string "also sets up by using Laser Focus\l"
	.string "again.\p"
	.string "Since neither Pokemon was hit this\n"
	.string "turn, a special aspect of both\l"
	.string "Laser Focus and Lock-On was\l"
	.string "activated at the end of the turn.\p"
	.string "Laser Focus raised the barnacle's\n"
	.string "Attack by two stages.\l"
	.string "Lock-On raised the bird's\l"
	.string "Special Attack by two stages.\p"
	.string "Next turn.\p"
	.string "The bird uses Hurricane.\n"
	.string "Hurricane lands and KOs\l"
	.string "the barnacle.)$"

RustGymComputerLab_Text_ComputerClassOver:
	.string "There goes the bell.\n"
	.string "Hope you all enjoyed the sim...\l"
	.string "it was a blast to program.\p"
	.string "Your next period should be\n"
	.string "lunch in the cafeteria.\l"
	.string "You've earned some relaxation.$"
