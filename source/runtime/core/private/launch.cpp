#include "launch.h"
#include "launch_params.h"

#include "util/log.h"

namespace dyro
{
    bool initialize(const launch_params& params)
    {
        dsl::log::info("Initialize application: {}", params.app_name);

        return true;
    }

    void tick(const launch_params& params)
    {
        dsl::log::info("Start application: {}", params.app_name);
    }

    void shutdown(const launch_params& params)
    {
        dsl::log::info("Shutdown application: {}", params.app_name);
    }

    s32 launch(const launch_params& params)
    {
        if(!initialize(params))
        {
            dsl::log::error("Failed to initialize application, program will exit");
            return 1;
        }

        tick(params);
        shutdown(params);

        return 0;
    }
}