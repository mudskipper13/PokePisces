#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Huddle Up switches Level 25+ Lottabats's form when HP is 25-percent or less at the end of the turn")
{
    u16 level;
    PARAMETRIZE { level = 19; }
    PARAMETRIZE { level = 25; }

    GIVEN {
        ASSUME(P_GEN_7_POKEMON == TRUE);
        ASSUME(gSpeciesInfo[SPECIES_LOTTABATS].baseHP == gSpeciesInfo[SPECIES_LOTTABATS_HUDDLED].baseHP);
        PLAYER(SPECIES_LOTTABATS)
        {
            Level(level);
            HP(GetMonData(&PLAYER_PARTY[0], MON_DATA_MAX_HP) / 2);
            Ability(ABILITY_HUDDLE_UP);
        }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_SUPER_FANG); }
    } SCENE {
        if (level >= 25)
        {
            ABILITY_POPUP(player, ABILITY_HUDDLE_UP);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_FORM_CHANGE, player);
        }
        MESSAGE("Lottabats used Celebrate!");
        MESSAGE("Foe Wobbuffet used Super Fang!");
        HP_BAR(player);
        if (level >= 25)
        {
            ABILITY_POPUP(player, ABILITY_HUDDLE_UP);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_FORM_CHANGE, player);
        }
    } THEN {
        EXPECT_EQ(player->species, SPECIES_LOTTABATS);
    }
}

SINGLE_BATTLE_TEST("Huddle Up switches Level 25+ Lottabats's form when HP is over 25-percent before the first turn")
{
    u16 level;
    bool32 overQuarterHP;
    PARAMETRIZE { level = 19; overQuarterHP = FALSE; }
    PARAMETRIZE { level = 25; overQuarterHP = FALSE; }
    PARAMETRIZE { level = 19; overQuarterHP = TRUE; }
    PARAMETRIZE { level = 25; overQuarterHP = TRUE; }

    GIVEN {
        ASSUME(P_GEN_7_POKEMON == TRUE);
        ASSUME(gSpeciesInfo[SPECIES_LOTTABATS].baseHP == gSpeciesInfo[SPECIES_LOTTABATS_HUDDLED].baseHP);
        PLAYER(SPECIES_LOTTABATS)
        {
            Level(level);
            HP(GetMonData(&PLAYER_PARTY[0], MON_DATA_MAX_HP) / (overQuarterHP ? 2 : 4));
            Ability(ABILITY_HUDDLE_UP);
        }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_CELEBRATE); }
    } SCENE {
        if (level >= 25 && overQuarterHP)
        {
            ABILITY_POPUP(player, ABILITY_HUDDLE_UP);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_FORM_CHANGE, player);
        }
        MESSAGE("Lottabats used Celebrate!");
        MESSAGE("Foe Wobbuffet used Celebrate!");
    } THEN {
        if (level >= 25 && overQuarterHP)
            EXPECT_EQ(player->species, SPECIES_LOTTABATS_HUDDLED);
        else
            EXPECT_EQ(player->species, SPECIES_LOTTABATS);
    }
}

SINGLE_BATTLE_TEST("Huddle Up switches Level 25+ Lottabats's form when HP is healed above 25-percent")
{
    u16 level;
    PARAMETRIZE { level = 19; }
    PARAMETRIZE { level = 25; }

    GIVEN {
        ASSUME(P_GEN_7_POKEMON == TRUE);
        ASSUME(gSpeciesInfo[SPECIES_LOTTABATS].baseHP == gSpeciesInfo[SPECIES_LOTTABATS_HUDDLED].baseHP);
        PLAYER(SPECIES_LOTTABATS)
        {
            Level(level);
            HP(GetMonData(&PLAYER_PARTY[0], MON_DATA_MAX_HP) / 4);
            Ability(ABILITY_HUDDLE_UP);
        }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_HEAL_PULSE); }
    } SCENE {
        MESSAGE("Lottabats used Celebrate!");
        MESSAGE("Foe Wobbuffet used Heal Pulse!");
        HP_BAR(player);
        if (level >= 25)
        {
            ABILITY_POPUP(player, ABILITY_HUDDLE_UP);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_FORM_CHANGE, player);
        }
    } THEN {
        if (level >= 25)
            EXPECT_EQ(player->species, SPECIES_LOTTABATS_HUDDLED);
        else
            EXPECT_EQ(player->species, SPECIES_LOTTABATS);
    }
}
