.set LOCALID_TABITHA, 7

MasoriedHike_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, MasoriedHike_OnLoad
	.byte 0

MasoriedHike_OnLoad:
	call_if_lt VAR_OZONE_ADMINS_STATE, 6, MasoriedHike_EventScript_RemoveTabitha
	call_if_gt VAR_OZONE_ADMINS_STATE, 6, MasoriedHike_EventScript_RemoveTabithaAndBolterock
	end

MasoriedHike_EventScript_RemoveTabitha::
	removeobject LOCALID_TABITHA
	setflag FLAG_TEMP_11
	return

MasoriedHike_EventScript_RemoveTabithaAndBolterock::
	removeobject LOCALID_TABITHA
	setflag FLAG_TEMP_11
	setmetatile 27, 14, METATILE_Chimney_BolterockGone, FALSE
	setmetatile 28, 14, METATILE_Chimney_BolterockGone, FALSE
	setmetatile 29, 14, METATILE_Chimney_BolterockGoneCliff, TRUE
	setmetatile 26, 15, METATILE_Chimney_BolterockGone, FALSE
	setmetatile 27, 15, METATILE_Chimney_BolterockGone, FALSE
	setmetatile 28, 15, METATILE_Chimney_BolterockGone, FALSE
	setmetatile 29, 15, METATILE_Chimney_BolterockGone, FALSE
	setmetatile 30, 15, METATILE_Chimney_BolterockGone, FALSE
	setmetatile 26, 16, METATILE_Chimney_BolterockGone, FALSE
	setmetatile 27, 16, METATILE_Chimney_BolterockGone, FALSE
	setmetatile 28, 16, METATILE_Chimney_BolterockGone, FALSE
	setmetatile 29, 16, METATILE_Chimney_BolterockGone, FALSE
	setmetatile 30, 16, METATILE_Chimney_BolterockGone, FALSE
	special DrawWholeMapView
	return

MasonriedHike_EventScript_Tabitha::
	lock
	faceplayer
	goto_if_eq VAR_OZONE_ADMINS_STATE, 7, MasonriedHike_EventScript_TabithaPostBolt
	speakername MasonriedHike_Text_NameTabitha
	msgbox MasonriedHike_Text_HowToWakeEmUp, MSGBOX_DEFAULT
	closemessage
	turnobject LOCALID_TABITHA, DIR_NORTH
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	delay 16
	playse SE_M_EXPLOSION
	waitse
	delay 32
	setwildbattle SPECIES_BOLTEROCK, 35
	playmoncry SPECIES_BOLTEROCK, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	speakername NULL
	msgbox MasonriedHike_Text_BolterockJoltedAwake, MSGBOX_DEFAULT
	setflag FLAG_WILD_NO_RUNNING_FLAG
	setflag FLAG_SMART_WILD_AI_FLAG
	delay 4
	dowildbattle
	delay 8
	clearflag FLAG_WILD_NO_RUNNING_FLAG
	clearflag FLAG_SMART_WILD_AI_FLAG
	delay 8
	setmetatile 27, 14, METATILE_Chimney_BolterockGone, FALSE
	setmetatile 28, 14, METATILE_Chimney_BolterockGone, FALSE
	setmetatile 29, 14, METATILE_Chimney_BolterockGoneCliff, TRUE
	setmetatile 26, 15, METATILE_Chimney_BolterockGone, FALSE
	setmetatile 27, 15, METATILE_Chimney_BolterockGone, FALSE
	setmetatile 28, 15, METATILE_Chimney_BolterockGone, FALSE
	setmetatile 29, 15, METATILE_Chimney_BolterockGone, FALSE
	setmetatile 30, 15, METATILE_Chimney_BolterockGone, FALSE
	setmetatile 26, 16, METATILE_Chimney_BolterockGone, FALSE
	setmetatile 27, 16, METATILE_Chimney_BolterockGone, FALSE
	setmetatile 28, 16, METATILE_Chimney_BolterockGone, FALSE
	setmetatile 29, 16, METATILE_Chimney_BolterockGone, FALSE
	setmetatile 30, 16, METATILE_Chimney_BolterockGone, FALSE
	special DrawWholeMapView
	setflag FLAG_TEMP_11
	setvar VAR_OZONE_ADMINS_STATE, 7
	speakername MasonriedHike_Text_NameTabitha
	msgbox MasonriedHike_Text_DealtWithItGood, MSGBOX_AUTOCLOSE
	release
	end

MasonriedHike_EventScript_TabithaPostBolt::
	speakername MasonriedHike_Text_NameTabitha
	msgbox MasonriedHike_Text_IllMeetYouAhead, MSGBOX_AUTOCLOSE
	release
    end

MasonriedHike_EventScript_BlockingBolterock::
	lock
	goto_if_lt VAR_OZONE_ADMINS_STATE, 7, MasonriedHike_EventScript_CantPassBolterock
	msgbox MasonriedHike_Text_BolterockGone, MSGBOX_AUTOCLOSE
	release
	end

MasonriedHike_EventScript_CantPassBolterock::
	msgbox MasonriedHike_Text_CantPassBolterock, MSGBOX_AUTOCLOSE
	release
	end

MasonriedHike_EventScript_BlockingBolterock2::
	lock
	goto_if_lt VAR_OZONE_ADMINS_STATE, 7, MasonriedHike_EventScript_CantPassBolterock
	goto_if_set FLAG_TEMP_12, MasonriedHike_EventScript_BolterockGone
	msgbox MasonriedHike_Text_YouMadeAnExplosionSound, MSGBOX_DEFAULT
	closemessage
	delay 16
	playse SE_M_EXPLOSION
	waitse
	delay 32
	setwildbattle SPECIES_BOLTEROCK, 35
	playmoncry SPECIES_BOLTEROCK, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	speakername NULL
	msgbox MasonriedHike_Text_BolterockJoltedAwake, MSGBOX_DEFAULT
	setflag FLAG_WILD_NO_RUNNING_FLAG
	setflag FLAG_SMART_WILD_AI_FLAG
	delay 4
	dowildbattle
	delay 8
	clearflag FLAG_WILD_NO_RUNNING_FLAG
	clearflag FLAG_SMART_WILD_AI_FLAG
	delay 8
	setmetatile 39, 29, METATILE_Chimney_BolterockGone, FALSE
	setmetatile 40, 29, METATILE_Chimney_BolterockGone, FALSE
	setmetatile 41, 29, METATILE_Chimney_BolterockGone, FALSE
	setmetatile 38, 30, METATILE_Chimney_BolterockGone, FALSE
	setmetatile 39, 30, METATILE_Chimney_BolterockGone, FALSE
	setmetatile 40, 30, METATILE_Chimney_BolterockGone, FALSE
	setmetatile 41, 30, METATILE_Chimney_BolterockGone, FALSE
	setmetatile 42, 30, METATILE_Chimney_BolterockGone, FALSE
	setmetatile 38, 31, METATILE_Chimney_BolterockGone, FALSE
	setmetatile 39, 31, METATILE_Chimney_BolterockGone, FALSE
	setmetatile 40, 31, METATILE_Chimney_BolterockGone, FALSE
	setmetatile 41, 31, METATILE_Chimney_BolterockGone, FALSE
	setmetatile 42, 31, METATILE_Chimney_BolterockGone, FALSE
	special DrawWholeMapView
	msgbox MasonriedHike_Text_TheWildBoltFled, MSGBOX_AUTOCLOSE
	setflag FLAG_TEMP_12
	release
	end

MasonriedHike_EventScript_BolterockGone::
	msgbox MasonriedHike_Text_BolterockGone, MSGBOX_AUTOCLOSE
	release
	end

MasonriedHike_EventScript_Michael::
    trainerbattle_single TRAINER_P_MICHAEL, MasonriedHike_Text_MichaelIntro, MasonriedHike_Text_MichaelDefeated
    msgbox MasonriedHike_Text_MichaelPostBattle, MSGBOX_AUTOCLOSE
    end

MasonriedHike_EventScript_Chloe::
    trainerbattle_single TRAINER_P_CHLOE, MasonriedHike_Text_ChloeIntro, MasonriedHike_Text_ChloeDefeated
    msgbox MasonriedHike_Text_ChloePostBattle, MSGBOX_AUTOCLOSE
    end

MasonriedHike_EventScript_Bichael::
    trainerbattle_single TRAINER_P_BICHAEL, MasonriedHike_Text_BichaelIntro, MasonriedHike_Text_BichaelDefeated
    msgbox MasonriedHike_Text_BichaelPostBattle, MSGBOX_AUTOCLOSE
    end

MasonriedHike_EventScript_Flowers::
    trainerbattle_single TRAINER_P_FLOWERS, MasonriedHike_Text_FlowersIntro, MasonriedHike_Text_FlowersDefeated
    msgbox MasonriedHike_Text_FlowersPostBattle, MSGBOX_AUTOCLOSE
    end

MasonriedHike_EventScript_JayAndEm::
    trainerbattle_double TRAINER_P_JAY_AND_EM, MasonriedHike_Text_JayAndEmIntro, MasonriedHike_Text_JayAndEmDefeated, MasonriedHike_Text_JayAndEmNeedTwoMons
    msgbox MasonriedHike_Text_JayAndEmPostBattle, MSGBOX_AUTOCLOSE
    end

MasonriedHike_Text_MichaelIntro:
	.string "...Eeyup.$"

MasonriedHike_Text_MichaelDefeated:
	.string "...$"

MasonriedHike_Text_MichaelPostBattle:
	.string "...Think I already said more than\n"
	.string "enough.$"

MasonriedHike_Text_ChloeIntro:
	.string "intro$"

MasonriedHike_Text_ChloeDefeated:
	.string "defeat$"

MasonriedHike_Text_ChloePostBattle:
	.string "post$"

MasonriedHike_Text_BichaelIntro:
	.string "Boy, this terrain is tough to bike on!\n"
	.string "Care for a battle?$"

MasonriedHike_Text_BichaelDefeated:
	.string "Well, not as tough as you...$"

MasonriedHike_Text_BichaelPostBattle:
	.string "I come from a family of bike\n"
	.string "enthusiasts.\p"
	.string "I wish they'd given me a normal name,\n"
	.string "though...$"

MasonriedHike_Text_FlowersIntro:
	.string "I'm just gettin' started!\n"
	.string "Wanna be part of my journey?$"

MasonriedHike_Text_FlowersDefeated:
	.string "Oof! You used me like a stepping\n"
	.string "stone...$"

MasonriedHike_Text_FlowersPostBattle:
	.string "I'll just head back to the Pokémon\n"
	.string "Center now...$"

MasonriedHike_Text_JayAndEmIntro:
	.string "JAY: You're the Plus to my Minus!\n"
	.string "EM: You're the Minus to my Plus!$"


MasonriedHike_Text_JayAndEmDefeated:
	.string "JAY: Whoa! Neutralized!\n"
	.string "EM: We balance each other out, don't we?$"

MasonriedHike_Text_JayAndEmPostBattle:
	.string "JAY: I guess you could say we're a\n"
	.string "''Power Couple''.\p"
	.string "EM: Is that an electricity joke?\n"
	.string "Ion' get it...$"

MasonriedHike_Text_JayAndEmNeedTwoMons:
	.string "JAY: Two plus one...\n"
	.string "Doesn't make for a good double battle.\n"
	.string "EM: One plus two...\n"
	.string "That's three, right?$"

MasonriedHike_Text_NameTabitha:
	.string "Tabitha$"

MasonriedHike_Text_HowToWakeEmUp:
	.string "{PLAYER}, it appears our path\n"
	.string "has been blocked.\p"
	.string "This Pokemon is called Bolterock.\n"
	.string "It is, barring few, one of the\l"
	.string "largest species of Pokemon\l"
	.string "I have laid eyes on.\p"
	.string "As you might surmise... a\n"
	.string "sleeping Bolterock is no easy\l"
	.string "mass to move. However, I have\l"
	.string "personally developed a solution.\p"
	.string "When all else fails when getting\n"
	.string "a Bolterock to move from its spot,\l"
	.string "miners and demolitionists will\l"
	.string "utilize explosives. Over time,\l"
	.string "Bolterock have come to recognize\l"
	.string "this, and will jolt awake at\l"
	.string "the sound of a detonation.\p"
	.string "If you make a convincing enough\n"
	.string "explosion noise directly next\l"
	.string "to its ear, it should awake.\p"
	.string "Ahem.\n"
	.string "KAAAAAA-POOOOWWWW!!!!$"

MasonriedHike_Text_BolterockJoltedAwake:
	.string "(The Wild Bolterock has awoken!)$"

MasonriedHike_Text_DealtWithItGood:
	.string "I... did neglect to mention\n"
	.string "how agitated the Bolterock\l"
	.string "would become. No matter.\l"
	.string "You dealt with it swimmingly.\p"
	.string "The path to our left up Mt. Chimney\n"
	.string "splits into three ways.\p"
	.string "One leads to the cavern system\n"
	.string "beneath the mountain, which I\l"
	.string "believe is currently impossible\l"
	.string "for you to fully traverse.\p"
	.string "The other two paths lead around\n"
	.string "the mountain, and over the mountain.\l"
	.string "Both paths converge on\l"
	.string "Fallarbor Town, but each has their\l"
	.string "own terrain and fauna to\l"
	.string "contend with.\p"
	.string "The choice is yours. I will\n"
	.string "be meeting you at the town proper.$"

MasonriedHike_Text_IllMeetYouAhead:
	.string "The path to our left up Mt. Chimney\n"
	.string "splits into three ways.\p"
	.string "One leads to the cavern system\n"
	.string "beneath the mountain, which I\l"
	.string "believe is currently impossible\l"
	.string "for you to fully traverse.\p"
	.string "The other two paths lead around\n"
	.string "the mountain, and over the mountain.\l"
	.string "Both paths converge on\l"
	.string "Fallarbor Town, but each has their\l"
	.string "own terrain and fauna to\l"
	.string "contend with.\p"
	.string "The choice is yours. I will\n"
	.string "be meeting you at the town proper.$"

MasonriedHike_Text_BolterockGone:
	.string "(The path is no longer\n"
	.string "Bolte-blocked.)$"

MasonriedHike_Text_CantPassBolterock:
	.string "(This ginormous Pokemon is\n"
	.string "gently snoring.\l"
	.string "And is also blocking your way.)$"

MasonriedHike_Text_YouMadeAnExplosionSound:
	.string "(You follow Tabitha's advice\n"
	.string "a make an explosion sound...)$"

MasonriedHike_Text_TheWildBoltFled:
	.string "(Bolterock has left its\n"
	.string "resting spot.)$"
