# -------------------------------
# Macro that will define our source groups
# -------------------------------
MACRO(GROUPSOURCES curdir folder_name)
    # Retrieve all files and directories in the current directory
    FILE(GLOB children RELATIVE ${curdir} ${curdir}/*)

    # Loop through each child in the current directory
    FOREACH(child ${children})
        # If the child is a directory, recursively call the macro
        IF(IS_DIRECTORY ${curdir}/${child})
            GROUPSOURCES(${curdir}/${child} ${folder_name}/${child})
        ELSE()
            # If the child is a file, add it to the source group
            SOURCE_GROUP(${folder_name} FILES ${curdir}/${child})
        ENDIF()
    ENDFOREACH()
ENDMACRO(GROUPSOURCES)

# Add the core subdirectory to the build
add_subdirectory(core)
