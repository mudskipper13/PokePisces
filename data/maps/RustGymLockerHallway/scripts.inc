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
	.string "Are you a member of the\n"
	.string "bourgeosie? Would you perhaps\l"
	.string "be interested in advocating\l"
	.string "for those of lower class standing?$"

RustGymLockerHallway_Text_JeanPaulDefeated:
	.string "I supposed I am condemned to\n"
	.string "be free of battling prowess.$"

RustGymLockerHallway_Text_JeanPaulPostBattle:
	.string "Upon my defeat, I have become an\n"
	.string "object in your mind. No longer\l"
	.string "an individual, merely your\l"
	.string "interpretation of what I was.$"

RustGymLockerHallway_Text_SimoneIntro:
	.string "Your philosophical leanings\n"
	.string "seem quite... ambiguous.\p"
	.string "Let us ponder the ethics\n"
	.string "of that as we battle.$"

RustGymLockerHallway_Text_SimoneDefeated:
	.string "One is not born a master.\p"
	.string "One becomes one.$"

RustGymLockerHallway_Text_SimonePostBattle:
	.string "Jean-Paul and I are in\n"
	.string "an open relationship.\p"
	.string "You seem quite wishy-washy,\n"
	.string "though, so I don't see you\l"
	.string "integrating yourself with us.$"
