#include "cgate/core/strext.hpp"
#include "cgate/core/stream/memory_stream.hpp"
#include "cgate/ex/stream_open.hpp"

#include <cassert>

namespace cgate
{
    MemoryStream::MemoryStream(const size_t size)
        : m_buffer{nullptr}
        , m_size{size}
        , m_is_managed{true}
    {
        m_buffer = new char[size];

        if ((m_stream = SDL_RWFromMem(m_buffer, (int) m_size)) == nullptr)
            throw ex::StreamOpen{vstring("Error creating memory stream : %s", SDL_GetError()).c_str()};
    } /* end of : MemoryStream::MemoryStream(const size_t size) */

    MemoryStream::MemoryStream(void * buffer,
                               const size_t size)
        : m_buffer{buffer}
        , m_size{size}
        , m_is_managed{false}
    {
        assert(buffer != nullptr);

        if ((m_stream = SDL_RWFromMem(m_buffer, (int) m_size)) == nullptr)
            throw ex::StreamOpen{vstring("Error creating memory stream : %s", SDL_GetError()).c_str()};
    } /* end of : MemoryStream::MemoryStream(void * buffer,
                                             const size_t size) */

    MemoryStream::~MemoryStream(void)
    {
        if (m_is_managed)
            delete [] m_buffer;

        SDL_RWclose(m_stream);
    } /* end of : MemoryStream::~MemoryStream(void) */

    void*
    MemoryStream::getBuffer(void) const
    {
        return m_buffer;
    } /* end of : void*
                  MemoryStream::getBuffer(void) const */

    size_t
    MemoryStream::getSize(void) const
    {
        return m_size;
    } /* end of : size_t
                  MemoryStream::getSize(void) const */

    bool
    MemoryStream::isManaged(void) const
    {
        return m_is_managed;
    } /* end of : bool
                  MemoryStream::isManaged(void) const */

} // end of : namespace cgate
