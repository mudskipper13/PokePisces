RustGymLockerHallway_MapScripts::
	.byte 0

RustGymLockerHallway_EventScript_JeanPaul::
    trainerbattle_single TRAINER_P_JEAN_PAUL, RustGymLockerHallway_Text_JeanPaulIntro, RustGymLockerHallway_Text_JeanPaulDefeated
    msgbox RustGymLockerHallway_Text_JeanPaulPostBattle, MSGBOX_AUTOCLOSE
    end

RustGymLockerHallway_EventScript_Simone::
    trainerbattle_single TRAINER_P_SIMONE, RustGymLockerHallway_Text_SimoneIntro, RustGymLockerHallway_Text_SimoneDefeated
    msgbox RustGymLockerHallway_Text_SimonePostBattle, MSGBOX_AUTOCLOSE
    end

RustGymLockerHallway_Text_JeanPaulIntro:
	.string "intro$"

RustGymLockerHallway_Text_JeanPaulDefeated:
	.string "defeat$"

RustGymLockerHallway_Text_JeanPaulPostBattle:
	.string "post$"

RustGymLockerHallway_Text_SimoneIntro:
	.string "intro$"

RustGymLockerHallway_Text_SimoneDefeated:
	.string "defeat$"

RustGymLockerHallway_Text_SimonePostBattle:
	.string "post$"
