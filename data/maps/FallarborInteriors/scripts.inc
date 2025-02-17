FallarborInteriors_MapScripts::
	.byte 0

FallarborInteriors_EventScript_Trader::
	lock
	faceplayer
	goto_if_set FLAG_RAITAIC_TRADE_COMPLETED, FallarborInteriors_EventScript_TradeCompleted
	setvar VAR_0x8008, INGAME_TRADE_RAITAIC
	copyvar VAR_0x8004, VAR_0x8008
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
	copyvar VAR_0x8009, VAR_RESULT
	msgbox FallarborInteriors_Text_IllTradeIfYouWant, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, FallarborInteriors_EventScript_DeclineTrade
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, FallarborInteriors_EventScript_DeclineTrade
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	goto_if_ne VAR_RESULT, VAR_0x8009, FallarborInteriors_EventScript_NotRequestedMon
	copyvar VAR_0x8004, VAR_0x8008
	copyvar VAR_0x8005, VAR_0x800A
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	waitstate
	msgbox FallarborInteriors_Text_PleaseBeGoodToMyPokemon, MSGBOX_DEFAULT
	setflag FLAG_RAITAIC_TRADE_COMPLETED
	release
	end

FallarborInteriors_EventScript_DeclineTrade::
	msgbox FallarborInteriors_Text_YouDontWantToThatsOkay, MSGBOX_DEFAULT
	release
	end

FallarborInteriors_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox FallarborInteriors_Text_DoesntLookLikeMonToMe, MSGBOX_DEFAULT
	release
	end

FallarborInteriors_EventScript_TradeCompleted::
	msgbox FallarborInteriors_Text_ThanksForTrading, MSGBOX_DEFAULT
	release
	end

FallarborInteriors_Text_IllTradeIfYouWant:
	.string "I'll trade you my {STR_VAR_2} for\n"
	.string "a {STR_VAR_1} if you want.$"

FallarborInteriors_Text_PleaseBeGoodToMyPokemon:
	.string "Please be good to my POKéMON.$"

FallarborInteriors_Text_DoesntLookLikeMonToMe:
	.string "Huh? That doesn't look anything like\n"
	.string "a {STR_VAR_1} to me.$"

FallarborInteriors_Text_YouDontWantToThatsOkay:
	.string "Oh, if you don't want to, that's okay.$"

FallarborInteriors_Text_ThanksForTrading:
	.string "Thanks for the trade.$"
