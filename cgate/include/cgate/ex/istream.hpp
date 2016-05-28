#pragma once

#include "cgate/export.hpp"
#include "cgate/ex/iexception.hpp"

namespace cgate
{
    namespace ex
    {
        /// @brief
        class IStream : public IException
        {
        public:
            /// @brief
            ///
            /// @param message
            IStream(const std::string message = "") noexcept
                : IException{message}
            {

            } /* end of : IStream(const std::string message) noexcept */

        }; // end of : class IStream

    } // end of : namespace ex

} // end of : namespace cgate
