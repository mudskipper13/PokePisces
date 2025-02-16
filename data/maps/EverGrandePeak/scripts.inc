.set LOCALID_MONKBLOCK1, 2
.set LOCALID_MONKBLOCK2, 3
.set LOCALID_MONKBLOCK3, 4
.set LOCALID_MONKBLOCK4, 5
.set LOCALID_WALLACE, 6
.set LOCALID_STEVEN, 7
.set LOCALID_MAY, 8
.set LOCALID_BRENDAN, 9

EverGrandePeak_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, EverGrandePeak_OnLoad
	.byte 0

EverGrandePeak_OnLoad:
	call_if_gt VAR_NEW_COO_STATE, 10, EverGrandePeak_EventScript_RemoveMonkBlock
	call EverGrandePeak_EventScript_RemoveBrendanMay
	call_if_gt VAR_PISCES_STORY_PROGRESS, 12, EverGrandePeak_EventScript_RemoveStevenWallace
	call_if_set FLAG_SHAYON_ORB, EverGrandePeak_EventScript_AddShayonOrb
	call_if_set FLAG_LUOSHAN_ORB, EverGrandePeak_EventScript_AddLuoshanOrb
	end

EverGrandePeak_EventScript_RemoveMonkBlock::
	removeobject LOCALID_MONKBLOCK1
	setflag FLAG_TEMP_2
	removeobject LOCALID_MONKBLOCK2
	setflag FLAG_TEMP_3
	removeobject LOCALID_MONKBLOCK3
	setflag FLAG_TEMP_4
	removeobject LOCALID_MONKBLOCK4
	setflag FLAG_TEMP_5
	return

EverGrandePeak_EventScript_RemoveBrendanMay::
	removeobject LOCALID_BRENDAN
	setflag FLAG_TEMP_11
	removeobject LOCALID_MAY
	setflag FLAG_TEMP_12
	return

EverGrandePeak_EventScript_RemoveStevenWallace::
	removeobject LOCALID_WALLACE
	setflag FLAG_TEMP_13
	removeobject LOCALID_STEVEN
	setflag FLAG_TEMP_14
	return

EverGrandePeak_EventScript_AddShayonOrb::
	setmetatile 6, 1, METATILE_Golden_ShaYonOrbTop, TRUE
	setmetatile 6, 2, METATILE_Golden_ShaYonOrbBottom, TRUE
	special DrawWholeMapView
	return

EverGrandePeak_EventScript_AddLuoshanOrb::
	setmetatile 70, 67, METATILE_Golden_LuoShanOrbTop, TRUE
	setmetatile 70, 68, METATILE_Golden_LuoShanOrbBottom, TRUE
	special DrawWholeMapView
	return

EverGrandePeak_EventScript_SWTriggerWest1::
	lock
	delay 4
	applymovement OBJ_EVENT_ID_PLAYER, EverGrandePeak_Movement_PlayerSWWest1
	waitmovement 0
	goto EverGrandePeak_EventScript_StevenWallaceBattle
	release
	end

EverGrandePeak_Movement_PlayerSWWest1:
	walk_down
	walk_right
	walk_down
	walk_right
	walk_right
	face_up
	step_end

EverGrandePeak_EventScript_SWTriggerWest2::
	lock
	delay 4
	applymovement OBJ_EVENT_ID_PLAYER, EverGrandePeak_Movement_PlayerSWWest2
	waitmovement 0
	goto EverGrandePeak_EventScript_StevenWallaceBattle
	release
	end

EverGrandePeak_Movement_PlayerSWWest2:
	walk_right
	walk_down
	walk_right
	walk_right
	face_up
	step_end

EverGrandePeak_EventScript_SWTriggerWest3::
	lock
	delay 4
	applymovement OBJ_EVENT_ID_PLAYER, EverGrandePeak_Movement_PlayerSWWest3
	waitmovement 0
	goto EverGrandePeak_EventScript_StevenWallaceBattle
	release
	end

EverGrandePeak_Movement_PlayerSWWest3:
	walk_right
	walk_right
	walk_right
	face_up
	step_end

EverGrandePeak_EventScript_SWTriggerEast1::
	lock
	delay 4
	applymovement OBJ_EVENT_ID_PLAYER, EverGrandePeak_Movement_PlayerSWEast1
	waitmovement 0
	goto EverGrandePeak_EventScript_StevenWallaceBattle
	release
	end

EverGrandePeak_Movement_PlayerSWEast1:
	walk_down
	walk_left
	walk_down
	walk_left
	walk_left
	face_up
	step_end

EverGrandePeak_EventScript_SWTriggerEast2::
	lock
	delay 4
	applymovement OBJ_EVENT_ID_PLAYER, EverGrandePeak_Movement_PlayerSWEast2
	waitmovement 0
	goto EverGrandePeak_EventScript_StevenWallaceBattle
	release
	end

EverGrandePeak_Movement_PlayerSWEast2:
	walk_left
	walk_down
	walk_left
	walk_left
	face_up
	step_end

EverGrandePeak_EventScript_SWTriggerEast3::
	lock
	delay 4
	applymovement OBJ_EVENT_ID_PLAYER, EverGrandePeak_Movement_PlayerSWEast3
	waitmovement 0
	goto EverGrandePeak_EventScript_StevenWallaceBattle
	release
	end

EverGrandePeak_Movement_PlayerSWEast3:
	walk_left
	walk_left
	walk_left
	face_up
	step_end

EverGrandePeak_EventScript_SWTriggerSouth1::
	lock
	delay 4
	applymovement OBJ_EVENT_ID_PLAYER, EverGrandePeak_Movement_PlayerSWSouth1
	waitmovement 0
	goto EverGrandePeak_EventScript_StevenWallaceBattle
	release
	end

EverGrandePeak_Movement_PlayerSWSouth1:
	walk_up
	walk_right
	face_up
	step_end

EverGrandePeak_EventScript_SWTriggerSouth2::
	lock
	delay 4
	applymovement OBJ_EVENT_ID_PLAYER, EverGrandePeak_Movement_PlayerSWSouth2
	waitmovement 0
	goto EverGrandePeak_EventScript_StevenWallaceBattle
	release
	end

EverGrandePeak_Movement_PlayerSWSouth2:
	walk_up
	face_up
	step_end

EverGrandePeak_EventScript_SWTriggerSouth3::
	lock
	delay 4
	applymovement OBJ_EVENT_ID_PLAYER, EverGrandePeak_Movement_PlayerSWSouth3
	waitmovement 0
	goto EverGrandePeak_EventScript_StevenWallaceBattle
	release
	end

EverGrandePeak_Movement_PlayerSWSouth3:
	walk_up
	walk_left
	face_up
	step_end

EverGrandePeak_EventScript_StevenWallaceBattle::
	delay 16
	turnobject LOCALID_WALLACE, DIR_SOUTH
	turnobject LOCALID_STEVEN, DIR_SOUTH
	delay 8
	speakername EverGrandePeak_Text_NameWallace
	msgbox EverGrandePeak_Text_Welcome, MSGBOX_DEFAULT
	speakername EverGrandePeak_Text_NameSteven
	msgbox EverGrandePeak_Text_YouveDoneWell, MSGBOX_DEFAULT
	speakername EverGrandePeak_Text_NameWallace
	msgbox EverGrandePeak_Text_DoYouHaveTheOrbs, MSGBOX_DEFAULT
	speakername EverGrandePeak_Text_NameSteven
	msgbox EverGrandePeak_Text_OneLastTest, MSGBOX_DEFAULT
	speakername NULL
	trainerbattle_two_trainers TRAINER_P_WALLACE, EverGrandePeak_Text_WallaceDefeat, TRAINER_P_STEVEN, EverGrandePeak_Text_StevenDefeat, EverGrandePeak_EventScript_SWDefeated, NO_MUSIC
	goto EverGrandePeak_EventScript_SWDefeated
	release
	end

EverGrandePeak_EventScript_SWDefeated::
	setvar VAR_NEW_COO_STATE, 11
	speakername EverGrandePeak_Text_NameSteven
	msgbox EverGrandePeak_Text_YouAreWorthy, MSGBOX_DEFAULT
	speakername EverGrandePeak_Text_NameWallace
	msgbox EverGrandePeak_Text_TakeTheOrbsToTheirShrines, MSGBOX_DEFAULT
	call EverGrandePeak_EventScript_RemoveMonkBlock
	speakername EverGrandePeak_Text_NameSteven
	msgbox EverGrandePeak_Text_WeWillBeWaiting, MSGBOX_AUTOCLOSE
	release
	end

EverGrandePeak_EventScript_ShayonShrine::
	lock
	goto_if_set FLAG_SHAYON_ORB, EverGrandePeak_EventScript_ShayonShrineOrbSet
	msgbox EverGrandePeak_Text_HighestPoint, MSGBOX_DEFAULT
	playse SE_SHINY
	call EverGrandePeak_EventScript_AddShayonOrb
	setflag FLAG_SHAYON_ORB
	closemessage
	delay 8
	goto_if_set FLAG_LUOSHAN_ORB, EverGrandePeak_EventScript_BothOrbsSet
	release
	end

EverGrandePeak_EventScript_ShayonShrineOrbSet::
	msgbox EverGrandePeak_Text_ShayonShrineOrbSet, MSGBOX_AUTOCLOSE
	release
	end

EverGrandePeak_EventScript_LuoshanShrine::
	lock
	goto_if_set FLAG_LUOSHAN_ORB, EverGrandePeak_EventScript_LuoshanShrineOrbSet
	msgbox EverGrandePeak_Text_LowestPoint, MSGBOX_DEFAULT
	playse SE_SHINY
	call EverGrandePeak_EventScript_AddLuoshanOrb
	setflag FLAG_LUOSHAN_ORB
	closemessage
	delay 8
	goto_if_set FLAG_SHAYON_ORB, EverGrandePeak_EventScript_BothOrbsSet
	release
	end

EverGrandePeak_EventScript_LuoshanShrineOrbSet::
	msgbox EverGrandePeak_Text_LuoshanShrineOrbSet, MSGBOX_AUTOCLOSE
	release
	end

EverGrandePeak_EventScript_BothOrbsSet::
	setvar VAR_NEW_COO_STATE, 12
	msgbox EverGrandePeak_Text_BothOrbsSet, MSGBOX_AUTOCLOSE
	release
	end

EverGrandePeak_EventScript_BMTriggerWest1::
	lock
	delay 4
	applymovement OBJ_EVENT_ID_PLAYER, EverGrandePeak_Movement_PlayerSWWest1
	waitmovement 0
	goto EverGrandePeak_EventScript_BrendanMayBattle
	release
	end

EverGrandePeak_EventScript_BMTriggerWest2::
	lock
	delay 4
	applymovement OBJ_EVENT_ID_PLAYER, EverGrandePeak_Movement_PlayerSWWest2
	waitmovement 0
	goto EverGrandePeak_EventScript_BrendanMayBattle
	release
	end

EverGrandePeak_EventScript_BMTriggerWest3::
	lock
	delay 4
	applymovement OBJ_EVENT_ID_PLAYER, EverGrandePeak_Movement_PlayerSWWest3
	waitmovement 0
	goto EverGrandePeak_EventScript_BrendanMayBattle
	release
	end

EverGrandePeak_EventScript_BMTriggerEast1::
	lock
	delay 4
	applymovement OBJ_EVENT_ID_PLAYER, EverGrandePeak_Movement_PlayerSWEast1
	waitmovement 0
	goto EverGrandePeak_EventScript_BrendanMayBattle
	release
	end

EverGrandePeak_EventScript_BMTriggerEast2::
	lock
	delay 4
	applymovement OBJ_EVENT_ID_PLAYER, EverGrandePeak_Movement_PlayerSWEast2
	waitmovement 0
	goto EverGrandePeak_EventScript_BrendanMayBattle
	release
	end

EverGrandePeak_EventScript_BMTriggerEast3::
	lock
	delay 4
	applymovement OBJ_EVENT_ID_PLAYER, EverGrandePeak_Movement_PlayerSWEast3
	waitmovement 0
	goto EverGrandePeak_EventScript_BrendanMayBattle
	release
	end

EverGrandePeak_EventScript_BMTriggerSouth1::
	lock
	delay 4
	applymovement OBJ_EVENT_ID_PLAYER, EverGrandePeak_Movement_PlayerSWSouth1
	waitmovement 0
	goto EverGrandePeak_EventScript_BrendanMayBattle
	release
	end

EverGrandePeak_EventScript_BMTriggerSouth2::
	lock
	delay 4
	applymovement OBJ_EVENT_ID_PLAYER, EverGrandePeak_Movement_PlayerSWSouth2
	waitmovement 0
	goto EverGrandePeak_EventScript_BrendanMayBattle
	release
	end

EverGrandePeak_EventScript_BMTriggerSouth3::
	lock
	delay 4
	applymovement OBJ_EVENT_ID_PLAYER, EverGrandePeak_Movement_PlayerSWSouth3
	waitmovement 0
	goto EverGrandePeak_EventScript_BrendanMayBattle
	release
	end

EverGrandePeak_EventScript_BrendanMayBattle::
	delay 16
	turnobject LOCALID_WALLACE, DIR_SOUTH
	turnobject LOCALID_STEVEN, DIR_SOUTH
	delay 8
	speakername EverGrandePeak_Text_NameWallace
	msgbox EverGrandePeak_Text_IFeelTheOrbsPower, MSGBOX_DEFAULT
	speakername EverGrandePeak_Text_NameSteven
	msgbox EverGrandePeak_Text_OneMoreThingToDo, MSGBOX_DEFAULT
	closemessage
	special HealPlayerParty
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, EverGrandePeak_EventScript_MayBattle
	goto_if_eq VAR_RESULT, FEMALE, EverGrandePeak_EventScript_BrendanBattle
	release
	end

EverGrandePeak_EventScript_MayBattle::
	clearflag FLAG_TEMP_12
	addobject LOCALID_MAY
	delay 16
	applymovement LOCALID_MAY, EverGrandePeak_Movement_MayWalkOnScreen
	waitmovement 0
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, EverGrandePeak_Movement_PlayerNoticeRival
	waitmovement 0
	delay 16
	playbgm MUS_ENCOUNTER_MAY, FALSE
	applymovement OBJ_EVENT_ID_PLAYER, EverGrandePeak_Movement_PlayerWalkToRival
	waitmovement 0
	delay 8
	speakername NULL
	msgbox EverGrandePeak_Text_YouLockEyes, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_P_MAY_FINAL, EverGrandePeak_Text_MayDefeated
	goto EverGrandePeak_EventScript_ShunyongAwakens
	release
	end

EverGrandePeak_EventScript_BrendanBattle::
	clearflag FLAG_TEMP_11
	addobject LOCALID_BRENDAN
	delay 16
	applymovement LOCALID_BRENDAN, EverGrandePeak_Movement_BrendanWalkOnScreen
	waitmovement 0
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, EverGrandePeak_Movement_PlayerNoticeRival
	waitmovement 0
	delay 16
	playbgm MUS_ENCOUNTER_BRENDAN, FALSE
	applymovement OBJ_EVENT_ID_PLAYER, EverGrandePeak_Movement_PlayerWalkToRival
	waitmovement 0
	delay 8
	speakername NULL
	msgbox EverGrandePeak_Text_YouLockEyes, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_P_BRENDAN_FINAL, EverGrandePeak_Text_BrendanDefeated
	goto EverGrandePeak_EventScript_ShunyongAwakens
	release
	end

EverGrandePeak_Movement_MayWalkOnScreen:
	walk_right
	walk_up
	walk_up
	step_end

EverGrandePeak_Movement_BrendanWalkOnScreen:
	walk_left
	walk_up
	walk_up
	step_end

EverGrandePeak_Movement_PlayerNoticeRival:
	face_down
	emote_exclamation_mark
	step_end

EverGrandePeak_Movement_PlayerWalkToRival:
	walk_down
	walk_down
	step_end

EverGrandePeak_EventScript_ShunyongAwakens::
	playbgm MUS_NONE, FALSE
	msgbox EverGrandePeak_Text_HardFoughtVictory, MSGBOX_DEFAULT
	closemessage
	turnobject LOCALID_WALLACE, DIR_NORTH
	turnobject LOCALID_STEVEN, DIR_NORTH
	delay 16
	special SpawnCameraObject
	delay 16
	applymovement OBJ_EVENT_ID_CAMERA, EverGrandePeak_Movement_CameraPanUp
	waitmovement 0
	pike_flashscreen
	playse SE_INTRO_BLAST
	pike_flashscreen
	waitse
	delay 16
	pike_flashscreen
	special HealPlayerParty
	playmoncry SPECIES_SHUNYONG, CRY_MODE_NORMAL
	waitmoncry
	delay 8
	warp MAP_SHUNYONG_BATTLE_ARENA, 4, 7
	waitstate
	release
	end

EverGrandePeak_Movement_CameraPanUp:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

EverGrandePeak_EventScripts_ShunyongTest::
	lock
	doshunyongbattle
	release
	end

EverGrandePeak_Text_NameWallace:
	.string "$"

EverGrandePeak_Text_NameSteven:
	.string "$"

EverGrandePeak_Text_Welcome:
	.string "$"

EverGrandePeak_Text_YouveDoneWell:
	.string "$"

EverGrandePeak_Text_DoYouHaveTheOrbs:
	.string "$"

EverGrandePeak_Text_OneLastTest:
	.string "$"

EverGrandePeak_Text_WallaceDefeat:
	.string "$"

EverGrandePeak_Text_StevenDefeat:
	.string "$"

EverGrandePeak_Text_YouAreWorthy:
	.string "$"

EverGrandePeak_Text_TakeTheOrbsToTheirShrines:
	.string "$"

EverGrandePeak_Text_WeWillBeWaiting:
	.string "$"

EverGrandePeak_Text_HighestPoint:
	.string "$"

EverGrandePeak_Text_ShayonShrineOrbSet:
	.string "$"

EverGrandePeak_Text_LowestPoint:
	.string "$"

EverGrandePeak_Text_LuoshanShrineOrbSet:
	.string "$"

EverGrandePeak_Text_BothOrbsSet:
	.string "$"

EverGrandePeak_Text_IFeelTheOrbsPower:
	.string "$"

EverGrandePeak_Text_OneMoreThingToDo:
	.string "$"

EverGrandePeak_Text_YouLockEyes:
	.string "$"

EverGrandePeak_Text_MayDefeated:
	.string "$"

EverGrandePeak_Text_BrendanDefeated:
	.string "$"

EverGrandePeak_Text_HardFoughtVictory:
	.string "$"
