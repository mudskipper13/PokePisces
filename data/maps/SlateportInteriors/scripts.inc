SlateportInteriors_MapScripts::
	.byte 0

SlateportInteriors_EventScript_FanClubChairman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_POKE_FLUTE, SlateportInteriors_EventScript_FanClubChairmanPostFlute
	checkitem ITEM_TEACHY_TV
	goto_if_eq VAR_RESULT, TRUE, SlateportInteriors_EventScript_PokeFluteSpiel
	msgbox SlateportInteriors_Text_ILovePrimo, MSGBOX_AUTOCLOSE
	release
	end

SlateportInteriors_EventScript_PokeFluteSpiel::
	msgbox SlateportInteriors_Text_WhyItsATeachyTV, MSGBOX_DEFAULT
	playbgm MUS_RG_TEACHY_TV_MENU, FALSE
	msgbox SlateportInteriors_Text_PrimoAndFluteStory, MSGBOX_DEFAULT
	fadenewbgm MUS_SLATEPORT
	delay 32
	msgbox SlateportInteriors_Text_AnywaysLetsTrade, MSGBOX_DEFAULT
	removeitem ITEM_TEACHY_TV, 1
	giveitem ITEM_POKE_FLUTE
	setflag FLAG_RECEIVED_POKE_FLUTE
	closemessage
	release
	end

SlateportInteriors_EventScript_FanClubChairmanPostFlute::
	msgbox SlateportInteriors_Text_ILoveMyNewTV, MSGBOX_AUTOCLOSE
	release
	end

SlateportInteriors_EventScript_Trader::
	lock
	faceplayer
	goto_if_set FLAG_MOTHRAMITY_TRADE_COMPLETED, SlateportInteriors_EventScript_TradeCompleted
	setvar VAR_0x8008, INGAME_TRADE_MOTHRAMITY
	copyvar VAR_0x8004, VAR_0x8008
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
	copyvar VAR_0x8009, VAR_RESULT
	msgbox SlateportInteriors_Text_IllTradeIfYouWant, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SlateportInteriors_EventScript_DeclineTrade
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, SlateportInteriors_EventScript_DeclineTrade
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	goto_if_ne VAR_RESULT, VAR_0x8009, SlateportInteriors_EventScript_NotRequestedMon
	copyvar VAR_0x8004, VAR_0x8008
	copyvar VAR_0x8005, VAR_0x800A
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	waitstate
	msgbox SlateportInteriors_Text_PleaseBeGoodToMyPokemon, MSGBOX_DEFAULT
	setflag FLAG_MOTHRAMITY_TRADE_COMPLETED
	release
	end

SlateportInteriors_EventScript_DeclineTrade::
	msgbox SlateportInteriors_Text_YouDontWantToThatsOkay, MSGBOX_DEFAULT
	release
	end

SlateportInteriors_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox SlateportInteriors_Text_DoesntLookLikeMonToMe, MSGBOX_DEFAULT
	release
	end

SlateportInteriors_EventScript_TradeCompleted::
	msgbox SlateportInteriors_Text_ThanksForTrading, MSGBOX_DEFAULT
	release
	end

SlateportInteriors_Text_IllTradeIfYouWant:
	.string "I'll trade you my {STR_VAR_2} for\n"
	.string "a {STR_VAR_1} if you want.$"

SlateportInteriors_Text_PleaseBeGoodToMyPokemon:
	.string "Please be good to my POKéMON.$"

SlateportInteriors_Text_DoesntLookLikeMonToMe:
	.string "Huh? That doesn't look anything like\n"
	.string "a {STR_VAR_1} to me.$"

SlateportInteriors_Text_YouDontWantToThatsOkay:
	.string "Oh, if you don't want to, that's okay.$"

SlateportInteriors_Text_ThanksForTrading:
	.string "Thanks for the trade.$"

SlateportInteriors_Text_ILovePrimo:
	.string "I say, as the chairman of the club,\n"
	.string "things have rather changed\l"
	.string "over the years!\p"
	.string "Nowadays, these younger inductees\n"
	.string "are really into their\l"
	.string "Pokemon cards and whatnot.\p"
	.string "But during the club's heyday?\n"
	.string "Primo's program on the Teachy TV\l"
	.string "was all the rage...!\p"
	.string "I'm still a diehard fan.\n"
	.string "If only I hadn't lost my vintage\l"
	.string "Teachy TV Set from years ago...$"

SlateportInteriors_Text_WhyItsATeachyTV:
	.string "!\n"
	.string "W-Why, it's a mint condition...\l"
	.string "...T-T-TEACHY TV SET!!!$"

SlateportInteriors_Text_PrimoAndFluteStory:
	.string "We share a kindred love for\n"
	.string "the program, you and I!\p"
	.string "Golly, my favorite episode is\n"
	.string "loaded onto here. Surely you\l"
	.string "remember “Unbolt The Rock”?\l"
	.string "It's a veritable CLASSIC.\p"
	.string "Our suave, handsome hero Primo\n"
	.string "has his path to the next city\l"
	.string "blocked by a ginormous\l"
	.string "sleeping Bolterock!\p"
	.string "OH, WHAT IS HE TO DO!?\p"
	.string "As it just so happens, in the\n"
	.string "nearby ruins is an instumental\l"
	.string "instrument; the Poke Flute.\l"
	.string "Said to awake any sleeper,\l"
	.string "no matter how giant.\p"
	.string "Primo, intelligent as ever,\n"
	.string "brings the Flute back to\l"
	.string "the Bolterock and awakens it.\p"
	.string "A fierce, drawn out battle begins\n"
	.string "between the roused creature\l"
	.string "and the hero's ragtag team...\l"
	.string "and they narrowly escape with\l"
	.string "the victory.\p"
	.string "I get goosebumps just recalling it!\n"
	.string "My stars...$"

SlateportInteriors_Text_AnywaysLetsTrade:
	.string "...Mm. I could ramble on, but let\n"
	.string "me officially trade you something\l"
	.string "equally valuable for the TV Set.\p"
	.string "It just so happens I own a second,\n"
	.string "no-longer-for-sale replica of\l"
	.string "the Poke Flute used in the show!\p"
	.string "Please, I insist on a superfan\n"
	.string "like you to give it a good home.$"

SlateportInteriors_Text_ILoveMyNewTV:
	.string "I have been binge-watching the\n"
	.string "whole Primo series on the\l"
	.string "TV Set you traded me, friend.\p"
	.string "Almost at the mid-season 19 finale,\n"
	.string "“Blinguin Gets Shot By The CIA”!\p"
	.string "It was controversial at the time.$"
