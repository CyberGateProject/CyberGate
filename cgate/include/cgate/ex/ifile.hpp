#pragma once

#include "cgate/export.hpp"
#include "cgate/ex/iexception.hpp"

namespace cgate
{
    namespace ex
    {
        /// @brief
        class IFile : public IException
        {
        protected:
            /// @brief
            ///
            /// @param message
            IFile(const std::string message = "") noexcept
                : IException{message}
            {

            } /* end of : IFile(const std::string message) noexcept */

        }; // end of : class IFile

    } // end of : namespace ex

} // end of : namespace cgate
