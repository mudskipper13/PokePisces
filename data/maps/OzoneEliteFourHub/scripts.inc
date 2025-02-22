OzoneEliteFourHub_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, OzoneEliteFourHub_OnFrame
	.byte 0

OzoneEliteFourHub_OnFrame:
	map_script_2 VAR_TEMP_4, 0, OzoneEliteFourHub_EventScript_LockDoors
	.2byte 0

OzoneEliteFourHub_EventScript_LockDoors::
	lock
	playse SE_UNLOCK
	waitse
	setvar VAR_TEMP_4, 1
	call_if_set FLAG_FINAL_OZONE_BEAT_TABITHA, OzoneEliteFourHub_EventScript_LockTabithaDoor
	call_if_set FLAG_FINAL_OZONE_BEAT_MATT, OzoneEliteFourHub_EventScript_LockMattDoor
	call_if_set FLAG_FINAL_OZONE_BEAT_COURTNEY, OzoneEliteFourHub_EventScript_LockCourtneyDoor
	call_if_set FLAG_FINAL_OZONE_BEAT_SHELLY, OzoneEliteFourHub_EventScript_LockShellyDoor
	call_if_lt VAR_TEMP_5, 4, OzoneEliteFourHub_EventScript_LockFinalDoor
	special DrawWholeMapView
	release
	end

OzoneEliteFourHub_EventScript_LockFinalDoor::
	setmetatile 12, 0, METATILE_OzoneInterior_OzoneClosedDoor1, TRUE
	setmetatile 13, 0, METATILE_OzoneInterior_OzoneClosedDoor2, TRUE
	setmetatile 14, 0, METATILE_OzoneInterior_OzoneClosedDoor3, TRUE
	setmetatile 12, 1, METATILE_OzoneInterior_OzoneClosedDoor4, TRUE
	setmetatile 13, 1, METATILE_OzoneInterior_OzoneClosedDoor5, TRUE
	setmetatile 14, 1, METATILE_OzoneInterior_OzoneClosedDoor6, TRUE
	return

OzoneEliteFourHub_EventScript_LockTabithaDoor::
	setmetatile 18, 4, METATILE_OzoneInterior_OzoneClosedDoor1, TRUE
	setmetatile 19, 4, METATILE_OzoneInterior_OzoneClosedDoor2, TRUE
	setmetatile 20, 4, METATILE_OzoneInterior_OzoneClosedDoor3, TRUE
	setmetatile 18, 5, METATILE_OzoneInterior_OzoneClosedDoor4, TRUE
	setmetatile 19, 5, METATILE_OzoneInterior_OzoneClosedDoor5, TRUE
	setmetatile 20, 5, METATILE_OzoneInterior_OzoneClosedDoor6, TRUE
	addvar VAR_TEMP_5, 1
	return

OzoneEliteFourHub_EventScript_LockMattDoor::
	setmetatile 6, 4, METATILE_OzoneInterior_OzoneClosedDoor1, TRUE
	setmetatile 7, 4, METATILE_OzoneInterior_OzoneClosedDoor2, TRUE
	setmetatile 8, 4, METATILE_OzoneInterior_OzoneClosedDoor3, TRUE
	setmetatile 6, 5, METATILE_OzoneInterior_OzoneClosedDoor4, TRUE
	setmetatile 7, 5, METATILE_OzoneInterior_OzoneClosedDoor5, TRUE
	setmetatile 8, 5, METATILE_OzoneInterior_OzoneClosedDoor6, TRUE
	addvar VAR_TEMP_5, 1
	return

OzoneEliteFourHub_EventScript_LockCourtneyDoor::
	setmetatile 1, 4, METATILE_OzoneInterior_OzoneClosedDoor1, TRUE
	setmetatile 2, 4, METATILE_OzoneInterior_OzoneClosedDoor2, TRUE
	setmetatile 3, 4, METATILE_OzoneInterior_OzoneClosedDoor3, TRUE
	setmetatile 1, 5, METATILE_OzoneInterior_OzoneClosedDoor4, TRUE
	setmetatile 2, 5, METATILE_OzoneInterior_OzoneClosedDoor5, TRUE
	setmetatile 3, 5, METATILE_OzoneInterior_OzoneClosedDoor6, TRUE
	addvar VAR_TEMP_5, 1
	return

OzoneEliteFourHub_EventScript_LockShellyDoor::
	setmetatile 23, 4, METATILE_OzoneInterior_OzoneClosedDoor1, TRUE
	setmetatile 24, 4, METATILE_OzoneInterior_OzoneClosedDoor2, TRUE
	setmetatile 25, 4, METATILE_OzoneInterior_OzoneClosedDoor3, TRUE
	setmetatile 23, 5, METATILE_OzoneInterior_OzoneClosedDoor4, TRUE
	setmetatile 24, 5, METATILE_OzoneInterior_OzoneClosedDoor5, TRUE
	setmetatile 25, 5, METATILE_OzoneInterior_OzoneClosedDoor6, TRUE
	addvar VAR_TEMP_5, 1
	return
