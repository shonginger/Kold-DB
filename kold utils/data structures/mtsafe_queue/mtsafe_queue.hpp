#ifndef KOLD_DB_WAIT_QUEUE
#define KOLD_DB_WAIT_QUEUE

#include <queue>
#include <chrono>

// to be implmented #include "task.hpp"
typedef int Task;

class WaitQueue
{
public:
  WaitQueue();
  ~WaitQUeue();

 Task Push(const Task& task);
 Task& Pop();
 Task& TimedPop(std::chrono::miliseconds timeout);
  
private:
   WaitQueue(const WaitQueue& other);
   WaitQueue& operator=(const WaitQueue& other);
  
  std::queue<Task> m_queue;
  std::mutex m_lock;
  std::condition_variable m_queueNotEmpty;
}

#endif // KOLD_DB_WAIT_QUEUE
