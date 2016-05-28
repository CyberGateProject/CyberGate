#pragma once

#include "cgate/export.hpp"
#include "cgate/core/stream/istream.hpp"

namespace cgate
{
    /// @brief
    class CGATE_API MemoryStream : public IStream
    {
    public:
        /// @brief
        ///
        /// @param size
        ///
        /// @throw ex::StreamOpen
        MemoryStream(const size_t size);

        /// @brief
        ///
        /// @param buffer
        /// @param size
        ///
        /// @throw ex::StreamOpen
        MemoryStream(void * buffer,
                     const size_t size);

        /// @brief
        ///
        /// @param stream
        MemoryStream(const MemoryStream & stream) = delete;

        /// @brief
        ///
        /// @param stream
        MemoryStream(MemoryStream && stream) = delete;

        /// @brief
        ~MemoryStream(void);

        /// @brief
        ///
        /// @param stream
        /// @return
        MemoryStream &
        operator =(const MemoryStream & stream) = delete;

        /// @brief
        ///
        /// @param stream
        /// @return
        MemoryStream &
        operator =(MemoryStream && stream) = delete;

        /// @brief
        ///
        /// @return
        void*
        getBuffer(void) const;

        /// @brief
        ///
        /// @return
        size_t
        getSize(void) const;

        /// @brief
        ///
        /// @return
        bool
        isManaged(void) const;

    protected:
        /// @brief
        void * m_buffer;

        /// @brief
        size_t m_size;

        /// @brief
        bool m_is_managed;

    }; // end of : class MemoryStream

} // end of : namespace cgate
