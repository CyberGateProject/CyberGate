#pragma once

#include "cgate/export.hpp"
#include "cgate/ex/ifile.hpp"

namespace cgate
{
    namespace ex
    {
        /// @brief
        class FileWrite : public IFile
        {
        public:
            /// @brief
            ///
            /// @param message
            FileWrite(const std::string message = "File write error") noexcept
                : IFile{message}
            {

            } /* end of : FileWrite(const std::string message) noexcept */

        }; // end of : class FileWrite

    } // end of : namespace ex

} // end of : namespace cgate
