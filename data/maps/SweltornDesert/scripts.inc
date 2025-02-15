.set LOCALID_MATT, 14
.set LOCALID_OZONE1, 15
.set LOCALID_OZONE2, 16
.set LOCALID_OZONE3, 17

SweltornDesert_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, SweltornDesert_OnLoad
	.byte 0

SweltornDesert_OnLoad:
	call_if_lt VAR_OZONE_ADMINS_STATE, 8, SweltornDesert_EventScript_RemoveMattAndMinions
	call_if_gt VAR_OZONE_ADMINS_STATE, 8, SweltornDesert_EventScript_RemoveMattAndMinions
	end

SweltornDesert_EventScript_RemoveMattAndMinions::
	removeobject LOCALID_MATT
	setflag FLAG_TEMP_11
	removeobject LOCALID_OZONE1
	setflag FLAG_TEMP_12
	removeobject LOCALID_OZONE2
	setflag FLAG_TEMP_13
	removeobject LOCALID_OZONE3
	setflag FLAG_TEMP_14
	return

SweltornDesert_EventScript_MattEncounterLeft1::
	lock
	playse SE_PIN
	applymovement LOCALID_MATT, SweltornDesert_Movement_MattNoticePlayerLeft
	waitmovement 0
	speakername SweltornDesert_Text_NameMatt
	msgbox SweltornDesert_Text_IsThatYou, MSGBOX_DEFAULT
	applymovement OBJ_EVENT_ID_PLAYER, SweltornDesert_Movement_PlayerMeetLeft1
	waitmovement 0
	goto SweltornDesert_EventScript_MattBattleLeft
	release
	end

SweltornDesert_Movement_MattNoticePlayerLeft:
	face_left
	emote_exclamation_mark
	step_end

SweltornDesert_Movement_PlayerMeetLeft1:
	walk_right
	walk_down
	walk_right
	walk_down
	face_right
	step_end

SweltornDesert_EventScript_MattEncounterLeft2::
	lock
	playse SE_PIN
	applymovement LOCALID_MATT, SweltornDesert_Movement_MattNoticePlayerLeft
	waitmovement 0
	speakername SweltornDesert_Text_NameMatt
	msgbox SweltornDesert_Text_IsThatYou, MSGBOX_DEFAULT
	applymovement OBJ_EVENT_ID_PLAYER, SweltornDesert_Movement_PlayerMeetLeft2
	waitmovement 0
	goto SweltornDesert_EventScript_MattBattleLeft
	release
	end

SweltornDesert_Movement_PlayerMeetLeft2:
	walk_right
	walk_down
	walk_right
	step_end

SweltornDesert_EventScript_MattEncounterLeft3::
	lock
	playse SE_PIN
	applymovement LOCALID_MATT, SweltornDesert_Movement_MattNoticePlayerLeft
	waitmovement 0
	speakername SweltornDesert_Text_NameMatt
	msgbox SweltornDesert_Text_IsThatYou, MSGBOX_DEFAULT
	applymovement OBJ_EVENT_ID_PLAYER, SweltornDesert_Movement_PlayerMeetLeft3
	waitmovement 0
	goto SweltornDesert_EventScript_MattBattleLeft
	release
	end

SweltornDesert_Movement_PlayerMeetLeft3:
	walk_right
	walk_right
	step_end

SweltornDesert_EventScript_MattEncounterLeft4::
	lock
	playse SE_PIN
	applymovement LOCALID_MATT, SweltornDesert_Movement_MattNoticePlayerLeft
	waitmovement 0
	speakername SweltornDesert_Text_NameMatt
	msgbox SweltornDesert_Text_IsThatYou, MSGBOX_DEFAULT
	applymovement OBJ_EVENT_ID_PLAYER, SweltornDesert_Movement_PlayerMeetLeft4
	waitmovement 0
	goto SweltornDesert_EventScript_MattBattleLeft
	release
	end

SweltornDesert_Movement_PlayerMeetLeft4:
	walk_right
	walk_up
	walk_right
	step_end

SweltornDesert_EventScript_MattEncounterLeft5::
	lock
	playse SE_PIN
	applymovement LOCALID_MATT, SweltornDesert_Movement_MattNoticePlayerLeft
	waitmovement 0
	speakername SweltornDesert_Text_NameMatt
	msgbox SweltornDesert_Text_IsThatYou, MSGBOX_DEFAULT
	applymovement OBJ_EVENT_ID_PLAYER, SweltornDesert_Movement_PlayerMeetLeft5
	waitmovement 0
	goto SweltornDesert_EventScript_MattBattleLeft
	release
	end

SweltornDesert_Movement_PlayerMeetLeft5:
	walk_up
	walk_right
	walk_up
	walk_right
	step_end

SweltornDesert_EventScript_MattBattleLeft::
	speakername SweltornDesert_Text_NameMatt
	msgbox SweltornDesert_Text_BeenSpelunking, MSGBOX_DEFAULT
	speakername SweltornDesert_Text_NameMatt
	msgbox SweltornDesert_Text_MattIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_P_MATT_2, SweltornDesert_Text_MattDefeated
	goto SweltornDesert_EventScript_MattPostBattleLeft
	release
	end

SweltornDesert_EventScript_MattPostBattleLeft::
	speakername SweltornDesert_Text_NameMatt
	msgbox SweltornDesert_Text_GoodBattleIllMoveMyGuys, MSGBOX_DEFAULT
	applymovement LOCALID_MATT, SweltornDesert_Movement_MattLeavesLeft
	waitmovement 0
	setvar VAR_OZONE_ADMINS_STATE, 9
	removeobject LOCALID_MATT
	setflag FLAG_TEMP_11
	removeobject LOCALID_OZONE1
	setflag FLAG_TEMP_12
	removeobject LOCALID_OZONE2
	setflag FLAG_TEMP_13
	removeobject LOCALID_OZONE3
	setflag FLAG_TEMP_14
	release
	end

SweltornDesert_Movement_MattLeavesLeft:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

SweltornDesert_EventScript_MattEncounterRight1::
	lock
	playse SE_PIN
	applymovement LOCALID_MATT, SweltornDesert_Movement_MattNoticePlayerRight
	waitmovement 0
	speakername SweltornDesert_Text_NameMatt
	msgbox SweltornDesert_Text_IsThatYou, MSGBOX_DEFAULT
	applymovement OBJ_EVENT_ID_PLAYER, SweltornDesert_Movement_PlayerMeetRight1
	waitmovement 0
	goto SweltornDesert_EventScript_MattBattleRight
	release
	end

SweltornDesert_Movement_MattNoticePlayerRight:
	face_right
	emote_exclamation_mark
	step_end

SweltornDesert_Movement_PlayerMeetRight1:
	walk_down
	walk_left
	walk_down
	walk_left
	step_end

SweltornDesert_EventScript_MattEncounterRight2::
	lock
	playse SE_PIN
	applymovement LOCALID_MATT, SweltornDesert_Movement_MattNoticePlayerRight
	waitmovement 0
	speakername SweltornDesert_Text_NameMatt
	msgbox SweltornDesert_Text_IsThatYou, MSGBOX_DEFAULT
	applymovement OBJ_EVENT_ID_PLAYER, SweltornDesert_Movement_PlayerMeetRight2
	waitmovement 0
	goto SweltornDesert_EventScript_MattBattleRight
	release
	end

SweltornDesert_Movement_PlayerMeetRight2:
	walk_left
	walk_down
	walk_left
	step_end

SweltornDesert_EventScript_MattEncounterRight3::
	lock
	playse SE_PIN
	applymovement LOCALID_MATT, SweltornDesert_Movement_MattNoticePlayerRight
	waitmovement 0
	speakername SweltornDesert_Text_NameMatt
	msgbox SweltornDesert_Text_IsThatYou, MSGBOX_DEFAULT
	applymovement OBJ_EVENT_ID_PLAYER, SweltornDesert_Movement_PlayerMeetRight3
	waitmovement 0
	goto SweltornDesert_EventScript_MattBattleRight
	release
	end

SweltornDesert_Movement_PlayerMeetRight3:
	walk_left
	walk_left
	step_end

SweltornDesert_EventScript_MattEncounterRight4::
	lock
	playse SE_PIN
	applymovement LOCALID_MATT, SweltornDesert_Movement_MattNoticePlayerRight
	waitmovement 0
	speakername SweltornDesert_Text_NameMatt
	msgbox SweltornDesert_Text_IsThatYou, MSGBOX_DEFAULT
	applymovement OBJ_EVENT_ID_PLAYER, SweltornDesert_Movement_PlayerMeetRight4
	waitmovement 0
	goto SweltornDesert_EventScript_MattBattleRight
	release
	end

SweltornDesert_Movement_PlayerMeetRight4:
	walk_left
	walk_up
	walk_left
	step_end

SweltornDesert_EventScript_MattBattleRight::
	speakername SweltornDesert_Text_NameMatt
	msgbox SweltornDesert_Text_BeenSpelunking, MSGBOX_DEFAULT
	speakername SweltornDesert_Text_NameMatt
	msgbox SweltornDesert_Text_MattIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_P_MATT_2, SweltornDesert_Text_MattDefeated
	goto SweltornDesert_EventScript_MattPostBattleRight
	release
	end

SweltornDesert_EventScript_MattPostBattleRight::
	speakername SweltornDesert_Text_NameMatt
	msgbox SweltornDesert_Text_GoodBattleIllMoveMyGuys, MSGBOX_DEFAULT
	applymovement LOCALID_MATT, SweltornDesert_Movement_MattLeavesRight
	waitmovement 0
	setvar VAR_OZONE_ADMINS_STATE, 9
	removeobject LOCALID_MATT
	setflag FLAG_TEMP_11
	removeobject LOCALID_OZONE1
	setflag FLAG_TEMP_12
	removeobject LOCALID_OZONE2
	setflag FLAG_TEMP_13
	removeobject LOCALID_OZONE3
	setflag FLAG_TEMP_14
	release
	end

SweltornDesert_Movement_MattLeavesRight:
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

SweltornDesert_EventScript_OzoneRoadblocker1::
	msgbox SweltornDesert_Text_OzoneRoadblocker1, MSGBOX_NPC
    end

SweltornDesert_EventScript_OzoneRoadblocker2::
	msgbox SweltornDesert_Text_OzoneRoadblocker2, MSGBOX_NPC
    end

SweltornDesert_EventScript_OzoneRoadblocker3::
	msgbox SweltornDesert_Text_OzoneRoadblocker3, MSGBOX_NPC
    end

SweltornDesert_EventScript_Santo::
    trainerbattle_single TRAINER_P_SANTO, SweltornDesert_Text_SantoIntro, SweltornDesert_Text_SantoDefeated
    msgbox SweltornDesert_Text_SantoPostBattle, MSGBOX_AUTOCLOSE
    end

SweltornDesert_EventScript_Dorothy::
    trainerbattle_single TRAINER_P_DOROTHY, SweltornDesert_Text_DorothyIntro, SweltornDesert_Text_DorothyDefeated
    msgbox SweltornDesert_Text_DorothyPostBattle, MSGBOX_AUTOCLOSE
    end

SweltornDesert_EventScript_Erin::
    trainerbattle_single TRAINER_P_ERIN, SweltornDesert_Text_ErinIntro, SweltornDesert_Text_ErinDefeated
    msgbox SweltornDesert_Text_ErinPostBattle, MSGBOX_AUTOCLOSE
    end

SweltornDesert_EventScript_Aaron::
    trainerbattle_single TRAINER_P_AARON, SweltornDesert_Text_AaronIntro, SweltornDesert_Text_AaronDefeated
    msgbox SweltornDesert_Text_AaronPostBattle, MSGBOX_AUTOCLOSE
    end

SweltornDesert_EventScript_Thad::
    trainerbattle_single TRAINER_P_THAD, SweltornDesert_Text_ThadIntro, SweltornDesert_Text_ThadDefeated
    msgbox SweltornDesert_Text_ThadPostBattle, MSGBOX_AUTOCLOSE
    end

SweltornDesert_EventScript_Leela::
    trainerbattle_single TRAINER_P_LEELA, SweltornDesert_Text_LeelaIntro, SweltornDesert_Text_LeelaDefeated
    msgbox SweltornDesert_Text_LeelaPostBattle, MSGBOX_AUTOCLOSE
    end

SweltornDesert_EventScript_Ickle::
    trainerbattle_single TRAINER_P_ICKLE, SweltornDesert_Text_IckleIntro, SweltornDesert_Text_IckleDefeated
    msgbox SweltornDesert_Text_IcklePostBattle, MSGBOX_AUTOCLOSE
    end

SweltornDesert_EventScript_Staph::
    trainerbattle_single TRAINER_P_STAPH, SweltornDesert_Text_StaphIntro, SweltornDesert_Text_StaphDefeated
    msgbox SweltornDesert_Text_StaphPostBattle, MSGBOX_AUTOCLOSE
    end

SweltornDesert_EventScript_Hwarang::
    trainerbattle_single TRAINER_P_HWARANG, SweltornDesert_Text_HwarangIntro, SweltornDesert_Text_HwarangDefeated
    msgbox SweltornDesert_Text_HwarangPostBattle, MSGBOX_AUTOCLOSE
    end

SweltornDesert_EventScript_Takeshi::
    trainerbattle_single TRAINER_P_TAKESHI, SweltornDesert_Text_TakeshiIntro, SweltornDesert_Text_TakeshiDefeated
    msgbox SweltornDesert_Text_TakeshiPostBattle, MSGBOX_AUTOCLOSE
    end

SweltornDesert_EventScript_Beat::
    trainerbattle_single TRAINER_P_BEAT, SweltornDesert_Text_BeatIntro, SweltornDesert_Text_BeatDefeated
    msgbox SweltornDesert_Text_BeatPostBattle, MSGBOX_AUTOCLOSE
    end

SweltornDesert_EventScript_Dotty::
    trainerbattle_single TRAINER_P_DOTTY, SweltornDesert_Text_DottyIntro, SweltornDesert_Text_DottyDefeated
    msgbox SweltornDesert_Text_DottyPostBattle, MSGBOX_AUTOCLOSE
    end

SweltornDesert_Text_SantoIntro:
	.string "Hold it kid! Sweltorn Desert is\n"
	.string "experiencing a pretty severe\l"
	.string "sandstorm right now.\p"
	.string "Do you have a pair of Go-Goggles?$"

SweltornDesert_Text_SantoDefeated:
	.string "Good, it seems you're prepared...$"

SweltornDesert_Text_SantoPostBattle:
	.string "Sandstorms around this area used to be \n"
	.string "pretty minor, but now they're out of\l"
	.string "control...\p"
	.string "...But don't worry, kid!\n"
	.string "Team Ozone will have everything\l"
	.string "under control in no time!$"

SweltornDesert_Text_DorothyIntro:
	.string "intro$"

SweltornDesert_Text_DorothyDefeated:
	.string "defeat$"

SweltornDesert_Text_DorothyPostBattle:
	.string "post$"

SweltornDesert_Text_ErinIntro:
	.string "Who do you think these big ol' bones\n"
	.string "belong to?$"

SweltornDesert_Text_ErinDefeated:
	.string "I wasn't talking about myself!$"

SweltornDesert_Text_ErinPostBattle:
	.string "I'm trying to find out what sort of \n"
	.string "colossal Pokémon these bones once \n"
	.string "were...\n"
	.string "Or maybe it wasn't a Pokémon at all...?$"

SweltornDesert_Text_AaronIntro:
	.string "intro$"

SweltornDesert_Text_AaronDefeated:
	.string "defeat$"

SweltornDesert_Text_AaronPostBattle:
	.string "post$"

SweltornDesert_Text_ThadIntro:
	.string "intro$"

SweltornDesert_Text_ThadDefeated:
	.string "defeat$"

SweltornDesert_Text_ThadPostBattle:
	.string "post$"

SweltornDesert_Text_LeelaIntro:
	.string "Is this the right address?\n"
	.string "I think I'm lost...$"

SweltornDesert_Text_LeelaDefeated:
	.string "Can you give me a five-star review,\n"
	.string "please?$"

SweltornDesert_Text_LeelaPostBattle:
	.string "Hmm, this isn't right...\n"
	.string "I'm trying to find ''Yes Town''.\p"
	.string "You don't suppose someone's punking\n"
	.string "me, do you?$"

SweltornDesert_Text_IckleIntro:
	.string "Woof.. sure is hot here.$"

SweltornDesert_Text_IckleDefeated:
	.string "Good weather for some ice cold treats.$"

SweltornDesert_Text_IcklePostBattle:
	.string "Have some dessert in the desert.$"

SweltornDesert_Text_StaphIntro:
	.string "...Eh? Trainers, out here!?$"

SweltornDesert_Text_StaphDefeated:
	.string "I specifically wanted to avoid this.$"

SweltornDesert_Text_StaphPostBattle:
	.string "Have you been drinking water?\n"
	.string "Yeah, I bet you haven't, you're sweating\l"
	.string "like a Sadsod. Take some of mine.$"

SweltornDesert_Text_HwarangIntro:
	.string "intro$"

SweltornDesert_Text_HwarangDefeated:
	.string "defeat$"

SweltornDesert_Text_HwarangPostBattle:
	.string "post$"

SweltornDesert_Text_TakeshiIntro:
	.string "Those eyes... You hold a love for battle,\n"
	.string "don't you?\p"
	.string "Very well then, show me your passion in\n"
	.string "combat!$"

SweltornDesert_Text_TakeshiDefeated:
	.string "Hmph, as to be expected!$"

SweltornDesert_Text_TakeshiPostBattle:
	.string "You are a very unique trainer.\n"
	.string "Do not squander such a gift!$"

SweltornDesert_Text_BeatIntro:
	.string "intro$"

SweltornDesert_Text_BeatDefeated:
	.string "defeat$"

SweltornDesert_Text_BeatPostBattle:
	.string "post$"

SweltornDesert_Text_DottyIntro:
	.string "intro$"

SweltornDesert_Text_DottyDefeated:
	.string "defeat$"

SweltornDesert_Text_DottyPostBattle:
	.string "post$"

SweltornDesert_Text_NameMatt:
	.string "$"

SweltornDesert_Text_IsThatYou:
	.string "$"

SweltornDesert_Text_BeenSpelunking:
	.string "$"

SweltornDesert_Text_MattIntro:
	.string "$"

SweltornDesert_Text_MattDefeated:
	.string "$"

SweltornDesert_Text_GoodBattleIllMoveMyGuys:
	.string "$"

SweltornDesert_Text_OzoneRoadblocker1:
	.string "$"

SweltornDesert_Text_OzoneRoadblocker2:
	.string "$"

SweltornDesert_Text_OzoneRoadblocker3:
	.string "$"
