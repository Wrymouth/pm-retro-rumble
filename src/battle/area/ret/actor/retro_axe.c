#include "../area.h"

#include "sprite/npc/RetroAxe.h"

#define NAMESPACE A(retro_axe)

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
    AVar_TurnsLeft    = 0,
};

enum N(ActorParams) {
    DMG_HAMMER   = 1,
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

ActorPartBlueprint N(ActorParts)[] = {
    {
        .flags = ACTOR_PART_FLAG_NO_TARGET,
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
    .flags = ACTOR_FLAG_NO_HEALTH_BAR,
    .type = ACTOR_TYPE_RETRO_AXE,
    .level = ACTOR_LEVEL_RETRO_AXE,
    .maxHP = 3,
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
    STATUS_KEY_NORMAL,    ANIM_RetroAxe_Still,
    STATUS_KEY_STONE,     ANIM_RetroAxe_Still,
    STATUS_KEY_SLEEP,     ANIM_RetroAxe_Still,
    STATUS_KEY_POISON,    ANIM_RetroAxe_Still,
    STATUS_KEY_STOP,      ANIM_RetroAxe_Still,
    STATUS_KEY_STATIC,    ANIM_RetroAxe_Still,
    STATUS_KEY_PARALYZE,  ANIM_RetroAxe_Still,
    STATUS_KEY_DIZZY,     ANIM_RetroAxe_Still,
    STATUS_KEY_FEAR,      ANIM_RetroAxe_Still,
    STATUS_END,
};

API_CALLABLE(N(SetNextBattleStats)) {
    PlayerData* playerData = &gPlayerData;
    s32 i;

    s16 items[] = {ITEM_MAPLE_SHROOM, ITEM_SUPER_SHROOM, ITEM_SUPER_SHROOM, ITEM_HONEY_SYRUP, ITEM_HONEY_SYRUP, ITEM_SNOWMAN_DOLL, ITEM_NONE, ITEM_NONE};
    s16 badges[] = {ITEM_POWER_RUSH, ITEM_DAMAGE_DODGE_A, ITEM_S_JUMP_CHG, ITEM_MULTIBOUNCE, ITEM_POWER_SMASH, ITEM_HAMMER_THROW, ITEM_HAPPY_FLOWER_A, ITEM_HAPPY_FLOWER_B};

    playerData->curMaxHP = 20;
    playerData->hardMaxHP = 20;
    playerData->curFP = 10;
    playerData->curMaxFP = 10;
    playerData->hardMaxFP = 10;
    playerData->bootsLevel = 1;
    playerData->hammerLevel = 2;
    playerData->maxStarPower = 3;
    playerData->starPower = playerData->maxStarPower * SP_PER_BAR;

    for (i = 0; i < ARRAY_COUNT(playerData->partners) - 3; i++) {
        if (i == PARTNER_GOOMPA) {
            continue;
        }
        playerData->partners[i].enabled = TRUE;
        playerData->partners[i].level = PARTNER_RANK_SUPER;
        playerData->partners[i].unk_02[0] = 0;
        playerData->partners[i].unk_02[1] = 0;
        playerData->partners[i].unk_02[2] = 0;
    }

    for (s32 i = 0; i < ARRAY_COUNT(items); i++)
    {
        playerData->invItems[i] = items[i];
        playerData->badges[i] = badges[i];
        playerData->equippedBadges[i] = badges[i];
    }
    

    return ApiStatus_DONE2;
}

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
            Set(GF_ZoomedOnAxe, TRUE)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_RetroAxe_Still)
            ExecWait(EVS_Enemy_Hit)
        EndCaseGroup
        CaseEq(EVENT_BURN_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_RetroAxe_Still)
            SetConst(LVar2, ANIM_RetroAxe_Still)
            ExecWait(EVS_Enemy_BurnHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_RetroAxe_Still)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_SHOCK_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_RetroAxe_Still)
            ExecWait(EVS_Enemy_ShockHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_RetroAxe_Still)
            ExecWait(EVS_Enemy_Knockback)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_RetroAxe_Still)
            ExecWait(EVS_Enemy_ReturnHome)
        CaseEq(EVENT_SHOCK_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_RetroAxe_Still)
            ExecWait(EVS_Enemy_ShockHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_RetroAxe_Still)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_DEATH)
            // do the bridge thing
            Set(LVar0, 0)
            Call(PlaySound, SOUND_LOOP_TRD_RAISE_STAIRS)
            Loop(100)
                Sub(LVar0, 2)
                Call(TranslateGroup, GROUP_Bridge, LVar0, 0, 0)
                Wait(1)
            EndLoop
            Call(StopSound, SOUND_LOOP_TRD_RAISE_STAIRS)
            Call(SetActorJumpGravity, ACTOR_ENEMY0, Float(1.0))
            Call(GetActorPos, ACTOR_ENEMY0, LVar0, LVar1, LVar2)
            Call(SetGoalPos, ACTOR_ENEMY0, LVar0, -200, LVar2)
            Call(PlaySoundAtActor, ACTOR_ENEMY0, SOUND_FALL_QUICK)
            Call(JumpToGoal, ACTOR_ENEMY0, 30, FALSE, FALSE, FALSE)
            Thread
                Loop(8)
                    Call(PlaySound, SOUND_BOMB_BLAST)
                    Wait(8)
                EndLoop
                Call(PlaySound, SOUND_ACTOR_DEATH)
            EndThread


            Call(PlaySound, SOUND_AUDIENCE_CHEER)
            Call(SetMusicTrack, 0, SONG_LEVEL_UP, 0, 8)
            Set(LVar0, 260)
            Loop(130)
                Sub(LVar0, 2)
                Call(TranslateGroup, GROUP_CurtainGroup, 0, LVar0, 0)
                Wait(1)
            EndLoop


            Call(TranslateGroup, GROUP_BowserArena, 0, 1000, 0)
            Call(TranslateGroup, GROUP_AngelIsland, -700, 0, 0)
            Call(ShowMessageAtScreenPos, MSG_Game_SonicIntro, 160, 40)

            Call(PlaySound, SOUND_AUDIENCE_CHEER)
            Thread 
                Set(LVar0, 0)
                Loop(130)
                    Add(LVar0, 2)
                    Call(TranslateGroup, GROUP_CurtainGroup, 0, LVar0, 0)
                    Wait(1)
                EndLoop
            EndThread
            
            Add(GB_BattlePhase, 1)
            Call(SetActorFlagBits, ACTOR_ENEMY1, ACTOR_FLAG_INVISIBLE|ACTOR_FLAG_NO_HEALTH_BAR, FALSE)
            Call(SetActorFlagBits, ACTOR_ENEMY2, ACTOR_FLAG_INVISIBLE|ACTOR_FLAG_NO_HEALTH_BAR, FALSE)
            Call(SetActorFlagBits, ACTOR_ENEMY3, ACTOR_FLAG_INVISIBLE|ACTOR_FLAG_NO_HEALTH_BAR, FALSE)
            Call(SetPartFlagBits, ACTOR_ENEMY1, PRT_MAIN, ACTOR_PART_FLAG_NO_TARGET, FALSE)
            Call(SetPartFlagBits, ACTOR_ENEMY2, PRT_MAIN, ACTOR_PART_FLAG_NO_TARGET, FALSE)
            Call(SetPartFlagBits, ACTOR_ENEMY3, PRT_MAIN, ACTOR_PART_FLAG_NO_TARGET, FALSE)
            Call(SetPartFlagBits, ACTOR_ENEMY1, PRT_MAIN, ACTOR_PART_FLAG_PRIMARY_TARGET, TRUE)
            Call(SetPartFlagBits, ACTOR_ENEMY2, PRT_MAIN, ACTOR_PART_FLAG_PRIMARY_TARGET, TRUE)
            Call(SetPartFlagBits, ACTOR_ENEMY3, PRT_MAIN, ACTOR_PART_FLAG_PRIMARY_TARGET, TRUE)
            
            Thread
                Wait(30)
                Call(SetMusicTrack, 0, SONG_ANGEL_ISLAND, 0, 8)
            EndThread
            Wait(70)
            
            Call(RemoveActor, ACTOR_ENEMY0)
            Call(RemoveActor, ACTOR_SELF)
            

            Call(N(SetNextBattleStats))
            Return

        CaseEq(EVENT_RECOVER_STATUS)
            // nothing
        CaseEq(EVENT_SCARE_AWAY)
            Call(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_FLYING, TRUE)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_RetroAxe_Still)
            SetConst(LVar2, ANIM_RetroAxe_Still)
            ExecWait(EVS_Enemy_ScareAway)
            Return
        CaseDefault
    EndSwitch
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

EvtScript N(EVS_TakeTurn) = {
    Call(GetActorVar, ACTOR_SELF, AVar_TurnsLeft, LVar0)
    IfFalse(LVar0)
        IfFalse(GF_ZoomedOnAxe)
            Call(UseBattleCamPreset, BTL_CAM_PRESET_14)
            Call(BattleCamTargetActor, ACTOR_SELF)
            Call(AddBattleCamZoom, 100)
            Call(MoveBattleCamOver, 30)
            Call(PlaySound, SOUND_QUIZ_NEXT_QUESTION)
            Wait(80)
            Call(SetPartFlagBits, ACTOR_SELF, PRT_MAIN, ACTOR_PART_FLAG_NO_TARGET, FALSE)
            Call(SetPartFlagBits, ACTOR_SELF, PRT_MAIN, ACTOR_PART_FLAG_PRIMARY_TARGET, TRUE)
            Call(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_NO_HEALTH_BAR, FALSE)
        EndIf
    Else
        Sub(LVar0, 1)
        Call(SetActorVar, ACTOR_SELF, AVar_TurnsLeft, LVar0)
    EndIf

    Return
    End
};

EvtScript N(EVS_Init) = {
    Call(SetActorVar, ACTOR_SELF, AVar_TurnsLeft, 3)
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
