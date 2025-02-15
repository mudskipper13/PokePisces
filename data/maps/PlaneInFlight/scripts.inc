PlaneInFlight_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PlaneInFlight_OnFrame
	.byte 0

PlaneInFlight_OnFrame:
	map_script_2 VAR_TEMP_4, 0, PlaneInFlight_EventScript_FlightTime
	.2byte 0

PlaneInFlight_EventScript_FlightTime::
	lock
	delay 32
	speakername PlaneInFlight_Text_NameArchie
	msgbox PlaneInFlight_Text_BeenAWhileSinceWeFlied, MSGBOX_DEFAULT
	speakername PlaneInFlight_Text_NameMaxie
	msgbox PlaneInFlight_Text_NeverThoughtWedBeFriends, MSGBOX_DEFAULT
	speakername PlaneInFlight_Text_NameArchie
	msgbox PlaneInFlight_Text_ICanSeeTheGoldCoast, MSGBOX_DEFAULT
	speakername PlaneInFlight_Text_NameMaxie
	msgbox PlaneInFlight_Text_PrepareToLand, MSGBOX_DEFAULT
	warp MAP_EVER_GRANDE_REST_AREA, 6, 10
	waitstate
	release
	end

PlaneInFlight_Text_NameArchie:
	.string "Archie$"

PlaneInFlight_Text_NameMaxie:
	.string "Maxie$"

PlaneInFlight_Text_BeenAWhileSinceWeFlied:
	.string "$"

PlaneInFlight_Text_NeverThoughtWedBeFriends:
	.string "$"

PlaneInFlight_Text_ICanSeeTheGoldCoast:
	.string "$"

PlaneInFlight_Text_PrepareToLand:
	.string "$"
