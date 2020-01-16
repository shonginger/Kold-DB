#ifndef __KOLD_DB_FORMAT
#define __KOLD_DB_FORMAT

#include <cstddef>
#include <string>

// sections - header, entries, index, footer

// file header

// entry

struct Entry
{
        std::string _key;
        std::string _value;
};



// index
struct IndexItem
{
        size_t _hashed_key;
        size_t _offset;
};


// footer


// constants - fixed file sizes? section limits? naming scheme?


#endif // __KOLD_DB_FORMAT
