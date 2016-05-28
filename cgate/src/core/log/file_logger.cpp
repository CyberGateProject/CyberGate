#include "cgate/core/strext.hpp"
#include "cgate/core/log/file_logger.hpp"
#include "cgate/core/stream/file_stream.hpp"
#include "SDL2/SDL_platform.h"

#include <cassert>

namespace cgate
{
    FileLogger::FileLogger(const std::string path,
                           const bool do_clear,
                           const LogLevel level)
        : ILogger{level}
        , m_path{path}
    {
        assert(path != "");

        m_stream.reset(new FileStream{path, do_clear ? "w" : "a"});
    } /* end of : FileLogger::FileLogger(const std::string path,
                                         const bool do_clear,
                                         const LogLevel level) */

    std::string
    FileLogger::getPath(void) const
    {
        return m_path;
    } /* end of : std::string
                  FileLogger::getPath(void) const */

} // end of : namespace cgate
