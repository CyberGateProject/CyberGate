#pragma once

#include "cgate/export.hpp"
#include "SDL2/SDL_mutex.h"

namespace cgate
{
    /// @brief
    class CGATE_API Mutex
    {
    public:
        /// @brief
        Mutex(void);

        /// @brief
        ///
        /// @param mutex
        Mutex(const Mutex & mutex) = delete;

        /// @brief
        ///
        /// @param mutex
        Mutex(Mutex && mutex) = delete;

        /// @brief
        ~Mutex(void);

        /// @brief
        ///
        /// @param mutex
        /// @return
        Mutex &
        operator =(const Mutex & mutex) = delete;

        /// @brief
        ///
        /// @param mutex
        /// @return
        Mutex &
        operator =(Mutex && mutex) = delete;

        /// @brief
        ///
        /// @return
        SDL_mutex *
        getSDL(void) const;

        /// @brief
        ///
        /// @return
        Mutex &
        lock(void);

        /// @brief
        ///
        /// @return
        bool
        tryLock(void);

        /// @brief
        ///
        /// @return
        Mutex &
        unlock(void);

    private:
        /// @brief
        SDL_mutex * m_mutex;

    }; // end of : class Mutex

} // end of : namespace cgate
