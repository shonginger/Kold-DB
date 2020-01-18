#ifndef POOL_TASK_HPP
#define POOL_TASK_HPP

#include "callable.hpp"

template<typename T>
class Task: ICallable<T>
{
public:
        Task(T& (*function)(void*), void* args = nullptr);
        ~Task();
        T& operator()();

private:
        T& (*_with_args)(void*);
        T& (*_no_args)();
        void* _args;
};

template<typename T>
T& Task<T>::operator()()
{
        return _args ? _with_args(_args) : _no_args();
}

template<typename T>
Task<T>::Task(T& (*function)(void*), void* args)        
{
        if (args)
        {                
                _with_args = function;
        }
        else
        {                
                _no_args = function;
        }
        _args = args;
}


#endif // POOL_TASK_HPP