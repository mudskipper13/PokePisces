.set LOCALID_RAY, 5

OzoneInstitute_MapScripts::
	.byte 0

OzoneInstitute_EventScript_RayEncounterWest1::
	lock
	applymovement LOCALID_RAY, OzoneInstitute_Movement_RayEncounterWest1
	waitmovement 0
	goto OzoneInstitute_EventScript_RayBattleStart
	release
	end

OzoneInstitute_Movement_RayEncounterWest1:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

OzoneInstitute_EventScript_RayEncounterWest2::
	lock
	applymovement LOCALID_RAY, OzoneInstitute_Movement_RayEncounterWest2
	waitmovement 0
	goto OzoneInstitute_EventScript_RayBattleStart
	release
	end

OzoneInstitute_Movement_RayEncounterWest2:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

OzoneInstitute_EventScript_RayEncounterEast1::
	lock
	applymovement LOCALID_RAY, OzoneInstitute_Movement_RayEncounterEast1
	waitmovement 0
	goto OzoneInstitute_EventScript_RayBattleStart
	release
	end

OzoneInstitute_Movement_RayEncounterEast1:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

OzoneInstitute_EventScript_RayEncounterEast2::
	lock
	applymovement LOCALID_RAY, OzoneInstitute_Movement_RayEncounterEast2
	waitmovement 0
	goto OzoneInstitute_EventScript_RayBattleStart
	release
	end

OzoneInstitute_Movement_RayEncounterEast2:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

OzoneInstitute_EventScript_RayEncounterEast3::
	lock
	applymovement LOCALID_RAY, OzoneInstitute_Movement_RayEncounterEast3
	waitmovement 0
	goto OzoneInstitute_EventScript_RayBattleStart
	release
	end

OzoneInstitute_Movement_RayEncounterEast3:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

OzoneInstitute_EventScript_RayEncounterEast4::
	lock
	applymovement LOCALID_RAY, OzoneInstitute_Movement_RayEncounterEast4
	waitmovement 0
	goto OzoneInstitute_EventScript_RayBattleStart
	release
	end

OzoneInstitute_Movement_RayEncounterEast4:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

OzoneInstitute_EventScript_RayBattleStart::
	speakername OzoneInstitute_Text_NameRay
	trainerbattle_single TRAINER_P_RAY_3, OzoneInstitute_Text_RayIntro, OzoneInstitute_Text_RayDefeat, OzoneInstitute_EventScript_RayLeaves
	speakername NULL
	release
	end

OzoneInstitute_EventScript_RayLeaves::
	speakername OzoneInstitute_Text_NameRay
	msgbox OzoneInstitute_Text_RayLeaves, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_RAY, OzoneInstitute_Movement_RayLeaves
	waitmovement 0
	removeobject LOCALID_RAY
	speakername NULL
	setflag FLAG_BEAT_RAY_3
	setvar VAR_RAY_STATE, 3
	setflag FLAG_VISITED_OZONE_INSTITUTE
	setflag FLAG_HIDE_MAXIE_OZONE
	release
	end

OzoneInstitute_Movement_RayLeaves:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

OzoneInstitute_EventScript_Gale::
    trainerbattle_single TRAINER_P_GALE, OzoneInstitute_Text_GaleIntro, OzoneInstitute_Text_GaleDefeated
    msgbox OzoneInstitute_Text_GalePostBattle, MSGBOX_AUTOCLOSE
    end

OzoneInstitute_EventScript_Smokey::
    trainerbattle_single TRAINER_P_SMOKEY, OzoneInstitute_Text_SmokeyIntro, OzoneInstitute_Text_SmokeyDefeated
    msgbox OzoneInstitute_Text_SmokeyPostBattle, MSGBOX_AUTOCLOSE
    end

OzoneInstitute_EventScript_DessAndEmber::
    trainerbattle_double TRAINER_P_DESS_AND_EMBER, OzoneInstitute_Text_DessAndEmberIntro, OzoneInstitute_Text_DessAndEmberDefeated, OzoneInstitute_Text_DessAndEmberNeedTwoMons
    msgbox OzoneInstitute_Text_DessAndEmberPostBattle, MSGBOX_AUTOCLOSE
    end

OzoneInstitute_Text_GaleIntro:
	.string "intro$"

OzoneInstitute_Text_GaleDefeated:
	.string "defeat$"

OzoneInstitute_Text_GalePostBattle:
	.string "post$"

OzoneInstitute_Text_SmokeyIntro:
	.string "intro$"

OzoneInstitute_Text_SmokeyDefeated:
	.string "defeat$"

OzoneInstitute_Text_SmokeyPostBattle:
	.string "post$"

OzoneInstitute_Text_DessAndEmberIntro:
	.string "intro$"

OzoneInstitute_Text_DessAndEmberDefeated:
	.string "defeat$"

OzoneInstitute_Text_DessAndEmberPostBattle:
	.string "post$"

OzoneInstitute_Text_DessAndEmberNeedTwoMons:
	.string "need 2 dood$"

OzoneInstitute_Text_NameRay:
	.string "Ray$"

OzoneInstitute_Text_RayIntro:
	.string "u suck$"

OzoneInstitute_Text_RayDefeat:
	.string "i suck$"

OzoneInstitute_Text_RayLeaves:
	.string "we suck$"
