.set LOCALID_DEVONEMPLOYEE, 1

RustboroNew_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RustboroNew_OnTransition
	.byte 0

RustboroNew_OnTransition:
	setflag FLAG_VISITED_RUSTBORO_CITY
	end

RustboroNew_EventScript_DevonEncounterStartUpLeft::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, RustboroNew_Movement_PlayerStartUpLeft
	waitmovement 0
	applymovement LOCALID_DEVONEMPLOYEE, RustboroNew_Movement_EmployeeStartUpLeft
	waitmovement 0
	delay 4
	goto RustboroNew_EventScript_DevonEncounter
	release
	end

RustboroNew_Movement_PlayerStartUpLeft:
	face_right
	step_end

RustboroNew_Movement_EmployeeStartUpLeft:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

RustboroNew_EventScript_DevonEncounterStartDownLeft::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, RustboroNew_Movement_PlayerStartDownLeft
	waitmovement 0
	applymovement LOCALID_DEVONEMPLOYEE, RustboroNew_Movement_EmployeeStartDownLeft
	waitmovement 0
	delay 4
	goto RustboroNew_EventScript_DevonEncounter
	release
	end

RustboroNew_Movement_PlayerStartDownLeft:
	face_right
	step_end

RustboroNew_Movement_EmployeeStartDownLeft:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

RustboroNew_EventScript_DevonEncounterStartDown::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, RustboroNew_Movement_PlayerStartDown
	waitmovement 0
	applymovement LOCALID_DEVONEMPLOYEE, RustboroNew_Movement_EmployeeStartDown
	waitmovement 0
	delay 4
	goto RustboroNew_EventScript_DevonEncounter
	release
	end

RustboroNew_Movement_PlayerStartDown:
	face_up
	step_end

RustboroNew_Movement_EmployeeStartDown:
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

RustboroNew_EventScript_DevonEncounterStartDownRight::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, RustboroNew_Movement_PlayerStartDownRight
	waitmovement 0
	applymovement LOCALID_DEVONEMPLOYEE, RustboroNew_Movement_EmployeeStartDownRight
	waitmovement 0
	delay 4
	goto RustboroNew_EventScript_DevonEncounter
	release
	end

RustboroNew_Movement_PlayerStartDownRight:
	face_right
	step_end

RustboroNew_Movement_EmployeeStartDownRight:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

RustboroNew_EventScript_DevonEncounterStartUpRight::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, RustboroNew_Movement_PlayerStartUpRight
	waitmovement 0
	applymovement LOCALID_DEVONEMPLOYEE, RustboroNew_Movement_EmployeeStartUpRight
	waitmovement 0
	delay 4
	goto RustboroNew_EventScript_DevonEncounter
	release
	end

RustboroNew_Movement_PlayerStartUpRight:
	face_right
	step_end

RustboroNew_Movement_EmployeeStartUpRight:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

RustboroNew_EventScript_DevonEncounter::
	lock
	setvar VAR_RUST_GYM_STATE, 15
	msgbox RustboroNew_Text_DevonNeedsYou, MSGBOX_DEFAULT
	closemessage
	warp MAP_DEVON_CORP, 12, 33
	waitstate
	release
	end

RustboroNew_Text_DevonNeedsYou:
	.string "Greetings!\n"
	.string "If I have the right information,\l"
	.string "your name is {PLAYER}.\p"
	.string "You have been summoned\n"
	.string "to the President of\l"
	.string "Devon Corp's office.\l"
	.string "I will lead you there.\l"
	.string "This is an urgent matter.$"
