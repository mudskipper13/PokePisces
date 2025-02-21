.set LOCALID_FLANNERY, 1
.set LOCALID_MOORE, 6
.set LOCALID_HEDORAH, 4
.set LOCALID_GHIDORAH, 3
.set LOCALID_GOJIRA, 2
.set LOCALID_GAMERA, 5

LavaridgeGymNew_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, LavaridgeGymNew_OnLoad
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LavaridgeGymNew_OnFrame
	.byte 0

LavaridgeGymNew_OnLoad:
	call LavaridgeGymNew_EventScript_RemoveFlanneryMoore
	end

LavaridgeGymNew_EventScript_RemoveFlanneryMoore::
	removeobject LOCALID_FLANNERY
	setflag FLAG_TEMP_7
	removeobject LOCALID_MOORE
	setflag FLAG_TEMP_8
	return

LavaridgeGymNew_OnFrame:
	map_script_2 VAR_TEMP_7, 0, LavaridgeGymNew_EventScript_Interrogation
	.2byte 0

LavaridgeGymNew_EventScript_Interrogation::
	lock
	setvar VAR_TEMP_7, 1
	applymovement LOCALID_FLANNERY, LavaridgeGymNew_Movement_SetInvis
	applymovement LOCALID_MOORE, LavaridgeGymNew_Movement_SetInvis
	applymovement OBJ_EVENT_ID_PLAYER, LavaridgeGymNew_Movement_FaceUp
	waitmovement 0
	msgbox LavaridgeGymNew_Text_GojiraWelcome, MSGBOX_DEFAULT
	waitmessage
	applymovement OBJ_EVENT_ID_PLAYER, LavaridgeGymNew_Movement_PlayerWalkToTable
	applymovement LOCALID_GOJIRA, LavaridgeGymNew_Movement_GojiraWalkToTable
	waitmovement 0
	delay 32
	special SpawnCameraObject
	delay 16
	applymovement OBJ_EVENT_ID_CAMERA, LavaridgeGymNew_Movement_CameraPanDown
	waitmovement 0
	msgbox LavaridgeGymNew_Text_DurinTest, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_HEDORAH, LavaridgeGymNew_Movement_HedorahGiveDurin
	waitmovement 0
	delay 16
	setmetatile 7, 6, METATILE_LavaridgeGymNew_DurinOnTable, TRUE
	special DrawWholeMapView
	applymovement LOCALID_HEDORAH, LavaridgeGymNew_Movement_HedorahWalkBack
	msgbox LavaridgeGymNew_Text_WeInsist, MSGBOX_DEFAULT
	switch VAR_DURIN_RESISTANCE
	case 0, LavaridgeGymNew_EventScript_Eat0Resist
	case 1, LavaridgeGymNew_EventScript_Eat0Resist
	case 2, LavaridgeGymNew_EventScript_Eat1Resist
	case 3, LavaridgeGymNew_EventScript_Eat2Resist
	case 4, LavaridgeGymNew_EventScript_EatMaxResist
	case 5, LavaridgeGymNew_EventScript_EatMaxResist
	closemessage
	release
	end

LavaridgeGymNew_Movement_CameraPanDown:
	walk_down
	walk_down
	step_end

LavaridgeGymNew_Movement_CameraPanUp:
	walk_up
	walk_up
	step_end

LavaridgeGymNew_EventScript_Eat0Resist::
	setmetatile 7, 6, METATILE_LavaridgeGymNew_TableTop, TRUE
	special DrawWholeMapView
	pike_flashscreen
	playse SE_M_NIGHTMARE
	msgbox LavaridgeGymNew_Text_Eat0Resist, MSGBOX_DEFAULT
	poisonplayerparty
	goto LavaridgeGymNew_EventScript_InterrogationPart2
	release
	end

LavaridgeGymNew_EventScript_Eat1Resist::
	setmetatile 7, 6, METATILE_LavaridgeGymNew_TableTop, TRUE
	special DrawWholeMapView
	pike_flashscreen
	playse SE_M_NIGHTMARE
	msgbox LavaridgeGymNew_Text_Eat1Resist, MSGBOX_DEFAULT
	poisonplayerparty
	goto LavaridgeGymNew_EventScript_InterrogationPart2
	release
	end

LavaridgeGymNew_EventScript_Eat2Resist::
	setmetatile 7, 6, METATILE_LavaridgeGymNew_TableTop, TRUE
	special DrawWholeMapView
	pike_flashscreen
	playse SE_M_NIGHTMARE
	msgbox LavaridgeGymNew_Text_Eat2Resist, MSGBOX_DEFAULT
	poisonplayerparty
	goto LavaridgeGymNew_EventScript_InterrogationPart2
	release
	end

LavaridgeGymNew_EventScript_EatMaxResist::
	setmetatile 7, 6, METATILE_LavaridgeGymNew_TableTop, TRUE
	special DrawWholeMapView
	msgbox LavaridgeGymNew_Text_EatMaxResist, MSGBOX_DEFAULT
	goto LavaridgeGymNew_EventScript_InterrogationPart2
	release
	end

LavaridgeGymNew_EventScript_InterrogationPart2::
	msgbox LavaridgeGymNew_Text_DurinPride, MSGBOX_DEFAULT
	msgbox LavaridgeGymNew_Text_WhatDoForLiving, MSGBOX_DEFAULT
	multichoice 19, 4, MULTI_LAVAGYM_QUESTION_1, TRUE
	copyvar VAR_TEMP_1, VAR_RESULT
	switch VAR_TEMP_1
	case 0, LavaridgeGymNew_EventScript_StudyPokemon
	case 1, LavaridgeGymNew_EventScript_TasteTestSoup
	case 2, LavaridgeGymNew_EventScript_Cop
	closemessage
	release
	end

LavaridgeGymNew_EventScript_StudyPokemon::
	setflag FLAG_TEMP_1
	msgbox LavaridgeGymNew_Text_SoYouStudyPokemon, MSGBOX_DEFAULT
	goto LavaridgeGymNew_EventScript_InterrogationPart3
	release
	end

LavaridgeGymNew_EventScript_TasteTestSoup::
	setflag FLAG_TEMP_2
	msgbox LavaridgeGymNew_Text_SoYouTasteTestSoup, MSGBOX_DEFAULT
	goto LavaridgeGymNew_EventScript_InterrogationPart3
	release
	end

LavaridgeGymNew_EventScript_Cop::
	applymovement OBJ_EVENT_ID_CAMERA, LavaridgeGymNew_Movement_CameraPanUp
	waitmovement 0
	special RemoveCameraObject
	delay 4
	applymovement LOCALID_GOJIRA, LavaridgeGymNew_Movement_ShockAtCop
	msgbox LavaridgeGymNew_Text_GetOutDirtyCop, MSGBOX_DEFAULT
	warp MAP_LAVARIDGE_INT, 23, 11
	release
	end

LavaridgeGymNew_EventScript_InterrogationPart3::
	msgbox LavaridgeGymNew_Text_SmallTalk, MSGBOX_DEFAULT
	applymovement LOCALID_GOJIRA, LavaridgeGymNew_Movement_FaceRight
	msgbox LavaridgeGymNew_Text_HoldOnHere, MSGBOX_DEFAULT
	applymovement LOCALID_GHIDORAH, LavaridgeGymNew_Movement_GhidorahAccost
	applymovement LOCALID_HEDORAH, LavaridgeGymNew_Movement_HedorahAccost
	waitmovement 0
	applymovement OBJ_EVENT_ID_CAMERA, LavaridgeGymNew_Movement_CameraPanUp
	waitmovement 0
	special RemoveCameraObject
	delay 4
	msgbox LavaridgeGymNew_Text_WeWannaBattle, MSGBOX_DEFAULT
	trainerbattle_two_trainers TRAINER_P_HEDORAH, LavaridgeGymNew_Text_HedorahDefeat, TRAINER_P_GHIDORAH, LavaridgeGymNew_Text_GhidorahDefeat, LavaridgeGymNew_EventScript_InterrogationPart4, NO_MUSIC
	goto LavaridgeGymNew_EventScript_InterrogationPart4
	release
	end

LavaridgeGymNew_EventScript_InterrogationPart4::
	applymovement LOCALID_GHIDORAH, LavaridgeGymNew_Movement_Shocked
	applymovement LOCALID_HEDORAH, LavaridgeGymNew_Movement_Shocked
	waitmovement 0
	msgbox LavaridgeGymNew_Text_YoureToughStuff, MSGBOX_DEFAULT
	special SpawnCameraObject
	delay 8
	applymovement OBJ_EVENT_ID_CAMERA, LavaridgeGymNew_Movement_CameraPanDown
	waitmovement 0
	applymovement LOCALID_GOJIRA, LavaridgeGymNew_Movement_StandAtAttention
	waitmovement 0
	playse SE_BANG
	msgbox LavaridgeGymNew_Text_EnoughFromYou, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GHIDORAH, LavaridgeGymNew_Movement_GhidorahLeave
	applymovement LOCALID_HEDORAH, LavaridgeGymNew_Movement_HedorahLeave
	waitmovement 0
	removeobject LOCALID_GHIDORAH
	removeobject LOCALID_HEDORAH
	applymovement LOCALID_GAMERA, LavaridgeGymNew_Movement_GameraEnter
	waitmovement 0
	msgbox LavaridgeGymNew_Text_IWillBeginSupervising, MSGBOX_DEFAULT
	applymovement LOCALID_GOJIRA, LavaridgeGymNew_Movement_SitBackDown
	waitmovement 0
	msgbox LavaridgeGymNew_Text_WillQuestionYou, MSGBOX_DEFAULT
	msgbox LavaridgeGymNew_Text_HowMuchWouldYouSpend, MSGBOX_DEFAULT
	multichoice 19, 4, MULTI_LAVAGYM_QUESTION_2, TRUE
	copyvar VAR_TEMP_1, VAR_RESULT
	switch VAR_TEMP_1
	case 0, LavaridgeGymNew_EventScript_MoneyNone
	case 1, LavaridgeGymNew_EventScript_MoneyAll
	case 2, LavaridgeGymNew_EventScript_MoneyNameYourPrice
	closemessage
	release
	end

LavaridgeGymNew_EventScript_MoneyNone::
	msgbox LavaridgeGymNew_Text_MoneyNone, MSGBOX_DEFAULT
	goto LavaridgeGymNew_EventScript_GameraQuestion2
	release
	end

LavaridgeGymNew_EventScript_MoneyAll::
	addvar VAR_TEMP_8, 1
	msgbox LavaridgeGymNew_Text_MoneyAll, MSGBOX_DEFAULT
	goto LavaridgeGymNew_EventScript_GameraQuestion2
	release
	end

LavaridgeGymNew_EventScript_MoneyNameYourPrice::
	addvar VAR_TEMP_8, 1
	msgbox LavaridgeGymNew_Text_MoneyNameYourPrice, MSGBOX_DEFAULT
	goto LavaridgeGymNew_EventScript_GameraQuestion2
	release
	end

LavaridgeGymNew_EventScript_GameraQuestion2::
	msgbox LavaridgeGymNew_Text_HaveYouEverDropKicked, MSGBOX_DEFAULT
	multichoice 19, 4, MULTI_LAVAGYM_QUESTION_3, TRUE
	copyvar VAR_TEMP_1, VAR_RESULT
	switch VAR_TEMP_1
	case 0, LavaridgeGymNew_EventScript_DropKickNo
	case 1, LavaridgeGymNew_EventScript_DropKickSeveral
	case 2, LavaridgeGymNew_EventScript_DropKickWoman
	closemessage
	release
	end

LavaridgeGymNew_EventScript_DropKickNo::
	addvar VAR_TEMP_8, 1
	msgbox LavaridgeGymNew_Text_DropKickNo, MSGBOX_DEFAULT
	goto LavaridgeGymNew_EventScript_GameraQuestion3
	release
	end

LavaridgeGymNew_EventScript_DropKickSeveral::
	msgbox LavaridgeGymNew_Text_DropKickSeveral, MSGBOX_DEFAULT
	goto LavaridgeGymNew_EventScript_GameraQuestion3
	release
	end

LavaridgeGymNew_EventScript_DropKickWoman::
	applymovement OBJ_EVENT_ID_CAMERA, LavaridgeGymNew_Movement_CameraPanUp
	waitmovement 0
	special RemoveCameraObject
	delay 4
	msgbox LavaridgeGymNew_Text_GameraDropKickIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_P_GAMERA, LavaridgeGymNew_Text_GameraDefeat
	goto LavaridgeGymNew_EventScript_InterrogationPart5
	release
	end

LavaridgeGymNew_EventScript_GameraQuestion3::
	msgbox LavaridgeGymNew_Text_HowMuchSmokeInhaled, MSGBOX_DEFAULT
	multichoice 19, 4, MULTI_LAVAGYM_QUESTION_4, TRUE
	copyvar VAR_TEMP_1, VAR_RESULT
	switch VAR_TEMP_1
	case 0, LavaridgeGymNew_EventScript_SmokeALittle
	case 1, LavaridgeGymNew_EventScript_SmokeALottle
	case 2, LavaridgeGymNew_EventScript_SmokeCoughingFit
	closemessage
	release
	end	

LavaridgeGymNew_EventScript_SmokeALittle::
	addvar VAR_TEMP_8, 1
	msgbox LavaridgeGymNew_Text_SmokeALittle, MSGBOX_DEFAULT
	goto LavaridgeGymNew_EventScript_GameraQuestion4
	release
	end

LavaridgeGymNew_EventScript_SmokeALottle::
	addvar VAR_TEMP_8, 1
	msgbox LavaridgeGymNew_Text_SmokeALottle, MSGBOX_DEFAULT
	goto LavaridgeGymNew_EventScript_GameraQuestion4
	release
	end

LavaridgeGymNew_EventScript_SmokeCoughingFit::
	msgbox LavaridgeGymNew_Text_SmokeCoughingFit, MSGBOX_DEFAULT
	goto LavaridgeGymNew_EventScript_GameraQuestion4
	release
	end

LavaridgeGymNew_EventScript_GameraQuestion4::
	msgbox LavaridgeGymNew_Text_ManWithFuschiaHair, MSGBOX_DEFAULT
	multichoice 19, 4, MULTI_LAVAGYM_QUESTION_5, TRUE
	copyvar VAR_TEMP_1, VAR_RESULT
	switch VAR_TEMP_1
	case 0, LavaridgeGymNew_EventScript_BreadFightHim
	case 1, LavaridgeGymNew_EventScript_BreadFightHim
	case 2, LavaridgeGymNew_EventScript_BreadFightHim
	closemessage
	release
	end

LavaridgeGymNew_EventScript_BreadFightHim::
	msgbox LavaridgeGymNew_Text_BreadFightHim, MSGBOX_DEFAULT
	goto_if_ge VAR_TEMP_8, 2, LavaridgeGymNew_EventScript_FightGameraGojira
	goto LavaridgeGymNew_EventScript_GameraGojiraRespect
	release
	end

LavaridgeGymNew_EventScript_FightGameraGojira::
	applymovement OBJ_EVENT_ID_CAMERA, LavaridgeGymNew_Movement_CameraPanUp
	waitmovement 0
	special RemoveCameraObject
	delay 4
	playse SE_BANG
	msgbox LavaridgeGymNew_Text_NotApproved, MSGBOX_DEFAULT
	trainerbattle_two_trainers TRAINER_P_GAMERA, LavaridgeGymNew_Text_GameraDefeat, TRAINER_P_GOJIRA, LavaridgeGymNew_Text_GojiraDefeat, LavaridgeGymNew_EventScript_InterrogationPart5, NO_MUSIC
	goto LavaridgeGymNew_EventScript_InterrogationPart5
	release
	end

LavaridgeGymNew_EventScript_GameraGojiraRespect::
	applymovement OBJ_EVENT_ID_CAMERA, LavaridgeGymNew_Movement_CameraPanUp
	waitmovement 0
	special RemoveCameraObject
	delay 4
	msgbox LavaridgeGymNew_Text_Approved, MSGBOX_DEFAULT
	goto LavaridgeGymNew_EventScript_InterrogationPart5
	release
	end

LavaridgeGymNew_EventScript_InterrogationPart5::
	playse SE_BANG
	msgbox LavaridgeGymNew_Text_WeveHeardEnough, MSGBOX_DEFAULT
	playse SE_PIN
	applymovement LOCALID_GOJIRA, LavaridgeGymNew_Movement_LookUpInShock
	applymovement LOCALID_GAMERA, LavaridgeGymNew_Movement_LookUpInShock
	clearflag FLAG_TEMP_7
	addobject LOCALID_FLANNERY
	clearflag FLAG_TEMP_8
	addobject LOCALID_MOORE
	delay 8
	applymovement LOCALID_FLANNERY, LavaridgeGymNew_Movement_FlanneryEnterRoom
	applymovement LOCALID_MOORE, LavaridgeGymNew_Movement_MooreEnterRoom
	waitmovement 0
	special SpawnCameraObject
	delay 8
	applymovement OBJ_EVENT_ID_CAMERA, LavaridgeGymNew_Movement_CameraPanDown
	waitmovement 0
	msgbox LavaridgeGymNew_Text_WeWillTakeCareOfThis, MSGBOX_DEFAULT
	applymovement LOCALID_GOJIRA, LavaridgeGymNew_Movement_GojiraRunAway
	applymovement LOCALID_GAMERA, LavaridgeGymNew_Movement_GameraRunAway
	waitmovement 0
	removeobject LOCALID_GOJIRA
	setflag FLAG_TEMP_9
	removeobject LOCALID_GAMERA
	setflag FLAG_TEMP_A
	applymovement LOCALID_FLANNERY, LavaridgeGymNew_Movement_FlanneryGoToTable
	applymovement LOCALID_MOORE, LavaridgeGymNew_Movement_MooreGoToTable
	waitmovement 0
	msgbox LavaridgeGymNew_Text_MooreFamilyHistory, MSGBOX_DEFAULT
	applymovement LOCALID_MOORE, LavaridgeGymNew_Movement_MooreGiveLava
	waitmovement 0
	delay 16
	setmetatile 7, 6, METATILE_LavaridgeGymNew_SoupOnTable, TRUE
	special DrawWholeMapView
	msgbox LavaridgeGymNew_Text_HaveSomeSearingSpicySoup, MSGBOX_DEFAULT
	goto_if_set FLAG_TEMP_2, LavaridgeGymNew_EventScript_SkipSoup
	msgbox LavaridgeGymNew_Text_CantRefuseSoup, MSGBOX_DEFAULT
	pike_flashscreen
	playse SE_M_EMBER
	burnplayerparty
	setmetatile 7, 6, METATILE_LavaridgeGymNew_TableTop, TRUE
	special DrawWholeMapView
	msgbox LavaridgeGymNew_Text_ItBurns, MSGBOX_DEFAULT
	goto LavaridgeGymNew_EventScript_InterrogationPart6
	release
	end

LavaridgeGymNew_EventScript_SkipSoup::
	msgbox LavaridgeGymNew_Text_OhYouEatEnoughSoup, MSGBOX_DEFAULT
	setmetatile 7, 6, METATILE_LavaridgeGymNew_TableTop, TRUE
	special DrawWholeMapView
	goto LavaridgeGymNew_EventScript_InterrogationPart6
	release
	end

LavaridgeGymNew_EventScript_InterrogationPart6::
	applymovement LOCALID_MOORE, LavaridgeGymNew_Movement_MooreSitBackDown
	applymovement LOCALID_FLANNERY, LavaridgeGymNew_Movement_FlanneryGetUpWater
	waitmovement 0
	msgbox LavaridgeGymNew_Text_WouldYouLikeWater, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, LavaridgeGymNew_EventScript_HowDareYou
	applymovement LOCALID_FLANNERY, LavaridgeGymNew_Movement_FaceDown
	waitmovement 0
	msgbox LavaridgeGymNew_Text_WouldYouLikeAirCon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, LavaridgeGymNew_EventScript_HowDareYou
	applymovement LOCALID_FLANNERY, LavaridgeGymNew_Movement_FlanneryBackToSeat
	waitmovement 0
	applymovement OBJ_EVENT_ID_CAMERA, LavaridgeGymNew_Movement_CameraPanUp
	waitmovement 0
	special RemoveCameraObject
	delay 4
	msgbox LavaridgeGymNew_Text_ItsTimeForBattle, MSGBOX_DEFAULT
	trainerbattle_two_trainers TRAINER_P_FLANNERY, LavaridgeGymNew_Text_FlanneryDefeat, TRAINER_P_MR_MOORE, LavaridgeGymNew_Text_MooreDefeat, LavaridgeGymNew_EventScript_GymBattleOver, NO_MUSIC
	goto LavaridgeGymNew_EventScript_GymBattleOver
	release
	end

LavaridgeGymNew_EventScript_HowDareYou::
	applymovement LOCALID_FLANNERY, LavaridgeGymNew_Movement_HowDareYou
	waitmovement 0
	playbgm MUS_RG_ENCOUNTER_GYM_LEADER, FALSE
	msgbox LavaridgeGymNew_Text_WeLikeToSweat, MSGBOX_DEFAULT
	delay 16
	setweather WEATHER_DROUGHT
	doweather
	delay 8
	applymovement OBJ_EVENT_ID_CAMERA, LavaridgeGymNew_Movement_CameraPanUp
	waitmovement 0
	special RemoveCameraObject
	delay 4
	msgbox LavaridgeGymNew_Text_BattleUsInSwelteringHeat, MSGBOX_DEFAULT
	trainerbattle_two_trainers TRAINER_P_FLANNERY, LavaridgeGymNew_Text_FlanneryDefeat, TRAINER_P_MR_MOORE, LavaridgeGymNew_Text_MooreDefeat, LavaridgeGymNew_EventScript_GymBattleOver, NO_MUSIC
	goto LavaridgeGymNew_EventScript_GymBattleOver
	release
	end

LavaridgeGymNew_EventScript_GymBattleOver::
	speakername LavaridgeGymNew_Text_NameMoore
	msgbox LavaridgeGymNew_Text_YouDidIt, MSGBOX_DEFAULT
	setflag FLAG_BADGE05_GET
	setflag FLAG_DEFEATED_LAVARIDGE_GYM
	setvar VAR_PISCES_STORY_PROGRESS, 6
	giveitem ITEM_TM_WILL_O_WISP
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	giveitem ITEM_TM_DRAGON_CLAW
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	speakername NULL
	message LavaridgeGymNew_Text_ReceivedTemperBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	speakername LavaridgeGymNew_Text_NameFlannery
	msgbox LavaridgeGymNew_Text_ByeBye, MSGBOX_DEFAULT
	speakername NULL
	setvar VAR_TEMP_7, 1
	warp MAP_LAVARIDGE_INT, 23, 11
	waitstate
	release
	end	

LavaridgeGymNew_Movement_FlanneryBackToSeat:
	walk_down
	walk_down
	walk_down
	walk_right
	step_end

LavaridgeGymNew_Movement_HowDareYou:
	face_down
	delay_16
	delay_16
	walk_in_place_fast_down
	walk_in_place_fast_down
	walk_in_place_fast_down
	walk_in_place_fast_down
	step_end

LavaridgeGymNew_Movement_FaceDown:
	face_down
	step_end

LavaridgeGymNew_Movement_FlanneryGetUpWater:
	walk_up
	walk_up
	walk_up
	walk_left
	face_up
	step_end

LavaridgeGymNew_Movement_MooreSitBackDown:
	walk_slow_right
	walk_slow_right
	walk_slow_up
	face_left
	step_end

LavaridgeGymNew_Movement_MooreGiveLava:
	walk_slow_down
	walk_slow_left
	walk_slow_left
	face_up
	delay_8
	step_end

LavaridgeGymNew_Movement_GameraRunAway:
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
	step_end

LavaridgeGymNew_Movement_GojiraRunAway:
	jump_in_place_left
	walk_fast_down
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fast_down
	step_end

LavaridgeGymNew_Movement_MooreGoToTable:
	walk_slow_down
	walk_slow_right
	walk_slow_right
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_slow_down
	face_left
	step_end

LavaridgeGymNew_Movement_FlanneryGoToTable:
	walk_down
	walk_down
	walk_down
	walk_down
	face_right
	step_end

LavaridgeGymNew_Movement_MooreEnterRoom:
	set_visible
	walk_slow_down
	walk_slow_right
	face_down
	step_end

LavaridgeGymNew_Movement_FlanneryEnterRoom:
	set_visible
	walk_down
	walk_left
	face_down
	step_end

LavaridgeGymNew_Movement_LookUpInShock:
	emote_exclamation_mark
	face_up
	step_end

LavaridgeGymNew_Movement_SitBackDown:
	walk_right
	walk_right
	walk_up
	face_left
	step_end

LavaridgeGymNew_Movement_GameraEnter:
	walk_slow_up
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_down
	face_right
	step_end

LavaridgeGymNew_Movement_HedorahLeave:
	walk_fast_left
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	set_invisible
	step_end

LavaridgeGymNew_Movement_GhidorahLeave:
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	set_invisible
	step_end

LavaridgeGymNew_Movement_StandAtAttention:
	walk_down
	walk_left
	walk_left
	face_up
	delay_8
	step_end

LavaridgeGymNew_Movement_Shocked:
	emote_exclamation_mark
	delay_8
	step_end

LavaridgeGymNew_Movement_HedorahWalkBack:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_right
	walk_up
	walk_up
	face_left
	step_end

LavaridgeGymNew_Movement_HedorahGiveDurin:
	walk_down
	walk_down
	walk_left
	walk_down
	walk_down
	face_right
	delay_16
	delay_8
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	face_up
	delay_16
	step_end

LavaridgeGymNew_Movement_GhidorahAccost:
	delay_4
	jump_2_left
	walk_left
	walk_left
	step_end

LavaridgeGymNew_Movement_HedorahAccost:
	jump_2_left
	jump_2_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_down
	face_right
	step_end

LavaridgeGymNew_Movement_FaceRight:
	face_right
	step_end

LavaridgeGymNew_Movement_ShockAtCop:
	emote_exclamation_mark
	delay_8
	walk_fast_up
	walk_fast_up
	walk_fast_left
	step_end

LavaridgeGymNew_Movement_SetInvis:
	set_invisible
	step_end

LavaridgeGymNew_Movement_FaceUp:
	face_up
	step_end

LavaridgeGymNew_Movement_PlayerWalkToTable:
	walk_up
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	face_down
	step_end

LavaridgeGymNew_Movement_GojiraWalkToTable:
	delay_16
	delay_16
	face_left
	delay_16
	walk_left
	walk_left
	walk_up
	face_left
	step_end

LavaridgeGymNew_Text_NameMoore:
	.string "Mr. Moore$"

LavaridgeGymNew_Text_NameFlannery:
	.string "Flannery$"

LavaridgeGymNew_Text_GojiraWelcome:
	.string "The pleasure is ours, challenger.\n"
	.string "Respectfully, if your wish is an\l"
	.string "audience with the Moore family,\l"
	.string "we will need to seriously\l"
	.string "pick your brain.\p"
	.string "Come, pull up a seat.$"

LavaridgeGymNew_Text_DurinTest:
	.string "I'm sure you are in the know\n"
	.string "of Lavaridge's pride and joy,\l"
	.string "mmm? The Durin Berry.\l"
	.string "A delicacy, really. In fact…\p"
	.string "Hedorah?\n"
	.string "Please get a berry for\l"
	.string "this challenger.$"

LavaridgeGymNew_Text_WeInsist:
	.string "Bottoms up.\p"
	.string "(You sense that saying\n"
	.string "“no” here is futile.)$"

LavaridgeGymNew_Text_Eat0Resist:
	.string "(It is absolutely profane.\n"
	.string "A cancer on the mouth.\l"
	.string "You instantly get food poisoning\l"
	.string "SO bad, the effects ripple\l"
	.string "through your party members.)$"

LavaridgeGymNew_Text_Eat1Resist:
	.string "(It is no better the second time.\n"
	.string "You resist the urge to vomit to\l"
	.string "save face. The putrid fruit\l"
	.string "descends punctuatingly into\l"
	.string "your stomach.)$"

LavaridgeGymNew_Text_Eat2Resist:
	.string "(Breathing deeply and steadily,\n"
	.string "you down the Durin.\l"
	.string "You regulate the bile attempting\l"
	.string "to breach and rid your body\l"
	.string "of the hideous produce.\l"
	.string "...Wasn't AS bad as before.)$"

LavaridgeGymNew_Text_EatMaxResist:
	.string "(You hastily get all of the\n"
	.string "berry consumed and swallowed\l"
	.string "before your tongue realizes\l"
	.string "what is on it.\l"
	.string "This berry, for once,\l"
	.string "did not make you sick.)$"

LavaridgeGymNew_Text_AfterEat:
	.string "I will front you some respect;\n"
	.string "that fruit is hazardous\l"
	.string "to outsiders.\p"
	.string "Muscle through it.$"

LavaridgeGymNew_Text_AfterEatResisted:
	.string "A Durin regular!\n"
	.string "Don't get challengers like\l"
	.string "that every day. Impressive.$"

LavaridgeGymNew_Text_DurinPride:
	.string "Durin Berries are the perfect\n"
	.string "emblem of our town. We find\l"
	.string "solace in things the rest\l"
	.string "of the world would deem\l"
	.string "disgusting, or worth refusing.\p"
	.string "That's weakling behavior!$"

LavaridgeGymNew_Text_WhatDoForLiving:
	.string "Now challenger, it behooves me\n"
	.string "to ask you this...\p"
	.string "What is it that you do\n"
	.string "for a living?$"

LavaridgeGymNew_Text_SoYouStudyPokemon:
	.string "Ah. A bit of a ho-hum answer.\n"
	.string "Though maybe it's to be expected,\l"
	.string "considering you are a\l"
	.string "competent enough trainer.$"

LavaridgeGymNew_Text_SoYouTasteTestSoup:
	.string "A soup taster? Bit of a unique\n"
	.string "spin, eh? We don't typically see\l"
	.string "many of those in this neck\l"
	.string "of the woods.$"

LavaridgeGymNew_Text_GetOutDirtyCop:
	.string "Hah. Hah-hah. Real funny.\p"
	.string "I assume that you are well aware\n"
	.string "of where you are standing, yes?\p"
	.string "You are quite lucky that I am in\n"
	.string "a giving mood. Self-identified\l"
	.string "coppers like you don't usually\l"
	.string "leave here with all their\l"
	.string "vital body parts intact.\p"
	.string "Get out, and tell your fed friends\n"
	.string "to keep far away.$"

LavaridgeGymNew_Text_SmallTalk:
	.string "(You twitch your nose at\n"
	.string "the nearby candle's scent.)\p"
	.string "Oh? Taking a liking to the\n"
	.string "candle, eh? It's Mr. Moore's\l"
	.string "favorite scent. 'Ember Snow',\l"
	.string "he called it...$"

LavaridgeGymNew_Text_HoldOnHere:
	.string "(The peanut gallery on the\n"
	.string "eastern side of the room groaned.)\p"
	.string "Enough of this GREENHORN NONSENSE!$"

LavaridgeGymNew_Text_WeWannaBattle:
	.string "Best way to prove you're not\n"
	.string "some namby-pamby loser?\p"
	.string "A RED-HOT BATTLE!$"

LavaridgeGymNew_Text_GhidorahDefeat:
	.string "A wise guy, eh?$"

LavaridgeGymNew_Text_HedorahDefeat:
	.string "Grr.... rrrgh...!\p"
	.string "rrRRRRAAAAARRRRGGGHHHH!!!$"

LavaridgeGymNew_Text_YoureToughStuff:
	.string "We thought you'd get absolutely\n"
	.string "char-broiled...! Boss...!\l"
	.string "H-Help...!$"

LavaridgeGymNew_Text_EnoughFromYou:
	.string "Help? Sure, I'll help... the\n"
	.string "instant a politican tells\l"
	.string "the truth, I will.\p"
	.string "My ass. Out of my sight.\n"
	.string "We will be discussing\l"
	.string "fingernail priveleges later.$"

LavaridgeGymNew_Text_IWillBeginSupervising:
	.string "Ah, ah, ah. Mister Gojira.\n"
	.string "You have been slacking in\l"
	.string "disciplining the peons...\p"
	.string "As per the norm, it falls on\n"
	.string "my shoulders to continue this\l"
	.string "interrogation proper.$"

LavaridgeGymNew_Text_WillQuestionYou:
	.string "I, Mistress Gamera, will\n"
	.string "be studying your every move,\l"
	.string "Master {PLAYER}.\p"
	.string "Do not disappoint me.$"

LavaridgeGymNew_Text_HowMuchWouldYouSpend:
	.string "Let us get down to the root\n"
	.string "of the oak, so to speak, on\l"
	.string "this issue.\p"
	.string "You desire an audience with\n"
	.string "the heads of the Moore family.\p"
	.string "A tall order. Out of your current\n"
	.string "monetary possessions, what amount\l"
	.string "would you be willing to part with?$"

LavaridgeGymNew_Text_MoneyNone:
	.string "Some may say that refusing to\n"
	.string "throw money around to\l"
	.string "solve problems shows respect\l"
	.string "for who you are bargaining with.\p"
	.string "Us at the Moore Estate tend\n"
	.string "to agree with this notion.$"

LavaridgeGymNew_Text_MoneyAll:
	.string "Have you no scruples,\n"
	.string "Master {PLAYER}?\p"
	.string "Just instantly willing to toss\n"
	.string "wads of greenbacks at your\l"
	.string "problems and expect them\l"
	.string "to disappear?\p"
	.string "We do not have need for\n"
	.string "your paultry purse.$"

LavaridgeGymNew_Text_MoneyNameYourPrice:
	.string "...Zero. Zilch. Nada.\p"
	.string "Had you done your research on\n"
	.string "our estate, you would have learned\l"
	.string "that we do not think highly of\l"
	.string "strictly monetary transactions.$"

LavaridgeGymNew_Text_HaveYouEverDropKicked:
	.string "Moving forwards...\p"
	.string "I should not have to explain\n"
	.string "what a drop-kick is, mm?\p"
	.string "It is a fighting tactic that\n"
	.string "we train our peons on from day\l"
	.string "one to deal with particularly\l"
	.string "rowdy debt dodgers...\p"
	.string "Surely a rough-and-tumble\n"
	.string "individual like yourself has\l"
	.string "drop-kicked a man before?$"

LavaridgeGymNew_Text_DropKickNo:
	.string "With those withered strips\n"
	.string "of cooking twine you call legs,\l"
	.string "that does not surprise me.\l"
	.string "Yet, it still disappointed me.$"

LavaridgeGymNew_Text_DropKickSeveral:
	.string "Such confidence,\n"
	.string "Master {PLAYER}.\p"
	.string "We will have to glimpse you\n"
	.string "in action some day.$"

LavaridgeGymNew_Text_GameraDropKickIntro:
	.string "You fancy yourself a smart aleck?\n"
	.string "Wretched thing. I have half a mind\l"
	.string "to catapult you off of your\l"
	.string "moral pedestal.\p"
	.string "Make that full mind. There will\n"
	.string "be nary a trace when I'm\l"
	.string "done with you.$"

LavaridgeGymNew_Text_HowMuchSmokeInhaled:
	.string "Now, another inquiry.\p"
	.string "I would imagine you have\n"
	.string "traversed Mt. Chimney throroughly\l"
	.string "to get to us in Lavaridge.\p"
	.string "Those who live here year-round\n"
	.string "have built a strong resistance\l"
	.string "to the smoky fumes exhausted\l"
	.string "by the molten mountain.\p"
	.string "How much of that black smog\n"
	.string "have you inhaled?$"

LavaridgeGymNew_Text_SmokeALittle:
	.string "Oh, I see. So, you are one of\n"
	.string "those accustomed to cushy, big\l"
	.string "city life. Afraid to get your\l"
	.string "hands, and lungs, dirty. Hmph.$"

LavaridgeGymNew_Text_SmokeALottle:
	.string "A 'lottle'? Please do not insult\n"
	.string "my intelligence with make-pretend\l"
	.string "infant words. Grow up.$"

LavaridgeGymNew_Text_SmokeCoughingFit:
	.string "Well, actions speak louder than\n"
	.string "words, so they say.\p"
	.string "That is the cancerous cough of\n"
	.string "one who has assimilated into\l"
	.string "Mt. Chimney culture.$"

LavaridgeGymNew_Text_ManWithFuschiaHair:
	.string "A scenario for you,\n"
	.string "Master {PLAYER}.\p"
	.string "A middle-aged, fuschia-haired\n"
	.string "man in glasses bumps into\l"
	.string "you while you are en route to\l"
	.string "an important job. What do\l"
	.string "you do to this salaryman?$"

LavaridgeGymNew_Text_BreadFightHim:
	.string "The only logical answer.$"

LavaridgeGymNew_Text_NotApproved:
	.string "Hmph. That should be all.\p"
	.string "Unfortunately, through my\n"
	.string "extensive investigation into\l"
	.string "you, Master {PLAYER}, I have\l"
	.string "determined you unfit to\l"
	.string "meet the heads of the family.\p"
	.string "...I sense you still desire\n"
	.string "to push through. Very well.\p"
	.string "(She snaps her fingers.)\p"
	.string "Gojira. Let us beat the manners\n"
	.string "into this challenger, posthaste!$"

LavaridgeGymNew_Text_GameraDefeat:
	.string "Gh...!\p"
	.string "...Ahem.$"

LavaridgeGymNew_Text_GojiraDefeat:
	.string "Should've guessed this would\n"
	.string "be how it ended after seeing\l"
	.string "you fight earlier...$"

LavaridgeGymNew_Text_Approved:
	.string "I must admit, even with my\n"
	.string "heightened scrutiny, you seem\l"
	.string "to check all of the boxes needed,\l"
	.string "Master {PLAYER}.\p"
	.string "It has been a pleasure\n"
	.string "talking with you.$"

LavaridgeGymNew_Text_WeveHeardEnough:
	.string "(A brash sounding voice boomed\n"
	.string "from the north hallway.)\p"
	.string "I'VE HEARD ENOUGH!$"

LavaridgeGymNew_Text_WeWillTakeCareOfThis:
	.string "Gamera, Gojira, you are dismissed.\p"
	.string "We have accepted this\n"
	.string "challenger's audience.\p"
	.string "You are no longer of use.$"

LavaridgeGymNew_Text_MooreFamilyHistory:
	.string "Pleased to make your acquaintance,\n"
	.string "Master {PLAYER}. I believe I know\l"
	.string "much about you now from observing\l"
	.string "the goings-on earlier.\p"
	.string "I fancy myself a sort of poet, in\n"
	.string "my golden years. In fact, here is\l"
	.string "a quick haiku, off the cuff...\p"
	.string "Heads of Lavaridge.\n"
	.string "What that family strived for?\l"
	.string "Always Moore, not less.\p"
	.string "I've still got it! For the time\n"
	.string "being, while my mind is sharp.\p"
	.string "I had wanted to retire some time\n"
	.string "ago, you know. I had been training\l"
	.string "my dear granddaughter to fully\l"
	.string "take over my duties at the gym.\p"
	.string "After going on a journey throughout\n"
	.string "Hoenn, writing poetry, I soon\l"
	.string "found out in time that I could not\l"
	.string "resist the call of my inner dragon.\p"
	.string "However, I did not wish to strip\n"
	.string "Flannery of her title. Thus, we\l"
	.string "both now man this gym as a duo.\p"
	.string "The two strongest Moores\n"
	.string "Weild awe-inspiring prowess\l"
	.string "In body and mind!\p"
	.string "Hah! Another quick one for you.\n"
	.string "In any case, we should get\l"
	.string "ready for our match.$"

LavaridgeGymNew_Text_HaveSomeSearingSpicySoup:
	.string "Here, this is some of my famous\n"
	.string "recipe, Searing Spicy Soup!\l"
	.string "Made with real lava!\p"
	.string "You can't go fighting on an\n"
	.string "empty stomach, Master {PLAYER}!$"

LavaridgeGymNew_Text_CantRefuseSoup:
	.string "(You sense that this\n"
	.string "is not to be refused.)$"

LavaridgeGymNew_Text_ItBurns:
	.string "(Mr. Moore was not joking around.\n"
	.string "This is the most searing hot food\l"
	.string "you have ever let into your mouth.)\p"
	.string "(It not only burned your esophagus,\n"
	.string "but your party Pokemon got\l"
	.string "burned by association...)$"

LavaridgeGymNew_Text_OhYouEatEnoughSoup:
	.string "Oh...! Silly me!\n"
	.string "I'd almost forgotten; you said\l"
	.string "you were a full-time soup\l"
	.string "taste tester earlier.\p"
	.string "Well I would say you may be sick\n"
	.string "of all that soup, then. Plus, to be\l"
	.string "frank, I don't quite know how I\l"
	.string "would take having a critic dissect\l"
	.string "my family recipe!\p"
	.string "More for Mr. Moore, then! Gahah!\n$"

LavaridgeGymNew_Text_WouldYouLikeWater:
	.string "(Flannery comes over, bearing\n"
	.string "a water bottle in hand.)\p"
	.string "Hey you. Stone-face.\n"
	.string "Have some cold water before I\l"
	.string "kick your ass into next Tuesday.\p"
	.string "(Accept the water?)$"

LavaridgeGymNew_Text_WouldYouLikeAirCon:
	.string "Huh? Not thirsty?\n"
	.string "OKAY then, desert-lips.\p"
	.string "You're lookin' sweaty, by the way.\n"
	.string "Want me to turn on the\l"
	.string "air conditioner before the fight?\l"
	.string "Y'know, if you can't handle\l"
	.string "the heat...?$"

LavaridgeGymNew_Text_ItsTimeForBattle:
	.string "Ha-ha-ha..! Pops, this\n"
	.string "challenger's up my alley.\p"
	.string "You got the memo alright.\n"
	.string "Us Lavaridgers? We THRIVE\l"
	.string "in the heat.\p"
	.string "Let's see if you can still thrive-\n"
	.string "or even survive- this double duel!$"

LavaridgeGymNew_Text_WeLikeToSweat:
	.string "HAH! CALLED IT, POPS!\p"
	.string "I KNEW ol' Preppy McMilqueToast\n"
	.string "here wouldn't beat the heat\l"
	.string "of our confrontation!\p"
	.string "See, bricks-for-brains, the Moore\n"
	.string "family likes our temperatures\l"
	.string "high and dry! What, lookin'\l"
	.string "for some oh-so-comfy AC?\l"
	.string "LOSER! In fact...!$"

LavaridgeGymNew_Text_BattleUsInSwelteringHeat:
	.string "Your battle with us is gonna\n"
	.string "be EXTRA crispy!\p"
	.string "Get ready to sweat this out,\n"
	.string "or DIE TRYING!$"

LavaridgeGymNew_Text_FlanneryDefeat:
	.string "JEEZ, thin-mint!\n"
	.string "You're on a roll!$"

LavaridgeGymNew_Text_MooreDefeat:
	.string "The brave challenger\n"
	.string "overcame their opponents\l"
	.string "and claimed victory!$"

LavaridgeGymNew_Text_YouDidIt:
	.string "A very good display,\n"
	.string "Master {PLAYER}!\p"
	.string "Good to see my brash grand-\n"
	.string "daughter's taunting doesn't phase\l"
	.string "you in the slightest.\p"
	.string "Please accept these presents\n"
	.string "on behalf of the Moore Estate!$"

LavaridgeGymNew_Text_ReceivedTemperBadge:
	.string "{PLAYER} received the\n"
	.string "Temper Badge\l"
	.string "from Mr. Moore and Flannery.$"

LavaridgeGymNew_Text_ByeBye:
	.string "Alright, that's enough.\p"
	.string "Truth be told, I went REAL\n"
	.string "easy on you. Was worried you'd\l"
	.string "have a heart attack of somethin'\l"
	.string "if I went at 100 percent.\p"
	.string "So, with that badge, your Pokemon\n"
	.string "can use the Strength field move\l"
	.string "outside of battle. I don't\l"
	.string "PERSONALLY need it, since I\l"
	.string "can lift them things on my own...\p"
	.string "...But you? Lettuce-arms?\n"
	.string "You're in dire need of it.\l"
	.string "Go try it out.\l"
	.string "Or don't. I don't really care.\p"
	.string "See ya.\n$"
