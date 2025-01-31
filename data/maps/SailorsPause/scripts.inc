.set LOCALID_RAY, 4

SailorsPause_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, SailorsPause_OnLoad
	.byte 0

SailorsPause_OnLoad:
	call_if_gt VAR_RAY_STATE, 4, SailorsPause_EventScript_RemoveRay
	end

SailorsPause_EventScript_RemoveRay::
	removeobject LOCALID_RAY
	setflag FLAG_TEMP_13
	return

SailorsPause_EventScript_RayEncounter::
	lock
	applymovement LOCALID_RAY, SailorsPause_Movement_RayEncounter
	waitmovement 0
	speakername SailorsPause_Text_NameRay
	trainerbattle_single TRAINER_P_RAY_5, SailorsPause_Text_RayIntro, SailorsPause_Text_RayDefeat, SailorsPause_EventScript_RayLeaves
	speakername NULL
	release
	end

SailorsPause_Movement_RayEncounter:
	emote_exclamation_mark
	delay_16
	jump_in_place_up
	jump_in_place_up
	jump_in_place_up
	step_end

SailorsPause_EventScript_RayLeaves::
	speakername SailorsPause_Text_NameRay
	msgbox SailorsPause_Text_RayLeaves, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_RAY, SailorsPause_Movement_RayLeaves
	waitmovement 0
	removeobject LOCALID_RAY
	speakername NULL
	setflag FLAG_TEMP_13
	setvar VAR_RAY_STATE, 5
	release
	end

SailorsPause_Movement_RayLeaves:
	walk_fast_right
	jump_2_right
	jump_2_down
	walk_fast_right
	jump_2_right
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_down
	jump_2_right
	step_end

SailorsPause_EventScript_Valerie::
    trainerbattle_single TRAINER_P_VALERIE, SailorsPause_Text_ValerieIntro, SailorsPause_Text_ValerieDefeated
    msgbox SailorsPause_Text_ValeriePostBattle, MSGBOX_AUTOCLOSE
    end

SailorsPause_EventScript_Queequeg::
    trainerbattle_single TRAINER_P_QUEEQUEG, SailorsPause_Text_QueequegIntro, SailorsPause_Text_QueequegDefeated
    msgbox SailorsPause_Text_QueequegPostBattle, MSGBOX_AUTOCLOSE
    end

SailorsPause_EventScript_Jess::
    trainerbattle_single TRAINER_P_JESS, SailorsPause_Text_JessIntro, SailorsPause_Text_JessDefeated
    msgbox SailorsPause_Text_JessPostBattle, MSGBOX_AUTOCLOSE
    end

SailorsPause_Text_ValerieIntro:
	.string "intro$"

SailorsPause_Text_ValerieDefeated:
	.string "defeat$"

SailorsPause_Text_ValeriePostBattle:
	.string "post$"

SailorsPause_Text_QueequegIntro:
	.string "intro$"

SailorsPause_Text_QueequegDefeated:
	.string "defeat$"

SailorsPause_Text_QueequegPostBattle:
	.string "post$"

SailorsPause_Text_JessIntro:
	.string "intro$"

SailorsPause_Text_JessDefeated:
	.string "defeat$"

SailorsPause_Text_JessPostBattle:
	.string "post$"

SailorsPause_Text_NameRay:
	.string "Ray$"

SailorsPause_Text_RayIntro:
	.string "intro$"

SailorsPause_Text_RayDefeat:
	.string "defeat$"

SailorsPause_Text_RayLeaves:
	.string "byebye$"
