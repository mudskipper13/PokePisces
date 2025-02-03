OzoneTabithaRoom_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, OzoneTabithaRoom_OnFrame
	.byte 0

OzoneTabithaRoom_OnFrame:
	map_script_2 VAR_TEMP_4, 0, OzoneTabithaRoom_EventScript_FightTabitha
	.2byte 0

OzoneTabithaRoom_EventScript_FightTabitha::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, OzoneTabithaRoom_Movement_WalkToBattle
	waitmovement 0
	delay 8
	setvar VAR_TEMP_4, 1
	speakername OzoneTabithaRoom_Text_NameTabitha
	trainerbattle_single TRAINER_P_TABITHA_3, OzoneTabithaRoom_Text_TabithaIntro, OzoneTabithaRoom_Text_TabithaDefeated, OzoneTabithaRoom_EventScript_TabithaBeaten
	goto OzoneTabithaRoom_EventScript_TabithaBeaten
	release
	end

OzoneTabithaRoom_Movement_WalkToBattle:
	walk_up
	walk_up
	walk_left
	walk_up
	face_right
	step_end

OzoneTabithaRoom_EventScript_TabithaBeaten::
	lock
	speakername OzoneTabithaRoom_Text_NameTabitha
	msgbox OzoneTabithaRoom_Text_TabithaPost, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_FINAL_OZONE_BEAT_TABITHA
	warp MAP_OZONE_ELITE_FOUR_HUB, 19, 6
	waitstate
	release
	end

OzoneTabithaRoom_Text_NameTabitha:
	.string "Tabitha$"

OzoneTabithaRoom_Text_TabithaIntro:
	.string "intro$"

OzoneTabithaRoom_Text_TabithaDefeated:
	.string "defeat$"

OzoneTabithaRoom_Text_TabithaPost:
	.string "post$"
