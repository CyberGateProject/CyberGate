#pragma once

#include "cgate/export.hpp"
#include "cgate/core/thread/mutex.hpp"

namespace cgate
{
    /// @brief
    class CGATE_API Condition
    {
    public:
        /// @brief
        Condition(void);

        /// @brief
        ///
        /// @param condition
        Condition(const Condition & condition) = delete;

        /// @brief
        ///
        /// @param condition
        Condition(Condition && condition) = delete;

        /// @brief
        ~Condition(void);

        /// @brief
        ///
        /// @param condition
        /// @return
        Condition &
        operator =(const Condition & condition) = delete;

        /// @brief
        ///
        /// @param condition
        /// @return
        Condition &
        operator =(Condition && condition) = delete;

        /// @brief
        ///
        /// @return
        SDL_cond *
        getSDL(void) const;

        /// @brief
        ///
        /// @param mutex
        /// @return
        Condition &
        wait(Mutex & mutex);

        /// @brief
        ///
        /// @param mutex
        /// @param timeout
        /// @return
        bool
        waitTimeout(Mutex & mutex,
                    const size_t timeout);

        /// @brief
        ///
        /// @return
        Condition &
        signal(void);

        /// @brief
        ///
        /// @return
        Condition &
        broadcast(void);

    private:
        /// @brief
        SDL_cond * m_condition;

    }; // end of : class Condition

} // end of : namespace cgate
