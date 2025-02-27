#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gBattleMoves[MOVE_DIRE_CLAW].effect == EFFECT_DIRE_CLAW);
}

SINGLE_BATTLE_TEST("Dire Claw can inflict poison, paralysis or panic")
{
    u8 statusAnim;
    PARAMETRIZE { statusAnim = B_ANIM_STATUS_PSN; }
    PARAMETRIZE { statusAnim = B_ANIM_STATUS_PRZ; }
    PARAMETRIZE { statusAnim = B_ANIM_STATUS_PNC; }
    PASSES_RANDOMLY(1, 3, RNG_DIRE_CLAW);
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_DIRE_CLAW); }
        TURN {}
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DIRE_CLAW, player);
        HP_BAR(opponent);
        ANIMATION(ANIM_TYPE_STATUS, statusAnim, opponent);
        if (statusAnim == B_ANIM_STATUS_PRZ) {
            STATUS_ICON(opponent, paralysis: TRUE);
        }
        else if (statusAnim == B_ANIM_STATUS_PNC) {
            STATUS_ICON(opponent, panic: TRUE);
        }
        else if (statusAnim == B_ANIM_STATUS_PSN) {
            STATUS_ICON(opponent, poison: TRUE);
        }
    }
}

SINGLE_BATTLE_TEST("Dire Claw cannot poison/paralyze poison/electric types respectively")
{
    u8 statusAnim;
    u16 species;
    u32 rng;
    #if B_PARALYZE_ELECTRIC >= GEN_6
    PARAMETRIZE { statusAnim = B_ANIM_STATUS_PRZ; rng = MOVE_EFFECT_PARALYSIS; species = SPECIES_RAICHU; }
    #endif // B_PARALYZE_ELECTRIC
    PARAMETRIZE { statusAnim = B_ANIM_STATUS_PSN; rng = MOVE_EFFECT_POISON; species = SPECIES_ARBOK; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(species);
    } WHEN {
        TURN { MOVE(player, MOVE_DIRE_CLAW, WITH_RNG(RNG_DIRE_CLAW, rng)); }
        TURN {}
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DIRE_CLAW, player);
        HP_BAR(opponent);
        NOT ANIMATION(ANIM_TYPE_STATUS, statusAnim, opponent);
        if (statusAnim == B_ANIM_STATUS_PRZ) {
            NOT STATUS_ICON(opponent, paralysis: TRUE);
        }
        else if (statusAnim == B_ANIM_STATUS_PSN) {
            NOT STATUS_ICON(opponent, poison: TRUE);
        }
    }
}

SINGLE_BATTLE_TEST("Dire Claw cannot poison/paralyze/cause to fall apanic pokemon with abilities preventing respective statuses")
{
    u8 statusAnim;
    u16 species, ability;
    u32 rng;
    PARAMETRIZE { statusAnim = B_ANIM_STATUS_PRZ; rng = MOVE_EFFECT_PARALYSIS; species = SPECIES_RAICHU; ability = ABILITY_LIGHTNING_ROD; }
    PARAMETRIZE { statusAnim = B_ANIM_STATUS_PRZ; rng = MOVE_EFFECT_PARALYSIS; species = SPECIES_JOLTEON; ability = ABILITY_VOLT_ABSORB; }
    #if P_GEN_4_POKEMON == TRUE
    PARAMETRIZE { statusAnim = B_ANIM_STATUS_PRZ; rng = MOVE_EFFECT_PARALYSIS; species = SPECIES_ELECTIVIRE; ability = ABILITY_MOTOR_DRIVE; }
    #endif // P_GEN_4_POKEMON
    PARAMETRIZE { statusAnim = B_ANIM_STATUS_PSN; rng = MOVE_EFFECT_POISON; species = SPECIES_ZANGOOSE; ability = ABILITY_IMMUNITY; }
    PARAMETRIZE { statusAnim = B_ANIM_STATUS_PNC; rng = MOVE_EFFECT_PANIC; species = SPECIES_CHAFFAW; ability = ABILITY_OBLIVIOUS; }
    PARAMETRIZE { statusAnim = B_ANIM_STATUS_PNC; rng = MOVE_EFFECT_PANIC; species = SPECIES_SHEEDRAKE; ability = ABILITY_UNAWARE; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(species) { Ability(ability); }
    } WHEN {
        TURN { MOVE(player, MOVE_DIRE_CLAW, WITH_RNG(RNG_DIRE_CLAW, rng)); }
        TURN {}
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DIRE_CLAW, player);
        HP_BAR(opponent);
        NOT ANIMATION(ANIM_TYPE_STATUS, statusAnim, opponent);
        if (statusAnim == B_ANIM_STATUS_PRZ) {
            NOT STATUS_ICON(opponent, paralysis: TRUE);
        }
        else if (statusAnim == B_ANIM_STATUS_PNC) {
            NOT STATUS_ICON(opponent, panic: TRUE);
        }
        else if (statusAnim == B_ANIM_STATUS_PSN) {
            NOT STATUS_ICON(opponent, poison: TRUE);
        }
    }
}

SINGLE_BATTLE_TEST("Dire Claw cannot poison/paralyze/cause to fall apanic a mon which is already statused")
{
    u8 statusAnim;
    u32 rng;
    PARAMETRIZE { statusAnim = B_ANIM_STATUS_PSN; rng = MOVE_EFFECT_POISON; }
    PARAMETRIZE { statusAnim = B_ANIM_STATUS_PRZ; rng = MOVE_EFFECT_PARALYSIS; }
    PARAMETRIZE { statusAnim = B_ANIM_STATUS_PNC; rng = MOVE_EFFECT_PANIC; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Status1(STATUS1_BURN); }
    } WHEN {
        TURN { MOVE(player, MOVE_DIRE_CLAW, WITH_RNG(RNG_DIRE_CLAW, rng)); }
        TURN {}
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DIRE_CLAW, player);
        HP_BAR(opponent);
        NOT ANIMATION(ANIM_TYPE_STATUS, statusAnim, opponent);
        if (statusAnim == B_ANIM_STATUS_PRZ) {
            NOT STATUS_ICON(opponent, paralysis: TRUE);
        }
        else if (statusAnim == B_ANIM_STATUS_PNC) {
            NOT STATUS_ICON(opponent, panic: TRUE);
        }
        else if (statusAnim == B_ANIM_STATUS_PSN) {
            NOT STATUS_ICON(opponent, poison: TRUE);
        }
    }
}
