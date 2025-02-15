MaintenanceBondingArena_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, MaintenanceBondingArena_OnLoad
	.byte 0

MaintenanceBondingArena_OnLoad:
	call_if_ge VAR_NEW_MAUVILLE_STATE, 2, MaintenanceBondingArena_EventScript_DarkRoom
	call MaintenanceBondingArena_EventScript_TerminalCheck
	end

MaintenanceBondingArena_EventScript_DarkRoom::
	setflashlevel 4
	setmetatile 6, 3, METATILE_BattleFactory_CordelictOff, TRUE
	special DrawWholeMapView
	return

MaintenanceBondingArena_EventScript_TerminalCheck::
	getcaughtmon SPECIES_CORDELICT
	goto_if_eq VAR_RESULT, TRUE, MaintenanceBondingArena_EventScript_RemoveTerminal
	return

MaintenanceBondingArena_EventScript_RemoveTerminal::
	setvar VAR_TEMP_4, 1
	setmetatile 6, 2, METATILE_BattleFactory_CordlecitGone1, FALSE
	setmetatile 6, 3, METATILE_BattleFactory_CordelictGone2, FALSE
	setmetatile 6, 4, METATILE_BattleFactory_CordelictGone3, FALSE
	special DrawWholeMapView
	return

MaintenanceBondingArena_EventScript_Cordelict::
	lock
	goto_if_eq VAR_TEMP_4, 1, MaintenanceBondingArena_EventScript_CordelictGone
	goto_if_eq VAR_NEW_MAUVILLE_STATE, 3, MaintenanceBondingArena_EventScript_CordelictRematch
	goto_if_eq VAR_NEW_MAUVILLE_STATE, 2, MaintenanceBondingArena_EventScript_CordelictBattle
	goto_if_set FLAG_TEMP_A, MaintenanceBondingArena_EventScript_CordelictRepeatInstructions
	playse SE_PC_LOGIN
	msgbox MaintenanceBondingArena_Text_ConsoleIsOpen, MSGBOX_DEFAULT
	setflag FLAG_TEMP_A
	playse SE_PC_ON
	speakername MaintenanceBondingArena_Text_NameSYS
	msgbox MaintenanceBondingArena_Text_TurnOffGenerator, MSGBOX_DEFAULT
	closemessage
	playse SE_PC_OFF
	waitse
	release
	end

MaintenanceBondingArena_EventScript_CordelictRepeatInstructions::
	playse SE_PC_ON
	speakername MaintenanceBondingArena_Text_NameSYS
	msgbox MaintenanceBondingArena_Text_GoToGenerator, MSGBOX_DEFAULT
	closemessage
	playse SE_PC_OFF
	waitse
	release
	end

MaintenanceBondingArena_EventScript_CordelictBattle::
	setmetatile 6, 3, METATILE_BattleFactory_CordelictTurnOn1, TRUE
	special DrawWholeMapView
	delay 8
	setmetatile 6, 3, METATILE_BattleFactory_CordelictTurnOn2, TRUE
	special DrawWholeMapView
	delay 8
	playse SE_PC_LOGIN
	setmetatile 6, 3, METATILE_BattleFactory_CordelictFace1, TRUE
	special DrawWholeMapView
	delay 4
	setmetatile 6, 3, METATILE_BattleFactory_CordelictFace2, TRUE
	special DrawWholeMapView
	delay 4
	setmetatile 6, 3, METATILE_BattleFactory_CordelictFace1, TRUE
	special DrawWholeMapView
	delay 4
	speakername MaintenanceBondingArena_Text_NameSYS
	msgbox MaintenanceBondingArena_Text_YouFool, MSGBOX_DEFAULT
	setwildbattle SPECIES_CORDELICT, 47
	setflag FLAG_WILD_NO_RUNNING_FLAG
	setflag FLAG_SMART_WILD_AI_FLAG
	playmoncry SPECIES_CORDELICT, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	dowildbattle
	delay 16
	clearflag FLAG_WILD_NO_RUNNING_FLAG
	clearflag FLAG_SMART_WILD_AI_FLAG
	setvar VAR_NEW_MAUVILLE_STATE, 3
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, MaintenanceBondingArena_EventScript_CordelictCaught
	setmetatile 6, 3, METATILE_BattleFactory_CordelictOff, TRUE
	special DrawWholeMapView
	speakername NULL
	msgbox MaintenanceBondingArena_Text_ItsStoppedForNow, MSGBOX_DEFAULT
	closemessage
	release
	end

MaintenanceBondingArena_EventScript_CordelictCaught::
	setvar VAR_TEMP_4, 1
	setmetatile 6, 2, METATILE_BattleFactory_CordlecitGone1, FALSE
	setmetatile 6, 3, METATILE_BattleFactory_CordelictGone2, FALSE
	setmetatile 6, 4, METATILE_BattleFactory_CordelictGone3, FALSE
	special DrawWholeMapView
	release
	end

MaintenanceBondingArena_EventScript_CordelictRematch::
	setmetatile 6, 3, METATILE_BattleFactory_CordelictTurnOn1, TRUE
	special DrawWholeMapView
	delay 8
	setmetatile 6, 3, METATILE_BattleFactory_CordelictTurnOn2, TRUE
	special DrawWholeMapView
	delay 8
	playse SE_PC_LOGIN
	setmetatile 6, 3, METATILE_BattleFactory_CordelictFace1, TRUE
	special DrawWholeMapView
	delay 4
	setmetatile 6, 3, METATILE_BattleFactory_CordelictFace2, TRUE
	special DrawWholeMapView
	delay 4
	setmetatile 6, 3, METATILE_BattleFactory_CordelictFace1, TRUE
	special DrawWholeMapView
	delay 4
	speakername MaintenanceBondingArena_Text_NameSYS
	msgbox MaintenanceBondingArena_Text_AgainYouFool, MSGBOX_DEFAULT
	setwildbattle SPECIES_CORDELICT, 47
	setflag FLAG_WILD_NO_RUNNING_FLAG
	setflag FLAG_SMART_WILD_AI_FLAG
	playmoncry SPECIES_CORDELICT, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	dowildbattle
	delay 16
	clearflag FLAG_WILD_NO_RUNNING_FLAG
	clearflag FLAG_SMART_WILD_AI_FLAG
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, MaintenanceBondingArena_EventScript_CordelictCaught
	setmetatile 6, 3, METATILE_BattleFactory_CordelictOff, TRUE
	special DrawWholeMapView
	speakername NULL
	msgbox MaintenanceBondingArena_Text_ItsStoppedForNow, MSGBOX_DEFAULT
	closemessage
	release
	end

MaintenanceBondingArena_EventScript_CordelictGone::
	speakername NULL
	msgbox MaintenanceBondingArena_Text_TheTerminalIsGone, MSGBOX_AUTOCLOSE
	release
	end

MaintenanceBondingArena_Text_NameSYS:
	.string "SYS$"

MaintenanceBondingArena_Text_ConsoleIsOpen:
	.string "its a terminal$"

MaintenanceBondingArena_Text_TurnOffGenerator:
	.string "turn off generator plz$"

MaintenanceBondingArena_Text_GoToGenerator:
	.string "go to dat genny$"

MaintenanceBondingArena_Text_YouFool:
	.string "haha fooled u, die$"

MaintenanceBondingArena_Text_ItsStoppedForNow:
	.string "its stopped 4 now$"

MaintenanceBondingArena_Text_AgainYouFool:
	.string "again??? time for more der$"

MaintenanceBondingArena_Text_TheTerminalIsGone:
	.string "cordelict has been caught$"
