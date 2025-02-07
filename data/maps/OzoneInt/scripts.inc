.set LOCALID_DOORGUARD, 1

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

OzoneInt_Text_NameMaxie:
	.string "Maxie$"

OzoneInt_Text_NameArchie:
	.string "Archie$"

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
