JaggroPass_MapScripts::
	.byte 0

JaggroPass_EventScript_GravelitoIdle::
	lock
	setflag FLAG_TEMP_A
	clearflag FLAG_TEMP_B
	msgbox JaggroPass_Text_ItsHumming, MSGBOX_DEFAULT
	goto JaggroPass_EventScript_CheckSing
	release
	end

JaggroPass_EventScript_MegalitoIdle::
	lock
	clearflag FLAG_TEMP_A
	setflag FLAG_TEMP_B
	msgbox JaggroPass_Text_ItsBellowing, MSGBOX_DEFAULT
	goto JaggroPass_EventScript_CheckSing
	release
	end

JaggroPass_EventScript_CheckSing::
	checkpartynonhmmove MOVE_SING
	goto_if_eq VAR_RESULT, PARTY_SIZE, JaggroPass_EventScript_CheckPerishSong
	goto_if_set FLAG_TEMP_A, JaggroPass_EventScript_GravelitoBattle
	goto_if_set FLAG_TEMP_B, JaggroPass_EventScript_MegalitoBattle
	release
	end

JaggroPass_EventScript_CheckPerishSong::
	checkpartynonhmmove MOVE_PERISH_SONG
	goto_if_eq VAR_RESULT, PARTY_SIZE, JaggroPass_EventScript_CheckGrassWhistle
	goto_if_set FLAG_TEMP_A, JaggroPass_EventScript_GravelitoBattle
	goto_if_set FLAG_TEMP_B, JaggroPass_EventScript_MegalitoBattle
	release
	end

JaggroPass_EventScript_CheckGrassWhistle::
	checkpartynonhmmove MOVE_GRASS_WHISTLE
	goto_if_eq VAR_RESULT, PARTY_SIZE, JaggroPass_EventScript_CheckRound
	goto_if_set FLAG_TEMP_A, JaggroPass_EventScript_GravelitoBattle
	goto_if_set FLAG_TEMP_B, JaggroPass_EventScript_MegalitoBattle
	release
	end

JaggroPass_EventScript_CheckRound::
	checkpartynonhmmove MOVE_ROUND
	goto_if_eq VAR_RESULT, PARTY_SIZE, JaggroPass_EventScript_CheckSparklingAria
	goto_if_set FLAG_TEMP_A, JaggroPass_EventScript_GravelitoBattle
	goto_if_set FLAG_TEMP_B, JaggroPass_EventScript_MegalitoBattle
	release
	end

JaggroPass_EventScript_CheckSparklingAria::
	checkpartynonhmmove MOVE_SPARKLING_ARIA
	goto_if_eq VAR_RESULT, PARTY_SIZE, JaggroPass_EventScript_CheckTorchSong
	goto_if_set FLAG_TEMP_A, JaggroPass_EventScript_GravelitoBattle
	goto_if_set FLAG_TEMP_B, JaggroPass_EventScript_MegalitoBattle
	release
	end

JaggroPass_EventScript_CheckTorchSong::
	checkpartynonhmmove MOVE_TORCH_SONG
	goto_if_eq VAR_RESULT, PARTY_SIZE, JaggroPass_EventScript_CheckBeatbox
	goto_if_set FLAG_TEMP_A, JaggroPass_EventScript_GravelitoBattle
	goto_if_set FLAG_TEMP_B, JaggroPass_EventScript_MegalitoBattle
	release
	end

JaggroPass_EventScript_CheckBeatbox::
	checkpartynonhmmove MOVE_BEATBOX
	goto_if_eq VAR_RESULT, PARTY_SIZE, JaggroPass_EventScript_CheckBeatDrop
	goto_if_set FLAG_TEMP_A, JaggroPass_EventScript_GravelitoBattle
	goto_if_set FLAG_TEMP_B, JaggroPass_EventScript_MegalitoBattle
	release
	end

JaggroPass_EventScript_CheckBeatDrop::
	checkpartynonhmmove MOVE_BEAT_DROP
	goto_if_eq VAR_RESULT, PARTY_SIZE, JaggroPass_EventScript_NoSingingMoves
	goto_if_set FLAG_TEMP_A, JaggroPass_EventScript_GravelitoBattle
	goto_if_set FLAG_TEMP_B, JaggroPass_EventScript_MegalitoBattle
	release
	end

JaggroPass_EventScript_NoSingingMoves::
	msgbox JaggroPass_Text_NoSingingMove, MSGBOX_AUTOCLOSE
	speakername NULL
	release
	end

JaggroPass_EventScript_GravelitoBattle::
	lock
	msgbox JaggroPass_Text_ItBecameLively, MSGBOX_DEFAULT
	closemessage
	setwildbattle SPECIES_GRAVELITO, 31
	playmoncry SPECIES_GRAVELITO, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	dowildbattle
	removeobject VAR_LAST_TALKED
	release
	end

JaggroPass_EventScript_MegalitoBattle::
	lock
	msgbox JaggroPass_Text_ItBecameLively, MSGBOX_DEFAULT
	closemessage
	setwildbattle SPECIES_MEGALITO, 35
	playmoncry SPECIES_MEGALITO, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	dowildbattle
	removeobject VAR_LAST_TALKED
	release
	end

JaggroPass_EventScript_Emmy::
    trainerbattle_single TRAINER_P_EMMY, JaggroPass_Text_EmmyIntro, JaggroPass_Text_EmmyDefeated
    msgbox JaggroPass_Text_EmmyPostBattle, MSGBOX_AUTOCLOSE
    end

JaggroPass_EventScript_Dayton::
    trainerbattle_single TRAINER_P_DAYTON, JaggroPass_Text_DaytonIntro, JaggroPass_Text_DaytonDefeated
    msgbox JaggroPass_Text_DaytonPostBattle, MSGBOX_AUTOCLOSE
    end

JaggroPass_EventScript_Anto::
    trainerbattle_single TRAINER_P_ANTO, JaggroPass_Text_AntoIntro, JaggroPass_Text_AntoDefeated
    msgbox JaggroPass_Text_AntoPostBattle, MSGBOX_AUTOCLOSE
    end

JaggroPass_EventScript_Baze::
    trainerbattle_single TRAINER_P_BAZE, JaggroPass_Text_BazeIntro, JaggroPass_Text_BazeDefeated
    msgbox JaggroPass_Text_BazePostBattle, MSGBOX_AUTOCLOSE
    end

JaggroPass_EventScript_Chinzao::
    trainerbattle_single TRAINER_P_CHINZAO, JaggroPass_Text_ChinzaoIntro, JaggroPass_Text_ChinzaoDefeated
    msgbox JaggroPass_Text_ChinzaoPostBattle, MSGBOX_AUTOCLOSE
    end

JaggroPass_EventScript_Marimar::
    trainerbattle_single TRAINER_P_MARIMAR, JaggroPass_Text_MarimarIntro, JaggroPass_Text_MarimarDefeated
    msgbox JaggroPass_Text_MarimarPostBattle, MSGBOX_AUTOCLOSE
    end

JaggroPass_EventScript_Jelly::
    trainerbattle_single TRAINER_P_JELLY, JaggroPass_Text_JellyIntro, JaggroPass_Text_JellyDefeated
    msgbox JaggroPass_Text_JellyPostBattle, MSGBOX_AUTOCLOSE
    end

JaggroPass_Text_EmmyIntro:
	.string "intro$"

JaggroPass_Text_EmmyDefeated:
	.string "defeat$"

JaggroPass_Text_EmmyPostBattle:
	.string "post$"

JaggroPass_Text_DaytonIntro:
	.string "Let's soak up some Vitamin D!\n"
	.string "It's good for you!$"

JaggroPass_Text_DaytonDefeated:
	.string "I've just absorbed some\n"
	.string "Vitamin D-feat...$"

JaggroPass_Text_DaytonPostBattle:
	.string "All kinds of Pokémon like the desert\n"
	.string "sun. Berries like the sun, too!$"

JaggroPass_Text_AntoIntro:
	.string "Na-a-a! Wrong way.$"

JaggroPass_Text_AntoDefeated:
	.string "I said wrong way!!$"

JaggroPass_Text_AntoPostBattle:
	.string "Fine, you can go, since you beat\n"
	.string "grandpa.$"

JaggroPass_Text_BazeIntro:
	.string "intro$"

JaggroPass_Text_BazeDefeated:
	.string "defeat$"

JaggroPass_Text_BazePostBattle:
	.string "post$"

JaggroPass_Text_ChinzaoIntro:
	.string "intro$"

JaggroPass_Text_ChinzaoDefeated:
	.string "defeat$"

JaggroPass_Text_ChinzaoPostBattle:
	.string "post$"

JaggroPass_Text_MarimarIntro:
	.string "Hey doll, did it hurt when you fell from\n"
	.string "heaven?$"

JaggroPass_Text_MarimarDefeated:
	.string "Ouchie... That hurt...$"

JaggroPass_Text_MarimarPostBattle:
	.string "Did it hurt when you fell from heaven?\p"
	.string "Because you have a tough outer shell\n"
	.string "like a Minior does...$"

JaggroPass_Text_JellyIntro:
	.string "intro$"

JaggroPass_Text_JellyDefeated:
	.string "defeat$"

JaggroPass_Text_JellyPostBattle:
	.string "post$"

JaggroPass_Text_ItsHumming:
	.string "$"

JaggroPass_Text_ItsBellowing:
	.string "$"

JaggroPass_Text_NoSingingMove:
	.string "$"

JaggroPass_Text_ItBecameLively:
	.string "$"
