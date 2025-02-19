.set LOCALID_LUNASTER, 1

FallarborSteepleInterior_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, FallarborSteepleInterior_OnLoad
	.byte 0

FallarborSteepleInterior_OnLoad:
	call_if_gt VAR_ORBS_QUEST_STATE, 4, FallarborSteepleInterior_EventScript_RemoveLunaster
	end

FallarborSteepleInterior_EventScript_RemoveLunaster::
	removeobject LOCALID_LUNASTER
	setflag FLAG_TEMP_11
	return

FallarborSteepleInterior_EventScript_Lunaster::
	lock
	faceplayer
	msgbox FallarborSteepleInterior_Text_HeySlick, MSGBOX_DEFAULT
	setwildbattle SPECIES_LUNASTER, 38
	settotemboost B_POSITION_OPPONENT_LEFT, 2, 0, 1, 2
	setflag FLAG_WILD_NO_CATCHING_FLAG
	setflag FLAG_WILD_NO_RUNNING_FLAG
	setflag FLAG_SMART_WILD_AI_FLAG
	delay 4
	dowildbattle
	delay 8
	clearflag FLAG_WILD_NO_CATCHING_FLAG
	clearflag FLAG_WILD_NO_RUNNING_FLAG
	clearflag FLAG_SMART_WILD_AI_FLAG
	removeobject LOCALID_LUNASTER
	setflag FLAG_TEMP_11
	msgbox FallarborSteepleInterior_Text_LunasterWasHoldingOrb, MSGBOX_DEFAULT
	giveitem ITEM_PANIC_ORB
	closemessage
	setvar VAR_ORBS_QUEST_STATE, 5
	delay 16
	playse SE_M_SWORDS_DANCE
	waitse
	playse SE_M_BUBBLE_BEAM2
	msgbox FallarborSteepleInterior_Text_TheMapPointsToFlotshore, MSGBOX_AUTOCLOSE
	release
	end

FallarborSteepleInterior_Text_HeySlick:
	.string "(It's some sort of odd clown.)\p"
	.string "Hey, slick! Disturbing my me time?\n"
	.string "Phooey! And here I thought I'd be\l"
	.string "able to turn 'em all into swine!\l"
	.string "Stupid, weak little Saintisow\l"
	.string "for me to destroy!\p"
	.string "I'll beat you up somethin' fierce,\n"
	.string "Slick! Then you'll be joinin'\l"
	.string "the ranks of the hogs!\p"
	.string "(This isn't a person...!\n"
	.string "It's a Pokemon!)$"

FallarborSteepleInterior_Text_LunasterWasHoldingOrb:
	.string "(That Lunaster seemed to have\n"
	.string "been using this to turn\l"
	.string "townspeople into Saintisow...)$"

FallarborSteepleInterior_Text_TheMapPointsToFlotshore:
	.string "(Your magical map shines once more,\n"
	.string "pointing you to a new location.)\p"
	.string "(This time, it is leading you\n"
	.string "to a sea cave in Flotshore Trail...)$"
