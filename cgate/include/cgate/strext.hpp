#pragma once

#include "cgate/export.hpp"

#include <string>

namespace cgate
{
    /// @brief
    ///
    /// @param str
    /// @return
    CGATE_API std::string
    rtrim(std::string str);

    /// @brief
    ///
    /// @param str
    /// @return
    CGATE_API std::string
    ltrim(std::string str);

    /// @brief
    ///
    /// @param str
    /// @return
    CGATE_API std::string
    trim(std::string str);

    /// @brief
    ///
    /// @param format
    /// @param ...
    /// @return
    CGATE_API std::string
    vstring(const std::string format,
            ...);

} // end of : namespace cgate
