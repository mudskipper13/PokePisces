OzoneCourtneyRoom_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, OzoneCourtneyRoom_OnFrame
	.byte 0

OzoneCourtneyRoom_OnFrame:
	map_script_2 VAR_TEMP_4, 0, OzoneCourtneyRoom_EventScript_FightCourtney
	.2byte 0

OzoneCourtneyRoom_EventScript_FightCourtney::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, OzoneCourtneyRoom_Movement_WalkToBattle
	waitmovement 0
	delay 8
	setvar VAR_TEMP_4, 1
	speakername OzoneCourtneyRoom_Text_NameCourtney
	msgbox OzoneCourtneyRoom_Text_CourtneyIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_P_COURTNEY_2, OzoneCourtneyRoom_Text_CourtneyDefeated
	goto OzoneCourtneyRoom_EventScript_CourtneyBeaten
	release
	end

OzoneCourtneyRoom_Movement_WalkToBattle:
	walk_up
	walk_up
	walk_left
	walk_up
	face_right
	step_end

OzoneCourtneyRoom_EventScript_CourtneyBeaten::
	lock
	speakername OzoneCourtneyRoom_Text_NameCourtney
	msgbox OzoneCourtneyRoom_Text_CourtneyPost, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_FINAL_OZONE_BEAT_COURTNEY
	warp MAP_OZONE_ELITE_FOUR_HUB, 2, 6
	waitstate
	release
	end

OzoneCourtneyRoom_Text_NameCourtney:
	.string "Courtney$"

OzoneCourtneyRoom_Text_CourtneyIntro:
	.string "intro$"

OzoneCourtneyRoom_Text_CourtneyDefeated:
	.string "defeat$"

OzoneCourtneyRoom_Text_CourtneyPost:
	.string "post$"
