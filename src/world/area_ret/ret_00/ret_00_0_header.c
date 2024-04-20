#include "ret_00.h"

EntryList N(Entrances) = {
    [ret_00_ENTRY_0]    {    0.0,    0.0,  0.0,  180.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .background = &gBackgroundImage,
    .tattle = { MSG_MapTattle_mac_03 },
};
