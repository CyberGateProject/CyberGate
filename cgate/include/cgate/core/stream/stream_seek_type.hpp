#pragma once

#include "cgate/export.hpp"
#include "SDL2/SDL_rwops.h"

#include <string>

namespace cgate
{
    /// @brief
    enum class StreamSeekType
    {
        /// @brief
        Begin = RW_SEEK_SET,

        /// @brief
        Current = RW_SEEK_CUR,

        /// @brief
        End = RW_SEEK_END
    }; // end of : enum class StreamSeekType

} // end of : namespace cgate
