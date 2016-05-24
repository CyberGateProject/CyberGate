#pragma once

#include "SFML/Config.hpp"

#if defined(SFML_SYSTEM_WINDOWS)

    // Windows compilers need specific (and different) keywords for export and import
    #define CGATE_API_EXPORT __declspec(dllexport)
    #define CGATE_API_IMPORT __declspec(dllimport)

    // For Visual C++ compilers, we also need to turn off this annoying C4251 warning
    #ifdef _MSC_VER

        #pragma warning(disable: 4251)

    #endif

#else // Linux, FreeBSD, Mac OS X

    #if __GNUC__ >= 4

        // GCC 4 has special keywords for showing/hidding symbols,
        // the same keyword is used for both importing and exporting
        #define CGATE_API_EXPORT __attribute__ ((__visibility__ ("default")))
        #define CGATE_API_IMPORT __attribute__ ((__visibility__ ("default")))

    #else

        // GCC < 4 has no mechanism to explicitely hide symbols, everything's exported
        #define CGATE_API_EXPORT
        #define CGATE_API_IMPORT

    #endif

#endif

#if defined(CGATE_EXPORTS)

    #define CGATE_API CGATE_API_EXPORT

#else

    #define CGATE_API CGATE_API_IMPORT

#endif
