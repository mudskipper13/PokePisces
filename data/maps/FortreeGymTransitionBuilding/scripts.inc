.set LOCALID_AARUNE, 1

FortreeGymTransitionBuilding_MapScripts::
	.byte 0

FortreeGymTransitionBuilding_EventScript_Aarune::
	lock
	setflag FLAG_MET_AARUNE
	msgbox FortreeGymTransitionBuilding_Text_AaruneGreeting, MSGBOX_DEFAULT
	speakername FortreeGymTransitionBuilding_Text_NameAarune
	msgbox FortreeGymTransitionBuilding_Text_AaruneMission, MSGBOX_DEFAULT
	closemessage
	delay 8
	applymovement LOCALID_AARUNE, FortreeGymTransitionBuilding_Movement_AaruneLookUp
	waitmovement 0
	delay 16
	playse SE_EXIT
	waitse
	removeobject LOCALID_AARUNE
	release
	end

FortreeGymTransitionBuilding_EventScript_Whistle::
	lock
	setvar VAR_TEMP_4, 1
	goto_if_set FLAG_MET_AARUNE, FortreeGymTransitionBuilding_EventScript_CancelOut
	playmoncry SPECIES_FOONGUS, CRY_MODE_NORMAL
	waitmoncry
	msgbox FortreeGymTransitionBuilding_Text_Whistling, MSGBOX_DEFAULT
	closemessage
	release
	end

FortreeGymTransitionBuilding_EventScript_CantPassAaruneLeft::
	lock
	goto_if_set FLAG_MET_AARUNE, FortreeGymTransitionBuilding_EventScript_CancelOut2
	applymovement LOCALID_AARUNE, FortreeGymTransitionBuilding_Movement_AaruneLookLeft
	waitmovement 0
	msgbox FortreeGymTransitionBuilding_Text_WalkAroundAarune, MSGBOX_AUTOCLOSE
	applymovement OBJ_EVENT_ID_PLAYER, FortreeGymTransitionBuilding_Movement_PlayerMoveDown
	waitmovement 0
	delay 4
	release
	end

FortreeGymTransitionBuilding_EventScript_CantPassAaruneRight::
	lock
	goto_if_set FLAG_MET_AARUNE, FortreeGymTransitionBuilding_EventScript_CancelOut2
	applymovement LOCALID_AARUNE, FortreeGymTransitionBuilding_Movement_AaruneLookRight
	waitmovement 0
	msgbox FortreeGymTransitionBuilding_Text_WalkAroundAarune, MSGBOX_AUTOCLOSE
	applymovement OBJ_EVENT_ID_PLAYER, FortreeGymTransitionBuilding_Movement_PlayerMoveDown
	waitmovement 0
	delay 4
	release
	end

FortreeGymTransitionBuilding_EventScript_CancelOut2::
	setvar VAR_TEMP_5, 1
	release
	end

FortreeGymTransitionBuilding_EventScript_CancelOut::
	release
	end

FortreeGymTransitionBuilding_Movement_AaruneLookUp:
	face_up
	step_end

FortreeGymTransitionBuilding_Movement_AaruneLookLeft:
	face_left
	step_end

FortreeGymTransitionBuilding_Movement_AaruneLookRight:
	face_right
	step_end

FortreeGymTransitionBuilding_Movement_PlayerMoveDown:
	walk_down
	step_end

FortreeGymTransitionBuilding_Text_NameAarune:
	.string "Aarune$"

FortreeGymTransitionBuilding_Text_Whistling:
	.string "(A peculiar man in a red hat is\n"
	.string "whistling to get your attention.)$"

FortreeGymTransitionBuilding_Text_AaruneGreeting:
	.string "I knew I smelled the scent of\n"
	.string "a fellow adventurer!\p"
	.string "Pleased to meet you, little buddy.\n"
	.string "My name is Aarune. Put'er there!$"

FortreeGymTransitionBuilding_Text_AaruneMission:
	.string "My trainers' instinct? You're here\n"
	.string "to take on the gym.\p"
	.string "Bit of a problem with that, see.\n"
	.string "I, uh, had this whole awesome arena\l"
	.string "set up for the occasion\l"
	.string "and everything... but, my\l"
	.string "girlfriend Winona went on one of\l"
	.string "her spacey mountain climbs again!\p"
	.string "I can't gym battle without my\n"
	.string "partner in crime, little buddy!\l"
	.string "She's probably at the tippy-top\l"
	.string "of the peak as we speak, and I'm\l"
	.string "down here on terra firma!\l"
	.string "Oh, what is an Aarune to do...\p"
	.string "If only a certain little buddy\n"
	.string "would help his new pal out by\l"
	.string "fetching his significant other...\p"
	.string "...Psst. That's your cue.\n"
	.string "Strike a cool pose!\p"
	.string "(You strike a purposefully\n"
	.string "uncool pose.)\p"
	.string "Good enough! Anyways, them's\n"
	.string "the breaks. If you find Winona,\l"
	.string "bring her to me. Then we'll\l"
	.string "get to battlin' for the badge!$"

FortreeGymTransitionBuilding_Text_WalkAroundAarune:
	.string "(You try to walk around the man,\n"
	.string "but his eyes expectantly bear\l"
	.string "into your soul.\p"
	.string "Might as well hear him out.)$"
