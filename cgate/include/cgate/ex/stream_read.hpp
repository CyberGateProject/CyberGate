#pragma once

#include "cgate/export.hpp"
#include "cgate/ex/istream.hpp"

namespace cgate
{
    namespace ex
    {
        /// @brief
        class StreamRead : public IStream
        {
        public:
            /// @brief
            ///
            /// @param message
            StreamRead(const std::string message = "File read error") noexcept
                : IStream{message}
            {

            } /* end of : StreamRead(const std::string message) noexcept */

        }; // end of : class StreamRead

    } // end of : namespace ex

} // end of : namespace cgate
