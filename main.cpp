#include <stdio.h>
#include <emscripten/bind.h>

using namespace emscripten;

struct B
{
    int num;
    B()
    {
        printf("B::B()\n");
    }
    B(const B &b)
    {
        printf("B::B(&b)\n");
        num = b.num;
    }
    ~B()
    {
        printf("B::~B()\n");
    }
};

struct A
{
    B field;
    A()
    {
        printf("A::A()\n");
    }
    A(const A &a)
    {
        printf("A::A(&a)\n");
        field = a.field;
    }
    ~A()
    {
        printf("A::~A()\n");
    }
};

EMSCRIPTEN_BINDINGS(my_module)
{
    class_<B>("B").constructor<>().property("num", &B::num);
    class_<A>("A").constructor<>().property("field", &A::field);
}