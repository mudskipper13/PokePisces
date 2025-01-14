.set LOCALID_RAY, 11
.set LOCALID_DEVONEMPLOYEE, 14
.set LOCALID_MRSTONE, 3

DevonCorp_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, DevonCorp_OnFrame
	.byte 0

DevonCorp_OnFrame:
	map_script_2 VAR_RUST_GYM_STATE, 15, DevonCorp_EventScript_DevonMeeting
	.2byte 0

DevonCorp_EventScript_DevonMeeting::
	lock
	setvar VAR_RUST_GYM_STATE, 14
	playbgm MUS_RG_VICTORY_ROAD, FALSE
	delay 4
	applymovement OBJ_EVENT_ID_PLAYER, DevonCorp_Movement_PlayerFaceRight
	waitmovement 0
	speakername DevonCorp_Text_NameMrStone
	msgbox DevonCorp_Text_IAmDevonsDirector, MSGBOX_DEFAULT
	speakername DevonCorp_Text_NameSteven
	msgbox DevonCorp_Text_YourCertificationHasBeenBlocked, MSGBOX_DEFAULT
	speakername DevonCorp_Text_NameMrStone
	msgbox DevonCorp_Text_YouMustBeUpset, MSGBOX_DEFAULT
	speakername DevonCorp_Text_NameRoxanne
	msgbox DevonCorp_Text_CanVouchForPlayer, MSGBOX_DEFAULT
	speakername NULL
	msgbox DevonCorp_Text_YouTurnToMaxie, MSGBOX_DEFAULT
	speakername DevonCorp_Text_NameMaxie
	msgbox DevonCorp_Text_YouKnowWhoDidIt, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_RAY, DevonCorp_Movement_RayComeToMeeting
	waitmovement 0
	delay 4
	applymovement OBJ_EVENT_ID_PLAYER, DevonCorp_Movement_PlayerFaceDown
	waitmovement 0
	speakername DevonCorp_Text_NameRay
	msgbox DevonCorp_Text_WhyAmIHere, MSGBOX_DEFAULT
	speakername DevonCorp_Text_NameMaxie
	msgbox DevonCorp_Text_SoYouAccuseRay, MSGBOX_DEFAULT
	playfanfare MUS_RAYQUAZA_APPEARS
	speakername NULL
	msgbox DevonCorp_Text_ItHasToBeThem, MSGBOX_DEFAULT
	applymovement LOCALID_RAY, DevonCorp_Movement_RayFightPlayer
	waitmovement 0
	speakername DevonCorp_Text_NameRay
	trainerbattle_single TRAINER_P_RAY_6, DevonCorp_Text_RayIntro, DevonCorp_Text_RayDefeated, DevonCorp_EventScript_RayDefeat
	goto DevonCorp_EventScript_RayDefeat
	release
	end

DevonCorp_Movement_PlayerFaceRight:
	face_right
	step_end

DevonCorp_Movement_PlayerFaceDown:
	face_down
	step_end

DevonCorp_Movement_RayComeToMeeting:
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
	walk_right
	walk_right
	walk_right
	walk_up
	step_end

DevonCorp_Movement_RayFightPlayer:
	walk_fast_left
	walk_fast_up
	step_end

DevonCorp_EventScript_RayDefeat::
	lock
	playbgm MUS_RG_VICTORY_ROAD, FALSE
	applymovement LOCALID_RAY, DevonCorp_Movement_RayBackUp
	waitmovement 0
	speakername DevonCorp_Text_NameRay
	msgbox DevonCorp_Text_ImNotYourRival, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, DevonCorp_Movement_PlayerConfused
	waitmovement 0
	delay 16
	speakername NULL
	msgbox DevonCorp_Text_WhoCouldItBe, MSGBOX_DEFAULT
	applymovement LOCALID_DEVONEMPLOYEE, DevonCorp_Movement_EmployeeWalkIn
	waitmovement 0
	applymovement LOCALID_MRSTONE, DevonCorp_Movement_StoneLookDown
	setvar VAR_RUST_GYM_STATE, 16
	speakername DevonCorp_Text_NameMrStone
	msgbox DevonCorp_Text_ISeeThankYou, MSGBOX_DEFAULT
	applymovement LOCALID_DEVONEMPLOYEE, DevonCorp_Movement_EmployeeWalkAway
	waitmovement 0
	applymovement LOCALID_MRSTONE, DevonCorp_Movement_StoneLookLeft
	speakername DevonCorp_Text_NameMrStone
	msgbox DevonCorp_Text_ItWasNormanHimself, MSGBOX_DEFAULT
	speakername DevonCorp_Text_NameSteven
	msgbox DevonCorp_Text_YouMustSeekHimOut, MSGBOX_DEFAULT
	speakername DevonCorp_Text_NameRoxanne
	msgbox DevonCorp_Text_HeadToPetalburg, MSGBOX_DEFAULT
	speakername DevonCorp_Text_NameRay
	msgbox DevonCorp_Text_AreWeGoodNow, MSGBOX_DEFAULT
	setvar VAR_WALLY_QUEST_STATE, 2
	setflag FLAG_DEVON_CORP_VISIT
	warp MAP_RUSTBORO_NEW, 61, 35
	waitstate
	release
	end

DevonCorp_Movement_RayBackUp:
	walk_faster_down
	face_up
	step_end

DevonCorp_Movement_PlayerConfused:
	emote_question_mark
	delay_8
	face_right
	step_end

DevonCorp_Movement_EmployeeWalkIn:
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
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	step_end

DevonCorp_Movement_StoneLookDown:
	face_down
	step_end

DevonCorp_Movement_EmployeeWalkAway:
	walk_down
	walk_down
	walk_right
	face_left
	step_end

DevonCorp_Movement_StoneLookLeft:
	face_left
	step_end

DevonCorp_Text_NameMrStone:
	.string "Mr. Stone$"

DevonCorp_Text_NameSteven:
	.string "Steven$"

DevonCorp_Text_NameRoxanne:
	.string "Roxanne$"

DevonCorp_Text_NameMaxie:
	.string "Maxie$"

DevonCorp_Text_NameRay:
	.string "Ray$"

DevonCorp_Text_IAmDevonsDirector:
	.string "Hello, {PLAYER}.\n"
	.string "You've been summoned to meet\l"
	.string "with this group of high-ranking\l"
	.string "league officials regarding\l"
	.string "your gym challenge completion\l"
	.string "status.\p"
	.string "You may know me as President Stone\n"
	.string "of Devon Corp. Steven here is\l"
	.string "my son. Pleased to meet you,\l"
	.string "though I apologize it is\l"
	.string "under these circumstances.$"

DevonCorp_Text_YourCertificationHasBeenBlocked:
	.string "To cut to the meat of the matter;\n"
	.string "your league certification has\l"
	.string "been blocked, {PLAYER}, via\l"
	.string "strong recommendation of\l"
	.string "someone affiliated with the league.\p"
	.string "We understand it to be the former\n"
	.string "champion, Norman's child,\l"
	.string "that has submitted the motion.\p"
	.string "I am sorry to inform you that this\n"
	.string "means that the completion of your\l"
	.string "gym challenge has been blocked\l"
	.string "indefinitely, and upon later\l"
	.string "review, your badges may be\l"
	.string "confiscated.$"

DevonCorp_Text_YouMustBeUpset:
	.string "This must be terribly\n"
	.string "upsetting, {PLAYER}.\l"
	.string "Truly, I have empathy for\l"
	.string "your situation. However,\l"
	.string "we take all matters of this sort\l"
	.string "very seriously.\p"
	.string "I trust that you will co-\n"
	.string "operate with this review process.$"

DevonCorp_Text_CanVouchForPlayer:
	.string "I, personally, am one who\n"
	.string "is able to vouch for\l"
	.string "{PLAYER}'s character.\p"
	.string "I fail to see what the former\n"
	.string "champion so strongly objects\l"
	.string "to in this trainer.$"

DevonCorp_Text_YouTurnToMaxie:
	.string "(...)\p"
	.string "(Your heart has been fluttering\n"
	.string "for this whole interaction.\l"
	.string "What could have caused your\l"
	.string "old friend to cut you down at\l"
	.string "the end of the journey like this?)\p"
	.string "(...)\p"
	.string "(...Maybe that person was never\n"
	.string "a true friend at all.\l"
	.string "In fact... you seem to have\l"
	.string "figured out where they have\l"
	.string "been hiding all this time.)\p"
	.string "(You notice Ozone Leader Maxie\n"
	.string "has attended this meeting.\l"
	.string "You turn to him and\l"
	.string "get his attention.)$"

DevonCorp_Text_YouKnowWhoDidIt:
	.string "Yes?\p"
	.string "You... would like to speak\n"
	.string "to the former champion\l"
	.string "to resolve the issue?\p"
	.string "...Hm. Well, other than in\n"
	.string "writing, we have not seen\l"
	.string "that person in the flesh in\l"
	.string "quite some time. I'd imagine\l"
	.string "it would be difficult to-\p"
	.string "Summon... that person?\n"
	.string "Are you sure? ...Hm.\l"
	.string "I will humor the request,\l"
	.string "if only because I find this\l"
	.string "highly unusual.\p"
	.string "(Maxie pulls out a communicator\n"
	.string "and orders a subordinate of\l"
	.string "his to arrive on the scene.)$"

DevonCorp_Text_WhyAmIHere:
	.string "Uhhhhh. This is some\n"
	.string "poppycock. Hogwash, even.\l"
	.string "For WHAT reason was I called\l"
	.string "to this board meeting?\p"
	.string "Am I to be let go? That would\n"
	.string "be an imbecilic move\l"
	.string "(befitting a low-IQ individual).\l"
	.string "I have at least one drop\l"
	.string "of respect for you, Maxie,\l"
	.string "and this might just get\l"
	.string "it sucked through the\l"
	.string "straw of stupidity...$"

DevonCorp_Text_SoYouAccuseRay:
	.string "Let me get this straight,\n"
	.string "{PLAYER}. You wish to talk\l"
	.string "to Ray... because you believe\l"
	.string "Ray to BE the former champion?$"

DevonCorp_Text_ItHasToBeThem:
	.string "(...Everything lines up.\n"
	.string "It must be them. Surely...\l"
	.string "under that mask...)$"

DevonCorp_Text_RayIntro:
	.string "Ah-hah-hah-hah.\n"
	.string "That was a sarcastic laugh.\l"
	.string "Dripping with discontent.\p"
	.string "You... why must you always\n"
	.string "insert yourself as an obstacle\l"
	.string "within my path? Are you that\l"
	.string "obsessed (and/or lacking in\l"
	.string "anything better to do)?\p"
	.string "Me? The former champion?\n"
	.string "While yes, I do see myself\l"
	.string "as champion material\l"
	.string "(and could probably beat that\l"
	.string "old fraud in ten seconds flat),\l"
	.string "you are making even less\l"
	.string "sense than your usual zero.\l"
	.string "You have invented negative sense.\l"
	.string "Bravo.\p"
	.string "That was also sarcastic.\n"
	.string "If you are so jonesing for\l"
	.string "a tussle, I will make this one\l"
	.string "count. Now, this time,\l"
	.string "everyone's watching.\l"
	.string "No place to hide and cheat.\p"
	.string "Game on.\n$"

DevonCorp_Text_RayDefeated:
	.string "This match felt a little\n"
	.string "bit out of the ordinary\l"
	.string "for you...\p"
	.string "Why do you feel like you\n"
	.string "have something to prove?$"

DevonCorp_Text_ImNotYourRival:
	.string "Okay. Alright. Okay.\n"
	.string "Let me clear my name in\l"
	.string "your addled brain, as it\l"
	.string "seems I have to.\l"
	.string "Otherwise, I am slightly\l"
	.string "vexxed that you will show\l"
	.string "up at the foot of my bed as\l"
	.string "I sleep and demand an answer then.$"

DevonCorp_Text_WhoCouldItBe:
	.string "(Ray briefly removes their goggles\n"
	.string "and mask, revealing...)\p"
	.string "(A completely unknown face to you.\n"
	.string "Ray really was just...\l"
	.string "some guy.)\p"
	.string "(...)\p"
	.string "(...If that's the case,\n"
	.string "then...)$"

DevonCorp_Text_ISeeThankYou:
	.string "Yes, Mr. Ignison?\p"
	.string "...Ah, alright. I will let\n"
	.string "them know. That was a\l"
	.string "mistake on our part.$"

DevonCorp_Text_ItWasNormanHimself:
	.string "Please take my humblest of\n"
	.string "apologies. It appears we\l"
	.string "slipped up on a crucial\l"
	.string "detail of our information.\p"
	.string "It was, in fact, Norman himself,\n"
	.string "that submitted the motion.\l"
	.string "NOT the former champion.\l"
	.string "Again, that is our mistake.$"

DevonCorp_Text_YouMustSeekHimOut:
	.string "{PLAYER}... I get the sense\n"
	.string "that you wish to fight this\l"
	.string "motion tooth and nail.\l"
	.string "I respect the tenacity.\p"
	.string "If you are looking to\n"
	.string "confront Mr. Norman about\l"
	.string "the situation, I am willing\l"
	.string "to accompany you as a third\l"
	.string "party to mediate.\p"
	.string "Hopefully, we can get everything\n"
	.string "resolved and get you\l"
	.string "officially league certified.$"

DevonCorp_Text_HeadToPetalburg:
	.string "You both should be headed\n"
	.string "to Petalburg, then. I talked\l"
	.string "to Norman not too long ago\l"
	.string "regarding separate matters.\l"
	.string "He should be in the city.\p"
	.string "Good luck, {PLAYER}.$"

DevonCorp_Text_AreWeGoodNow:
	.string "I guess that means I'm\n"
	.string "free to leave as well.\p"
	.string "In the future, you professional\n"
	.string "mouth-breather, take\l"
	.string "the cool, calm, and collected\l"
	.string "Ray's advice (referenced\l"
	.string "by over 70 scholars):\p"
	.string "Assuming makes an\n"
	.string "ass out of u and me.$"
