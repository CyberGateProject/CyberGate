#pragma once

#include "cgate/export.hpp"

namespace cgate
{
    class CGATE_API IRunnable
    {
    protected:
        /// @brief
        IRunnable(void)
        {

        } /* end of : IRunnable(void) */

    public:
        /// @brief
        virtual
        ~IRunnable(void)
        {

        } /* end of : virtual
                      ~IRunnable(void) */

        /// @brief
        ///
        /// @return
        virtual int
        proc(void) = 0;

    }; // end of : class IRunnable

} // end of : namespace cgate
