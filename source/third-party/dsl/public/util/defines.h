#pragma once

#ifndef DSL_DEFINES
  #define DSL_DEFINES

  //-------------------------------------------------------------------------
  // Unused parameter.
  #if defined DSL_COMPILER_CLANG
    #define UNUSED_PARAM(...)                                                                                                                                                                                                                            \
      _Pragma("clang diagnostic push") _Pragma("clang diagnostic ignored \"-Wunused-value\"")                                                                                                                                                            \
      {                                                                                                                                                                                                                                                  \
        __VA_ARGS__;                                                                                                                                                                                                                                     \
      }                                                                                                                                                                                                                                                  \
      _Pragma("clang diagnostic pop")
  #elif defined DSL_COMPILER_MSVC
    #define UNUSED_PARAM(...)                                                                                                                                                                                                                            \
      {                                                                                                                                                                                                                                                  \
        __VA_ARGS__;                                                                                                                                                                                                                                     \
      }
  #endif

  //-------------------------------------------------------------------------
  // Assembly instruction to break execution.
  #if defined DSL_COMPILER_CLANG
    #define DEBUG_BREAK() __builtin_trap()
  #elif defined DSL_COMPILER_MSVC
    #define DEBUG_BREAK() __debugbreak()
  #else
    #error DEBUG_BREAK unsupported machine instruction ...
  #endif

  //-------------------------------------------------------------------------
  // BIT TWIDDLING
  #define BIT(x) (1 << x)

  //-------------------------------------------------------------------------
  // Func signature
  #if defined DSL_COMPILER_CLANG
    #define DSL_FUNC_SIG __PRETTY_FUNCTION__
  #elif defined DSL_COMPILER_MSVC
    #define DSL_FUNC_SIG __FUNCSIG__
  #else
    #define DSL_FUNC_SIG "DSL_FUNC_SIG unknown!"
  #endif

#endif