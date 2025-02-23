MirageIsland_MapScripts::
	.byte 0

MirageIsland_EventScript_ZoruaEventSon::
	lock
	faceplayer
	goto_if_eq VAR_ZORUA_QUEST_STATE, 4, MirageIsland_EventScript_DoneTalking
	msgbox MirageIsland_Text_WhoAreYou, MSGBOX_DEFAULT
	goto_if_eq VAR_ZORUA_QUEST_STATE, 2, MirageIsland_EventScript_GiveComedyMask
	goto_if_eq VAR_ZORUA_QUEST_STATE, 3, MirageIsland_EventScript_GiveTragedyMask
	release
	end

MirageIsland_EventScript_GiveComedyMask::
	giveitem ITEM_COMEDY_MASK
	delay 8
	goto MirageIsland_EventScript_SonLeave
	release
	end

MirageIsland_EventScript_GiveTragedyMask::
	giveitem ITEM_TRAGEDY_MASK
	delay 8
	goto MirageIsland_EventScript_SonLeave
	release
	end

MirageIsland_EventScript_SonLeave::
	setvar VAR_ZORUA_QUEST_STATE, 4
	msgbox MirageIsland_Text_LeaveMeHere, MSGBOX_AUTOCLOSE
	release
	end

MirageIsland_EventScript_DoneTalking::
	msgbox MirageIsland_Text_NothingLeftToSay, MSGBOX_AUTOCLOSE
	release
	end

MirageIsland_EventScript_MirageIslandSailor::
	lock
	faceplayer
	msgbox MirageIsland_Text_AllDoneHere, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MirageIsland_EventScript_SailToSailorsPause
	msgbox MirageIsland_Text_CallMeWhenReady, MSGBOX_AUTOCLOSE
	release
	end

MirageIsland_EventScript_SailToSailorsPause::
	msgbox MirageIsland_Text_LetsSetSail, MSGBOX_DEFAULT
	closemessage
	delay 8
	warp MAP_SAILORS_PAUSE, 27, 19
	waitstate
	release
	end

MirageIsland_Text_WhoAreYou:
	.string "A-Another person...?\n"
	.string "Has your ship capsized\l"
	.string "on the island as well?\p"
	.string "...Hold on...\n"
	.string "That Zorua you have with you...\p"
	.string "I recognize it.\p"
	.string "...\p"
	.string "So, you've befriended my\n"
	.string "father, then? Is he...\l"
	.string "doing well? In good health?\p"
	.string "...That's a relief.\n"
	.string "I'm glad that one of my\l"
	.string "Pokemon is getting to explore\l"
	.string "the region with you.\p"
	.string "Take good care of that Zorua.\n"
	.string "...Hm, hold on one second...\p"
	.string "(The man rummages through\n"
	.string "a crate nearby.)\p"
	.string "Take this mask. When I first\n"
	.string "found that Zorua, it was\l"
	.string "tied around its torso.\l"
	.string "I never found out the\l"
	.string "significance of the thing.\l"
	.string "But maybe, you can.$"

MirageIsland_Text_LeaveMeHere:
	.string "...No, sorry. I am not going\n"
	.string "to be coming back with you.\p"
	.string "I was born to be a nomad.\n"
	.string "Getting to live on a deserted\l"
	.string "island like this...\l"
	.string "that's something I can't turn down.\p"
	.string "...Don't let my father know.\n"
	.string "I'd prefer to not be found.\p"
	.string "Happy travels, {PLAYER}.$"

MirageIsland_Text_NothingLeftToSay:
	.string "You should be on your way.\n"
	.string "Don't worry about me...\l"
	.string "I have enough supplies here\l"
	.string "to live comfortably.$"

MirageIsland_Text_AllDoneHere:
	.string "Are ya all done here, mate?$"

MirageIsland_Text_CallMeWhenReady:
	.string "Let me know when you're\n"
	.string "ready to sail back.$"

MirageIsland_Text_LetsSetSail:
	.string "'Bout time to haul anchor, then.$"
