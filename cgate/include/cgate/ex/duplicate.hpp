#pragma once

#include "cgate/export.hpp"
#include "cgate/ex/icontainer.hpp"

namespace cgate
{
    namespace ex
    {
        /// @brief
        class Duplicate : public IContainer
        {
        public:
            /// @brief
            ///
            /// @param message
            Duplicate(const std::string message = "Duplicate element") noexcept
                : IContainer{message}
            {

            } /* end of : Duplicate(const std::string message) noexcept */

        }; // end of : class Duplicate

    } // end of : namespace ex

} // end of : namespace cgate
