#include "tst_01.h"
#include "sprite/player.h"
#include "world/common/npc/Toad_Stationary.inc.c"


EvtScript N(EVS_NpcIdle_Fishmael) = {
    Call(DisablePlayerInput, TRUE)
    Wait(45)
    Call(ShowMessageAtScreenPos, MSG_Game_Credits, 160, 40)
    Call(StartBossBattle, SONG_SMB1_BOWSER)
    Return
    End
};

EvtScript N(EVS_NpcDefeat_Fishmael) = {
    Call(DisablePlayerInput, TRUE)
    Call(ShowMessageAtScreenPos, MSG_Game_YouWin, 160, 40)
    Call(GotoMap, "kmr_30", 0)
    Return
    End
};

EvtScript N(EVS_NpcInit_Fishmael) = {
    Call(BindNpcIdle, NPC_SELF, N(EVS_NpcIdle_Fishmael))
    Call(BindNpcDefeat, NPC_SELF, N(EVS_NpcDefeat_Fishmael))
    Return
    End
};

NpcData N(NpcData_Fishmael) = {
    .id = NPC_Fishmael,
    .pos = { 370.0f, -10.0f, -115.0f },
    .yaw = 270,
    .init = &N(EVS_NpcInit_Fishmael),
    .settings = &N(NpcSettings_Toad_Stationary),
    .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_400000,
    .drops = NO_DROPS,
    .animations = {
        .idle   = ANIM_Fishmael_Idle,
    },
    .tattle = MSG_NpcTattle_Fishmael,
};

NpcGroupList N(NpcSetA) = {
    NPC_GROUP(N(NpcData_Fishmael), BTL_RET_FORMATION_00),
    {}
};
