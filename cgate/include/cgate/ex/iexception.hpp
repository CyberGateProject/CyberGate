#pragma once

#include "cgate/export.hpp"

#include <exception>
#include <string>

namespace cgate
{
    namespace ex
    {
        /// @brief
        class IException : public std::exception
        {
        protected:
            /// @brief
            ///
            /// @param message
            IException(const std::string message = "") noexcept
                : m_message{message}
            {

            } /* end of : IException(const std::string message) noexcept */

        public:
            /// @brief
            ///
            /// @return
            virtual const char*
            what() const noexcept
            {
                return m_message.c_str();
            } /* end of : virtual const char*
                          what() const noexcept */

        protected:
            /// @brief
            std::string m_message;

        }; // end of : class IException

    } // end of : namespace ex

} // end of : namespace cgate
