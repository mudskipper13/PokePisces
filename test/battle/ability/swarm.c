#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Swarm boosts Bug-type moves in a pinch", s16 damage)
{
    u16 hp;
    PARAMETRIZE { hp = 99; }
    PARAMETRIZE { hp = 33; }
    GIVEN {
        ASSUME(gBattleMoves[MOVE_SILVER_WIND].type == TYPE_BUG);
        PLAYER(SPECIES_LEDYBA) { Ability(ABILITY_SWARM); MaxHP(99); HP(hp); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SILVER_WIND); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(2), results[1].damage);
    }
}
