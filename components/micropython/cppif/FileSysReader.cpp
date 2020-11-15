/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// RIC Micropython
//
// Rob Dobson 2016-20
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <FileSysReader.h>
#include "string.h"
#include "esp_log.h"

#ifdef __cplusplus
extern "C" {
#endif
#include "py/reader.h"
#include "py/runtime.h"
#include "py/mperrno.h"
#include "py/mpthread.h"
#ifdef __cplusplus
}
#endif

FileSysReader::FileSysReader(const char* filename)
{
    _cacheLen = 0;
    _cachePos = 0;
    _filePos = 0;
    _isFinal = false;
    strlcpy(_filePath, "/spiffs/", sizeof(_filePath));
    strlcat(_filePath, filename, sizeof(_filePath));
    read();
}

int FileSysReader::read()
{
    // Open file
    FILE* pFile = fopen(_filePath, "rb");
    if (!pFile)
    {
        ESP_LOGE("FileSysReader", "Can't open %s", _filePath);
        return 0;
    }

    // Move to appropriate place in file
    if (fseek(pFile, _filePos, SEEK_SET) == 0)
    {
        // Read
        _cacheLen = fread((char*)_buf, 1, CHARS_TO_CACHE, pFile);
        _filePos += _cacheLen;
        if (_cacheLen != CHARS_TO_CACHE)
            _isFinal = true;
    }
    else
    {
        _cacheLen = 0;
        _isFinal = true;
    }
    // Close
    fclose(pFile);
    if (_cacheLen == 0)
        _isFinal = true;
    return _cacheLen;
}

void FileSysReader::close()
{
}

extern "C" mp_uint_t mp_reader_ric_readbyte(void *data) {
    FileSysReader* pFSReader = (FileSysReader*)data;
    if (pFSReader->_cachePos >= pFSReader->_cacheLen) {
        if (pFSReader->_cacheLen == 0) {
            return MP_READER_EOF;
        } else {
            MP_THREAD_GIL_EXIT();
            int n = pFSReader->read();
            MP_THREAD_GIL_ENTER();
            if (n <= 0) {
                return MP_READER_EOF;
            }
        }
    }
    int readVal = pFSReader->_buf[pFSReader->_cachePos++];
    return readVal;
}

extern "C" void mp_reader_ric_close(void *data) {
    FileSysReader* pFSReader = (FileSysReader*)data;
    MP_THREAD_GIL_EXIT();
    pFSReader->close();
    MP_THREAD_GIL_ENTER();
    if (pFSReader)
        delete pFSReader;
    pFSReader = NULL;
}

extern "C" void mp_reader_new_file(mp_reader_t *reader, const char *filename) {
    MP_THREAD_GIL_EXIT();
    FileSysReader* pFSReader = new FileSysReader(filename);
    MP_THREAD_GIL_ENTER();
    if (!pFSReader)
        mp_raise_OSError(MP_EIO);
    reader->data = pFSReader;
    reader->readbyte = mp_reader_ric_readbyte;
    reader->close = mp_reader_ric_close;
}
