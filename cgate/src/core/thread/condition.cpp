#include "cgate/core/strext.hpp"
#include "cgate/core/thread/condition.hpp"
#include "cgate/ex/condition.hpp"

namespace cgate
{
    Condition::Condition(void)
    {
        if ((m_condition = SDL_CreateCond()) == nullptr)
            throw ex::Condition{vstring("Error creating condition : %s", SDL_GetError())};
    } /* end of : Condition::Condition(void) */

    Condition::~Condition(void)
    {
        SDL_DestroyCond(m_condition);
    } /* end of : Condition::~Condition(void) */

    SDL_cond *
    Condition::getSDL(void) const
    {
        return m_condition;
    } /* end of : SDL_cond *
                  Condition::getSDL(void) const */

    Condition &
    Condition::wait(Mutex & mutex)
    {
        if (SDL_CondWait(m_condition, mutex.getSDL()) != 0)
            throw ex::Condition{vstring("Error waiting on the condition : %s", SDL_GetError())};

        return * this;
    } /* end of : Condition &
                  Condition::wait(Mutex & mutex) */

    bool
    Condition::waitTimeout(Mutex & mutex,
                           const size_t timeout)
    {
        switch (SDL_CondWaitTimeout(m_condition, mutex.getSDL(), (Uint32) timeout))
        {
            case -1:
                throw ex::Condition{vstring("Error waiting on the condition : %s", SDL_GetError())};
            case SDL_MUTEX_TIMEDOUT:
                return false;
            default:
                return true;
        }
    } /* end of : bool
                  Condition::waitTimeout(Mutex & mutex,
                                         const size_t timeout) */

    Condition &
    Condition::signal(void)
    {
        if (SDL_CondSignal(m_condition) != 0)
            throw ex::Condition{vstring("Error signaling on the condition : %s", SDL_GetError())};

        return * this;
    } /* end of : Condition &
                  Condition::signal(void) */

    Condition &
    Condition::broadcast(void)
    {
        if (SDL_CondBroadcast(m_condition) != 0)
            throw ex::Condition{vstring("Error broadcasting on the condition : %s", SDL_GetError())};

        return * this;
    } /* end of : Condition &
                  Condition::broadcast(void) */

} // end of : namespace cgate
