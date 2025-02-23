.set LOCALID_DADDY_BIGBUCKS, 5

BattleStudioCages_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, BattleStudioCages_OnLoad
	.byte 0

BattleStudioCages_OnLoad:
	call BattleStudioCages_EventScript_RemoveDaddyB
	end

BattleStudioCages_EventScript_RemoveDaddyB::
	removeobject LOCALID_DADDY_BIGBUCKS
	setflag FLAG_TEMP_11
	return

BattleStudioCages_EventScript_DBTriggerLeft::
	lock
	delay 4
	applymovement OBJ_EVENT_ID_PLAYER, BattleStudioCages_Movement_DBTriggerLeft
	waitmovement 0
	goto BattleStudioCages_EventScript_CapturedFighters
	release
	end

BattleStudioCages_Movement_DBTriggerLeft:
	walk_up
	walk_up
	walk_left
	walk_left
	walk_up
	step_end

BattleStudioCages_EventScript_DBTriggerRight::
	lock
	delay 4
	applymovement OBJ_EVENT_ID_PLAYER, BattleStudioCages_Movement_DBTriggerRight
	waitmovement 0
	goto BattleStudioCages_EventScript_CapturedFighters
	release
	end

BattleStudioCages_Movement_DBTriggerRight:
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

BattleStudioCages_EventScript_CapturedFighters::
	msgbox BattleStudioCages_Text_CapturedFighters, MSGBOX_DEFAULT
	closemessage
	playse SE_EXIT
	clearflag FLAG_TEMP_11
	addobject LOCALID_DADDY_BIGBUCKS
	delay 8
	applymovement LOCALID_DADDY_BIGBUCKS, BattleStudioCages_Movement_DBApproach
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	msgbox BattleStudioCages_Text_WhatHaveWeHere, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_P_DADDY_BIGBUCKS, BattleStudioCages_Text_BigbucksDefeated
	goto BattleStudioCages_EventScript_BigbucksRunAway
	release
	end

BattleStudioCages_Movement_DBApproach:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

BattleStudioCages_EventScript_BigbucksRunAway::
	msgbox BattleStudioCages_Text_WhoYouMessedWith, MSGBOX_DEFAULT
	applymovement LOCALID_DADDY_BIGBUCKS, BattleStudioCages_Movement_DBRun
	waitmovement 0
	msgbox BattleStudioCages_Text_HeDroppedTheOrb, MSGBOX_DEFAULT
	giveitem ITEM_FLAME_ORB
	closemessage
	setvar VAR_ORBS_QUEST_STATE, 4
	delay 16
	playse SE_M_SWORDS_DANCE
	waitse
	playse SE_M_BUBBLE_BEAM2
	msgbox BattleStudioCages_Text_TheMapPointsToFallarbor, MSGBOX_DEFAULT
	closemessage
	warp MAP_BATTLE_STUDIO_LOBBY, 3, 3
	waitstate
	release
	end

BattleStudioCages_Movement_DBRun:
	walk_down
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

BattleStudioCages_Text_CapturedFighters:
	.string "(!)\p"
	.string "(It's a prison filled with...\n"
	.string "trainers...?)\p"
	.string "(...They seem transfixed.\n"
	.string "Unresponsive.)$"

BattleStudioCages_Text_WhatHaveWeHere:
	.string "Now, we can't have a rat like you\n"
	.string "poking your head around places\l"
	.string "you shouldn't be.\p"
	.string "Haven't met me before? I am THE\n"
	.string "Daddy Bigbucks, the owner\l"
	.string "of the Battle Studio,\l"
	.string "and the richest man in Lilycove!\p"
	.string "I know a way or two to make people\n"
	.string "disappear, y'hear? And you, my\l"
	.string "little rat, are on that list!$"

BattleStudioCages_Text_BigbucksDefeated:
	.string "Oi! You've crossed me twofold!$"

BattleStudioCages_Text_WhoYouMessedWith:
	.string "You don't know the lion's den\n"
	.string "that you've just disturbed, kiddo.\p"
	.string "Better have eyes in the back\n"
	.string "of your head. Nobody crosses\l"
	.string "Daddy B and gets away with it!\p"
	.string "Nobody!$"

BattleStudioCages_Text_HeDroppedTheOrb:
	.string "(On his way out, Bigbucks dropped\n"
	.string "exactly what you were looking for.)$"

BattleStudioCages_Text_TheMapPointsToFallarbor:
	.string "(Your magical map shines once more,\n"
	.string "pointing you to a new location.)\p"
	.string "(This time, it is leading you\n"
	.string "to a house in northern Fallarbor...)$"
