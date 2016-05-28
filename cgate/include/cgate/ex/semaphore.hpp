#pragma once

#include "cgate/export.hpp"
#include "cgate/ex/ithreading.hpp"

namespace cgate
{
    namespace ex
    {
        /// @brief
        class Semaphore : public IThreading
        {
        public:
            /// @brief
            ///
            /// @param message
            Semaphore(const std::string message = "Semaphore error") noexcept
                : IThreading{message}
            {

            } /* end of : Semaphore(const std::string message) noexcept */

        }; // end of : class Semaphore

    } // end of : namespace ex

} // end of : namespace cgate
