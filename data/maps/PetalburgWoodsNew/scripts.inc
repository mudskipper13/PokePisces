.set LOCALID_BREAD, 1

PetalburgWoodsNew_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, PetalburgWoodsNew_OnLoad
	.byte 0

PetalburgWoodsNew_OnLoad:
	call PetalburgWoodsNew_EventScript_RemoveBreadwinner
	end

PetalburgWoodsNew_EventScript_RemoveBreadwinner::
	removeobject LOCALID_BREAD
	setflag FLAG_TEMP_13
	return

PetalburgWoodsNew_EventScript_BreadwinnerEncounter1::
	lock
	clearflag FLAG_TEMP_13
	addobject LOCALID_BREAD
	delay 4
	applymovement LOCALID_BREAD, PetalburgWoodsNew_Movement_BreadEnc1
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	delay 4
	playse SE_PIN
	applymovement LOCALID_BREAD, PetalburgWoodsNew_Movement_BreadSurprised
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, PetalburgWoodsNew_Movement_PlayerChaseBread1
	applymovement LOCALID_BREAD, PetalburgWoodsNew_Movement_BreadChased1
	waitmovement 0
	goto PetalburgWoodsNew_EventScript_BreadwinnerBattle
	release
	end

PetalburgWoodsNew_Movement_BreadEnc1:
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_down
	walk_fast_left
	walk_fast_down
	walk_fast_left
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_down
	walk_fast_left
	step_end

PetalburgWoodsNew_Movement_BreadSurprised:
	emote_exclamation_mark
	step_end

PetalburgWoodsNew_Movement_PlayerChaseBread1:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_down
	face_right
	step_end

PetalburgWoodsNew_Movement_BreadChased1:
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_right
	walk_fast_right
	step_end

PetalburgWoodsNew_EventScript_BreadwinnerEncounter2::
	lock
	clearflag FLAG_TEMP_13
	addobject LOCALID_BREAD
	delay 4
	applymovement LOCALID_BREAD, PetalburgWoodsNew_Movement_BreadEnc2
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	delay 4
	playse SE_PIN
	applymovement LOCALID_BREAD, PetalburgWoodsNew_Movement_BreadSurprised
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, PetalburgWoodsNew_Movement_PlayerChaseBread2
	applymovement LOCALID_BREAD, PetalburgWoodsNew_Movement_BreadChased2
	waitmovement 0
	goto PetalburgWoodsNew_EventScript_BreadwinnerBattle
	release
	end

PetalburgWoodsNew_Movement_BreadEnc2:
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_down
	walk_fast_left
	walk_fast_down
	walk_fast_left
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_down
	walk_fast_down
	walk_fast_left
	step_end

PetalburgWoodsNew_Movement_PlayerChaseBread2:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_down
	face_right
	step_end

PetalburgWoodsNew_Movement_BreadChased2:
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_right
	walk_fast_right
	step_end

PetalburgWoodsNew_EventScript_BreadwinnerBattle::
	delay 8
	applymovement LOCALID_BREAD, PetalburgWoodsNew_Movement_BreadCornered
	waitmovement 0
	speakername PetalburgWoodsNew_Text_NamePandou
	trainerbattle_single TRAINER_P_PANDOU_5, PetalburgWoodsNew_Text_BreadwinnerIntro, PetalburgWoodsNew_Text_BreadwinnerDefeat, PetalburgWoodsNew_EventScript_BreadRun
	release
	end

PetalburgWoodsNew_EventScript_BreadRun::
	setvar VAR_BREADWINNER_STATE, 5
	speakername PetalburgWoodsNew_Text_NamePandou
	msgbox PetalburgWoodsNew_Text_BreadwinnerRunAway, MSGBOX_DEFAULT
	closemessage
	playse SE_FLEE
	applymovement LOCALID_BREAD, PetalburgWoodsNew_Movement_BreadEscape
	waitmovement 0
	removeobject LOCALID_BREAD
	setflag FLAG_TEMP_13
	release
	end

PetalburgWoodsNew_Movement_BreadCornered:
	face_right
	delay_16
	face_up
	delay_16
	face_down
	delay_16
	face_left
	delay_16
	step_end

PetalburgWoodsNew_Movement_BreadEscape:
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

PetalburgWoodsNew_EventScript_BirdhouseShishima::
	lock
	goto_if_set FLAG_DEFEATED_SHISHIMA, PetalburgWoodsNew_EventScript_BirdPost
	msgbox PetalburgWoodsNew_Text_DoYouLookInside, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, PetalburgWoodsNew_EventScript_ShishimaBattle
	msgbox PetalburgWoodsNew_Text_ProbablyShouldnt, MSGBOX_AUTOCLOSE
	release
	end

PetalburgWoodsNew_EventScript_ShishimaBattle::
	setwildbattle SPECIES_SHISHIMA, 66
	settotemboost B_POSITION_OPPONENT_LEFT, 1, 5, 0, 1, 5, 1, 1
	playmoncry SPECIES_SHISHIMA, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	msgbox PetalburgWoodsNew_Text_PunishingPresence, MSGBOX_DEFAULT
	setflag FLAG_WILD_NO_CATCHING_FLAG
	setflag FLAG_WILD_NO_RUNNING_FLAG
	setflag FLAG_SMART_WILD_AI_FLAG
	delay 4
	dowildbattle
	delay 8
	clearflag FLAG_WILD_NO_CATCHING_FLAG
	clearflag FLAG_WILD_NO_RUNNING_FLAG
	clearflag FLAG_SMART_WILD_AI_FLAG
	goto PetalburgWoodsNew_EventScript_ShishimaDefeat
	release
	end

PetalburgWoodsNew_EventScript_ShishimaDefeat::
	msgbox PetalburgWoodsNew_Text_ShishimaBecameEgg, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_SHISHIMA
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_EGG
	giveegg SPECIES_SHISHIMA
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, PetalburgWoodsNew_EventScript_ReceiveEggParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, PetalburgWoodsNew_EventScript_ReceiveEggPC
	goto Common_EventScript_NoMoreRoomForPokemon
	release
	end

PetalburgWoodsNew_EventScript_BirdhouseOlFlookie::
	lock
	goto_if_set FLAG_DEFEATED_OLFLOOKIE, PetalburgWoodsNew_EventScript_BirdPost
	msgbox PetalburgWoodsNew_Text_DoYouLookInside, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, PetalburgWoodsNew_EventScript_OlFlookieBattle
	msgbox PetalburgWoodsNew_Text_ProbablyShouldnt, MSGBOX_AUTOCLOSE
	release
	end

PetalburgWoodsNew_EventScript_OlFlookieBattle::
	setwildbattle SPECIES_OLFLOOKIE, 66
	settotemboost B_POSITION_OPPONENT_LEFT, 1, 5, 0, 1, 5, 1, 1
	playmoncry SPECIES_OLFLOOKIE, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	msgbox PetalburgWoodsNew_Text_BigPresence, MSGBOX_DEFAULT
	setflag FLAG_WILD_NO_CATCHING_FLAG
	setflag FLAG_WILD_NO_RUNNING_FLAG
	setflag FLAG_SMART_WILD_AI_FLAG
	delay 4
	dowildbattle
	delay 8
	clearflag FLAG_WILD_NO_CATCHING_FLAG
	clearflag FLAG_WILD_NO_RUNNING_FLAG
	clearflag FLAG_SMART_WILD_AI_FLAG
	goto PetalburgWoodsNew_EventScript_OlFlookieDefeat
	release
	end

PetalburgWoodsNew_EventScript_OlFlookieDefeat::
	msgbox PetalburgWoodsNew_Text_OlFlookieBecameEgg, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_OLFLOOKIE
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_EGG
	giveegg SPECIES_OLFLOOKIE
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, PetalburgWoodsNew_EventScript_ReceiveEggParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, PetalburgWoodsNew_EventScript_ReceiveEggPC
	goto Common_EventScript_NoMoreRoomForPokemon
	release
	end

PetalburgWoodsNew_EventScript_BirdhouseJustricha::
	lock
	goto_if_set FLAG_DEFEATED_JUSTRICHA, PetalburgWoodsNew_EventScript_BirdPost
	msgbox PetalburgWoodsNew_Text_DoYouLookInside, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, PetalburgWoodsNew_EventScript_JustrichaBattle
	msgbox PetalburgWoodsNew_Text_ProbablyShouldnt, MSGBOX_AUTOCLOSE
	release
	end

PetalburgWoodsNew_EventScript_JustrichaBattle::
	setwildbattle SPECIES_JUSTRICHA, 66
	settotemboost B_POSITION_OPPONENT_LEFT, 1, 5, 0, 1, 5, 1, 1
	playmoncry SPECIES_JUSTRICHA, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	msgbox PetalburgWoodsNew_Text_JudgingPresence, MSGBOX_DEFAULT
	setflag FLAG_WILD_NO_CATCHING_FLAG
	setflag FLAG_WILD_NO_RUNNING_FLAG
	setflag FLAG_SMART_WILD_AI_FLAG
	delay 4
	dowildbattle
	delay 8
	clearflag FLAG_WILD_NO_CATCHING_FLAG
	clearflag FLAG_WILD_NO_RUNNING_FLAG
	clearflag FLAG_SMART_WILD_AI_FLAG
	goto PetalburgWoodsNew_EventScript_JustrichaDefeat
	release
	end

PetalburgWoodsNew_EventScript_JustrichaDefeat::
	msgbox PetalburgWoodsNew_Text_JustrichaBecameEgg, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_JUSTRICHA
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_EGG
	giveegg SPECIES_JUSTRICHA
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, PetalburgWoodsNew_EventScript_ReceiveEggParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, PetalburgWoodsNew_EventScript_ReceiveEggPC
	goto Common_EventScript_NoMoreRoomForPokemon
	release
	end

PetalburgWoodsNew_EventScript_BirdPost::
	msgbox PetalburgWoodsNew_Text_BirdIsGone, MSGBOX_AUTOCLOSE
	release
	end

PetalburgWoodsNew_EventScript_ReceiveEggParty::
	call PetalburgWoodsNew_EventScript_ReceivedEggFanfare
	release
	end

PetalburgWoodsNew_EventScript_ReceiveEggPC::
	call PetalburgWoodsNew_EventScript_ReceivedEggFanfare
	call Common_EventScript_TransferredToPC
	release
	end

PetalburgWoodsNew_EventScript_ReceivedEggFanfare::
	playfanfare MUS_OBTAIN_ITEM
	message PetalburgWoodsNew_Text_PlayerReceivedEgg
	waitmessage
	waitfanfare
	return

PetalburgWoodsNew_EventScript_Tutu::
    trainerbattle_single TRAINER_P_TUTU, PetalburgWoodsNew_Text_TutuIntro, PetalburgWoodsNew_Text_TutuDefeated
    msgbox PetalburgWoodsNew_Text_TutuPostBattle, MSGBOX_AUTOCLOSE
    end

PetalburgWoodsNew_EventScript_Duck::
    trainerbattle_single TRAINER_P_DUCK, PetalburgWoodsNew_Text_DuckIntro, PetalburgWoodsNew_Text_DuckDefeated
    msgbox PetalburgWoodsNew_Text_DuckPostBattle, MSGBOX_AUTOCLOSE
    end

PetalburgWoodsNew_EventScript_Violet::
    trainerbattle_single TRAINER_P_VIOLET, PetalburgWoodsNew_Text_VioletIntro, PetalburgWoodsNew_Text_VioletDefeated
    msgbox PetalburgWoodsNew_Text_VioletPostBattle, MSGBOX_AUTOCLOSE
    end

PetalburgWoodsNew_EventScript_Elizabeth::
    trainerbattle_single TRAINER_P_ELIZABETH, PetalburgWoodsNew_Text_ElizabethIntro, PetalburgWoodsNew_Text_ElizabethDefeated
    msgbox PetalburgWoodsNew_Text_ElizabethPostBattle, MSGBOX_AUTOCLOSE
    end

PetalburgWoodsNew_EventScript_Artie::
    trainerbattle_single TRAINER_P_ARTIE, PetalburgWoodsNew_Text_ArtieIntro, PetalburgWoodsNew_Text_ArtieDefeated
    msgbox PetalburgWoodsNew_Text_ArtiePostBattle, MSGBOX_AUTOCLOSE
    end

PetalburgWoodsNew_EventScript_Gyomaru::
    trainerbattle_single TRAINER_P_GYOMARU, PetalburgWoodsNew_Text_GyomaruIntro, PetalburgWoodsNew_Text_GyomaruDefeated
    msgbox PetalburgWoodsNew_Text_GyomaruPostBattle, MSGBOX_AUTOCLOSE
    end

PetalburgWoodsNew_EventScript_Suzume::
    trainerbattle_single TRAINER_P_SUZUME, PetalburgWoodsNew_Text_SuzumeIntro, PetalburgWoodsNew_Text_SuzumeDefeated
    msgbox PetalburgWoodsNew_Text_SuzumePostBattle, MSGBOX_AUTOCLOSE
    end

PetalburgWoodsNew_EventScript_Mio::
    trainerbattle_single TRAINER_P_MIO, PetalburgWoodsNew_Text_MioIntro, PetalburgWoodsNew_Text_MioDefeated
    msgbox PetalburgWoodsNew_Text_MioPostBattle, MSGBOX_AUTOCLOSE
    end

PetalburgWoodsNew_EventScript_Lemmy::
    trainerbattle_single TRAINER_P_LEMMY, PetalburgWoodsNew_Text_LemmyIntro, PetalburgWoodsNew_Text_LemmyDefeated
    msgbox PetalburgWoodsNew_Text_LemmyPostBattle, MSGBOX_AUTOCLOSE
    end

PetalburgWoodsNew_EventScript_Ichi::
    trainerbattle_single TRAINER_P_ICHI, PetalburgWoodsNew_Text_IchiIntro, PetalburgWoodsNew_Text_IchiDefeated
    msgbox PetalburgWoodsNew_Text_IchiPostBattle, MSGBOX_AUTOCLOSE
    end

PetalburgWoodsNew_EventScript_InuAndPersia::
    trainerbattle_double TRAINER_P_INU_AND_PERSIA, PetalburgWoodsNew_Text_InuAndPersiaIntro, PetalburgWoodsNew_Text_InuAndPersiaDefeated, PetalburgWoodsNew_Text_InuAndPersiaNeedTwoMons
    msgbox PetalburgWoodsNew_Text_InuAndPersiaPostBattle, MSGBOX_AUTOCLOSE
    end

PetalburgWoodsNew_Text_TutuIntro:
	.string "intro$"

PetalburgWoodsNew_Text_TutuDefeated:
	.string "defeat$"

PetalburgWoodsNew_Text_TutuPostBattle:
	.string "post$"

PetalburgWoodsNew_Text_DuckIntro:
	.string "intro$"

PetalburgWoodsNew_Text_DuckDefeated:
	.string "defeat$"

PetalburgWoodsNew_Text_DuckPostBattle:
	.string "post$"

PetalburgWoodsNew_Text_VioletIntro:
	.string "intro$"

PetalburgWoodsNew_Text_VioletDefeated:
	.string "defeat$"

PetalburgWoodsNew_Text_VioletPostBattle:
	.string "post$"

PetalburgWoodsNew_Text_ElizabethIntro:
	.string "intro$"

PetalburgWoodsNew_Text_ElizabethDefeated:
	.string "defeat$"

PetalburgWoodsNew_Text_ElizabethPostBattle:
	.string "post$"

PetalburgWoodsNew_Text_ArtieIntro:
	.string "intro$"

PetalburgWoodsNew_Text_ArtieDefeated:
	.string "defeat$"

PetalburgWoodsNew_Text_ArtiePostBattle:
	.string "post$"

PetalburgWoodsNew_Text_GyomaruIntro:
	.string "intro$"

PetalburgWoodsNew_Text_GyomaruDefeated:
	.string "defeat$"

PetalburgWoodsNew_Text_GyomaruPostBattle:
	.string "post$"

PetalburgWoodsNew_Text_SuzumeIntro:
	.string "intro$"

PetalburgWoodsNew_Text_SuzumeDefeated:
	.string "defeat$"

PetalburgWoodsNew_Text_SuzumePostBattle:
	.string "post$"

PetalburgWoodsNew_Text_MioIntro:
	.string "intro$"

PetalburgWoodsNew_Text_MioDefeated:
	.string "defeat$"

PetalburgWoodsNew_Text_MioPostBattle:
	.string "post$"

PetalburgWoodsNew_Text_LemmyIntro:
	.string "intro$"

PetalburgWoodsNew_Text_LemmyDefeated:
	.string "defeat$"

PetalburgWoodsNew_Text_LemmyPostBattle:
	.string "post$"

PetalburgWoodsNew_Text_IchiIntro:
	.string "intro$"

PetalburgWoodsNew_Text_IchiDefeated:
	.string "defeat$"

PetalburgWoodsNew_Text_IchiPostBattle:
	.string "post$"

PetalburgWoodsNew_Text_InuAndPersiaIntro:
	.string "intro$"

PetalburgWoodsNew_Text_InuAndPersiaDefeated:
	.string "defeat$"

PetalburgWoodsNew_Text_InuAndPersiaPostBattle:
	.string "post$"

PetalburgWoodsNew_Text_InuAndPersiaNeedTwoMons:
	.string "need 2 dood$"

PetalburgWoodsNew_Text_NamePandou:
	.string "Pandou$"

PetalburgWoodsNew_Text_BreadwinnerIntro:
	.string "$"

PetalburgWoodsNew_Text_BreadwinnerDefeat:
	.string "$"

PetalburgWoodsNew_Text_BreadwinnerRunAway:
	.string "$"

PetalburgWoodsNew_Text_DoYouLookInside:
	.string "$"

PetalburgWoodsNew_Text_ProbablyShouldnt:
	.string "$"

PetalburgWoodsNew_Text_PunishingPresence:
	.string "$"

PetalburgWoodsNew_Text_BigPresence:
	.string "$"

PetalburgWoodsNew_Text_JudgingPresence:
	.string "$"

PetalburgWoodsNew_Text_ShishimaBecameEgg:
	.string "$"

PetalburgWoodsNew_Text_OlFlookieBecameEgg:
	.string "$"

PetalburgWoodsNew_Text_JustrichaBecameEgg:
	.string "$"

PetalburgWoodsNew_Text_PlayerReceivedEgg:
	.string "$"

PetalburgWoodsNew_Text_BirdIsGone:
	.string "$"
