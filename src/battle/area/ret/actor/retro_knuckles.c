#include "../area.h"

#include "sprite/npc/RetroKnuckles.h"

#define NAMESPACE A(retro_knuckles)

extern s32 N(DefaultAnims)[];
extern EvtScript N(EVS_Init);
extern EvtScript N(EVS_Idle);
extern EvtScript N(EVS_TakeTurn);
extern EvtScript N(EVS_HandleEvent);
extern EvtScript N(EVS_HandlePhase);

enum N(ActorPartIDs) {
    PRT_MAIN            = 1,
};

enum N(ActorVars) {
    AVar_AttackDamageAdd    = 0,
    AVar_UseCharge          = 1,
};

enum N(ActorParams) {
    DMG_GLIDE   = 3,
    DMG_JUMP   = 2,
};

s32 N(DefenseTable)[] = {
    ELEMENT_NORMAL,  0,
    ELEMENT_END,
};

s32 N(StatusTable)[] = {
    STATUS_KEY_NORMAL,              0,
    STATUS_KEY_DEFAULT,             0,
    STATUS_KEY_SLEEP,              40,
    STATUS_KEY_POISON,              0,
    STATUS_KEY_FROZEN,              0,
    STATUS_KEY_DIZZY,              40,
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
};

ActorBlueprint NAMESPACE = {
    .flags = 0,
    .type = ACTOR_TYPE_RETRO_KNUCKLES,
    .level = ACTOR_LEVEL_RETRO_KNUCKLES,
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
    STATUS_KEY_NORMAL,    ANIM_RetroKnuckles_Idle,
    STATUS_KEY_STONE,     ANIM_RetroKnuckles_Idle,
    STATUS_KEY_SLEEP,     ANIM_RetroKnuckles_Idle,
    STATUS_KEY_POISON,    ANIM_RetroKnuckles_Idle,
    STATUS_KEY_STOP,      ANIM_RetroKnuckles_Idle,
    STATUS_KEY_STATIC,    ANIM_RetroKnuckles_Idle,
    STATUS_KEY_PARALYZE,  ANIM_RetroKnuckles_Idle,
    STATUS_KEY_DIZZY,     ANIM_RetroKnuckles_Idle,
    STATUS_KEY_FEAR,      ANIM_RetroKnuckles_Idle,
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
            SetConst(LVar1, ANIM_RetroKnuckles_Hurt)
            ExecWait(EVS_Enemy_Hit)
        EndCaseGroup
        CaseEq(EVENT_BURN_DEATH)
            Set(GF_KnucklesDead, TRUE)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_RetroKnuckles_Hurt)
            SetConst(LVar2, ANIM_RetroKnuckles_Hurt)
            ExecWait(EVS_Enemy_BurnHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_RetroKnuckles_Hurt)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_SHOCK_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_RetroKnuckles_Hurt)
            ExecWait(EVS_Enemy_ShockHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_RetroKnuckles_Hurt)
            ExecWait(EVS_Enemy_Knockback)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_RetroKnuckles_Idle)
            ExecWait(EVS_Enemy_ReturnHome)
        CaseEq(EVENT_SHOCK_DEATH)
            Set(GF_KnucklesDead, TRUE)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_RetroKnuckles_Hurt)
            ExecWait(EVS_Enemy_ShockHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_RetroKnuckles_Hurt)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_DEATH)
            Set(GF_KnucklesDead, TRUE)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_RetroKnuckles_Hurt)
            ExecWait(EVS_Enemy_Hit)
            Wait(10)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_RetroKnuckles_Hurt)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_RECOVER_STATUS)
            // nothing
        CaseEq(EVENT_SCARE_AWAY)
            Call(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_FLYING, TRUE)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_RetroKnuckles_Hurt)
            SetConst(LVar2, ANIM_RetroKnuckles_Idle)
            ExecWait(EVS_Enemy_ScareAway)
            Return
        CaseDefault
    EndSwitch
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

EvtScript N(EVS_JumpAttack) = {
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(SetActorJumpGravity, ACTOR_SELF, Float(0.8))
    Call(SetJumpAnimations, ACTOR_SELF, PRT_MAIN, ANIM_RetroKnuckles_Roll, ANIM_RetroKnuckles_Roll, ANIM_RetroKnuckles_Roll)
    Call(JumpToGoal, ACTOR_SELF, 30, TRUE, FALSE, FALSE)
    Call(EnemyDamageTarget, ACTOR_SELF, LVarA, DAMAGE_TYPE_JUMP, 0, 0, DMG_JUMP, 0)
    Call(SetActorJumpGravity, ACTOR_SELF, Float(0.6))
    Call(JumpToGoal, ACTOR_SELF, 30, TRUE, FALSE, FALSE)
    Call(EnemyDamageTarget, ACTOR_SELF, LVarA, DAMAGE_TYPE_JUMP, 0, 0, DMG_JUMP, 0)
    Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Add(LVar0, 50)
    Call(SetGoalPos, ACTOR_SELF, LVar0, 0, LVar2)
    Call(SetActorJumpGravity, ACTOR_SELF, Float(0.3))
    Call(JumpToGoal, ACTOR_SELF, 30, TRUE, FALSE, FALSE)
    Call(SetGoalToHome, ACTOR_SELF)
    Call(SetActorYaw, ACTOR_SELF, 180)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_RetroKnuckles_Walk)
    Call(SetActorSpeed, ACTOR_SELF, Float(8.0))
    Call(RunToGoal, ACTOR_SELF, 0, FALSE)
    Call(SetActorYaw, ACTOR_SELF, 0)

    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

EvtScript N(EVS_GlideAttack) = {
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Add(LVar0, 150)
    Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(SetActorYaw, ACTOR_SELF, 180)
    Call(SetActorSpeed, ACTOR_SELF, Float(7.0))
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_RetroKnuckles_Walk)
    Call(RunToGoal, ACTOR_SELF, 0, FALSE)
    Call(SetActorYaw, ACTOR_SELF, 0)
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Add(LVar1, 100)
    Call(SetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_RetroKnuckles_Glide)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Sub(LVar1, 20)
    Call(SetGoalPos, ACTOR_SELF, LVar0, 0, LVar2)
    Call(FlyToGoal, ACTOR_SELF, 0, 0, 0)
    Call(EnemyDamageTarget, ACTOR_SELF, LVarA, DAMAGE_TYPE_SMASH, 0, 0, DMG_GLIDE, 0)
    Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Add(LVar0, 50)
    Call(SetGoalPos, ACTOR_SELF, LVar0, 0, LVar2)
    Call(SetJumpAnimations, ACTOR_SELF, PRT_MAIN, ANIM_RetroKnuckles_Roll, ANIM_RetroKnuckles_Roll, ANIM_RetroKnuckles_Roll)
    Call(SetActorJumpGravity, ACTOR_SELF, Float(0.5))
    Call(JumpToGoal, ACTOR_SELF, 15, TRUE, FALSE, FALSE)
    Call(SetActorYaw, ACTOR_SELF, 180)
    Call(SetGoalToHome, ACTOR_SELF)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_RetroKnuckles_Walk)
    Call(RunToGoal, ACTOR_SELF, 0, FALSE)
    Call(SetActorYaw, ACTOR_SELF, 0)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

EvtScript N(EVS_ChargeAttack) = {
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(SetTargetActor, ACTOR_SELF, ACTOR_SELF)

    Call(UseBattleCamPreset, BTL_CAM_PRESET_14)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Call(MoveBattleCamOver, 20)
    Wait(20)
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Add(LVar1, 10)
    PlayEffect(EFFECT_ENERGY_IN_OUT, 6, LVar0, LVar1, LVar2, Float(1.0), 45, 0)
    Thread
        Wait(10)
        Call(PlaySoundAtActor, LVar8, SOUND_MAGIKOOPA_POWER_UP)
    EndThread
    Thread
        Call(FreezeBattleState, TRUE)
        Call(BoostAttack, ACTOR_SELF, 1)
        Call(FreezeBattleState, FALSE)
    EndThread
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Call(MoveBattleCamOver, 20)

    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

EvtScript N(EVS_TakeTurn) = {
    IfNe(GB_BattlePhase, 2)
        Return
    EndIf
    Call(RandInt, 100, LVar0)
    IfGt(LVar0, 49)
        ExecWait(N(EVS_JumpAttack))
    Else
        ExecWait(N(EVS_GlideAttack))
    EndIf
    Call(GetActorVar, ACTOR_SELF, AVar_UseCharge, LVar0)
    IfTrue(LVar0)
        Call(SetActorVar, ACTOR_SELF, AVar_UseCharge, FALSE)
        ExecWait(N(EVS_ChargeAttack))
    Else
        Call(SetActorVar, ACTOR_SELF, AVar_UseCharge, TRUE)
    EndIf
    Return
    End
};

EvtScript N(EVS_Init) = {
    Call(SetPartFlagBits, ACTOR_SELF, PRT_MAIN, ACTOR_PART_FLAG_NO_TARGET, TRUE)
    Call(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_INVISIBLE|ACTOR_FLAG_NO_HEALTH_BAR, TRUE)
    Call(SetActorScale, ACTOR_SELF, Float(1.5), Float(1.5), Float(1.5))
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
