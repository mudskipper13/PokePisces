SweltornDesert_MapScripts::
	.byte 0

SweltornDesert_EventScript_Santo::
    trainerbattle_single TRAINER_P_SANTO, SweltornDesert_Text_SantoIntro, SweltornDesert_Text_SantoDefeated
    msgbox SweltornDesert_Text_SantoPostBattle, MSGBOX_AUTOCLOSE
    end

SweltornDesert_EventScript_Dorothy::
    trainerbattle_single TRAINER_P_DOROTHY, SweltornDesert_Text_DorothyIntro, SweltornDesert_Text_DorothyDefeated
    msgbox SweltornDesert_Text_DorothyPostBattle, MSGBOX_AUTOCLOSE
    end

SweltornDesert_EventScript_Erin::
    trainerbattle_single TRAINER_P_ERIN, SweltornDesert_Text_ErinIntro, SweltornDesert_Text_ErinDefeated
    msgbox SweltornDesert_Text_ErinPostBattle, MSGBOX_AUTOCLOSE
    end

SweltornDesert_EventScript_Aaron::
    trainerbattle_single TRAINER_P_AARON, SweltornDesert_Text_AaronIntro, SweltornDesert_Text_AaronDefeated
    msgbox SweltornDesert_Text_AaronPostBattle, MSGBOX_AUTOCLOSE
    end

SweltornDesert_EventScript_Thad::
    trainerbattle_single TRAINER_P_THAD, SweltornDesert_Text_ThadIntro, SweltornDesert_Text_ThadDefeated
    msgbox SweltornDesert_Text_ThadPostBattle, MSGBOX_AUTOCLOSE
    end

SweltornDesert_EventScript_Leela::
    trainerbattle_single TRAINER_P_LEELA, SweltornDesert_Text_LeelaIntro, SweltornDesert_Text_LeelaDefeated
    msgbox SweltornDesert_Text_LeelaPostBattle, MSGBOX_AUTOCLOSE
    end

SweltornDesert_EventScript_Ickle::
    trainerbattle_single TRAINER_P_ICKLE, SweltornDesert_Text_IckleIntro, SweltornDesert_Text_IckleDefeated
    msgbox SweltornDesert_Text_IcklePostBattle, MSGBOX_AUTOCLOSE
    end

SweltornDesert_EventScript_Staph::
    trainerbattle_single TRAINER_P_STAPH, SweltornDesert_Text_StaphIntro, SweltornDesert_Text_StaphDefeated
    msgbox SweltornDesert_Text_StaphPostBattle, MSGBOX_AUTOCLOSE
    end

SweltornDesert_EventScript_Hwarang::
    trainerbattle_single TRAINER_P_HWARANG, SweltornDesert_Text_HwarangIntro, SweltornDesert_Text_HwarangDefeated
    msgbox SweltornDesert_Text_HwarangPostBattle, MSGBOX_AUTOCLOSE
    end

SweltornDesert_EventScript_Takeshi::
    trainerbattle_single TRAINER_P_TAKESHI, SweltornDesert_Text_TakeshiIntro, SweltornDesert_Text_TakeshiDefeated
    msgbox SweltornDesert_Text_TakeshiPostBattle, MSGBOX_AUTOCLOSE
    end

SweltornDesert_EventScript_Beat::
    trainerbattle_single TRAINER_P_BEAT, SweltornDesert_Text_BeatIntro, SweltornDesert_Text_BeatDefeated
    msgbox SweltornDesert_Text_BeatPostBattle, MSGBOX_AUTOCLOSE
    end

SweltornDesert_EventScript_Dotty::
    trainerbattle_single TRAINER_P_DOTTY, SweltornDesert_Text_DottyIntro, SweltornDesert_Text_DottyDefeated
    msgbox SweltornDesert_Text_DottyPostBattle, MSGBOX_AUTOCLOSE
    end

SweltornDesert_Text_SantoIntro:
	.string "Hold it kid! Sweltorn Desert is\n"
	.string "experiencing a pretty severe\l"
	.string "sandstorm right now.\p"
	.string "Do you have a pair of Go-Goggles?$"

SweltornDesert_Text_SantoDefeated:
	.string "Good, it seems you're prepared...$"

SweltornDesert_Text_SantoPostBattle:
	.string "Sandstorms around this area used to be \n"
	.string "pretty minor, but now they're out of\l"
	.string "control...\p"
	.string "...But don't worry, kid!\n"
	.string "Team Ozone will have everything\l"
	.string "under control in no time!$"

SweltornDesert_Text_DorothyIntro:
	.string "intro$"

SweltornDesert_Text_DorothyDefeated:
	.string "defeat$"

SweltornDesert_Text_DorothyPostBattle:
	.string "post$"

SweltornDesert_Text_ErinIntro:
	.string "Who do you think these big ol' bones\n"
	.string "belong to?$"

SweltornDesert_Text_ErinDefeated:
	.string "I wasn't talking about myself!$"

SweltornDesert_Text_ErinPostBattle:
	.string "I'm trying to find out what sort of \n"
	.string "colossal Pokémon these bones once \n"
	.string "were...\n"
	.string "Or maybe it wasn't a Pokémon at all...?$"

SweltornDesert_Text_AaronIntro:
	.string "intro$"

SweltornDesert_Text_AaronDefeated:
	.string "defeat$"

SweltornDesert_Text_AaronPostBattle:
	.string "post$"

SweltornDesert_Text_ThadIntro:
	.string "intro$"

SweltornDesert_Text_ThadDefeated:
	.string "defeat$"

SweltornDesert_Text_ThadPostBattle:
	.string "post$"

SweltornDesert_Text_LeelaIntro:
	.string "Is this the right address?\n"
	.string "I think I'm lost...$"

SweltornDesert_Text_LeelaDefeated:
	.string "Can you give me a five-star review,\n"
	.string "please?$"

SweltornDesert_Text_LeelaPostBattle:
	.string "Hmm, this isn't right...\n"
	.string "I'm trying to find ''Yes Town''.\p"
	.string "You don't suppose someone's punking\n"
	.string "me, do you?$"

SweltornDesert_Text_IckleIntro:
	.string "Woof.. sure is hot here.$"

SweltornDesert_Text_IckleDefeated:
	.string "Good weather for some ice cold treats.$"

SweltornDesert_Text_IcklePostBattle:
	.string "Have some dessert in the desert.$"

SweltornDesert_Text_StaphIntro:
	.string "...Eh? Trainers, out here!?$"

SweltornDesert_Text_StaphDefeated:
	.string "I specifically wanted to avoid this.$"

SweltornDesert_Text_StaphPostBattle:
	.string "Have you been drinking water?\n"
	.string "Yeah, I bet you haven't, you're sweating\l"
	.string "like a Sadsod. Take some of mine.$"

SweltornDesert_Text_HwarangIntro:
	.string "intro$"

SweltornDesert_Text_HwarangDefeated:
	.string "defeat$"

SweltornDesert_Text_HwarangPostBattle:
	.string "post$"

SweltornDesert_Text_TakeshiIntro:
	.string "Those eyes... You hold a love for battle,\n"
	.string "don't you?\p"
	.string "Very well then, show me your passion in\n"
	.string "combat!$"

SweltornDesert_Text_TakeshiDefeated:
	.string "Hmph, as to be expected!$"

SweltornDesert_Text_TakeshiPostBattle:
	.string "You are a very unique trainer.\n"
	.string "Do not squander such a gift!$"

SweltornDesert_Text_BeatIntro:
	.string "intro$"

SweltornDesert_Text_BeatDefeated:
	.string "defeat$"

SweltornDesert_Text_BeatPostBattle:
	.string "post$"

SweltornDesert_Text_DottyIntro:
	.string "intro$"

SweltornDesert_Text_DottyDefeated:
	.string "defeat$"

SweltornDesert_Text_DottyPostBattle:
	.string "post$"
