RustGymPrincipalsOffice_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, RustGymPrincipalsOffice_OnFrame
	.byte 0

RustGymPrincipalsOffice_OnFrame:
	map_script_2 VAR_RUST_GYM_STATE, 10, RustGymPrincipalsOffice_EventScript_Delinquency
	.2byte 0

RustGymPrincipalsOffice_EventScript_Delinquency::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, RustGymPrincipalsOffice_Movement_WalkUpToRox
	waitmovement 0
	speakername RustGymPrincipalsOffice_Text_NameRoxanne
	msgbox RustGymPrincipalsOffice_Text_YouAreNowADelinquent, MSGBOX_DEFAULT
	closemessage
	delay 8
	setvar VAR_RUST_GYM_STATE, 11
	warp MAP_RUST_GYM_DARK_HALLWAY, 1, 2
	waitstate
	release
	end

RustGymPrincipalsOffice_Movement_WalkUpToRox:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

RustGymPrincipalsOffice_Text_NameRoxanne:
	.string "Roxanne$"

RustGymPrincipalsOffice_Text_YouAreNowADelinquent:
	.string "$"
