.set LOCALID_WALLACE, 1

CaveOfOrigin_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CaveOfOrigin_OnFrame
	.byte 0

CaveOfOrigin_OnFrame:
	map_script_2 VAR_NEW_COO_STATE, 1, CaveOfOrigin_EventScript_GoToRedWater
	.2byte 0

CaveOfOrigin_EventScript_GoToRedWater::
	lock
	removeobject LOCALID_WALLACE
	applymovement OBJ_EVENT_ID_PLAYER, CaveOfOrigin_Movement_PlayerWalkToWater
	waitmovement 0
	addobject LOCALID_WALLACE
	applymovement LOCALID_WALLACE, CaveOfOrigin_Movement_WallaceWalkToWater
	waitmovement 0
	msgbox CaveOfOrigin_Text_Otherworldly, MSGBOX_DEFAULT
	speakername CaveOfOrigin_Text_NameWallace
	msgbox CaveOfOrigin_Text_AboutTheLegends, MSGBOX_AUTOCLOSE
	speakername NULL
	applymovement LOCALID_WALLACE, CaveOfOrigin_Movement_WallaceWalkAway
	waitmovement 0
	setvar VAR_NEW_COO_STATE, 2
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_WALLACE
	release
	end

CaveOfOrigin_Movement_PlayerWalkToWater:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

CaveOfOrigin_Movement_WallaceWalkToWater:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

CaveOfOrigin_Movement_WallaceWalkAway:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	set_invisible
	step_end

CaveOfOrigin_Text_NameWallace:
	.string "Wallace$"

CaveOfOrigin_Text_Otherworldly:
	.string "Otherworldly, isn't it?\p"
	.string "…Pleased to meet you!\n"
	.string "I am the former Champion, Wallace.$"

CaveOfOrigin_Text_AboutTheLegends:
	.string "Ah, welcome! I apologize, but\n"
	.string "you have just missed today's mass.\p"
	.string "I imagine your curiosity in the divine\n"
	.string "led you to this chamber, mm?\p"
	.string "Many well-researched folks in Hoenn\n"
	.string "know well of Groudon, Kyogre,\l"
	.string "and Rayquaza.\l"
	.string "In fact, a bevy of Sootopolitans have\l"
	.string "seen one of their fierce bouts unfold.\p"
	.string "Groudon and Kyogre have an insatiable\n"
	.string "hatred for the other.\p"
	.string "Only natural, I presume, that the\n"
	.string "lords of land and sea would\l"
	.string "oppose each other.\p"
	.string "They have fought many times over the\n"
	.string "years, with Rayquaza, lord of the sky,\l"
	.string "always around to quell them.\p"
	.string "In a way, they were living symbols\n"
	.string "of the cultural division of Hoenn.\l"
	.string "A division which has,\l"
	.string "in present day, subsided.\p"
	.string "And wouldn't you know it…\n"
	.string "we haven't heard a peep from the\l"
	.string "warring titans in some time.\p"
	.string "Those who pray here in the Cave\n"
	.string "of Origin are beheld to a pair\l"
	.string "of water-dwelling Legendary\l"
	.string "Pokemon named Sha-yon\l"
	.string "and Luo-shan.\p"
	.string "This period of peace we've had\n"
	.string "in Hoenn, some believe to be\l"
	.string "brought about due to the presence\l"
	.string "of this pair. Quite the polar\l"
	.string "opposite pairing to the\l"
	.string "ever-violent Groudon and Kyogre.\p"
	.string "Though we have never physically\n"
	.string "seen Luo-shan and Sha-yon,\l"
	.string "it is said that this pond's\l"
	.string "water runs red only when they\l"
	.string "are present and healthy.\p"
	.string "It takes a high amount of faith\n"
	.string "to believe in something you\l"
	.string "cannot see with your eyes, but\l"
	.string "I personally have always been\l"
	.string "a believer.\p"
	.string "Mayhaps you will return for\n"
	.string "a ceremony one day?\l"
	.string "In any case, I must be off.$"
