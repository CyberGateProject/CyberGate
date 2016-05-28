#pragma once

#include "cgate/export.hpp"
#include "cgate/ex/isystem.hpp"

namespace cgate
{
    namespace ex
    {
        /// @brief
        class IThreading : public ISystem
        {
        protected:
            /// @brief
            ///
            /// @param message
            IThreading(const std::string message = "") noexcept
                : ISystem{message}
            {

            } /* end of : IThreading(const std::string message) noexcept */

        }; // end of : class IThreading

    } // end of : namespace ex

} // end of : namespace cgate
