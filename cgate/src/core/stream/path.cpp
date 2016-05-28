#include "cgate/core/stream/path.hpp"
#include "cgate/ex/stream_open.hpp"

#include "SDL2/SDL_filesystem.h"

namespace cgate
{
    std::string
    getBasePath(void)
    {
        auto result = SDL_GetBasePath();
        if (result == nullptr)
            throw ex::StreamOpen{"Unable to retrieve the application Base path"};
        return result;
    } /* end of : std::string
                    getBasePath(void) */

} // end of : namespace cgate
