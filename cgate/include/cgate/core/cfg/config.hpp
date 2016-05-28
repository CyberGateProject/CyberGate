#pragma once

#include "cgate/export.hpp"

#include <string>
#include <map>
#include <memory>

namespace cgate
{
    /// @brief
    class CGATE_API Config
    {
    private:
        /// @brief
        Config(void);

    public:
        /// @brief
        ///
        /// @param file
        static void
        load(const std::string file);

        /// @brief
        ///
        /// @param file
        static void
        save(const std::string file);

        /// @brief
        ///
        /// @param key
        /// @return
        static bool
        exists(const std::string key);

        /// @brief
        ///
        /// @param key
        /// @return
        static int
        getInteger(const std::string key);

        /// @brief
        ///
        /// @param key
        /// @return
        static float
        getFloat(const std::string key);

        /// @brief
        ///
        /// @param key
        /// @return
        static std::string
        getString(const std::string key);

        /// @brief
        ///
        /// @param key
        /// @param value
        static void
        set(const std::string key,
            const int value);

        /// @brief
        ///
        /// @param key
        /// @param value
        static void
        set(const std::string key,
            const float value);

        /// @brief
        ///
        /// @param key
        /// @param value
        static void
        set(const std::string key,
            const std::string value);

        /// @brief
        static void
        clear(void);

    private:
        /// @brief
        static std::unique_ptr<Config> m_singleton;

        /// @brief
        std::map<std::string, std::string> m_entries;

    }; // end of : class Config

} // end of : namespace cgate
