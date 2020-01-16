#ifndef POOL_INTERFACE_HPP
#define POOL_INTERFACE_HPP

template<typename T>
class IPool
{
public:
        virtual IPool();
        virtual ~IPool() = 0;
        virtual Task* AddTask(Task& task) = 0;        
        virtual T* Await(Task& task) = 0;

        struct Task
        {
                void* _function;
                void* _args;
        };
};

#endif // POOL_INTERFACE_HPP
