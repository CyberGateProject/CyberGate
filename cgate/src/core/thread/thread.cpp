#include "cgate/ex/thread.hpp"
#include "cgate/core/thread/thread.hpp"

#include <cassert>

namespace cgate
{
    Thread::Thread(const std::string name,
                   IRunnable * runnable)
        : m_name{name}
        , m_runnable{runnable}
        , m_thread{nullptr}
    {
        assert(runnable != nullptr);
    } /* end of : Thread::Thread(const std::string name,
                                 IRunnable * runnable) */

    Thread::~Thread(void)
    {
        join();
    } /* end of : Thread::~Thread(void) */

    IRunnable *
    Thread::getRunnable(void) const
    {
        return m_runnable.get();
    } /* end of : IRunnable *
                  Thread::getRunnable(void) const */

    SDL_Thread *
    Thread::getSDL(void) const
    {
        return m_thread;
    } /* end of : SDL_Thread *
                  Thread::getSDL(void) const */

    bool
    Thread::isRunning(void)
    {
        return m_thread != nullptr;
    } /* end of : bool
                  Thread::isRunning(void) */

    Thread &
    Thread::start(void)
    {
        if (m_thread != nullptr)
            return * this;

        if (SDL_CreateThread(Thread::run, m_name.c_str(), m_runnable.get()) != 0)
            throw ex::Thread{"Error starting the thread"};

        return * this;
    } /* end of : Thread &
                  Thread::start(void) */

    int
    Thread::join(void)
    {
        if (m_thread == nullptr)
            return 0;

        int result{0};
        SDL_WaitThread(m_thread, &result);
        m_thread = nullptr;

        return result;
    } /* end of : int
                  Thread::join(void) */

    int
    Thread::run(void * runnable)
    {
        assert(runnable != nullptr);

        return ((IRunnable *) runnable)->proc();
    } /* end of : int
                  Thread::run(void * runnable) */

} // end of : namespace cgate
