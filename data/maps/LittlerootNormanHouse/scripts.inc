.set LOCALID_STEVEN, 3
.set LOCALID_NORMAN, 1
.set LOCALID_NORMANWIFE, 2

LittlerootNormanHouse_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, LittlerootNormanHouse_OnLoad
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LittlerootNormanHouse_OnFrame
	.byte 0

LittlerootNormanHouse_OnLoad:
	call_if_lt VAR_WALLY_QUEST_STATE, 3, LittlerootNormanHouse_EventScript_RemoveSteven
	call_if_gt VAR_WALLY_QUEST_STATE, 3, LittlerootNormanHouse_EventScript_RemoveSteven
	end

LittlerootNormanHouse_EventScript_RemoveSteven::
	removeobject LOCALID_STEVEN
	setflag FLAG_TEMP_11
	return

LittlerootNormanHouse_OnFrame:
	map_script_2 VAR_WALLY_QUEST_STATE, 3, LittlerootNormanHouse_EventScript_NormanBattle
	.2byte 0

LittlerootNormanHouse_EventScript_NormanBattle::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootNormanHouse_Movement_PlayerWalkIntoHouse
	applymovement LOCALID_STEVEN, LittlerootNormanHouse_Movement_StevenWalkIntoHouse
	waitmovement 0
	delay 8
	playse SE_PIN
	applymovement LOCALID_NORMAN, LittlerootNormanHouse_Movement_NormanShocked
	waitmovement 0
	speakername LittlerootNormanHouse_Text_NameNorman
	msgbox LittlerootNormanHouse_Text_WhatsUp, MSGBOX_DEFAULT
	speakername LittlerootNormanHouse_Text_NameSteven
	msgbox LittlerootNormanHouse_Text_WereHereRegarding, MSGBOX_DEFAULT
	applymovement LOCALID_NORMAN, LittlerootNormanHouse_Movement_NormanWalkUpToPlayer
	waitmovement 0
	speakername NULL
	msgbox LittlerootNormanHouse_Text_YouLookHimInTheEye, MSGBOX_DEFAULT
	speakername LittlerootNormanHouse_Text_NameNorman
	msgbox LittlerootNormanHouse_Text_SoImBeingAccused, MSGBOX_DEFAULT
	speakername LittlerootNormanHouse_Text_NameSteven
	msgbox LittlerootNormanHouse_Text_ThatShouldBeFine, MSGBOX_DEFAULT
	speakername LittlerootNormanHouse_Text_NameNorman
	msgbox LittlerootNormanHouse_Text_NormanIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_P_NORMAN, LittlerootNormanHouse_Text_NormanDefeated
	goto LittlerootNormanHouse_EventScript_NormanBeaten
	release
	end

LittlerootNormanHouse_Movement_PlayerWalkIntoHouse:
	walk_up
	walk_up
	face_left
	step_end

LittlerootNormanHouse_Movement_StevenWalkIntoHouse:
	walk_up
	face_left
	step_end

LittlerootNormanHouse_Movement_NormanShocked:
	emote_exclamation_mark
	step_end

LittlerootNormanHouse_Movement_NormanWalkUpToPlayer:
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	face_right
	step_end

LittlerootNormanHouse_EventScript_NormanBeaten::
	setvar VAR_WALLY_QUEST_STATE, 4
	speakername LittlerootNormanHouse_Text_NameNorman
	msgbox LittlerootNormanHouse_Text_YouSeemAngered, MSGBOX_DEFAULT
	speakername NULL
	msgbox LittlerootNormanHouse_Text_Reflection, MSGBOX_DEFAULT
	speakername LittlerootNormanHouse_Text_NameSteven
	msgbox LittlerootNormanHouse_Text_FoulPlay, MSGBOX_DEFAULT
	speakername LittlerootNormanHouse_Text_NameNorman
	msgbox LittlerootNormanHouse_Text_ShouldCheckOutCasino, MSGBOX_DEFAULT
	speakername LittlerootNormanHouse_Text_NameSteven
	msgbox LittlerootNormanHouse_Text_IllMeetYouThere, MSGBOX_DEFAULT
	warp MAP_LITTLEROOT_NEW, 11, 15
	waitstate
	release
	end

LittlerootNormanHouse_Text_NameNorman:
	.string "Norman$"

LittlerootNormanHouse_Text_NameSteven:
	.string "Steven$"

LittlerootNormanHouse_Text_WhatsUp:
	.string "Oh, it's a pleasure, Steven!\n"
	.string "What brings yo-\p"
	.string "Is that... {PLAYER}? It's\n"
	.string "great to see you! I didn't\l"
	.string "know you were visiting from Sevii!\l"
	.string "Are you here to catch up?\l"
	.string "Ahaha... it's a bit of a shocker\l"
	.string "that you know Steven this well, too.$"

LittlerootNormanHouse_Text_WereHereRegarding:
	.string "My apologies, Norman. But we\n"
	.string "are here in a more... business-\l"
	.string "oriented capacity.\p"
	.string "I'm sure you are quite aware of\n"
	.string "having personally signed off\l"
	.string "on blocking {PLAYER}'s league\l"
	.string "certification. We simply\l"
	.string "wanted to hear out your reasons,\l"
	.string "and perhaps convince you\l"
	.string "to change your mind on the manner.$"

LittlerootNormanHouse_Text_YouLookHimInTheEye:
	.string "(Norman walks over with a stern,\n"
	.string "yet perplexed look on his face.\l"
	.string "You take out the paperwork with\l"
	.string "his signature on it and\l"
	.string "show it to him.)$"

LittlerootNormanHouse_Text_SoImBeingAccused:
	.string "I see. My character is being\n"
	.string "drawn into question? That\l"
	.string "is really upsetting. I can tell\l"
	.string "you right now that I did not,\l"
	.string "and would never, sign off on\l"
	.string "something like this.\p"
	.string "Despite my denial... I can see\n"
	.string "that {PLAYER} isn't having\l"
	.string "any of it. If you've so made\l"
	.string "up your mind, {PLAYER}, then\l"
	.string "let's lay it all out on\l"
	.string "the battlefield. Maybe then we\l"
	.string "can really understand each other.\p"
	.string "Would that be ok, Steven?$"

LittlerootNormanHouse_Text_ThatShouldBeFine:
	.string "As long as this matter is\n"
	.string "resolved, I am alright with it.$"

LittlerootNormanHouse_Text_NormanIntro:
	.string "Alright! Well, {PLAYER},\n"
	.string "I can see you're itching to\l"
	.string "let out some steam.\l"
	.string "I'm not gonna let you make me\l"
	.string "some punching bag though!\l"
	.string "Do your best!$"

LittlerootNormanHouse_Text_NormanDefeated:
	.string "This reminds me why I retired!\n"
	.string "Hahahaha!$"

LittlerootNormanHouse_Text_YouSeemAngered:
	.string "Was that enough, {PLAYER}?\p"
	.string "Look, you're confused and upset.\n"
	.string "I get it, kiddo. But I need you\l"
	.string "to keep a level head. Let's\l"
	.string "think things over as calm minds.$"

LittlerootNormanHouse_Text_Reflection:
	.string "(...)\p"
	.string "(...He's right. Norman was always\n"
	.string "a dear friend to Dad. He wouldn't\l"
	.string "do something like this without\l"
	.string "telling you or Dad beforehand.)\p"
	.string "(Maybe it's time to finally...\n"
	.string "let some emotional baggage go\l"
	.string "regarding your old rival...)\p"
	.string "(...With all that said...)$"

LittlerootNormanHouse_Text_FoulPlay:
	.string "If you are claiming ignorance\n"
	.string "despite your clearly printed\l"
	.string "signature, Norman, then we must\l"
	.string "assume in good faith that there\l"
	.string "is potential foul play afoot.\p"
	.string "A forgery, to be precise.\n"
	.string "Someone out there really has\l"
	.string "it out for you, {PLAYER}.\p"
	.string "I... hesitate to state where\n"
	.string "to begin looking into this\l"
	.string "forgery angle.$"

LittlerootNormanHouse_Text_ShouldCheckOutCasino:
	.string "Best way to look for scoundrels\n"
	.string "like that? My money would be on\l"
	.string "asking one of their own.\p"
	.string "Seaside Casino in Sea Mauville\n"
	.string "has always been an open secret\l"
	.string "hotspot for unsavory types\l"
	.string "to gather. Chances are, you\l"
	.string "can find a rat among them.\p"
	.string "It's due east from here, a pretty\n"
	.string "short walk through the under\l"
	.string "construction streets.\l"
	.string "I really recommend that angle,\l"
	.string "but of course, look out for each\l"
	.string "other in there. Dealing with\l"
	.string "cronies like that can be unsafe.$"

LittlerootNormanHouse_Text_IllMeetYouThere:
	.string "Then so it shall be.\n"
	.string "I will meet you there, {PLAYER}.$"
