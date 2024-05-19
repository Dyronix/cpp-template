add_library(core STATIC)

# Sources
## private platform sources
if(WIN32)
    target_sources(core PRIVATE 
        ${SOURCE_RUNTIME_DIRECTORY}/core/private/windows/win32_min.h
        ${SOURCE_RUNTIME_DIRECTORY}/core/private/windows/win32_entrypoint.cpp)
endif()

## private sources
target_sources(core PRIVATE 
    ${SOURCE_RUNTIME_DIRECTORY}/core/private/launch.cpp
    ${SOURCE_RUNTIME_DIRECTORY}/core/private/launch.h)

## public sources
target_sources(core PUBLIC 
    ${SOURCE_RUNTIME_DIRECTORY}/core/public/launch_params.h
    ${SOURCE_RUNTIME_DIRECTORY}/core/public/entrypoint.h)

# Create the project filters
# Group source files into private and public directories
GROUPSOURCES(${SOURCE_RUNTIME_DIRECTORY}/core/private private)
GROUPSOURCES(${SOURCE_RUNTIME_DIRECTORY}/core/public public)

# Private includes
target_include_directories(core PRIVATE ${SOURCE_RUNTIME_DIRECTORY}/core/private)

# Public includes
target_include_directories(core PUBLIC ${SOURCE_RUNTIME_DIRECTORY}/core/public)
target_include_directories(core PUBLIC ${SOURCE_THIRDPARTY_DIRECTORY}/dsl/public) 

# Link necessary libraries based on the platform
if(WIN32)
    target_link_libraries(core PUBLIC Shlwapi.lib)
endif()

# Target properties
# Set the folder for the project in IDEs
set_target_properties(core PROPERTIES FOLDER "runtime")
                      