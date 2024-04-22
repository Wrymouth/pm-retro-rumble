#include "machi.h"

#define VAR_RANGE_BYTE(s, firstVar, nextRange, nextVar) \
{ \
    .name = s, \
    .first = EVT_INDEX_OF_GAME_BYTE(firstVar), \
    .count = nextRange - firstVar, \
    .next = nextVar, \
}

GameVarRange N(GameByteTable)[] = {
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
