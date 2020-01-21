#ifndef KOLD_DB_WAIT_QUEUE
#define KOLD_DB_WAIT_QUEUE

#include <chrono>
#include <thread>
#include <mutex>
#include <condition_variable>

// to be implmented #include "task.hpp"
typedef int Task;

template <class ADTQueue>
class WaitQueue
{
public:
  WaitQueue();
  ~WaitQueue();

 void Push(const Task& task);
 
 template <class typeof> typeof Pop();
 template <class typeof> typeof TimedPop(std::chrono::nanoseconds timeout);
  
private:
   WaitQueue(const WaitQueue& other);
   WaitQueue& operator=(const WaitQueue& other);
  
  ADTQueue m_queue;
  std::mutex m_lock;
  std::condition_variable m_queue_not_empty;
};

template <class Q>
WaitQueue<Q>::WaitQueue()
  : m_queue()
  , m_lock()
  , m_queue_not_empty()
{}

template <class Q>
WaitQueue<Q>::~WaitQueue(){}

template <class Q>
void WaitQueue<Q>::Push(const Task& task)
{
  std::unique_lock<std::mutex> scope_lock(m_lock);

  m_queue.push(task);

  m_queue_not_empty.notify_one();
}

template <class Q>
template <class typeof>
typeof WaitQueue<Q>::Pop()
{
    std::unique_lock<std::mutex> scope_lock(m_lock);

    while (m_queue.empty())
    {
        m_queue_not_empty.wait(m_lock);
    }
    
    typeof ret_val = m_queue.front();
    m_queue.pop();
    
    return ret_val;
}

template <class Q>
template <class typeof>
typeof WaitQueue<Q>::TimedPop(std::chrono::nanoseconds timeout)
{
    std::unique_lock<std::mutex> scope_lock(m_lock);

    while (m_queue.empty())
    {
        m_queue_not_empty.wait_for(std::chrono::duration_cast<std::chrono::nanoseconds>(timeout), m_lock);
    }
    
    typeof ret_val = m_queue.front();
    m_queue.pop();
    
    return ret_val;
}

#endif // KOLD_DB_WAIT_QUEUE


