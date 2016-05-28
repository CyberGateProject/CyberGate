#pragma once

#include "cgate/export.hpp"
#include "cgate/core/stream/istream.hpp"

namespace cgate
{
    /// @brief
    class CGATE_API ConsoleStream : public IStream
    {
    public:
        /// @brief
        ///
        /// @throw ex::StreamOpen
        ConsoleStream(void);

        /// @brief
        ///
        /// @param stream
        ConsoleStream(const ConsoleStream & stream) = delete;

        /// @brief
        ///
        /// @param stream
        ConsoleStream(ConsoleStream && stream) = delete;

        /// @brief
        ~ConsoleStream(void);

        /// @brief
        ///
        /// @param stream
        /// @return
        ConsoleStream &
        operator =(const ConsoleStream & stream) = delete;

        /// @brief
        ///
        /// @param stream
        /// @return
        ConsoleStream &
        operator =(ConsoleStream && stream) = delete;

    private:
        /// @brief
        ///
        /// @param rw
        /// @return
        static Sint64
        rwSize(SDL_RWops * rw);

        /// @brief
        ///
        /// @param rw
        /// @param offset
        /// @param whence
        /// @return
        static Sint64
        rwSeek(SDL_RWops * rw,
               Sint64 offset,
               int whence);

        /// @brief
        ///
        /// @param rw
        /// @param buffer
        /// @param size
        /// @param number
        /// @return
        static size_t
        rwRead(SDL_RWops * rw,
               void * buffer,
               size_t size,
               size_t number);

        /// @brief
        ///
        /// @param rw
        /// @param buffer
        /// @param size
        /// @param number
        /// @return
        static size_t
        rwWrite(SDL_RWops * rw,
                const void * buffer,
                size_t size,
                size_t number);

        /// @brief
        ///
        /// @param rw
        /// @return
        static int
        rwClose(SDL_RWops * rw);

    }; // end of : class ConsoleStream

} // end of : namespace cgate
