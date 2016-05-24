#pragma once

#include "cgate/export.hpp"
#include "cgate/thread/irunnable.hpp"
#include "SFML/System/Thread.hpp"

#include <memory>

namespace cgate
{
    class CGATE_API ThreadFactory;

    /// @brief
    class CGATE_API Thread
    {
        friend class ThreadFactory;

    protected:
        /// @brief
        ///
        /// param runnable
        Thread(IRunnable* runnable);

    public:
        /// @brief
        ///
        /// @param thread
        Thread(const Thread& thread) = delete;

        /// @brief
        ///
        /// @param thread
        Thread(Thread&& thread) = delete;

        /// @brief
        ~Thread(void);

        /// @brief
        ///
        /// @param thread
        /// @return
        Thread&
        operator=(const Thread& thread) = delete;

        /// @brief
        ///
        /// @param thread
        /// @return
        Thread&
        operator=(Thread&& thread) = delete;

        /// @brief
        ///
        /// @return
        bool
        isRunning(void);

        /// @brief
        void
        start(void);

        /// @brief
        void
        join(void);

        /// @brief
        void
        cancel(void);

    protected:
        /// @brief
        std::unique_ptr<IRunnable> m_runnable;

        /// @brief
        std::unique_ptr<sf::Thread> m_thread;

        /// @brief
        bool m_running;

    }; // end of : class Thread

} // end of : namespace cgate
