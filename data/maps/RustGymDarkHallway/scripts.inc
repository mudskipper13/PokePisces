.set LOCALID_GANGMEMBER1, 7
.set LOCALID_GANGMEMBER2, 6
.set LOCALID_GANGMEMBER3, 9
.set LOCALID_BLOCKER, 8

RustGymDarkHallway_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, RustGymDarkHallway_OnLoad
	.byte 0

RustGymDarkHallway_OnLoad:
	call_if_gt VAR_RUST_GYM_STATE, 11, RustGymDarkHallway_EventScript_RemoveBlocker
	end

RustGymDarkHallway_EventScript_RemoveBlocker::
	removeobject LOCALID_BLOCKER
	setflag FLAG_TEMP_14
	return

RustGymDarkHallway_EventScript_LunchMoney1Left::
	lock
	delay 4
	applymovement LOCALID_GANGMEMBER1, RustGymDarkHallway_Movement_LunchAttack1Left
	waitmovement 0
	call RustGymDarkHallway_EventScript_StealLunchMoney1
	applymovement OBJ_EVENT_ID_PLAYER, RustGymDarkHallway_Movement_LunchLeave1Left
	waitmovement 0
	applymovement LOCALID_GANGMEMBER1, RustGymDarkHallway_Movement_LunchReturn1Left
	waitmovement 0
	release
	end

RustGymDarkHallway_Movement_LunchAttack1Left:
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	step_end

RustGymDarkHallway_Movement_LunchLeave1Left:
	walk_left
	step_end

RustGymDarkHallway_Movement_LunchReturn1Left:
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	step_end

RustGymDarkHallway_EventScript_LunchMoney1Right::
	lock
	delay 4
	applymovement LOCALID_GANGMEMBER1, RustGymDarkHallway_Movement_LunchAttack1Right
	waitmovement 0
	call RustGymDarkHallway_EventScript_StealLunchMoney1
	applymovement OBJ_EVENT_ID_PLAYER, RustGymDarkHallway_Movement_LunchLeave1Right
	waitmovement 0
	applymovement LOCALID_GANGMEMBER1, RustGymDarkHallway_Movement_LunchReturn1Right
	waitmovement 0
	release
	end

RustGymDarkHallway_Movement_LunchAttack1Right:
	walk_fast_down
	walk_fast_down
	face_right
	step_end

RustGymDarkHallway_Movement_LunchLeave1Right:
	walk_right
	step_end

RustGymDarkHallway_Movement_LunchReturn1Right:
	walk_fast_up
	walk_fast_up
	step_end

RustGymDarkHallway_EventScript_StealLunchMoney1::
	showmoneybox 0, 0
	msgbox RustGymDarkHallway_Text_StealLunchMoney1, MSGBOX_DEFAULT
	checkmoney 2000
	goto_if_eq VAR_RESULT, FALSE, RustGymDarkHallway_EventScript_PoorLol
	playse SE_M_PAY_DAY
	removemoney 2000
	updatemoneybox
	delay 40
	hidemoneybox
	msgbox RustGymDarkHallway_Text_Loser1, MSGBOX_DEFAULT
	closemessage
	return

RustGymDarkHallway_EventScript_PoorLol::
	msgbox RustGymDarkHallway_Text_NoMoney, MSGBOX_DEFAULT
	closemessage
	delay 40
	hidemoneybox
	return

RustGymDarkHallway_EventScript_LunchMoney2North::
	lock
	delay 4
	applymovement LOCALID_GANGMEMBER2, RustGymDarkHallway_Movement_LunchAttack2North
	waitmovement 0
	call RustGymDarkHallway_EventScript_StealLunchMoney2
	applymovement OBJ_EVENT_ID_PLAYER, RustGymDarkHallway_Movement_LunchLeave2North
	waitmovement 0
	applymovement LOCALID_GANGMEMBER2, RustGymDarkHallway_Movement_LunchReturn2North
	waitmovement 0
	release
	end

RustGymDarkHallway_Movement_LunchAttack2North:
	walk_fast_up
	walk_fast_up
	step_end

RustGymDarkHallway_Movement_LunchLeave2North:
	walk_up
	step_end

RustGymDarkHallway_Movement_LunchReturn2North:
	walk_fast_down
	walk_fast_down
	face_up
	step_end

RustGymDarkHallway_EventScript_LunchMoney2East::
	lock
	delay 4
	applymovement LOCALID_GANGMEMBER2, RustGymDarkHallway_Movement_LunchAttack2East
	waitmovement 0
	call RustGymDarkHallway_EventScript_StealLunchMoney2
	applymovement OBJ_EVENT_ID_PLAYER, RustGymDarkHallway_Movement_LunchLeave2East
	waitmovement 0
	applymovement LOCALID_GANGMEMBER2, RustGymDarkHallway_Movement_LunchReturn2East
	waitmovement 0
	release
	end

RustGymDarkHallway_Movement_LunchAttack2East:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

RustGymDarkHallway_Movement_LunchLeave2East:
	walk_right
	step_end

RustGymDarkHallway_Movement_LunchReturn2East:
	walk_fast_left
	walk_fast_left
	walk_fast_left
	face_up
	step_end

RustGymDarkHallway_EventScript_LunchMoney2South::
	lock
	delay 4
	applymovement LOCALID_GANGMEMBER2, RustGymDarkHallway_Movement_LunchAttack2South
	waitmovement 0
	call RustGymDarkHallway_EventScript_StealLunchMoney2
	applymovement OBJ_EVENT_ID_PLAYER, RustGymDarkHallway_Movement_LunchLeave2South
	waitmovement 0
	applymovement LOCALID_GANGMEMBER2, RustGymDarkHallway_Movement_LunchReturn2South
	waitmovement 0
	release
	end

RustGymDarkHallway_Movement_LunchAttack2South:
	walk_fast_left
	walk_fast_left
	walk_fast_left
	face_down
	step_end

RustGymDarkHallway_Movement_LunchLeave2South:
	walk_down
	step_end

RustGymDarkHallway_Movement_LunchReturn2South:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	face_up
	step_end

RustGymDarkHallway_EventScript_LunchMoney2West::
	lock
	delay 4
	applymovement LOCALID_GANGMEMBER2, RustGymDarkHallway_Movement_LunchAttack2West
	waitmovement 0
	call RustGymDarkHallway_EventScript_StealLunchMoney2
	applymovement OBJ_EVENT_ID_PLAYER, RustGymDarkHallway_Movement_LunchLeave2West
	waitmovement 0
	applymovement LOCALID_GANGMEMBER2, RustGymDarkHallway_Movement_LunchReturn2West
	waitmovement 0
	release
	end

RustGymDarkHallway_Movement_LunchAttack2West:
	walk_fast_left
	walk_fast_left
	step_end

RustGymDarkHallway_Movement_LunchLeave2West:
	walk_left
	step_end

RustGymDarkHallway_Movement_LunchReturn2West:
	walk_fast_right
	walk_fast_right
	face_up
	step_end

RustGymDarkHallway_EventScript_StealLunchMoney2::
	showmoneybox 0, 0
	msgbox RustGymDarkHallway_Text_StealLunchMoney2, MSGBOX_DEFAULT
	checkmoney 2000
	goto_if_eq VAR_RESULT, FALSE, RustGymDarkHallway_EventScript_PoorLol
	playse SE_M_PAY_DAY
	removemoney 2000
	updatemoneybox
	delay 40
	hidemoneybox
	msgbox RustGymDarkHallway_Text_Loser2, MSGBOX_DEFAULT
	closemessage
	return

RustGymDarkHallway_EventScript_LunchMoney3North::
	lock
	delay 4
	applymovement LOCALID_GANGMEMBER3, RustGymDarkHallway_Movement_LunchAttack3North
	waitmovement 0
	call RustGymDarkHallway_EventScript_StealLunchMoney3
	applymovement OBJ_EVENT_ID_PLAYER, RustGymDarkHallway_Movement_LunchLeave3North
	waitmovement 0
	applymovement LOCALID_GANGMEMBER3, RustGymDarkHallway_Movement_LunchReturn3North
	waitmovement 0
	release
	end

RustGymDarkHallway_Movement_LunchAttack3North:
	walk_fast_left
	walk_fast_left
	walk_fast_up
	step_end

RustGymDarkHallway_Movement_LunchLeave3North:
	walk_up
	step_end

RustGymDarkHallway_Movement_LunchReturn3North:
	walk_fast_down
	walk_fast_right
	walk_fast_right
	face_down
	step_end

RustGymDarkHallway_EventScript_LunchMoney3East::
	lock
	delay 4
	applymovement LOCALID_GANGMEMBER3, RustGymDarkHallway_Movement_LunchAttack3East
	waitmovement 0
	call RustGymDarkHallway_EventScript_StealLunchMoney3
	applymovement OBJ_EVENT_ID_PLAYER, RustGymDarkHallway_Movement_LunchLeave3East
	waitmovement 0
	applymovement LOCALID_GANGMEMBER3, RustGymDarkHallway_Movement_LunchReturn3East
	waitmovement 0
	release
	end

RustGymDarkHallway_Movement_LunchAttack3East:
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

RustGymDarkHallway_Movement_LunchLeave3East:
	walk_right
	step_end

RustGymDarkHallway_Movement_LunchReturn3East:
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_up
	face_down
	step_end

RustGymDarkHallway_EventScript_LunchMoney3South::
	lock
	delay 4
	applymovement LOCALID_GANGMEMBER3, RustGymDarkHallway_Movement_LunchAttack3South
	waitmovement 0
	call RustGymDarkHallway_EventScript_StealLunchMoney3
	applymovement OBJ_EVENT_ID_PLAYER, RustGymDarkHallway_Movement_LunchLeave3South
	waitmovement 0
	applymovement LOCALID_GANGMEMBER3, RustGymDarkHallway_Movement_LunchReturn3South
	waitmovement 0
	release
	end

RustGymDarkHallway_Movement_LunchAttack3South:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	face_down
	step_end

RustGymDarkHallway_Movement_LunchLeave3South:
	walk_down
	step_end

RustGymDarkHallway_Movement_LunchReturn3South:
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	face_down
	step_end

RustGymDarkHallway_EventScript_StealLunchMoney3::
	showmoneybox 0, 0
	msgbox RustGymDarkHallway_Text_StealLunchMoney3, MSGBOX_DEFAULT
	checkmoney 2000
	goto_if_eq VAR_RESULT, FALSE, RustGymDarkHallway_EventScript_PoorLol
	playse SE_M_PAY_DAY
	removemoney 2000
	updatemoneybox
	delay 40
	hidemoneybox
	msgbox RustGymDarkHallway_Text_Loser3, MSGBOX_DEFAULT
	closemessage
	return

RustGymDarkHallway_EventScript_Goombella::
    trainerbattle_single TRAINER_P_GOOMBELLA, RustGymDarkHallway_Text_GoombellaIntro, RustGymDarkHallway_Text_GoombellaDefeated
    msgbox RustGymDarkHallway_Text_GoombellaPostBattle, MSGBOX_AUTOCLOSE
    end

RustGymDarkHallway_EventScript_Timpani::
    trainerbattle_single TRAINER_P_TIMPANI, RustGymDarkHallway_Text_TimpaniIntro, RustGymDarkHallway_Text_TimpaniDefeated
    msgbox RustGymDarkHallway_Text_TimpaniPostBattle, MSGBOX_AUTOCLOSE
    end

RustGymDarkHallway_EventScript_PlatoAndAris::
    trainerbattle_double TRAINER_P_PLATO_AND_ARIS, RustGymDarkHallway_Text_PlatoAndArisIntro, RustGymDarkHallway_Text_PlatoAndArisDefeated, RustGymDarkHallway_Text_PlatoAndArisNeedTwoMons
    msgbox RustGymDarkHallway_Text_PlatoAndArisPostBattle, MSGBOX_AUTOCLOSE
    end

RustGymDarkHallway_EventScript_WatchOutForGangGuards::
	msgbox RustGymDarkHallway_Text_WatchOutForGangGuards, MSGBOX_NPC
    end

RustGymDarkHallway_EventScript_BlockingThisHallway::
	msgbox RustGymDarkHallway_Text_BlockingThisHallway, MSGBOX_NPC
    end

RustGymDarkHallway_EventScript_PanicAboutTest::
	msgbox RustGymDarkHallway_Text_PanicAboutTest, MSGBOX_NPC
    end

RustGymDarkHallway_EventScript_IdolPhotoshoot::
	msgbox RustGymDarkHallway_Text_IdolPhotoshoot, MSGBOX_NPC
    end

RustGymDarkHallway_EventScript_SlappedATeacher::
	msgbox RustGymDarkHallway_Text_SlappedATeacher, MSGBOX_NPC
    end

RustGymDarkHallway_Text_GoombellaIntro:
	.string "According to my book, it\n"
	.string "says here...\p"
	.string "{PLAYER}: A researcher and trainer\n"
	.string "from Littleroot Town.\l"
	.string "Stubborn. Strong opponent.\p"
	.string "That it? I think I can take\n"
	.string "you, lickety-split!$"

RustGymDarkHallway_Text_GoombellaDefeated:
	.string "Crud! I got bonked!$"

RustGymDarkHallway_Text_GoombellaPostBattle:
	.string "I'm actually a transfer from\n"
	.string "the University of Goom.\p"
	.string "Goooooo Goombas!$"

RustGymDarkHallway_Text_TimpaniIntro:
	.string "I've identified...\n"
	.string "a weak-willed person.\p"
	.string "It should be easy enough to\n"
	.string "take them down and move on...$"

RustGymDarkHallway_Text_TimpaniDefeated:
	.string "...A bad outcome.$"

RustGymDarkHallway_Text_TimpaniPostBattle:
	.string "I have been to dimensions...\n"
	.string "you could not possibly comprehend.\p"
	.string "A single loss like this is...\n"
	.string "simply another step in my long road.$"

RustGymDarkHallway_Text_PlatoAndArisIntro:
	.string "Aris keeps claiming I have\n"
	.string "a 'broad forehead'.\l"
	.string "Say it ain't so?$"

RustGymDarkHallway_Text_PlatoAndArisDefeated:
	.string "Your reason, your spirit,\n"
	.string "your appetite...\l"
	.string "Simply tremendous!$"

RustGymDarkHallway_Text_PlatoAndArisPostBattle:
	.string "We are keeping ourselves busy\n"
	.string "pondering what reality\l"
	.string "is composed of.\p"
	.string "Yes, that has led to us not\n"
	.string "studying for tests.$"

RustGymDarkHallway_Text_PlatoAndArisNeedTwoMons:
	.string "You possess but one Pokemon\n"
	.string "soul on your person.\p"
	.string "Two are needed to challenge us!$"

RustGymDarkHallway_Text_StealLunchMoney1:
	.string "Hey, locker stuffing.\p"
	.string "I get the feelin' that you're\n"
	.string "one of the pansy ones around here.\l"
	.string "Know what that means?\p"
	.string "Fork up summa that cash.$"

RustGymDarkHallway_Text_Loser1:
	.string "And stay out of my area.\n"
	.string "I'm tryna read here, and your\l"
	.string "plink-plonkin' goody-two-shoe\l"
	.string "steps are distractin'.$"

RustGymDarkHallway_Text_NoMoney:
	.string "No greenbacks? At ALL?\p"
	.string "Wow. You're a hell of a joke.\p"
	.string "Get outta here.$"

RustGymDarkHallway_Text_StealLunchMoney2:
	.string "Nuh-uh. Nope. I ain't\n"
	.string "lettin' someone I ain't recognize\l"
	.string "past this point.\p"
	.string "Matter of fact, slip me some\n"
	.string "of the money you got. That way,\l"
	.string "I ain't gonna rat you out\l"
	.string "to someone who's a lot less\l"
	.string "nice than me.$"

RustGymDarkHallway_Text_Loser2:
	.string "Now get to steppin'.\n"
	.string "This is a no-trespassing zone!$"

RustGymDarkHallway_Text_StealLunchMoney3:
	.string "Ugh. ANOTHER lamer.\p"
	.string "(She simply holds out her\n"
	.string "palm to receive your lunch money.)$"

RustGymDarkHallway_Text_Loser3:
	.string "Book it.$"

RustGymDarkHallway_Text_WatchOutForGangGuards:
	.string "Oh, a new face!\n"
	.string "Well, this is the\l"
	.string "delinquency program home base.\p"
	.string "Like, I'm pretty nice, but most\n"
	.string "of my friends aren't so kind\l"
	.string "to the newbies.\p"
	.string "Try not to step into anybody's\n"
	.string "turf. You could get your\l"
	.string "money taken from ya.\p"
	.string "Now, with all that said...\p"
	.string "Gimme your lunch money!\p"
	.string "Hah! Just joshin'. But I had\n"
	.string "you sweatin' there, huh?$"

RustGymDarkHallway_Text_BlockingThisHallway:
	.string "I'm under strict orders to\n"
	.string "block this hallway like a\l"
	.string "brick wall.\p"
	.string "(His nametag says\n"
	.string "Rick Wall.)$"

RustGymDarkHallway_Text_PanicAboutTest:
	.string "Grrrggh! I can't stop going\n"
	.string "over what I got wrong on that\l"
	.string "blasted test...!\p"
	.string "I swear, I don't belong here!\n"
	.string "Take me back! Gahhhhh!$"

RustGymDarkHallway_Text_IdolPhotoshoot:
	.string "Ey. Whatcha in for?\p"
	.string "Me... I got the teachers in a tizzy\n"
	.string "when I took over a classroom for\l"
	.string "a glamour photoshoot.\p"
	.string "I didn't get permission from\n"
	.string "anybody! Even the magazine it\l"
	.string "was supposed to feature in.\l"
	.string "I figure it wouldn't be too hard.\p"
	.string "But now I'm here.\n"
	.string "Glamourless.$"

RustGymDarkHallway_Text_SlappedATeacher:
	.string "How was I supposed to know\n"
	.string "that slapping the teacher across\l"
	.string "the face would land me here?$"
