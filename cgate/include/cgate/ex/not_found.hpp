#pragma once

#include "cgate/export.hpp"
#include "cgate/ex/icontainer.hpp"

namespace cgate
{
    namespace ex
    {
        /// @brief
        class NotFound : public IContainer
        {
        public:
            /// @brief
            ///
            /// @param message
            NotFound(const std::string message = "Element not found") noexcept
                : IContainer{message}
            {

            } /* end of : NotFound(const std::string message) noexcept */

        }; // end of : class NotFound

    } // end of : namespace ex

} // end of : namespace cgate
