#include "launch.h"
#include "launch_params.h"

#include "util/log.h"

namespace dyro
{
    // Function to initialize the application with the given parameters
    bool initialize(const launch_params& params)
    {
        dsl::log::info("Initialize application: {}", params.app_name);

        // Initialization successful when we reach this point
        return true;
    }

    // Function to start the application's main loop or tasks
    void tick(const launch_params& params)
    {
        dsl::log::info("Start application: {}", params.app_name);
    }

    // Function to shut down the application gracefully
    void shutdown(const launch_params& params)
    {
        dsl::log::info("Shutdown application: {}", params.app_name);
    }

    // Function to launch the application with the given parameters
    s32 launch(const launch_params& params)
    {
        // Attempt to initialize the application
        if(!initialize(params))
        {
            // Log an error if initialization fails
            dsl::log::error("Failed to initialize application, program will exit");
            return 1;  // Return an error code
        }

        tick(params);
        shutdown(params);

        // Return success code
        return 0;
    }
}