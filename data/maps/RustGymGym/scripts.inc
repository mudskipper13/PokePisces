RustGymGym_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, RustGymGym_OnFrame
	.byte 0

RustGymGym_OnFrame:
	map_script_2 VAR_RUST_GYM_STATE, 8, RustGymGym_EventScript_GymBattle
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
	speakername RustGymGym_Text_NameLanette
	msgbox RustGymGym_Text_AmberBadgeDesc, MSGBOX_DEFAULT
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
	.string "Roxanne$"

RustGymGym_Text_NameLanette:
	.string "Lanette$"

RustGymGym_Text_YoureQuiteImpressive:
	.string "Not many students in the\n"
	.string "accelerated program can do\l"
	.string "so well on the exam right\l"
	.string "from the start. I commend you\l"
	.string "for your attention to detail.\p"
	.string "You know... once, I was considered\n"
	.string "the weakest gym leader.\l"
	.string "But, over time, I have risen the\l"
	.string "ranks through perserverance.\l"
	.string "That is why I favor the Rock type.\l"
	.string "It is the type of stability\l"
	.string "and resistance to the hardships\l"
	.string "of life.\p"
	.string "Can your team break through?\n"
	.string "We certainly shall see.$"

RustGymGym_Text_IWillBeJoining:
	.string "I'll be joining the principal\n"
	.string "for this battle.\l"
	.string "...To be honest, I'm not as\l"
	.string "strong as her. But it's a bit\l"
	.string "of a tradition at this point\l"
	.string "that we do these matches as a duo.$"

RustGymGym_Text_YourFinalExamIsNow:
	.string "The reason for your inclusion\n"
	.string "has always been that you are\l"
	.string "a calm and collected partner\l"
	.string "on the battlefield, Ms. Lanette.\l"
	.string "I value what you bring\l"
	.string "to the table.\p"
	.string "Frankly, {PLAYER} should\n"
	.string "perhaps be fearing the\l"
	.string "strength of our combined skills.\p"
	.string "Consider this your true\n"
	.string "final exam. Give it your all!$"

RustGymGym_Text_RoxanneDefeat:
	.string "Your foundation is solid\n"
	.string "as concrete. Quite commendable.$"

RustGymGym_Text_LanetteDefeat:
	.string "I should use your strategies\n"
	.string "as basis for my program's\l"
	.string "AI improvements...$"

RustGymGym_Text_YouDidIt:
	.string "That showed me more than enough\n"
	.string "of your rock-hard grit\l"
	.string "and determination.\p"
	.string "You have earned the right to\n"
	.string "behold... the last badge.$"

RustGymGym_Text_ReceivedAmberBadge:
	.string "{PLAYER} received the\n"
	.string "Amber Badge\l"
	.string "from Roxanne and Lanette.$"

RustGymGym_Text_AmberBadgeDesc:
	.string "The Amber Badge allows you\n"
	.string "to use the Waterfall field move\l"
	.string "outside of battle.\l"
	.string "Now that you've reached the\l"
	.string "height of the gym journey...\l"
	.string "you can reach new physical\l"
	.string "heights as well. Pretty fitting.\p"
	.string "These technical machines\n"
	.string "are for you, too.$"

RustGymGym_Text_PermanentRecord:
	.string "Your track record should proceed\n"
	.string "you from now on, {PLAYER}.\p"
	.string "I trust people will treat you\n"
	.string "with great respect now that\l"
	.string "you have proven yourself\l"
	.string "the best of the best.$"

RustGymGym_Text_ByeBye:
	.string "Take care...\n"
	.string "Oh, and if you ever want\l"
	.string "a job in tech... I think you\l"
	.string "would do well at helping me\l"
	.string "code my trainer AI.\p"
	.string "But, I digress. Let me\n"
	.string "escort you back outside.$"
