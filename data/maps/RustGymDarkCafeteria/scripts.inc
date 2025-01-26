.set LOCALID_ROXANNE, 8
.set LOCALID_DIOGENES, 7
.set LOCALID_PEON1, 2
.set LOCALID_PEON2, 1
.set LOCALID_PEON3, 6
.set LOCALID_PEON4, 5
.set LOCALID_PEON5, 4
.set LOCALID_PEON6, 3

RustGymDarkCafeteria_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, RustGymDarkCafeteria_OnLoad
	.byte 0

RustGymDarkCafeteria_OnLoad:
	call RustGymDarkCafeteria_EventScript_RemoveRoxanne
	call_if_lt VAR_RUST_GYM_STATE, 12, RustGymDarkCafeteria_EventScript_RemoveDiogenes
	end

RustGymDarkCafeteria_EventScript_RemoveRoxanne::
	removeobject LOCALID_ROXANNE
	setflag FLAG_TEMP_14
	return

RustGymDarkCafeteria_EventScript_RemoveDiogenes::
	removeobject LOCALID_DIOGENES
	setflag FLAG_TEMP_15
	return

RustGymDarkCafeteria_EventScript_StartGangWarLeft::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, RustGymDarkCafeteria_Movement_PlayerWalkRight
	waitmovement 0
	goto RustGymDarkCafeteria_EventScript_GangWar
	release
	end

RustGymDarkCafeteria_EventScript_StartGangWarRight::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, RustGymDarkCafeteria_Movement_PlayerWalkLeft
	waitmovement 0
	goto RustGymDarkCafeteria_EventScript_GangWar
	release
	end

RustGymDarkCafeteria_Movement_PlayerWalkLeft:
	walk_left
	step_end

RustGymDarkCafeteria_Movement_PlayerWalkRight:
	walk_right
	step_end

RustGymDarkCafeteria_EventScript_GangWar::
	lock
	delay 4
	applymovement OBJ_EVENT_ID_PLAYER, RustGymDarkCafeteria_Movement_PlayerGoToCenter
	waitmovement 0
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	msgbox RustGymDarkCafeteria_Text_ImTakingOver, MSGBOX_DEFAULT
	closemessage
	playmoncry SPECIES_FOONGUS, CRY_MODE_NORMAL
	waitmoncry
	applymovement LOCALID_PEON1, RustGymDarkCafeteria_Movement_Peon1GoToCenter
	applymovement LOCALID_PEON2, RustGymDarkCafeteria_Movement_Peon2GoToCenter
	applymovement LOCALID_PEON3, RustGymDarkCafeteria_Movement_Peon3GoToCenter
	applymovement LOCALID_PEON4, RustGymDarkCafeteria_Movement_Peon4GoToCenter
	applymovement LOCALID_PEON5, RustGymDarkCafeteria_Movement_Peon5GoToCenter
	applymovement LOCALID_PEON6, RustGymDarkCafeteria_Movement_Peon6GoToCenter
	waitmovement 0
	delay 32
	trainerbattle_single TRAINER_P_DIOGENES, RustGymDarkCafeteria_Text_DiogenesIntro, RustGymDarkCafeteria_Text_DiogenesDefeated, RustGymDarkCafeteria_EventScript_DiogenesDefeat
	goto RustGymDarkCafeteria_EventScript_DiogenesDefeat
	release
	end

RustGymDarkCafeteria_Movement_PlayerGoToCenter:
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

RustGymDarkCafeteria_Movement_Peon1GoToCenter:
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fast_right
	face_up
	step_end

RustGymDarkCafeteria_Movement_Peon2GoToCenter:
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_right
	step_end

RustGymDarkCafeteria_Movement_Peon3GoToCenter:
	walk_fast_left
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_right
	walk_fast_down
	walk_fast_right
	face_down
	step_end

RustGymDarkCafeteria_Movement_Peon4GoToCenter:
	jump_2_down
	step_end

RustGymDarkCafeteria_Movement_Peon5GoToCenter:
	walk_fast_left
	walk_fast_left
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_left
	step_end

RustGymDarkCafeteria_Movement_Peon6GoToCenter:
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	face_up
	step_end

RustGymDarkCafeteria_EventScript_DiogenesDefeat::
	setvar VAR_RUST_GYM_STATE, 13
	delay 8
	msgbox RustGymDarkCafeteria_Text_ThisIsntOver, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_NONE, FALSE
	clearflag FLAG_TEMP_14
	addobject LOCALID_ROXANNE
	playse SE_M_STRENGTH
	waitse
	removeobject LOCALID_DIOGENES
	setflag FLAG_TEMP_15
	setmetatile 6, 6, METATILE_RustboroGymNew_DiogenesLeft, TRUE
	setmetatile 7, 6, METATILE_RustboroGymNew_DiogenesRight, TRUE
	special DrawWholeMapView
	delay 16
	speakername RustGymDarkCafeteria_Text_NameRoxanne
	msgbox RustGymDarkCafeteria_Text_ThatsEnoughOfThat, MSGBOX_DEFAULT
	closemessage
	warp MAP_RUST_GYM_DARK_CAFE_ARENA, 6, 8
	waitstate
	release
	end

RustGymDarkCafeteria_EventScript_SpeakOutAndYouGetWhacked::
	msgbox RustGymDarkCafeteria_Text_SpeakOutAndYouGetWhacked, MSGBOX_NPC
	end

RustGymDarkCafeteria_EventScript_RoxannesBat::
	msgbox RustGymDarkCafeteria_Text_RoxannesBat, MSGBOX_NPC
	end

RustGymDarkCafeteria_EventScript_BigSisRoxanne::
	msgbox RustGymDarkCafeteria_Text_BigSisRoxanne, MSGBOX_NPC
	end

RustGymDarkCafeteria_EventScript_GangKeptInLine::
	msgbox RustGymDarkCafeteria_Text_GangKeptInLine, MSGBOX_NPC
	end

RustGymDarkCafeteria_EventScript_DiogenesMakesGoodPoints::
	msgbox RustGymDarkCafeteria_Text_DiogenesMakesGoodPoints, MSGBOX_NPC
	end

RustGymDarkCafeteria_EventScript_IllFollowWhoeverHasPower::
	msgbox RustGymDarkCafeteria_Text_IllFollowWhoeverHasPower, MSGBOX_NPC
	end

RustGymDarkCafeteria_Text_NameRoxanne:
	.string "Roxanne$"

RustGymDarkCafeteria_Text_ImTakingOver:
	.string "I've been sowing these seeds\n"
	.string "for weeks now, it's time they\l"
	.string "bore some fruit.\p"
	.string "Listen up, underlings!\n"
	.string "You are under new management!\l"
	.string "I am sick of answering to the\l"
	.string "principal and her brutish\l"
	.string "violent nature...\l"
	.string "The winds of change are blowing,\l"
	.string "and if you want to ride it,\l"
	.string "follow behind me!$"

RustGymDarkCafeteria_Text_DiogenesIntro:
	.string "Ah-hah-hah! You know, I just\n"
	.string "noticed you there, new blood.\l"
	.string "I think I will make an\l"
	.string "example out of you to show\l"
	.string "my newfound dominance.\p"
	.string "Watch and learn how a REAL\n"
	.string "leader battles, underlings!!$"

RustGymDarkCafeteria_Text_DiogenesDefeated:
	.string "Y-Y-You...!\n"
	.string "Featherless...biped...!$"

RustGymDarkCafeteria_Text_ThisIsntOver:
	.string "(Diogenes frantically eyes\n"
	.string "the crowd, who are losing faith\l"
	.string "rapidly in his supposed skills.)\p"
	.string "Stay in line, underlings!!!\n"
	.string "This is NOT over! If that\l"
	.string "blasted Roxanne thinks I will\l"
	.string "continue to grovel at her\l"
	.string "feet, she has another thing\l"
	.string "coming-$"

RustGymDarkCafeteria_Text_ThatsEnoughOfThat:
	.string "That is enough of that\n"
	.string "carnival sideshow-worthy\l"
	.string "performance.\p"
	.string "Students. I expect you all to\n"
	.string "take Diogenes to the school nurse\l"
	.string "at the earliest convenience.\l"
	.string "I will discipline him later.\p"
	.string "...{PLAYER}. Stay here.\n"
	.string "I would like a word with you.$"

RustGymDarkCafeteria_Text_SpeakOutAndYouGetWhacked:
	.string "Don't plan on speakin' out against\n"
	.string "our leader. I've seen some unlucky\l"
	.string "SOBs on the recieving end of some\l"
	.string "brutal dang beatdowns from her.\p"
	.string "I ain't tryna get clubbed,\n"
	.string "no thank you. I will\l"
	.string "'Yes Ma'am' till the cows\l"
	.string "come home.$"

RustGymDarkCafeteria_Text_RoxannesBat:
	.string "Big Sis Roxanne's bat has earned\n"
	.string "the nickname 'A Hard Place'.\p"
	.string "One of the most brutal ways she\n"
	.string "likes to punish unruly hooligans\l"
	.string "is by lining 'em up against\l"
	.string "a big rock and knockin' their knees\l"
	.string "into it with the bat.\p"
	.string "You get caught between a rock...\n"
	.string "and A Hard Place.$"

RustGymDarkCafeteria_Text_BigSisRoxanne:
	.string "I think I speak for a lotta us\n"
	.string "delinquents when I say Big Sis\l"
	.string "Roxanne has a lot of clout here.\p"
	.string "You want to be taken care of?\n"
	.string "Then you listen to what she says.$"

RustGymDarkCafeteria_Text_GangKeptInLine:
	.string "The gang of us troublemakers can\n"
	.string "be rough around the edges, sure.\l"
	.string "But hey, Big Sis knows how to keep\l"
	.string "us in line.\p"
	.string "I think the way she conducts herself\n"
	.string "exudes power and demands respect.\l"
	.string "She can make you sweat with not\l"
	.string "much effort exuded.$"

RustGymDarkCafeteria_Text_DiogenesMakesGoodPoints:
	.string "D-Don't let this make its\n"
	.string "way to Big Sister... but...\p"
	.string "Sometimes, my teacher,\n"
	.string "Diogenes? He can make some good\l"
	.string "points about how the gang\l"
	.string "should be run.\l"
	.string "Maybe he'd do good\l"
	.string "ascending the ranks.$"

RustGymDarkCafeteria_Text_IllFollowWhoeverHasPower:
	.string "To be honest, I'm not FULLY\n"
	.string "attached to Roxanne specifically.\l"
	.string "I just follow whoever's\l"
	.string "got the power.\p"
	.string "Don't go bein' a tattle tale,\n"
	.string "y'hear?$"
