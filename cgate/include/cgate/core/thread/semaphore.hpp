#pragma once

#include "cgate/export.hpp"
#include "SDL2/SDL_thread.h"

namespace cgate
{
    /// @brief
    class CGATE_API Semaphore
    {
    public:
        /// @brief
        ///
        /// @param value
        Semaphore(const Uint32 value);

        /// @brief
        ///
        /// @param semaphore
        Semaphore(const Semaphore & semaphore) = delete;

        /// @brief
        ///
        /// @param semaphore
        Semaphore(Semaphore && semaphore) = delete;

        /// @brief
        ~Semaphore(void);

        /// @brief
        ///
        /// @param semaphore
        /// @return
        Semaphore &
        operator =(const Semaphore & semaphore) = delete;

        /// @brief
        ///
        /// @param semaphore
        /// @return
        Semaphore &
        operator =(Semaphore && semaphore) = delete;

        /// @brief
        ///
        /// @return
        SDL_sem *
        getSDL(void) const;

        /// @brief
        ///
        /// @return
        size_t
        getValue(void) const;

        /// @brief
        ///
        /// @return
        Semaphore &
        wait(void);

        /// @brief
        ///
        /// @return
        bool
        tryWait(void);

        /// @brief
        ///
        /// @param timeout
        /// @return
        bool
        waitTimeout(const Uint32 timeout);

        /// @brief
        ///
        /// @return
        Semaphore &
        post(void);

    private:
        /// @brief
        SDL_sem * m_semaphore;

    }; // end of : class Semaphore

} // end of : namespace cgate
