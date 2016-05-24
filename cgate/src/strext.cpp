#include "cgate/strext.hpp"

#include <algorithm>
#include <functional>
#include <cassert>
#include <cstdarg>
#include <cstring>
#include <locale>

#ifndef vasprintf
#define pt_vasprintf
#include <climits>

/// @brief
///
/// @param strp
/// @param format
/// @param vargs
/// @return
int vasprintf(char** strp,
              const char* format,
              va_list vargs)
{
    assert(strp != nullptr);
    assert(strcmp(format, "") != 0);

    int result = -1, size = vsnprintf(0, 0, format, vargs);

    if ((size >= 0) && (size < INT_MAX))
    {
        *strp = (char *) malloc(size + 1); //+1 for null
        if (*strp)
        {
            result = vsnprintf(*strp, size + 1, format, vargs);  //+1 for null
            if ((result < 0) || (result > size))
            {
                free(*strp);
                *strp = 0;
                result = -1;
            }
        }
    }
    else
    {
        *strp = 0;
    }

    return result;
} /* end of : int vasprintf(char** strp,
                            const char* format,
                            va_list vargs) */
#endif

namespace cgate
{
    std::string
    rtrim(std::string str)
    {
        str.erase(std::find_if(str.rbegin(),
                               str.rend(),
                               std::not1(std::ptr_fun<int, int>(isspace))).base(),
                  str.end());
        return str;
    } /* end of : std::string
                  rtrim(std::string str) */

    std::string
    ltrim(std::string str)
    {
        str.erase(str.begin(),
                  std::find_if(str.begin(),
                               str.end(),
                               std::not1(std::ptr_fun<int, int>(isspace))));
        return str;
    } /* end of : std::string
                  ltrim(std::string str) */

    std::string
    trim(const std::string str)
    {
        return ltrim(rtrim(str));
    } /* end of : std::string
                  trim(const std::string str) */

    std::string
    vstring(const std::string format,
            ...)
    {
        assert(format != "");

        char *buffer;

        va_list vargs;
        va_start(vargs, format);
        vasprintf(&buffer, format.c_str(), vargs);
        va_end(vargs);

        std::string result{buffer};
        free(buffer);

        return result;
    } /* end of : std::string
                  vstring(const std::string format,
                          ...) */

} // end of : namespace cgate