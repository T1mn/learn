#include <type_traits>
#include <iostream>

struct A {
    A()= default;
    int m;
};

struct B {
    int m;
};

struct C{
    C(){}
    int m;
};

int main(int argc, char**argv)
{
    std::cout << std::boolalpha;
    std::cout << std::is_trivial<A>::value << '\n';
    std::cout << std::is_trivial<B>::value << '\n';
    std::cout << std::is_trivial<C>::value << '\n';
}