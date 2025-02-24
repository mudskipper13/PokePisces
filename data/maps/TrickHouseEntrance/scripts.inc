.set LOCALID_TRICK_MASTER, 1
.set LOCALID_P_MAN, 2

TrickHouseEntrance_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, TrickHouseEntrance_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, TrickHouseEntrance_OnWarp
	.byte 0

TrickHouseEntrance_OnTransition:
	goto_if_lt VAR_OLD_GUYS_STATE, 5, TrickHouseEntrance_EventScript_SetMauvilleOldManGfx
	end

TrickHouseEntrance_OnWarp:
	map_script_2 VAR_OLD_GUYS_STATE, 1, TrickHouseEntrance_EventScript_RemoveTrigger
	map_script_2 VAR_OLD_GUYS_STATE, 2, TrickHouseEntrance_EventScript_SetGiddyHidingSpot
	map_script_2 VAR_OLD_GUYS_STATE, 3, TrickHouseEntrance_EventScript_RemoveTrigger
	map_script_2 VAR_OLD_GUYS_STATE, 4, TrickHouseEntrance_EventScript_SetGiddyHidingSpotPost
	map_script_2 VAR_OLD_GUYS_STATE, 5, TrickHouseEntrance_EventScript_SetGiddyHidingSpotPost
	.2byte 0

TrickHouseEntrance_EventScript_SetMauvilleOldManGfx::
	setvar VAR_BARD_COLOR, MAUVILLE_MAN_GIDDY
	special SetMauvilleOldManObjEventGfx
	end

TrickHouseEntrance_EventScript_RemoveTrigger::
	setvar VAR_TEMP_5, 1
	removeobject LOCALID_P_MAN
	setflag FLAG_TEMP_14
	end

TrickHouseEntrance_EventScript_GiddyHiding::
	lockall
	goto_if_ge VAR_OLD_GUYS_STATE, 4, TrickHouseEntrance_EventScript_GiddyGone
	msgbox TrickHouseEntrance_Text_YoureBeingWatched, MSGBOX_DEFAULT
	releaseall
	dofieldeffectsparkle 10, 1, 0
	waitfieldeffect FLDEFF_SPARKLE
	delay 10
	setvar VAR_TEMP_5, 1
	end

TrickHouseEntrance_EventScript_GiddyGone::
	msgbox TrickHouseEntrance_Text_NotBeingWatched, MSGBOX_AUTOCLOSE
	setvar VAR_TEMP_5, 1
	releaseall
	end

TrickHouseEntrance_EventScript_SetGiddyHidingSpot::
	removeobject LOCALID_P_MAN
	setflag FLAG_TEMP_14
	goto_if_ge VAR_OLD_GUYS_STATE, 5, TrickHouseEntrance_EventScript_RemoveGiddy
	goto_if_set FLAG_POTTRICIA_DEFEATED, TrickHouseEntrance_EventScript_DefeatedPottricia
	goto TrickHouseEntrance_EventScript_RemoveGiddy
	end

TrickHouseEntrance_EventScript_RemoveGiddy::
	removeobject LOCALID_TRICK_MASTER
	setflag FLAG_TEMP_11
	end

TrickHouseEntrance_EventScript_SetGiddyHidingSpotPost::
	removeobject LOCALID_P_MAN
	setflag FLAG_TEMP_14
	setvar VAR_TEMP_5, 1
	goto_if_ge VAR_OLD_GUYS_STATE, 5, TrickHouseEntrance_EventScript_RemoveGiddy
	goto_if_set FLAG_POTTRICIA_DEFEATED, TrickHouseEntrance_EventScript_DefeatedPottricia
	goto TrickHouseEntrance_EventScript_RemoveGiddy
	end

TrickHouseEntrance_EventScript_DefeatedPottricia::
	clearflag FLAG_TEMP_11
	end

TrickHouseEntrance_EventScript_GiddyFound::
	lockall
	goto_if_le VAR_OLD_GUYS_STATE, 1, TrickHouseEntrance_EventScript_OrdinaryCabinet
	goto_if_ge VAR_OLD_GUYS_STATE, 3, TrickHouseEntrance_EventScript_OrdinaryCabinet
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	msgbox TrickHouseEntrance_Text_ConcealedInCabinet, MSGBOX_DEFAULT
	closemessage
	setvar VAR_OLD_GUYS_STATE, 3
	warpsilent MAP_TRICK_HOUSE_ENTRANCE, 6, 2
	waitstate
	releaseall
	end

TrickHouseEntrance_EventScript_OrdinaryCabinet::
	msgbox TrickHouseEntrance_Text_OrdinaryCabinet, MSGBOX_AUTOCLOSE
	releaseall
	end

TrickHouseEntrance_EventScript_Giddy::
	lock
	faceplayer
	goto_if_le VAR_OLD_GUYS_STATE, 1, TrickHouseEntrance_EventScript_GiddyPreQuestStart
	goto_if_set FLAG_POTTRICIA_DEFEATED, TrickHouseEntrance_EventScript_GiddyRetires
	msgbox TrickHouseEntrance_Text_IAmTrickMaster, MSGBOX_DEFAULT
	setvar VAR_OLD_GUYS_STATE, 4
	clearflag FLAG_TEMP_14
	addobject LOCALID_P_MAN
	playse SE_DOOR
	waitse
	speakername TrickHouseEntrance_Text_NameKizuna
	msgbox TrickHouseEntrance_Text_ThisIsOurLead, MSGBOX_DEFAULT
	applymovement LOCALID_P_MAN, TrickHouseEntrance_Movement_KizunaWalkIn
	speakername TrickHouseEntrance_Text_NameGiddy
	msgbox TrickHouseEntrance_Text_WhatDoYouNeed, MSGBOX_DEFAULT
	applymovement LOCALID_TRICK_MASTER, TrickHouseEntrance_Movement_FaceLeft
	waitmovement 0
	speakername TrickHouseEntrance_Text_NameKizuna
	msgbox TrickHouseEntrance_Text_NeedAWayIn, MSGBOX_DEFAULT
	speakername TrickHouseEntrance_Text_NameGiddy
	msgbox TrickHouseEntrance_Text_DoMyPuzzle, MSGBOX_DEFAULT
	speakername NULL
	applymovement LOCALID_TRICK_MASTER, TrickHouseEntrance_Movement_GiddyHop
	waitmovement 0
	playse SE_M_FAINT_ATTACK
	removeobject LOCALID_TRICK_MASTER
	setflag FLAG_TEMP_11
	delay 16
	dofieldeffectsparkle 5, 1, 0
	release
	end

TrickHouseEntrance_Movement_KizunaWalkIn:
	walk_up
	walk_up
	walk_left
	walk_left
	walk_up
	face_right
	step_end

TrickHouseEntrance_Movement_FaceLeft:
	face_left
	step_end

TrickHouseEntrance_Movement_GiddyHop:
	jump_in_place_down
	jump_in_place_down
	step_end

TrickHouseEntrance_EventScript_GiddyPreQuestStart::
	msgbox TrickHouseEntrance_Text_GiddyPreQuestStart, MSGBOX_AUTOCLOSE
	release
	end

TrickHouseEntrance_EventScript_GiddyRetires::
	speakername TrickHouseEntrance_Text_NameGiddy
	msgbox TrickHouseEntrance_Text_YouCompletedMyPuzzle, MSGBOX_DEFAULT
	clearflag FLAG_TEMP_14
	addobject LOCALID_P_MAN
	playse SE_DOOR
	applymovement LOCALID_P_MAN, TrickHouseEntrance_Movement_KizunaWalkIn
	speakername TrickHouseEntrance_Text_NameKizuna
	msgbox TrickHouseEntrance_Text_GiveUsInfo, MSGBOX_DEFAULT
	speakername TrickHouseEntrance_Text_NameGiddy
	msgbox TrickHouseEntrance_Text_CanIHaveAMoment, MSGBOX_DEFAULT
	applymovement OBJ_EVENT_ID_PLAYER, TrickHouseEntrance_Movement_StepBack
	waitmovement 0
	applymovement LOCALID_TRICK_MASTER, TrickHouseEntrance_Movement_GiddyFaceDown
	applymovement LOCALID_P_MAN, TrickHouseEntrance_Movement_KizunaGoToGiddy
	waitmovement 0
	speakername TrickHouseEntrance_Text_NameKizuna
	msgbox TrickHouseEntrance_Text_YesGiddy, MSGBOX_DEFAULT
	fadenewbgm MUS_VERDANTURF
	speakername TrickHouseEntrance_Text_NameGiddy
	msgbox TrickHouseEntrance_Text_TimeToRetire, MSGBOX_DEFAULT
	closemessage
	playse SE_M_MEGA_KICK
	applymovement LOCALID_P_MAN, TrickHouseEntrance_Movement_KizunaAbsorbGiddy
	waitmovement 0
	removeobject LOCALID_TRICK_MASTER
	setflag FLAG_TEMP_11
	setvar VAR_OLD_GUYS_STATE, 5
	playse SE_M_FAINT_ATTACK
	waitse
	applymovement OBJ_EVENT_ID_PLAYER, TrickHouseEntrance_Movement_WalkDown
	fadenewbgm MUS_NONE
	speakername TrickHouseEntrance_Text_NameKizuna
	msgbox TrickHouseEntrance_Text_MyBodyDidThatOnItsOwn, MSGBOX_DEFAULT
	speakername NULL
	closemessage
	applymovement LOCALID_P_MAN, TrickHouseEntrance_Movement_KizunaLeave
	waitmovement 0
	playse SE_EXIT
	removeobject LOCALID_P_MAN
	setflag FLAG_TEMP_14
	release
	end

TrickHouseEntrance_Movement_StepBack:
	walk_right
	walk_right
	walk_up
	face_left
	step_end

TrickHouseEntrance_Movement_GiddyFaceDown:
	face_down
	step_end

TrickHouseEntrance_Movement_KizunaGoToGiddy:
	walk_down
	walk_right
	walk_right
	walk_right
	face_up
	step_end

TrickHouseEntrance_Movement_KizunaAbsorbGiddy:
	walk_slow_up
	step_end

TrickHouseEntrance_Movement_WalkDown:
	walk_down
	step_end

TrickHouseEntrance_Movement_KizunaLeave:
	walk_slow_down
	walk_slow_left
	walk_slow_down
	walk_slow_down
	step_end

TrickHouseEntrance_EventScript_KizunaIdle::
	lock
	faceplayer
	speakername TrickHouseEntrance_Text_NameKizuna
	msgbox TrickHouseEntrance_Text_MustExplore, MSGBOX_AUTOCLOSE
	release
	end

TrickHouseEntrance_EventScript_EntranceScroll::
	lock
	goto_if_lt VAR_OLD_GUYS_STATE, 4, TrickHouseEntrance_EventScript_Unreadable
	msgbox TrickHouseEntrance_Text_YouCanNowReadScroll, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, TrickHouseEntrance_EventScript_WarpIn
	release
	end

TrickHouseEntrance_EventScript_WarpIn::
	warp MAP_TRICK_HOUSE_MAIN_PORTION, 3, 15
	waitstate
	release
	end

TrickHouseEntrance_EventScript_Unreadable::
	msgbox TrickHouseEntrance_Text_Unreadable, MSGBOX_AUTOCLOSE
	release
	end	

TrickHouseEntrance_Text_NameKizuna:
	.string "Kizuna$"

TrickHouseEntrance_Text_NameGiddy:
	.string "Giddy$"

TrickHouseEntrance_Text_YoureBeingWatched:
	.string "You're being watched…$"

TrickHouseEntrance_Text_NotBeingWatched:
	.string "Not being watched anymore.$"

TrickHouseEntrance_Text_ConcealedInCabinet:
	.string "Hah? Grrr…\p"
	.string "How did you know I concealed myself\n"
	.string "in this cabinet? You're sharp!\p"
	.string "Let's talk by the table!$"

TrickHouseEntrance_Text_OrdinaryCabinet:
	.string "(It's an ordinary cabinet...)$"

TrickHouseEntrance_Text_GiddyPreQuestStart:
	.string "Gehee-hee... time to plan\n"
	.string "out a new maze for the\l"
	.string "Trick House...\p"
	.string "...Hmm? Who are you?\n"
	.string "Kindly get outta here!$"

TrickHouseEntrance_Text_IAmTrickMaster:
	.string "I... am the fabulous\n"
	.string "Trick Master, Giddy!\l"
	.string "What brings you to my abode,\l"
	.string "traveller?$"

TrickHouseEntrance_Text_ThisIsOurLead:
	.string "Well, looks like I found this\n"
	.string "place just in the nick of time!\l"
	.string "This is exactly who I\l"
	.string "wanted to see!$"

TrickHouseEntrance_Text_WhatDoYouNeed:
	.string "Oh, an entourage? Gehee-hee..!\p"
	.string "You two are clearly in pursuit\n"
	.string "of something. Knowledge, perhaps?\l"
	.string "Or maybe a little... adventure?$"

TrickHouseEntrance_Text_NeedAWayIn:
	.string "You could say we are in pursuit\n"
	.string "of knowledge, yes.\l"
	.string "We are looking to meet\l"
	.string "The Storyteller. And we know that\l"
	.string "you two are friends.\l"
	.string "Would you be willing to point\l"
	.string "us towards him?$"

TrickHouseEntrance_Text_DoMyPuzzle:
	.string "Geh! Geheheheh! Geheheheheheh!\p"
	.string "I will give you the information\n"
	.string "you so desperately seek!\p"
	.string "But!\p"
	.string "You must solve my maze of\n"
	.string "tricks and turns first!\p"
	.string "Jump into the scroll!\n"
	.string "Adventure... awaits! Gehee-hee!$"

TrickHouseEntrance_Text_MustExplore:
	.string "Whelp. I should have pegged that\n"
	.string "he was looney.\p"
	.string "It looks like we're going to\n"
	.string "have to 'solve his maze'.\l"
	.string "Let's get exploring, {PLAYER}.$"

TrickHouseEntrance_Text_YouCompletedMyPuzzle:
	.string "Geheheheh! Geheh!\n"
	.string "I am pleased as punch!\l"
	.string "You've solved all of my puzzles!$"

TrickHouseEntrance_Text_GiveUsInfo:
	.string "My... head feels like it\n"
	.string "got unscrewed and put back on wrong.\p"
	.string "Are you going to give us the\n"
	.string "information we want now, Giddy?\l"
	.string "That's the deal, right?$"

TrickHouseEntrance_Text_CanIHaveAMoment:
	.string "Indeedily-doo! Gehee-hee!\n"
	.string "Come a bit closer, my boy.\l"
	.string "I don't wanna have to speak\l"
	.string "louder than I must.$"

TrickHouseEntrance_Text_YesGiddy:
	.string "Alright. Please, tell us\n"
	.string "where we can find The Storyteller.$"

TrickHouseEntrance_Text_TimeToRetire:
	.string "The Storyteller...\n"
	.string "geh-heh... what a dear friend\l"
	.string "of mine he was. We used to\l"
	.string "draft up puzzles together!\l"
	.string "Those were the days.\p"
	.string "Geh.... I fear my mind's been\n"
	.string "on the fritz these recent years.\l"
	.string "Maybe it's time for ol' Giddy\l"
	.string "to retire.\p"
	.string "Will you do that for me?\n"
	.string "Let me be at peace?$"

TrickHouseEntrance_Text_MyBodyDidThatOnItsOwn:
	.string "W-W-What....\p"
	.string "You... saw that happen, right?\p"
	.string "My.. m-my body did that on\n"
	.string "its own, it felt...\l"
	.string "It was like... I absorbed him...\p"
	.string "What... is going on...\p"
	.string "Giddy... I can feel his memories\n"
	.string "coursing through me...\l"
	.string "Maybe I really did absorb\l"
	.string "him in some way...\p"
	.string "Hmm. Judging by what Giddy's\n"
	.string "memories tell me...\l"
	.string "our best bet is to look for their\l"
	.string "mutual friend, Rydel...\p"
	.string "I believe he owns a bike shop\n"
	.string "in New Mauville. Let's...\l"
	.string "head there.\p"
	.string "And I'll try to... process\n"
	.string "what has happened to me...$"

TrickHouseEntrance_Text_Unreadable:
	.string "(You try to read the scroll,\n"
	.string "but your brain feels like it is\l"
	.string "blurring out the words somehow...)$"

TrickHouseEntrance_Text_YouCanNowReadScroll:
	.string "(You try to read the scroll,\n"
	.string "and it is difficult, but you\l"
	.string "manage to make out the following...)\p"
	.string "GO TO THE TRICK HOUSE?$"
