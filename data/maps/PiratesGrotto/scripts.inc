PiratesGrotto_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, PiratesGrotto_OnLoad
	.byte 0

PiratesGrotto_OnLoad:
	call_if_set FLAG_DEFEATED_GROTTO_SKELLYWARG, PiratesGrotto_EventScript_RemoveSkellywarg
	call_if_gt VAR_ORBS_QUEST_STATE, 5, PiratesGrotto_EventScript_RemoveOrb
	end

PiratesGrotto_EventScript_RemoveSkellywarg::
	setvar VAR_TEMP_4, 1
	setmetatile 6, 4, METATILE_BossCave_GrottoTile, FALSE
	setmetatile 7, 4, METATILE_BossCave_GrottoTile, FALSE
	setmetatile 8, 4, METATILE_BossCave_GrottoTile, FALSE
	setmetatile 6, 5, METATILE_BossCave_GrottoTile, FALSE
	setmetatile 7, 5, METATILE_BossCave_GrottoTile, FALSE
	setmetatile 8, 5, METATILE_BossCave_GrottoTile, FALSE
	special DrawWholeMapView
	return

PiratesGrotto_EventScript_RemoveOrb::
	setflag FLAG_TEMP_A
	return

PiratesGrotto_EventScript_SkellywargTriggerLeft::
	lock
	delay 4
	applymovement OBJ_EVENT_ID_PLAYER, PiratesGrotto_Movement_SkellywargLeft
	waitmovement 0
	goto PiratesGrotto_EventScript_SkellywargBattle
	release
	end

PiratesGrotto_Movement_SkellywargLeft:
	walk_up
	step_end

PiratesGrotto_EventScript_SkellywargTriggerRight::
	lock
	delay 4
	applymovement OBJ_EVENT_ID_PLAYER, PiratesGrotto_Movement_SkellywargRight
	waitmovement 0
	goto PiratesGrotto_EventScript_SkellywargBattle
	release
	end

PiratesGrotto_Movement_SkellywargRight:
	walk_up
	walk_left
	face_up
	step_end

PiratesGrotto_EventScript_SkellywargBattle::
	setwildbattle SPECIES_SKELLYWARG, 40
	settotemboost B_POSITION_OPPONENT_LEFT, 0, 2, 0, 0, 2, 1
	playmoncry SPECIES_SKELLYWARG, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	msgbox PiratesGrotto_Text_BigGhost, MSGBOX_DEFAULT
	setflag FLAG_WILD_NO_CATCHING_FLAG
	setflag FLAG_WILD_NO_RUNNING_FLAG
	setflag FLAG_SMART_WILD_AI_FLAG
	delay 4
	dowildbattle
	delay 8
	clearflag FLAG_WILD_NO_CATCHING_FLAG
	clearflag FLAG_WILD_NO_RUNNING_FLAG
	clearflag FLAG_SMART_WILD_AI_FLAG
	setflag FLAG_DEFEATED_GROTTO_SKELLYWARG
	setvar VAR_TEMP_4, 1
	setmetatile 6, 4, METATILE_BossCave_GrottoTile, FALSE
	setmetatile 7, 4, METATILE_BossCave_GrottoTile, FALSE
	setmetatile 8, 4, METATILE_BossCave_GrottoTile, FALSE
	setmetatile 6, 5, METATILE_BossCave_GrottoTile, FALSE
	setmetatile 7, 5, METATILE_BossCave_GrottoTile, FALSE
	setmetatile 8, 5, METATILE_BossCave_GrottoTile, FALSE
	special DrawWholeMapView
	release
	end

PiratesGrotto_EventScript_ObtainFrostOrb::
	lock
	goto_if_lt VAR_ORBS_QUEST_STATE, 5, PiratesGrotto_EventScript_UselessItem
	msgbox PiratesGrotto_Text_ItsTheFrostOrb, MSGBOX_DEFAULT
	removeobject VAR_LAST_TALKED
	setflag FLAG_TEMP_A
	giveitem ITEM_FROST_ORB
	closemessage
	setvar VAR_ORBS_QUEST_STATE, 6
	delay 16
	playse SE_M_SWORDS_DANCE
	waitse
	playse SE_M_BUBBLE_BEAM2
	msgbox PiratesGrotto_Text_TheMapPointsToMuseum, MSGBOX_AUTOCLOSE
	release
	end

PiratesGrotto_EventScript_UselessItem::
	msgbox PiratesGrotto_Text_UselessItem, MSGBOX_AUTOCLOSE
	release
	end

PiratesGrotto_Text_BigGhost:
	.string "(It's an imposing Ghost Pokemon.)\p"
	.string "(It appears to want to guard\n"
	.string "its hoard of treasure...)$"

PiratesGrotto_Text_UselessItem:
	.string "(A crystal orb of some sort.\n"
	.string "You have no use for this now.)$"

PiratesGrotto_Text_ItsTheFrostOrb:
	.string "(It's the fifth orb that the\n"
	.string "magical map has led you to...\l"
	.string "That Skellywarg took it as\l"
	.string "a part of its hoard.)$"

PiratesGrotto_Text_TheMapPointsToMuseum:
	.string "(Your magical map shines once more,\n"
	.string "pointing you to a new location.)\p"
	.string "(This time, it is leading you\n"
	.string "to the Lilycove Museum...)$"
