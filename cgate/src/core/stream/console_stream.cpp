#include "cgate/core/strext.hpp"
#include "cgate/core/stream/console_stream.hpp"
#include "cgate/ex/stream_open.hpp"

#include <cassert>

namespace cgate
{
    ConsoleStream::ConsoleStream(void)
    {
        if ((m_stream = SDL_AllocRW()) == nullptr)
            throw ex::StreamOpen{vstring("Error creating console stream : %s", SDL_GetError()).c_str()};

        m_stream->size  = ConsoleStream::rwSize;
        m_stream->seek  = ConsoleStream::rwSeek;
        m_stream->read  = ConsoleStream::rwRead;
        m_stream->write = ConsoleStream::rwWrite;
        m_stream->close = ConsoleStream::rwClose;
    } /* end of : ConsoleStream::ConsoleStream(void) */

    ConsoleStream::~ConsoleStream(void)
    {
        SDL_RWclose(m_stream);
    } /* end of : ConsoleStream::~ConsoleStream(void) */

    Sint64
    ConsoleStream::rwSize(SDL_RWops * rw)
    {
        assert(rw != nullptr);

        return -1;
    } /* end of : Sint64
                  ConsoleStream::rwSize(SDL_RWops * rw) */

    Sint64
    ConsoleStream::rwSeek(SDL_RWops * rw,
                          Sint64 offset,
                          int whence)
    {
        assert(rw != nullptr);

        return -1;
    } /* end of : Sint64
                  ConsoleStream::rwSeek(SDL_RWops * rw,
                                        Sint64 offset,
                                        int whence) */

    size_t
    ConsoleStream::rwRead(SDL_RWops * rw,
                          void * buffer,
                          size_t size,
                          size_t number)
    {
        assert(rw != nullptr);

        return fread(buffer, size, number, stdin);
    } /* end of : size_t
                  ConsoleStream::rwRead(SDL_RWops * rw,
                                        void * buffer,
                                        size_t size,
                                        size_t number) */

    size_t
    ConsoleStream::rwWrite(SDL_RWops * rw,
                           const void * buffer,
                           size_t size,
                           size_t number)
    {
        assert(rw != nullptr);

        return fwrite(buffer, size, number, stdout);
    } /* end of : size_t
                  ConsoleStream::rwWrite(SDL_RWops * rw,
                                         const void * buffer,
                                         size_t size,
                                         size_t number) */

    int
    ConsoleStream::rwClose(SDL_RWops * rw)
    {
        assert(rw != nullptr);

        return 0;
    } /* end of : int
                  ConsoleStream::rwClose(SDL_RWops * rw) */

} // end of : namespace cgate
