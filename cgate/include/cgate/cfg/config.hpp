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
        /// @return
        static Config&
        getSingleton(void);

        /// @brief
        ///
        /// @param key
        /// @return
        std::string
        operator [](const std::string key) const;

        /// @brief
        ///
        /// @param file
        /// @return
        Config&
        load(const std::string file);

        /// @brief
        ///
        /// @param file
        /// @return
        Config&
        save(const std::string file);

        /// @brief
        ///
        /// @param key
        /// @return
        bool
        exists(const std::string key) const;

        /// @brief
        ///
        /// @param key
        /// @return
        int
        getInteger(const std::string key) const;

        /// @brief
        ///
        /// @param key
        /// @return
        float
        getFloat(const std::string key) const;

        /// @brief
        ///
        /// @param key
        /// @return
        std::string
        getString(const std::string key) const;

        /// @brief
        ///
        /// @param key
        /// @param value
        /// @return
        Config&
        set(const std::string key,
            const int value);

        /// @brief
        ///
        /// @param key
        /// @param value
        /// @return
        Config&
        set(const std::string key,
            const float value);

        /// @brief
        ///
        /// @param key
        /// @param value
        /// @return
        Config&
        set(const std::string key,
            const std::string value);

        /// @brief
        ///
        /// @return
        Config&
        clear(void);

    private:
        /// @brief
        static std::unique_ptr<Config> m_singleton;

        /// @brief
        std::map<std::string, std::string> m_entries;

    }; // end of : class Config

} // end of : namespace cgate
