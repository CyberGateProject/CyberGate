#pragma once

#include "cgate/export.hpp"
#include "cgate/ex/ithreading.hpp"

namespace cgate
{
    namespace ex
    {
        /// @brief
        class Mutex : public IThreading
        {
        public:
            /// @brief
            ///
            /// @param message
            Mutex(const std::string message = "Mutex error") noexcept
                : IThreading{message}
            {

            } /* end of : Mutex(const std::string message) noexcept */

        }; // end of : class Mutex

    } // end of : namespace ex

} // end of : namespace cgate
