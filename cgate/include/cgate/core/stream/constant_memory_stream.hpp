#pragma once

#include "cgate/export.hpp"
#include "cgate/core/stream/istream.hpp"

namespace cgate
{
    /// @brief
    class CGATE_API ConstantMemoryStream : public IStream
    {
    public:
        /// @brief
        ///
        /// @param size
        ///
        /// @throw ex::StreamOpen
        ConstantMemoryStream(const size_t size);

        /// @brief
        ///
        /// @param buffer
        /// @param size
        ///
        /// @throw ex::StreamOpen
        ConstantMemoryStream(const void * buffer,
                             const size_t size);

        /// @brief
        ///
        /// @param stream
        ConstantMemoryStream(const ConstantMemoryStream & stream) = delete;

        /// @brief
        ///
        /// @param stream
        ConstantMemoryStream(ConstantMemoryStream && stream) = delete;

        /// @brief
        ~ConstantMemoryStream(void);

        /// @brief
        ///
        /// @param stream
        /// @return
        ConstantMemoryStream &
        operator =(const ConstantMemoryStream & stream) = delete;

        /// @brief
        ///
        /// @param stream
        /// @return
        ConstantMemoryStream &
        operator =(ConstantMemoryStream && stream) = delete;

        /// @brief
        ///
        /// @return
        const void*
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
        const void * m_buffer;

        /// @brief
        size_t m_size;

        /// @brief
        bool m_is_managed;

    }; // end of : class ConstantMemoryStream

} // end of : namespace cgate
