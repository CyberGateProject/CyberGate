#include "cgate/core/strext.hpp"
#include "cgate/core/stream/istream.hpp"
#include "cgate/ex/stream_open.hpp"
#include "cgate/ex/stream_read.hpp"
#include "cgate/ex/stream_write.hpp"

#include <cassert>

namespace cgate
{
    IStream::IStream(void)
    {

    } /* end of : IStream::IStream(void) */

    IStream::~IStream(void)
    {

    } /* end of : IStream::~IStream(void) */

    SDL_RWops *
    IStream::getSDL(void) const
    {
        return m_stream;
    } /* end of : SDL_RWops *
                    IStream::getSDL(void) const */

    size_t
    IStream::getSize(void)
    {
        auto result = SDL_RWsize(m_stream);
        if (result == -1)
            throw ex::StreamOpen{"Unable to determine the stream size"};
        if (result < -1)
            throw ex::StreamOpen{vstring("Error while determine the stream size : %s", SDL_GetError()).c_str()};

        return (size_t) result;
    } /* end of : size_t
                    IStream::getSize(void) */

    size_t
    IStream::getPosition(void)
    {
        auto result = SDL_RWtell(m_stream);
        if (result == -1)
            throw ex::StreamOpen{"Unable to determine the stream internal pointer position"};

        return (size_t) result;
    } /* end of : size_t
                    IStream::getPosition(void) */

    IStream &
    IStream::setPosition(const StreamSeekType type,
                         const int offset)
    {
        auto result = SDL_RWseek(m_stream, offset, static_cast<int>(type));
        if (result == -1)
            throw ex::StreamOpen{"Unable to move the stream internal pointer position"};

        return * this;
    } /* end of : IStream &
                    IStream::setPosition(const StreamSeekType type,
                                         const int offset) */

    size_t
    IStream::read(void * buffer,
                    const size_t size,
                    const size_t number)
    {
        assert(buffer != nullptr);

        SDL_ClearError();
        auto result = SDL_RWread(m_stream, buffer, size, number);
        if (std::string{SDL_GetError()} != "")
            throw ex::StreamRead{"Error reading the buffer from the stream"};

        return result;
    } /* end of : size_t
                    IStream::read(void * buffer,
                                const size_t size,
                                const size_t number) */

    Uint8
    IStream::read8(void)
    {
        SDL_ClearError();
        auto result = SDL_ReadU8(m_stream);
        if (std::string{SDL_GetError()} != "")
            throw ex::StreamRead{"Error reading the byte from the stream"};

        return result;
    } /* end of : Uint8
                    IStream::read8(void) */

    Uint16
    IStream::read16(const bool big_endian)
    {
        SDL_ClearError();
        Uint16 (*func)(SDL_RWops*) = (big_endian ? SDL_ReadBE16 : SDL_ReadLE16);
        auto result = func(m_stream);
        if (std::string{SDL_GetError()} != "")
            throw ex::StreamRead{"Error reading the short from the stream"};

        return result;
    } /* end of : Uint16
                    IStream::read16(const bool big_endian) */

    Uint32
    IStream::read32(const bool big_endian)
    {
        SDL_ClearError();
        Uint32 (*func)(SDL_RWops*) = (big_endian ? SDL_ReadBE32 : SDL_ReadLE32);
        auto result = func(m_stream);
        if (std::string{SDL_GetError()} != "")
            throw ex::StreamRead{"Error reading the int from the stream"};

        return result;
    } /* end of : Uint32
                    IStream::read32(const bool big_endian) */

    Uint64
    IStream::read64(const bool big_endian)
    {
        SDL_ClearError();
        Uint64 (*func)(SDL_RWops*) = (big_endian ? SDL_ReadBE64 : SDL_ReadLE64);
        auto result = func(m_stream);
        if (std::string{SDL_GetError()} != "")
            throw ex::StreamRead{"Error reading the long int from the stream"};

        return result;
    } /* end of : Uint64
                    IStream::read64(const bool big_endian) */

    size_t
    IStream::write(const void * buffer,
                    const size_t size,
                    const size_t number)
    {
        assert(buffer != nullptr);

        auto result = SDL_RWwrite(m_stream, buffer, size, number);
        if (result < number)
            throw ex::StreamWrite{"Error writing the buffer into the stream"};

        return result;
    } /* end of : size_t
                    IStream::write(const void * buffer,
                                    const size_t size,
                                    const size_t number) */

    IStream &
    IStream::write8(const Uint8 value)
    {
        if (SDL_WriteU8(m_stream, value) == 0)
            throw ex::StreamWrite{vstring("Error writing the value %u into the stream", value).c_str()};
        return * this;
    } /* end of : IStream &
                    IStream::write8(const Uint8 value) */

    IStream &
    IStream::write16(const Uint16 value,
                        const bool big_endian)
    {
        size_t (*func)(SDL_RWops*, Uint16) = (big_endian ? SDL_WriteBE16 : SDL_WriteLE16);
        if (func(m_stream, value) == 0)
            throw ex::StreamWrite{vstring("Error writing the value %u into the stream", value).c_str()};

        return * this;
    } /* end of : IStream &
                    IStream::write16(const Uint16 value,
                                    const bool big_endian) */

    IStream &
    IStream::write32(const Uint32 value,
                        const bool big_endian)
    {
        size_t (*func)(SDL_RWops*, Uint32) = (big_endian ? SDL_WriteBE32 : SDL_WriteLE32);
        if (func(m_stream, value) == 0)
            throw ex::StreamWrite{vstring("Error writing the value %u into the stream", value).c_str()};

        return * this;
    } /* end of : IStream &
                    IStream::write32(const Uint32 value,
                                    const bool big_endian) */

    IStream &
    IStream::write64(const Uint64 value,
                        const bool big_endian)
    {
        size_t (*func)(SDL_RWops*, Uint64) = (big_endian ? SDL_WriteBE64 : SDL_WriteLE64);
        if (func(m_stream, value) == 0)
            throw ex::StreamWrite{vstring("Error writing the value %lu into the stream", value).c_str()};

        return * this;
    } /* end of : IStream &
                    IStream::write64(const Uint64 value,
                                    const bool big_endian) */

} // end of : namespace cgate
