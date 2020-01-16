#ifndef KOLD_BPP_TREE_HPP
#define KOLD_BPP_TREE_HPP

#include "key_value.hpp"

template <typename T>
class Btree: IKeyValueCollection<T>
{
private:
        
public:
        Btree() {}
        ~Btree() {}

        T& Put(std::string key, T& value);
        T& Get(std::String key);
        T& Delete(std::String key);
};


#endif // KOLD_BPP_TREE_HPP
