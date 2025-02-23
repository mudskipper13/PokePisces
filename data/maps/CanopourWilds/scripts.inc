CanopourWilds_MapScripts::
	.byte 0

CanopourWilds_EventScript_Justin::
    trainerbattle_single TRAINER_P_JUSTIN, CanopourWilds_Text_JustinIntro, CanopourWilds_Text_JustinDefeated
    msgbox CanopourWilds_Text_JustinPostBattle, MSGBOX_AUTOCLOSE
    end

CanopourWilds_EventScript_Juono::
    trainerbattle_single TRAINER_P_JUONO, CanopourWilds_Text_JuonoIntro, CanopourWilds_Text_JuonoDefeated
    msgbox CanopourWilds_Text_JuonoPostBattle, MSGBOX_AUTOCLOSE
    end

CanopourWilds_EventScript_Wallpress::
    trainerbattle_single TRAINER_P_WALLPRESS, CanopourWilds_Text_WallpressIntro, CanopourWilds_Text_WallpressDefeated
    msgbox CanopourWilds_Text_WallpressPostBattle, MSGBOX_AUTOCLOSE
    end

CanopourWilds_EventScript_Tawny::
    trainerbattle_single TRAINER_P_TAWNY, CanopourWilds_Text_TawnyIntro, CanopourWilds_Text_TawnyDefeated
    msgbox CanopourWilds_Text_TawnyPostBattle, MSGBOX_AUTOCLOSE
    end

CanopourWilds_EventScript_Jaiden::
    trainerbattle_single TRAINER_P_JAIDEN, CanopourWilds_Text_JaidenIntro, CanopourWilds_Text_JaidenDefeated
    msgbox CanopourWilds_Text_JaidenPostBattle, MSGBOX_AUTOCLOSE
    end

CanopourWilds_EventScript_Griseldis::
    trainerbattle_single TRAINER_P_GRISELDIS, CanopourWilds_Text_GriseldisIntro, CanopourWilds_Text_GriseldisDefeated
    msgbox CanopourWilds_Text_GriseldisPostBattle, MSGBOX_AUTOCLOSE
    end

CanopourWilds_EventScript_Cameron::
    trainerbattle_single TRAINER_P_CAMERON, CanopourWilds_Text_CameronIntro, CanopourWilds_Text_CameronDefeated
    msgbox CanopourWilds_Text_CameronPostBattle, MSGBOX_AUTOCLOSE
    end

CanopourWilds_EventScript_Flaitine::
    trainerbattle_single TRAINER_P_FLAITINE, CanopourWilds_Text_FlaitineIntro, CanopourWilds_Text_FlaitineDefeated
    msgbox CanopourWilds_Text_FlaitinePostBattle, MSGBOX_AUTOCLOSE
    end

CanopourWilds_EventScript_Jamper::
    trainerbattle_single TRAINER_P_JAMPER, CanopourWilds_Text_JamperIntro, CanopourWilds_Text_JamperDefeated
    msgbox CanopourWilds_Text_JamperPostBattle, MSGBOX_AUTOCLOSE
    end

CanopourWilds_EventScript_Englatere::
    trainerbattle_single TRAINER_P_ENGLATERE, CanopourWilds_Text_EnglatereIntro, CanopourWilds_Text_EnglatereDefeated
    msgbox CanopourWilds_Text_EnglaterePostBattle, MSGBOX_AUTOCLOSE
    end

CanopourWilds_EventScript_Koizumi::
    trainerbattle_single TRAINER_P_KOIZUMI, CanopourWilds_Text_KoizumiIntro, CanopourWilds_Text_KoizumiDefeated
    msgbox CanopourWilds_Text_KoizumiPostBattle, MSGBOX_AUTOCLOSE
    end

CanopourWilds_EventScript_Charli::
    trainerbattle_single TRAINER_P_CHARLI, CanopourWilds_Text_CharliIntro, CanopourWilds_Text_CharliDefeated
    msgbox CanopourWilds_Text_CharliPostBattle, MSGBOX_AUTOCLOSE
    end

CanopourWilds_EventScript_Shamoo::
    trainerbattle_single TRAINER_P_SHAMOO, CanopourWilds_Text_ShamooIntro, CanopourWilds_Text_ShamooDefeated
    msgbox CanopourWilds_Text_ShamooPostBattle, MSGBOX_AUTOCLOSE
    end

CanopourWilds_EventScript_Marisa::
    trainerbattle_single TRAINER_P_MARISA, CanopourWilds_Text_MarisaIntro, CanopourWilds_Text_MarisaDefeated
    msgbox CanopourWilds_Text_MarisaPostBattle, MSGBOX_AUTOCLOSE
    end

CanopourWilds_EventScript_Gunness::
    trainerbattle_single TRAINER_P_GUNNESS, CanopourWilds_Text_GunnessIntro, CanopourWilds_Text_GunnessDefeated
    msgbox CanopourWilds_Text_GunnessPostBattle, MSGBOX_AUTOCLOSE
    end

CanopourWilds_EventScript_Jason::
    trainerbattle_single TRAINER_P_JASON, CanopourWilds_Text_JasonIntro, CanopourWilds_Text_JasonDefeated
    msgbox CanopourWilds_Text_JasonPostBattle, MSGBOX_AUTOCLOSE
    end

CanopourWilds_EventScript_Leah::
    trainerbattle_single TRAINER_P_LEAH, CanopourWilds_Text_LeahIntro, CanopourWilds_Text_LeahDefeated
    msgbox CanopourWilds_Text_LeahPostBattle, MSGBOX_AUTOCLOSE
    end

CanopourWilds_EventScript_Lele::
    trainerbattle_single TRAINER_P_LELE, CanopourWilds_Text_LeleIntro, CanopourWilds_Text_LeleDefeated
    msgbox CanopourWilds_Text_LelePostBattle, MSGBOX_AUTOCLOSE
    end

CanopourWilds_EventScript_PickleLou::
    trainerbattle_single TRAINER_P_PICKLE_LOU, CanopourWilds_Text_PickleLouIntro, CanopourWilds_Text_PickleLouDefeated
    msgbox CanopourWilds_Text_PickleLouPostBattle, MSGBOX_AUTOCLOSE
    end

CanopourWilds_EventScript_Trader::
	lock
	faceplayer
	goto_if_set FLAG_TOXITIDE_TRADE_COMPLETED, CanopourWilds_EventScript_TradeCompleted
	setvar VAR_0x8008, INGAME_TRADE_TOXITIDE
	copyvar VAR_0x8004, VAR_0x8008
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
	copyvar VAR_0x8009, VAR_RESULT
	msgbox CanopourWilds_Text_IllTradeIfYouWant, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, CanopourWilds_EventScript_DeclineTrade
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, CanopourWilds_EventScript_DeclineTrade
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	goto_if_ne VAR_RESULT, VAR_0x8009, CanopourWilds_EventScript_NotRequestedMon
	copyvar VAR_0x8004, VAR_0x8008
	copyvar VAR_0x8005, VAR_0x800A
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	waitstate
	msgbox CanopourWilds_Text_PleaseBeGoodToMyPokemon, MSGBOX_DEFAULT
	setflag FLAG_TOXITIDE_TRADE_COMPLETED
	release
	end

CanopourWilds_EventScript_DeclineTrade::
	msgbox CanopourWilds_Text_YouDontWantToThatsOkay, MSGBOX_DEFAULT
	release
	end

CanopourWilds_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox CanopourWilds_Text_DoesntLookLikeMonToMe, MSGBOX_DEFAULT
	release
	end

CanopourWilds_EventScript_TradeCompleted::
	msgbox CanopourWilds_Text_ThanksForTrading, MSGBOX_DEFAULT
	release
	end

CanopourWilds_Text_IllTradeIfYouWant:
	.string "I'll trade you my {STR_VAR_2} for\n"
	.string "a {STR_VAR_1} if you want.$"

CanopourWilds_Text_PleaseBeGoodToMyPokemon:
	.string "Please be good to my POKéMON.$"

CanopourWilds_Text_DoesntLookLikeMonToMe:
	.string "Huh? That doesn't look anything like\n"
	.string "a {STR_VAR_1} to me.$"

CanopourWilds_Text_YouDontWantToThatsOkay:
	.string "Oh, if you don't want to, that's okay.$"

CanopourWilds_Text_ThanksForTrading:
	.string "Thanks for the trade.$"

CanopourWilds_Text_JustinIntro:
	.string "Hey?! What are you doing?!\p"
	.string "This is MY bug hunting spot!\n"
	.string "Go get your own!$"

CanopourWilds_Text_JustinDefeated:
	.string "Huh! Y-you DIDN'T want to take my\n"
	.string "super awesome secret hiding spot?$"

CanopourWilds_Text_JustinPostBattle:
	.string "Sorry about that. Many of them lil'\n"
	.string "Bug Catcher wannabes keep trying to\l"
	.string "butt in on my turf!$"

CanopourWilds_Text_JuonoIntro:
	.string "Smell that?\n"
	.string "That's the smell of a good roast.$"

CanopourWilds_Text_JuonoDefeated:
	.string "Roasted as black as charcoal...$"

CanopourWilds_Text_JuonoPostBattle:
	.string "You should come eat some at my stall\n"
	.string "sometime.$"

CanopourWilds_Text_WallpressIntro:
	.string "intro$"

CanopourWilds_Text_WallpressDefeated:
	.string "defeat$"

CanopourWilds_Text_WallpressPostBattle:
	.string "post$"

CanopourWilds_Text_TawnyIntro:
	.string "intro$"

CanopourWilds_Text_TawnyDefeated:
	.string "defeat$"

CanopourWilds_Text_TawnyPostBattle:
	.string "post$"

CanopourWilds_Text_JaidenIntro:
	.string "Remember! All Pokémon require one thing\n"
	.string "above all else!\p"
	.string "Can you tell me what that thing is?$"

CanopourWilds_Text_JaidenDefeated:
	.string "Yep, love! They all need love!$"

CanopourWilds_Text_JaidenPostBattle:
	.string "Not showing a Pokémon any love can\n"
	.string "severely stunt their growth.$"

CanopourWilds_Text_GriseldisIntro:
	.string "Delivery!\n"
	.string "Special delivery for you, {PLAYER}!$"

CanopourWilds_Text_GriseldisDefeated:
	.string "There goes my tip...$"

CanopourWilds_Text_GriseldisPostBattle:
	.string "Hang on, I need to take a picture of my\n"
	.string "fainted Pokémon so they know you\l"
	.string "recieved your battle.$"

CanopourWilds_Text_CameronIntro:
	.string "intro$"

CanopourWilds_Text_CameronDefeated:
	.string "defeat$"

CanopourWilds_Text_CameronPostBattle:
	.string "post$"

CanopourWilds_Text_FlaitineIntro:
	.string "intro$"

CanopourWilds_Text_FlaitineDefeated:
	.string "defeat$"

CanopourWilds_Text_FlaitinePostBattle:
	.string "post$"

CanopourWilds_Text_JamperIntro:
	.string "intro$"

CanopourWilds_Text_JamperDefeated:
	.string "defeat$"

CanopourWilds_Text_JamperPostBattle:
	.string "post$"

CanopourWilds_Text_EnglatereIntro:
	.string "intro$"

CanopourWilds_Text_EnglatereDefeated:
	.string "defeat$"

CanopourWilds_Text_EnglaterePostBattle:
	.string "post$"

CanopourWilds_Text_KoizumiIntro:
	.string "intro$"

CanopourWilds_Text_KoizumiDefeated:
	.string "defeat$"

CanopourWilds_Text_KoizumiPostBattle:
	.string "post$"

CanopourWilds_Text_CharliIntro:
	.string "A battle?\l"
	.string "I haven't had my coffee yet, but sure,\n"
	.string "why not?$"

CanopourWilds_Text_CharliDefeated:
	.string "Hmph, now I just want to go back to\n"
	.string "sleep.$"

CanopourWilds_Text_CharliPostBattle:
	.string "The life of a scientist is a\n"
	.string "daunting one.\l"
	.string "Lots of sleepless nights. What a drag.$"

CanopourWilds_Text_ShamooIntro:
	.string "intro$"

CanopourWilds_Text_ShamooDefeated:
	.string "defeat$"

CanopourWilds_Text_ShamooPostBattle:
	.string "post$"

CanopourWilds_Text_MarisaIntro:
	.string "intro$"

CanopourWilds_Text_MarisaDefeated:
	.string "defeat$"

CanopourWilds_Text_MarisaPostBattle:
	.string "post$"

CanopourWilds_Text_GunnessIntro:
	.string "... Do you wanna see my super rare\n"
	.string "Steven Stone poster?$"

CanopourWilds_Text_GunnessDefeated:
	.string "That was NOT the answer I was\n"
	.string "expecting.$"

CanopourWilds_Text_GunnessPostBattle:
	.string "If you ever meet Steven Stone, can\n"
	.string "you PLEASE ask him to sign my poster?\p"
	.string "It would mean the world to me.$"

CanopourWilds_Text_JasonIntro:
	.string "D'you know how to start a fire with\n"
	.string "sticks?$"

CanopourWilds_Text_JasonDefeated:
	.string "N-not like that...$"

CanopourWilds_Text_JasonPostBattle:
	.string "Maybe I should just buy a flashlight...$"

CanopourWilds_Text_LeahIntro:
	.string "I'm learning to forage for berries!$"

CanopourWilds_Text_LeahDefeated:
	.string "He's not a very good teacher, is he?$"

CanopourWilds_Text_LeahPostBattle:
	.string "Maybe a Pokémon with Pickup can\n"
	.string "forage for me.$"

CanopourWilds_Text_LeleIntro:
	.string "Dragons are the best!\n"
	.string "They're the biggest and baddest\l"
	.string "Pokémon around!$"

CanopourWilds_Text_LeleDefeated:
	.string "Huh?! How could you beat my super\n"
	.string "awesome Dragons?!$"

CanopourWilds_Text_LelePostBattle:
	.string "Hmph! You're a big ol' meanie!\n"
	.string "Y'know that?!$"

CanopourWilds_Text_PickleLouIntro:
	.string "intro$"

CanopourWilds_Text_PickleLouDefeated:
	.string "defeat$"

CanopourWilds_Text_PickleLouPostBattle:
	.string "post$"
