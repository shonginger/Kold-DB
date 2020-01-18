
#ifndef SIMPLE_BUFFER_HPP
#define SIMPLE_BUFFER_HPP

#include <string>
#include <cstring>

class Buffer
{        
private:
        char* _storage;
        size_t _vacancy;
        const size_t _capacity;
        
public:
        Buffer(size_t size);
        ~Buffer();

        bool Write(const std::string& bytes);
        Buffer& Dump(std::ofstream& stream);
};

#endif // SIMPLE_BUFFER_HPP

