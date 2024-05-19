# -------------------------------
# Macro that will define our source groups
# -------------------------------
MACRO(GROUPSOURCES curdir folder_name)
    FILE(GLOB children RELATIVE ${curdir} ${curdir}/*)
    FOREACH(child ${children})
           IF(IS_DIRECTORY ${curdir}/${child})
              GROUPSOURCES(${curdir}/${child} ${folder_name}/${child})
           ELSE()
              SOURCE_GROUP(${folder_name} FILES ${curdir}/${child})
           ENDIF()
    ENDFOREACH()
ENDMACRO(GROUPSOURCES)

option(DSL_STATIC_LIB "Option to make DSL a static or shared library" ON)

# -------------------------------
# Setup lib
# -------------------------------
if(DSL_STATIC_LIB)
    add_library(dsl STATIC)
else()
    add_library(dsl SHARED)
endif()

if(MSVC)
    add_definitions(-DDSL_COMPILER_MSVC)
endif()

# Sources
## private sources
target_sources(dsl PRIVATE 
    ${CMAKE_CURRENT_LIST_DIR}/private/util/blob.cpp
    ${CMAKE_CURRENT_LIST_DIR}/private/util/blob_view.cpp
    ${CMAKE_CURRENT_LIST_DIR}/private/util/blob_reader.cpp
    ${CMAKE_CURRENT_LIST_DIR}/private/util/blob_writer.cpp
    ${CMAKE_CURRENT_LIST_DIR}/private/util/pointer_math.cpp
    ${CMAKE_CURRENT_LIST_DIR}/private/util/string_op.cpp)

## public sources
target_sources(dsl PUBLIC 
    ### fmt
    ${CMAKE_CURRENT_LIST_DIR}/public/fmt/core.h
    ${CMAKE_CURRENT_LIST_DIR}/public/fmt/format-inl.h
    ${CMAKE_CURRENT_LIST_DIR}/public/fmt/format.h

    ${CMAKE_CURRENT_LIST_DIR}/public/util/hash.h
    ${CMAKE_CURRENT_LIST_DIR}/public/util/string_op.h
    ${CMAKE_CURRENT_LIST_DIR}/public/util/defines.h
    ${CMAKE_CURRENT_LIST_DIR}/public/util/blob.h
    ${CMAKE_CURRENT_LIST_DIR}/public/util/blob_view.h
    ${CMAKE_CURRENT_LIST_DIR}/public/util/blob_reader.h
    ${CMAKE_CURRENT_LIST_DIR}/public/util/blob_writer.h
    ${CMAKE_CURRENT_LIST_DIR}/public/util/pointer_math.h
    ${CMAKE_CURRENT_LIST_DIR}/public/util/color.h
    ${CMAKE_CURRENT_LIST_DIR}/public/util/memory_size.h
    ${CMAKE_CURRENT_LIST_DIR}/public/util/log.h
    ${CMAKE_CURRENT_LIST_DIR}/public/util/assert.h
    ${CMAKE_CURRENT_LIST_DIR}/public/util/types.h)

# Create the project filters
GROUPSOURCES(${CMAKE_CURRENT_LIST_DIR}/private private)
GROUPSOURCES(${CMAKE_CURRENT_LIST_DIR}/public public)

# Private includes
target_include_directories(dsl PRIVATE ${CMAKE_CURRENT_LIST_DIR}/private)

# Public includes
target_include_directories(dsl PUBLIC ${CMAKE_CURRENT_LIST_DIR}/public)

# Target properties
set_target_properties(dsl PROPERTIES FOLDER "third-party")

# Compile definitions
if(WIN32)
    target_compile_definitions(dsl PUBLIC DSL_PLATFORM_WINDOWS)
endif()
                      