TestMap_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, TestMapOnTransition
	.byte 0

TestMapOnTransition:
	goto TestMapEventScript_SetMauvilleOldManGfx
	end

TestMapEventScript_SetMauvilleOldManGfx::
	special SetMauvilleOldManObjEventGfx
	end

TestMap_EventScript_PoisonPartyTest::
	lock
	faceplayer
	msgbox TestMap_Text_MendelIntro, MSGBOX_DEFAULT
	burnplayerparty
	msgbox TestMap_Text_MendelPostBattle, MSGBOX_AUTOCLOSE
	release
	end

TestMap_EventScript_Mendel::
    trainerbattle_single TRAINER_P_MENDEL, TestMap_Text_MendelIntro, TestMap_Text_MendelDefeated
    msgbox TestMap_Text_MendelPostBattle, MSGBOX_AUTOCLOSE
    end

TestMap_EventScript_Egg::
	lock
	faceplayer
	playfanfare MUS_OBTAIN_ITEM
	message TestMap_Text_MendelPostBattle
	waitfanfare
	giveegg SPECIES_WANNEGG
	release
	end

TestMap_EventScript_SpeakerNameTest::
    lock
    speakername TestMap_Text_NameJacob
    msgbox TestMap_Text_MendelIntro, MSGBOX_DEFAULT
    speakername NULL
    msgbox TestMap_Text_MendelPostBattle, MSGBOX_AUTOCLOSE
    release
    end

TestMap_EventScript_GymLeader::
	lock
	trainerbattle_two_trainers TRAINER_P_MENDEL, TestMap_Text_MendelIntro, TRAINER_GRUNT_AQUA_HIDEOUT_2, TestMap_Text_MendelDefeated, TestMap_EventScript_Mendel, NO_MUSIC
	release
	end

TestMap_EventScript_Gym1::
	lock
	trainerbattle_two_trainers TRAINER_P_SEBASTIAN, TestMap_Text_MendelIntro, TRAINER_P_JUAN, TestMap_Text_MendelDefeated
	release
	end

TestMap_EventScript_Ray1::
    trainerbattle_single TRAINER_P_RAY_1, TestMap_Text_MendelIntro, TestMap_Text_MendelDefeated
    msgbox TestMap_Text_MendelPostBattle, MSGBOX_AUTOCLOSE
    end

TestMap_EventScript_Gym2::
    trainerbattle_single TRAINER_P_LIZA, TestMap_Text_MendelIntro, TestMap_Text_MendelDefeated
    msgbox TestMap_Text_MendelPostBattle, MSGBOX_AUTOCLOSE
    end

TestMap_EventScript_MattTab::
	lock
	trainerbattle_two_trainers TRAINER_P_OZONE_TABITHA_1, TestMap_Text_MendelIntro, TRAINER_P_OZONE_MATT_1, TestMap_Text_MendelDefeated
	release
	end

TestMap_EventScript_Ray2::
    trainerbattle_single TRAINER_P_RAY_2, TestMap_Text_MendelIntro, TestMap_Text_MendelDefeated
    msgbox TestMap_Text_MendelPostBattle, MSGBOX_AUTOCLOSE
    end

TestMap_EventScript_Gym3::
	lock
	trainerbattle_two_trainers TRAINER_P_SPENSER, TestMap_Text_MendelIntro, TRAINER_P_PHOEBE, TestMap_Text_MendelDefeated
	release
	end

TestMap_EventScript_Gym4::
	lock
	trainerbattle_two_trainers TRAINER_P_AARUNE, TestMap_Text_MendelIntro, TRAINER_P_WINONA, TestMap_Text_MendelDefeated
	release
	end

TestMap_EventScript_Ray3::
    trainerbattle_single TRAINER_P_RAY_3, TestMap_Text_MendelIntro, TestMap_Text_MendelDefeated
    msgbox TestMap_Text_MendelPostBattle, MSGBOX_AUTOCLOSE
    end

TestMap_EventScript_Tab1::
    trainerbattle_single TRAINER_P_TABITHA_2, TestMap_Text_MendelIntro, TestMap_Text_MendelDefeated
    msgbox TestMap_Text_MendelPostBattle, MSGBOX_AUTOCLOSE
    end

TestMap_EventScript_Gym5::
	lock
	trainerbattle_two_trainers TRAINER_P_MR_MOORE, TestMap_Text_MendelIntro, TRAINER_P_FLANNERY, TestMap_Text_MendelDefeated
	release
	end

TestMap_EventScript_Matt1::
    trainerbattle_single TRAINER_P_MATT_2, TestMap_Text_MendelIntro, TestMap_Text_MendelDefeated
    msgbox TestMap_Text_MendelPostBattle, MSGBOX_AUTOCLOSE
    end

TestMap_EventScript_Ray4::
    trainerbattle_single TRAINER_P_RAY_4, TestMap_Text_MendelIntro, TestMap_Text_MendelDefeated
    msgbox TestMap_Text_MendelPostBattle, MSGBOX_AUTOCLOSE
    end

TestMap_EventScript_Courtney1::
    trainerbattle_single TRAINER_P_COURTNEY_1, TestMap_Text_MendelIntro, TestMap_Text_MendelDefeated
    msgbox TestMap_Text_MendelPostBattle, MSGBOX_AUTOCLOSE
    end

TestMap_EventScript_MrBonding::
    trainerbattle_single TRAINER_P_MR_BONDING, TestMap_Text_MendelIntro, TestMap_Text_MendelDefeated
    msgbox TestMap_Text_MendelPostBattle, MSGBOX_AUTOCLOSE
    end

TestMap_EventScript_Gym6::
	lock
	trainerbattle_two_trainers TRAINER_P_WATTSON, TestMap_Text_MendelIntro, TRAINER_P_SCOTT, TestMap_Text_MendelDefeated
	release
	end

TestMap_EventScript_Ray5::
    trainerbattle_single TRAINER_P_RAY_5, TestMap_Text_MendelIntro, TestMap_Text_MendelDefeated
    msgbox TestMap_Text_MendelPostBattle, MSGBOX_AUTOCLOSE
    end

TestMap_EventScript_Gym7::
	lock
	trainerbattle_two_trainers TRAINER_P_BRAWLY, TestMap_Text_MendelIntro, TRAINER_P_SHELLY_1, TestMap_Text_MendelDefeated
	release
	end

TestMap_EventScript_Gym8::
	lock
	trainerbattle_two_trainers TRAINER_P_ROXANNE, TestMap_Text_MendelIntro, TRAINER_P_LANETTE, TestMap_Text_MendelDefeated
	release
	end

TestMap_EventScript_Ray6::
    trainerbattle_single TRAINER_P_RAY_6, TestMap_Text_MendelIntro, TestMap_Text_MendelDefeated
    msgbox TestMap_Text_MendelPostBattle, MSGBOX_AUTOCLOSE
    end

TestMap_EventScript_Norman::
    trainerbattle_single TRAINER_P_NORMAN, TestMap_Text_MendelIntro, TestMap_Text_MendelDefeated
    msgbox TestMap_Text_MendelPostBattle, MSGBOX_AUTOCLOSE
    end

TestMap_EventScript_Gym9::
	lock
	trainerbattle_two_trainers TRAINER_P_SIDNEY, TestMap_Text_MendelIntro, TRAINER_P_LUCY, TestMap_Text_MendelDefeated
	release
	end

TestMap_EventScript_Wally::
    trainerbattle_double TRAINER_P_WALLY, TestMap_Text_MendelIntro, TestMap_Text_MendelDefeated, TestMap_Text_MendelPostBattle
    msgbox TestMap_Text_MendelPostBattle, MSGBOX_AUTOCLOSE
    end

TestMap_EventScript_Ray7::
    trainerbattle_single TRAINER_P_RAY_7, TestMap_Text_MendelIntro, TestMap_Text_MendelDefeated
    msgbox TestMap_Text_MendelPostBattle, MSGBOX_AUTOCLOSE
    end

TestMap_EventScript_Tab2::
    trainerbattle_single TRAINER_P_TABITHA_3, TestMap_Text_MendelIntro, TestMap_Text_MendelDefeated
    msgbox TestMap_Text_MendelPostBattle, MSGBOX_AUTOCLOSE
    end

TestMap_EventScript_Matt2::
    trainerbattle_single TRAINER_P_MATT_3, TestMap_Text_MendelIntro, TestMap_Text_MendelDefeated
    msgbox TestMap_Text_MendelPostBattle, MSGBOX_AUTOCLOSE
    end

TestMap_EventScript_Courtney2::
    trainerbattle_single TRAINER_P_COURTNEY_2, TestMap_Text_MendelIntro, TestMap_Text_MendelDefeated
    msgbox TestMap_Text_MendelPostBattle, MSGBOX_AUTOCLOSE
    end

TestMap_EventScript_Shelly2::
    trainerbattle_single TRAINER_P_SHELLY_2, TestMap_Text_MendelIntro, TestMap_Text_MendelDefeated
    msgbox TestMap_Text_MendelPostBattle, MSGBOX_AUTOCLOSE
    end

TestMap_EventScript_OzoneLeaders::
	lock
	trainerbattle_two_trainers TRAINER_P_MAXIE, TestMap_Text_MendelIntro, TRAINER_P_ARCHIE, TestMap_Text_MendelDefeated
	release
	end

TestMap_EventScript_Champions::
	lock
	trainerbattle_two_trainers TRAINER_P_WALLACE, TestMap_Text_MendelIntro, TRAINER_P_STEVEN, TestMap_Text_MendelDefeated
	release
	end

TestMap_EventScript_May::
    trainerbattle_single TRAINER_P_MAY_FINAL, TestMap_Text_MendelIntro, TestMap_Text_MendelDefeated
    msgbox TestMap_Text_MendelPostBattle, MSGBOX_AUTOCLOSE
    end

TestMap_EventScript_Brendan::
    trainerbattle_single TRAINER_P_BRENDAN_FINAL, TestMap_Text_MendelIntro, TestMap_Text_MendelDefeated
    msgbox TestMap_Text_MendelPostBattle, MSGBOX_AUTOCLOSE
    end

TestMap_EventScript_ItemBurntBranch::
	finditem ITEM_BURNT_BRANCH
	end

TestMap_EventScript_ItemCursedAmulet::
	finditem ITEM_CURSED_AMULET
	end

TestMap_EventScript_OldGuysTest::
	lock
	faceplayer
	setvar VAR_BARD_COLOR, MAUVILLE_MAN_GIDDY
	msgbox TestMap_Text_MendelDefeated, MSGBOX_AUTOCLOSE
	release
	end

TestMap_EventScript_FightLegends::
	lock
	msgbox TestMap_Text_MendelDefeated, MSGBOX_DEFAULT
	closemessage
	setwildbattle SPECIES_LUOSHAN, 50, ITEM_NONE, SPECIES_KYOGRE, 50, ITEM_NONE
	setflag FLAG_WILD_NO_CATCHING_FLAG
	setflag FLAG_WILD_NO_RUNNING_FLAG
	setflag FLAG_WILD_NO_CATCHING_FLAG
	setflag FLAG_SMART_WILD_AI_FLAG
	delay 4
	dowildbattle
	delay 8
	clearflag FLAG_WILD_NO_CATCHING_FLAG
	clearflag FLAG_WILD_NO_RUNNING_FLAG
	clearflag FLAG_WILD_NO_CATCHING_FLAG
	clearflag FLAG_SMART_WILD_AI_FLAG
	release
	end

TestMap_Text_MendelIntro:
	.string "intro$"

TestMap_Text_MendelDefeated:
	.string "defeat$"

TestMap_Text_MendelPostBattle:
	.string "post$"

TestMap_Text_NameJacob:
	.string "Quigley$"
