#ifndef POOL_INTERFACE_HPP
#define POOL_INTERFACE_HPP

#include "pool_task.hpp"

template<typename T>
class IPool
{
public:
        virtual IPool();
        virtual ~IPool() = 0;
        virtual Task<T>* AddTask(Task<T>& task) = 0;        
        virtual T* AwaitTask(const Task<T>& task) = 0;
};


#endif // POOL_INTERFACE_HPP
