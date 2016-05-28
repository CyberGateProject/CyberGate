#pragma once

#include "cgate/export.hpp"
#include "cgate/core/stream/stream_seek_type.hpp"
#include "SDL2/SDL_rwops.h"

#include <string>

namespace cgate
{
    /// @brief
    class CGATE_API IStream
    {
    public:
        /// @brief
        ///
        /// @param stream
        IStream(const IStream & stream) = delete;

        /// @brief
        ///
        /// @param stream
        IStream(IStream && stream) = delete;

        /// @brief
        virtual
        ~IStream(void);

        /// @brief
        ///
        /// @param stream
        /// @return
        IStream &
        operator =(const IStream & stream) = delete;

        /// @brief
        ///
        /// @param stream
        /// @return
        IStream &
        operator =(IStream && stream) = delete;

        /// @brief
        ///
        /// @return
        SDL_RWops *
        getSDL(void) const;

        /// @brief
        ///
        /// @return
        ///
        /// @throw ex::StreamOpen
        size_t
        getSize(void);

        /// @brief
        ///
        /// @return
        ///
        /// @throw ex::StreamOpen
        size_t
        getPosition(void);

        /// @brief
        ///
        /// @param type
        /// @param offset
        /// @return
        ///
        /// @throw ex::StreamOpen
        IStream &
        setPosition(const StreamSeekType type,
                    const int offset);

        /// @brief
        ///
        /// @param buffer
        /// @param size
        /// @param number
        /// @return
        ///
        /// @throw ex::StreamRead
        size_t
        read(void * buffer,
                const size_t size,
                const size_t number);

        /// @brief
        ///
        /// @return
        ///
        /// @throw ex::StreamRead
        Uint8
        read8(void);

        /// @brief
        ///
        /// @param big_endian
        /// @return
        ///
        /// @throw ex::StreamRead
        Uint16
        read16(const bool big_endian = true);

        /// @brief
        ///
        /// @param big_endian
        /// @return
        ///
        /// @throw ex::StreamRead
        Uint32
        read32(const bool big_endian = true);

        /// @brief
        ///
        /// @param big_endian
        /// @return
        ///
        /// @throw ex::StreamRead
        Uint64
        read64(const bool big_endian = true);

        /// @brief
        ///
        /// @param buffer
        /// @param size
        /// @param number
        /// @return
        ///
        /// @throw ex::StreamWrite
        size_t
        write(const void * buffer,
                const size_t size,
                const size_t number);

        /// @brief
        ///
        /// @param value
        /// @return
        ///
        /// @throw ex::StreamWrite
        IStream &
        write8(const Uint8 value);

        /// @brief
        ///
        /// @param value
        /// @param big_endian
        /// @return
        ///
        /// @throw ex::StreamWrite
        IStream &
        write16(const Uint16 value,
                const bool big_endian = true);

        /// @brief
        ///
        /// @param value
        /// @param big_endian
        /// @return
        ///
        /// @throw ex::StreamWrite
        IStream &
        write32(const Uint32 value,
                const bool big_endian = true);

        /// @brief
        ///
        /// @param value
        /// @param big_endian
        /// @return
        ///
        /// @throw ex::StreamWrite
        IStream &
        write64(const Uint64 value,
                const bool big_endian = true);

    protected:
        /// @brief
        IStream(void);

    protected:
        /// @brief
        SDL_RWops * m_stream;

    }; // end of : class Stream

} // end of : namespace cgate
