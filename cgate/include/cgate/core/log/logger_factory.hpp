#pragma once

#include "cgate/export.hpp"
#include "cgate/core/log/ilogger.hpp"
#include "cgate/core/pattern/ifactory.hpp"

#include <string>

namespace cgate
{
    /// @brief
    class CGATE_API LoggerFactory : public pattern::IFactory<std::string, ILogger>
    {
    private:
        /// @brief
        LoggerFactory(void);

    public:
        /// @brief
        ///
        /// @param key
        /// @param level
        /// @return
        ///
        /// @throw ex::Duplicate
        static ILogger &
        createConsoleLogger(const std::string key,
                            const LogLevel level = LogLevel::Warning);

        /// @brief
        ///
        /// @param key
        /// @param path
        /// @param do_clear
        /// @param level
        /// @return
        ///
        /// @throw ex::Duplicate
        static ILogger &
        createFileLogger(const std::string key,
                         const std::string path,
                         const bool do_clear = false,
                         const LogLevel level = LogLevel::Warning);

        /// @brief
        ///
        /// @param section
        /// @param level
        /// @param format
        /// @param ...
        static void
        output(const size_t section,
               const LogLevel level,
               const std::string format,
               ...);

        /// @brief
        ///
        /// @param section
        /// @param level
        /// @param format
        /// @param vargs
        static void
        voutput(const size_t section,
                const LogLevel level,
                const std::string format,
                va_list vargs);

        /// @brief
        ///
        /// @param section
        /// @param format
        /// @param ...
        static void
        fatal(const size_t section,
              const std::string format,
              ...);

        /// @brief
        ///
        /// @param section
        /// @param format
        /// @param vargs
        static void
        vfatal(const size_t section,
               const std::string format,
               va_list vargs);

        /// @brief
        ///
        /// @param section
        /// @param format
        /// @param ...
        static void
        error(const size_t section,
              const std::string format,
              ...);

        /// @brief
        ///
        /// @param section
        /// @param format
        /// @param vargs
        static void
        verror(const size_t section,
               const std::string format,
               va_list vargs);

        /// @brief
        ///
        /// @param section
        /// @param format
        /// @param ...
        static void
        warning(const size_t section,
                const std::string format,
                ...);

        /// @brief
        ///
        /// @param section
        /// @param format
        /// @param vargs
        static void
        vwarning(const size_t section,
                 const std::string format,
                 va_list vargs);

        /// @brief
        ///
        /// @param section
        /// @param format
        /// @param ...
        static void
        notice(const size_t section,
               const std::string format,
               ...);

        /// @brief
        ///
        /// @param section
        /// @param format
        /// @param vargs
        static void
        vnotice(const size_t section,
                const std::string format,
                va_list vargs);

        /// @brief
        ///
        /// @param section
        /// @param format
        /// @param ...
        static void
        debug(const size_t section,
              const std::string format,
              ...);

        /// @brief
        ///
        /// @param section
        /// @param format
        /// @param vargs
        static void
        vdebug(const size_t section,
               const std::string format,
               va_list vargs);

    private:
        /// @brief
        static std::unique_ptr<LoggerFactory> m_singleton;

    }; // end of : class LoggerFactory : public pattern::IFactory<std::string, ILogger>

} // end of : namespace cgate
