.set LOCALID_KITIKITI1, 2
.set LOCALID_KITIKITI2, 3
.set LOCALID_KITIKITI3, 4
.set LOCALID_KITIKITI4, 5
.set LOCALID_KITIKITI5, 6
.set LOCALID_KITIKITI6, 7
.set LOCALID_KITIKITI7, 8
.set LOCALID_KITIKITI8, 9

PerplumeTreehouse_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, PerplumeTreehouse_OnLoad
	.byte 0

PerplumeTreehouse_OnLoad:
	call_if_lt VAR_KITIKITI_QUEST_STATE, 9, PerplumeTreehouse_EventScript_RemoveKitikiti
	call_if_gt VAR_ORBS_QUEST_STATE, 2, PerplumeTreehouse_EventScript_RemoveOrb
	end

PerplumeTreehouse_EventScript_RemoveKitikiti::
	removeobject LOCALID_KITIKITI1
	removeobject LOCALID_KITIKITI2
	removeobject LOCALID_KITIKITI3
	removeobject LOCALID_KITIKITI4
	removeobject LOCALID_KITIKITI5
	removeobject LOCALID_KITIKITI6
	removeobject LOCALID_KITIKITI7
	removeobject LOCALID_KITIKITI8
	setflag FLAG_TEMP_1
	return

PerplumeTreehouse_EventScript_RemoveOrb::
	setflag FLAG_TEMP_A
	return

PerplumeTreehouse_EventScript_Olimar::
	lock
	faceplayer
	goto_if_ge VAR_KITIKITI_QUEST_STATE, 10, PerplumeTreehouse_EventScript_OlimarPost
	goto_if_ge VAR_KITIKITI_QUEST_STATE, 9, PerplumeTreehouse_EventScript_GiveLongNose
	goto_if_gt VAR_KITIKITI_QUEST_STATE, 0, PerplumeTreehouse_EventScript_GoSearching
	msgbox PerplumeTreehouse_Text_FindMyKitikiti, MSGBOX_DEFAULT
	setvar VAR_ORBS_QUEST_STATE, 1
	closemessage
	release
	end

PerplumeTreehouse_EventScript_GoSearching::
	msgbox PerplumeTreehouse_Text_GoSearching, MSGBOX_AUTOCLOSE
	release
	end

PerplumeTreehouse_EventScript_GiveLongNose::
	msgbox PerplumeTreehouse_Text_ThankYou, MSGBOX_DEFAULT
	giveitem ITEM_LONG_NOSE
	setvar VAR_KITIKITI_QUEST_STATE, 10
	msgbox PerplumeTreehouse_Text_LeadYourBugs, MSGBOX_AUTOCLOSE
	release
	end

PerplumeTreehouse_EventScript_OlimarPost::
	goto_if_eq VAR_ORBS_QUEST_STATE, 2, PerplumeTreehouse_EventScript_OlimarBloomOrb
	msgbox PerplumeTreehouse_Text_HowsYourJourney, MSGBOX_AUTOCLOSE
	release
	end

PerplumeTreehouse_EventScript_OlimarBloomOrb::
	msgbox PerplumeTreehouse_Text_IDoHaveThatOrb, MSGBOX_DEFAULT
	closemessage
	delay 8
	warp MAP_PERPLUME_TREEHOUSE, 18, 7
	waitstate
	release
	end

PerplumeTreehouse_EventScript_ObtainBloomOrb::
	lock
	msgbox PerplumeTreehouse_Text_ItsTheBloomOrb, MSGBOX_DEFAULT
	removeobject VAR_LAST_TALKED
	setflag FLAG_TEMP_A
	giveitem ITEM_BLOOM_ORB
	closemessage
	setvar VAR_ORBS_QUEST_STATE, 3
	delay 16
	playse SE_M_SWORDS_DANCE
	waitse
	playse SE_M_BUBBLE_BEAM2
	msgbox PerplumeTreehouse_Text_TheMapPointsToLilycove, MSGBOX_AUTOCLOSE
	release
	end

PerplumeTreehouse_Text_FindMyKitikiti:
	.string "Ho-ho! Pleased to meet you.\n"
	.string "This is my treehouse. My name\l"
	.string "is Olimar. I'm a bit of an explorer.\p"
	.string "There's a group of 8 Kitikiti that\n"
	.string "follow me around. I've taken to\l"
	.string "caring for them. Problem is, they\l"
	.string "are quite scatterbrained. I appear\l"
	.string "to have lost them in the maze.\p"
	.string "Could you please assist me and\n"
	.string "find my lost Kitikiti? If you\l"
	.string "whistle at them, they should\l"
	.string "return to this place.\p"
	.string "Now, if you don't nab them all\n"
	.string "at once, I'm afraid they may\l"
	.string "scatter once more. Try not\l"
	.string "to leave Perplume Maze, alright?\p"
	.string "I am in your debt.\n$"

PerplumeTreehouse_Text_GoSearching:
	.string "If you whistle at my Kitikiti, they\n"
	.string "should return to this place.\p"
	.string "Now, if you don't nab them all\n"
	.string "at once, I'm afraid they may\l"
	.string "scatter once more. Try not\l"
	.string "to leave Perplume Maze, alright?\p"
	.string "I am in your debt.\n$"

PerplumeTreehouse_Text_ThankYou:
	.string "All 8 of my Kitikiti seem\n"
	.string "to have returned! Thank the stars!\p"
	.string "I am ever so grateful for the help.\n"
	.string "I will give you this\l"
	.string "as a parting gift.$"

PerplumeTreehouse_Text_LeadYourBugs:
	.string "Kitikiti's evolution, Moskopo,\n"
	.string "is rather weak. But if you\l"
	.string "equip one with a Long Nose,\l"
	.string "they can tussle with even\l"
	.string "the biggest of foes.\p"
	.string "Be a good leader for your\n"
	.string "Pokemon, okay? They deserve it!$"

PerplumeTreehouse_Text_HowsYourJourney:
	.string "How is your journey?\n"
	.string "Going well?\p"
	.string "Myself? I await my partner\n"
	.string "Louie's arrival from our\l"
	.string "freight company... that dolt\l"
	.string "is even more scatterbrained\l"
	.string "than my Kitikiti!$"

PerplumeTreehouse_Text_IDoHaveThatOrb:
	.string "Welcome back!\p"
	.string "...You're looking for some\n"
	.string "sort of Orb in this tree?\l"
	.string "...Oh! I believe I know\l"
	.string "what you're referring to.\p"
	.string "It was there when I commandeered\n"
	.string "this tree. It seemed important,\l"
	.string "so I had left it there.\p"
	.string "Here... I will take you to\n"
	.string "the chamber where it lies.$"

PerplumeTreehouse_Text_ItsTheBloomOrb:
	.string "(It's the second Orb that\n"
	.string "was marked by the map...)$"

PerplumeTreehouse_Text_TheMapPointsToLilycove:
	.string "(Your magical map shines once more,\n"
	.string "pointing you to a new location.)\p"
	.string "(This time, it is leading you\n"
	.string "to the Battle Studio in Lilycove...)$"
