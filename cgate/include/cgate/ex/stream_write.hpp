#pragma once

#include "cgate/export.hpp"
#include "cgate/ex/istream.hpp"

namespace cgate
{
    namespace ex
    {
        /// @brief
        class StreamWrite : public IStream
        {
        public:
            /// @brief
            ///
            /// @param message
            StreamWrite(const std::string message = "File write error") noexcept
                : IStream{message}
            {

            } /* end of : StreamWrite(const std::string message) noexcept */

        }; // end of : class StreamWrite

    } // end of : namespace ex

} // end of : namespace cgate
