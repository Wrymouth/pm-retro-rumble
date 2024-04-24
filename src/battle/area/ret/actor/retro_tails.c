#include "../area.h"

#include "sprite/npc/RetroTails.h"
#include "sprite/npc/Mushroom.h"
#include "sprite/player.h"

#define NAMESPACE A(retro_tails)

extern s32 N(DefaultAnims)[];
extern EvtScript N(EVS_Init);
extern EvtScript N(EVS_Idle);
extern EvtScript N(EVS_TakeTurn);
extern EvtScript N(EVS_HandleEvent);
extern EvtScript N(EVS_HandlePhase);

enum N(ActorPartIDs) {
    PRT_MAIN            = 1,
    PRT_MUSHROOM        = 2,
};

enum N(ActorVars) {
    AVar_TurnsLeft    = 0,
};

enum N(ActorParams) {
    DMG_CARRY   = 3,
    DMG_JUMP   = 4,
    AMT_HEAL   = 5,
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

s32 N(MushroomAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_Mushroom_Still,
    STATUS_KEY_STONE,     ANIM_Mushroom_Still,
    STATUS_KEY_SLEEP,     ANIM_Mushroom_Still,
    STATUS_KEY_POISON,    ANIM_Mushroom_Still,
    STATUS_KEY_STOP,      ANIM_Mushroom_Still,
    STATUS_KEY_STATIC,    ANIM_Mushroom_Still,
    STATUS_KEY_PARALYZE,  ANIM_Mushroom_Still,
    STATUS_KEY_DIZZY,     ANIM_Mushroom_Still,
    STATUS_KEY_FEAR,      ANIM_Mushroom_Still,
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
        .index = PRT_MUSHROOM,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 30 },
        .opacity = 255,
        .idleAnimations = N(MushroomAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 1, 7 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = 0,
    .type = ACTOR_TYPE_RETRO_TAILS,
    .level = ACTOR_LEVEL_RETRO_TAILS,
    .maxHP = 30,
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
    STATUS_KEY_NORMAL,    ANIM_RetroTails_Idle,
    STATUS_KEY_STONE,     ANIM_RetroTails_Idle,
    STATUS_KEY_SLEEP,     ANIM_RetroTails_Idle,
    STATUS_KEY_POISON,    ANIM_RetroTails_Idle,
    STATUS_KEY_STOP,      ANIM_RetroTails_Idle,
    STATUS_KEY_STATIC,    ANIM_RetroTails_Idle,
    STATUS_KEY_PARALYZE,  ANIM_RetroTails_Idle,
    STATUS_KEY_DIZZY,     ANIM_RetroTails_Idle,
    STATUS_KEY_FEAR,      ANIM_RetroTails_Idle,
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
            SetConst(LVar1, ANIM_RetroTails_Hurt)
            ExecWait(EVS_Enemy_Hit)
        EndCaseGroup
        CaseEq(EVENT_BURN_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_RetroTails_Hurt)
            SetConst(LVar2, ANIM_RetroTails_Hurt)
            ExecWait(EVS_Enemy_BurnHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_RetroTails_Hurt)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_SHOCK_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_RetroTails_Hurt)
            ExecWait(EVS_Enemy_ShockHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_RetroTails_Hurt)
            ExecWait(EVS_Enemy_Knockback)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_RetroTails_Idle)
            ExecWait(EVS_Enemy_ReturnHome)
        CaseEq(EVENT_SHOCK_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_RetroTails_Hurt)
            ExecWait(EVS_Enemy_ShockHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_RetroTails_Hurt)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_RetroTails_Hurt)
            ExecWait(EVS_Enemy_Hit)
            Wait(10)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_RetroTails_Hurt)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_RECOVER_STATUS)
            // nothing
        CaseEq(EVENT_SCARE_AWAY)
            Call(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_FLYING, TRUE)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_RetroTails_Hurt)
            SetConst(LVar2, ANIM_RetroTails_Idle)
            ExecWait(EVS_Enemy_ScareAway)
            Return
        CaseDefault
    EndSwitch
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

API_CALLABLE(N(DetermineAttackOdds)) {
    Actor* sonic;
    Actor* knuckles;
    s16 sonicHp;
    s16 knucklesHp;

    sonicHp = 0;
    knucklesHp = 0;

    if (!evt_get_variable(script, GF_SonicDead)) {
        sonic = get_actor(ACTOR_ENEMY1);
        sonicHp = sonic->curHP;
    }
    if (!evt_get_variable(script, GF_KnucklesDead)) {
        knuckles = get_actor(ACTOR_ENEMY3);
        knucklesHp = knuckles->curHP;
    }

    if (evt_get_variable(script, GF_SonicDead) && evt_get_variable(script, GF_KnucklesDead)) {
        evt_set_variable(script, LVar1, 50);
        evt_set_variable(script, LVar2, 100);
    } else if (knucklesHp + sonicHp > 25 ) {
        evt_set_variable(script, LVar1, 40);
        evt_set_variable(script, LVar2, 80);
    } else {
        evt_set_variable(script, LVar1, 33);
        evt_set_variable(script, LVar2, 66);
    }
    return ApiStatus_DONE2;
}

EvtScript N(EVS_JumpAttack) = {
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)

    Call(SetJumpAnimations, ACTOR_SELF, PRT_MAIN, ANIM_RetroTails_RollUp, ANIM_RetroTails_RollDown, ANIM_RetroTails_RollUp)

    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(SetGoalPos, ACTOR_SELF, LVar0, 0, LVar2)
    Call(SetActorJumpGravity, ACTOR_SELF, Float(1.0))
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_QUICK_PLAYER_JUMP)
    Call(JumpToGoal, ACTOR_SELF, 20, TRUE, 0, 0)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_OBJECT_LAND)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(SetActorJumpGravity, ACTOR_SELF, Float(1.6))
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_QUICK_PLAYER_JUMP)
    Call(JumpToGoal, ACTOR_SELF, 20, TRUE, 0, 0)
    Call(EnemyDamageTarget, ACTOR_SELF, LVarA, DAMAGE_TYPE_JUMP, 0, 0, DMG_JUMP, 0)
    
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_RetroTails_Idle)
    Call(SetGoalToHome, ACTOR_SELF)
    Call(FlyToGoal, ACTOR_SELF, 0, 0, EASING_COS_IN_OUT)
    
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Call(GetActorVar, ACTOR_SELF, AVar_TurnsLeft, LVar0)
    Return
    End
};

EvtScript N(EVS_HealAlly) = {
    Call(SetTargetActor, ACTOR_SELF, LVarC)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(GetActorPos, ACTOR_SELF, LVar3, LVar4, LVar5)
    Add(LVar4, 10)
    Call(SetGoalPos, ACTOR_SELF, LVar0, LVar4, LVar5)
    Call(SetActorSpeed, ACTOR_SELF, Float(2.0))
    Call(FlyToGoal, ACTOR_SELF, 0, 0, EASING_COS_IN_OUT)
    Call(SetPartFlagBits, ACTOR_SELF, PRT_MUSHROOM, ACTOR_PART_FLAG_INVISIBLE, FALSE)
    Sub(LVar4, 10)
    Add(LVar5, 2)
    Call(SetPartPos, ACTOR_SELF, PRT_MUSHROOM, LVar0, LVar4, LVar5)
    Call(SetGoalToTarget, ACTOR_SELF)
    Wait(20)
    Call(SetPartJumpGravity, ACTOR_SELF, PRT_MUSHROOM, Float(1.0))
    Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Sub(LVar1, 10)
    Call(PlaySoundAtPart, ACTOR_SELF, PRT_MUSHROOM, SOUND_FALL_QUICK)
    Call(JumpPartTo, ACTOR_SELF, PRT_MUSHROOM, LVar0, LVar1, LVar2, 15, FALSE)
    Call(PlaySoundAtActor, LVarC, SOUND_RECOVER_HEART)
    Call(SetPartFlagBits, ACTOR_SELF, PRT_MUSHROOM, ACTOR_PART_FLAG_INVISIBLE, TRUE)
    Thread
        Call(HealActor, LVarC, AMT_HEAL, FALSE)
    EndThread
    Wait(30)
    Return
    End
};

EvtScript N(EVS_Heal) = {
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)

    IfFalse(GF_SonicDead)
        Set(LVarC, ACTOR_ENEMY1)
        ExecWait(N(EVS_HealAlly))
    EndIf

    IfFalse(GF_KnucklesDead)
        Set(LVarC, ACTOR_ENEMY3)
        ExecWait(N(EVS_HealAlly))
    EndIf

    Call(SetGoalToHome, ACTOR_SELF)
    Call(FlyToGoal, ACTOR_SELF, 0, 0, EASING_COS_IN_OUT)

    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

EvtScript N(EVS_CarryAttack) = {
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)

    Call(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Wait(30)

    Call(SetGoalToTarget, ACTOR_SELF)
    Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(SetActorSpeed, ACTOR_SELF, Float(4.0))
    Sub(LVar1, 10)
    Sub(LVar0, 20)
    Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Thread
        Loop(5)
            Call(PlaySoundAtActor, ACTOR_SELF, SOUND_FLIGHT)
            Wait(5)
        EndLoop
    EndThread
    Call(FlyToGoal, ACTOR_SELF, 0, 0, EASING_COS_IN_OUT)
    
    Call(SetActorSpeed, ACTOR_SELF, Float(1.8))
    Call(SetActorSpeed, ACTOR_PLAYER, Float(1.9))
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_MALLET_SWING)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_RetroTails_Carry)
    Call(UseIdleAnimation, ACTOR_PLAYER, FALSE)
    Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Hurt)
    Wait(5)
    Add(LVar1, 60)
    Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Sub(LVar1, 18)
    Add(LVar0, 10)
    Call(SetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    
    Thread
        Call(FlyToGoal, ACTOR_SELF, 0, 0, 0)
    EndThread
    Thread
        Wait(1)
        Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
        Call(MoveBattleCamOver, 60)
    EndThread
    Call(FlyToGoal, ACTOR_PLAYER, 0, 0, 0)

    Wait(15)
    Call(SetGoalToHome, ACTOR_PLAYER)
    Call(SetActorJumpGravity, ACTOR_PLAYER, Float(1.0))

    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_RetroTails_Idle)
    Call(PlaySoundAtActor, ACTOR_PLAYER, SOUND_FALL_QUICK)
    Call(JumpToGoal, ACTOR_PLAYER, 15, 0, 0, 0)
    Call(EnemyDamageTarget, ACTOR_SELF, LVarA, DAMAGE_TYPE_NO_CONTACT, 0, 0, DMG_CARRY, 0)

    Call(SetActorSpeed, ACTOR_SELF, Float(3.0))
    Call(SetGoalToHome, ACTOR_SELF)
    Call(FlyToGoal, ACTOR_SELF, 0, 0, EASING_COS_IN_OUT)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_PLAYER, TRUE)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

EvtScript N(EVS_TakeTurn) = {
    IfNe(GB_BattlePhase, 2)
        Return
    EndIf
    Call(N(DetermineAttackOdds)) // returns in lvar1, lvar2
    Call(RandInt, 100, LVar0)
    IfLt(LVar0, LVar1)
        ExecWait(N(EVS_JumpAttack))
        Return
    EndIf
    IfLt(LVar0, LVar2)
        ExecWait(N(EVS_CarryAttack))
        Return
    EndIf
    ExecWait(N(EVS_Heal))
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
