#include <fstream>

#include "buffer.hpp"

Buffer::Buffer(size_t size)
        :_storage(new char[size]), _vacancy(size), _capacity(size)
{}

Buffer::~Buffer()
{
        delete[] _storage;
}

bool Buffer::Write(const std::string& bytes)
{
        const size_t writeLen = bytes.length();

        if (_vacancy >= writeLen)
        {
                memmove(_storage + (_capacity - _vacancy), bytes.data(), writeLen);

                _vacancy -= writeLen;

                return true;
        }

        return false;
}

Buffer& Buffer::Dump(std::ofstream& stream)
{
        stream.write(_storage, _capacity - _vacancy);
        _vacancy = _capacity;
}