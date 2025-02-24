.set LOCALID_DOORGUARD, 1
.set LOCALID_TABITHA, 4

OzoneInt_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, OzoneInt_OnTransition
	.byte 0

OzoneInt_OnTransition:
	setrespawn HEAL_LOCATION_OZONE_INSTITUTE
	end

OzoneInt_EventScript_DoorGuard::
	lock
	faceplayer
	goto_if_eq VAR_NEW_COO_STATE, 5, OzoneInt_EventScript_GuardGetOutOfWay
	goto_if_gt VAR_NEW_COO_STATE, 6, OzoneInt_EventScript_GuardPostBattles
	msgbox OzoneInt_Text_CantLetYouUpstairs, MSGBOX_AUTOCLOSE
	release
	end

OzoneInt_EventScript_GuardGetOutOfWay::
	msgbox OzoneInt_Text_ReadyForTheChallenge, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DOORGUARD, OzoneInt_Movement_GuardGetOutOfWay
	waitmovement 0
	playse SE_EXIT
	removeobject LOCALID_DOORGUARD
	setflag FLAG_TEMP_11
	release
	end

OzoneInt_Movement_GuardGetOutOfWay:
	walk_slow_up
	step_end

OzoneInt_EventScript_GuardPostBattles::
	msgbox OzoneInt_Text_GuardPostBattles, MSGBOX_AUTOCLOSE
	release
	end

OzoneInt_EventScript_Maxie::
	lock
	faceplayer
	speakername OzoneInt_Text_NameMaxie
	msgbox OzoneInt_Text_ThingsHaveGottenSerious, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, OzoneInt_EventScript_PlaneWarp
	msgbox OzoneInt_Text_PrepareAdequately, MSGBOX_AUTOCLOSE
	release
	end

OzoneInt_EventScript_PlaneWarp::
	speakername OzoneInt_Text_NameMaxie
	msgbox OzoneInt_Text_NoGoingBack, MSGBOX_DEFAULT
	closemessage
	warp MAP_PLANE_IN_FLIGHT, 7, 5
	waitstate
	release
	end

OzoneInt_EventScript_Archie::
	lock
	faceplayer
	goto_if_lt VAR_OLD_GUYS_STATE, 8, OzoneInt_EventScript_ArchiePreDock
	goto_if_gt VAR_OLD_GUYS_STATE, 8, OzoneInt_EventScript_ArchiePostDock
	goto_if_set FLAG_DOCK_QUEST_FOUND_ARCHIE, OzoneInt_EventScript_ArchieGatherOthers
	setflag FLAG_DOCK_QUEST_FOUND_ARCHIE
	speakername OzoneInt_Text_NameArchie
	msgbox OzoneInt_Text_DockNeedsMe, MSGBOX_AUTOCLOSE
	release
	end

OzoneInt_EventScript_ArchiePreDock::
	speakername OzoneInt_Text_NameArchie
	msgbox OzoneInt_Text_ArchiePreDock, MSGBOX_AUTOCLOSE
	release
	end

OzoneInt_EventScript_ArchiePostDock::
	speakername OzoneInt_Text_NameArchie
	msgbox OzoneInt_Text_ArchiePostDock, MSGBOX_AUTOCLOSE
	release
	end

OzoneInt_EventScript_ArchieGatherOthers::
	speakername OzoneInt_Text_NameArchie
	msgbox OzoneInt_Text_ArchieGatherOthers, MSGBOX_AUTOCLOSE
	release
	end

OzoneInt_EventScript_Tabitha::
	lock
	faceplayer
	speakername OzoneInt_Text_NameTabitha
	msgbox OzoneInt_Text_TabithaBolterockAdvice, MSGBOX_DEFAULT
	closemessage
	setvar VAR_OZONE_ADMINS_STATE, 6
	goto_if_eq VAR_FACING, DIR_NORTH, OzoneInt_EventScript_TabithaLeaveGoAroundPlayer
	applymovement LOCALID_TABITHA, OzoneInt_Movement_TabithaLeave
	waitmovement 0
	removeobject LOCALID_TABITHA
	setflag FLAG_HIDE_TABITHA_OZONE
	release
	end

OzoneInt_Movement_TabithaLeave:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	step_end

OzoneInt_EventScript_TabithaLeaveGoAroundPlayer::
	applymovement LOCALID_TABITHA, OzoneInt_Movement_TabithaLeaveGoAroundPlayer
	waitmovement 0
	removeobject LOCALID_TABITHA
	setflag FLAG_HIDE_TABITHA_OZONE
	release
	end

OzoneInt_Movement_TabithaLeaveGoAroundPlayer:
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	step_end

OzoneInt_Text_NameMaxie:
	.string "Maxie$"

OzoneInt_Text_NameArchie:
	.string "Archie$"

OzoneInt_Text_NameTabitha:
	.string "Tabitha$"

OzoneInt_Text_DockNeedsMe:
	.string "dock needs me to show tf up$"

OzoneInt_Text_ArchiePreDock:
	.string "welcome to my house$"

OzoneInt_Text_ArchiePostDock:
	.string "never talk 2 me again$"

OzoneInt_Text_ArchieGatherOthers:
	.string "gather the other doods$"

OzoneInt_Text_CantLetYouUpstairs:
	.string "$"

OzoneInt_Text_ReadyForTheChallenge:
	.string "$"

OzoneInt_Text_GuardPostBattles:
	.string "$"

OzoneInt_Text_ThingsHaveGottenSerious:
	.string "$"

OzoneInt_Text_PrepareAdequately:
	.string "$"

OzoneInt_Text_NoGoingBack:
	.string "$"

OzoneInt_Text_TabithaBolterockAdvice:
	.string "It is nice to see you, {PLAYER}.\n"
	.string "I have been spending a lot more\l"
	.string "time here at Ozone's main\l"
	.string "facility thanks to that buffoon's\l"
	.string "fracturing of our department.\p"
	.string "I am planning a trip west to\n"
	.string "obtain some sensitive research\l"
	.string "files from a colleague of ours,\l"
	.string "Professor Cosmo, in Fallarbor Town.\p"
	.string "How many badges do you possess\n"
	.string "as of now? Four? Hmm. Your next\l"
	.string "stop should be Lavaridge, then.\p"
	.string "Perfect! That is in the same\n"
	.string "general area. I can assist you\l"
	.string "with traversing the rugged\l"
	.string "mountainous terrain ahead, if\l"
	.string "you will accompany me to\l"
	.string "Fallarbor Town.\p"
	.string "I assume that is acceptable.\n"
	.string "We shall meet up on Masonried\l"
	.string "Hike due west. Best not\l"
	.string "to dawdle, {PLAYER}.$"
