

#include "queue.hpp"
#include "pool.hpp"
#include "pool_task.hpp"


template <typename T>
class ThreadPool: IPool<T>
{
private:
        IQueue<Task<T>>* _tasks;

public:
        ThreadPool();
        ~ThreadPool();
        T& AddTask(Task<T>& task) { _tasks->Enqueue(task); return task; }
        T& AwaitTask(Task<T> task);
};

