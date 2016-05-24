#include "cgate/ex/file_open.hpp"
#include "cgate/log/file_logger.hpp"

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

        if (do_clear)
        {
            FILE *fd{nullptr};

#if defined(_WIN32)
            if (fopen_s(&fd, m_path.c_str(), "w") != 0)
#else
            if ((fd = fopen(m_path.c_str(), "w")) == nullptr)
#endif
                throw ex::FileOpen{};

            fclose(fd);
        }
    } /* end of : FileLogger::FileLogger(const std::string path,
                                         const bool do_clear,
                                         const LogLevel level) */

    FILE*
    FileLogger::openStream(void)
    {
        FILE *fd{nullptr};

#if defined(_WIN32)
        if (fopen_s(&fd, m_path.c_str(), "a") != 0)
#else
        if ((fd = fopen(m_path.c_str(), "a")) == nullptr)
#endif
            throw ex::FileOpen{};

        return fd;
    } /* end of : FILE*
                  FileLogger::openStream(void) */

    void
    FileLogger::closeStream(FILE* stream)
    {
        fclose(stream);
    } /* end of : void
                  FileLogger::closeStream(FILE* stream) */

} // end of : namespace cgate
