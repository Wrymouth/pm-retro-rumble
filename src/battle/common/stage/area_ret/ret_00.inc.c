#include "battle/battle.h"

#define NAMESPACE A(ret_00)

EvtScript N(EVS_PreBattle) = {
    Call(SetSpriteShading, SHADING_NONE)
    Call(SetCamBGColor, CAM_BATTLE, 0, 0, 0)
    Thread
        Wait(5)
        Call(PlaySound, SOUND_AUDIENCE_CHEER)
    EndThread
    Set(LVar0, 0)
    Loop(130)
        Add(LVar0, 2)
        Call(TranslateGroup, GROUP_CurtainGroup, 0, LVar0, 0)
        Wait(1)
    EndLoop
    Return
    End
};

EvtScript N(EVS_PostBattle) = {
    Return
    End
};

Stage NAMESPACE = {
    .texture = "ret_tex",
    .shape = "ret_bt00_shape",
    .hit = "ret_bt00_hit",
    .bg = "hos_bg",
    .preBattle = &N(EVS_PreBattle),
    .postBattle = &N(EVS_PostBattle),
};
