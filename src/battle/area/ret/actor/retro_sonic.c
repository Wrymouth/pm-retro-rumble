#include "../area.h"

#include "sprite/npc/RetroSonic.h"
#include "sprite/npc/RetroEmerald.h"

#define NAMESPACE A(retro_sonic)

extern s32 N(DefaultAnims)[];
extern EvtScript N(EVS_Init);
extern EvtScript N(EVS_Idle);
extern EvtScript N(EVS_TakeTurn);
extern EvtScript N(EVS_HandleEvent);
extern EvtScript N(EVS_HandlePhase);

enum N(ActorPartIDs) {
    PRT_MAIN            = 1,
    PRT_EMERALD         = 2,
};

enum N(ActorVars) {
    AVar_EmeraldsCollected    = 0,
};

enum N(ActorParams) {
    DMG_SPIN   = 3,
    DMG_JUMP   = 3,
};

s32 N(DefenseTable)[] = {
    ELEMENT_NORMAL,  0,
    ELEMENT_END,
};

s32 N(SuperDefenseTable)[] = {
    ELEMENT_NORMAL,  99,
    ELEMENT_END,
};


s32 N(StatusTable)[] = {
    STATUS_KEY_NORMAL,              0,
    STATUS_KEY_DEFAULT,             0,
    STATUS_KEY_SLEEP,               0,
    STATUS_KEY_POISON,              0,
    STATUS_KEY_FROZEN,              0,
    STATUS_KEY_DIZZY,               0,
    STATUS_KEY_FEAR,                0,
    STATUS_KEY_STATIC,              0,
    STATUS_KEY_PARALYZE,            0,
    STATUS_KEY_SHRINK,              0,
    STATUS_KEY_STOP,                0,
    STATUS_TURN_MOD_DEFAULT,        0,
    STATUS_TURN_MOD_SLEEP,          0,
    STATUS_TURN_MOD_POISON,         0,
    STATUS_TURN_MOD_FROZEN,         0,
    STATUS_TURN_MOD_DIZZY,          0,
    STATUS_TURN_MOD_FEAR,           0,
    STATUS_TURN_MOD_STATIC,         0,
    STATUS_TURN_MOD_PARALYZE,       0,
    STATUS_TURN_MOD_SHRINK,         0,
    STATUS_TURN_MOD_STOP,           0,
    STATUS_END,
};

s32 N(EmeraldAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_RetroEmerald_Blue_Blue,
    STATUS_KEY_STONE,     ANIM_RetroEmerald_Blue_Blue,
    STATUS_KEY_SLEEP,     ANIM_RetroEmerald_Blue_Blue,
    STATUS_KEY_POISON,    ANIM_RetroEmerald_Blue_Blue,
    STATUS_KEY_STOP,      ANIM_RetroEmerald_Blue_Blue,
    STATUS_KEY_STATIC,    ANIM_RetroEmerald_Blue_Blue,
    STATUS_KEY_PARALYZE,  ANIM_RetroEmerald_Blue_Blue,
    STATUS_KEY_DIZZY,     ANIM_RetroEmerald_Blue_Blue,
    STATUS_KEY_FEAR,      ANIM_RetroEmerald_Blue_Blue,
    STATUS_END,
};

ActorPartBlueprint N(ActorParts)[] = {
    {
        .flags = 0,
        .index = PRT_MAIN,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 30 },
        .opacity = 255,
        .idleAnimations = N(DefaultAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 1, 7 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_DECORATIONS | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = PRT_EMERALD,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 30 },
        .opacity = 255,
        .idleAnimations = N(EmeraldAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 1, 7 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = 0,
    .type = ACTOR_TYPE_RETRO_SONIC,
    .level = ACTOR_LEVEL_RETRO_SONIC,
    .maxHP = 20,
    .partCount = ARRAY_COUNT(N(ActorParts)),
    .partsData = N(ActorParts),
    .initScript = &N(EVS_Init),
    .statusTable = N(StatusTable),
    .escapeChance = 100,
    .airLiftChance = 0,
    .hurricaneChance = 0,
    .spookChance = 0,
    .upAndAwayChance = 0,
    .spinSmashReq = 0,
    .powerBounceChance = 100,
    .coinReward = 0,
    .size = { 22, 18 },
    .healthBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 20 },
    .statusTextOffset = { 10, 20 },
};

s32 N(DefaultAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_RetroSonic_Idle,
    STATUS_KEY_STONE,     ANIM_RetroSonic_Idle,
    STATUS_KEY_SLEEP,     ANIM_RetroSonic_Idle,
    STATUS_KEY_POISON,    ANIM_RetroSonic_Idle,
    STATUS_KEY_STOP,      ANIM_RetroSonic_Idle,
    STATUS_KEY_STATIC,    ANIM_RetroSonic_Idle,
    STATUS_KEY_PARALYZE,  ANIM_RetroSonic_Idle,
    STATUS_KEY_DIZZY,     ANIM_RetroSonic_Idle,
    STATUS_KEY_FEAR,      ANIM_RetroSonic_Idle,
    STATUS_END,
};

#include "common/battle/SetAbsoluteStatusOffsets.inc.c"

EvtScript N(EVS_Idle) = {
    Return
    End
};

EvtScript N(EVS_HandleEvent) = {
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(GetLastEvent, ACTOR_SELF, LVar0)
    Switch(LVar0)
        CaseOrEq(EVENT_HIT_COMBO)
        CaseOrEq(EVENT_HIT)
        CaseOrEq(EVENT_IMMUNE)
        CaseOrEq(EVENT_ZERO_DAMAGE)
        CaseOrEq(EVENT_FLIP_TRIGGER)
        CaseOrEq(EVENT_BURN_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_RetroSonic_Hurt)
            ExecWait(EVS_Enemy_Hit)
        EndCaseGroup
        CaseEq(EVENT_BURN_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_RetroSonic_Hurt)
            SetConst(LVar2, ANIM_RetroSonic_Hurt)
            ExecWait(EVS_Enemy_BurnHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_RetroSonic_Hurt)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_SHOCK_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_RetroSonic_Hurt)
            ExecWait(EVS_Enemy_ShockHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_RetroSonic_Hurt)
            ExecWait(EVS_Enemy_Knockback)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_RetroSonic_Walk)
            ExecWait(EVS_Enemy_ReturnHome)
        CaseEq(EVENT_SHOCK_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_RetroSonic_Hurt)
            ExecWait(EVS_Enemy_ShockHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_RetroSonic_Hurt)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_RetroSonic_Hurt)
            ExecWait(EVS_Enemy_Hit)
            Wait(10)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_RetroSonic_Hurt)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_RECOVER_STATUS)
            // nothing
        CaseEq(EVENT_SCARE_AWAY)
            Call(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_FLYING, TRUE)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_RetroSonic_Hurt)
            SetConst(LVar2, ANIM_RetroSonic_Run)
            ExecWait(EVS_Enemy_ScareAway)
            Return
        CaseDefault
    EndSwitch
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

EvtScript N(EVS_SpinDashAttack) = {
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

EvtScript N(EVS_JumpAttack) = {
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

EvtScript N(EVS_TransformSuper) = {
    Call(SetDefenseTable, ACTOR_SELF, PRT_MAIN, Ref(N(SuperDefenseTable)))
    Call(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_DAMAGE_IMMUNE, TRUE)
    Return
    End
};

EvtScript N(EVS_GiveEmerald) = {
    Call(GetPartPos, ACTOR_SELF, PRT_MAIN, LVar0, LVar1, LVar2)
    Add(LVar1, 90)
    Call(SetPartPos, ACTOR_SELF, PRT_EMERALD, LVar0, LVar1, LVar2)
    Call(GetActorVar, ACTOR_SELF, AVar_EmeraldsCollected, LVarA)
    IfEq(LVarA, 7)
        Return
    EndIf
    Switch(LVarA)
        CaseEq(0)
            Call(SetAnimation, ACTOR_SELF, PRT_EMERALD, ANIM_RetroEmerald_Blue)
        CaseEq(1)
            Call(SetAnimation, ACTOR_SELF, PRT_EMERALD, ANIM_RetroEmerald_Green)
        CaseEq(2)
            Call(SetAnimation, ACTOR_SELF, PRT_EMERALD, ANIM_RetroEmerald_Ice)
        CaseEq(3)
            Call(SetAnimation, ACTOR_SELF, PRT_EMERALD, ANIM_RetroEmerald_Pink)
        CaseEq(4)
            Call(SetAnimation, ACTOR_SELF, PRT_EMERALD, ANIM_RetroEmerald_Red)
        CaseEq(5)
            Call(SetAnimation, ACTOR_SELF, PRT_EMERALD, ANIM_RetroEmerald_White)
        CaseEq(6)
            Call(SetAnimation, ACTOR_SELF, PRT_EMERALD, ANIM_RetroEmerald_Yellow)
            ExecWait(N(EVS_TransformSuper))
    EndSwitch
    Add(LVarA, 1)
    Call(SetPartFlagBits, ACTOR_SELF, PRT_EMERALD, ACTOR_PART_FLAG_INVISIBLE, FALSE)
    Wait(30)
    Call(GetPartPos, ACTOR_SELF, PRT_MAIN, LVar0, LVar1, LVar2)
    Call(FlyPartTo, ACTOR_SELF, PRT_EMERALD, LVar0, LVar1, LVar2, 30, 0, 0)
    Call(SetActorVar, ACTOR_SELF, AVar_EmeraldsCollected, LVarA)
    Call(SetPartFlagBits, ACTOR_SELF, PRT_EMERALD, ACTOR_PART_FLAG_INVISIBLE, TRUE)
    Return
    End
};

EvtScript N(EVS_TakeTurn) = {
    IfFalse(GB_BattlePhase)
        Return
    EndIf
    ExecWait(N(EVS_JumpAttack))

    ExecWait(N(EVS_GiveEmerald))

    Return
    End
};

EvtScript N(EVS_Init) = {
    // Call(SetPartFlagBits, ACTOR_SELF, PRT_MAIN, ACTOR_PART_FLAG_NO_TARGET, TRUE)
    // Call(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_INVISIBLE|ACTOR_FLAG_NO_HEALTH_BAR, TRUE)
    Call(SetPartScale, ACTOR_SELF, PRT_MAIN, Float(1.5), Float(1.5), Float(1.5))
    Call(SetPartScale, ACTOR_SELF, PRT_EMERALD, Float(0.5), Float(0.5), Float(0.5))
    Call(BindIdle, ACTOR_SELF, Ref(N(EVS_Idle)))
    Call(BindTakeTurn, ACTOR_SELF, Ref(N(EVS_TakeTurn)))
    Call(BindHandleEvent, ACTOR_SELF, Ref(N(EVS_HandleEvent)))
    Call(BindHandlePhase, ACTOR_SELF, Ref(N(EVS_HandlePhase)))
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

EvtScript N(EVS_HandlePhase) = {
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(GetBattlePhase, LVar0)
    Switch(LVar0)
        CaseEq(PHASE_PLAYER_BEGIN)
        CaseEq(PHASE_ENEMY_BEGIN)
    EndSwitch
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};
