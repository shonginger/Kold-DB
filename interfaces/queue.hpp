#ifndef QUEUE_INTERFACE_HPP
#define QUEUE_INTERFACE_HPP


template <typename T>
class IQueue
{
        public:
                virtual IQueue();
                virtual ~IQueue() = 0;
                virtual T& Enqueue(T& element) = 0;
                virtual T& Dequeue() = 0;
                virtual bool Empty() const = 0;
};

#endif // QUEUE_INTERFACE_HPP