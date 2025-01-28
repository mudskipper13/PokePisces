.set LOCALID_STEVEN, 3
.set LOCALID_SIDNEY, 1
.set LOCALID_LUCY, 2

SeasideCasinoBattleRoom_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, SeasideCasinoBattleRoom_OnLoad
	.byte 0

SeasideCasinoBattleRoom_OnLoad:
	call_if_gt VAR_WALLY_QUEST_STATE, 6, SeasideCasinoBattleRoom_EventScript_RemoveSteven
	end

SeasideCasinoBattleRoom_EventScript_RemoveSteven::
	removeobject LOCALID_STEVEN
	setflag FLAG_TEMP_11
	return

SeasideCasinoBattleRoom_EventScript_SidneyLucyBattle::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, SeasideCasinoBattleRoom_Movement_PlayerMeetSidney
	waitmovement 0
	turnobject LOCALID_STEVEN, DIR_WEST
	speakername SeasideCasinoBattleRoom_Text_NameSteven
	msgbox SeasideCasinoBattleRoom_Text_HelloPlayer, MSGBOX_DEFAULT
	turnobject LOCALID_STEVEN, DIR_NORTH
	speakername SeasideCasinoBattleRoom_Text_NameSidney
	msgbox SeasideCasinoBattleRoom_Text_WhatDoYouWant, MSGBOX_DEFAULT
	speakername SeasideCasinoBattleRoom_Text_NameSteven
	msgbox SeasideCasinoBattleRoom_Text_TheresBeenAForgery, MSGBOX_DEFAULT
	speakername SeasideCasinoBattleRoom_Text_NameSidney
	msgbox SeasideCasinoBattleRoom_Text_HowBoutAWager, MSGBOX_DEFAULT
	turnobject LOCALID_SIDNEY, DIR_WEST
	speakername SeasideCasinoBattleRoom_Text_NameSidney
	msgbox SeasideCasinoBattleRoom_Text_LucyComeOver, MSGBOX_DEFAULT
	applymovement LOCALID_LUCY, SeasideCasinoBattleRoom_Movement_LucyComeToChair
	waitmovement 0
	turnobject LOCALID_SIDNEY, DIR_SOUTH
	speakername SeasideCasinoBattleRoom_Text_NameLucy
	msgbox SeasideCasinoBattleRoom_Text_AreWeBattling, MSGBOX_DEFAULT
	speakername SeasideCasinoBattleRoom_Text_NameSidney
	msgbox SeasideCasinoBattleRoom_Text_LetsTussleWinnerGetsInfo, MSGBOX_DEFAULT
	speakername NULL
	trainerbattle_two_trainers TRAINER_P_SIDNEY, SeasideCasinoBattleRoom_Text_SidneyDefeat, TRAINER_P_LUCY, SeasideCasinoBattleRoom_Text_LucyDefeat, SeasideCasinoBattleRoom_EventScript_LeadersDefeated, NO_MUSIC
	goto SeasideCasinoBattleRoom_EventScript_LeadersDefeated
	release
	end

SeasideCasinoBattleRoom_EventScript_LeadersDefeated::
	setvar VAR_WALLY_QUEST_STATE, 7
	speakername SeasideCasinoBattleRoom_Text_NameSidney
	msgbox SeasideCasinoBattleRoom_Text_AlrightThen, MSGBOX_DEFAULT
	speakername SeasideCasinoBattleRoom_Text_NameLucy
	msgbox SeasideCasinoBattleRoom_Text_DoctorInfoDump, MSGBOX_DEFAULT
	speakername SeasideCasinoBattleRoom_Text_NameSidney
	msgbox SeasideCasinoBattleRoom_Text_ThanksDoll, MSGBOX_DEFAULT
	turnobject LOCALID_STEVEN, DIR_WEST
	speakername SeasideCasinoBattleRoom_Text_NameSteven
	msgbox SeasideCasinoBattleRoom_Text_LetsGetOutOfHereAndRegroup, MSGBOX_DEFAULT
	warp MAP_SEASIDE_CASINO, 18, 8
	waitstate
	release
	end

SeasideCasinoBattleRoom_Movement_PlayerMeetSidney:
	walk_up
	walk_up
	walk_left
	face_up
	step_end

SeasideCasinoBattleRoom_Movement_LucyComeToChair:
	walk_down
	walk_down
	step_end

SeasideCasinoBattleRoom_Text_NameSteven:
	.string "Steven$"

SeasideCasinoBattleRoom_Text_NameSidney:
	.string "Sidney$"

SeasideCasinoBattleRoom_Text_NameLucy:
	.string "Lucy$"

SeasideCasinoBattleRoom_Text_HelloPlayer:
	.string "Just in time. I had just\n"
	.string "started interrogating an...\l"
	.string "old coworker of mine.\p"
	.string "Sidney here was expelled\n"
	.string "from the League after reports\l"
	.string "of money smuggling. He was never\l"
	.string "charged, which I disagree with.$"

SeasideCasinoBattleRoom_Text_WhatDoYouWant:
	.string "Can it, Stone. You're in\n"
	.string "MY turf. Ya don't get to pull\l"
	.string "the justice n' truth card.\p"
	.string "Now I know your ugly mug wouldn't\n"
	.string "be sittin' in fronna me if\l"
	.string "ya didn't have somethin'\l"
	.string "real pressin' to ask me about.\l"
	.string "So, whaddaya want? N' watch that\l"
	.string "harsh tongue a' yours.$"

SeasideCasinoBattleRoom_Text_TheresBeenAForgery:
	.string "This trainer, I believe, has\n"
	.string "been a target of a forging campaign\l"
	.string "to block their league\l"
	.string "certification.\p"
	.string "I simply want to pick your brain\n"
	.string "to obtain intel on known\l"
	.string "forgers in Hoenn. I do not wish\l"
	.string "to step on your toes.$"

SeasideCasinoBattleRoom_Text_HowBoutAWager:
	.string "How 'boutta wager?$"

SeasideCasinoBattleRoom_Text_LucyComeOver:
	.string "Luce, doll. Get your behind\n"
	.string "up here.$"

SeasideCasinoBattleRoom_Text_AreWeBattling:
	.string "... ... ... ...\n"
	.string "I am ready to lay down the law.\p"
	.string "No idle chatter. ...Sid.\n"
	.string "Let me humiliate them.$"

SeasideCasinoBattleRoom_Text_LetsTussleWinnerGetsInfo:
	.string "Good! You're ready for a\n"
	.string "knock-out, drag-out brawl, eh?\l"
	.string "Well, same here!\p"
	.string "Here's the wager. We fight your\n"
	.string "weak lookin' pal, Stone.\l"
	.string "Without you joinin' 'em.\l"
	.string "If they pull out the W, we\l"
	.string "spill our beans.\l"
	.string "If not, then you're outta here.\p"
	.string "Ready to gamble, pipsqueak!?$"

SeasideCasinoBattleRoom_Text_SidneyDefeat:
	.string "A wise guy, eh?$"

SeasideCasinoBattleRoom_Text_LucyDefeat:
	.string "Urk...!$"

SeasideCasinoBattleRoom_Text_AlrightThen:
	.string "Looks like lady luck's on ya\n"
	.string "side, pipsqueak. I concede.\p"
	.string "Luce, I don't wanna give 'em\n"
	.string "the long version. Can ya give\l"
	.string "'em the short version for me?$"

SeasideCasinoBattleRoom_Text_DoctorInfoDump:
	.string "... ... ... ...\p"
	.string "I have no reason to respect you.\n"
	.string "But, since Sid desires...\p"
	.string "...We know a forger.\n"
	.string "One of the best. Seems to be\l"
	.string "a talented psychic.\l"
	.string "Can forge people's signatures\l"
	.string "one-to-one using his mind.\p"
	.string "Met them once. Short on words.\n"
	.string "Can relate...\l"
	.string "Called themselves 'The Doctor'.\l"
	.string "Refused to give personal info.\l"
	.string "Was short. Feeble stature.\l"
	.string "Wore cloth to cover their face.\p"
	.string "...Had a bit of a wheezing cough.\n"
	.string "Glad they kept the cloth on.\p"
	.string "That is all I know.\n"
	.string "You may now kindly disappear\l"
	.string "from my world.$"

SeasideCasinoBattleRoom_Text_ThanksDoll:
	.string "Thanks, doll. N' yeah, I got\n"
	.string "nothin' to add. This Doctor\l"
	.string "wannabe is your man. Prob'ly.\p"
	.string "Anyways, I'm up to my knees in\n"
	.string "crud to sign off on. Busier than\l"
	.string "a one-legged guy in an\l"
	.string "ass-kickin' contest, for sure.\l"
	.string "Get to steppin'.$"

SeasideCasinoBattleRoom_Text_LetsGetOutOfHereAndRegroup:
	.string "...Quite. Let's adjourn to the\n"
	.string "lobby and make sense of\l"
	.string "what we know, {PLAYER}.$"
