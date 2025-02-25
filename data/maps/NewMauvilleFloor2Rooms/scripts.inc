.set LOCALID_P_MAN, 1

NewMauvilleFloor2Rooms_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, NewMauvilleFloor2Rooms_OnLoad
	.byte 0

NewMauvilleFloor2Rooms_OnLoad:
	call_if_gt VAR_OLD_GUYS_STATE, 1, NewMauvilleFloor2Rooms_EventScript_RemovePowerlessMan
	end

NewMauvilleFloor2Rooms_EventScript_RemovePowerlessMan::
	removeobject LOCALID_P_MAN
	setflag FLAG_TEMP_11
	return

NewMauvilleFloor2Rooms_EventScript_KizunaMission::
	lock
	faceplayer
	speakername NewMauvilleFloor2Rooms_Text_NameKizuna
	msgbox NewMauvilleFloor2Rooms_Text_HeresOurMission, MSGBOX_DEFAULT
	speakername NULL
	closemessage
	setvar VAR_OLD_GUYS_STATE, 2
	goto_if_eq VAR_FACING, DIR_WEST, NewMauvilleFloor2Rooms_EventScript_WalkAroundPlayer
	applymovement LOCALID_P_MAN, NewMauvilleFloor2Rooms_Movement_LeaveRoom
	waitmovement 0
	playse SE_EXIT
	removeobject LOCALID_P_MAN
	setflag FLAG_TEMP_11
	release
	end

NewMauvilleFloor2Rooms_EventScript_WalkAroundPlayer::
	applymovement LOCALID_P_MAN, NewMauvilleFloor2Rooms_Movement_LeaveRoom2
	waitmovement 0
	playse SE_EXIT
	removeobject LOCALID_P_MAN
	setflag FLAG_TEMP_11
	release
	end

NewMauvilleFloor2Rooms_Movement_LeaveRoom:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	step_end

NewMauvilleFloor2Rooms_Movement_LeaveRoom2:
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	face_down
	step_end

NewMauvilleFloor2Rooms_Text_NameKizuna:
	.string "Kizuna$"

NewMauvilleFloor2Rooms_Text_HeresOurMission:
	.string "Oh. You're really serious?\n"
	.string "Glad you trust me, but...\l"
	.string "gah, you know what, screw it,\l"
	.string "let's throw caution to the wind\l"
	.string "and try and put this plan\l"
	.string "into action! I'm sick of this\l"
	.string "boring job!\p"
	.string "So, yeah, the appointments?\n"
	.string "Paying for the badge? Forget that.\l"
	.string "I have a lead on someone who\l"
	.string "can get us the badge personally.\p"
	.string "The former owner of Greater\n"
	.string "Mauville Holdings. I've never\l"
	.string "heard his name, only his title.\l"
	.string "'The Storyteller'.\p"
	.string "The Storyteller is one of a rumored\n"
	.string "connected network of older men\l"
	.string "that have a lot of pull in this\l"
	.string "neck of the region. One of his\l"
	.string "good friends was someone named\l"
	.string "Giddy, also known as the\l"
	.string "Trick Master. He used to operate\l"
	.string "this big funhouse nearby Mauville,\l"
	.string "but he's since relocated.\p"
	.string "Bit of a problem. If we're going\n"
	.string "to find Giddy, I don't exactly know\l"
	.string "where the Trick House he lives in\l"
	.string "got moved to.\p"
	.string "So, we'll have to ask around.\n"
	.string "Let's try the food court, there's\l"
	.string "a pretty big collection\l"
	.string "of Mauville residents there.$"
