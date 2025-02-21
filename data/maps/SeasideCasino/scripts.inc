.set LOCALID_STEVEN, 2
.set LOCALID_STEVEN2, 4
.set LOCALID_DOORGUARD, 1

SeasideCasino_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, SeasideCasino_OnLoad
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SeasideCasino_OnFrame
	.byte 0

SeasideCasino_OnLoad:
	call SeasideCasino_EventScript_RemoveSteven
	call_if_eq VAR_WALLY_QUEST_STATE, 5, SeasideCasino_EventScript_RemoveDoorGuard
	call_if_eq VAR_WALLY_QUEST_STATE, 6, SeasideCasino_EventScript_RemoveDoorGuard
	end

SeasideCasino_OnFrame:
	map_script_2 VAR_WALLY_QUEST_STATE, 7, SeasideCasino_EventScript_StevenDiscussion
	.2byte 0

SeasideCasino_EventScript_RemoveSteven::
	removeobject LOCALID_STEVEN
	removeobject LOCALID_STEVEN2
	setflag FLAG_TEMP_11
	setflag FLAG_TEMP_13
	return

SeasideCasino_EventScript_RemoveDoorGuard::
	removeobject LOCALID_DOORGUARD
	setflag FLAG_TEMP_12
	return

SeasideCasino_EventScript_StevenDiscussion::
	lock
	clearflag FLAG_TEMP_13
	addobject LOCALID_STEVEN2
	speakername SeasideCasino_Text_NameSteven
	msgbox SeasideCasino_Text_WhatAreOurOptions, MSGBOX_DEFAULT
	speakername NULL
	msgbox SeasideCasino_Text_ThinkingItOver, MSGBOX_DEFAULT
	multichoice 19, 4, MULTI_WHODUNNIT, TRUE
	copyvar VAR_TEMP_1, VAR_RESULT
	switch VAR_TEMP_1
	case 0, SeasideCasino_EventScript_AnswerNorman
	case 1, SeasideCasino_EventScript_AnswerWally
	case 2, SeasideCasino_EventScript_AnswerLiza
	case 3, SeasideCasino_EventScript_AnswerTate
	case 4, SeasideCasino_EventScript_AnswerMrBonding
	release
	end

SeasideCasino_EventScript_AnswerNorman::
	speakername SeasideCasino_Text_NameSteven
	msgbox SeasideCasino_Text_CantBeNorman, MSGBOX_DEFAULT
	speakername NULL
	msgbox SeasideCasino_Text_ThinkingItOverAgain, MSGBOX_DEFAULT
	multichoice 19, 4, MULTI_WHODUNNIT, TRUE
	copyvar VAR_TEMP_1, VAR_RESULT
	switch VAR_TEMP_1
	case 0, SeasideCasino_EventScript_AnswerNorman
	case 1, SeasideCasino_EventScript_AnswerWally
	case 2, SeasideCasino_EventScript_AnswerLiza
	case 3, SeasideCasino_EventScript_AnswerTate
	case 4, SeasideCasino_EventScript_AnswerMrBonding
	release
	end

SeasideCasino_EventScript_AnswerLiza::
	speakername SeasideCasino_Text_NameSteven
	msgbox SeasideCasino_Text_CantBeLiza, MSGBOX_DEFAULT
	speakername NULL
	msgbox SeasideCasino_Text_ThinkingItOverAgain, MSGBOX_DEFAULT
	multichoice 19, 4, MULTI_WHODUNNIT, TRUE
	copyvar VAR_TEMP_1, VAR_RESULT
	switch VAR_TEMP_1
	case 0, SeasideCasino_EventScript_AnswerNorman
	case 1, SeasideCasino_EventScript_AnswerWally
	case 2, SeasideCasino_EventScript_AnswerLiza
	case 3, SeasideCasino_EventScript_AnswerTate
	case 4, SeasideCasino_EventScript_AnswerMrBonding
	release
	end

SeasideCasino_EventScript_AnswerTate::
	speakername SeasideCasino_Text_NameSteven
	msgbox SeasideCasino_Text_CantBeTate, MSGBOX_DEFAULT
	speakername NULL
	msgbox SeasideCasino_Text_ThinkingItOverAgain, MSGBOX_DEFAULT
	multichoice 19, 4, MULTI_WHODUNNIT, TRUE
	copyvar VAR_TEMP_1, VAR_RESULT
	switch VAR_TEMP_1
	case 0, SeasideCasino_EventScript_AnswerNorman
	case 1, SeasideCasino_EventScript_AnswerWally
	case 2, SeasideCasino_EventScript_AnswerLiza
	case 3, SeasideCasino_EventScript_AnswerTate
	case 4, SeasideCasino_EventScript_AnswerMrBonding
	release
	end

SeasideCasino_EventScript_AnswerMrBonding::
	speakername SeasideCasino_Text_NameSteven
	msgbox SeasideCasino_Text_CantBeMrBonding, MSGBOX_DEFAULT
	speakername NULL
	msgbox SeasideCasino_Text_ThinkingItOverAgain, MSGBOX_DEFAULT
	multichoice 19, 4, MULTI_WHODUNNIT, TRUE
	copyvar VAR_TEMP_1, VAR_RESULT
	switch VAR_TEMP_1
	case 0, SeasideCasino_EventScript_AnswerNorman
	case 1, SeasideCasino_EventScript_AnswerWally
	case 2, SeasideCasino_EventScript_AnswerLiza
	case 3, SeasideCasino_EventScript_AnswerTate
	case 4, SeasideCasino_EventScript_AnswerMrBonding
	release
	end

SeasideCasino_EventScript_AnswerWally::
	speakername NULL
	msgbox SeasideCasino_Text_IsItReallyHim, MSGBOX_DEFAULT
	speakername SeasideCasino_Text_NameSteven
	msgbox SeasideCasino_Text_WallyIsOurMan, MSGBOX_DEFAULT
	applymovement LOCALID_STEVEN2, SeasideCasino_Movement_StevenReadyToLeave
	waitmovement 0
	speakername SeasideCasino_Text_NameSteven
	msgbox SeasideCasino_Text_MeetMeInMossdeep, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_STEVEN2, SeasideCasino_Movement_StevenLeavesFinal
	waitmovement 0
	removeobject LOCALID_STEVEN2
	setflag FLAG_TEMP_13
	setvar VAR_WALLY_QUEST_STATE, 8
	delay 4
	release
	end

SeasideCasino_Movement_StevenReadyToLeave:
	walk_down
	walk_left
	face_up
	step_end

SeasideCasino_Movement_StevenLeavesFinal:
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

SeasideCasino_EventScript_BackroomGuard::
	lock
	goto_if_lt VAR_WALLY_QUEST_STATE, 4, SeasideCasino_EventScript_CantGoPast
	goto_if_gt VAR_WALLY_QUEST_STATE, 7, SeasideCasino_EventScript_CantGoPast
	goto_if_eq VAR_FACING, DIR_NORTH, SeasideCasino_EventScript_StevenApproachFromSide
	goto SeasideCasino_EventScript_StevenApproach
	release
	end

SeasideCasino_EventScript_CantGoPast::
	faceplayer
	msgbox SeasideCasino_Text_CantGoPast, MSGBOX_AUTOCLOSE
	release
	end

SeasideCasino_EventScript_StevenApproach::
	speakername NULL
	clearflag FLAG_TEMP_11
	addobject LOCALID_STEVEN
	faceplayer
	msgbox SeasideCasino_Text_CantGoPast, MSGBOX_DEFAULT
	applymovement LOCALID_STEVEN, SeasideCasino_Movement_StevenApproach
	waitmovement 0
	turnobject LOCALID_DOORGUARD, DIR_SOUTH
	speakername SeasideCasino_Text_NameSteven
	msgbox SeasideCasino_Text_YouShouldLetUsIn, MSGBOX_DEFAULT
	speakername NULL
	msgbox SeasideCasino_Text_CantLetInPlayer, MSGBOX_DEFAULT
	speakername SeasideCasino_Text_NameSteven
	msgbox SeasideCasino_Text_ComeWithMe, MSGBOX_AUTOCLOSE
	applymovement LOCALID_STEVEN, SeasideCasino_Movement_StevenWalkAway
	applymovement LOCALID_DOORGUARD, SeasideCasino_Movement_DoorGuardWalkAway
	waitmovement 0
	waitmessage
	removeobject LOCALID_STEVEN
	setflag FLAG_TEMP_11
	removeobject LOCALID_DOORGUARD
	setflag FLAG_TEMP_12
	setvar VAR_WALLY_QUEST_STATE, 5
	release
	end

SeasideCasino_Movement_StevenApproach:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_up
	step_end

SeasideCasino_Movement_StevenWalkAway:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

SeasideCasino_Movement_DoorGuardWalkAway:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

SeasideCasino_EventScript_StevenApproachFromSide::
	faceplayer
	speakername NULL
	clearflag FLAG_TEMP_11
	addobject LOCALID_STEVEN
	msgbox SeasideCasino_Text_CantGoPast, MSGBOX_DEFAULT
	applymovement LOCALID_STEVEN, SeasideCasino_Movement_StevenApproachFromSide
	waitmovement 0
	turnobject LOCALID_DOORGUARD, DIR_WEST
	speakername SeasideCasino_Text_NameSteven
	msgbox SeasideCasino_Text_YouShouldLetUsIn, MSGBOX_DEFAULT
	speakername NULL
	msgbox SeasideCasino_Text_CantLetInPlayer, MSGBOX_DEFAULT
	speakername SeasideCasino_Text_NameSteven
	msgbox SeasideCasino_Text_ComeWithMe, MSGBOX_AUTOCLOSE
	applymovement LOCALID_STEVEN, SeasideCasino_Movement_StevenWalkAwayFromSide
	applymovement LOCALID_DOORGUARD, SeasideCasino_Movement_DoorGuardWalkAwayFromSide
	waitmovement 0
	waitmessage
	removeobject LOCALID_STEVEN
	setflag FLAG_TEMP_11
	removeobject LOCALID_DOORGUARD
	setflag FLAG_TEMP_12
	setvar VAR_WALLY_QUEST_STATE, 5
	release
	end

SeasideCasino_Movement_StevenApproachFromSide:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_right
	walk_right
	walk_up
	walk_up
	face_right
	step_end

SeasideCasino_Movement_StevenWalkAwayFromSide:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

SeasideCasino_Movement_DoorGuardWalkAwayFromSide:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

SeasideCasino_EventScript_SlotMachine0::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, SeasideCasino_EventScript_NoCoinCase
	setvar VAR_0x8004, 0
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

SeasideCasino_EventScript_SlotMachine1::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, SeasideCasino_EventScript_NoCoinCase
	setvar VAR_0x8004, 1
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

SeasideCasino_EventScript_SlotMachine2::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, SeasideCasino_EventScript_NoCoinCase
	setvar VAR_0x8004, 2
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

SeasideCasino_EventScript_SlotMachine3::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, SeasideCasino_EventScript_NoCoinCase
	setvar VAR_0x8004, 3
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

SeasideCasino_EventScript_SlotMachine4::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, SeasideCasino_EventScript_NoCoinCase
	setvar VAR_0x8004, 4
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

SeasideCasino_EventScript_SlotMachine5::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, SeasideCasino_EventScript_NoCoinCase
	setvar VAR_0x8004, 5
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

SeasideCasino_EventScript_SlotMachine6::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, SeasideCasino_EventScript_NoCoinCase
	setvar VAR_0x8004, 6
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

SeasideCasino_EventScript_SlotMachine7::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, SeasideCasino_EventScript_NoCoinCase
	setvar VAR_0x8004, 7
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

SeasideCasino_EventScript_SlotMachine8::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, SeasideCasino_EventScript_NoCoinCase
	setvar VAR_0x8004, 8
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

SeasideCasino_EventScript_SlotMachine9::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, SeasideCasino_EventScript_NoCoinCase
	setvar VAR_0x8004, 9
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

SeasideCasino_EventScript_SlotMachine10::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, SeasideCasino_EventScript_NoCoinCase
	setvar VAR_0x8004, 10
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

SeasideCasino_EventScript_SlotMachine11::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, SeasideCasino_EventScript_NoCoinCase
	setvar VAR_0x8004, 11
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

SeasideCasino_EventScript_NoCoinCase::
	msgbox SeasideCasino_Text_CantPlayWithNoCoinCase, MSGBOX_DEFAULT
	releaseall
	end

SeasideCasino_Text_NameSteven:
	.string "Steven$"

SeasideCasino_Text_CantPlayWithNoCoinCase:
	.string "(You can't play the games here\n"
	.string "without a Coin Case.)$"

SeasideCasino_Text_CantGoPast:
	.string "Past here is the VIP Rooms, bub.\n"
	.string "Gonna have to block the door\l"
	.string "for ya if ya ain't on the list.\p"
	.string "Which, ya ain't.$"

SeasideCasino_Text_YouShouldLetUsIn:
	.string "Is that really set in stone?\n"
	.string "Surely, the rules can be bent\l"
	.string "for a former champion, heir\l"
	.string "of the Devon Corporation, and\l"
	.string "his honored guest?$"

SeasideCasino_Text_CantLetInPlayer:
	.string "S-Steven? A-Ah, listen, I can\n"
	.string "prob'ly let ya in, but the\l"
	.string "higher-ups're gonna get real\l"
	.string "cross with me if I let in\l"
	.string "that guest with ya...$"

SeasideCasino_Text_ComeWithMe:
	.string "Hm. You know what...\p"
	.string "Come with me. I will speak to\n"
	.string "these higher-ups. They\l"
	.string "will know reason.$"

SeasideCasino_Text_WhatAreOurOptions:
	.string "'The Doctor'... a clever name.\n"
	.string "Both doctor as in, editing\l"
	.string "something, like forging a\l"
	.string "signature... but also a medical\l"
	.string "title of importance.\p"
	.string "That, combined with the cough...\n"
	.string "leads me to believe we're dealing\l"
	.string "with someone medically inclined.\p"
	.string "Though, there is also the ESP\n"
	.string "factor to consider... whoever\l"
	.string "did this has considerable\l"
	.string "psychic power. A sharp mind...\p"
	.string "Not to mention, this must be\n"
	.string "someone with a personal\l"
	.string "vendetta against you. Maybe an\l"
	.string "open one, maybe a hidden one...$"

SeasideCasino_Text_ThinkingItOver:
	.string "(...)\p"
	.string "(...Psychic ability...\n"
	.string "...ties to the medical field...\l"
	.string "...a vendetta with you...)\p"
	.string "(The identity of The Doctor\n"
	.string "must be...!)$"

SeasideCasino_Text_ThinkingItOverAgain:
	.string "(Right. How silly of you.\n"
	.string "Thinking it over again...)\p"
	.string "(...)\p"
	.string "(...Psychic ability...\n"
	.string "...ties to the medical field...\l"
	.string "...a vendetta with you...)\p"
	.string "(The identity of The Doctor\n"
	.string "must be...!)$"

SeasideCasino_Text_CantBeNorman:
	.string "You still insist it to\n"
	.string "be Norman, and that there is\l"
	.string "no forgery afoot?\p"
	.string "Well, if that is the case, then\n"
	.string "you should not be arguing this\l"
	.string "point, {PLAYER}. If he really\l"
	.string "did just use the forgery angle\l"
	.string "as a smokescreen, and he signed\l"
	.string "the paper himself, then there\l"
	.string "is no grounds to reinstate your\l"
	.string "certification.\p"
	.string "In addition, after speaking with\n"
	.string "Norman myself, I find it hard\l"
	.string "to believe that he would\l"
	.string "harbor ill will against you.\p"
	.string "Let us go back to the\n"
	.string "drawing board...$"

SeasideCasino_Text_CantBeLiza:
	.string "Liza... hm.\p"
	.string "While she has the League\n"
	.string "credentials to be able to\l"
	.string "know of the paperwork,\l"
	.string "and she does have high\l"
	.string "psychic attunement, I would\l"
	.string "think that if she really\l"
	.string "disliked you personally, she\l"
	.string "would simply have just refused\l"
	.string "to battle you for the second\l"
	.string "badge of your journey.\p"
	.string "No need to go this complicated.\n"
	.string "Back to the drawing board...$"

SeasideCasino_Text_CantBeTate:
	.string "While it is true that Tate is\n"
	.string "someone of high esper caliber\l"
	.string "and has ties to the League,\l"
	.string "he is confirmed to be in a\l"
	.string "far-off region as we speak.\l"
	.string "The forms were submitted locally.\p"
	.string "Let us go back to the\n"
	.string "drawing board...$"

SeasideCasino_Text_CantBeMrBonding:
	.string "Mr... Bonding?\n"
	.string "Oh yes, that peculiar man.\l"
	.string "To me, the case against him\l"
	.string "is simple... I do not think\l"
	.string "he has extensive knowledge\l"
	.string "of the League's workings, nor\l"
	.string "do I believe that he knows\l"
	.string "who Norman is.\p"
	.string "Back to the drawing board...$"

SeasideCasino_Text_IsItReallyHim:
	.string "(The name is about to escape\n"
	.string "from your mouth, but you hesitate.)\p"
	.string "(Why... would Wally... commit such\n"
	.string "a crime? And why... would he\l"
	.string "loathe you so much...?)$"

SeasideCasino_Text_WallyIsOurMan:
	.string "...Wally. That sickly gym\n"
	.string "challenger from yesteryear...\p"
	.string "He does have an unmistakeable,\n"
	.string "constant cough. Small and thin\l"
	.string "in stature, as well...\l"
	.string "Though, I had no idea he harbored\l"
	.string "psychic abilities. Nor a burning\l"
	.string "hatred for you, {PLAYER}.$"

SeasideCasino_Text_MeetMeInMossdeep:
	.string "We should apprehend him as soon\n"
	.string "as we are able. This will take\l"
	.string "some planning and coordination.\l"
	.string "Meet me at my house in\l"
	.string "Mossdeep when you are ready.$"
