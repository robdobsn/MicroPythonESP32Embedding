/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// RIC Micropython
//
// Rob Dobson 2016-20
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "string.h"

class MicropyExecTask
{
public:
    MicropyExecTask()
    {
        _pExecStr = NULL;
        _execStrBufLen = 0;
        _isFile = false;
    }
    virtual ~MicropyExecTask()
    {
        if (_pExecStr)
            delete _pExecStr;
    }

    MicropyExecTask(const char* execStr, bool isFile)
    {
        _execStrBufLen = strlen(execStr)+1;
        _pExecStr = new char[_execStrBufLen];
        if (_pExecStr)
            memcpy(_pExecStr, execStr, _execStrBufLen);
        _isFile = isFile;
    }

    MicropyExecTask& operator=(const MicropyExecTask& other)
    {
        if (_pExecStr)
            delete _pExecStr;
        _pExecStr = NULL;
        _execStrBufLen = 0;
        if (other._pExecStr)
        {
            _execStrBufLen = other._execStrBufLen;
            _pExecStr = new char[_execStrBufLen];
            if (_pExecStr)
                memcpy(_pExecStr, other._pExecStr, _execStrBufLen);
        }
        _isFile = other._isFile;
        return *this;
    }

    MicropyExecTask(const MicropyExecTask& other)
    {
        operator=(other);
    }

    char* _pExecStr;
    int _execStrBufLen;
    bool _isFile;
};
