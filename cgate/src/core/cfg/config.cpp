#include "cgate/core/strext.hpp"
#include "cgate/core/cfg/config.hpp"
#include "cgate/ex/stream_open.hpp"

#include <cassert>
#include <fstream>
#include <sstream>

namespace cgate
{
    std::unique_ptr<Config> Config::m_singleton{nullptr};

    Config::Config(void)
    {

    } /* end of : Config::Config(void) */

    void
    Config::load(const std::string file)
    {
        assert(file != "");

        if (m_singleton.get() == nullptr)
            m_singleton.reset(new Config{});

        // TODO : use cgate::File

        std::ifstream stream{file, std::ios::in};
        if (!stream.is_open())
            throw ex::StreamOpen{vstring("Error opening the requested stream : %s", file.c_str())};

        char buffer[1024];
        while (stream.getline(buffer, 1024))
        {
            std::string line{buffer};
            auto pos = line.find_first_of('#');
            if (pos != std::string::npos)
                line = line.substr(0, pos);

            pos = line.find_first_of('=');
            if (pos == std::string::npos)
                continue;

            m_singleton->set(trim(line.substr(0, pos)), trim(line.substr(pos + 1)));
        }
    } /* end of : void
                  Config::load(const std::string file) */

    void
    Config::save(const std::string file)
    {
        assert(file != "");

        if (m_singleton.get() == nullptr)
            m_singleton.reset(new Config{});

        // TODO : use cgate::File

        std::ofstream stream{file, std::ios::out};
        if (!stream.is_open())
            throw ex::StreamOpen{vstring("Error opening the requested stream : %s", file.c_str())};

        for (auto it = m_singleton->m_entries.begin(), end = m_singleton->m_entries.end();
             it != end;
             it++)
            stream << it->first << " = " << it->second << std::endl;
    } /* end of : void
                  Config::save(const std::string file) */

    bool
    Config::exists(const std::string key) const
    {
        assert(key != "");

        if (m_singleton.get() == nullptr)
            m_singleton.reset(new Config{});

        return m_singleton->m_entries.find(key) != m_singleton->m_entries.end();
    } /* end of : bool
                  Config::exists(const std::string key) const */

    int
    Config::getInteger(const std::string key)
    {
        assert(key != "");

        if (m_singleton.get() == nullptr)
            m_singleton.reset(new Config{});

        auto it = m_singleton->m_entries.find(key);
        if (it == m_singleton->m_entries.end())
            return 0;

        int value{0};

        std::stringstream ss{it->second};
        ss >> value;

        return value;
    } /* end of : int
                  Config::getInteger(const std::string key) */

    float
    Config::getFloat(const std::string key)
    {
        assert(key != "");

        if (m_singleton.get() == nullptr)
            m_singleton.reset(new Config{});

        auto it = m_singleton->m_entries.find(key);
        if (it == m_singleton->m_entries.end())
            return 0;

        float value{0};

        std::stringstream ss{it->second};
        ss >> value;

        return value;
    } /* end of : float
                  Config::getFloat(const std::string key) */

    std::string
    Config::getString(const std::string key)
    {
        assert(key != "");

        if (m_singleton.get() == nullptr)
            m_singleton.reset(new Config{});

        auto it = m_singleton->m_entries.find(key);
        if (it == m_singleton->m_entries.end())
            return "";

        return it->second;
    } /* end of : std::string
                  Config::getString(const std::string key) */

    void
    Config::set(const std::string key,
                const int value)
    {
        assert(key != "");

        if (m_singleton.get() == nullptr)
            m_singleton.reset(new Config{});

        std::stringstream ss;
        ss << value;

        m_singleton->m_entries[key] = ss.str();
    } /* end of : void
                  Config::set(const std::string key,
                              const int value) */

    void
    Config::set(const std::string key,
                const float value)
    {
        assert(key != "");

        if (m_singleton.get() == nullptr)
            m_singleton.reset(new Config{});

        std::stringstream ss;
        ss << value;

        m_singleton->m_entries[key] = ss.str();
    } /* end of : void
                  Config::set(const std::string key,
                              const float value) */

    void
    Config::set(const std::string key,
                const std::string value)
    {
        assert(key != "");

        if (m_singleton.get() == nullptr)
            m_singleton.reset(new Config{});

        m_singleton->m_entries[key] = value;
    } /* end of : void
                  Config::set(const std::string key,
                              const std::string value) */

    void
    Config::clear(void)
    {
        if (m_singleton.get() == nullptr)
            m_singleton.reset(new Config{});

        m_singleton->m_entries.clear();
    } /* end of : void
                  Config::clear(void) */

} // end of : namespace cgate
