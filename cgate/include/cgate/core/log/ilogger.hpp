#pragma once

#include "cgate/export.hpp"
#include "cgate/core/log/log_level.hpp"
#include "cgate/core/stream/istream.hpp"

#include <cstdarg>
#include <map>
#include <memory>
#include <string>

namespace cgate
{
    class CGATE_API ILogger
    {
    protected:
        /// @brief
        ///
        /// @param level
        ILogger(const LogLevel level = LogLevel::Warning);

    public:
        /// @brief
        ///
        /// @param section
        /// @return
        LogLevel
        getLevel(const size_t section) const;

        /// @brief
        ///
        /// @param section
        /// @param level
        /// @return
        ILogger &
        setLevel(const size_t section,
                 const LogLevel level);

        /// @brief
        ///
        /// @return
        LogLevel
        getDefaultLevel(void) const;

        /// @brief
        ///
        /// @param level
        /// @return
        ILogger &
        setDefaultLevel(const LogLevel level);

        /// @brief
        ///
        /// @param section
        /// @param level
        /// @param format
        /// @param ...
        /// @return
        ILogger &
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
        /// @return
        ILogger &
        voutput(const size_t section,
                const LogLevel level,
                const std::string format,
                va_list vargs);

        /// @brief
        ///
        /// @param section
        /// @param format
        /// @param ...
        /// @return
        ILogger &
        fatal(const size_t section,
              const std::string format,
              ...);

        /// @brief
        ///
        /// @param section
        /// @param format
        /// @param vargs
        /// @return
        ILogger &
        vfatal(const size_t section,
               const std::string format,
               va_list vargs);

        /// @brief
        ///
        /// @param section
        /// @param format
        /// @param ...
        /// @return
        ILogger &
        error(const size_t section,
              const std::string format,
              ...);

        /// @brief
        ///
        /// @param section
        /// @param format
        /// @param vargs
        /// @return
        ILogger &
        verror(const size_t section,
               const std::string format,
               va_list vargs);

        /// @brief
        ///
        /// @param section
        /// @param format
        /// @param ...
        /// @return
        ILogger &
        warning(const size_t section,
                const std::string format,
                ...);

        /// @brief
        ///
        /// @param section
        /// @param format
        /// @param vargs
        /// @return
        ILogger &
        vwarning(const size_t section,
                 const std::string format,
                 va_list vargs);

        /// @brief
        ///
        /// @param section
        /// @param format
        /// @param ...
        /// @return
        ILogger &
        notice(const size_t section,
               const std::string format,
               ...);

        /// @brief
        ///
        /// @param section
        /// @param format
        /// @param vargs
        /// @return
        ILogger &
        vnotice(const size_t section,
                const std::string format,
                va_list vargs);

        /// @brief
        ///
        /// @param section
        /// @param format
        /// @param ...
        /// @return
        ILogger &
        debug(const size_t section,
              const std::string format,
              ...);

        /// @brief
        ///
        /// @param section
        /// @param format
        /// @param vargs
        /// @return
        ILogger &
        vdebug(const size_t section,
               const std::string format,
               va_list vargs);

    protected:
        /// @brief
        ///
        /// @param section
        /// @param level
        /// @param format
        /// @param vargs
        void
        process(const size_t section,
                const LogLevel level,
                const std::string format,
                va_list vargs);

    protected:
        /// @brief
        LogLevel m_default_level;

        /// @brief
        std::map<size_t, LogLevel> m_sections;

        /// @brief
        std::unique_ptr<IStream> m_stream;

    }; // end of : class ILogger

} // end of : namespace cgate
