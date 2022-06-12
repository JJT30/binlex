#ifndef RAW_H
#define RAW_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#ifndef _WIN32
#include <unistd.h>
#endif // _WIN32
#include <stdexcept>
#include "file.h"

#ifdef _WIN32
#define BINLEX_EXPORT __declspec(dllexport)
#else
#define BINLEX_EXPORT
#endif

#ifdef _WIN32
typedef unsigned int uint;
#endif

#ifdef _WIN32
typedef unsigned int uint;
#endif

namespace binlex{
    class Raw : public File{
        /**
         * This class is used to read raw data.
         */
        public:
            /**
             * Get the size of a file.
             * @param fd file descriptor
             * @return int result
             */
            int GetFileSize(FILE *fd);
            BINLEX_EXPORT Raw();
            /**
             * Read data.
             * @param data pointer to uint8_t vector
             * @return bool
             */
	        BINLEX_EXPORT virtual bool ReadVector(const std::vector<uint8_t> &data);
            BINLEX_EXPORT ~Raw();
    };
}

#endif
