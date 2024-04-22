#include "../area.h"

#include "sprite/npc/RetroBowser.h"
#include "sprite/npc/RetroFireball.h"

#define NAMESPACE A(retro_bowser)

extern s32 N(DefaultAnims)[];
extern EvtScript N(EVS_Init);
extern EvtScript N(EVS_Idle);
extern EvtScript N(EVS_TakeTurn);
extern EvtScript N(EVS_HandleEvent);
extern EvtScript N(EVS_HandlePhase);

enum N(ActorPartIDs) {
    PRT_MAIN            = 1,
    PRT_FIREBALL        = 2,
    PRT_HAMMER1          = 3,
    PRT_HAMMER2          = 4,
    PRT_HAMMER3          = 5,
};

enum N(ActorVars) {
    AVar_UseHammer        = 0,
};

enum N(ActorParams) {
    DMG_HAMMER   = 1,
    DMG_FIREBALL = 3,
};

s32 N(DefenseTable)[] = {
    ELEMENT_NORMAL,  0,
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

s32 N(FireballAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_RetroFireball_Idle,
    STATUS_END,
};

s32 N(FireballDefense)[] = {
    ELEMENT_NORMAL,   0,
    ELEMENT_END,
};

s32 N(HammerAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_RetroBowser_HammerRotate,
    STATUS_END,
};

s32 N(HammerDefense)[] = {
    ELEMENT_NORMAL,   0,
    ELEMENT_END,
};

ActorPartBlueprint N(ActorParts)[] = {
    {
        .flags = ACTOR_PART_FLAG_PRIMARY_TARGET,
        .index = PRT_MAIN,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 60 },
        .opacity = 255,
        .idleAnimations = N(DefaultAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 1, 7 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_DECORATIONS | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = PRT_FIREBALL,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(FireballAnims),
        .defenseTable = N(FireballDefense),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_DECORATIONS | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = PRT_HAMMER1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(HammerAnims),
        .defenseTable = N(HammerDefense),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_DECORATIONS | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = PRT_HAMMER2,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(HammerAnims),
        .defenseTable = N(HammerDefense),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_DECORATIONS | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = PRT_HAMMER3,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(HammerAnims),
        .defenseTable = N(HammerDefense),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = ACTOR_FLAG_NO_SHADOW,
    .type = ACTOR_TYPE_RETRO_BOWSER,
    .level = ACTOR_LEVEL_RETRO_BOWSER,
    .maxHP = 99,
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
    STATUS_KEY_NORMAL,    ANIM_RetroBowser_Idle,
    STATUS_KEY_STONE,     ANIM_RetroBowser_Idle,
    STATUS_KEY_SLEEP,     ANIM_RetroBowser_Idle,
    STATUS_KEY_POISON,    ANIM_RetroBowser_Idle,
    STATUS_KEY_STOP,      ANIM_RetroBowser_Idle,
    STATUS_KEY_STATIC,    ANIM_RetroBowser_Idle,
    STATUS_KEY_PARALYZE,  ANIM_RetroBowser_Idle,
    STATUS_KEY_DIZZY,     ANIM_RetroBowser_Idle,
    STATUS_KEY_FEAR,      ANIM_RetroBowser_Idle,
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
            SetConst(LVar1, ANIM_RetroBowser_OpenMouth)
            ExecWait(EVS_Enemy_Hit)
        EndCaseGroup
        CaseEq(EVENT_BURN_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_RetroBowser_OpenMouth)
            SetConst(LVar2, ANIM_RetroBowser_OpenMouth)
            ExecWait(EVS_Enemy_BurnHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_RetroBowser_OpenMouth)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_SHOCK_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_RetroBowser_OpenMouth)
            ExecWait(EVS_Enemy_ShockHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_RetroBowser_OpenMouth)
            ExecWait(EVS_Enemy_Knockback)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_RetroBowser_OpenMouth)
            ExecWait(EVS_Enemy_ReturnHome)
        CaseEq(EVENT_SHOCK_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_RetroBowser_OpenMouth)
            ExecWait(EVS_Enemy_ShockHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_RetroBowser_OpenMouth)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_RetroBowser_OpenMouth)
            ExecWait(EVS_Enemy_Hit)
            Wait(10)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_RetroBowser_OpenMouth)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_RECOVER_STATUS)
            // nothing
        CaseEq(EVENT_SCARE_AWAY)
            Call(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_FLYING, TRUE)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_RetroBowser_OpenMouth)
            SetConst(LVar2, ANIM_RetroBowser_OpenMouth)
            ExecWait(EVS_Enemy_ScareAway)
            Return
        CaseDefault
    EndSwitch
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

EvtScript N(EVS_DoFireballAttack) = {
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_RetroBowser_OpenMouth)
    Call(SetPartScale, ACTOR_SELF, PRT_FIREBALL, Float(0.8), Float(0.8), Float(0.8))
    Sub(LVar0, 25)
    Add(LVar1, 40)
    Sub(LVar2, 2)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_LAVA_PIRANHA_FIRE_BREATH)
    Call(SetPartPos, ACTOR_SELF, PRT_FIREBALL, LVar0, LVar1, LVar2)
    Call(SetPartFlagBits, ACTOR_SELF, PRT_FIREBALL, ACTOR_PART_FLAG_INVISIBLE, FALSE)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(SetPartMoveSpeed, ACTOR_SELF, PRT_FIREBALL, Float(6.0))
    Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(EnemyTestTarget, ACTOR_SELF, LVarA, DAMAGE_TYPE_NO_CONTACT|DAMAGE_TYPE_FIRE, 0, DMG_FIREBALL, 0)
    IfEq(LVarA, HIT_RESULT_MISS)
        Sub(LVar0, 20)
        Add(LVar1, 20)
        Call(FlyPartTo, ACTOR_SELF, PRT_FIREBALL, LVar0, LVar1, LVar2, 0, 0, EASING_LINEAR )
    Else
        Sub(LVar0, 5)
        Sub(LVar1, 8)
        Call(FlyPartTo, ACTOR_SELF, PRT_FIREBALL, LVar0, LVar1, LVar2, 0, 0, EASING_LINEAR )
        Call(EnemyDamageTarget, ACTOR_SELF, LVarA, DAMAGE_TYPE_NO_CONTACT|DAMAGE_TYPE_FIRE, 0, 0, DMG_FIREBALL, 0)
        Call(SetPartFlagBits, ACTOR_SELF, PRT_FIREBALL, ACTOR_PART_FLAG_INVISIBLE, TRUE)
    EndIf
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

EvtScript N(EVS_DoHammerAttack) = {
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Sub(LVar0, 25)
    Add(LVar1, 40)
    Sub(LVar2, 2)
    Call(SetPartScale, ACTOR_SELF, PRT_HAMMER1, Float(0.5), Float(0.5), Float(0.5))
    Call(SetPartScale, ACTOR_SELF, PRT_HAMMER2, Float(0.5), Float(0.5), Float(0.5))
    Call(SetPartScale, ACTOR_SELF, PRT_HAMMER3, Float(0.5), Float(0.5), Float(0.5))
    Call(SetPartPos, ACTOR_SELF, PRT_HAMMER1, LVar0, LVar1, LVar2)
    Call(SetPartPos, ACTOR_SELF, PRT_HAMMER2, LVar0, LVar1, LVar2)
    Call(SetPartPos, ACTOR_SELF, PRT_HAMMER3, LVar0, LVar1, LVar2)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(SetPartJumpGravity, ACTOR_SELF, PRT_HAMMER1, Float(1.8))
    Call(SetPartJumpGravity, ACTOR_SELF, PRT_HAMMER2, Float(1.8))
    Call(SetPartJumpGravity, ACTOR_SELF, PRT_HAMMER3, Float(1.8))
    Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(EnemyTestTarget, ACTOR_SELF, LVarA, DAMAGE_TYPE_NO_CONTACT|DAMAGE_TYPE_JUMP, 0, DMG_HAMMER, 0)
    IfEq(LVarA, HIT_RESULT_MISS)
        Sub(LVar0, 20)
        Add(LVar1, 20)
        Thread
            Call(SetPartFlagBits, ACTOR_SELF, PRT_HAMMER1, ACTOR_PART_FLAG_INVISIBLE, FALSE)
            Call(PlaySoundAtActor, ACTOR_SELF, SOUND_PARAKARRY_PREDIVE)
            Call(JumpPartTo, ACTOR_SELF, PRT_HAMMER1, LVar0, LVar1, LVar2, 15, 0)
            Call(SetPartFlagBits, ACTOR_SELF, PRT_HAMMER1, ACTOR_PART_FLAG_INVISIBLE, TRUE)
        EndThread
        Wait(10)
        Thread
            Call(SetPartFlagBits, ACTOR_SELF, PRT_HAMMER2, ACTOR_PART_FLAG_INVISIBLE, FALSE)
            Call(PlaySoundAtActor, ACTOR_SELF, SOUND_PARAKARRY_PREDIVE)
            Call(JumpPartTo, ACTOR_SELF, PRT_HAMMER2, LVar0, LVar1, LVar2, 15, 0)
            Call(SetPartFlagBits, ACTOR_SELF, PRT_HAMMER2, ACTOR_PART_FLAG_INVISIBLE, TRUE)
        EndThread
        Wait(10)
        Thread
            Call(SetPartFlagBits, ACTOR_SELF, PRT_HAMMER3, ACTOR_PART_FLAG_INVISIBLE, FALSE)
            Call(PlaySoundAtActor, ACTOR_SELF, SOUND_PARAKARRY_PREDIVE)
            Call(JumpPartTo, ACTOR_SELF, PRT_HAMMER3, LVar0, LVar1, LVar2, 15, 0)
            Call(SetPartFlagBits, ACTOR_SELF, PRT_HAMMER3, ACTOR_PART_FLAG_INVISIBLE, TRUE)
        EndThread
    Else
        Sub(LVar0, 5)
        Add(LVar1, 5)
        Thread
            Call(SetPartFlagBits, ACTOR_SELF, PRT_HAMMER1, ACTOR_PART_FLAG_INVISIBLE, FALSE)
            Call(PlaySoundAtActor, ACTOR_SELF, SOUND_PARAKARRY_PREDIVE)
            Call(JumpPartTo, ACTOR_SELF, PRT_HAMMER1, LVar0, LVar1, LVar2, 15, 0)
            Call(SetPartFlagBits, ACTOR_SELF, PRT_HAMMER1, ACTOR_PART_FLAG_INVISIBLE, TRUE)
            Call(EnemyDamageTarget, ACTOR_SELF, LVarA, DAMAGE_TYPE_NO_CONTACT|DAMAGE_TYPE_JUMP, 0, 0, DMG_HAMMER, 0)
        EndThread
        Wait(10)
        Thread
            Call(SetPartFlagBits, ACTOR_SELF, PRT_HAMMER2, ACTOR_PART_FLAG_INVISIBLE, FALSE)
            Call(PlaySoundAtActor, ACTOR_SELF, SOUND_PARAKARRY_PREDIVE)
            Call(JumpPartTo, ACTOR_SELF, PRT_HAMMER2, LVar0, LVar1, LVar2, 15, 0)
            Call(SetPartFlagBits, ACTOR_SELF, PRT_HAMMER2, ACTOR_PART_FLAG_INVISIBLE, TRUE)
            Call(EnemyDamageTarget, ACTOR_SELF, LVarA, DAMAGE_TYPE_NO_CONTACT|DAMAGE_TYPE_JUMP, 0, 0, DMG_HAMMER, 0)
        EndThread
        Wait(10)
        Thread
            Call(SetPartFlagBits, ACTOR_SELF, PRT_HAMMER3, ACTOR_PART_FLAG_INVISIBLE, FALSE)
            Call(PlaySoundAtActor, ACTOR_SELF, SOUND_PARAKARRY_PREDIVE)
            Call(JumpPartTo, ACTOR_SELF, PRT_HAMMER3, LVar0, LVar1, LVar2, 15, 0)
            Call(SetPartFlagBits, ACTOR_SELF, PRT_HAMMER3, ACTOR_PART_FLAG_INVISIBLE, TRUE)
            Call(EnemyDamageTarget, ACTOR_SELF, LVarA, DAMAGE_TYPE_NO_CONTACT|DAMAGE_TYPE_JUMP, 0, 0, DMG_HAMMER, 0)
        EndThread
    EndIf
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

EvtScript N(EVS_TakeTurn) = {
    Call(GetActorVar, ACTOR_SELF, AVar_UseHammer, LVar0)
    IfTrue(LVar0)
        Call(SetActorVar, ACTOR_SELF, AVar_UseHammer, FALSE)
        ExecWait(N(EVS_DoHammerAttack))
    Else
        Call(SetActorVar, ACTOR_SELF, AVar_UseHammer, TRUE)
        ExecWait(N(EVS_DoFireballAttack))
    EndIf
    Return
    End
};

EvtScript N(EVS_Init) = {
    Set(GB_BattlePhase, 1)
    Call(SetActorScale, ACTOR_SELF, Float(1.1), Float(1.1), Float(1.1))
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
