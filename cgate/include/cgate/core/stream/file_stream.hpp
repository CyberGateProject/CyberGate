#pragma once

#include "cgate/export.hpp"
#include "cgate/core/stream/istream.hpp"

namespace cgate
{
    /// @brief
    class CGATE_API FileStream : public IStream
    {
    public:
        /// @brief
        ///
        /// @param path
        /// @param mode
        ///
        /// @throw ex::StreamOpen
        FileStream(const std::string path,
                   const std::string mode);

        /// @brief
        ///
        /// @param stream
        FileStream(const FileStream & stream) = delete;

        /// @brief
        ///
        /// @param stream
        FileStream(FileStream && stream) = delete;

        /// @brief
        ~FileStream(void);

        /// @brief
        ///
        /// @param stream
        /// @return
        FileStream &
        operator =(const FileStream & stream) = delete;

        /// @brief
        ///
        /// @param stream
        /// @return
        FileStream &
        operator =(FileStream && stream) = delete;

        /// @brief
        ///
        /// @return
        std::string
        getPath(void) const;

    protected:
        /// @brief
        std::string m_path;

    }; // end of : class FileStream

} // end of : namespace cgate
