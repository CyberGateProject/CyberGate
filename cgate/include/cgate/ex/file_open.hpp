#pragma once

#include "cgate/export.hpp"
#include "cgate/ex/ifile.hpp"

namespace cgate
{
    namespace ex
    {
        /// @brief
        class FileOpen : public IFile
        {
        public:
            /// @brief
            ///
            /// @param message
            FileOpen(const std::string message = "File open error") noexcept
                : IFile{message}
            {

            } /* end of : FileOpen(const std::string message) noexcept */

        }; // end of : class FileOpen

    } // end of : namespace ex

} // end of : namespace cgate
