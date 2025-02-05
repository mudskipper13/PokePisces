.set LOCALID_RAY, 1

OzoneFloor2_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, OzoneFloor2_OnLoad
	.byte 0

OzoneFloor2_OnLoad:
	call_if_gt VAR_RAY_STATE, 6, OzoneFloor2_EventScript_RemoveRay
	end

OzoneFloor2_EventScript_RemoveRay::
	removeobject LOCALID_RAY
	setflag FLAG_TEMP_13
	return

OzoneFloor2_EventScript_RayEncounter1::
	lock
	applymovement LOCALID_RAY, OzoneFloor2_Movement_RayEncounter1
	waitmovement 0
	goto OzoneFloor2_EventScript_RayBattleStart
	release
	end

OzoneFloor2_Movement_RayEncounter1:
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

OzoneFloor2_EventScript_RayEncounter2::
	lock
	applymovement LOCALID_RAY, OzoneFloor2_Movement_RayEncounter2
	waitmovement 0
	goto OzoneFloor2_EventScript_RayBattleStart
	release
	end

OzoneFloor2_Movement_RayEncounter2:
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

OzoneFloor2_EventScript_RayEncounter3::
	lock
	applymovement LOCALID_RAY, OzoneFloor2_Movement_RayEncounter3
	waitmovement 0
	goto OzoneFloor2_EventScript_RayBattleStart
	release
	end

OzoneFloor2_Movement_RayEncounter3:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

OzoneFloor2_EventScript_RayEncounter4::
	lock
	applymovement LOCALID_RAY, OzoneFloor2_Movement_RayEncounter4
	waitmovement 0
	goto OzoneFloor2_EventScript_RayBattleStart
	release
	end

OzoneFloor2_Movement_RayEncounter4:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

OzoneFloor2_EventScript_RayBattleStart::
	speakername OzoneFloor2_Text_NameRay
	trainerbattle_single TRAINER_P_RAY_7, OzoneFloor2_Text_RayIntro, OzoneFloor2_Text_RayDefeat, OzoneFloor2_EventScript_RayLeaves
	speakername NULL
	release
	end

OzoneFloor2_EventScript_RayLeaves::
	speakername OzoneFloor2_Text_NameRay
	msgbox OzoneFloor2_Text_RayLeaves, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_RAY, OzoneFloor2_Movement_RayLeaves
	waitmovement 0
	removeobject LOCALID_RAY
	speakername NULL
	setflag FLAG_TEMP_13
	setvar VAR_RAY_STATE, 7
	release
	end

OzoneFloor2_Movement_RayLeaves:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

OzoneFloor2_Text_NameRay:
	.string "Ray$"

OzoneFloor2_Text_RayIntro:
	.string "intro$"

OzoneFloor2_Text_RayDefeat:
	.string "defaet$"

OzoneFloor2_Text_RayLeaves:
	.string "leavin now$"
