#ifndef POOL_TASK_HPP
#define POOL_TASK_HPP

#include "callable.hpp"

template<typename T>
class Task: ICallable<T>
{
public:
        Task();
        ~Task();
        T* operator()();

private:
        T* (*_function)(void*);
        void* _args;
        pthread_t _threadId;
};

template<typename T>
T* Task<T>::operator()()
{
        return _function(_args);
}


#endif // POOL_TASK_HPP