SootopolisCastle_MapScripts::
	.byte 0

SootopolisCastle_EventScript_LusckawBattle::
	lock
	goto_if_lt VAR_ORBS_QUEST_STATE, 1, SootopolisCastle_EventScript_StonePokeball
	goto_if_gt VAR_ORBS_QUEST_STATE, 1, SootopolisCastle_EventScript_StonePokeballPost
	msgbox SootopolisCastle_Text_TheStonePokeballIsReacting, MSGBOX_DEFAULT
	setwildbattle SPECIES_LUSCKAW, 38
	settotemboost B_POSITION_OPPONENT_LEFT, 0, 3, 0, 0, 3
	playmoncry SPECIES_LUSCKAW, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	msgbox SootopolisCastle_Text_ItsADragon, MSGBOX_DEFAULT
	setflag FLAG_WILD_NO_CATCHING_FLAG
	setflag FLAG_WILD_NO_RUNNING_FLAG
	setflag FLAG_SMART_WILD_AI_FLAG
	delay 4
	dowildbattle
	delay 8
	clearflag FLAG_WILD_NO_CATCHING_FLAG
	clearflag FLAG_WILD_NO_RUNNING_FLAG
	clearflag FLAG_SMART_WILD_AI_FLAG
	msgbox SootopolisCastle_Text_TheLusckawDroppedSomething, MSGBOX_DEFAULT
	giveitem ITEM_POISON_ORB
	closemessage
	setvar VAR_ORBS_QUEST_STATE, 2
	delay 16
	playse SE_M_SWORDS_DANCE
	waitse
	playse SE_M_BUBBLE_BEAM2
	msgbox SootopolisCastle_Text_TheMapPointsToPerplume, MSGBOX_DEFAULT
	closemessage
	release
	end

SootopolisCastle_EventScript_StonePokeball::
	msgbox SootopolisCastle_Text_StonePokeball, MSGBOX_AUTOCLOSE
	release
	end

SootopolisCastle_EventScript_StonePokeballPost::
	msgbox SootopolisCastle_Text_StonePokeballPost, MSGBOX_AUTOCLOSE
	release
	end

SootopolisCastle_Text_StonePokeball:
	.string "(It's an ancient looking\n"
	.string "Pokeball made of stone.)$"

SootopolisCastle_Text_TheStonePokeballIsReacting:
	.string "(!)\p"
	.string "(The stone Pokeball is reacting\n"
	.string "to the presence of your map!)\p"
	.string "(It begins to open...)\n$"

SootopolisCastle_Text_ItsADragon:
	.string "(A dragon is emerging\n"
	.string "from the ancient Pokeball...!)$"

SootopolisCastle_Text_TheLusckawDroppedSomething:
	.string "(The Lusckaw you defeated\n"
	.string "left something behind...)$"

SootopolisCastle_Text_TheMapPointsToPerplume:
	.string "(Your magical map shines once more,\n"
	.string "pointing you to a new location.)\p"
	.string "(This time, it is leading you\n"
	.string "to a great tree in Perplume Maze...)$"

SootopolisCastle_Text_StonePokeballPost:
	.string "(It's the stone Pokeball that\n"
	.string "a Lusckaw was once kept inside of.)$"
