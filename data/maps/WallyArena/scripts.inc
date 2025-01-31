.set LOCALID_WALLY, 1
.set LOCALID_STEVEN, 2
.set LOCALID_NORMAN, 3

WallyArena_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, WallyArena_OnLoad
	.byte 0

WallyArena_OnLoad:
	call WallyArena_EventScript_RemoveStevenNorman
	end

WallyArena_EventScript_RemoveStevenNorman::
	removeobject LOCALID_STEVEN
	setflag FLAG_TEMP_11
	removeobject LOCALID_NORMAN
	setflag FLAG_TEMP_12
	return

WallyArena_EventScript_WallyBattle::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, WallyArena_Movement_PlayerMoveToWally
	waitmovement 0
	delay 8
	turnobject LOCALID_WALLY, DIR_EAST
	delay 16
	turnobject LOCALID_WALLY, DIR_SOUTH
	delay 16
	speakername WallyArena_Text_NameWally
	msgbox WallyArena_Text_HelloPlayerKun, MSGBOX_DEFAULT
	playbgm MUS_VICTORY_ROAD, FALSE
	speakername WallyArena_Text_NameWally
	msgbox WallyArena_Text_FullVillainMonologue, MSGBOX_DEFAULT
	trainerbattle_single TRAINER_P_WALLY, WallyArena_Text_WallyIntro, WallyArena_Text_WallyDefeated, WallyArena_EventScript_WallyBeaten
	goto WallyArena_EventScript_WallyBeaten
	release
	end

WallyArena_EventScript_WallyBeaten::
	lock
	setvar VAR_WALLY_QUEST_STATE, 9
	setflag FLAG_DEFEATED_EVIL_WALLY
	setvar VAR_PISCES_STORY_PROGRESS, 10
	playbgm MUS_RG_VICTORY_ROAD, FALSE
	speakername WallyArena_Text_NameWally
	msgbox WallyArena_Text_HowCouldThisBe, MSGBOX_DEFAULT
	clearflag FLAG_TEMP_11
	addobject LOCALID_STEVEN
	clearflag FLAG_TEMP_12
	addobject LOCALID_NORMAN
	delay 4
	closemessage
	applymovement LOCALID_STEVEN, WallyArena_Movement_StevenMoveToWally
	applymovement LOCALID_NORMAN, WallyArena_Movement_NormanMoveToWally
	waitmovement 0
	speakername WallyArena_Text_NameNorman
	msgbox WallyArena_Text_ThatsEnoughWally, MSGBOX_DEFAULT
	speakername WallyArena_Text_NameWally
	msgbox WallyArena_Text_HowDidYouFindMe, MSGBOX_DEFAULT
	speakername WallyArena_Text_NameSteven
	msgbox WallyArena_Text_TrackedTheScent, MSGBOX_DEFAULT
	speakername WallyArena_Text_NameWally
	msgbox WallyArena_Text_WhatsGonnaHappenNow, MSGBOX_DEFAULT
	speakername WallyArena_Text_NameNorman
	msgbox WallyArena_Text_ISeeTheGoodInYou, MSGBOX_DEFAULT
	speakername WallyArena_Text_NameWally
	msgbox WallyArena_Text_AnUnwiseChoice, MSGBOX_DEFAULT
	applymovement LOCALID_WALLY, WallyArena_Movement_WallyRunAway
	waitmovement 0
	speakername WallyArena_Text_NameNorman
	msgbox WallyArena_Text_ThatShouldSettleIt, MSGBOX_DEFAULT
	speakername WallyArena_Text_NameSteven
	msgbox WallyArena_Text_LetsGoToDevonCorp, MSGBOX_DEFAULT
	closemessage
	delay 4
	warp MAP_DEVON_CORP, 12, 19
	waitstate
	release
	end

WallyArena_Movement_PlayerMoveToWally:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

WallyArena_Movement_StevenMoveToWally:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	face_up
	step_end

WallyArena_Movement_NormanMoveToWally:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	face_up
	step_end

WallyArena_Movement_WallyRunAway:
	walk_fast_down
	walk_fast_left
	walk_fast_down
	walk_fast_down
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

WallyArena_Text_NameWally:
	.string "Wally$"

WallyArena_Text_NameNorman:
	.string "Norman$"

WallyArena_Text_NameSteven:
	.string "Steven$"

WallyArena_Text_HelloPlayerKun:
	.string "Cough, cough...\n"
	.string "{PLAYER}, is that you?\p"
	.string "I'm glad. Glad that...\n"
	.string "you walked right into my trap!$"

WallyArena_Text_FullVillainMonologue:
	.string "I see the look of dismay\n"
	.string "on your, cough... stupid face!\p"
	.string "Yes, that's right! I've ALWAYS\n"
	.string "despised you. Ever since that\l"
	.string "first gym challenge...!\l"
	.string "The champ never cared about ME.\l"
	.string "They were always talking to YOU.\l"
	.string "I wanted to be their rival!\l"
	.string "Their best friend!\l"
	.string "I wanted recognition! Respect!\l"
	.string "But I was FORGOTTEN.\p"
	.string "And you.\n"
	.string "YOU.\p"
	.string "You just HAD to show back up\n"
	.string "in Hoenn again. And not just\l"
	.string "that! You act like YOU'RE the\l"
	.string "protagonist of life now!\l"
	.string "It, cough, INFURIATES me to no end!\p"
	.string "I've tried! Boy, have I tried\n"
	.string "COUNTLESS times to stop\l"
	.string "your dumb adventure...!\p"
	.string "That avalanche in the Cold Mines?\n"
	.string "I caused it!\p"
	.string "Those Bolterock in Masonried Hike?\n"
	.string "I COMMANDED them to block your path!\p"
	.string "Shelly and Brawly? I lured them\n"
	.string "away from...cough, cough... the gym!\p"
	.string "And now, my last hoorah. I couldn't\n"
	.string "just let you complete the challenge\l"
	.string "so EASILY, PLAYER-KUN!\p"
	.string "I FORGED THE SIGNATURE!\n"
	.string "AND YOU STILL FOUND ME OUT!$"

WallyArena_Text_WallyIntro:
	.string "I'VE HAD IT!\n"
	.string "NO MORE GAMES!\l"
	.string "We are battling RIGHT NOW!\l"
	.string "And when you lose, and your\l"
	.string "Pokemon are all incapacitated,\l"
	.string "and your breath runs thin\l"
	.string "from exhaustion...!\p"
	.string "I'LL KILL YOU!$"

WallyArena_Text_WallyDefeated:
	.string "Cough, cough, cough...!\p"
	.string "NOOOOOOOOOOOOOOOOOOOOOOOO!$"

WallyArena_Text_HowCouldThisBe:
	.string "How did you WIN...!?\n"
	.string "Even with me throwing myself\l"
	.string "in the battle, cough...!\l"
	.string "It wasn't ENOUGH!?$"

WallyArena_Text_ThatsEnoughWally:
	.string "That is IT, Wally. We're\n"
	.string "here to put an end to things.$"

WallyArena_Text_HowDidYouFindMe:
	.string "How... HOW did you find\n"
	.string "my secret cave...?$"

WallyArena_Text_TrackedTheScent:
	.string "I had gotten concerned that\n"
	.string "{PLAYER} hadn't arrived yet.\l"
	.string "I checked my doorstep, and smelled\l"
	.string "the scent of spider lilies.\l"
	.string "This islet is not far from my home.\l"
	.string "It was... fairly easy to find,\l"
	.string "in fact.$"

WallyArena_Text_WhatsGonnaHappenNow:
	.string "No... NO....!\n"
	.string "Foiled...!\p"
	.string "Sniff... what is going to\n"
	.string "happen to me now...!?\l"
	.string "Am I going to... cough, prison?$"

WallyArena_Text_ISeeTheGoodInYou:
	.string "You are very, very lucky I\n"
	.string "came here to mediate, Wally.\p"
	.string "I watched you capture your first\n"
	.string "Pokemon. That year, you grew\l"
	.string "into a fine trainer. It is\l"
	.string "because of those memories that\l"
	.string "I cannot bring myself to have you\l"
	.string "locked up in jail for the rest\l"
	.string "of your life.\p"
	.string "I will let you go free. But\n"
	.string "only if you leave {PLAYER}\l"
	.string "alone... and never show\l"
	.string "your face around the\l"
	.string "League ever again.$"

WallyArena_Text_AnUnwiseChoice:
	.string "Cough, cough...\p"
	.string "An... unwise choice...\p"
	.string "...{PLAYER}. I hope misfortune\n"
	.string "befalls you. Maybe not by\l"
	.string "my hands... but I will never\l"
	.string "lose this grudge.\p"
	.string "Goodbye...!$"

WallyArena_Text_ThatShouldSettleIt:
	.string "I can act as an eyewitness\n"
	.string "to these events. That should\l"
	.string "be enough to overturn the\l"
	.string "blockage and get you certified.\l"
	.string "I'm glad we could get everything\l"
	.string "sorted out!$"

WallyArena_Text_LetsGoToDevonCorp:
	.string "Indeed. Shall we go\n"
	.string "back to Devon Corp. to make\l"
	.string "this official?$"
