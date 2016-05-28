#pragma once

#include "cgate/export.hpp"

namespace cgate
{
    namespace pattern
    {
        template<typename K, typename T>
        class IObservable;

        /// @brief
        template<typename K, typename T>
        class IObserver
        {
        protected:
            /// @brief
            IObserver(void)
            {

            } /* end of : IObserver(void) */

        public:
            /// @brief
            ///
            /// @param observable
            /// @return
            virtual const IObserver &
            changed(const IObservable<K, T> * observable) const
            {
                return *this;
            } /* end of : virtual const IObserver &
                          changed(const IObservable<K, T> * observable) const */

        }; // end of : template<typename T> class IObserver

    } // end of : namespace pattern

} // end of : namespace cgate
