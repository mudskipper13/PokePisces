#include "global.h"
#include "test/battle.h"


SINGLE_BATTLE_TEST("Frostbite reduces Attack by 50%", s16 damage)
{
    bool32 frostbite;
    PARAMETRIZE { frostbite = FALSE; }
    PARAMETRIZE { frostbite = TRUE; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { if (frostbite) Status1(STATUS1_FROSTBITE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_WATER_GUN); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(0.5), results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Frostbite deals 1/16 damage to effected pokemon")
{
    s16 frostbiteDamage;

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Status1(STATUS1_FROSTBITE); }
    } WHEN {
        TURN {}
    } SCENE {
        MESSAGE("Foe Wobbuffet is hurt by its frostbite!");
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_FRS, opponent);
        HP_BAR(opponent, captureDamage: &frostbiteDamage);
   } THEN { EXPECT_EQ(frostbiteDamage, opponent->maxHP / 16); }
}

SINGLE_BATTLE_TEST("Frostbite is healed if hit with a thawing move")
{
    u32 move;

    PARAMETRIZE { move = MOVE_FLAME_WHEEL; }
    PARAMETRIZE { move = MOVE_SACRED_FIRE; }
    PARAMETRIZE { move = MOVE_FLARE_BLITZ; }
    PARAMETRIZE { move = MOVE_FUSION_FLARE; }
    PARAMETRIZE { move = MOVE_EMBER; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Status1(STATUS1_FROSTBITE); }
    } WHEN {
        TURN { MOVE(player, move); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, move, player);
        if (move == MOVE_EMBER) {
            NONE_OF {
                MESSAGE("Foe Wobbuffet's frostbite was healed!");
            }
        } else {
            MESSAGE("Foe Wobbuffet's frostbite was healed!");
        }
   }
}

SINGLE_BATTLE_TEST("Frostbite is healed when the user uses a thawing move")
{
    u32 move;

    PARAMETRIZE { move = MOVE_FLAME_WHEEL; }
    PARAMETRIZE { move = MOVE_SACRED_FIRE; }
    PARAMETRIZE { move = MOVE_FLARE_BLITZ; }
    PARAMETRIZE { move = MOVE_FUSION_FLARE; }
    PARAMETRIZE { move = MOVE_EMBER; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Status1(STATUS1_FROSTBITE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, move); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, move, player);
        HP_BAR(opponent);
        if (move == MOVE_EMBER) {
            MESSAGE("Wobbuffet is hurt by its frostbite!");
            ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_FRS, player);
        } else {
            NONE_OF {
                MESSAGE("Wobbuffet is hurt by its frostbite!");
                ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_FRS, player);
            }
        }
   }
}
