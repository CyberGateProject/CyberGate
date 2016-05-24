#include "cgate/log/logger_factory.hpp"
#include "cgate/log/console_logger.hpp"
#include "cgate/log/file_logger.hpp"

#include <cassert>

namespace cgate
{
    std::unique_ptr<LoggerFactory> LoggerFactory::m_singleton{nullptr};

    LoggerFactory::LoggerFactory(void)
    {

    } /* end of : LoggerFactory::LoggerFactory(void) */

    LoggerFactory&
    LoggerFactory::getSingleton(void)
    {
        if (m_singleton.get() == nullptr)
            m_singleton.reset(new LoggerFactory{});

        return *m_singleton.get();
    } /* end of : LoggerFactory&
                  LoggerFactory::getSingleton(void) */

    ILogger&
    LoggerFactory::createConsoleLogger(const std::string key,
                                       const LogLevel level)
    {
        assert(key != "");

        return *m_manager.add(key, new ConsoleLogger{level});
    } /* end of : ILogger&
                  LoggerFactory::createConsoleLogger(const std::string key,
                                                     const LogLevel level) */

    ILogger&
    LoggerFactory::createFileLogger(const std::string key,
                                    const std::string path,
                                    const bool do_clear,
                                    const LogLevel level)
    {
        assert(key != "");
        assert(path != "");

        return *m_manager.add(key, new FileLogger{path, do_clear, level});
    } /* end of : ILogger&
                  LoggerFactory::createFileLogger(const std::string key,
                                                  const std::string path,
                                                  const bool do_clear,
                                                  const LogLevel level) */

    void
    LoggerFactory::output(const size_t section,
                          const LogLevel level,
                          const std::string format,
                          ...)
    {
        assert(level != LogLevel::None);
        assert(format != "");

        for (auto it = m_manager.begin(), end = m_manager.end();
             it != end;
             ++it)
        {
            va_list vargs;
            va_start(vargs, format);
            it->second->voutput(section, level, format, vargs);
            va_end(vargs);
        }
    } /* end of : void
                  LoggerFactory::output(const size_t section,
                                        const LogLevel level,
                                        const std::string format,
                                        ...) */

    void
    LoggerFactory::voutput(const size_t section,
                           const LogLevel level,
                           const std::string format,
                           va_list vargs)
    {
        assert(level != LogLevel::None);
        assert(format != "");

        for (auto it = m_manager.begin(), end = m_manager.end();
             it != end;
             ++it)
            it->second->voutput(section, level, format, vargs);
    } /* end of : void
                  LoggerFactory::voutput(const size_t section,
                                         const LogLevel level,
                                         const std::string format,
                                         va_list vargs) */

    void
    LoggerFactory::fatal(const size_t section,
                         const std::string format,
                         ...)
    {
        assert(format != "");

        for (auto it = m_manager.begin(), end = m_manager.end();
             it != end;
             ++it)
        {
            va_list vargs;
            va_start(vargs, format);
            it->second->vfatal(section, format, vargs);
            va_end(vargs);
        }
    } /* end of : void
                  LoggerFactory::fatal(const size_t section,
                                       const std::string format,
                                       ...) */

    void
    LoggerFactory::vfatal(const size_t section,
                          const std::string format,
                          va_list vargs)
    {
        assert(format != "");

        for (auto it = m_manager.begin(), end = m_manager.end();
             it != end;
             ++it)
            it->second->vfatal(section, format, vargs);
    } /* end of : void
                  LoggerFactory::vfatal(const size_t section,
                                        const std::string format,
                                        va_list vargs) */

    void
    LoggerFactory::error(const size_t section,
                         const std::string format,
                         ...)
    {
        assert(format != "");

        for (auto it = m_manager.begin(), end = m_manager.end();
             it != end;
             ++it)
        {
            va_list vargs;
            va_start(vargs, format);
            it->second->verror(section, format, vargs);
            va_end(vargs);
        }
    } /* end of : void
                  LoggerFactory::error(const size_t section,
                                       const std::string format,
                                       ...) */

    void
    LoggerFactory::verror(const size_t section,
                          const std::string format,
                          va_list vargs)
    {
        assert(format != "");

        for (auto it = m_manager.begin(), end = m_manager.end();
             it != end;
             ++it)
            it->second->verror(section, format, vargs);
    } /* end of : void
                  LoggerFactory::verror(const size_t section,
                                        const std::string format,
                                        va_list vargs) */

    void
    LoggerFactory::warning(const size_t section,
                           const std::string format,
                           ...)
    {
        assert(format != "");

        for (auto it = m_manager.begin(), end = m_manager.end();
             it != end;
             ++it)
        {
            va_list vargs;
            va_start(vargs, format);
            it->second->vwarning(section, format, vargs);
            va_end(vargs);
        }
    } /* end of : void
                  LoggerFactory::warning(const size_t section,
                                         const std::string format,
                                         ...) */

    void
    LoggerFactory::vwarning(const size_t section,
                            const std::string format,
                            va_list vargs)
    {
        assert(format != "");

        for (auto it = m_manager.begin(), end = m_manager.end();
             it != end;
             ++it)
            it->second->vwarning(section, format, vargs);
    } /* end of : void
                  LoggerFactory::vwarning(const size_t section,
                                          const std::string format,
                                          va_list vargs) */

    void
    LoggerFactory::notice(const size_t section,
                          const std::string format,
                          ...)
    {
        assert(format != "");

        for (auto it = m_manager.begin(), end = m_manager.end();
             it != end;
             ++it)
        {
            va_list vargs;
            va_start(vargs, format);
            it->second->vnotice(section, format, vargs);
            va_end(vargs);
        }
    } /* end of : void
                  LoggerFactory::notice(const size_t section,
                                        const std::string format,
                                        ...) */

    void
    LoggerFactory::vnotice(const size_t section,
                           const std::string format,
                           va_list vargs)
    {
        assert(format != "");

        for (auto it = m_manager.begin(), end = m_manager.end();
             it != end;
             ++it)
            it->second->vnotice(section, format, vargs);
    } /* end of : void
                  LoggerFactory::vnotice(const size_t section,
                                         const std::string format,
                                         va_list vargs) */

    void
    LoggerFactory::debug(const size_t section,
                         const std::string format,
                         ...)
    {
        assert(format != "");

        for (auto it = m_manager.begin(), end = m_manager.end();
             it != end;
             ++it)
        {
            va_list vargs;
            va_start(vargs, format);
            it->second->vdebug(section, format, vargs);
            va_end(vargs);
        }
    } /* end of : void
                  LoggerFactory::debug(const size_t section,
                                       const std::string format,
                                       ...) */

    void
    LoggerFactory::vdebug(const size_t section,
                          const std::string format,
                          va_list vargs)
    {
        assert(format != "");

        for (auto it = m_manager.begin(), end = m_manager.end();
             it != end;
             ++it)
            it->second->vdebug(section, format, vargs);
    } /* end of : void
                  LoggerFactory::vdebug(const size_t section,
                                        const std::string format,
                                        va_list vargs) */

} // end of : namespace cgate