#pragma once

#include "util/types.h"

namespace dyro
{
    // Forward declaration of the structure to hold launch parameters
    struct launch_params;

    // Function declaration for launching with given parameters
    s32 launch(const launch_params& params);
}