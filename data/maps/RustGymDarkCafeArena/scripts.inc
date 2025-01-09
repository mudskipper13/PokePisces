RustGymDarkCafeArena_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, RustGymDarkCafeArena_OnFrame
	.byte 0

RustGymDarkCafeArena_OnFrame:
	map_script_2 VAR_RUST_GYM_STATE, 13, RustGymDarkCafeArena_EventScript_GymBattle
	.2byte 0

RustGymDarkCafeArena_EventScript_GymBattle::
	lock
	speakername RustGymDarkCafeArena_Text_NameRoxanne
	msgbox RustGymDarkCafeArena_Text_YoureQuiteImpressive, MSGBOX_DEFAULT
	speakername RustGymDarkCafeArena_Text_NameLanette
	msgbox RustGymDarkCafeArena_Text_IWillBeJoining, MSGBOX_DEFAULT
	speakername RustGymDarkCafeArena_Text_NameRoxanne
	msgbox RustGymDarkCafeArena_Text_YourFinalExamIsNow, MSGBOX_DEFAULT
	speakername NULL
	trainerbattle_two_trainers TRAINER_P_ROXANNE, RustGymDarkCafeArena_Text_RoxanneDefeat, TRAINER_P_LANETTE, RustGymDarkCafeArena_Text_LanetteDefeat, RustGymDarkCafeArena_EventScript_LeadersDefeated, NO_MUSIC
	goto RustGymDarkCafeArena_EventScript_LeadersDefeated
	release
	end

RustGymDarkCafeArena_EventScript_LeadersDefeated::
	speakername RustGymDarkCafeArena_Text_NameRoxanne
	msgbox RustGymDarkCafeArena_Text_YouDidIt, MSGBOX_DEFAULT
	setflag FLAG_BADGE08_GET
	setflag FLAG_DEFEATED_RUSTBORO_GYM
	setvar VAR_PISCES_STORY_PROGRESS, 9
	giveitem ITEM_TM_ROADBLOCK
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	giveitem ITEM_TM_BUG_BUZZ
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	speakername NULL
	message RustGymDarkCafeArena_Text_ReceivedAmberBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	speakername RustGymDarkCafeArena_Text_NameRoxanne
	msgbox RustGymDarkCafeArena_Text_PermanentRecord, MSGBOX_DEFAULT
	speakername RustGymDarkCafeArena_Text_NameLanette
	msgbox RustGymDarkCafeArena_Text_ByeBye, MSGBOX_DEFAULT
	speakername NULL
	setvar VAR_RUST_GYM_STATE, 14
	warp MAP_RUSTBORO_NEW, 51, 36
	waitstate
	release
	end

RustGymDarkCafeArena_Text_NameRoxanne:
	.string "$"

RustGymDarkCafeArena_Text_NameLanette:
	.string "$"

RustGymDarkCafeArena_Text_YoureQuiteImpressive:
	.string "$"

RustGymDarkCafeArena_Text_IWillBeJoining:
	.string "$"

RustGymDarkCafeArena_Text_YourFinalExamIsNow:
	.string "$"

RustGymDarkCafeArena_Text_RoxanneDefeat:
	.string "$"

RustGymDarkCafeArena_Text_LanetteDefeat:
	.string "$"

RustGymDarkCafeArena_Text_YouDidIt:
	.string "$"

RustGymDarkCafeArena_Text_ReceivedAmberBadge:
	.string "{PLAYER} received the\n"
	.string "Amber Badge\l"
	.string "from Roxanne and Lanette.$"

RustGymDarkCafeArena_Text_PermanentRecord:
	.string "$"

RustGymDarkCafeArena_Text_ByeBye:
	.string "$"
