FieryPath_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FieryPath_OnTransition
	.byte 0

FieryPath_OnTransition:
	call_if_unset FLAG_LANDMARK_FIERY_PATH, FieryPath_EventScript_MoveScottToFallarbor
	setflag FLAG_LANDMARK_FIERY_PATH
	end

FieryPath_EventScript_MoveScottToFallarbor::
	setflag FLAG_HIDE_VERDANTURF_TOWN_SCOTT
	clearflag FLAG_HIDE_FALLARBOR_TOWN_BATTLE_TENT_SCOTT
	return

FieryPath_EventScript_Cass::
    trainerbattle_single TRAINER_P_CASS, FieryPath_Text_CassIntro, FieryPath_Text_CassDefeated
    msgbox FieryPath_Text_CassPostBattle, MSGBOX_AUTOCLOSE
    end

FieryPath_EventScript_Sandy::
    trainerbattle_single TRAINER_P_SANDY, FieryPath_Text_SandyIntro, FieryPath_Text_SandyDefeated
    msgbox FieryPath_Text_SandyPostBattle, MSGBOX_AUTOCLOSE
    end

FieryPath_EventScript_Jan::
    trainerbattle_single TRAINER_P_JAN, FieryPath_Text_JanIntro, FieryPath_Text_JanDefeated
    msgbox FieryPath_Text_JanPostBattle, MSGBOX_AUTOCLOSE
    end

FieryPath_EventScript_Catt::
    trainerbattle_single TRAINER_P_CATHY, FieryPath_Text_CattIntro, FieryPath_Text_CattDefeated
    msgbox FieryPath_Text_CattPostBattle, MSGBOX_AUTOCLOSE
    end

FieryPath_EventScript_Celia::
    trainerbattle_single TRAINER_P_CELIA, FieryPath_Text_CeliaIntro, FieryPath_Text_CeliaDefeated
    msgbox FieryPath_Text_CeliaPostBattle, MSGBOX_AUTOCLOSE
    end

FieryPath_EventScript_REDACTED::
    trainerbattle_single TRAINER_P_REDACTED, FieryPath_Text_REDACTEDIntro, FieryPath_Text_REDACTEDDefeated
    msgbox FieryPath_Text_REDACTEDPostBattle, MSGBOX_AUTOCLOSE
    end

FieryPath_EventScript_Dimitri::
    trainerbattle_single TRAINER_P_DIMITRI, FieryPath_Text_DimitriIntro, FieryPath_Text_DimitriDefeated
    msgbox FieryPath_Text_DimitriPostBattle, MSGBOX_AUTOCLOSE
    end

FieryPath_EventScript_CliffAndIssa::
    trainerbattle_double TRAINER_P_CLIFF_AND_ISSA, FieryPath_Text_CliffAndIssaIntro, FieryPath_Text_CliffAndIssaDefeated, FieryPath_Text_CliffAndIssaNeedTwoMons
    msgbox FieryPath_Text_CliffAndIssaPostBattle, MSGBOX_AUTOCLOSE
    end

FieryPath_EventScript_Gerode::
    trainerbattle_single TRAINER_P_GERODE, FieryPath_Text_GerodeIntro, FieryPath_Text_GerodeDefeated
    msgbox FieryPath_Text_GerodePostBattle, MSGBOX_AUTOCLOSE
    end

FieryPath_EventScript_Mezra::
    trainerbattle_single TRAINER_P_MEZRA, FieryPath_Text_MezraIntro, FieryPath_Text_MezraDefeated
    msgbox FieryPath_Text_MezraPostBattle, MSGBOX_AUTOCLOSE
    end

FieryPath_EventScript_Lane::
    trainerbattle_single TRAINER_P_LANE, FieryPath_Text_LaneIntro, FieryPath_Text_LaneDefeated
    msgbox FieryPath_Text_LanePostBattle, MSGBOX_AUTOCLOSE
    end

FieryPath_EventScript_Bonnie::
    trainerbattle_single TRAINER_P_BONNIE, FieryPath_Text_BonnieIntro, FieryPath_Text_BonnieDefeated
    msgbox FieryPath_Text_BonniePostBattle, MSGBOX_AUTOCLOSE
    end

FieryPath_EventScript_Hedon::
    trainerbattle_single TRAINER_P_HEDON, FieryPath_Text_HedonIntro, FieryPath_Text_HedonDefeated
    msgbox FieryPath_Text_HedonPostBattle, MSGBOX_AUTOCLOSE
    end

FieryPath_EventScript_Rye::
    trainerbattle_single TRAINER_P_RYE, FieryPath_Text_RyeIntro, FieryPath_Text_RyeDefeated
    msgbox FieryPath_Text_RyePostBattle, MSGBOX_AUTOCLOSE
    end

FieryPath_EventScript_Ingrid::
    trainerbattle_single TRAINER_P_INGRID, FieryPath_Text_IngridIntro, FieryPath_Text_IngridDefeated
    msgbox FieryPath_Text_IngridPostBattle, MSGBOX_AUTOCLOSE
    end

FieryPath_EventScript_BlaiseAndMar::
    trainerbattle_double TRAINER_P_BLAISE_AND_MAR, FieryPath_Text_BlaiseAndMarIntro, FieryPath_Text_BlaiseAndMarDefeated, FieryPath_Text_BlaiseAndMarNeedTwoMons
    msgbox FieryPath_Text_BlaiseAndMarPostBattle, MSGBOX_AUTOCLOSE
    end

FieryPath_Text_CassIntro:
	.string "intro$"

FieryPath_Text_CassDefeated:
	.string "defeat$"

FieryPath_Text_CassPostBattle:
	.string "post$"

FieryPath_Text_SandyIntro:
	.string "... You remind me of someone I battled a\n"
	.string "long time ago...$"

FieryPath_Text_SandyDefeated:
	.string "Yep... I lost to them, too...$"

FieryPath_Text_SandyPostBattle:
	.string "Right, I remember now...\p"
	.string "Back when Maxie was trying to awaken\n"
	.string "Groudon, I tried to stop them and we\l"
	.string "ended up losing.\p"
	.string "Uh, what a blast from the past!$"

FieryPath_Text_JanIntro:
	.string "I'm a janitor! I do it for free!$"

FieryPath_Text_JanDefeated:
	.string "Maybe I should demand a pay raise...$"

FieryPath_Text_JanPostBattle:
	.string "I take my job very seriously.$"

FieryPath_Text_CattIntro:
	.string "You will serve as a springboard for my\n"
	.string "ambition!$"

FieryPath_Text_CattDefeated:
	.string "Me?! Lose?! Impossible!$"

FieryPath_Text_CattPostBattle:
	.string "In the end I only served as a\n"
	.string "springboard for your own\n"
	.string "ambitions, how humiliating.$"

FieryPath_Text_CeliaIntro:
	.string "I'm totally lost in this place...\n"
	.string "Little help?$"

FieryPath_Text_CeliaDefeated:
	.string "I must be stupid or something...$"

FieryPath_Text_CeliaPostBattle:
	.string "On second thought...\n"
	.string "I think I'll just stay here.$"

FieryPath_Text_REDACTEDIntro:
	.string "It's a secret to everybody.$"

FieryPath_Text_REDACTEDDefeated:
	.string "(DATA EXPUNGED)$"

FieryPath_Text_REDACTEDPostBattle:
	.string "This speech intentionally left blank.$"

FieryPath_Text_DimitriIntro:
	.string "intro$"

FieryPath_Text_DimitriDefeated:
	.string "defeat$"

FieryPath_Text_DimitriPostBattle:
	.string "post$"

FieryPath_Text_CliffAndIssaIntro:
	.string "CLIFF: Hey kid, why ya lookin' at me that\n"
	.string "way?\p"
	.string "ISSA: Do you always have to act like\n"
	.string "this?$"

FieryPath_Text_CliffAndIssaDefeated:
	.string "ISSA: We lost because of you and your\n"
	.string "ego!\p"
	.string "CLIFF: You’re the one who was in my way!$"

FieryPath_Text_CliffAndIssaPostBattle:
	.string "CLIFF: Ya itchin' for another battle?\n"
	.string "ISSA: You can't ever take a break, can\l"
	.string"you?$"

FieryPath_Text_CliffAndIssaNeedTwoMons:
	.string "CLIFF: This kid's so weak and puny, they \n"
	.string "can't even battle us!\p"
	.string "ISSA: Or maybe you're so weak they\n"
	.string "can't bring themselves to beat you?$"


FieryPath_Text_GerodeIntro:
	.string "intro$"

FieryPath_Text_GerodeDefeated:
	.string "defeat$"

FieryPath_Text_GerodePostBattle:
	.string "post$"

FieryPath_Text_MezraIntro:
	.string "Swing your arms from side to side!$"

FieryPath_Text_MezraDefeated:
	.string "....Juuust liiike thaaat!$"

FieryPath_Text_MezraPostBattle:
	.string "Come on, it's time to go!$"

FieryPath_Text_LaneIntro:
	.string "Something here smells funny...\n"
	.string "Oh, it's just you!$"

FieryPath_Text_LaneDefeated:
	.string "Don't forget to flush!$"

FieryPath_Text_LanePostBattle:
	.string "(sniff, sniff) Wait, that smell isn't\n"
	.string "you. I must be plumb crazy...$"

FieryPath_Text_BonnieIntro:
	.string "poob!$"

FieryPath_Text_BonnieDefeated:
	.string "defeat$"

FieryPath_Text_BonniePostBattle:
	.string "post$"

FieryPath_Text_HedonIntro:
	.string "intro$"

FieryPath_Text_HedonDefeated:
	.string "defeat$"

FieryPath_Text_HedonPostBattle:
	.string "post$"

FieryPath_Text_RyeIntro:
	.string "intro$"

FieryPath_Text_RyeDefeated:
	.string "defeat$"

FieryPath_Text_RyePostBattle:
	.string "post$"

FieryPath_Text_IngridIntro:
	.string "intro$"

FieryPath_Text_IngridDefeated:
	.string "defeat$"

FieryPath_Text_IngridPostBattle:
	.string "post$"

FieryPath_Text_BlaiseAndMarIntro:
	.string "BLAISE: I'm a weather expert, you know.\n"
	.string "MAR: So am I! Don't discount me!$"

FieryPath_Text_BlaiseAndMarDefeated:
	.string "BLAISE: Why am I all wet?\n"
	.string "MAR: What happened?$"

FieryPath_Text_BlaiseAndMarPostBattle:
	.string "MAR: Well, now I'm all dried up...\n"
	.string "BLAISE: You doused my chances of\l"
	.string "winning!$"

FieryPath_Text_BlaiseAndMarNeedTwoMons:
	.string "BLAISE: We should double battle for a\n"
	.string "change.\p"
	.string "MAR: That sounds good to me...$"
