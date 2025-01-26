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
	speakername RustGymDarkCafeArena_Text_NameLanette
	msgbox RustGymDarkCafeArena_Text_AmberBadgeDesc, MSGBOX_DEFAULT
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
	.string "Roxanne$"

RustGymDarkCafeArena_Text_NameLanette:
	.string "Lanette$"

RustGymDarkCafeArena_Text_YoureQuiteImpressive:
	.string "I must tell you that I am\n"
	.string "grateful that you put Diogenes\l"
	.string "in his place.\p"
	.string "I had not seen you battle prior\n"
	.string "to then; had I seen your\l"
	.string "prowess before, mayhaps I'd\l"
	.string "have sought some alternative\l"
	.string "to sending you down the path\l"
	.string "of delinquency.\p"
	.string "Though, in a way, it is humbling,\n"
	.string "is it not?\p"
	.string "Enough of the preamble. I find it\n"
	.string "fit to skip your remedial exams\l"
	.string "and jump right into your\l"
	.string "gym battle.$"

RustGymDarkCafeArena_Text_IWillBeJoining:
	.string "I will be joining the...\n"
	.string "festivities, or so to speak.\p"
	.string "Roxanne never does gym bouts\n"
	.string "without me at her side. I'm\l"
	.string "flattered that she thinks\l"
	.string "highly of me... but I do think\l"
	.string "she wants to moreso handicap\l"
	.string "herself, hahaha...$"

RustGymDarkCafeArena_Text_YourFinalExamIsNow:
	.string "You're simply filling your role,\n"
	.string "Ms. Lanette. And quite\l"
	.string "masterfully, at that.\p"
	.string "Consider this your final exam.\n"
	.string "Show us everything you've got,\l"
	.string "and then some!$"

RustGymDarkCafeArena_Text_RoxanneDefeat:
	.string "Your foundation is solid\n"
	.string "as concrete. Quite commendable.$"

RustGymDarkCafeArena_Text_LanetteDefeat:
	.string "I should use your strategies\n"
	.string "as basis for my program's\l"
	.string "AI improvements...$"

RustGymDarkCafeArena_Text_YouDidIt:
	.string "That showed me more than enough\n"
	.string "of your rock-hard grit\l"
	.string "and determination.\p"
	.string "You have earned the right to\n"
	.string "behold... the last badge.$"

RustGymDarkCafeArena_Text_ReceivedAmberBadge:
	.string "{PLAYER} received the\n"
	.string "Amber Badge\l"
	.string "from Roxanne and Lanette.$"

RustGymDarkCafeArena_Text_AmberBadgeDesc:
	.string "The Amber Badge allows you\n"
	.string "to use the Waterfall field move\l"
	.string "outside of battle.\l"
	.string "Now that you've reached the\l"
	.string "height of the gym journey...\l"
	.string "you can reach new physical\l"
	.string "heights as well. Pretty fitting.\p"
	.string "These technical machines\n"
	.string "are for you, too.$"

RustGymDarkCafeArena_Text_PermanentRecord:
	.string "I am feeling generous this evening,\n"
	.string "so I am striking your delinquency\l"
	.string "from your permanent record.\l"
	.string "Just this once.\p"
	.string "You will take care not to misbehave\n"
	.string "in my presence in the future.\l"
	.string "Understood? Good.$"

RustGymDarkCafeArena_Text_ByeBye:
	.string "I'll escort you back out to\n"
	.string "the city, {PLAYER}...\p"
	.string "And, if you ever get a chance...\n"
	.string "I'd like you to email me.\l"
	.string "I really could use the help\l"
	.string "coding my trainer AI...$"
