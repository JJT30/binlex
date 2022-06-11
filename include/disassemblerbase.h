#ifndef DISASSEMBLERBASE_H
#define DISASSEMBLERBASE_H

#include <stdint.h>
#include <fstream>
#include <capstone/capstone.h>
#include "json.h"
#include "file.h"
#include "args.h"

using json = nlohmann::json;

namespace binlex {
    class DisassemblerBase : public Common {
        /**
         * This class shares common methods between all decompilers.
         */
        public:
            const binlex::File &file_reference;
            /**
             * Decompiler constructor requiring file object.
             * @param fileref File object
             */
            DisassemblerBase(const binlex::File &firef);
            /**
             * Get Traits as JSON
             * @return list of traits json objects
             */
            virtual vector<json> GetTraits() = 0;

            /**
             * Write Traits to output or file
             * This function usees GetTraits() to get the traits data as a json.
             */
            BINLEX_EXPORT void WriteTraits();

            /*
            * The following functions are for pybind-only use. They offer a way to pass arguments to
            * the CPP code, which otherwise if obtained via command-line arguments.
            */

            /**
             * Set Threads and Thread Cycles, via pybind11
             * @param threads number of threads
             */
            BINLEX_EXPORT void py_SetThreads(uint threads);
            /**
             * Sets The Corpus Name, via pybind11
             * @param corpus pointer to corpus name
             */
            BINLEX_EXPORT void py_SetCorpus(const char *corpus);
            /**
             * Sets the tags, via pybind11
             * @param tags set of tags
             */
            BINLEX_EXPORT void py_SetTags(const vector<string> &tags);
            /**
             * Set decompiler mode, via pybind11
             * @param mode decompiler mode
             */
            BINLEX_EXPORT void py_SetMode(string mode);
    };
}
#endif
