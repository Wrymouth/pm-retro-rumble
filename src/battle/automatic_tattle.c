#include "automatic_tattle.h"

API_CALLABLE(Tattle_CheckForLPress) {
    GameStatus* gameStatus = &gGameStatus;

    if (!evt_get_variable(script, GF_TattleWindowOpen) && evt_get_variable(script, LVar1) == PHASE_PLAYER_BEGIN && (gameStatus->pressedButtons[0] & BUTTON_L)) {
        evt_set_variable(script, LVar0, TRUE);
    } else {
        evt_set_variable(script, LVar0, FALSE);
    }
    return ApiStatus_DONE2;   
}

API_CALLABLE(Tattle_GetTargetActor) {
    // use gamebyte to determine which tattle to show
    // store in LVar0
    return ApiStatus_DONE2;   
}

EvtScript EVS_DisplayTattleWindow = {
    Loop(0)
        Label(10)
        Call(GetBattlePhase, LVar1)
        Call(Tattle_CheckForLPress)
        IfEq(LVar0, TRUE)
            Set(GF_TattleWindowOpen, TRUE)
            // TODO set proper tattle
            Call(Tattle_GetTargetActor, LVar0)
            Call(ShowMessageAtScreenPos, LVar0, 160, 40)
        EndIf
        Wait(1)
    EndLoop
    Return
    End
};
