#pragma once

#include "cgate/export.hpp"
#include "cgate/pattern/imanager.hpp"

namespace cgate
{
    namespace pattern
    {
        /// @brief
        template<typename K, typename T>
        class IFactory
        {
        protected:
            /// @brief
            IFactory(void)
            {

            } // end of : IFactory(void)

        public:
            /// @brief
            ///
            /// @param factory
            IFactory(const IFactory& factory) = delete;

            /// @brief
            ///
            /// @param factory
            IFactory(IFactory&& factory) = delete;

            /// @brief
            virtual
            ~IFactory(void)
            {

            } // end of : ~IFactory(void)

            /// @brief
            ///
            /// @param factory
            /// @return
            IFactory&
            operator =(const IFactory& factory) = delete;

            /// @brief
            ///
            /// @param factory
            /// @return
            IFactory&
            operator =(IFactory&& factory) = delete;

            /// @brief
            ///
            /// @param key
            /// @return
            ///
            /// @throw ex::NotFound
            T&
            operator[] (const K key)
            {
                return *m_manager.get(key);
            } /* end of : T&
                          operator[] (const K key) */

            /// @brief
            ///
            /// @param key
            /// @return
            ///
            /// @throw ex::NotFound
            const T&
            operator[] (const K key) const
            {
                return *m_manager.get(key);
            } /* end of : const T&
                          operator[] (const K key) const */

            /// @brief
            ///
            /// @param key
            /// @return
            bool
            exists(const K key) const
            {
                return m_manager.exists(key);
            } /* end of : bool
                          exists(const K key) const */

            /// @brief
            ///
            /// @param key
            /// @return
            ///
            /// @throw ex::NotFound
            T&
            get(const K key)
            {
                return *m_manager.get(key);
            } /* end of : T&
                          get(const K key) */

            /// @brief
            ///
            /// @param key
            /// @return
            ///
            /// @throw ex::NotFound
            const T&
            get(const K key) const
            {
                return *m_manager.get(key);
            } /* end of : const T&
                          get(const K key) const */

            /// @brief
            ///
            /// @param key
            /// @return
            ///
            /// @throw ex::NotFound
            IFactory&
            remove(const K key)
            {
                m_manager.remove(key);
                return *this;
            } /* end of : IFactory&
                          remove(const K key) */

            /// @brief
            ///
            /// @return
            IFactory&
            clear(void)
            {
                m_manager.clear();
                return *this;
            } /* end of : IFactory&
                          clear(void) */

        protected:
            /// @brief
            IManager<K, T> m_manager;

        }; // end of : template<typename K, typename T> class IFactory

    } // end of : namespace pattern

} // end of : namespace cgate
