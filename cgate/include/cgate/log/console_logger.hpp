#pragma once

#include "cgate/export.hpp"
#include "cgate/log/ilogger.hpp"

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

    protected:
        /// @brief
        ///
        /// @return
        FILE*
        openStream(void);

        /// @brief
        ///
        /// @param stream
        void
        closeStream(FILE* stream);

    }; // end of : class ConsoleLogger

} // end of : namespace cgate
