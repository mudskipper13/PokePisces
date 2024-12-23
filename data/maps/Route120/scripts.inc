Route120_MapScripts::
	.byte 0

Route120_EventScript_Colby::
    trainerbattle_single TRAINER_P_COLBY, Route120_Text_ColbyIntro, Route120_Text_ColbyDefeated
    msgbox Route120_Text_ColbyPostBattle, MSGBOX_AUTOCLOSE
    end

Route120_EventScript_KatAndAna::
    trainerbattle_double TRAINER_P_KAT_AND_ANA, Route120_Text_KatAndAnaIntro, Route120_Text_KatAndAnaDefeated, Route120_Text_KatAndAnaNeedTwoMons
    msgbox Route120_Text_KatAndAnaPostBattle, MSGBOX_AUTOCLOSE
    end

Route120_EventScript_Thatcher::
    trainerbattle_single TRAINER_P_THATCHER, Route120_Text_ThatcherIntro, Route120_Text_ThatcherDefeated
    msgbox Route120_Text_ThatcherPostBattle, MSGBOX_AUTOCLOSE
    end

Route120_EventScript_Cherie::
    trainerbattle_single TRAINER_P_CHERIE, Route120_Text_CherieIntro, Route120_Text_CherieDefeated
    msgbox Route120_Text_CheriePostBattle, MSGBOX_AUTOCLOSE
    end

Route120_EventScript_Finn::
    trainerbattle_single TRAINER_P_FINN, Route120_Text_FinnIntro, Route120_Text_FinnDefeated
    msgbox Route120_Text_FinnPostBattle, MSGBOX_AUTOCLOSE
    end

Route120_EventScript_Junie::
    trainerbattle_single TRAINER_P_JUNIE, Route120_Text_JunieIntro, Route120_Text_JunieDefeated
    msgbox Route120_Text_JuniePostBattle, MSGBOX_AUTOCLOSE
    end

Route120_EventScript_Kiwi::
    trainerbattle_single TRAINER_P_KIWI, Route120_Text_KiwiIntro, Route120_Text_KiwiDefeated
    msgbox Route120_Text_KiwiPostBattle, MSGBOX_AUTOCLOSE
    end

Route120_EventScript_JimBob::
    trainerbattle_single TRAINER_P_JIM_BOB, Route120_Text_JimBobIntro, Route120_Text_JimBobDefeated
    msgbox Route120_Text_JimBobPostBattle, MSGBOX_AUTOCLOSE
    end

Route120_EventScript_MaddyAndCross::
    trainerbattle_double TRAINER_P_MADDY_AND_CROSS, Route120_Text_MaddyAndCrossIntro, Route120_Text_MaddyAndCrossDefeated, Route120_Text_MaddyAndCrossNeedTwoMons
    msgbox Route120_Text_MaddyAndCrossPostBattle, MSGBOX_AUTOCLOSE
    end

Route120_EventScript_Hector::
    trainerbattle_single TRAINER_P_HECTOR, Route120_Text_HectorIntro, Route120_Text_HectorDefeated
    msgbox Route120_Text_HectorPostBattle, MSGBOX_AUTOCLOSE
    end

Route120_EventScript_Patrasche::
    trainerbattle_single TRAINER_P_PATRASCHE, Route120_Text_PatrascheIntro, Route120_Text_PatrascheDefeated
    msgbox Route120_Text_PatraschePostBattle, MSGBOX_AUTOCLOSE
    end

Route120_EventScript_Amira::
    trainerbattle_single TRAINER_P_AMIRA, Route120_Text_AmiraIntro, Route120_Text_AmiraDefeated
    msgbox Route120_Text_AmiraPostBattle, MSGBOX_AUTOCLOSE
    end

Route120_EventScript_Leilei::
    trainerbattle_single TRAINER_P_LEILEI, Route120_Text_LeileiIntro, Route120_Text_LeileiDefeated
    msgbox Route120_Text_LeileiPostBattle, MSGBOX_AUTOCLOSE
    end

Route120_Text_ColbyIntro:
	.string "I bet you can't beat my full team of 6!$"

Route120_Text_ColbyDefeated:
	.string "Huh? What about my strength in\n"
	.string "numbers...?$"

Route120_Text_ColbyPostBattle:
	.string "A team with more Pokémon should have a\n"
	.string "natural advantage, right?\p"
	.string "Or is there more to it than that...?$"

Route120_Text_KatAndAnaIntro:
	.string "KAT: We're so in sync, we finish each\n"
	.string "other's...\p"
	.string "ANA: ...sandwiches!$"

Route120_Text_KatAndAnaDefeated:
	.string "KAT: We're finished! You...\n"
	.string "ANA: ...Uhh. Beats me!$"

Route120_Text_KatAndAnaPostBattle:
	.string "KAT: We battle everyone together, and...\n"
	.string "ANA: ...we always lose together too!$"

Route120_Text_KatAndAnaNeedTwoMons:
	.string "KAT: Two! Two! You need...\n"
	.string "ANA: ...more than one.$"

Route120_Text_ThatcherIntro:
	.string "I'm both creepy AND crawly!$"

Route120_Text_ThatcherDefeated:
	.string "Whoa! I've been stomped!$"

Route120_Text_ThatcherPostBattle:
	.string "Time for me to skitter on out of here!$"

Route120_Text_CherieIntro:
	.string "We're going on a trainer hunt!\n"
	.string "We're gonna catch a big one!$"

Route120_Text_CherieDefeated:
	.string "What a beautiful day!$"

Route120_Text_CheriePostBattle:
	.string "We're not going on a trainer hunt again.$"

Route120_Text_FinnIntro:
	.string "Hey there, kid. Wanna battle my cute\n"
	.string "Pokémon?$"

Route120_Text_FinnDefeated:
	.string "Oops! ...Did I trick you?$"

Route120_Text_FinnPostBattle:
	.string "Looks can be decieving, my friend.$"

Route120_Text_JunieIntro:
	.string "intro$"

Route120_Text_JunieDefeated:
	.string "defeat$"

Route120_Text_JuniePostBattle:
	.string "post$"

Route120_Text_KiwiIntro:
	.string "intro$"

Route120_Text_KiwiDefeated:
	.string "defeat$"

Route120_Text_KiwiPostBattle:
	.string "post$"

Route120_Text_JimBobIntro:
	.string "My mom says I'll be an entomologist\n"
	.string "when I grow up! How cool is that?!$"

Route120_Text_JimBobDefeated:
	.string "Just have to learn what that means\n"
	.string "first...$"

Route120_Text_JimBobPostBattle:
	.string "Hopefully it has something to do with\n"
	.string "bugs! I just love bugs!$"

Route120_Text_MaddyAndCrossIntro:
	.string "MADDY: Dibs on this trainer!\n"
	.string "CROSS: No way, I'll get them first!$"

Route120_Text_MaddyAndCrossDefeated:
	.string "CROSS: Huh!!??\n"
	.string "MADDY: What!!!???$"

Route120_Text_MaddyAndCrossPostBattle:
	.string "MADDY: You totally screwed me up!\n"
	.string "CROSS: No way! You're the one who ruined\l"
	.string " my perfect strategy...$"

Route120_Text_MaddyAndCrossNeedTwoMons:
	.string "MADDY: Are you even good enough for\n"
	.string "us?\l"
	.string "CROSS: Let's not even bother with this\l"
	.string "one.$"

Route120_Text_HectorIntro:
	.string "Let me show you my finest specimens...\n"
	.string "Hee hee.$"

Route120_Text_HectorDefeated:
	.string "You've damaged my collection!\n"
	.string "How dare you!??$"

Route120_Text_HectorPostBattle:
	.string "We Collectors are proud of our rare\n"
	.string "Pokémon. If you happen upon one, you'll\l"
	.string "never know what to expect! Hee hee.$"

Route120_Text_PatrascheIntro:
	.string "intro$"

Route120_Text_PatrascheDefeated:
	.string "defeat$"

Route120_Text_PatraschePostBattle:
	.string "post$"

Route120_Text_AmiraIntro:
	.string "intro$"

Route120_Text_AmiraDefeated:
	.string "defeat$"

Route120_Text_AmiraPostBattle:
	.string "post$"

Route120_Text_LeileiIntro:
	.string "intro$"

Route120_Text_LeileiDefeated:
	.string "defeat$"

Route120_Text_LeileiPostBattle:
	.string "post$"
