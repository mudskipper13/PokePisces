MuseumSanctum_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, MuseumSanctum_OnLoad
	.byte 0

MuseumSanctum_OnLoad:
	call_if_gt VAR_ORBS_QUEST_STATE, 6, MuseumSanctum_EventScript_RemoveOrb
	end

MuseumSanctum_EventScript_RemoveOrb::
	setflag FLAG_TEMP_A
	return

MuseumSanctum_EventScript_JumpIntoPainting::
	lock
	msgbox MuseumSanctum_Text_JumpIntoPainting, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MuseumSanctum_EventScript_WarpToSanctum
	release
	end

MuseumSanctum_EventScript_WarpToSanctum::
	delay 4
	playse SE_BIKE_HOP
	applymovement OBJ_EVENT_ID_PLAYER, MuseumSanctum_Movement_JumpIntoPainting
	waitmovement 0
	warp MAP_LILYCOVE_MUSEUM_NEW, 28, 10
	waitstate
	release
	end

MuseumSanctum_Movement_JumpIntoPainting:
	jump_up
	step_end

MuseumSanctum_EventScript_ObtainToxicOrb::
	lock
	msgbox MuseumSanctum_Text_ItsTheToxicOrb, MSGBOX_DEFAULT
	removeobject VAR_LAST_TALKED
	setflag FLAG_TEMP_A
	giveitem ITEM_TOXIC_ORB
	closemessage
	setvar VAR_ORBS_QUEST_STATE, 7
	delay 16
	playse SE_M_SWORDS_DANCE
	waitse
	playse SE_M_BUBBLE_BEAM2
	msgbox MuseumSanctum_Text_TheMapPointsToCosmoss, MSGBOX_AUTOCLOSE
	release
	end

MuseumSanctum_Text_JumpIntoPainting:
	.string "(Jump back through the painting?)$"

MuseumSanctum_Text_ItsTheToxicOrb:
	.string "(It's yet another orb.\n"
	.string "This happens to be the 6th one.)$"

MuseumSanctum_Text_TheMapPointsToCosmoss:
	.string "(Your magical map shines once more,\n"
	.string "pointing you to a new location.)\p"
	.string "(This time, it is leading you\n"
	.string "to the Cosmoss Space Center...)$"
