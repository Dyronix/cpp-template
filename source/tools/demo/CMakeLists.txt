add_executable(demo)

target_sources(demo PRIVATE 
    ${SOURCE_TOOLS_DIRECTORY}/demo/private/demo.cpp)

# Create the project filters
GROUPSOURCES(${SOURCE_TOOLS_DIRECTORY}/demo/resources resources)
GROUPSOURCES(${SOURCE_TOOLS_DIRECTORY}/demo/private private)

# link libraries
target_link_libraries(demo PRIVATE core)

# Target properties
set_target_properties(demo PROPERTIES
                      FOLDER "tools")