#include "cgate/core/log/console_logger.hpp"
#include "cgate/core/stream/console_stream.hpp"

namespace cgate
{
    ConsoleLogger::ConsoleLogger(const LogLevel level)
        : ILogger{level}
    {
        m_stream.reset(new ConsoleStream{});
    } /* end of : ConsoleLogger::ConsoleLogger(const LogLevel level) */

} // end of : namesapce cgate