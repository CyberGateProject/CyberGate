#pragma once

#include "cgate/export.hpp"
#include "cgate/core/thread/irunnable.hpp"
#include "SDL2/SDL_thread.h"

#include <memory>

namespace cgate
{
    class ThreadFactory;

    /// @brief
    class CGATE_API Thread
    {
        friend class ThreadFactory;

    protected:
        /// @brief
        ///
        /// @param name
        /// @param runnable
        Thread(const std::string name,
               IRunnable * runnable);

    public:
        /// @brief
        ///
        /// @param thread
        Thread(const Thread & thread) = delete;

        /// @brief
        ///
        /// @param thread
        Thread(Thread && thread) = delete;

        /// @brief
        ~Thread(void);

        /// @brief
        ///
        /// @param thread
        /// @return
        Thread &
        operator=(const Thread & thread) = delete;

        /// @brief
        ///
        /// @param thread
        /// @return
        Thread &
        operator=(Thread && thread) = delete;

        /// @brief
        ///
        /// @return
        IRunnable *
        getRunnable(void) const;

        /// @brief
        ///
        /// @return
        SDL_Thread *
        getSDL(void) const;

        /// @brief
        ///
        /// @return
        bool
        isRunning(void);

        /// @brief
        ///
        /// @return
        ///
        /// @throw ex::Thread
        Thread &
        start(void);

        /// @brief
        ///
        /// @return
        ///
        /// @throw ex::Thread
        int
        join(void);

    protected:
        /// @brief
        ///
        /// @param runnable
        /// @return
        static int
        run(void * runnable);

    protected:
        /// @brief
        std::string m_name;

        /// @brief
        std::unique_ptr<IRunnable> m_runnable;

        /// @brief
        SDL_Thread * m_thread;

    }; // end of : class Thread

} // end of : namespace cgate
