.set LOCALID_JUAN, 13
.set LOCALID_SEBASTIAN, 14

SootopolisCity_Gym_B1F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SootopolisCity_Gym_B1F_OnFrame
	.byte 0

SootopolisCity_Gym_B1F_OnFrame:
	map_script_2 VAR_ICE_STEP_COUNT, 113, SootopolisCity_Gym_B1F_EventScript_JuanBattleStart
	.2byte 0

SootopolisCity_Gym_B1F_EventScript_JuanBattleStart::
	setvar VAR_ICE_STEP_COUNT, 0
	playse SE_PIN
	applymovement LOCALID_JUAN, SootopolisCity_Gym_B1F_Movement_JuanInterrupted
	applymovement OBJ_EVENT_ID_PLAYER, SootopolisCity_Gym_B1F_Movement_PlayerInterrupts
	waitmovement 0
	speakername SootopolisCity_Gym_B1F_Text_NameJuan
	msgbox SootopolisCity_Gym_B1F_Text_JuanNotices, MSGBOX_AUTOCLOSE
	applymovement LOCALID_JUAN, SootopolisCity_Gym_B1F_Movement_JuanMoveIntoPlace
	applymovement LOCALID_SEBASTIAN, SootopolisCity_Gym_B1F_Movement_SebastianMoveIntoPlace
	waitmovement 0
	speakername SootopolisCity_Gym_B1F_Text_NameSebastian
	msgbox SootopolisCity_Gym_B1F_Text_ImSebastian, MSGBOX_AUTOCLOSE
	applymovement LOCALID_JUAN, SootopolisCity_Gym_B1F_Movement_Talking
	speakername SootopolisCity_Gym_B1F_Text_NameJuan
	msgbox SootopolisCity_Gym_B1F_Text_BattleBegins, MSGBOX_DEFAULT
	playse SE_APPLAUSE
	delay 30
	delay 30
	delay 30
	delay 30
	speakername NULL
    trainerbattle_two_trainers TRAINER_P_JUAN, SootopolisCity_Gym_B1F_Text_JuanIntro, TRAINER_P_SEBASTIAN, SootopolisCity_Gym_B1F_Text_JuanDefeat, SootopolisCity_Gym_B1F_EventScript_JuanDefeated, NO_MUSIC
	goto SootopolisCity_Gym_B1F_EventScript_JuanDefeated
	goto_if_unset FLAG_RECEIVED_TM_WATER_PULSE, SootopolisCity_Gym_B1F_EventScript_GiveWaterPulse2
	msgbox SootopolisCity_Gym_B1F_Text_JuanPostBattle, MSGBOX_DEFAULT
	release
	end

SootopolisCity_Gym_B1F_Movement_JuanInterrupted:
	emote_exclamation_mark
	face_down
	step_end

SootopolisCity_Gym_B1F_Movement_PlayerInterrupts:
	face_up
	step_end

SootopolisCity_Gym_B1F_Movement_JuanMoveIntoPlace:
	walk_left
	face_down
	step_end

SootopolisCity_Gym_B1F_Movement_SebastianMoveIntoPlace:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	face_down
	step_end

SootopolisCity_Gym_B1F_Movement_Talking:
	walk_in_place_slow_down
	step_end

SootopolisCity_Gym_B1F_EventScript_JuanDefeated::
	speakername SootopolisCity_Gym_B1F_Text_NameJuan
	msgbox SootopolisCity_Gym_B1F_Text_GivePlayerTheWinnings, MSGBOX_DEFAULT
	applymovement LOCALID_SEBASTIAN, SootopolisCity_Gym_B1F_Movement_SebastianGiveItems
	speakername SootopolisCity_Gym_B1F_Text_NameSebastian
	msgbox SootopolisCity_Gym_B1F_Text_GivePlayerBadge, MSGBOX_DEFAULT
	speakername NULL
	message SootopolisCity_Gym_B1F_Text_ReceivedRainBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	speakername SootopolisCity_Gym_B1F_Text_NameSebastian
	msgbox SootopolisCity_Gym_B1F_Text_ExplainRainBadgeTakeThis, MSGBOX_DEFAULT
	clearflag FLAG_PISCES_A
	clearflag FLAG_PISCES_B
	clearflag FLAG_PISCES_C
	clearflag FLAG_PISCES_D
	clearflag FLAG_PISCES_E
	clearflag FLAG_PISCES_F
	clearflag FLAG_HIDE_SOOTOPOLIS_CITY_WALLACE
	addvar VAR_PISCES_STORY_PROGRESS, 1
	setvar VAR_BIRCH_LAB_STATE, 8
	setvar VAR_NEW_COO_STATE, 1
	setflag FLAG_DEFEATED_RUSTBORO_GYM
	setflag FLAG_BADGE01_GET
	setvar VAR_SOOTOPOLIS_CITY_STATE, 6
	call SootopolisCity_Gym_B1F_EventScript_GiveWaterPulse
	closemessage
	delay 30
	applymovement LOCALID_JUAN, SootopolisCity_Gym_B1F_Movement_Talking
	speakername SootopolisCity_Gym_B1F_Text_NameJuan
	msgbox SootopolisCity_Gym_B1F_Text_GetOuttaHere, MSGBOX_DEFAULT
	speakername NULL
	warp MAP_NEW_SOOTO, 41, 16
	release
	end

SootopolisCity_Gym_B1F_Movement_SebastianGiveItems:
	walk_left
	face_down
	step_end

SootopolisCity_Gym_B1F_EventScript_GiveWaterPulse::
	giveitem ITEM_TM_AVALANCHE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	giveitem ITEM_TM_COVET
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	setflag FLAG_RECEIVED_TM_WATER_PULSE
	return

SootopolisCity_Gym_B1F_EventScript_GiveWaterPulse2::
	giveitem ITEM_TM_AVALANCHE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	giveitem ITEM_TM_COVET
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox SootopolisCity_Gym_B1F_Text_ExplainWaterPulse, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_WATER_PULSE
	release
	end

SootopolisCity_Gym_B1F_EventScript_DontGoOnStage::
	lock
	msgbox SootopolisCity_Gym_B1F_Text_DontGoOnStage, MSGBOX_AUTOCLOSE
	applymovement OBJ_EVENT_ID_PLAYER, SootopolisCity_Gym_B1F_Movement_GetOff
	waitmovement 0
	release
	end

SootopolisCity_Gym_B1F_EventScript_Bouncer::
	msgbox SootopolisCity_Gym_B1F_Text_DontGoOnStage, MSGBOX_NPC
	end

SootopolisCity_Gym_B1F_Movement_GetOff:
	walk_down
	step_end

SootopolisCity_Gym_B1F_EventScript_Arthur::
	trainerbattle_single TRAINER_P_ARTHUR, SootopolisCity_Gym_B1F_Text_ArthurIntro, SootopolisCity_Gym_B1F_Text_ArthurDefeat
	msgbox SootopolisCity_Gym_B1F_Text_ArthurPostBattle, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_B1F_EventScript_Hasparoth::
	trainerbattle_single TRAINER_P_HASPAROTH, SootopolisCity_Gym_B1F_Text_HasparothIntro, SootopolisCity_Gym_B1F_Text_HasparothDefeat
	msgbox SootopolisCity_Gym_B1F_Text_HasparothPostBattle, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_B1F_EventScript_Lisa::
	trainerbattle_single TRAINER_P_LISA, SootopolisCity_Gym_B1F_Text_LisaIntro, SootopolisCity_Gym_B1F_Text_LisaDefeat
	msgbox SootopolisCity_Gym_B1F_Text_LisaPostBattle, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_B1F_EventScript_Miikachan::
	trainerbattle_single TRAINER_P_MIIKACHAN, SootopolisCity_Gym_B1F_Text_MiikachanIntro, SootopolisCity_Gym_B1F_Text_MiikachanDefeat
	msgbox SootopolisCity_Gym_B1F_Text_MiikachanPostBattle, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_B1F_EventScript_Emily::
	trainerbattle_single TRAINER_P_EMILY, SootopolisCity_Gym_B1F_Text_EmilyIntro, SootopolisCity_Gym_B1F_Text_EmilyDefeat
	msgbox SootopolisCity_Gym_B1F_Text_EmilyPostBattle, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_B1F_EventScript_GlassCeiling::
	msgbox SootopolisCity_Gym_B1F_Text_GlassCeiling, MSGBOX_NPC
	end

SootopolisCity_Gym_B1F_EventScript_DropIn::
	msgbox SootopolisCity_Gym_B1F_Text_DropIn, MSGBOX_NPC
	end

SootopolisCity_Gym_B1F_EventScript_Bartender::
    lock
	faceplayer
	showmoneybox 0, 0
	msgbox SootopolisCity_Gym_B1F_Text_HowMayIServeYou, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SootopolisCity_Gym_B1F_EventScript_CheckMoneyForSP
	closemessage
	hidemoneybox
	release
	end

SootopolisCity_Gym_B1F_EventScript_CheckMoneyForSP::
	checkmoney 250
	goto_if_eq VAR_RESULT, FALSE, SootopolisCity_Gym_B1F_EventScript_NotEnoughMoney
	playse SE_SHOP
	removemoney 250
	updatemoneybox
	delay 40
	hidemoneybox
	giveitem ITEM_SODA_POP
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	release
	end

SootopolisCity_Gym_B1F_EventScript_NotEnoughMoney::
	msgbox SootopolisCity_Gym_B1F_Text_NotEnoughMoney, MSGBOX_DEFAULT
	closemessage
	hidemoneybox
	release
	end

SootopolisCity_Gym_B1F_Text_NameJuan:
	.string "Juan$"

SootopolisCity_Gym_B1F_Text_NameSebastian:
	.string "Sebastian$"

SootopolisCity_Gym_B1F_Text_HowMayIServeYou:
	.string "Greetings.\n"
	.string "What may I get for you?\p"
	.string "…For someone your age, I am only at\n"
	.string "my liberty to offer you Soda Pop.\p"
	.string "Would you like one?$"

SootopolisCity_Gym_B1F_Text_NotEnoughMoney:
	.string "I'm afraid you lack the funds.$"

SootopolisCity_Gym_B1F_Text_GlassCeiling:
	.string "Ah, the ceiling of this establishment\n"
	.string "is a marvel.\p"
	.string "Why, it is made of perfectly\n"
	.string "solidified ice!\p"
	.string "Delicate materials are always the\n"
	.string "most beautiful…$"

SootopolisCity_Gym_B1F_Text_DropIn:
	.string "I happen to be Juan's\n"
	.string "number-Juan fan!\p"
	.string "Wish his bodyguard would recognize and\n"
	.string "let me come to the stage…\p"
	.string "If only I could dramatically\n"
	.string "drop in from above…!$"

SootopolisCity_Gym_B1F_Text_ArthurIntro:
	.string "Ice and Fairy are the two\n"
	.string "most elegant types.\l"
	.string "Befitting a man of my status,\l"
	.string "would you not say?$"

SootopolisCity_Gym_B1F_Text_ArthurDefeat:
	.string "Elegant, yet not unbeatable...$"

SootopolisCity_Gym_B1F_Text_ArthurPostBattle:
	.string "Try walking with a purpose.\n"
	.string "Not planning your movement\l"
	.string "can lead to you faltering.$"

SootopolisCity_Gym_B1F_Text_HasparothIntro:
	.string "Cards on the table, I shall\n"
	.string "fend you off from interrupting\l"
	.string "my comrade Juan's performance!$"

SootopolisCity_Gym_B1F_Text_HasparothDefeat:
	.string "I tip my hat to you, trainer.$"

SootopolisCity_Gym_B1F_Text_HasparothPostBattle:
	.string "Mayhaps you do belong up\n"
	.string "on the stage after all...$"

SootopolisCity_Gym_B1F_Text_EmilyIntro:
	.string "I purchased this speically bred\n"
	.string "Pokemon for a high price!\l"
	.string "She won't be losing, trust me!$"

SootopolisCity_Gym_B1F_Text_EmilyDefeat:
	.string "B-But...! It was so much money!$"

SootopolisCity_Gym_B1F_Text_EmilyPostBattle:
	.string "I shudder to think it...\n"
	.string "but I may have been fleeced...$"

SootopolisCity_Gym_B1F_Text_LisaIntro:
	.string "Apologies, challenger.\n"
	.string "But I cannot allow you\l"
	.string "up these stairs.$"

SootopolisCity_Gym_B1F_Text_LisaDefeat:
	.string "Great tactical play...$"

SootopolisCity_Gym_B1F_Text_LisaPostBattle:
	.string "I may not look it, but I am\n"
	.string "the captain of Juan's bodyguards.\l"
	.string "If you can get through me,\l"
	.string "you can get through anything.$"

SootopolisCity_Gym_B1F_Text_MiikachanIntro:
	.string "When I'm with my POKéMON, the time\n"
	.string "flies by before you can say, “Oops!”$"

SootopolisCity_Gym_B1F_Text_MiikachanDefeat:
	.string "Oops!$"

SootopolisCity_Gym_B1F_Text_MiikachanPostBattle:
	.string "I wish I could forget about lost causes\n"
	.string "before I can manage an “Oops!”$"

SootopolisCity_Gym_B1F_Text_JuanIntro:
	.string "Hmph. You weathered my harsh winter…$"

SootopolisCity_Gym_B1F_Text_JuanDefeat:
	.string "'Twas an honor.$"

SootopolisCity_Gym_B1F_Text_GivePlayerTheWinnings:
	.string "Sebastian. Please give our guest\n"
	.string "their winnings.$"

SootopolisCity_Gym_B1F_Text_GivePlayerBadge:
	.string "It is my pleasure to bestow upon you…\n"
	.string "the Margarita Badge.$"

SootopolisCity_Gym_B1F_Text_ReceivedRainBadge:
	.string "{PLAYER} received the\n"
	.string "Margarita Badge\l"
	.string "from Juan and Sebastian.$"

SootopolisCity_Gym_B1F_Text_ExplainRainBadgeTakeThis:
	.string "This badge gives you the privelege of\n"
	.string "being able to utilize the field move,\l"
	.string "Rock Smash.\p"
	.string "In addition, Master Juan would like\n"
	.string "you to have these two TMs.$"

SootopolisCity_Gym_B1F_Text_ExplainWaterPulse:
	.string "tesat$"

SootopolisCity_Gym_B1F_Text_RegisteredJuan:
	.string "shouldnt appear$"

SootopolisCity_Gym_B1F_Text_JuanPostBattle:
	.string "shouldnt appear$"

SootopolisCity_Gym_B1F_Text_JuanNotices:
	.string "Heavens above!\p"
	.string "Challenger, how DARE you drop in on\n"
	.string "this performance unnanounced!\p"
	.string "Hmph.\n"
	.string "And here I was, thinking I was going\l"
	.string "to hold back on today's challengers\l"
	.string "for once…\p"
	.string "(Juan claps his hands together twice.)\n"
	.string "Sebastian! Come hither!$"

SootopolisCity_Gym_B1F_Text_ImSebastian:
	.string "I am pleased to assist, m'lord.$"

SootopolisCity_Gym_B1F_Text_BattleBegins:
	.string "Trainer… do you know why I adore the\n"
	.string "Ice type so?\p"
	.string "It is cold, calculated.\n"
	.string "Weakening and debilitating.\p"
	.string "When I give it my all in this gym, the\n"
	.string "challengers… they shiver.\p"
	.string "Have you what it takes?\n"
	.string "Let us find out.$"

SootopolisCity_Gym_B1F_Text_GetOuttaHere:
	.string "You showed us your meddle, challenger.\p"
	.string "And now, I ask you to bid us adieu.$"

SootopolisCity_Gym_B1F_Text_DontGoOnStage:
	.string "Watch it!\n"
	.string "Master Juan is currently performing.\p"
	.string "No way I'm lettin' you onstage!$"
