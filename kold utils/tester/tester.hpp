#ifndef KOLD_DB_TESTER_HPP
#define KOLD_DB_TESTER_HPP


typedef int Logger;

#include <vector>
#include <iostream>

class Tester
{
public:
    Tester();
    ~Tester();
    Tester(const Tester& other);
    Tester& operator=(const Tester& other);
    
    void AddFunction(std::function test_func);
    void RemoveFunction(std::function test_func);
    bool IsRegistered(std::function test_func);
    
    void SetOutput(std::ostream output);
    
    void RunTests();

    
private:    
    Logger& m_logger;
    std::vector<std::function> m_test_functions;
}

#endif // KOLD_DB_TESTER_HPP
