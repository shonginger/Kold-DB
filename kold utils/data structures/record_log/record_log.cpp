#include "record_log.hpp"

static size_t _buffer_size = 0x2000; // 8k

RecordLog::RecordLog(const std::string logName)
        :_buffer(_buffer_size)
{
        _log.open(logName, std::fstream::app);
}

void RecordLog::AddRecord(const std::string record)
{
        if (!_buffer.Write(record))
        {               
                if (!_buffer.Dump(_log).Write(record))
                {
                        _log.write(record.data(), record.length());
                }
        }
}

RecordLog::~RecordLog()
{
        _log.flush();

        _log.close();
}