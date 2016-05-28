#pragma once

#include "cgate/export.hpp"
#include "cgate/ex/ithreading.hpp"

namespace cgate
{
    namespace ex
    {
        /// @brief
        class Condition : public IThreading
        {
        public:
            /// @brief
            ///
            /// @param message
            Condition(const std::string message = "Condition error") noexcept
                : IThreading{message}
            {

            } /* end of : Condition(const std::string message) noexcept */

        }; // end of : class Condition

    } // end of : namespace ex

} // end of : namespace cgate
