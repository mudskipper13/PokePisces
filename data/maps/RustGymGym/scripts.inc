RustGymGym_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, RustGymGym_OnFrame
	.byte 0

RustGymGym_OnFrame:
	map_script_2 VAR_RUST_GYM_STATE, 13, RustGymGym_EventScript_GymBattle
	.2byte 0

RustGymGym_EventScript_GymBattle::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, RustGymGym_EventScript_WalkToCenter
	waitmovement 0
	speakername RustGymGym_Text_NameRoxanne
	msgbox RustGymGym_Text_YoureQuiteImpressive, MSGBOX_DEFAULT
	speakername RustGymGym_Text_NameLanette
	msgbox RustGymGym_Text_IWillBeJoining, MSGBOX_DEFAULT
	speakername RustGymGym_Text_NameRoxanne
	msgbox RustGymGym_Text_YourFinalExamIsNow, MSGBOX_DEFAULT
	speakername NULL
	trainerbattle_two_trainers TRAINER_P_ROXANNE, RustGymGym_Text_RoxanneDefeat, TRAINER_P_LANETTE, RustGymGym_Text_LanetteDefeat, RustGymGym_EventScript_LeadersDefeated, NO_MUSIC
	goto RustGymGym_EventScript_LeadersDefeated
	release
	end

RustGymGym_EventScript_LeadersDefeated::
	speakername RustGymGym_Text_NameRoxanne
	msgbox RustGymGym_Text_YouDidIt, MSGBOX_DEFAULT
	setflag FLAG_BADGE08_GET
	setflag FLAG_DEFEATED_RUSTBORO_GYM
	setvar VAR_PISCES_STORY_PROGRESS, 9
	giveitem ITEM_TM_ROADBLOCK
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	giveitem ITEM_TM_BUG_BUZZ
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	speakername NULL
	message RustGymGym_Text_ReceivedAmberBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	speakername RustGymGym_Text_NameRoxanne
	msgbox RustGymGym_Text_PermanentRecord, MSGBOX_DEFAULT
	speakername RustGymGym_Text_NameLanette
	msgbox RustGymGym_Text_ByeBye, MSGBOX_DEFAULT
	speakername NULL
	setvar VAR_RUST_GYM_STATE, 14
	warp MAP_RUSTBORO_NEW, 51, 36
	waitstate
	release
	end

RustGymGym_EventScript_WalkToCenter:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	face_right
	step_end

RustGymGym_Text_NameRoxanne:
	.string "$"

RustGymGym_Text_NameLanette:
	.string "$"

RustGymGym_Text_YoureQuiteImpressive:
	.string "$"

RustGymGym_Text_IWillBeJoining:
	.string "$"

RustGymGym_Text_YourFinalExamIsNow:
	.string "$"

RustGymGym_Text_RoxanneDefeat:
	.string "$"

RustGymGym_Text_LanetteDefeat:
	.string "$"

RustGymGym_Text_YouDidIt:
	.string "$"

RustGymGym_Text_ReceivedAmberBadge:
	.string "{PLAYER} received the\n"
	.string "Amber Badge\l"
	.string "from Roxanne and Lanette.$"

RustGymGym_Text_PermanentRecord:
	.string "$"

RustGymGym_Text_ByeBye:
	.string "$"
