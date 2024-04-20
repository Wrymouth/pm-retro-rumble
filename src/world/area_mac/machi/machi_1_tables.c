#include "machi.h"

#define VAR_RANGE_BYTE(s, firstVar, nextRange, nextVar) \
{ \
    .name = s, \
    .first = EVT_INDEX_OF_GAME_BYTE(firstVar), \
    .count = nextRange - firstVar, \
    .next = nextVar, \
}

GameVarRange N(GameByteTable)[] = {
    VAR_RANGE_BYTE("GSW EVT",   GB_StoryProgress,                 GB_KMR20_MarioReadDiaryFlags_00,  GB_Unused_EVT_02),
    VAR_RANGE_BYTE("GSW KMR",   GB_KMR20_MarioReadDiaryFlags_00,  GB_MAC01_Merlon_SpinJumpCount,    GB_Unused_KMR_05),
    VAR_RANGE_BYTE("GSW MAC",   GB_MAC01_Merlon_SpinJumpCount,    GB_TIK15_RipCheato_PurchaseCount, GB_Unused_MAC_13),
    VAR_RANGE_BYTE("GSW TIK",   GB_TIK15_RipCheato_PurchaseCount, GB_Unused_KGR_00,                 GB_Unused_TIK_01),
    VAR_RANGE_BYTE("GSW KGR",   GB_Unused_KGR_00,                 GB_Unused_KKJ_00,                 GB_Unused_KGR_00),
    VAR_RANGE_BYTE("GSW KKJ",   GB_Unused_KKJ_00,                 GB_Unused_HOS_00,                 GB_Unused_KKJ_03),
    VAR_RANGE_BYTE("GSW HOS",   GB_Unused_HOS_00,                 GB_Unused_NOK_00,                 GB_Unused_HOS_00),
    VAR_RANGE_BYTE("GSW NOK",   GB_Unused_NOK_00,                 GB_Unused_TRD_00,                 GB_Unused_NOK_02),
    VAR_RANGE_BYTE("GSW TRD",   GB_Unused_TRD_00,                 GB_IWA10_ReturnedLetterCount,     GB_Unused_TRD_00),
    VAR_RANGE_BYTE("GSW IWA",   GB_IWA10_ReturnedLetterCount,     GB_DRO02_SheekGiftCount,          GB_Unused_IWA_02),
    VAR_RANGE_BYTE("GSW DRO",   GB_DRO02_SheekGiftCount,          GB_Unused_SBK_00,                 GB_Unused_DRO_02),
    VAR_RANGE_BYTE("GSW SBK",   GB_Unused_SBK_00,                 GB_ISK11_ItemSocket1,             GB_Unused_SBK_00),
    VAR_RANGE_BYTE("GSW ISK",   GB_ISK11_ItemSocket1,             GB_MIM_CurrentMapID,              GB_Unused_ISK_05),
    VAR_RANGE_BYTE("GSW MIM",   GB_MIM_CurrentMapID,              GB_OBK07_SelectedRecord,          GB_Unused_MIM_01),
    VAR_RANGE_BYTE("GSW OBK",   GB_OBK07_SelectedRecord,          GB_Unused_ARN_00,                 GB_Unused_OBK_01),
    VAR_RANGE_BYTE("GSW ARN",   GB_Unused_ARN_00,                 GB_ARN_Tubba_MapID,               GB_Unused_ARN_00),
    VAR_RANGE_BYTE("GSW DGB",   GB_ARN_Tubba_MapID,               GB_Unused_OMO_00,                 GB_Unused_DGB_01),
    VAR_RANGE_BYTE("GSW OMO",   GB_Unused_OMO_00,                 GB_Unused_JAN_00,                 GB_Unused_OMO_05),
    VAR_RANGE_BYTE("GSW JAN",   GB_Unused_JAN_00,                 GB_Unused_KZN_00,                 GB_Unused_JAN_00),
    VAR_RANGE_BYTE("GSW KZN",   GB_Unused_KZN_00,                 GB_Unused_FLO_00,                 GB_Unused_KZN_00),
    VAR_RANGE_BYTE("GSW FLO",   GB_Unused_FLO_00,                 GB_SAM09_ItemSocket1_LowerByte,   GB_Unused_FLO_05),
    VAR_RANGE_BYTE("GSW SAM",   GB_SAM09_ItemSocket1_LowerByte,   GB_Unused_PRA_00,                 GB_Unused_SAM_08),
    VAR_RANGE_BYTE("GSW PRA",   GB_Unused_PRA_00,                 GB_KPA_WaterLevel,                GB_Unused_PRA_04),
    VAR_RANGE_BYTE("GSW KPA",   GB_KPA_WaterLevel,                GB_Unused_OSR_00,                 GB_Unused_KPA_08),
    VAR_RANGE_BYTE("GSW END",   GB_Unused_END_00,                 GB_Unused_BAT_00,                 GB_Unused_END_01),
    VAR_RANGE_BYTE("GSW OSR",   GB_Unused_OSR_00,                 GB_Unused_END_00,                 GB_Unused_OSR_00),
    VAR_RANGE_BYTE("GSW BAT",   GB_Unused_BAT_00,                 GB_KootFavor_State,               GB_Unused_BAT_00),
    VAR_RANGE_BYTE("GSW NPC",   GB_KootFavor_State,               GB_Tattles_00,                    GB_Unused_NPC_09),
    VAR_RANGE_BYTE("GSW BTL",   GB_Tattles_00,                    GB_Unused_FBTL_00,                GB_Unused_BTL_1E),
    VAR_RANGE_BYTE("GSW FBTL",  GB_Unused_FBTL_00,                GB_Unused_DOKAN_00,               GB_Unused_FBTL_00),
    VAR_RANGE_BYTE("GSW DOKAN", GB_Unused_DOKAN_00,               GB_WorldLocation,                 GB_Unused_DOKAN_00),
    VAR_RANGE_BYTE("GSW MAP",   GB_WorldLocation,                 GB_Unused_1B4,                    GB_Unused_MAP_01),
    {}
};

#define VAR_RANGE_FLAG(s, firstVar, nextRange, nextVar) \
{ \
    .name = s, \
    .first = EVT_INDEX_OF_GAME_FLAG(firstVar), \
    .count = nextRange - firstVar, \
    .next = nextVar, \
}

GameVarRange N(GameFlagTable)[] = {
    {}
};
