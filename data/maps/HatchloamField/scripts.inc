.set LOCALID_ROADBLOCKER_1, 16
.set LOCALID_ROADBLOCKER_2, 17
.set LOCALID_ROADBLOCKER_3, 18
.set LOCALID_ROADBLOCKER_4, 19
.set LOCALID_COURTNEY, 15

HatchloamField_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, HatchloamField_OnLoad
	.byte 0

HatchloamField_OnLoad:
	call_if_gt VAR_WALLY_QUEST_STATE, 2, HatchloamField_EventScript_RemoveRoadblock
	end

HatchloamField_EventScript_RemoveRoadblock::
	removeobject LOCALID_ROADBLOCKER_1
	setflag FLAG_TEMP_11
	removeobject LOCALID_ROADBLOCKER_2
	setflag FLAG_TEMP_12
	removeobject LOCALID_ROADBLOCKER_3
	setflag FLAG_TEMP_13
	removeobject LOCALID_ROADBLOCKER_4
	setflag FLAG_TEMP_14
	return

HatchloamField_EventScript_Courtney::
	lock
	faceplayer
	goto_if_set FLAG_TEMP_A, HatchloamField_EventScript_CourtneyIdlePostBattle
	goto_if_eq VAR_OZONE_ADMINS_STATE, 9, HatchloamField_EventScript_CourtneyWantToBattle
	goto_if_gt VAR_OZONE_ADMINS_STATE, 9, HatchloamField_EventScript_CourtneyIdle
	release
	end

HatchloamField_EventScript_CourtneyWantToBattle::
	speakername HatchloamField_Text_NameCourtney
	msgbox HatchloamField_Text_NiceToSeeYou, MSGBOX_DEFAULT
	goto_if_eq VAR_RESULT, YES, HatchloamField_EventScript_CourtneyBattle
	speakername HatchloamField_Text_NameCourtney
	msgbox HatchloamField_Text_ThatsTooBad, MSGBOX_AUTOCLOSE
	release
	end

HatchloamField_EventScript_CourtneyBattle::
	msgbox HatchloamField_Text_CourtneyIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_P_COURTNEY_1, HatchloamField_Text_CourtneyDefeated
	goto HatchloamField_EventScript_CourtneyPostBattle

HatchloamField_EventScript_CourtneyPostBattle::
	speakername HatchloamField_Text_NameCourtney
	msgbox HatchloamField_Text_ThatWasFun, MSGBOX_DEFAULT
	setvar VAR_OZONE_ADMINS_STATE, 10
	setflag FLAG_TEMP_A
	turnobject LOCALID_COURTNEY, DIR_NORTH
	speakername HatchloamField_Text_NameCourtney
	msgbox HatchloamField_Text_IllStockNewBerries, MSGBOX_DEFAULT
	closemessage
	release
	end

HatchloamField_EventScript_CourtneyIdlePostBattle::
	speakername HatchloamField_Text_NameCourtney
	msgbox HatchloamField_Text_TrickHouseIsNorth, MSGBOX_AUTOCLOSE
	release
	end

HatchloamField_EventScript_CourtneyIdle::
	speakername HatchloamField_Text_NameCourtney
	msgbox HatchloamField_Text_HowIsYourJourney, MSGBOX_AUTOCLOSE
	release
	end

HatchloamField_EventScript_Dustin::
    trainerbattle_single TRAINER_P_DUSTIN, HatchloamField_Text_DustinIntro, HatchloamField_Text_DustinDefeated
    msgbox HatchloamField_Text_DustinPostBattle, MSGBOX_AUTOCLOSE
    end

HatchloamField_EventScript_Hayley::
    trainerbattle_single TRAINER_P_HAYLEY, HatchloamField_Text_HayleyIntro, HatchloamField_Text_HayleyDefeated
    msgbox HatchloamField_Text_HayleyPostBattle, MSGBOX_AUTOCLOSE
    end

HatchloamField_EventScript_EnaAndMina::
    trainerbattle_double TRAINER_P_ENA_AND_MINA, HatchloamField_Text_EnaAndMinaIntro, HatchloamField_Text_EnaAndMinaDefeated, HatchloamField_Text_EnaAndMinaNeedTwoMons
    msgbox HatchloamField_Text_EnaAndMinaPostBattle, MSGBOX_AUTOCLOSE
    end

HatchloamField_EventScript_Dill::
    trainerbattle_single TRAINER_P_DILL, HatchloamField_Text_DillIntro, HatchloamField_Text_DillDefeated
    msgbox HatchloamField_Text_DillPostBattle, MSGBOX_AUTOCLOSE
    end

HatchloamField_EventScript_Delilah::
    trainerbattle_single TRAINER_P_DELILAH, HatchloamField_Text_DelilahIntro, HatchloamField_Text_DelilahDefeated
    msgbox HatchloamField_Text_DelilahPostBattle, MSGBOX_AUTOCLOSE
    end

HatchloamField_EventScript_JiyuAndShirou::
    trainerbattle_double TRAINER_P_JIYU_AND_SHIROU, HatchloamField_Text_JiyuAndShirouIntro, HatchloamField_Text_JiyuAndShirouDefeated, HatchloamField_Text_JiyuAndShirouNeedTwoMons
    msgbox HatchloamField_Text_JiyuAndShirouPostBattle, MSGBOX_AUTOCLOSE
    end

HatchloamField_EventScript_Samuel::
    trainerbattle_single TRAINER_P_SAMUEL, HatchloamField_Text_SamuelIntro, HatchloamField_Text_SamuelDefeated
    msgbox HatchloamField_Text_SamuelPostBattle, MSGBOX_AUTOCLOSE
    end

HatchloamField_EventScript_YerbaAndBuena::
    trainerbattle_double TRAINER_P_YERBA_AND_BUENA, HatchloamField_Text_YerbaAndBuenaIntro, HatchloamField_Text_YerbaAndBuenaDefeated, HatchloamField_Text_YerbaAndBuenaNeedTwoMons
    msgbox HatchloamField_Text_YerbaAndBuenaPostBattle, MSGBOX_AUTOCLOSE
    end

HatchloamField_EventScript_LexAndTrish::
    trainerbattle_double TRAINER_P_LEX_AND_TRISH, HatchloamField_Text_LexAndTrishIntro, HatchloamField_Text_LexAndTrishDefeated, HatchloamField_Text_LexAndTrishNeedTwoMons
    msgbox HatchloamField_Text_LexAndTrishPostBattle, MSGBOX_AUTOCLOSE
    end

HatchloamField_Text_DustinIntro:
	.string "These here Pokémon are the finest I\n"
	.string "have ever bred!$"

HatchloamField_Text_DustinDefeated:
	.string "What?! No way!\n"
	.string "My finely bred Pokémon, defeated?!$"

HatchloamField_Text_DustinPostBattle:
	.string "How could my Pokémon be bested by a\n"
	.string "bunch of wild-caught savages!?\p"
	.string "It just doesn't make sense.$"

HatchloamField_Text_HayleyIntro:
	.string "It amazes me how many trainers are\n"
	.string "stumped why an egg 'appears' at the\l"
	.string "daycare...$"

HatchloamField_Text_HayleyDefeated:
	.string "I wonder... have their parents ever\n"
	.string "given them the 'talk'?...$"

HatchloamField_Text_HayleyPostBattle:
	.string "Don't look at me like that!\n"
	.string "I'm not gonna be the one to explain the\l"
	.string "beauty of life to them!...\p"
	.string "Way too embarrassing...$"

HatchloamField_Text_EnaAndMinaIntro:
	.string "ENA: We move in unison.\n"
	.string "MINA: We are one.$"

HatchloamField_Text_EnaAndMinaDefeated:
	.string "ENA: Us two, bested.\n"
	.string "MINA: By your single hand.$"

HatchloamField_Text_EnaAndMinaPostBattle:
	.string "ENA: We espers need more training.\n"
	.string "MINA: To best you, of course.$"

HatchloamField_Text_EnaAndMinaNeedTwoMons:
	.string "ENA: We are two in one.\n"
	.string "MINA: But you'd need two to keep up.$"

HatchloamField_Text_DillIntro:
	.string "Shush! Your loud footsteps are scaring\n"
	.string "them all away!$"

HatchloamField_Text_DillDefeated:
	.string "What?! How dare you disrespect me?!\n"
	.string "The most famous Bug researcher in\l"
	.string "all of Hoenn!?$"

HatchloamField_Text_DillPostBattle:
	.string "W-what do you mean you don't know who I\n"
	.string "am?! Hmph, kids these days...\l"
	.string "no respect I say, no respect at all!$"

HatchloamField_Text_DelilahIntro:
	.string "(sniff, sniff...)\n"
	.string "Yes, I smell a strong trainer!$"

HatchloamField_Text_DelilahDefeated:
	.string "(sniffle, sniffle...)\n"
	.string "Yes, that's it...\p"
	.string "The agonizing scent of defeat...$"

HatchloamField_Text_DelilahPostBattle:
	.string "Your eyes can betray you, but your nose\n"
	.string "knows all.$"

HatchloamField_Text_JiyuAndShirouIntro:
	.string "intro$"

HatchloamField_Text_JiyuAndShirouDefeated:
	.string "defeat$"

HatchloamField_Text_JiyuAndShirouPostBattle:
	.string "post$"

HatchloamField_Text_JiyuAndShirouNeedTwoMons:
	.string "need 2 dood$"

HatchloamField_Text_SamuelIntro:
	.string "Back and forth... Back and forth...\n"
	.string "Oh! An interruption!$"

HatchloamField_Text_SamuelDefeated:
	.string "Well, off I go now...$"

HatchloamField_Text_SamuelPostBattle:
	.string "Wanna know why I'm biking back and\n"
	.string "forth?\p"
	.string "I'm hatching Pokémon eggs, of course!$"

HatchloamField_Text_YerbaAndBuenaIntro:
	.string "intro$"

HatchloamField_Text_YerbaAndBuenaDefeated:
	.string "defeat$"

HatchloamField_Text_YerbaAndBuenaPostBattle:
	.string "post$"

HatchloamField_Text_YerbaAndBuenaNeedTwoMons:
	.string "need 2 dood$"

HatchloamField_Text_LexAndTrishIntro:
	.string "intro$"

HatchloamField_Text_LexAndTrishDefeated:
	.string "defeat$"

HatchloamField_Text_LexAndTrishPostBattle:
	.string "post$"

HatchloamField_Text_LexAndTrishNeedTwoMons:
	.string "need 2 dood$"

HatchloamField_Text_NameCourtney:
	.string "$"

HatchloamField_Text_NiceToSeeYou:
	.string "$"

HatchloamField_Text_ThatsTooBad:
	.string "$"

HatchloamField_Text_CourtneyIntro:
	.string "$"

HatchloamField_Text_CourtneyDefeated:
	.string "$"

HatchloamField_Text_ThatWasFun:
	.string "$"

HatchloamField_Text_IllStockNewBerries:
	.string "$"

HatchloamField_Text_TrickHouseIsNorth:
	.string "$"

HatchloamField_Text_HowIsYourJourney:
	.string "$"
