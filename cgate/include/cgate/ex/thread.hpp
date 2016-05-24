#pragma once

#include "cgate/export.hpp"
#include "cgate/ex/isystem.hpp"

namespace cgate
{
    namespace ex
    {
        /// @brief
        class Thread : public ISystem
        {
        public:
            /// @brief
            ///
            /// @param message
            Thread(const std::string message = "Thread error") noexcept
                : ISystem{message}
            {

            } /* end of : Thread(const std::string message) noexcept */

        }; // end of : class Thread

    } // end of : namespace ex

} // end of : namespace cgate
