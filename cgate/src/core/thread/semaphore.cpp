#include "cgate/core/strext.hpp"
#include "cgate/core/thread/semaphore.hpp"
#include "cgate/ex/semaphore.hpp"

namespace cgate
{
    Semaphore::Semaphore(const Uint32 value)
    {
        if ((m_semaphore = SDL_CreateSemaphore(value)) == nullptr)
            throw ex::Semaphore{vstring("Error creating semaphore : %s", SDL_GetError())};
    } /* end of : Semaphore::Semaphore(const Uint32 value) */

    Semaphore::~Semaphore(void)
    {
        SDL_DestroySemaphore(m_semaphore);
    } /* end of : Semaphore::~Semaphore(void) */

    SDL_sem *
    Semaphore::getSDL(void) const
    {
        return m_semaphore;
    } /* end of : SDL_sem *
                  Semaphore::getSDL(void) const */

    size_t
    Semaphore::getValue(void) const
    {
        return SDL_SemValue(m_semaphore);
    } /* end of : size_t
                  Semaphore::getValue(void) const */

    Semaphore &
    Semaphore::wait(void)
    {
        if (SDL_SemWait(m_semaphore) != 0)
            throw ex::Semaphore{vstring("Error waiting on the semaphore : %s", SDL_GetError())};

        return * this;
    } /* end of : Semaphore &
                  Semaphore::wait(void) */

    bool
    Semaphore::tryWait(void)
    {
        switch (SDL_SemTryWait(m_semaphore))
        {
            case -1:
                throw ex::Semaphore{vstring("Error waiting on the semaphore : %s", SDL_GetError())};
            case SDL_MUTEX_TIMEDOUT:
                return false;
            default:
                return true;
        }
    } /* end of : bool
                  Semaphore::tryWait(void) */

    bool
    Semaphore::waitTimeout(const Uint32 timeout)
    {
        switch (SDL_SemWaitTimeout(m_semaphore, timeout))
        {
            case -1:
                throw ex::Semaphore{vstring("Error waiting on the semaphore : %s", SDL_GetError())};
            case SDL_MUTEX_TIMEDOUT:
                return false;
            default:
                return true;
        }
    } /* end of : bool
                  Semaphore::waitTimeout(const Uint32 timeout) */

    Semaphore &
    Semaphore::post(void)
    {
        if (SDL_SemPost(m_semaphore) != 0)
            throw ex::Semaphore{vstring("Error posting on the semaphore : %s", SDL_GetError())};

        return * this;
    } /* end of : Semaphore &
                  Semaphore::post(void) */

} // end of : namespace cgate
