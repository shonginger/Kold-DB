#include <pthread.h>
#include <sys/sysinfo.h>
#include <vector>
#include <semaphore.h>

#include "queue.hpp"
#include "pool.hpp"
#include "pool_task.hpp"

enum tpool_states_t {WORK, HALT, KILL};

template <typename T>
class ThreadPool
{

private:
        IQueue<Task<T>>* _tasks;
        pthread_t* _threads;
        volatile tpool_states_t _state;
        sem_t _pending;
        const int _numThreads;

public:
        ThreadPool();
        ~ThreadPool();
        Task<T>& AddTask(Task<T>& task);
        T& AwaitTask(Task<T> task);

        void Worker();
};

template <typename T>
Task<T>& ThreadPool<T>::AddTask(Task<T>& task)
{
        _tasks->Enqueue(task);
        sem_post(&_pending);

        return task; 
}

template <typename T>
ThreadPool<T>::ThreadPool()
        :_numThreads(get_nprocs_conf())
{

        if (sem_init(_pending, 0, 0)) {}

        _threads = new pthread_t[_numThreads];
        
        for (size_t i = 0; i < _numThreads; i++)
        {
                if (pthread_create(_threads + i, nullptr, Worker, nullptr)
                {
                        
                }
        }

        _state = WORK;
}

template <typename T>
void ThreadPool<T>::Worker()
{
        while (1)
        {
                sem_wait(_pending);
                if (WORK != _state) goto l_stateCheckup;

                Task<T> task = _tasks->Dequeue();
                T taskResult = task();
                        
                l_stateCheckup:

                if (KILL == pool->_state) 
                {
                        return;
                }
        }
}

static void apple() {}

template <typename T>
ThreadPool<T>::~ThreadPool()
{
        _state = KILL;

        for (u_int16_t i = 0; i < _numThreads; i++)
        {
                TPoolAddTask(pool, &apple);
        }

        for (u_int16_t i = 0; i < _numThreads; i++)
        {
                pthread_join(_threads[i], nullptr);

        }

        delete _tasks;
        delete _threads;
        sem_destroy(_pending);
}

