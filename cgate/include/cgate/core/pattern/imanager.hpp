#pragma once

#include "cgate/export.hpp"
#include "cgate/ex/duplicate.hpp"
#include "cgate/ex/not_found.hpp"

#include <map>
#include <memory>

namespace cgate
{
    namespace pattern
    {
        /// @brief
        template<typename K, typename T>
        class IManager
        {
        public:
            /// @brief
            ///
            /// @param key
            /// @return
            T *
            operator[] (const K key)
            {
                return get(key);
            } /* end of : T *
                          operator[] (const K key) */

            /// @brief
            ///
            /// @param key
            /// @return
            const T *
            operator[] (const K key) const
            {
                return get(key);
            } /* end of : const T *
                          operator[] (const K key) const */

            /// @brief
            ///
            /// @param key
            /// @return
            bool
            exists(const K key) const
            {
                return m_entries.find(key) != m_entries.end();
            } /* end of : bool
                          exists(const K key) const */

            /// @brief
            ///
            /// @param key
            /// @return
            ///
            /// @throw ex::NotFound
            T *
            get(const K key)
            {
                auto it = m_entries.find(key);
                if (it == m_entries.end())
                    throw ex::NotFound{};
                return it->second.get();
            } /* end of : T *
                          get(const K key) */

            /// @brief
            ///
            /// @param key
            /// @return
            ///
            /// @throw ex::NotFound
            const T *
            get(const K key) const
            {
                auto it = m_entries.find(key);
                if (it == m_entries.end())
                    throw ex::NotFound{};
                return it->second.get();
            } /* end of : const T *
                          get(const K key) const */

            /// @brief
            ///
            /// @return
            typename std::map<K, std::unique_ptr<T>>::iterator
            begin(void)
            {
                return m_entries.begin();
            } /* end of : typename std::map<K, std::unique_ptr<T>>::iterator
                          begin(void) */

            /// @brief
            ///
            /// @return
            typename std::map<K, std::unique_ptr<T>>::const_iterator
            begin(void) const
            {
                return m_entries.begin();
            } /* end of : typename std::map<K, std::unique_ptr<T>>::const_iterator
                          begin(void) const */

            /// @brief
            ///
            /// @return
            typename std::map<K, std::unique_ptr<T>>::iterator
            end(void)
            {
                return m_entries.end();
            } /* end of : typename std::map<K, std::unique_ptr<T>>::iterator
                          end(void) */

            /// @brief
            ///
            /// @return
            typename std::map<K, std::unique_ptr<T>>::const_iterator
            end(void) const
            {
                return m_entries.end();
            } /* end of : typename std::map<K, std::unique_ptr<T>>::const_iterator
                          end(void) const */

            /// @brief
            ///
            /// @param key
            /// @param object
            /// @return
            ///
            /// @throw ex::Duplicate
            T *
            add(const K key,
                T * object)
            {
                auto it = m_entries.find(key);
                if (it != m_entries.end())
                    throw ex::Duplicate{};
                m_entries.insert(std::pair<K, std::unique_ptr<T>>{key, std::unique_ptr<T>{object}});
                return object;
            } /* end of : T *
                          add(const K key,
                              T * object) */

            /// @brief
            ///
            /// @param key
            /// @return
            ///
            /// @throw ex::NotFound
            IManager &
            remove(const K key)
            {
                auto it = m_entries.find(key);
                if (it == m_entries.end())
                    throw ex::NotFound{};
                m_entries.erase(it);
                return *this;
            } /* end of : IManager &
                          remove(const K key) */

            /// @brief
            ///
            /// @return
            IManager &
            clear(void)
            {
                m_entries.clear();
                return *this;
            } /* end of : IManager &
                          clear(void) */

        protected:
            /// @brief
            std::map<K, std::unique_ptr<T>> m_entries;

        }; // end of : template<typename K, typename T> class IManager

    } // end of : namespace pattern

} // end of : namespace cgate
