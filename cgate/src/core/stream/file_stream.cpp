#include "cgate/core/strext.hpp"
#include "cgate/core/stream/file_stream.hpp"
#include "cgate/ex/stream_open.hpp"

#include <cassert>

namespace cgate
{
    FileStream::FileStream(const std::string path,
                           const std::string mode)
        : m_path{path}
    {
        assert(path != "");
        assert(mode != "");

        if ((m_stream = SDL_RWFromFile(path.c_str(), mode.c_str())) == nullptr)
            throw ex::StreamOpen{vstring("Error creating file stream : %s", SDL_GetError()).c_str()};
    } /* end of : FileStream::FileStream(const std::string path,
                                         const std::string mode) */

    FileStream::~FileStream(void)
    {
        SDL_RWclose(m_stream);
    } /* end of : FileStream::~FileStream(void) */

    std::string
    FileStream::getPath(void) const
    {
        return m_path;
    } /* end of : std::string
                  FileStream::getPath(void) const */

} // end of : namespace cgate
