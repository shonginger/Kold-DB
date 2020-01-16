#ifndef CALLABLE_INTERFACE_HPP
#define CALLABLE_INTERFACE_HPP

template <typename T>
class ICallable
{
public:
        virtual T* operator()() = 0;
};

#endif // CALLABLE_INTERFACE_HPP