#pragma once

#include "cgate/export.hpp"
#include "cgate/pattern/ifactory.hpp"
#include "cgate/thread/thread.hpp"

#include <string>

namespace cgate
{
    /// @brief
    class CGATE_API ThreadFactory : public pattern::IFactory<std::string, Thread>
    {
    private:
        /// @brief
        ThreadFactory(void);

    public:
        /// @brief
        ///
        /// @return
        static ThreadFactory&
        getSingleton(void);

        /// @brief
        ///
        /// @param key
        /// @param runnable
        /// @return
        ///
        /// @throw ex::Duplicate
        Thread&
        create(const std::string key,
               IRunnable* runnable);

    private:
        /// @brief
        static std::unique_ptr<ThreadFactory> m_singleton;

    }; // end of : class ThreadFactory : public pattern::IFactory<std::string, Thread>

} // end of : namespace cgate
