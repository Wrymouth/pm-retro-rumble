#include "ret_00.h"

EvtScript N(EVS_Main) = {
  Set(GB_WorldLocation, LOCATION_SHIVER_MOUNTAIN)
  Call(SetSpriteShading, SHADING_NONE)
  EVT_SETUP_CAMERA_NO_LEAD(0, 0, 0)
  Return
  End  
};
