.set LOCALID_STEVEN, 4

SeasideCasinoBackrooms_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, SeasideCasinoBackrooms_OnLoad
	.byte 0

SeasideCasinoBackrooms_OnLoad:
	call SeasideCasinoBackrooms_EventScript_RemoveSteven
	end

SeasideCasinoBackrooms_EventScript_RemoveSteven::
	removeobject LOCALID_STEVEN
	setflag FLAG_TEMP_11
	return

SeasideCasinoBackrooms_EventScript_StevenMeetingNorth::
	lock
	applymovement LOCALID_STEVEN, SeasideCasinoBackrooms_Movement_StevenMeetingNorth
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	speakername SeasideCasinoBackrooms_Text_NameSteven
	msgbox SeasideCasinoBackrooms_Text_PointOfNoReturn, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_STEVEN, SeasideCasinoBackrooms_Movement_StevenLeavesNorth
	waitmovement 0
	setvar VAR_WALLY_QUEST_STATE, 6
	removeobject LOCALID_STEVEN
	setflag FLAG_TEMP_11
	release
	end

SeasideCasinoBackrooms_Movement_StevenMeetingNorth:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	face_right
	step_end

SeasideCasinoBackrooms_Movement_StevenLeavesNorth:
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	jump_2_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

SeasideCasinoBackrooms_EventScript_StevenMeetingSouth::
	lock
	applymovement LOCALID_STEVEN, SeasideCasinoBackrooms_Movement_StevenMeetingSouth
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	speakername SeasideCasinoBackrooms_Text_NameSteven
	msgbox SeasideCasinoBackrooms_Text_PointOfNoReturn, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_STEVEN, SeasideCasinoBackrooms_Movement_StevenLeavesSouth
	waitmovement 0
	setvar VAR_WALLY_QUEST_STATE, 6
	removeobject LOCALID_STEVEN
	setflag FLAG_TEMP_11
	release
	end

SeasideCasinoBackrooms_Movement_StevenMeetingSouth:
	walk_up
	walk_up
	walk_up
	walk_up
	face_right
	step_end

SeasideCasinoBackrooms_Movement_StevenLeavesSouth:
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	jump_2_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

SeasideCasinoBackrooms_EventScript_Lincoln::
    trainerbattle_single TRAINER_P_LINCOLN, SeasideCasinoBackrooms_Text_LincolnIntro, SeasideCasinoBackrooms_Text_LincolnDefeated
    msgbox SeasideCasinoBackrooms_Text_LincolnPostBattle, MSGBOX_AUTOCLOSE
    end

SeasideCasinoBackrooms_EventScript_Penn::
    trainerbattle_single TRAINER_P_PENN, SeasideCasinoBackrooms_Text_PennIntro, SeasideCasinoBackrooms_Text_PennDefeated
    msgbox SeasideCasinoBackrooms_Text_PennPostBattle, MSGBOX_AUTOCLOSE
    end

SeasideCasinoBackrooms_EventScript_Ari::
    trainerbattle_single TRAINER_P_ARI, SeasideCasinoBackrooms_Text_AriIntro, SeasideCasinoBackrooms_Text_AriDefeated
    msgbox SeasideCasinoBackrooms_Text_AriPostBattle, MSGBOX_AUTOCLOSE
    end

SeasideCasinoBackrooms_Text_LincolnIntro:
	.string "intro$"

SeasideCasinoBackrooms_Text_LincolnDefeated:
	.string "defeat$"

SeasideCasinoBackrooms_Text_LincolnPostBattle:
	.string "post$"

SeasideCasinoBackrooms_Text_PennIntro:
	.string "intro$"

SeasideCasinoBackrooms_Text_PennDefeated:
	.string "defeat$"

SeasideCasinoBackrooms_Text_PennPostBattle:
	.string "post$"

SeasideCasinoBackrooms_Text_AriIntro:
	.string "intro$"

SeasideCasinoBackrooms_Text_AriDefeated:
	.string "defeat$"

SeasideCasinoBackrooms_Text_AriPostBattle:
	.string "post$"

SeasideCasinoBackrooms_Text_NameSteven:
	.string "Steven$"

SeasideCasinoBackrooms_Text_PointOfNoReturn:
	.string "$"
