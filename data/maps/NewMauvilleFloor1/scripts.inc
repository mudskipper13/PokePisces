.set LOCALID_P_MAN, 4

NewMauvilleFloor1_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, NewMauvilleFloor1_OnLoad
	.byte 0

NewMauvilleFloor1_OnLoad:
	call_if_gt VAR_OLD_GUYS_STATE, 0, NewMauvilleFloor1_EventScript_RemovePowerlessMan
	call_if_lt VAR_OLD_GUYS_STATE, 15, NewMauvilleFloor1_EventScript_CloseElevator
	end

NewMauvilleFloor1_EventScript_RemovePowerlessMan::
	removeobject LOCALID_P_MAN
	setflag FLAG_TEMP_11
	return

NewMauvilleFloor1_EventScript_CloseElevator::
	setmetatile 46, 2, METATILE_Shop_MaintenanceDoorLocked, TRUE
	special DrawWholeMapView
	return

NewMauvilleFloor1_EventScript_PowerlessManTrigger1::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, NewMauvilleFloor1_Movement_PlayerGetIntoPos1
	goto NewMauvilleFloor1_EventScript_PowerlessManEvent
	releaseall
	end

NewMauvilleFloor1_Movement_PlayerGetIntoPos1:
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	step_end

NewMauvilleFloor1_EventScript_PowerlessManTrigger2::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, NewMauvilleFloor1_Movement_PlayerGetIntoPos2
	goto NewMauvilleFloor1_EventScript_PowerlessManEvent
	releaseall
	end

NewMauvilleFloor1_Movement_PlayerGetIntoPos2:
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	step_end

NewMauvilleFloor1_EventScript_PowerlessManTrigger3::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, NewMauvilleFloor1_Movement_PlayerGetIntoPos3
	goto NewMauvilleFloor1_EventScript_PowerlessManEvent
	releaseall
	end

NewMauvilleFloor1_Movement_PlayerGetIntoPos3:
	walk_right
	walk_right
	walk_right
	face_down
	step_end

NewMauvilleFloor1_EventScript_PowerlessManEvent::
	applymovement LOCALID_P_MAN, NewMauvilleFloor1_Movement_PManPassby
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_P_MAN, NewMauvilleFloor1_Movement_PManNotice
	waitmovement 0
	msgbox NewMauvilleFloor1_Text_ItsYouFromTheTidal, MSGBOX_DEFAULT
	applymovement OBJ_EVENT_ID_PLAYER, NewMauvilleFloor1_Movement_PlayerJoinUp
	applymovement LOCALID_P_MAN, NewMauvilleFloor1_Movement_PManJoinUp
	speakername NewMauvilleFloor1_Text_NameKizuna
	msgbox NewMauvilleFloor1_Text_AboutWattsonAndMauville, MSGBOX_DEFAULT
	speakername NULL
	closemessage
	applymovement LOCALID_P_MAN, NewMauvilleFloor1_Movement_PManGoToElevator
	waitmovement 0
	playse SE_EXIT
	removeobject LOCALID_P_MAN
	setflag FLAG_TEMP_11
	setflag FLAG_VISITED_MAUVILLE_CITY
	setvar VAR_OLD_GUYS_STATE, 1
	releaseall
	end

NewMauvilleFloor1_Movement_PManPassby:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

NewMauvilleFloor1_Movement_PManNotice:
	emote_exclamation_mark
	delay_16
	delay_16
	face_down
	step_end

NewMauvilleFloor1_Movement_PlayerJoinUp:
	walk_up
	step_end

NewMauvilleFloor1_Movement_PManJoinUp:
	walk_right
	walk_down
	step_end

NewMauvilleFloor1_Movement_PManGoToElevator:
	walk_left
	walk_up
	step_end

NewMauvilleFloor1_EventScript_Roy::
    trainerbattle_single TRAINER_P_ROY, NewMauvilleFloor1_Text_RoyIntro, NewMauvilleFloor1_Text_RoyDefeated
    msgbox NewMauvilleFloor1_Text_RoyPostBattle, MSGBOX_AUTOCLOSE
    end

NewMauvilleFloor1_EventScript_McKayleigh::
    trainerbattle_single TRAINER_P_MCKAYLEIGH, NewMauvilleFloor1_Text_McKayleighIntro, NewMauvilleFloor1_Text_McKayleighDefeated
    msgbox NewMauvilleFloor1_Text_McKayleighPostBattle, MSGBOX_AUTOCLOSE
    end

NewMauvilleFloor1_EventScript_Aiden::
    trainerbattle_single TRAINER_P_AIDEN, NewMauvilleFloor1_Text_AidenIntro, NewMauvilleFloor1_Text_AidenDefeated
    msgbox NewMauvilleFloor1_Text_AidenPostBattle, MSGBOX_AUTOCLOSE
    end

NewMauvilleFloor1_EventScript_Trader::
	lock
	faceplayer
	goto_if_set FLAG_NYARLY_TRADE_COMPLETED, NewMauvilleFloor1_EventScript_TradeCompleted
	setvar VAR_0x8008, INGAME_TRADE_NYARLY
	copyvar VAR_0x8004, VAR_0x8008
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
	copyvar VAR_0x8009, VAR_RESULT
	msgbox NewMauvilleFloor1_Text_IllTradeIfYouWant, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, NewMauvilleFloor1_EventScript_DeclineTrade
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, NewMauvilleFloor1_EventScript_DeclineTrade
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	goto_if_ne VAR_RESULT, VAR_0x8009, NewMauvilleFloor1_EventScript_NotRequestedMon
	copyvar VAR_0x8004, VAR_0x8008
	copyvar VAR_0x8005, VAR_0x800A
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	waitstate
	msgbox NewMauvilleFloor1_Text_PleaseBeGoodToMyPokemon, MSGBOX_DEFAULT
	setflag FLAG_NYARLY_TRADE_COMPLETED
	release
	end

NewMauvilleFloor1_EventScript_DeclineTrade::
	msgbox NewMauvilleFloor1_Text_YouDontWantToThatsOkay, MSGBOX_DEFAULT
	release
	end

NewMauvilleFloor1_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox NewMauvilleFloor1_Text_DoesntLookLikeMonToMe, MSGBOX_DEFAULT
	release
	end

NewMauvilleFloor1_EventScript_TradeCompleted::
	msgbox NewMauvilleFloor1_Text_ThanksForTrading, MSGBOX_DEFAULT
	release
	end

NewMauvilleFloor1_Text_IllTradeIfYouWant:
	.string "I'll trade you my {STR_VAR_2} for\n"
	.string "a {STR_VAR_1} if you want.$"

NewMauvilleFloor1_Text_PleaseBeGoodToMyPokemon:
	.string "Please be good to my POKéMON.$"

NewMauvilleFloor1_Text_DoesntLookLikeMonToMe:
	.string "Huh? That doesn't look anything like\n"
	.string "a {STR_VAR_1} to me.$"

NewMauvilleFloor1_Text_YouDontWantToThatsOkay:
	.string "Oh, if you don't want to, that's okay.$"

NewMauvilleFloor1_Text_ThanksForTrading:
	.string "Thanks for the trade.$"

NewMauvilleFloor1_Text_NameKizuna:
	.string "Kizuna$"

NewMauvilleFloor1_Text_RoyIntro:
	.string "intro$"

NewMauvilleFloor1_Text_RoyDefeated:
	.string "defeat$"

NewMauvilleFloor1_Text_RoyPostBattle:
	.string "post$"

NewMauvilleFloor1_Text_McKayleighIntro:
	.string "intro$"

NewMauvilleFloor1_Text_McKayleighDefeated:
	.string "defeat$"

NewMauvilleFloor1_Text_McKayleighPostBattle:
	.string "post$"

NewMauvilleFloor1_Text_AidenIntro:
	.string "intro$"

NewMauvilleFloor1_Text_AidenDefeated:
	.string "defeat$"

NewMauvilleFloor1_Text_AidenPostBattle:
	.string "post$"

NewMauvilleFloor1_Text_ItsYouFromTheTidal:
	.string "Oh! Hey, there!\p"
	.string "You, uh... might not remember me.\n"
	.string "I do look a bit... unremarkable,\l"
	.string "but I remember you! We were on\l"
	.string "the S.S. Tidal together!$"

NewMauvilleFloor1_Text_AboutWattsonAndMauville:
	.string "To formally introduce myself,\n"
	.string "my name is Kizuna. I'm a\l"
	.string "middle manager for Devo-...\l"
	.string "I mean, Greater Mauville Holdings.\p"
	.string "You had said you were going to\n"
	.string "embark on a journey to get every\l"
	.string "gym badge in Hoenn, right?\l"
	.string "It figures you would find yourself\l"
	.string "here in New Mauville.\p"
	.string "...Yes, it USED to be just\n"
	.string "Mauville City. But Wattson and\l"
	.string "his company basically bulldozed\l"
	.string "the old city and built this\l"
	.string "megastructure on top. Silly\l"
	.string "to change the name, I know, but\l"
	.string "that's just the kind of guy he is.\p"
	.string "He's still the gym leader here.\n"
	.string "Well, mostly only in name. He's\l"
	.string "a 'very busy man', so he claims,\l"
	.string "so he has started needing an\l"
	.string "appointment to battle him.\l"
	.string "The waiting list for those\l"
	.string "appointments is pretty long.\p"
	.string "There IS an alternative...\n"
	.string "which, is straight up buying\l"
	.string "the gym badge with cash. You\l"
	.string "can do that in Verdanturf to\l"
	.string "the west, where Wattson relocated\l"
	.string "the gym after the renovations.\p"
	.string "...That's no fun? Yeah, I guess not.\p"
	.string "I... MAY know of another...\n"
	.string "sneakier method. But I haven't\l"
	.string "really tested it.\p"
	.string "If you want to humor me, come meet\n"
	.string "me in my apartment on the\l"
	.string "second floor. If not, that's fine.\l"
	.string "Hope you enjoy your time here!$"
