#include "cgate/core/strext.hpp"
#include "cgate/core/thread/mutex.hpp"
#include "cgate/ex/mutex.hpp"

namespace cgate
{
    Mutex::Mutex(void)
    {
        if ((m_mutex = SDL_CreateMutex()) == nullptr)
            throw ex::Mutex{vstring("Error creating mutex : %s", SDL_GetError())};
    } /* end of : Mutex::Mutex(void) */

    Mutex::~Mutex(void)
    {
        SDL_DestroyMutex(m_mutex);
    } /* end of : Mutex::~Mutex(void) */

    SDL_mutex *
    Mutex::getSDL(void) const
    {
        return m_mutex;
    } /* end of : SDL_mutex *
                  Mutex::getSDL(void) const */

    Mutex &
    Mutex::lock(void)
    {
        if (SDL_LockMutex(m_mutex) != 0)
            throw ex::Mutex{vstring("Error locking mutex : %s", SDL_GetError())};

        return * this;
    } /* end of : Mutex &
                  Mutex::lock(void) */

    bool
    Mutex::tryLock(void)
    {
        switch (SDL_TryLockMutex(m_mutex))
        {
            case -1:
                throw ex::Mutex{vstring("Error locking mutex : %s", SDL_GetError())};
            case SDL_MUTEX_TIMEDOUT:
                return false;
            default:
                return true;
        }
    } /* end of : bool
                  Mutex::tryLock(void) */

    Mutex &
    Mutex::unlock(void)
    {
        if (SDL_UnlockMutex(m_mutex) != 0)
            throw ex::Mutex{vstring("Error locking mutex : %s", SDL_GetError())};

        return * this;
    } /* end of : Mutex &
                  Mutex::unlock(void) */

} // end of : namespace cgate
