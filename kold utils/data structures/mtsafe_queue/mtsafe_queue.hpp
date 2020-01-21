#ifndef KOLD_DB_WAIT_QUEUE
#define KOLD_DB_WAIT_QUEUE

#include <chrono>

// to be implmented #include "task.hpp"
typedef int Task;

template <class QueueType>
class WaitQueue
{
public:
  WaitQueue();
  ~WaitQueue();

 Task Push(const Task& task);
 Task& Pop();
 Task& TimedPop(std::chrono::miliseconds timeout);
  
private:
   WaitQueue(const WaitQueue& other);
   WaitQueue& operator=(const WaitQueue& other);
  
  QueueType<Task> m_queue;
  std::mutex m_lock;
  std::condition_variable m_queue_not_empty;
}

template <class Q>
WaitQueue<Q>::WaitQueue<Q>()
  : m_queue()
  , m_lock()
  , m_queue_not_empty()
{}

template <class Q>
WaitQueue<Q>:~WaitQueue<Q>{}



#endif // KOLD_DB_WAIT_QUEUE
