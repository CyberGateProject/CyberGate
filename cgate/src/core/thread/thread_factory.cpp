#include "cgate/core/thread/thread_factory.hpp"

#include <cassert>

namespace cgate
{
    std::unique_ptr<ThreadFactory> ThreadFactory::m_singleton{nullptr};

    ThreadFactory::ThreadFactory(void)
    {

    } /* end of : ThreadFactory::ThreadFactory(void) */

    Thread &
    ThreadFactory::create(const std::string key,
                          IRunnable* runnable)
    {
        assert(key != "");
        assert(runnable != nullptr);

        if (m_singleton.get() == nullptr)
            m_singleton.reset(new ThreadFactory{});

        return * m_singleton->m_manager.add(key, new Thread{key, runnable});
    } /* end of : Thread &
                  ThreadFactory::create(const std::string key,
                                        IRunnable* runnable) */

} // end of : namespace cgate
