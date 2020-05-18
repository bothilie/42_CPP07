#include "Array.hpp"
#include <iostream>

int main()
{
    unsigned int n = 3;
    Array<int> a(n);
    a[0] = 10;
    a[1] = 15;
    a[2] = 20;
    const Array<int> c(a);
    Array<int> b;
    b = a;
    b = c;
    Array<int> d;
    std::cout << a.size() << std::endl;
    std::cout << b.size() << std::endl;
    std::cout << c.size() << std::endl;
    std::cout << d.size() << std::endl;
    try {
        std::cout << "element 1 de a: " << a[0] << std::endl;
        std::cout << "element 1 de b: " << b[0] << std::endl;
        std::cout << "element 1 de b: " << c[0] << std::endl;
        std::cout << "element 1 de d: " << d[0] << std::endl;
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    try {
        std::cout << "element 15: " << a[15] << std::endl;
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}