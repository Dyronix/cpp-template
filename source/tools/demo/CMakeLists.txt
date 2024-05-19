add_executable(demo)

# Specify the source file for the executable
target_sources(demo PRIVATE 
    ${SOURCE_TOOLS_DIRECTORY}/demo/private/demo.cpp)

# Create the project filters
# Group source files into private directory
GROUPSOURCES(${SOURCE_TOOLS_DIRECTORY}/demo/private private)

# link libraries
target_link_libraries(demo PRIVATE core)

# Target properties
# Set the folder for the project in IDEs
set_target_properties(demo PROPERTIES
                      FOLDER "tools")