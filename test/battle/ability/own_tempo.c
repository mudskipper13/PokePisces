#include "global.h"
#include "test/battle.h"

//SINGLE_BATTLE_TEST("Own Tempo prevents intimidate")
//{
//    s16 turnOneHit;
//    s16 turnTwoHit;
//
//    GIVEN {
//        ASSUME(B_UPDATED_INTIMIDATE >= GEN_8);
//        PLAYER(SPECIES_EKANS) { Ability(ABILITY_SHED_SKIN); };
//        PLAYER(SPECIES_EKANS) { Ability(ABILITY_INTIMIDATE); };
//        OPPONENT(SPECIES_SLOWPOKE) { Ability(ABILITY_OWN_TEMPO); };
//    } WHEN {
//        TURN { MOVE(opponent, MOVE_TACKLE); }
//        TURN { SWITCH(player, 1); MOVE(opponent, MOVE_TACKLE); }
//
//    } SCENE {
//        HP_BAR(player, captureDamage: &turnOneHit);
//        ABILITY_POPUP(player, ABILITY_INTIMIDATE);
//        NONE_OF { ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player); }
//        ABILITY_POPUP(opponent, ABILITY_OWN_TEMPO);
//        MESSAGE("Foe Slowpoke's Attack was not lowered!");
//        HP_BAR(player, captureDamage: &turnTwoHit);
//    } THEN {
//        EXPECT_EQ(turnOneHit, turnTwoHit);
//    }
//}

SINGLE_BATTLE_TEST("Own Tempo prevents confusion from moves by the opponent")
{
    GIVEN {
        ASSUME(gBattleMoves[MOVE_CONFUSE_RAY].effect == EFFECT_CONFUSE);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_SLOWPOKE) { Ability(ABILITY_OWN_TEMPO); };
    } WHEN {
        TURN { MOVE(player, MOVE_CONFUSE_RAY); }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_OWN_TEMPO);
        MESSAGE("Foe Slowpoke's Own Tempo prevents confusion!");
    }
}

SINGLE_BATTLE_TEST("Own Tempo prevents confusion from moves by the user")
{
    GIVEN {
        ASSUME(gBattleMoves[MOVE_PETAL_DANCE].effect == EFFECT_RAMPAGE);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_SLOWPOKE) { Ability(ABILITY_OWN_TEMPO); };
    } WHEN {
        TURN { MOVE(opponent, MOVE_PETAL_DANCE); }
        TURN { MOVE(opponent, MOVE_PETAL_DANCE); }
        TURN { MOVE(opponent, MOVE_PETAL_DANCE); }
        TURN { MOVE(opponent, MOVE_PETAL_DANCE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PETAL_DANCE, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PETAL_DANCE, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PETAL_DANCE, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PETAL_DANCE, opponent);
        NONE_OF { MESSAGE("Foe Slowpoke became confused due to fatigue!"); }
    }
}

SINGLE_BATTLE_TEST("Own Tempo cures confusion obtained from an opponent with Mold Breaker")
{
    KNOWN_FAILING;
    GIVEN {
        ASSUME(gBattleMoves[MOVE_CONFUSE_RAY].effect == EFFECT_CONFUSE);
        PLAYER(SPECIES_PINSIR) { Ability(ABILITY_MOLD_BREAKER); };
        OPPONENT(SPECIES_SLOWPOKE) { Ability(ABILITY_OWN_TEMPO); };
    } WHEN {
        TURN { MOVE(player, MOVE_CONFUSE_RAY); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CONFUSE_RAY, player);
        MESSAGE("Foe Slowpoke became confused!");
        NONE_OF {
            ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_CONFUSION, opponent);
        }
        ABILITY_POPUP(opponent, ABILITY_OWN_TEMPO);
        MESSAGE("Foe Slowpoke's Own Tempo cured its confusion problem!");
    }
}

SINGLE_BATTLE_TEST("Own Tempo cures confusion if it's obtained via Skill Swap")
{
    GIVEN {
        ASSUME(gBattleMoves[MOVE_CONFUSE_RAY].effect == EFFECT_CONFUSE);
        ASSUME(gBattleMoves[MOVE_SKILL_SWAP].effect == EFFECT_SKILL_SWAP);
        PLAYER(SPECIES_SLOWPOKE) { Ability(ABILITY_OWN_TEMPO); };
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_CONFUSE_RAY); }
        TURN { MOVE(player, MOVE_SKILL_SWAP);
               MOVE(opponent, MOVE_TACKLE);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CONFUSE_RAY, player);
        MESSAGE("Foe Wobbuffet became confused!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SKILL_SWAP, player);
        ABILITY_POPUP(opponent, ABILITY_OWN_TEMPO);
        MESSAGE("Foe Wobbuffet's Own Tempo cured its confusion problem!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, opponent);
    }
}

SINGLE_BATTLE_TEST("Own Tempo prevents confusion from items")
{
    GIVEN {
        ASSUME(gItems[ITEM_BERSERK_GENE].holdEffect == HOLD_EFFECT_BERSERK_GENE);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_SLOWPOKE) { Ability(ABILITY_OWN_TEMPO); Item(ITEM_BERSERK_GENE); };
    } WHEN {
        TURN { MOVE(opponent, MOVE_TACKLE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, opponent);
        ABILITY_POPUP(opponent, ABILITY_OWN_TEMPO);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, opponent);
    }
}

//SINGLE_BATTLE_TEST("Own Tempo's power raises depending on different Dance moves", s16 damage) //tweak to use different dance moves
//{
//    u8 count;
//    PARAMETRIZE { count = 1; }
//    PARAMETRIZE { count = 2; }
//    PARAMETRIZE { count = 3; }
//    PARAMETRIZE { count = 4; }
//    PARAMETRIZE { count = 5; }
//    GIVEN {
//        PLAYER(SPECIES_INFAIRNO);
//        OPPONENT(SPECIES_WOBBUFFET);
//    } WHEN {
//        TURN { MOVE(player, MOVE_FEATHER_DANCE); }
//        if (count != 1){
//            TURN { MOVE(player, MOVE_FEATHER_DANCE); }
//            if (count == 5) {
//                TURN { MOVE(player, MOVE_FEATHER_DANCE); }
//            }
//        }
//        TURN { MOVE(player, MOVE_POUND); }
//    } SCENE {
//        ANIMATION(ANIM_TYPE_MOVE, MOVE_FEATHER_DANCE, player);
//        MESSAGE("Foe Wobbuffet's Attack harshly fell!");
//        if (count != 1) {
//            ANIMATION(ANIM_TYPE_MOVE, MOVE_FEATHER_DANCE, player);
//            MESSAGE("Foe Wobbuffet's Attack harshly fell!");
//            if (count == 5) {
//                ANIMATION(ANIM_TYPE_MOVE, MOVE_FEATHER_DANCE, player);
//                MESSAGE("Foe Wobbuffet's Attack harshly fell!");
//            }
//        }
//        ANIMATION(ANIM_TYPE_MOVE, MOVE_POUND, player);
//        HP_BAR(opponent, captureDamage: &results[i].damage);
//    } FINALLY {
//        EXPECT_MUL_EQ(results[0].damage, Q_4_12(1.0), results[0].damage);
//        EXPECT_MUL_EQ(results[0].damage, Q_4_12(1.1), results[1].damage);
//        EXPECT_MUL_EQ(results[0].damage, Q_4_12(1.2), results[2].damage);
//        EXPECT_MUL_EQ(results[0].damage, Q_4_12(1.3), results[3].damage);
//        EXPECT_MUL_EQ(results[0].damage, Q_4_12(1.4), results[4].damage);
//        EXPECT_MUL_EQ(results[0].damage, Q_4_12(1.5), results[5].damage);
//    }
//}
