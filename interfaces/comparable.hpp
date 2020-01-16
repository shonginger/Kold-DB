#ifndef COMPARABLE_INTERFACE_HPP
#define COMPARABLE_INTERFACE_HPP

template <typename T>
class IComparable
{
public:
        static virtual int operator==(T& a, T& b) const = 0;        
};

#endif // COMPARABLE_INTERFACE_HPP