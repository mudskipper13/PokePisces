MeteorNadir_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, MeteorNadir_OnLoad
	.byte 0

MeteorNadir_OnLoad:
	call_if_set FLAG_DEFEATED_LUO_KYO, MeteorNadir_EventScript_RemoveLuoKyo
	end

MeteorNadir_EventScript_RemoveLuoKyo::
	setvar VAR_TEMP_4, 1
	setmetatile 24, 10, METATILE_Underwater_SeaBottom, FALSE
	setmetatile 25, 10, METATILE_Underwater_SeaBottom, FALSE
	setmetatile 24, 11, METATILE_Underwater_SeaBottom, FALSE
	setmetatile 25, 11, METATILE_Underwater_SeaBottom, FALSE
	setmetatile 27, 10, METATILE_Underwater_SeaBottom, FALSE
	setmetatile 28, 10, METATILE_Underwater_SeaBottom, FALSE
	setmetatile 27, 11, METATILE_Underwater_SeaBottom, FALSE
	setmetatile 28, 11, METATILE_Underwater_SeaBottom, FALSE
	special DrawWholeMapView
	return

MeteorNadir_EventScript_LegendaryEncounter::
	lock
	msgbox MeteorNadir_Text_TheyreFighting, MSGBOX_DEFAULT
	closemessage
	playmoncry SPECIES_LUOSHAN, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	playmoncry SPECIES_KYOGRE, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	msgbox MeteorNadir_Text_TimeToStepIn, MSGBOX_DEFAULT
	closemessage
	setwildbattle SPECIES_LUOSHAN, 80, ITEM_NONE, SPECIES_KYOGRE, 80, ITEM_NONE
	setflag FLAG_WILD_NO_CATCHING_FLAG
	setflag FLAG_WILD_NO_RUNNING_FLAG
	setflag FLAG_SMART_WILD_AI_FLAG
	delay 4
	dowildbattle
	delay 8
	clearflag FLAG_WILD_NO_CATCHING_FLAG
	clearflag FLAG_WILD_NO_RUNNING_FLAG
	clearflag FLAG_SMART_WILD_AI_FLAG
	playmoncry SPECIES_LUOSHAN, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	playmoncry SPECIES_KYOGRE, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	msgbox MeteorNadir_Text_BreakThemUp, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_DEFEATED_LUO_KYO
	delay 16
	setvar VAR_NEW_COO_STATE, 8
	warp MAP_METEOR_NADIR, 26, 14
	waitstate
	release
	end

MeteorNadir_Text_TheyreFighting:
	.string "$"

MeteorNadir_Text_TimeToStepIn:
	.string "$"

MeteorNadir_Text_BreakThemUp:
	.string "$"
