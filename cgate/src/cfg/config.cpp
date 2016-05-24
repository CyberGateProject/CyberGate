#include "cgate/strext.hpp"
#include "cgate/cfg/config.hpp"
#include "cgate/ex/file_open.hpp"

#include <cassert>
#include <fstream>
#include <sstream>

namespace cgate
{
    std::unique_ptr<Config> Config::m_singleton{nullptr};

    Config::Config(void)
    {

    } /* end of : Config::Config(void) */

    Config&
    Config::getSingleton(void)
    {
        if (m_singleton.get() == nullptr)
            m_singleton.reset(new Config{});
        return *m_singleton.get();
    } /* end of : Config&
                  Config::getSingleton(void) */

    std::string
    Config::operator [](const std::string key) const
    {
        assert(key != "");

        return getString(key);
    } /* end of : std::string
                  Config::operator [](const std::string key) const */

    Config&
    Config::load(const std::string file)
    {
        assert(file != "");

        std::ifstream stream{file, std::ios::in};
        if (!stream.is_open())
            throw ex::FileOpen{vstring("Error opening the requested stream : %s", file.c_str())};

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

            set(trim(line.substr(0, pos)), trim(line.substr(pos + 1)));
        }

        return *this;
    } /* end of : Config&
                  Config::load(const std::string file) */

    Config&
    Config::save(const std::string file)
    {
        assert(file != "");

        std::ofstream stream{file, std::ios::out};
        if (!stream.is_open())
            throw ex::FileOpen{vstring("Error opening the requested stream : %s", file.c_str())};

        for (auto it = m_entries.begin(), end = m_entries.end();
             it != end;
             it++)
            stream << it->first << " = " << it->second << std::endl;

        return *this;
    } /* end of : Config&
                  Config::save(const std::string file) */

    bool
    Config::exists(const std::string key) const
    {
        assert(key != "");

        return m_entries.find(key) != m_entries.end();
    } /* end of : bool
                  Config::exists(const std::string key) const */

    int
    Config::getInteger(const std::string key) const
    {
        assert(key != "");

        auto it = m_entries.find(key);
        if (it == m_entries.end())
            return 0;

        int value{0};

        std::stringstream ss{it->second};
        ss >> value;

        return value;
    } /* end of : int
                  Config::getInteger(const std::string key) const */

    float
    Config::getFloat(const std::string key) const
    {
        assert(key != "");

        auto it = m_entries.find(key);
        if (it == m_entries.end())
            return 0;

        float value{0};

        std::stringstream ss{it->second};
        ss >> value;

        return value;
    } /* end of : float
                  Config::getFloat(const std::string key) const */

    std::string
    Config::getString(const std::string key) const
    {
        assert(key != "");

        auto it = m_entries.find(key);
        if (it == m_entries.end())
            return "";

        return it->second;
    } /* end of : std::string
                  Config::getString(const std::string key) const */

    Config&
    Config::set(const std::string key,
                const int value)
    {
        assert(key != "");

        std::stringstream ss;
        ss << value;

        m_entries[key] = ss.str();

        return *this;
    } /* end of : Config&
                  Config::set(const std::string key,
                              const int value) */

    Config&
    Config::set(const std::string key,
                const float value)
    {
        assert(key != "");

        std::stringstream ss;
        ss << value;

        m_entries[key] = ss.str();

        return *this;
    } /* end of : Config&
                  Config::set(const std::string key,
                              const float value) */

    Config&
    Config::set(const std::string key,
                const std::string value)
    {
        assert(key != "");

        m_entries[key] = value;

        return *this;
    } /* end of : Config&
                  Config::set(const std::string key,
                              const std::string value) */

    Config&
    Config::clear(void)
    {
        m_entries.clear();

        return *this;
    } /* end of : Config&
                  Config::clear(void) */

} // end of : namespace cgate