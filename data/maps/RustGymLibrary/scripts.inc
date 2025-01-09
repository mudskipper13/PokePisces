.set LOCALID_LANETTE, 1

RustGymLibrary_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, RustGymLibrary_OnFrame
	.byte 0

RustGymLibrary_OnFrame:
	map_script_2 VAR_RUST_GYM_STATE, 6, RustGymLibrary_EventScript_ShouldStudy
	.2byte 0

RustGymLibrary_EventScript_ShouldStudy::
	lock
	setvar VAR_RUST_GYM_STATE, 7
	msgbox RustGymLibrary_Text_ShouldStudy, MSGBOX_AUTOCLOSE
	release
	end

RustGymLibrary_Text_ShouldStudy:
	.string "$"
