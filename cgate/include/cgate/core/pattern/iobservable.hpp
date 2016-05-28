#pragma once

#include "cgate/export.hpp"
#include "cgate/core/pattern/imanager.hpp"
#include "cgate/core/pattern/iobserver.hpp"

namespace cgate
{
    namespace pattern
    {
        /// @brief
        template<typename K, typename T>
        class IObservable
        {
        protected:
            /// @brief
            IObservable(void)
            {

            } /* end of : IObservable(void) */

        public:
            /// @brief
            ///
            /// @param key
            /// @return
            bool
            existsObserver(const K key) const
            {
                return m_observers.exists(key);
            } /* end of : bool
                          existsObserver(const K key) const */

            /// @brief
            ///
            /// @param key
            /// @return
            ///
            /// @throw ex::NotFound
            IObserver<K, T> *
            getObserver(const K key)
            {
                return m_observers.get(key);
            } /* end of : IObserver<K, T> *
                          getObserver(const K key) */

            /// @brief
            ///
            /// @param key
            /// @return
            ///
            /// @throw ex::NotFound
            const IObserver<K, T> *
            getObserver(const K key) const
            {
                return m_observers.get(key);
            } /* end of : const IObserver<K, T> *
                          getObserver(const K key) const */

            /// @brief
            ///
            /// @param key
            /// @param observer
            /// @return
            ///
            /// @throw ex::Duplicate
            IObservable &
            addObserver(const K key,
                        IObserver<K, T> * observer)
            {
                m_observers.add(key, observer);
                return * this;
            } /* end of : IObservable &
                          addObserver(const K key,
                                      IObserver<K, T> * observer) */

            /// @brief
            ///
            /// @param key
            /// @return
            ///
            /// @throw ex::NotFound
            IObservable &
            removeObserver(const K key)
            {
                m_observers.remove(key);
                return *this;
            } /* end of : IObservable &
                          removeObserver(const K key) */

            /// @brief
            ///
            /// @return
            IObservable &
            clearObservers(void)
            {
                m_observers.clear();
                return *this;
            } /* end of : IObservable &
                          clearObservers(void) */

            virtual const IObservable &
            changed(void) const
            {
                for (auto it = m_observers.begin(),
                          end = m_observers.end();
                     it != end;
                     ++it)
                    it->second->changed(this);

                return * this;
            } /* end of : virtual const IObservable &
                          changed(void) const */

        protected:
            /// @brief
            IManager<K, IObserver<K, T>> m_observers;

        }; // end of : template<typename K, typename T> class IObservable

    } // end of : namespace pattern

} // end of : namespace cgate
