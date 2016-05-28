#pragma once

#include "cgate/export.hpp"
#include "cgate/core/log/ilogger.hpp"

namespace cgate
{
    /// @brief
    class CGATE_API ConsoleLogger : public ILogger
    {
    public:
        /// @brief
        ///
        /// @param level
        ConsoleLogger(const LogLevel level = LogLevel::Warning);

    }; // end of : class ConsoleLogger

} // end of : namespace cgate
