LilycoveCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LilycoveCity_OnTransition
	.byte 0

LilycoveCity_OnTransition:
	setflag FLAG_VISITED_LILYCOVE_CITY
	call_if_ge VAR_NOTICED_BY_YANDEMIC, 5, LilycoveCity_EventScript_RemoveYandemic
	end

LilycoveCity_EventScript_RemoveYandemic::
	removeobject LOCALID_YANDEMIC
	setflag FLAG_TEMP_11
	return

LilycoveCity_EventScript_FalseSwipeGiver::
	lock
	faceplayer
	checkitem ITEM_TM_FALSE_SWIPE
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_EventScript_GaveFalseSwipe
	setvar VAR_0x8004, 0
	specialvar VAR_RESULT, ScriptGetPokedexInfo
	copyvar VAR_0x8008, VAR_0x8005
	copyvar VAR_0x8009, VAR_0x8006
	copyvar VAR_0x800A, VAR_RESULT
	buffernumberstring STR_VAR_1, VAR_0x8008
	buffernumberstring STR_VAR_2, VAR_0x8009
	goto_if_gt VAR_0x8009, 39, LilycoveCity_EventScript_GiveFalseSwipe
	msgbox LilycoveCity_Text_WantToSee40CaughtMons, MSGBOX_AUTOCLOSE
	release
	end

LilycoveCity_EventScript_GiveFalseSwipe::
	msgbox LilycoveCity_Text_LotsOfCaughtMons, MSGBOX_DEFAULT
	giveitem ITEM_TM_FALSE_SWIPE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	release
	end

LilycoveCity_EventScript_GaveFalseSwipe::
	msgbox LilycoveCity_Text_GaveFS, MSGBOX_AUTOCLOSE
	release
	end

LilycoveCity_EventScript_ThisIsMyWorkplace::
	msgbox LilycoveCity_Text_ThisIsMyWorkplace, MSGBOX_NPC
	end

LilycoveCity_EventScript_YandemicNoticed::
	lock
	setvar VAR_TEMP_4, 1
	call_if_lt VAR_NOTICED_BY_YANDEMIC, 4, LilycoveCity_EventScript_YandemicAddVar
	msgbox MossdeepCity_Text_YouFeelWatched, MSGBOX_AUTOCLOSE
	release
	end

LilycoveCity_EventScript_YandemicAddVar::
	addvar VAR_NOTICED_BY_YANDEMIC, 1
	return

LilycoveCity_Text_YouFeelWatched:
	.string "(You begin to notice that\n"
	.string "you are being intently watched...)$"

LilycoveCity_Text_ThisIsMyWorkplace:
	.string "This here is my workplace! The\n"
	.string "Ozone Lilycove Branch HQ.\p"
	.string "Or as most of us call it,\n"
	.string "the Ol' Bihq.\p"
	.string "It sounds a lot better if you say it\n"
	.string "with a southern drawl!$"

LilycoveCity_Text_WantToSee40CaughtMons:
	.string "i wanna see 40 caught$"

LilycoveCity_Text_LotsOfCaughtMons:
	.string "wow u caught 40 mons$"

LilycoveCity_Text_GaveFS:
	.string "gave u FS already$"
