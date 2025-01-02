MasoriedHike_MapScripts::
	.byte 0

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

