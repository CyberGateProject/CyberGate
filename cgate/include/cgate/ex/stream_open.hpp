#pragma once

#include "cgate/export.hpp"
#include "cgate/ex/istream.hpp"

namespace cgate
{
    namespace ex
    {
        /// @brief
        class StreamOpen : public IStream
        {
        public:
            /// @brief
            ///
            /// @param message
            StreamOpen(const std::string message = "File open error") noexcept
                : IStream{message}
            {

            } /* end of : StreamOpen(const std::string message) noexcept */

        }; // end of : class StreamOpen

    } // end of : namespace ex

} // end of : namespace cgate
