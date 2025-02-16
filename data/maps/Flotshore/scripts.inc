.set LOCALID_BARRELFISHER, 19

Flotshore_MapScripts::
	.byte 0

Flotshore_EventScript_Sean::
    trainerbattle_single TRAINER_P_SEAN, Flotshore_Text_SeanIntro, Flotshore_Text_SeanDefeated
    msgbox Flotshore_Text_SeanPostBattle, MSGBOX_AUTOCLOSE
    end

Flotshore_EventScript_Janice::
    trainerbattle_single TRAINER_P_JANICE, Flotshore_Text_JaniceIntro, Flotshore_Text_JaniceDefeated
    msgbox Flotshore_Text_JanicePostBattle, MSGBOX_AUTOCLOSE
    end

Flotshore_EventScript_Jimmy::
    trainerbattle_single TRAINER_P_JIMMY, Flotshore_Text_JimmyIntro, Flotshore_Text_JimmyDefeated
    msgbox Flotshore_Text_JimmyPostBattle, MSGBOX_AUTOCLOSE
    end

Flotshore_EventScript_Dan::
    trainerbattle_single TRAINER_P_DAN, Flotshore_Text_DanIntro, Flotshore_Text_DanDefeated
    msgbox Flotshore_Text_DanPostBattle, MSGBOX_AUTOCLOSE
    end

Flotshore_EventScript_Lad::
    trainerbattle_single TRAINER_P_LAD, Flotshore_Text_LadIntro, Flotshore_Text_LadDefeated
    msgbox Flotshore_Text_LadPostBattle, MSGBOX_AUTOCLOSE
    end

Flotshore_EventScript_Sammie::
    trainerbattle_single TRAINER_P_SAMMIE, Flotshore_Text_SammieIntro, Flotshore_Text_SammieDefeated
    msgbox Flotshore_Text_SammiePostBattle, MSGBOX_AUTOCLOSE
    end

Flotshore_EventScript_Barbara::
    trainerbattle_single TRAINER_P_BARBARA, Flotshore_Text_BarbaraIntro, Flotshore_Text_BarbaraDefeated
    msgbox Flotshore_Text_BarbaraPostBattle, MSGBOX_AUTOCLOSE
    end

Flotshore_EventScript_SeaShellGiver::
    lock
	faceplayer
	goto_if_set FLAG_RECEIVED_SEASHELL_2, Flotshore_EventScript_GaveSeashellAlr
	msgbox Flotshore_Text_HaveMyShell, MSGBOX_DEFAULT
	giveitem ITEM_SHOAL_SHELL
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_SEASHELL_2
	release
	end

Flotshore_EventScript_GaveSeashellAlr::
    msgbox Flotshore_Text_GaveSeashellAlr, MSGBOX_AUTOCLOSE
    release
    end

Flotshore_EventScript_PounceFlagTest::
	lock
	setflag FLAG_RECEIVED_TM_POUNCE
	msgbox Flotshore_Text_Gugumbir, MSGBOX_AUTOCLOSE
	release
	end

Flotshore_EventScript_VacuumWaveJanitor::
    lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM_VACUUM_WAVE, Flotshore_EventScript_GaveVacuumWave
	msgbox Flotshore_Text_VacuumingTheWater, MSGBOX_DEFAULT
	giveitem ITEM_TM_VACUUM_WAVE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM_VACUUM_WAVE
	release
	end

Flotshore_EventScript_GaveVacuumWave::
    msgbox Flotshore_Text_MakingProgress, MSGBOX_AUTOCLOSE
    release
    end

Flotshore_EventScript_PounceBarrel::
    lock
	clearflag FLAG_RECEIVED_TM_POUNCE
	addobject LOCALID_BARRELFISHER
	applymovement LOCALID_BARRELFISHER, Flotshore_Movement_JumpFromBarrel
	waitmovement 0
	checkitem ITEM_TM_POUNCE
	goto_if_eq VAR_RESULT, TRUE, Flotshore_EventScript_GavePounce
	msgbox Flotshore_Text_GotYou, MSGBOX_DEFAULT
	giveitem ITEM_TM_POUNCE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setvar VAR_TEMP_1, 1
	setflag FLAG_RECEIVED_TM_POUNCE
	applymovement LOCALID_BARRELFISHER, Flotshore_Movement_JumpIntoBarrel
	waitmovement 0
	release
	end

Flotshore_Movement_JumpFromBarrel:
	set_visible
	jump_right
	face_right
	step_end

Flotshore_Movement_JumpIntoBarrel:
	jump_left
	face_left
	set_invisible
	step_end

Flotshore_EventScript_GavePounce::
    msgbox Flotshore_Text_AlreadyGotYou, MSGBOX_AUTOCLOSE
	setvar VAR_TEMP_1, 1
	setflag FLAG_RECEIVED_TM_POUNCE
	applymovement LOCALID_BARRELFISHER, Flotshore_Movement_JumpIntoBarrel
	waitmovement 0
    release
    end

Flotshore_EventScript_Starfishmonger::
	msgbox Flotshore_Text_Starfishmonger, MSGBOX_NPC
	end

Flotshore_EventScript_FloatieGirl::
	msgbox Flotshore_Text_FloatieGirl, MSGBOX_NPC
	end

Flotshore_EventScript_GoldAngler::
	msgbox Flotshore_Text_GoldAngler, MSGBOX_NPC
	end

Flotshore_EventScript_PacifidlogSign::
	msgbox Flotshore_Text_PacifidlogSign, MSGBOX_SIGN
	end

Flotshore_EventScript_BasalinSign::
	msgbox Flotshore_Text_BasalinSign, MSGBOX_SIGN
	end

Flotshore_EventScript_SailorsPauseSign::
	msgbox Flotshore_Text_SailorsPauseSign, MSGBOX_SIGN
	end

Flotshore_Text_GotYou:
	.string "BOOGA BOOGA BOOGA!!!\p"
	.string "Haha! Did I getcha? Come on now,\n"
	.string "lighten up! We're havin' as much\l"
	.string "fun as a BARREL of monkeys!!\p"
	.string "Haha! Here's my apology for\n"
	.string "the sensory overload.\p"
	.string "Take this and maybe YOU can get\n"
	.string "the drop on someone else!$"

Flotshore_Text_AlreadyGotYou:
	.string "BOOGA...boo...ga...\p"
	.string "Hey! I already jumpscared you\n"
	.string "before! Leave room for another sucker!$"

Flotshore_Text_VacuumingTheWater:
	.string "(This janitor is using her\n"
	.string "vacuum to shhhhhlerrrp up\l"
	.string "gallons of sea water.)\p"
	.string "I'm cleaning! All in a day's\n"
	.string "work for a janitor!\p"
	.string "You're a trainer, right? Why\n"
	.string "not take this TM with you?\l"
	.string "That way your Pokemon can...\l"
	.string "giggle... clean up\l"
	.string "the competition!$"

Flotshore_Text_MakingProgress:
	.string "(Is she making progress?\n"
	.string "Not particularly. The vacuum\l"
	.string "is almost filled with water.\l"
	.string "What then? Who can say.)$"

Flotshore_Text_Gugumbir:
	.string "test$"

Flotshore_Text_SeanIntro:
	.string "Sand Dollars for sale!\p"
	.string "1 Sand Dollar will cost...\n"
	.string "1000 PokeDollars!\p"
	.string "Th-that conversion rate is\n"
	.string "a good deal...!$"

Flotshore_Text_SeanDefeated:
	.string "I see you AREN'T interested!$"

Flotshore_Text_SeanPostBattle:
	.string "I'm trying to create a\n"
	.string "new economy here! My momma\l"
	.string "told me to be an entrepeneur!\p"
	.string "(He pronounced it wrong.)$"

Flotshore_Text_JaniceIntro:
	.string "You'll beat me when pigs fly!$"

Flotshore_Text_JaniceDefeated:
	.string "Pigs fly all over!\n"
	.string "I was t-telling you that\l"
	.string "I wasn't very tough...$"

Flotshore_Text_JanicePostBattle:
	.string "I wish my piggy didn't fly too\n"
	.string "fast when she's excited...\l"
	.string "I can't catch up...$"

Flotshore_Text_JimmyIntro:
	.string "I'm something of a boy\n"
	.string "genius, y'know!$"

Flotshore_Text_JimmyDefeated:
	.string "Even my super-powered mind\n"
	.string "couldn't measure up…$"

Flotshore_Text_JimmyPostBattle:
	.string "Hope you have a knack for adventure!\n"
	.string "The route branches off up ahead.$"

Flotshore_Text_DanIntro:
	.string "Is there anythin' better than fishin'?$"

Flotshore_Text_DanDefeated:
	.string "I suppose battlin' is a close second.$"

Flotshore_Text_DanPostBattle:
	.string "Y'know, plenty o' people go fishin'\n"
	.string "all of their lives, without knowin'\l"
	.string "that it ain't the fish\l"
	.string "they are really after.\p"
	.string "There's a little wisdom for ya'.$"

Flotshore_Text_LadIntro:
	.string "I'm a simple lad.\p"
	.string "Caught one fish.\p"
	.string "Stickin' with him.$"

Flotshore_Text_LadDefeated:
	.string "TOO simple.$"

Flotshore_Text_LadPostBattle:
	.string "I just know my guppy'll\n"
	.string "grow to a downright ginormous\l"
	.string "shark one day.\p"
	.string "Then they won't be laughin'.$"

Flotshore_Text_SammieIntro:
	.string "I found the coolest shells\n"
	.string "today! Cooler than my friends'!$"

Flotshore_Text_SammieDefeated:
	.string "Even though I lost, I'm still\n"
	.string "winning the shell contest!$"

Flotshore_Text_SammiePostBattle:
	.string "Look real hard the next time\n"
	.string "ya go shell huntin'!\l"
	.string "You never know when you might\l"
	.string "pass up something shiny!$"

Flotshore_Text_BarbaraIntro:
	.string "I wonder, what kind of\n"
	.string "Pokémon do you use?\p"
	.string "Ones that are good at battle, or\n"
	.string "ones that can help you outside of it?$"

Flotshore_Text_BarbaraDefeated:
	.string "Hmm... Perhaps,\n"
	.string "a healthy mix of both is best.$"

Flotshore_Text_BarbaraPostBattle:
	.string "My Pokémon help me swim around\n"
	.string "the local waterways when I\l"
	.string "want to find a new fishing spot.$"

Flotshore_Text_HaveMyShell:
	.string "I love searchin' underneath\n"
	.string "the boards!\p"
	.string "Here, take this shell\n"
	.string "I found down there.$"

Flotshore_Text_GaveSeashellAlr:
	.string "I think I'll make a fort\n"
	.string "down there… just for me!$"

Flotshore_Text_Starfishmonger:
	.string "My business partner and I\n"
	.string "exclusively deal in starfish.\p"
	.string "Not to eat. Just for, like,\n"
	.string "decoration.\p"
	.string "I have no idea why they sell,\n"
	.string "but they do, so off to collect\l"
	.string "them I go.$"

Flotshore_Text_FloatieGirl:
	.string "I hate these stupid floaties!\n"
	.string "They look real dumb! I want\l"
	.string "an inner tube like the cool kids!$"

Flotshore_Text_GoldAngler:
	.string "Keep this on the down low, but\n"
	.string "I've been findin' some gold coins\l"
	.string "when fishin' around this dock.\p"
	.string "Y'know, that rocky outcropping\n"
	.string "next to us has a little cave\l"
	.string "in it. Maybe the coins are\l"
	.string "remnants of some long-gone\l"
	.string "pirate crew's treasure lost\l"
	.string "within it?\p"
	.string "Nah, that's too out there.$"

Flotshore_Text_PacifidlogSign:
	.string "WEST - Pacifidlog Town$"

Flotshore_Text_BasalinSign:
	.string "NORTH - Basalin Coast\p"
	.string "Please keep the stone\n"
	.string "pathways free of litter!$"

Flotshore_Text_SailorsPauseSign:
	.string "Recreational travel strongly\n"
	.string "discouraged south of this point.$"
