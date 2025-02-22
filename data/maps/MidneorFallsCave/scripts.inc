MidneorFallsCave_MapScripts::
	.byte 0

MidneorFallsCave_EventScript_Kray::
    trainerbattle_single TRAINER_P_KRAY, MidneorFallsCave_Text_KrayIntro, MidneorFallsCave_Text_KrayDefeated
    msgbox MidneorFallsCave_Text_KrayPostBattle, MSGBOX_AUTOCLOSE
    end

MidneorFallsCave_EventScript_Zii::
    trainerbattle_single TRAINER_P_ZII, MidneorFallsCave_Text_ZiiIntro, MidneorFallsCave_Text_ZiiDefeated
    msgbox MidneorFallsCave_Text_ZiiPostBattle, MSGBOX_AUTOCLOSE
    end

MidneorFallsCave_EventScript_Ivan::
    trainerbattle_single TRAINER_P_IVAN, MidneorFallsCave_Text_IvanIntro, MidneorFallsCave_Text_IvanDefeated
    msgbox MidneorFallsCave_Text_IvanPostBattle, MSGBOX_AUTOCLOSE
    end

MidneorFallsCave_EventScript_Libya::
    trainerbattle_single TRAINER_P_LIBYA, MidneorFallsCave_Text_LibyaIntro, MidneorFallsCave_Text_LibyaDefeated
    msgbox MidneorFallsCave_Text_LibyaPostBattle, MSGBOX_AUTOCLOSE
    end

MidneorFallsCave_EventScript_Carville::
    trainerbattle_single TRAINER_P_CARVILLE, MidneorFallsCave_Text_CarvilleIntro, MidneorFallsCave_Text_CarvilleDefeated
    msgbox MidneorFallsCave_Text_CarvillePostBattle, MSGBOX_AUTOCLOSE
    end

MidneorFallsCave_EventScript_Boom::
    trainerbattle_single TRAINER_P_BOOM, MidneorFallsCave_Text_BoomIntro, MidneorFallsCave_Text_BoomDefeated
    msgbox MidneorFallsCave_Text_BoomPostBattle, MSGBOX_AUTOCLOSE
    end

MidneorFallsCave_EventScript_Iwan::
    trainerbattle_single TRAINER_P_IWAN, MidneorFallsCave_Text_IwanIntro, MidneorFallsCave_Text_IwanDefeated
    msgbox MidneorFallsCave_Text_IwanPostBattle, MSGBOX_AUTOCLOSE
    end

MidneorFallsCave_Text_KrayIntro:
	.string "Ahahahahaha!$"

MidneorFallsCave_Text_KrayDefeated:
	.string "Ka-boooooom!$"

MidneorFallsCave_Text_KrayPostBattle:
	.string "Kyahahahaha!$"

MidneorFallsCave_Text_ZiiIntro:
	.string "Here, hold this.$"

MidneorFallsCave_Text_ZiiDefeated:
	.string "Happy Birthday!$"

MidneorFallsCave_Text_ZiiPostBattle:
	.string "Hope you liked my gift!$"

MidneorFallsCave_Text_IvanIntro:
	.string "Ivan's not home.$"

MidneorFallsCave_Text_IvanDefeated:
	.string "Heh-heh-heh-heh.$"

MidneorFallsCave_Text_IvanPostBattle:
	.string "Kuheh...$"

MidneorFallsCave_Text_LibyaIntro:
	.string "Beepbeepbeepbeep...$"

MidneorFallsCave_Text_LibyaDefeated:
	.string "What the fuu-$"

MidneorFallsCave_Text_LibyaPostBattle:
	.string "BOOOOOUMMMMM!"

MidneorFallsCave_Text_CarvilleIntro:
	.string "It's too quiet here...$"

MidneorFallsCave_Text_CarvilleDefeated:
	.string "Shhhh.....$"

MidneorFallsCave_Text_CarvillePostBattle:
	.string "KABLAM!!$"

MidneorFallsCave_Text_BoomIntro:
	.string "Adios, amigo!$"

MidneorFallsCave_Text_BoomDefeated:
	.string "iVamos!$"

MidneorFallsCave_Text_BoomPostBattle:
	.string "Heh heh heh.$"

MidneorFallsCave_Text_IwanIntro:
	.string "Here's some hot papaya!$"

MidneorFallsCave_Text_IwanDefeated:
	.string "Served hot!$"

MidneorFallsCave_Text_IwanPostBattle:
	.string "How'd you like that?$"
