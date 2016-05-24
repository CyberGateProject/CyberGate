#include "cgate/log/console_logger.hpp"

namespace cgate
{
    ConsoleLogger::ConsoleLogger(const LogLevel level)
        : ILogger{level}
    {

    } /* end of : ConsoleLogger::ConsoleLogger(const LogLevel level) */

    FILE*
    ConsoleLogger::openStream(void)
    {
        return stdout;
    } /* end of : FILE*
                  ConsoleLogger::openStream(void) */

    void
    ConsoleLogger::closeStream(FILE* stream)
    {

    } /* end of : void
                  ConsoleLogger::closeStream(FILE* stream) */

} // end of : namesapce cgate