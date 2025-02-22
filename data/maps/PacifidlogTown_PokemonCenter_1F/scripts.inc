.set LOCALID_NURSE, 1

PacifidlogTown_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PacifidlogTown_PokemonCenter_1F_OnTransition
	.byte 0

PacifidlogTown_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_PACIFIDLOG_TOWN
	end

PacifidlogTown_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

PacifidlogTown_PokemonCenter_1F_EventScript_Girl::
	msgbox PacifidlogTown_PokemonCenter_1F_Text_WhatColorTrainerCard, MSGBOX_NPC
	end

PacifidlogTown_PokemonCenter_1F_EventScript_Woman::
	msgbox PacifidlogTown_PokemonCenter_1F_Text_OnColonyOfCorsola, MSGBOX_NPC
	end

PacifidlogTown_PokemonCenter_1F_EventScript_OldMan::
	msgbox PacifidlogTown_PokemonCenter_1F_Text_AncestorsLivedOnBoats, MSGBOX_NPC
	end

PacifidlogTown_EventScript_BlackSheepWoman::
	msgbox PacifidlogTown_Text_BlackSheepWoman, MSGBOX_NPC
	end

PacifidlogTown_EventScript_BoredKidsWoman::
	msgbox PacifidlogTown_Text_BoredKidsWoman, MSGBOX_NPC
	end

PacifidlogTown_EventScript_VisitSadFisher::
	msgbox PacifidlogTown_Text_VisitSadFisher, MSGBOX_NPC
	end

PacifidlogTown_Text_BlackSheepWoman:
	.string "Pacifidlog Town definitely used\n"
	.string "to be the black sheep of Hoenn's\l"
	.string "settlements.\p"
	.string "I've seen the community really\n"
	.string "blossom here as of late. They've\l"
	.string "earned their place among\l"
	.string "the other cities, I'd say.$"

PacifidlogTown_Text_BoredKidsWoman:
	.string "My little ones used to be more\n"
	.string "easily entertained by the beach...\l"
	.string "but now they're bored of it.\p"
	.string "They want a vacation from\n"
	.string "their vacation...$"

PacifidlogTown_Text_VisitSadFisher:
	.string "You a trainer? Ya got that\n"
	.string "look in your eye.\p"
	.string "If you're wantin' to train\n"
	.string "some fish Pokemon, maybe go hit\l"
	.string "up that one angler at the\l"
	.string "southeastern part of town.\l"
	.string "He's been advertisin'.$"

PacifidlogTown_PokemonCenter_1F_Text_WhatColorTrainerCard:
	.string "What color is your TRAINER CARD?\n"
	.string "Mine's copper!$"

PacifidlogTown_PokemonCenter_1F_Text_OnColonyOfCorsola:
	.string "PACIFIDLOG TOWN floats on top of\n"
	.string "a colony of CORSOLA.\p"
	.string "If I told you that, would you believe\n"
	.string "me?$"

PacifidlogTown_PokemonCenter_1F_Text_AncestorsLivedOnBoats:
	.string "The ancestors of the people in\n"
	.string "PACIFIDLOG were said to have been\l"
	.string "born on boats and then lived and died \l"
	.string "aboard them.\p"
	.string "I understand that they lived that way\n"
	.string "because they were searching for\l"
	.string "something.$"

