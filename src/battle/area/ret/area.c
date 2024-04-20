#include "area.h"

extern ActorBlueprint A(retro_bowser);
extern ActorBlueprint A(retro_axe);
extern Stage A(ret_00);


Vec3i A(axe_position) = { 230, 0, 5 };


Formation A(Formation_00) = {
    ACTOR_BY_IDX(A(retro_bowser), BTL_POS_GROUND_C, 10),
    ACTOR_BY_POS(A(retro_axe), A(axe_position), 9),
};

BattleList A(Formations) = {
    BATTLE(A(Formation_00), A(ret_00), "ret"),
    {},
};

StageList A(Stages) = {
    STAGE("ret_00", A(ret_00)),
    {},
};
