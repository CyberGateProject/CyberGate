#pragma once

#include "cgate/export.hpp"
#include "cgate/core/log/ilogger.hpp"

namespace cgate
{
    /// @brief
    class CGATE_API FileLogger : public ILogger
    {
    public:
        /// @brief
        ///
        /// @param path
        /// @param do_clear
        /// @param level
        ///
        /// @throw ex::File
        FileLogger(const std::string path,
                   const bool do_clear = false,
                   const LogLevel level = LogLevel::Warning);

        /// @brief
        ///
        /// @return
        std::string
        getPath(void) const;

    protected:
        /// @brief
        std::string m_path;

    }; // end of : class FileLogger

} // end of : namespace cgate
