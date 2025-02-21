HatchloamDayCare_MapScripts::
	.byte 0

HatchloamDayCare_EventScript_BerryShop::
	lock
	faceplayer
	goto_if_lt VAR_OZONE_ADMINS_STATE, 10, HatchloamDayCare_EventScript_BerryShopLite
	message HatchloamDayCare_Text_WelcomeToBerryShop
	waitmessage
	multichoice 19, 4, MULTI_BERRY_SHOP_CATEGORY, TRUE
	copyvar VAR_TEMP_1, VAR_RESULT
	switch VAR_TEMP_1
	case 0, HatchloamDayCare_EventScript_HealingBerries
	case 1, HatchloamDayCare_EventScript_ResistanceBerries
	case 2, HatchloamDayCare_EventScript_StatBerries
	case 3, HatchloamDayCare_EventScript_OtherBerries
	msgbox HatchloamDayCare_Text_HaveAGoodDay, MSGBOX_AUTOCLOSE
	release
	end

HatchloamDayCare_EventScript_HealingBerries::
	pokemart HatchloamDayCare_Mart_HealingBerryShop
	msgbox HatchloamDayCare_Text_HaveAGoodDay, MSGBOX_AUTOCLOSE
	release
	end

	.align 2
HatchloamDayCare_Mart_HealingBerryShop:
	.2byte ITEM_SITRUS_BERRY
	.2byte ITEM_FIGY_BERRY
	.2byte ITEM_WIKI_BERRY
	.2byte ITEM_MAGO_BERRY
	.2byte ITEM_AGUAV_BERRY
	.2byte ITEM_IAPAPA_BERRY
	.2byte ITEM_LUM_BERRY
	.2byte ITEM_PECHA_BERRY
	.2byte ITEM_CHERI_BERRY
	.2byte ITEM_CHESTO_BERRY
	.2byte ITEM_RAWST_BERRY
	.2byte ITEM_ASPEAR_BERRY
	.2byte ITEM_PERSIM_BERRY
	.2byte ITEM_PAMTRE_BERRY
	.2byte ITEM_ORAN_BERRY
	.2byte ITEM_NONE
	release
	end	

HatchloamDayCare_EventScript_ResistanceBerries::
	pokemart HatchloamDayCare_Mart_ResistanceBerryShop
	msgbox HatchloamDayCare_Text_HaveAGoodDay, MSGBOX_AUTOCLOSE
	release
	end

	.align 2
HatchloamDayCare_Mart_ResistanceBerryShop:
	.2byte ITEM_OCCA_BERRY
	.2byte ITEM_PASSHO_BERRY
	.2byte ITEM_WACAN_BERRY
	.2byte ITEM_RINDO_BERRY
	.2byte ITEM_YACHE_BERRY
	.2byte ITEM_CHOPLE_BERRY
	.2byte ITEM_KEBIA_BERRY
	.2byte ITEM_SHUCA_BERRY
	.2byte ITEM_COBA_BERRY
	.2byte ITEM_PAYAPA_BERRY
	.2byte ITEM_TANGA_BERRY
	.2byte ITEM_CHARTI_BERRY
	.2byte ITEM_KASIB_BERRY
	.2byte ITEM_HABAN_BERRY
	.2byte ITEM_COLBUR_BERRY
	.2byte ITEM_BABIRI_BERRY
	.2byte ITEM_CHILAN_BERRY
	.2byte ITEM_ROSELI_BERRY
	.2byte ITEM_ENIGMA_BERRY
	.2byte ITEM_MAGOST_BERRY
	.2byte ITEM_NONE
	release
	end	

HatchloamDayCare_EventScript_StatBerries::
	pokemart HatchloamDayCare_Mart_StatBerryShop
	msgbox HatchloamDayCare_Text_HaveAGoodDay, MSGBOX_AUTOCLOSE
	release
	end

	.align 2
HatchloamDayCare_Mart_StatBerryShop:
	.2byte ITEM_LIECHI_BERRY
	.2byte ITEM_GANLON_BERRY
	.2byte ITEM_SALAC_BERRY
	.2byte ITEM_PETAYA_BERRY
	.2byte ITEM_APICOT_BERRY
	.2byte ITEM_LANSAT_BERRY
	.2byte ITEM_STARF_BERRY
	.2byte ITEM_MICLE_BERRY
	.2byte ITEM_CUSTAP_BERRY
	.2byte ITEM_KEE_BERRY
	.2byte ITEM_MARANGA_BERRY
	.2byte ITEM_DURIN_BERRY
	.2byte ITEM_NONE
	release
	end	

HatchloamDayCare_EventScript_OtherBerries::
	pokemart HatchloamDayCare_Mart_OtherBerryShop
	msgbox HatchloamDayCare_Text_HaveAGoodDay, MSGBOX_AUTOCLOSE
	release
	end

	.align 2
HatchloamDayCare_Mart_OtherBerryShop:
	.2byte ITEM_NOMEL_BERRY
	.2byte ITEM_KELPSY_BERRY
	.2byte ITEM_QUALOT_BERRY
	.2byte ITEM_GREPA_BERRY
	.2byte ITEM_HONDEW_BERRY
	.2byte ITEM_BLUK_BERRY
	.2byte ITEM_BELUE_BERRY
	.2byte ITEM_RAZZ_BERRY
	.2byte ITEM_RIZZ_BERRY
	.2byte ITEM_RABUTA_BERRY
	.2byte ITEM_SPELON_BERRY
	.2byte ITEM_NANAB_BERRY
	.2byte ITEM_WEPEAR_BERRY
	.2byte ITEM_POMEG_BERRY
	.2byte ITEM_CORNN_BERRY
	.2byte ITEM_PINAP_BERRY
	.2byte ITEM_WATMEL_BERRY
	.2byte ITEM_NONE
	release
	end	

HatchloamDayCare_EventScript_BerryShopLite::
	message HatchloamDayCare_Text_WelcomeToBerryShop
	waitmessage
	pokemart HatchloamDayCare_Mart_BerryShopLite
	msgbox HatchloamDayCare_Text_HaveAGoodDay, MSGBOX_AUTOCLOSE
	release
	end

	.align 2
HatchloamDayCare_Mart_BerryShopLite:
	.2byte ITEM_SITRUS_BERRY
	.2byte ITEM_FIGY_BERRY
	.2byte ITEM_WIKI_BERRY
	.2byte ITEM_MAGO_BERRY
	.2byte ITEM_AGUAV_BERRY
	.2byte ITEM_IAPAPA_BERRY
	.2byte ITEM_LUM_BERRY
	.2byte ITEM_MAGOST_BERRY
	.2byte ITEM_NOMEL_BERRY
	.2byte ITEM_KELPSY_BERRY
	.2byte ITEM_QUALOT_BERRY
	.2byte ITEM_GREPA_BERRY
	.2byte ITEM_BLUK_BERRY
	.2byte ITEM_BELUE_BERRY
	.2byte ITEM_RAZZ_BERRY
	.2byte ITEM_RABUTA_BERRY
	.2byte ITEM_SPELON_BERRY
	.2byte ITEM_NANAB_BERRY
	.2byte ITEM_WEPEAR_BERRY
	.2byte ITEM_POMEG_BERRY
	.2byte ITEM_CORNN_BERRY
	.2byte ITEM_NONE
	release
	end	

HatchloamDayCare_EventScript_Trader::
	lock
	faceplayer
	goto_if_set FLAG_GUMBORREE_TRADE_COMPLETED, HatchloamDayCare_EventScript_TradeCompleted
	setvar VAR_0x8008, INGAME_TRADE_GUMBOREE
	copyvar VAR_0x8004, VAR_0x8008
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
	copyvar VAR_0x8009, VAR_RESULT
	msgbox HatchloamDayCare_Text_IllTradeIfYouWant, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, HatchloamDayCare_EventScript_DeclineTrade
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, HatchloamDayCare_EventScript_DeclineTrade
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	goto_if_ne VAR_RESULT, VAR_0x8009, HatchloamDayCare_EventScript_NotRequestedMon
	copyvar VAR_0x8004, VAR_0x8008
	copyvar VAR_0x8005, VAR_0x800A
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	waitstate
	msgbox HatchloamDayCare_Text_PleaseBeGoodToMyPokemon, MSGBOX_DEFAULT
	setflag FLAG_GUMBORREE_TRADE_COMPLETED
	release
	end

HatchloamDayCare_EventScript_DeclineTrade::
	msgbox HatchloamDayCare_Text_YouDontWantToThatsOkay, MSGBOX_DEFAULT
	release
	end

HatchloamDayCare_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox HatchloamDayCare_Text_DoesntLookLikeMonToMe, MSGBOX_DEFAULT
	release
	end

HatchloamDayCare_EventScript_TradeCompleted::
	msgbox HatchloamDayCare_Text_ThanksForTrading, MSGBOX_DEFAULT
	release
	end

HatchloamDayCare_Text_IllTradeIfYouWant:
	.string "I'll trade you my {STR_VAR_2} for\n"
	.string "a {STR_VAR_1} if you want.$"

HatchloamDayCare_Text_PleaseBeGoodToMyPokemon:
	.string "Please be good to my POKéMON.$"

HatchloamDayCare_Text_DoesntLookLikeMonToMe:
	.string "Huh? That doesn't look anything like\n"
	.string "a {STR_VAR_1} to me.$"

HatchloamDayCare_Text_YouDontWantToThatsOkay:
	.string "Oh, if you don't want to, that's okay.$"

HatchloamDayCare_Text_ThanksForTrading:
	.string "Thanks for the trade.$"

HatchloamDayCare_Text_WelcomeToBerryShop:
	.string "$"

HatchloamDayCare_Text_HaveAGoodDay:
	.string "$"
