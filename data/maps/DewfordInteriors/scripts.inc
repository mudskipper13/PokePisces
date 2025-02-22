DewfordInteriors_MapScripts::
	.byte 0

DewfordInteriors_EventScript_Trader::
	lock
	faceplayer
	goto_if_set FLAG_GLAREYALE_TRADE_COMPLETED, DewfordInteriors_EventScript_TradeCompleted
	setvar VAR_0x8008, INGAME_TRADE_GLAREYALE
	copyvar VAR_0x8004, VAR_0x8008
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
	copyvar VAR_0x8009, VAR_RESULT
	msgbox DewfordInteriors_Text_IllTradeIfYouWant, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, DewfordInteriors_EventScript_DeclineTrade
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, DewfordInteriors_EventScript_DeclineTrade
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	goto_if_ne VAR_RESULT, VAR_0x8009, DewfordInteriors_EventScript_NotRequestedMon
	copyvar VAR_0x8004, VAR_0x8008
	copyvar VAR_0x8005, VAR_0x800A
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	waitstate
	msgbox DewfordInteriors_Text_PleaseBeGoodToMyPokemon, MSGBOX_DEFAULT
	setflag FLAG_GLAREYALE_TRADE_COMPLETED
	release
	end

DewfordInteriors_EventScript_DeclineTrade::
	msgbox DewfordInteriors_Text_YouDontWantToThatsOkay, MSGBOX_DEFAULT
	release
	end

DewfordInteriors_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox DewfordInteriors_Text_DoesntLookLikeMonToMe, MSGBOX_DEFAULT
	release
	end

DewfordInteriors_EventScript_TradeCompleted::
	msgbox DewfordInteriors_Text_ThanksForTrading, MSGBOX_DEFAULT
	release
	end

DewfordInteriors_Text_IllTradeIfYouWant:
	.string "I'll trade you my {STR_VAR_2} for\n"
	.string "a {STR_VAR_1} if you want.$"

DewfordInteriors_Text_PleaseBeGoodToMyPokemon:
	.string "Please be good to my POKéMON.$"

DewfordInteriors_Text_DoesntLookLikeMonToMe:
	.string "Huh? That doesn't look anything like\n"
	.string "a {STR_VAR_1} to me.$"

DewfordInteriors_Text_YouDontWantToThatsOkay:
	.string "Oh, if you don't want to, that's okay.$"

DewfordInteriors_Text_ThanksForTrading:
	.string "Thanks for the trade.$"
