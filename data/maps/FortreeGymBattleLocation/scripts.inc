.set LOCALID_WINONA, 1
.set LOCALID_AARUNE, 2

FortreeGymBattleLocation_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, FortreeGymBattleLocation_OnFrame
	.byte 0

FortreeGymBattleLocation_OnFrame:
	map_script_2 VAR_TEMP_7, 0, FortreeGymBattleLocation_EventScript_GymBattle
	.2byte 0

FortreeGymBattleLocation_EventScript_GymBattle::
	lock
	speakername FortreeGymBattleLocation_Text_NameWinona
	msgbox FortreeGymBattleLocation_Text_NiceHops, MSGBOX_DEFAULT
	speakername FortreeGymBattleLocation_Text_NameAarune
	msgbox FortreeGymBattleLocation_Text_TimeToBattle, MSGBOX_DEFAULT
	speakername FortreeGymBattleLocation_Text_NameWinona
	msgbox FortreeGymBattleLocation_Text_OhThatsTheChallenger, MSGBOX_DEFAULT
	speakername NULL
	trainerbattle_two_trainers TRAINER_P_WINONA, FortreeGymBattleLocation_Text_WinonaDefeat, TRAINER_P_AARUNE, FortreeGymBattleLocation_Text_AaruneDefeat, FortreeGymBattleLocation_EventScript_LeadersDefeated, NO_MUSIC
	goto FortreeGymBattleLocation_EventScript_LeadersDefeated
	release
	end

FortreeGymBattleLocation_EventScript_LeadersDefeated::
	speakername FortreeGymBattleLocation_Text_NameWinona
	msgbox FortreeGymBattleLocation_Text_YouDidIt, MSGBOX_DEFAULT
	setflag FLAG_BADGE04_GET
	setflag FLAG_DEFEATED_FORTREE_GYM
	setvar VAR_PISCES_STORY_PROGRESS, 5
	giveitem ITEM_TM_ACROBATICS
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	giveitem ITEM_TM_EARTH_POWER
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	speakername NULL
	message FortreeGymBattleLocation_Text_ReceivedHorizonBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	speakername FortreeGymBattleLocation_Text_NameAarune
	msgbox FortreeGymBattleLocation_Text_ByeBye, MSGBOX_DEFAULT
	speakername NULL
	setvar VAR_TEMP_7, 1
	warp MAP_FORTREE_GYM_NEW, 44, 27
	waitstate
	release
	end	

FortreeGymBattleLocation_Text_NameWinona:
	.string "Winona$"

FortreeGymBattleLocation_Text_NameAarune:
	.string "Aarune$"

FortreeGymBattleLocation_Text_WinonaDefeat:
	.string "The northwinds blew in your\n"
	.string "favor today, {PLAYER}...$"

FortreeGymBattleLocation_Text_AaruneDefeat:
	.string "That went south for us\n"
	.string "faster'n birds migrating!$"

FortreeGymBattleLocation_Text_NiceHops:
	.string "See... I told you...\p"
	.string "Sometimes you have to trust\n"
	.string "that things will be okay...$"

FortreeGymBattleLocation_Text_TimeToBattle:
	.string "(Aarune whistled a\n"
	.string "triumphant tune.)\p"
	.string "I was watching your mountain trek\n"
	.string "from down here! Golly-gee, it\l"
	.string "almost made me wanna claw on up\l"
	.string "there beside you!\p"
	.string "You ready for the big league bout,\n"
	.string "little buddy?$"

FortreeGymBattleLocation_Text_OhThatsTheChallenger:
	.string "Oh. That's... the challenger.\n"
	.string "For some reason...\l"
	.string "the wires didn't cross for me...\p"
	.string "Alright... let's take another\n"
	.string "leap into the unknown...$"

FortreeGymBattleLocation_Text_YouDidIt:
	.string "Another gracious landing\n"
	.string "from you... I may have a thing\l"
	.string "or two to learn here...\p"
	.string "...Take these items with you\n"
	.string "on your future travels...$"

FortreeGymBattleLocation_Text_ReceivedHorizonBadge:
	.string "{PLAYER} received the\n"
	.string "Horizon Badge\l"
	.string "from Winona and Aarune.$"

FortreeGymBattleLocation_Text_ByeBye:
	.string "That's four badges, little buddy!\n"
	.string "Your adventure's already\l"
	.string "halfway through! Still lots of\l"
	.string "places to see and people to meet!\p"
	.string "To help you visit those places\n"
	.string "you've already been, the Horizon\l"
	.string "Badge lets you use the Fly\l"
	.string "field move out of battle!\l"
	.string "Hop on one of your pals and\l"
	.string "you can jet back to any city\l"
	.string "you've set foot in before.\p"
	.string "Maybe use it to come back here\n"
	.string "and pay your big bud a visit, huh?\l"
	.string "Hmm-hmm-hmm!\p"
	.string "Go kill it some more out there\n"
	.string "for us! Good luck!$"
