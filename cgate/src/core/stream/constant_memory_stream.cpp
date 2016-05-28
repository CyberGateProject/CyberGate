#include "cgate/core/strext.hpp"
#include "cgate/core/stream/constant_memory_stream.hpp"
#include "cgate/ex/stream_open.hpp"

#include <cassert>

namespace cgate
{
    ConstantMemoryStream::ConstantMemoryStream(const size_t size)
        : m_buffer{nullptr}
        , m_size{size}
        , m_is_managed{true}
    {
        m_buffer = new char[size];

        if ((m_stream = SDL_RWFromConstMem(m_buffer, (int) m_size)) == nullptr)
            throw ex::StreamOpen{vstring("Error creating constant memory stream : %s", SDL_GetError()).c_str()};
    } /* end of : ConstantMemoryStream::ConstantMemoryStream(const size_t size) */

    ConstantMemoryStream::ConstantMemoryStream(const void * buffer,
                                               const size_t size)
        : m_buffer{buffer}
        , m_size{size}
        , m_is_managed{false}
    {
        assert(buffer != nullptr);

        if ((m_stream = SDL_RWFromConstMem(m_buffer, (int) m_size)) == nullptr)
            throw ex::StreamOpen{vstring("Error creating constant memory stream : %s", SDL_GetError()).c_str()};
    } /* end of : ConstantMemoryStream::ConstantMemoryStream(const void * buffer,
                                                             const size_t size) */

    ConstantMemoryStream::~ConstantMemoryStream(void)
    {
        if (m_is_managed)
            delete [] m_buffer;

        SDL_RWclose(m_stream);
    } /* end of : ConstantMemoryStream::~ConstantMemoryStream(void) */

    const void*
    ConstantMemoryStream::getBuffer(void) const
    {
        return m_buffer;
    } /* end of : const void*
                  ConstantMemoryStream::getBuffer(void) const */

    size_t
    ConstantMemoryStream::getSize(void) const
    {
        return m_size;
    } /* end of : size_t
                  ConstantMemoryStream::getSize(void) const */

    bool
    ConstantMemoryStream::isManaged(void) const
    {
        return m_is_managed;
    } /* end of : bool
                  ConstantMemoryStream::isManaged(void) const */

} // end of : namespace cgate
