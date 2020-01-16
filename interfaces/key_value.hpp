#ifndef KEY_VALUE_COLLECTION_INTERFACE_HPP
#define KEY_VALUE_COLLECTION_INTERFACE_HPP

#include "comparable.hpp"

template <typename T)>
class IKeyValueCollection
{
public:
        virtual IKeyValueCollection();
        virtual ~IKeyValueCollection() = 0;

        virtual T& Put(std::string key, T& value) = 0;
        virtual T& Get(std::string key) = 0;
        virtual T& Delete(std::string key) = 0;

};

#endif // KEY_VALUE_COLLECTION_INTERFACE_HPP