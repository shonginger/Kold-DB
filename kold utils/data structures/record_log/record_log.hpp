#ifndef RECORD_LOG_HPP
#define RECORD_LOG_HPP

#include <fstream>

#include "buffer.hpp"

class RecordLog
{
private:
        std::ofstream _log;
        Buffer _buffer;
        static size_t _buffer_size;

public:
        RecordLog(const std::string logName);
        ~RecordLog();

        void AddRecord(const std::string record);

        // will take effect only for new buffers
        inline void SetBufferSize(size_t size) { _buffer_size = size; }

};



#endif // RECORD_LOG_HPP