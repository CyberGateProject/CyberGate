#pragma once

#include "cgate/export.hpp"
#include "cgate/core/pattern/ifactory.hpp"
#include "cgate/core/thread/thread.hpp"

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
        /// @param key
        /// @param runnable
        /// @return
        ///
        /// @throw ex::Duplicate
        static Thread &
        create(const std::string key,
               IRunnable * runnable);

    private:
        /// @brief
        static std::unique_ptr<ThreadFactory> m_singleton;

    }; // end of : class ThreadFactory : public pattern::IFactory<std::string, Thread>

} // end of : namespace cgate
