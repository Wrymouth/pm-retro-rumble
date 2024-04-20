/// @file tst_01.h
/// @brief Testing - Jump Width Test

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../tst.h"
#include "mapfs/tst_01_shape.h"
#include "mapfs/tst_01_hit.h"
#include "sprite/npc/Fishmael.h"



#define NAMESPACE tst_01

enum {
    NPC_Whale                   = 0,
    NPC_Kolorado                = 1,
    NPC_Fishmael                = 2,
    NPC_Fuzzipede               = 3,
    NPC_JrTroopa_01             = 4,
    NPC_JrTroopa_02             = 5,
    NPC_ChuckQuizmo             = 6,
    NPC_Bartender               = 7,
    NPC_Toad_02                 = 8,
    NPC_Chanterelle             = 9,
    NPC_ArtistToad              = 10,
    NPC_TradeEventToad          = 11,
    NPC_Toad_04                 = 12,
    NPC_Toad_05                 = 13,
    NPC_Toad_06                 = 14,
    NPC_Toad_07                 = 15,
};

extern NpcGroupList N(NpcSetA);
