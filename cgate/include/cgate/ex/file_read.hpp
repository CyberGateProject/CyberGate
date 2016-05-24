#pragma once

#include "cgate/export.hpp"
#include "cgate/ex/ifile.hpp"

namespace cgate
{
    namespace ex
    {
        /// @brief
        class FileRead : public IFile
        {
        public:
            /// @brief
            ///
            /// @param message
            FileRead(const std::string message = "File read error") noexcept
                : IFile{message}
            {

            } /* end of : FileRead(const std::string message) noexcept */

        }; // end of : class FileRead

    } // end of : namespace ex

} // end of : namespace cgate
