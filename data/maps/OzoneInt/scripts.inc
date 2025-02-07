OzoneInt_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, OzoneInt_OnTransition
	.byte 0

OzoneInt_OnTransition:
	setrespawn HEAL_LOCATION_OZONE_INSTITUTE
	end
