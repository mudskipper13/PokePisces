.set LOCALID_WALLY, 1

VerdanturfNew_MapScripts::
	.byte 0

VerdanturfNew_EventScript_InitWally1Trigger1::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, VerdanturfNew_Movement_Surprise
	applymovement LOCALID_WALLY, VerdanturfNew_Movement_WalkUpToPlayer1
	waitmovement 0
	goto VerdanturfNew_EventScript_FirstWallyEncounter
	release
	end

VerdanturfNew_Movement_WalkUpToPlayer1:
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

VerdanturfNew_EventScript_InitWally1Trigger2::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, VerdanturfNew_Movement_Surprise
	applymovement LOCALID_WALLY, VerdanturfNew_Movement_WalkUpToPlayer2
	waitmovement 0
	goto VerdanturfNew_EventScript_FirstWallyEncounter
	release
	end

VerdanturfNew_Movement_WalkUpToPlayer2:
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

VerdanturfNew_EventScript_InitWally1Trigger3::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, VerdanturfNew_Movement_Surprise
	applymovement LOCALID_WALLY, VerdanturfNew_Movement_WalkUpToPlayer3
	waitmovement 0
	goto VerdanturfNew_EventScript_FirstWallyEncounter
	release
	end

VerdanturfNew_Movement_WalkUpToPlayer3:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

VerdanturfNew_EventScript_InitWally1Trigger4::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, VerdanturfNew_Movement_Surprise
	applymovement LOCALID_WALLY, VerdanturfNew_Movement_WalkUpToPlayer4
	waitmovement 0
	goto VerdanturfNew_EventScript_FirstWallyEncounter
	release
	end

VerdanturfNew_Movement_WalkUpToPlayer4:
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

VerdanturfNew_EventScript_InitWally1Trigger5::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, VerdanturfNew_Movement_Surprise
	applymovement LOCALID_WALLY, VerdanturfNew_Movement_WalkUpToPlayer5
	waitmovement 0
	goto VerdanturfNew_EventScript_FirstWallyEncounter
	release
	end

VerdanturfNew_Movement_WalkUpToPlayer5:
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	face_down
	step_end

VerdanturfNew_EventScript_FirstWallyEncounter::
	release
	end

VerdanturfNew_Movement_Surprise:
	delay_4
	emote_exclamation_mark
	step_end
