#include "common.h"
#include "effects.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/shy_guy.h"
#include "sprite/npc/sky_guy.h"

#define NAMESPACE b_area_omo_sky_guy

extern s32 N(idleAnimations_8022B104)[];
extern EvtScript N(init_8022987C);
extern EvtScript N(takeTurn_8022A9D0);
extern EvtScript N(takeTurn_8022CA9C);
extern EvtScript N(idle_80229A24);
extern EvtScript N(idle_8022B19C);
extern EvtScript N(handleEvent_8022A398);
extern EvtScript N(handleEvent_8022B310);

s32 N(idleAnimations_802294C0)[] = {
    STATUS_NORMAL,    NPC_ANIM_sky_guy_Palette_00_Anim_1,
    STATUS_STONE,     NPC_ANIM_sky_guy_Palette_00_Anim_0,
    STATUS_SLEEP,     NPC_ANIM_sky_guy_Palette_00_Anim_4,
    STATUS_POISON,    NPC_ANIM_sky_guy_Palette_00_Anim_1,
    STATUS_STOP,      NPC_ANIM_sky_guy_Palette_00_Anim_0,
    STATUS_STATIC,    NPC_ANIM_sky_guy_Palette_00_Anim_1,
    STATUS_PARALYZE,  NPC_ANIM_sky_guy_Palette_00_Anim_0,
    STATUS_DIZZY,     NPC_ANIM_sky_guy_Palette_00_Anim_5,
    STATUS_FEAR,      NPC_ANIM_sky_guy_Palette_00_Anim_5,
    STATUS_END,
};

s32 N(idleAnimations_8022950C)[] = {
    STATUS_NORMAL,    NPC_ANIM_sky_guy_Palette_00_Anim_10,
    STATUS_STONE,     NPC_ANIM_sky_guy_Palette_00_Anim_D,
    STATUS_SLEEP,     NPC_ANIM_sky_guy_Palette_00_Anim_19,
    STATUS_POISON,    NPC_ANIM_sky_guy_Palette_00_Anim_10,
    STATUS_STOP,      NPC_ANIM_sky_guy_Palette_00_Anim_D,
    STATUS_STATIC,    NPC_ANIM_sky_guy_Palette_00_Anim_10,
    STATUS_PARALYZE,  NPC_ANIM_sky_guy_Palette_00_Anim_D,
    STATUS_DIZZY,     NPC_ANIM_sky_guy_Palette_00_Anim_10,
    STATUS_FEAR,      NPC_ANIM_sky_guy_Palette_00_Anim_10,
    STATUS_END,
};

s32 N(idleAnimations_80229558)[] = {
    STATUS_NORMAL,    NPC_ANIM_sky_guy_Palette_00_Anim_F,
    STATUS_STONE,     NPC_ANIM_sky_guy_Palette_00_Anim_C,
    STATUS_SLEEP,     NPC_ANIM_sky_guy_Palette_00_Anim_18,
    STATUS_POISON,    NPC_ANIM_sky_guy_Palette_00_Anim_F,
    STATUS_STOP,      NPC_ANIM_sky_guy_Palette_00_Anim_C,
    STATUS_STATIC,    NPC_ANIM_sky_guy_Palette_00_Anim_F,
    STATUS_PARALYZE,  NPC_ANIM_sky_guy_Palette_00_Anim_C,
    STATUS_DIZZY,     NPC_ANIM_sky_guy_Palette_00_Anim_F,
    STATUS_FEAR,      NPC_ANIM_sky_guy_Palette_00_Anim_F,
    STATUS_END,
};

s32 N(idleAnimations_802295A4)[] = {
    STATUS_NORMAL,    NPC_ANIM_sky_guy_Palette_00_Anim_11,
    STATUS_STONE,     NPC_ANIM_sky_guy_Palette_00_Anim_E,
    STATUS_SLEEP,     NPC_ANIM_sky_guy_Palette_00_Anim_1A,
    STATUS_POISON,    NPC_ANIM_sky_guy_Palette_00_Anim_11,
    STATUS_STOP,      NPC_ANIM_sky_guy_Palette_00_Anim_E,
    STATUS_STATIC,    NPC_ANIM_sky_guy_Palette_00_Anim_11,
    STATUS_PARALYZE,  NPC_ANIM_sky_guy_Palette_00_Anim_E,
    STATUS_DIZZY,     NPC_ANIM_sky_guy_Palette_00_Anim_11,
    STATUS_FEAR,      NPC_ANIM_sky_guy_Palette_00_Anim_11,
    STATUS_END,
};

s32 N(idleAnimations_802295F0)[] = {
    STATUS_NORMAL,    NPC_ANIM_sky_guy_Palette_00_Anim_B,
    STATUS_END,
};

s32 N(defenseTable_802295FC)[] = {
    ELEMENT_NORMAL, 0,
    ELEMENT_SHOCK, 0,
    ELEMENT_END,
};

s32 N(defenseTable_80229610)[] = {
    ELEMENT_NORMAL, 0,
    ELEMENT_SHOCK, 0,
    ELEMENT_END,
};

s32 N(statusTable_80229624)[] = {
    STATUS_NORMAL, 0,
    STATUS_DEFAULT, 0,
    STATUS_SLEEP, 70,
    STATUS_POISON, 50,
    STATUS_FROZEN, 0,
    STATUS_DIZZY, 90,
    STATUS_FEAR, 100,
    STATUS_STATIC, 50,
    STATUS_PARALYZE, 90,
    STATUS_SHRINK, 75,
    STATUS_STOP, 90,
    STATUS_DEFAULT_TURN_MOD, 0,
    STATUS_SLEEP_TURN_MOD, 0,
    STATUS_POISON_TURN_MOD, 0,
    STATUS_FROZEN_TURN_MOD, 0,
    STATUS_DIZZY_TURN_MOD, 1,
    STATUS_FEAR_TURN_MOD, 0,
    STATUS_STATIC_TURN_MOD, 0,
    STATUS_PARALYZE_TURN_MOD, 1,
    STATUS_SHRINK_TURN_MOD, 0,
    STATUS_STOP_TURN_MOD, 0,
    STATUS_END,
};

s32 N(statusTable_802296D0)[] = {
    STATUS_NORMAL, 0,
    STATUS_DEFAULT, 0,
    STATUS_SLEEP, 70,
    STATUS_POISON, 50,
    STATUS_FROZEN, 0,
    STATUS_DIZZY, 90,
    STATUS_FEAR, 100,
    STATUS_STATIC, 50,
    STATUS_PARALYZE, 90,
    STATUS_SHRINK, 75,
    STATUS_STOP, 90,
    STATUS_DEFAULT_TURN_MOD, 0,
    STATUS_SLEEP_TURN_MOD, 0,
    STATUS_POISON_TURN_MOD, 0,
    STATUS_FROZEN_TURN_MOD, 0,
    STATUS_DIZZY_TURN_MOD, 0,
    STATUS_FEAR_TURN_MOD, 0,
    STATUS_STATIC_TURN_MOD, 0,
    STATUS_PARALYZE_TURN_MOD, 1,
    STATUS_SHRINK_TURN_MOD, 0,
    STATUS_STOP_TURN_MOD, 0,
    STATUS_END,
};

ActorPartBlueprint N(partsTable_8022977C)[] = {
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET,
        .index = 1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 32 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_8022B104),
        .defenseTable = N(defenseTable_80229610),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .unk_1C = 246,
    },
    {
        .flags = ACTOR_PART_FLAG_MULTI_TARGET,
        .index = 2,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_802294C0),
        .defenseTable = N(defenseTable_802295FC),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .unk_1C = -10,
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_2 | ACTOR_PART_FLAG_100000,
        .index = 3,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 2, 50 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_8022950C),
        .defenseTable = N(defenseTable_802295FC),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .unk_1C = -10,
        .unk_20 = 0x29007E,
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_2 | ACTOR_PART_FLAG_2000 | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_100000,
        .index = 4,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_80229558),
        .defenseTable = N(defenseTable_802295FC),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .unk_1C = -10,
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_2 | ACTOR_PART_FLAG_2000 | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_100000,
        .index = 5,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_802295A4),
        .defenseTable = N(defenseTable_802295FC),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .unk_1C = -10,
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_100000,
        .index = 6,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_802295F0),
        .defenseTable = N(defenseTable_802295FC),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .unk_1C = -10,
    },
};

ActorBlueprint NAMESPACE = {
    .flags = ACTOR_FLAG_FLYING,
    .type = ACTOR_TYPE_SKY_GUY,
    .level = 14,
    .maxHP = 7,
    .partCount = ARRAY_COUNT(N(partsTable_8022977C)),
    .partsData = N(partsTable_8022977C),
    .script = N(init_8022987C),
    .statusTable = N(statusTable_80229624),
    .escapeChance = 50,
    .airLiftChance = 90,
    .spookChance = 90,
    .baseStatusChance = 80,
    .upAndAwayChance = 95,
    .spinSmashReq = 0,
    .powerBounceChance = 90,
    .coinReward = 1,
    .size = { 28, 28 },
    .hpBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 20 },
    .statusMessageOffset = { 10, 20 },
};

EvtScript N(init_8022987C) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_ADDR(N(takeTurn_8022A9D0)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_ADDR(N(idle_80229A24)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_ADDR(N(handleEvent_8022A398)))
    EVT_CALL(SetActorVar, ACTOR_SELF, 8, 0)
    EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(SetPartPos, ACTOR_SELF, 3, LW(0), LW(1), LW(2))
    EVT_CALL(SetPartPos, ACTOR_SELF, 4, LW(0), LW(1), LW(2))
    EVT_CALL(SetPartPos, ACTOR_SELF, 5, LW(0), LW(1), LW(2))
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, 3, ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_100000, 0)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, 4, ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_100000, 0)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, 5, ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_100000, 0)
    EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_SUB(LW(1), 5)
    EVT_CALL(ForceHomePos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(HPBarToHome, ACTOR_SELF)
    EVT_CALL(SetPartTargetFlagBits, ACTOR_SELF, 3, 4, 1)
    EVT_RETURN
    EVT_END
};

EvtScript N(idle_80229A24) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(80229A34) = {
    EVT_CALL(GetActorVar, ACTOR_SELF, 8, LW(2))
    EVT_IF_NE(LW(2), 0)
        EVT_EXEC_WAIT(DoDeath)
    EVT_ELSE
        EVT_CALL(SetActorVar, ACTOR_SELF, 8, 1)
        EVT_CALL(GetActorPos, ACTOR_SELF, LW(7), LW(8), LW(9))
        EVT_ADD(LW(8), 20)
        EVT_CALL(PlayEffect, EFFECT_ID_4B, 2, LW(7), LW(8), LW(9), EVT_FLOAT(1.0), 150, 0, 0, 0, 0, 0, 0, 0)
        EVT_SUB(LW(7), 14)
        EVT_SUB(LW(8), 4)
        EVT_CALL(PlayEffect, EFFECT_ID_4B, 0, LW(7), LW(8), LW(9), EVT_FLOAT(1.0), 150, 0, 0, 0, 0, 0, 0, 0)
        EVT_ADD(LW(7), 28)
        EVT_CALL(PlayEffect, EFFECT_ID_4B, 1, LW(7), LW(8), LW(9), EVT_FLOAT(1.0), 150, 0, 0, 0, 0, 0, 0, 0)
        EVT_CALL(SetActorVar, ACTOR_SELF, 8, 2)
        EVT_CALL(SetPartFlagBits, ACTOR_SELF, 3, ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET, 1)
        EVT_CALL(SetPartFlagBits, ACTOR_SELF, 4, ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET, 1)
        EVT_CALL(SetPartFlagBits, ACTOR_SELF, 5, ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET, 1)
        EVT_EXEC_WAIT(DoDeath)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(80229C40) = {
    EVT_CALL(SetAnimation, ACTOR_SELF, 2, NPC_ANIM_sky_guy_Palette_00_Anim_2)
    EVT_CALL(SetAnimation, ACTOR_SELF, 3, NPC_ANIM_sky_guy_Palette_00_Anim_13)
    EVT_CALL(SetAnimation, ACTOR_SELF, 4, NPC_ANIM_sky_guy_Palette_00_Anim_12)
    EVT_CALL(SetAnimation, ACTOR_SELF, 5, NPC_ANIM_sky_guy_Palette_00_Anim_14)
    EVT_RETURN
    EVT_END
};

EvtScript N(80229CB0) = {
    EVT_CALL(MakeLerp, 100, 80, 7, 5)
    EVT_LABEL(0)
    EVT_CALL(UpdateLerp)
    EVT_DIVF(LW(0), EVT_FLOAT(100.0))
    EVT_SETF(LW(2), EVT_FLOAT(2.0))
    EVT_SUBF(LW(2), LW(0))
    EVT_CALL(SetPartScale, ACTOR_SELF, 3, LW(2), LW(0), EVT_FLOAT(1.0))
    EVT_CALL(SetPartScale, ACTOR_SELF, 4, LW(2), LW(0), EVT_FLOAT(1.0))
    EVT_CALL(SetPartScale, ACTOR_SELF, 5, LW(2), LW(0), EVT_FLOAT(1.0))
    EVT_WAIT_FRAMES(1)
    EVT_IF_EQ(LW(1), 1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_CALL(MakeLerp, 80, 100, 7, 8)
    EVT_LABEL(1)
    EVT_CALL(UpdateLerp)
    EVT_DIVF(LW(0), EVT_FLOAT(100.0))
    EVT_SETF(LW(2), EVT_FLOAT(2.0))
    EVT_SUBF(LW(2), LW(0))
    EVT_CALL(SetPartScale, ACTOR_SELF, 3, LW(2), LW(0), EVT_FLOAT(1.0))
    EVT_CALL(SetPartScale, ACTOR_SELF, 4, LW(2), LW(0), EVT_FLOAT(1.0))
    EVT_CALL(SetPartScale, ACTOR_SELF, 5, LW(2), LW(0), EVT_FLOAT(1.0))
    EVT_WAIT_FRAMES(1)
    EVT_IF_EQ(LW(1), 1)
        EVT_GOTO(1)
    EVT_END_IF
    EVT_CALL(SetPartScale, ACTOR_SELF, 3, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
    EVT_CALL(SetPartScale, ACTOR_SELF, 4, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
    EVT_CALL(SetPartScale, ACTOR_SELF, 5, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
    EVT_RETURN
    EVT_END
};

#include "common/StartRumbleWithParams.inc.c"

EvtScript N(80229F08) = {
    EVT_CALL(GetLastElement, LW(0))
    EVT_SET(LW(0), 65536)
    EVT_IF_FLAG(LW(0), DAMAGE_TYPE_FIRE | DAMAGE_TYPE_BLAST | DAMAGE_TYPE_4000 | DAMAGE_TYPE_SPINY_SURGE)
        EVT_CALL(func_8027D32C, ACTOR_SELF)
        EVT_THREAD
            EVT_WAIT_FRAMES(20)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x2E1)
        EVT_END_THREAD
        EVT_CALL(SetAnimation, ACTOR_SELF, 3, NPC_ANIM_sky_guy_Palette_00_Anim_2E)
        EVT_CALL(SetAnimation, ACTOR_SELF, 4, NPC_ANIM_sky_guy_Palette_00_Anim_2D)
        EVT_CALL(SetAnimation, ACTOR_SELF, 5, NPC_ANIM_sky_guy_Palette_00_Anim_2F)
        EVT_WAIT_FRAMES(30)
        EVT_CALL(SetPartFlagBits, ACTOR_SELF, 3, ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET, 1)
        EVT_CALL(SetPartFlagBits, ACTOR_SELF, 4, ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET, 1)
        EVT_CALL(SetPartFlagBits, ACTOR_SELF, 5, ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET, 1)
        EVT_CALL(SetActorVar, ACTOR_SELF, 8, 2)
        EVT_WAIT_FRAMES(15)
        EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
        EVT_CALL(SetAnimation, ACTOR_SELF, 2, NPC_ANIM_sky_guy_Palette_00_Anim_0)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x263)
        EVT_CALL(PlayEffect, EFFECT_ID_10, 2, 0, LW(0), LW(1), LW(2), 24, 0, 25, 0, 0, 0, 0, 0)
        EVT_WAIT_FRAMES(25)
        EVT_CALL(SetAnimation, ACTOR_SELF, 2, NPC_ANIM_sky_guy_Palette_00_Anim_6)
        EVT_WAIT_FRAMES(30)
        EVT_CALL(SetAnimation, ACTOR_SELF, 2, NPC_ANIM_sky_guy_Palette_00_Anim_6)
        EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.5))
        EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
        EVT_SET(LW(1), 0)
        EVT_CALL(SetHomePos, ACTOR_SELF, LW(0), LW(1), LW(2))
        EVT_CALL(SetActorSounds, ACTOR_SELF, 2, 769, 0)
        EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
        EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
        EVT_CALL(N(StartRumbleWithParams), 120, 10)
        EVT_THREAD
            EVT_CALL(ShakeCam, 1, 0, 5, EVT_FLOAT(0.5))
        EVT_END_THREAD
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x20E4)
        EVT_CALL(ResetActorSounds, ACTOR_SELF, 2)
        EVT_CALL(SetPartFlags, ACTOR_SELF, 2, ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_4 | ACTOR_PART_FLAG_NO_TARGET)
        EVT_CALL(SetPartFlags, ACTOR_SELF, 1, ACTOR_PART_FLAG_4 | ACTOR_PART_FLAG_MULTI_TARGET)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_shy_guy_Palette_00_Anim_12)
        EVT_CALL(PlayEffect, EFFECT_ID_06, 3, LW(0), LW(1), LW(2), 0, 0, 0, 0, 0, 0, 0, 0, 0)
        EVT_WAIT_FRAMES(40)
        EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_FLYING, 0)
        EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_ADDR(N(takeTurn_8022CA9C)))
        EVT_CALL(BindIdle, ACTOR_SELF, EVT_ADDR(N(idle_8022B19C)))
        EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_ADDR(N(handleEvent_8022B310)))
        EVT_CALL(SetActorType, ACTOR_SELF, ACTOR_TYPE_SHY_GUY)
        EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_1000, 1)
        EVT_CALL(HPBarToHome, ACTOR_SELF)
        EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
    EVT_ELSE
        EVT_EXEC_WAIT(N(80229CB0))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(handleEvent_8022A398) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LW(0))
    EVT_SWITCH(LW(0))
        EVT_CASE_EQ(EVENT_HIT_COMBO)
            EVT_CALL(func_8026E914, LW(0), LW(1))
            EVT_IF_GE(LW(1), 3)
                EVT_EXEC_WAIT(N(80229CB0))
            EVT_ELSE
                EVT_SET_CONST(LW(0), 2)
                EVT_SET_CONST(LW(1), NPC_ANIM_sky_guy_Palette_00_Anim_6)
                EVT_EXEC_WAIT(DoNormalHit)
            EVT_END_IF
        EVT_CASE_EQ(EVENT_HIT)
            EVT_CALL(func_8026E914, LW(0), LW(1))
            EVT_IF_GE(LW(1), 3)
                EVT_EXEC_WAIT(N(80229CB0))
                EVT_EXEC_WAIT(N(80229F08))
            EVT_ELSE
                EVT_SET_CONST(LW(0), 2)
                EVT_SET_CONST(LW(1), NPC_ANIM_sky_guy_Palette_00_Anim_6)
                EVT_EXEC_WAIT(DoNormalHit)
            EVT_END_IF
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_SET_CONST(LW(0), 2)
            EVT_SET_CONST(LW(1), NPC_ANIM_sky_guy_Palette_00_Anim_9)
            EVT_SET_CONST(LW(2), NPC_ANIM_sky_guy_Palette_00_Anim_A)
            EVT_EXEC_WAIT(DoBurnHit)
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_SET_CONST(LW(0), 2)
            EVT_SET_CONST(LW(1), NPC_ANIM_sky_guy_Palette_00_Anim_9)
            EVT_SET_CONST(LW(2), NPC_ANIM_sky_guy_Palette_00_Anim_A)
            EVT_EXEC_WAIT(DoBurnHit)
            EVT_SET_CONST(LW(0), 2)
            EVT_SET_CONST(LW(1), NPC_ANIM_sky_guy_Palette_00_Anim_A)
            EVT_EXEC_WAIT(N(80229A34))
            EVT_RETURN
        EVT_CASE_EQ(EVENT_UNKNOWN_TRIGGER)
            EVT_CALL(func_8026E914, LW(0), LW(1))
            EVT_IF_GE(LW(1), 3)
                EVT_EXEC_WAIT(N(80229CB0))
            EVT_ELSE
                EVT_SET_CONST(LW(0), 2)
                EVT_SET_CONST(LW(1), NPC_ANIM_sky_guy_Palette_00_Anim_1)
                EVT_EXEC_WAIT(DoImmune)
            EVT_END_IF
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
        EVT_CASE_OR_EQ(EVENT_AIR_LIFT_FAILED)
            EVT_CALL(func_8026E914, LW(0), LW(1))
            EVT_IF_GE(LW(1), 3)
                EVT_EXEC_WAIT(N(80229CB0))
            EVT_ELSE
                EVT_SET_CONST(LW(0), 2)
                EVT_SET_CONST(LW(1), NPC_ANIM_sky_guy_Palette_00_Anim_1)
                EVT_EXEC_WAIT(DoImmune)
            EVT_END_IF
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_SET_CONST(LW(0), 2)
            EVT_SET_CONST(LW(1), NPC_ANIM_sky_guy_Palette_00_Anim_6)
            EVT_EXEC_WAIT(DoNormalHit)
            EVT_WAIT_FRAMES(10)
            EVT_SET_CONST(LW(0), 2)
            EVT_SET_CONST(LW(1), NPC_ANIM_sky_guy_Palette_00_Anim_6)
            EVT_EXEC_WAIT(N(80229A34))
            EVT_RETURN
        EVT_CASE_EQ(EVENT_BEGIN_FIRST_STRIKE)
            EVT_CALL(SetActorPos, ACTOR_SELF, 20, 0, 0)
            EVT_CALL(HPBarToCurrent, ACTOR_SELF)
        EVT_CASE_EQ(EVENT_END_FIRST_STRIKE)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
            EVT_CALL(SetAnimation, ACTOR_SELF, 2, NPC_ANIM_sky_guy_Palette_00_Anim_3)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
            EVT_CALL(FlyToGoal, ACTOR_SELF, 0, 1, 0)
            EVT_CALL(SetAnimation, ACTOR_SELF, 2, NPC_ANIM_sky_guy_Palette_00_Anim_1)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
            EVT_CALL(HPBarToHome, ACTOR_SELF)
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_SET_CONST(LW(0), 2)
            EVT_SET_CONST(LW(1), NPC_ANIM_sky_guy_Palette_00_Anim_1)
            EVT_EXEC_WAIT(DoRecover)
        EVT_CASE_EQ(EVENT_SCARE_AWAY)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 3, ACTOR_PART_FLAG_100000, 0)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 4, ACTOR_PART_FLAG_100000, 0)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 5, ACTOR_PART_FLAG_100000, 0)
            EVT_CALL(SetAnimation, ACTOR_SELF, 3, NPC_ANIM_sky_guy_Palette_00_Anim_1F)
            EVT_CALL(SetAnimation, ACTOR_SELF, 4, NPC_ANIM_sky_guy_Palette_00_Anim_1E)
            EVT_CALL(SetAnimation, ACTOR_SELF, 5, NPC_ANIM_sky_guy_Palette_00_Anim_20)
            EVT_SET_CONST(LW(0), 2)
            EVT_SET_CONST(LW(1), NPC_ANIM_sky_guy_Palette_00_Anim_3)
            EVT_SET_CONST(LW(2), NPC_ANIM_sky_guy_Palette_00_Anim_6)
            EVT_EXEC_WAIT(DoScareAway)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_BEGIN_AIR_LIFT)
            EVT_SET_CONST(LW(0), 2)
            EVT_SET_CONST(LW(1), NPC_ANIM_sky_guy_Palette_00_Anim_3)
            EVT_EXEC_WAIT(DoAirLift)
        EVT_CASE_EQ(EVENT_BLOW_AWAY)
            EVT_SET_CONST(LW(0), 2)
            EVT_SET_CONST(LW(1), NPC_ANIM_sky_guy_Palette_00_Anim_7)
            EVT_EXEC_WAIT(DoBlowAway)
            EVT_RETURN
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_EXEC_WAIT(N(80229C40))
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(takeTurn_8022A9D0) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetBattlePhase, LW(0))
    EVT_IF_EQ(LW(0), PHASE_FIRST_STRIKE)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
        EVT_CALL(MoveBattleCamOver, 1)
    EVT_END_IF
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x2E7)
    EVT_CALL(SetAnimation, ACTOR_SELF, 2, NPC_ANIM_sky_guy_Palette_00_Anim_8)
    EVT_WAIT_FRAMES(12)
    EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_ADD(LW(1), 20)
    EVT_ADD(LW(2), 2)
    EVT_CALL(SetPartPos, ACTOR_SELF, 6, LW(0), LW(1), LW(2))
    EVT_CALL(SetAnimation, ACTOR_SELF, 6, NPC_ANIM_sky_guy_Palette_00_Anim_B)
    EVT_WAIT_FRAMES(12)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, 6, ACTOR_PART_FLAG_INVISIBLE, 0)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x2E8)
    EVT_CALL(SetPartSounds, ACTOR_SELF, 6, 2, 0, 0)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(0), DAMAGE_TYPE_NO_CONTACT, 0, 3, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_SWITCH(LW(0))
        EVT_CASE_EQ(HIT_RESULT_MISS)
            EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_SUB(LW(0), 120)
            EVT_SET(LW(1), 0)
            EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, 6, EVT_FLOAT(12.0))
            EVT_CALL(SetPartJumpGravity, ACTOR_SELF, 6, EVT_FLOAT(0.1))
            EVT_CALL(JumpPartTo, ACTOR_SELF, 6, LW(0), LW(1), LW(2), 0, 1)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 6, ACTOR_PART_FLAG_INVISIBLE, 1)
            EVT_EXEC_WAIT(N(80229C40))
            EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_CASE_EQ(HIT_RESULT_LUCKY)
            EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_SUB(LW(0), 50)
            EVT_SET(LW(1), -5)
            EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, 6, EVT_FLOAT(14.0))
            EVT_CALL(SetPartJumpGravity, ACTOR_SELF, 6, EVT_FLOAT(0.1))
            EVT_CALL(FlyPartTo, ACTOR_SELF, 6, LW(0), LW(1), LW(2), 0, 30, 0)
            EVT_CALL(SetAnimation, ACTOR_SELF, 2, NPC_ANIM_sky_guy_Palette_00_Anim_7)
            EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(0), DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_CALL(GetActorPos, ACTOR_PLAYER, LW(0), LW(1), LW(2))
            EVT_SUB(LW(0), 65)
            EVT_SET(LW(1), -5)
            EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, 6, EVT_FLOAT(6.0))
            EVT_CALL(SetPartJumpGravity, ACTOR_SELF, 6, EVT_FLOAT(0.1))
            EVT_CALL(FlyPartTo, ACTOR_SELF, 6, LW(0), LW(1), LW(2), 0, 15, 0)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 6, ACTOR_PART_FLAG_INVISIBLE, 1)
            EVT_EXEC_WAIT(N(80229C40))
            EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
    EVT_END_SWITCH
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, 6, EVT_FLOAT(14.0))
    EVT_CALL(SetPartJumpGravity, ACTOR_SELF, 6, EVT_FLOAT(0.1))
    EVT_CALL(FlyPartTo, ACTOR_SELF, 6, LW(0), LW(1), LW(2), 0, 15, 0)
    EVT_WAIT_FRAMES(2)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LW(15), DAMAGE_TYPE_NO_CONTACT, 0, 0, 3, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_SWITCH(LW(15))
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_QUAKE_IMMUNE)
            EVT_CALL(GetActorPos, ACTOR_PLAYER, LW(0), LW(1), LW(2))
            EVT_SUB(LW(0), 55)
            EVT_SET(LW(1), 0)
            EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, 6, EVT_FLOAT(6.0))
            EVT_CALL(SetPartJumpGravity, ACTOR_SELF, 6, EVT_FLOAT(0.1))
            EVT_CALL(FlyPartTo, ACTOR_SELF, 6, LW(0), LW(1), LW(2), 0, 25, 0)
            EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, 6, EVT_FLOAT(4.0))
            EVT_SUB(LW(0), 20)
            EVT_CALL(FlyPartTo, ACTOR_SELF, 6, LW(0), LW(1), LW(2), 0, 21, 0)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 6, ACTOR_PART_FLAG_INVISIBLE, 1)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_EXEC_WAIT(N(80229C40))
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

s32 N(idleAnimations_8022B104)[] = {
    STATUS_NORMAL,    NPC_ANIM_shy_guy_Palette_00_Anim_1,
    STATUS_STONE,     NPC_ANIM_shy_guy_Palette_00_Anim_0,
    STATUS_SLEEP,     NPC_ANIM_shy_guy_Palette_00_Anim_12,
    STATUS_POISON,    NPC_ANIM_shy_guy_Palette_00_Anim_1,
    STATUS_STOP,      NPC_ANIM_shy_guy_Palette_00_Anim_0,
    STATUS_STATIC,    NPC_ANIM_shy_guy_Palette_00_Anim_1,
    STATUS_PARALYZE,  NPC_ANIM_shy_guy_Palette_00_Anim_0,
    STATUS_DIZZY,     NPC_ANIM_shy_guy_Palette_00_Anim_13,
    STATUS_FEAR,      NPC_ANIM_shy_guy_Palette_00_Anim_13,
    STATUS_END,
};

EvtScript N(8022B150) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_ADDR(N(takeTurn_8022CA9C)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_ADDR(N(idle_8022B19C)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_ADDR(N(handleEvent_8022B310)))
    EVT_RETURN
    EVT_END
};

#include "common/UnkBattleFunc1.inc.c"

EvtScript N(idle_8022B19C) = {
    EVT_LABEL(0)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(0))
    EVT_IF_FLAG(LW(0), STATUS_FLAG_SLEEP)
        EVT_CALL(SetTargetOffset, ACTOR_SELF, 1, -4, 14)
        EVT_CALL(func_8027D4C8, ACTOR_SELF, 1, 0, 0)
        EVT_CALL(N(UnkBattleFunc1), -10, 13, 10, 13)
    EVT_ELSE
        EVT_CALL(SetTargetOffset, ACTOR_SELF, 1, 0, 24)
        EVT_CALL(func_8027D4C8, ACTOR_SELF, 1, -1, -10)
        EVT_CALL(N(UnkBattleFunc1), -10, 20, 10, 20)
    EVT_END_IF
    EVT_WAIT_FRAMES(1)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(8022B2AC) = {
    EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
    EVT_SET_CONST(LW(0), 1)
    EVT_SET_CONST(LW(1), NPC_ANIM_shy_guy_Palette_00_Anim_3)
    EVT_EXEC_WAIT(DoReturnHome)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_shy_guy_Palette_00_Anim_1)
    EVT_RETURN
    EVT_END
};

EvtScript N(handleEvent_8022B310) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LW(0))
    EVT_SWITCH(LW(0))
        EVT_CASE_OR_EQ(EVENT_HIT_COMBO)
        EVT_CASE_OR_EQ(EVENT_HIT)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_shy_guy_Palette_00_Anim_C)
            EVT_EXEC_WAIT(DoNormalHit)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_shy_guy_Palette_00_Anim_D)
            EVT_SET_CONST(LW(2), NPC_ANIM_shy_guy_Palette_00_Anim_E)
            EVT_EXEC_WAIT(DoBurnHit)
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_shy_guy_Palette_00_Anim_D)
            EVT_SET_CONST(LW(2), NPC_ANIM_shy_guy_Palette_00_Anim_E)
            EVT_EXEC_WAIT(DoBurnHit)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_shy_guy_Palette_00_Anim_E)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SPIN_SMASH_HIT)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_shy_guy_Palette_00_Anim_C)
            EVT_EXEC_WAIT(DoSpinSmashHit)
        EVT_CASE_EQ(EVENT_SPIN_SMASH_DEATH)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_shy_guy_Palette_00_Anim_C)
            EVT_EXEC_WAIT(DoSpinSmashHit)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_shy_guy_Palette_00_Anim_C)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SHOCK_HIT)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_shy_guy_Palette_00_Anim_C)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_shy_guy_Palette_00_Anim_C)
            EVT_EXEC_WAIT(DoJumpBack)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
            EVT_EXEC_WAIT(N(8022B2AC))
        EVT_CASE_EQ(EVENT_SHOCK_DEATH)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_shy_guy_Palette_00_Anim_C)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_shy_guy_Palette_00_Anim_C)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_OR_EQ(EVENT_UNKNOWN_TRIGGER)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
        EVT_CASE_OR_EQ(EVENT_AIR_LIFT_FAILED)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_shy_guy_Palette_00_Anim_1)
            EVT_EXEC_WAIT(DoImmune)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_shy_guy_Palette_00_Anim_C)
            EVT_EXEC_WAIT(DoNormalHit)
            EVT_WAIT_FRAMES(10)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_shy_guy_Palette_00_Anim_C)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_shy_guy_Palette_00_Anim_1)
            EVT_EXEC_WAIT(DoRecover)
        EVT_CASE_EQ(EVENT_SCARE_AWAY)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_shy_guy_Palette_00_Anim_3)
            EVT_SET_CONST(LW(2), NPC_ANIM_shy_guy_Palette_00_Anim_14)
            EVT_EXEC_WAIT(DoScareAway)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_BEGIN_AIR_LIFT)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_shy_guy_Palette_00_Anim_C)
            EVT_EXEC_WAIT(DoAirLift)
        EVT_CASE_EQ(EVENT_BLOW_AWAY)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_shy_guy_Palette_00_Anim_C)
            EVT_EXEC_WAIT(DoBlowAway)
            EVT_RETURN
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(8022B7EC) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_63)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(MoveBattleCamOver, 20)
    EVT_CALL(func_8024ECF8, -1, 1, 0)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_shy_guy_Palette_00_Anim_3)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_ADD(LW(0), 50)
    EVT_SET(LW(1), 0)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(0), 0, 0, 1, BS_FLAGS1_10)
    EVT_SWITCH(LW(0))
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_SET(LW(10), LW(0))
            EVT_CALL(SetActorSounds, ACTOR_SELF, 2, 751, 0)
            EVT_CALL(SetActorSounds, ACTOR_SELF, 0, 8378, 948)
            EVT_CALL(SetActorSounds, ACTOR_SELF, 4, 10, 0)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_shy_guy_Palette_00_Anim_4)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_shy_guy_Palette_00_Anim_5)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.5))
            EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_SUB(LW(0), 30)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
            EVT_IF_EQ(LW(10), HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(10), DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
            EVT_SUB(LW(0), 20)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
            EVT_WAIT_FRAMES(15)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
            EVT_CALL(AddActorDecoration, ACTOR_SELF, 1, 0, 2)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_shy_guy_Palette_00_Anim_4)
            EVT_EXEC_WAIT(DoReturnHome)
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, 1, 0)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_shy_guy_Palette_00_Anim_1)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_THREAD
        EVT_WAIT_FRAMES(3)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x2EF)
    EVT_END_THREAD
    EVT_CALL(SetActorSounds, ACTOR_SELF, 0, 8378, 948)
    EVT_CALL(SetActorSounds, ACTOR_SELF, 4, 10, 0)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_shy_guy_Palette_00_Anim_4)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_ADD(LW(0), 10)
    EVT_SET(LW(1), 0)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_shy_guy_Palette_00_Anim_5)
    EVT_WAIT_FRAMES(2)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LW(0), 0, 0, 0, 2, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_CALL(MoveBattleCamOver, 15)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_ADD(LW(0), 30)
    EVT_SET(LW(1), 0)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.8))
    EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_shy_guy_Palette_00_Anim_1)
    EVT_WAIT_FRAMES(8)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
    EVT_EXEC_WAIT(N(8022B2AC))
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(8022BF14) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_63)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(MoveBattleCamOver, 20)
    EVT_CALL(func_8024ECF8, -1, 1, 0)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x234)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_shy_guy_Palette_00_Anim_9)
    EVT_WAIT_FRAMES(20)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_shy_guy_Palette_00_Anim_3)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(3.0))
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_ADD(LW(0), 80)
    EVT_SET(LW(1), 0)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(SetActorSounds, ACTOR_SELF, 0, 8378, 948)
    EVT_CALL(SetActorSounds, ACTOR_SELF, 4, 10, 0)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_shy_guy_Palette_00_Anim_4)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(5.0))
    EVT_SUB(LW(0), 40)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(0), 0, 0, 1, BS_FLAGS1_10)
    EVT_SWITCH(LW(0))
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_SET(LW(10), LW(0))
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_shy_guy_Palette_00_Anim_9)
            EVT_THREAD
                EVT_WAIT_FRAMES(12)
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_shy_guy_Palette_00_Anim_A)
            EVT_END_THREAD
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.8))
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_SUB(LW(0), 10)
            EVT_SET(LW(1), 0)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 24, FALSE, TRUE, FALSE)
            EVT_IF_EQ(LW(10), HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(0), DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_shy_guy_Palette_00_Anim_5)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.5))
            EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_SUB(LW(0), 30)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
            EVT_SUB(LW(0), 20)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
            EVT_WAIT_FRAMES(15)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_CALL(MoveBattleCamOver, 15)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
            EVT_CALL(AddActorDecoration, ACTOR_SELF, 1, 0, 2)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_shy_guy_Palette_00_Anim_4)
            EVT_EXEC_WAIT(DoReturnHome)
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, 1, 0)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_shy_guy_Palette_00_Anim_1)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_shy_guy_Palette_00_Anim_9)
    EVT_THREAD
        EVT_WAIT_FRAMES(9)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_shy_guy_Palette_00_Anim_A)
    EVT_END_THREAD
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.8))
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 18, FALSE, TRUE, FALSE)
    EVT_WAIT_FRAMES(2)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LW(0), 0, 0, 0, 3, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_SWITCH(LW(0))
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_QUAKE_IMMUNE)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_CALL(MoveBattleCamOver, 15)
            EVT_THREAD
                EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 14, 0)
                EVT_SET(LW(3), 0)
                EVT_LOOP(20)
                    EVT_SUB(LW(3), 30)
                    EVT_IF_LT(LW(3), 0)
                        EVT_ADD(LW(3), 360)
                    EVT_END_IF
                    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, LW(3))
                    EVT_WAIT_FRAMES(1)
                EVT_END_LOOP
                EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
                EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
            EVT_END_THREAD
            EVT_CALL(GetBattleFlags, LW(0))
            EVT_IF_FLAG(LW(0), BS_FLAGS1_ATK_BLOCKED)
                EVT_GOTO(1)
            EVT_END_IF
            EVT_CALL(GetLastDamage, ACTOR_PLAYER, LW(0))
            EVT_IF_EQ(LW(0), 0)
                EVT_GOTO(1)
            EVT_END_IF
            EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_ADD(LW(0), 40)
            EVT_SET(LW(1), 0)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.8))
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 20, FALSE, TRUE, FALSE)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x349)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x749)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_shy_guy_Palette_00_Anim_9)
            EVT_WAIT_FRAMES(10)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_shy_guy_Palette_00_Anim_7)
            EVT_WAIT_FRAMES(15)
            EVT_GOTO(2)
            EVT_LABEL(1)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_ADD(LW(0), 40)
            EVT_SET(LW(1), 0)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.8))
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 20, FALSE, TRUE, FALSE)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x20E4)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_shy_guy_Palette_00_Anim_10)
            EVT_WAIT_FRAMES(10)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x20C3)
            EVT_CALL(AddActorDecoration, ACTOR_SELF, 1, 0, 2)
            EVT_CALL(RandInt, 100, LW(0))
            EVT_IF_LT(LW(0), 50)
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_shy_guy_Palette_00_Anim_11)
            EVT_ELSE
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_shy_guy_Palette_00_Anim_13)
            EVT_END_IF
            EVT_WAIT_FRAMES(25)
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, 1, 0)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
            EVT_LABEL(2)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_shy_guy_Palette_00_Anim_4)
            EVT_EXEC_WAIT(DoReturnHome)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_shy_guy_Palette_00_Anim_1)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(takeTurn_8022CA9C) = {
    EVT_CALL(RandInt, 1, LW(0))
    EVT_IF_EQ(LW(0), 0)
        EVT_EXEC_WAIT(N(8022B7EC))
    EVT_ELSE
        EVT_EXEC_WAIT(N(8022BF14))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};