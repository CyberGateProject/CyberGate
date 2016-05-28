#include "cgate/core/strext.hpp"
#include "cgate/core/log/ilogger.hpp"
#include "SDL2/SDL_platform.h"

#include <cassert>
#include <ctime>

namespace cgate
{
    ILogger::ILogger(const LogLevel level)
        : m_default_level{level}
        , m_stream{nullptr}
    {

    } /* end of : ILogger::ILogger(const LogLevel level) */

    LogLevel
    ILogger::getLevel(const size_t section) const
    {
        auto it = m_sections.find(section);

        return it != m_sections.end() ? it->second : m_default_level;
    } /* end of : LogLevel
                  ILogger::getLevel(const size_t section) const */

    ILogger &
    ILogger::setLevel(const size_t section,
                      const LogLevel level)
    {
        m_sections[section] = level;

        return * this;
    } /* end of : ILogger &
                  ILogger::setLevel(const size_t section,
                                    const LogLevel level) */

    LogLevel
    ILogger::getDefaultLevel(void) const
    {
        return m_default_level;
    } /* end of : LogLevel
                  ILogger::getDefaultLevel(void) const */

    ILogger &
    ILogger::setDefaultLevel(const LogLevel level)
    {
        m_default_level = level;

        return * this;
    } /* end of : ILogger &
                  ILogger::setDefaultLevel(const LogLevel level) */

    ILogger &
    ILogger::output(const size_t section,
                    const LogLevel level,
                    const std::string format,
                    ...)
    {
        assert(level != LogLevel::None);
        assert(format != "");

        va_list vargs;
        va_start(vargs, format);
        voutput(section, level, format, vargs);
        va_end(vargs);

        return * this;
    } /* end of : ILogger &
                  ILogger::output(const size_t section,
                                  const LogLevel level,
                                  const std::string format,
                                  ...) */

    ILogger &
    ILogger::voutput(const size_t section,
                     const LogLevel level,
                     const std::string format,
                     va_list vargs)
    {
        assert(level != LogLevel::None);
        assert(format != "");

        auto limit = getLevel(section);
        if (   limit != LogLevel::None
            && static_cast<int>(limit) >= static_cast<int>(level))
            process(section, level, format, vargs);

        return * this;
    } /* end of : ILogger &
                  ILogger::voutput(const size_t section,
                                   const LogLevel level,
                                   const std::string format,
                                   va_list vargs) */

    ILogger &
    ILogger::fatal(const size_t section,
                   const std::string format,
                   ...)
    {
        assert(format != "");

        va_list vargs;
        va_start(vargs, format);
        voutput(section, LogLevel::Fatal, format, vargs);
        va_end(vargs);

        return * this;
    } /* end of : ILogger &
                  ILogger::fatal(const size_t section,
                                 const std::string format,
                                 ...) */

    ILogger &
    ILogger::vfatal(const size_t section,
                    const std::string format,
                    va_list vargs)
    {
        assert(format != "");

        return voutput(section, LogLevel::Fatal, format, vargs);
    } /* end of : ILogger &
                  ILogger::vfatal(const size_t section,
                                  const std::string format,
                                  va_list vargs) */

    ILogger &
    ILogger::error(const size_t section,
                   const std::string format,
                   ...)
    {
        assert(format != "");

        va_list vargs;
        va_start(vargs, format);
        voutput(section, LogLevel::Error, format, vargs);
        va_end(vargs);

        return * this;
    } /* end of : ILogger &
                  ILogger::error(const size_t section,
                                 const std::string format,
                                 ...) */

    ILogger &
    ILogger::verror(const size_t section,
                    const std::string format,
                    va_list vargs)
    {
        assert(format != "");

        return voutput(section, LogLevel::Error, format, vargs);
    } /* end of : ILogger &
                  ILogger::verror(const size_t section,
                                  const std::string format,
                                  va_list vargs) */

    ILogger &
    ILogger::warning(const size_t section,
                     const std::string format,
                     ...)
    {
        assert(format != "");

        va_list vargs;
        va_start(vargs, format);
        voutput(section, LogLevel::Warning, format, vargs);
        va_end(vargs);

        return * this;
    } /* end of : ILogger &
                  ILogger::warning(const size_t section,
                                   const std::string format,
                                   ...) */

    ILogger &
    ILogger::vwarning(const size_t section,
                      const std::string format,
                      va_list vargs)
    {
        assert(format != "");

        return voutput(section, LogLevel::Warning, format, vargs);
    } /* end of : ILogger &
                  ILogger::vwarning(const size_t section,
                                    const std::string format,
                                    va_list vargs) */

    ILogger &
    ILogger::notice(const size_t section,
                    const std::string format,
                    ...)
    {
        assert(format != "");

        va_list vargs;
        va_start(vargs, format);
        voutput(section, LogLevel::Notice, format, vargs);
        va_end(vargs);

        return * this;
    } /* end of : ILogger &
                  ILogger::notice(const size_t section,
                                  const std::string format,
                                  ...) */

    ILogger &
    ILogger::vnotice(const size_t section,
                     const std::string format,
                     va_list vargs)
    {
        assert(format != "");

        return voutput(section, LogLevel::Notice, format, vargs);
    } /* end of : ILogger &
                  ILogger::vnotice(const size_t section,
                                   const std::string format,
                                   va_list vargs) */

    ILogger &
    ILogger::debug(const size_t section,
                   const std::string format,
                   ...)
    {
        assert(format != "");

        va_list vargs;
        va_start(vargs, format);
        voutput(section, LogLevel::Debug, format, vargs);
        va_end(vargs);

        return * this;
    } /* end of : ILogger &
                  ILogger::debug(const size_t section,
                                 const std::string format,
                                 ...) */

    ILogger &
    ILogger::vdebug(const size_t section,
                    const std::string format,
                    va_list vargs)
    {
        assert(format != "");

        return voutput(section, LogLevel::Debug, format, vargs);
    } /* end of : ILogger &
                  ILogger::vdebug(const size_t section,
                                  const std::string format,
                                  va_list vargs) */

    void
    ILogger::process(const size_t section,
                     const LogLevel level,
                     const std::string format,
                     va_list vargs)
    {
        assert(level != LogLevel::None);
        assert(format != "");

        time_t rawtime{0};
        time(&rawtime);

 #if defined(__WINDOWS__)
        struct tm timeinfo;
        localtime_s(&timeinfo, &rawtime);

        auto str_time = vstring("[%02d/%02d/%4d %02d:%02d:%02d] ",
                                timeinfo.tm_mday,
                                timeinfo.tm_mon + 1,
                                timeinfo.tm_year + 1900,
                                timeinfo.tm_hour,
                                timeinfo.tm_min,
                                timeinfo.tm_sec);
#else
        struct tm * timeinfo{nullptr};
        timeinfo = localtime(&rawtime);

        auto str_time = vstring("[%02d/%02d/%4d %02d:%02d:%02d] ",
                                timeinfo->tm_mday,
                                timeinfo->tm_mon + 1,
                                timeinfo->tm_year + 1900,
                                timeinfo->tm_hour,
                                timeinfo->tm_min,
                                timeinfo->tm_sec);
#endif

        auto str_message = vvstring(format.c_str(), vargs);
        auto str_newline = std::string{"\n"};

        m_stream->write(str_time.c_str(), 1, str_time.size());
        m_stream->write(str_message.c_str(), 1, str_message.size());
        m_stream->write(str_newline.c_str(), 1, str_newline.size());
    } /* end of : void
                  ILogger::process(const size_t section,
                                   const LogLevel level,
                                   const std::string format,
                                   va_list vargs) */

} // end of : namespace cgate
