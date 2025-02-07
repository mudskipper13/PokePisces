OldaleNew_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, OldaleNew_OnTransition
	.byte 0

OldaleNew_OnTransition:
	setflag FLAG_VISITED_OLDALE_TOWN
	end

OldaleNew_EventScript_Natasha::
    trainerbattle_single TRAINER_P_NATASHA, OldaleNew_Text_NatashaIntro, OldaleNew_Text_NatashaDefeated
    msgbox OldaleNew_Text_NatashaPostBattle, MSGBOX_AUTOCLOSE
    end

OldaleNew_Text_NatashaIntro:
	.string "intro$"

OldaleNew_Text_NatashaDefeated:
	.string "defeat$"

OldaleNew_Text_NatashaPostBattle:
	.string "post$"
