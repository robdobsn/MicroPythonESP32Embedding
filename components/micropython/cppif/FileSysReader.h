/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// RIC Micropython
//
// Rob Dobson 2016-20
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <stdint.h>

class FileSysReader
{
public:
    static const int CHARS_TO_CACHE = 50;
    FileSysReader(const char* filename);
    int read();
    void close();

    static const int MAX_FILE_PATH_LEN = 200;
    char _filePath[MAX_FILE_PATH_LEN];
    uint8_t _buf[CHARS_TO_CACHE];
    uint32_t _cacheLen;
    uint32_t _cachePos;
    bool _isFinal;
    uint32_t _filePos;
};
