#include "cgate/ex/thread.hpp"
#include "cgate/thread/thread.hpp"

#include <cassert>

namespace cgate
{
    Thread::Thread(IRunnable* runnable)
        : m_runnable{runnable}
        , m_thread{new sf::Thread{&IRunnable::proc, runnable}}
        , m_running{false}
    {
        assert(runnable != nullptr);
    } /* end of : Thread::Thread(IRunnable* runnable) */

    Thread::~Thread(void)
    {
        cancel();
    } /* end of : Thread::~Thread(void) */

    bool
    Thread::isRunning(void)
    {
        return m_running != 0;
    } /* end of : bool
                  Thread::isRunning(void) */

    void
    Thread::start(void)
    {
        if (m_running)
            return;

        m_running = true;
        m_thread->launch();
    } /* end of : void
                  Thread::start(void) */

    void
    Thread::join(void)
    {
        if (!m_running)
            return;

        m_thread->wait();
        m_running = false;
    } /* end of : void
                  Thread::join(void) */

    void
    Thread::cancel(void)
    {
        if (!m_running)
            return;

        m_thread->terminate();
        m_running = false;
    } /* end of : void
                  Thread::cancel(void) */

} // end of : namespace cgate