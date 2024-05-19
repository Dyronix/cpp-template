#pragma once

#include "launch_params.h"

namespace dyro
{      
    // Declaration of the entry function which returns launch parameters
    // Has to be implemented by the client
    extern launch_params entry();
}