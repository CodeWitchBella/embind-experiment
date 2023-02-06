#include <stdio.h>
#include <emscripten/bind.h>

using namespace emscripten;

int counter = 0;

struct Nested
{
    int num;
    Nested()
    {
        printf("Nested::Nested()\n");
        counter++;
    }
    Nested(const Nested &b)
    {
        printf("Nested::Nested(&b)\n");
        num = b.num;
        counter++;
    }
    ~Nested()
    {
        printf("Nested::~Nested()\n");
        counter--;
    }
};

struct RootClass
{
    Nested field;
    RootClass()
    {
        printf("RootClass::RootClass()\n");
        counter++;
    }
    RootClass(const RootClass &a)
    {
        printf("RootClass::RootClass(&)\n");
        field = a.field;
        counter++;
    }
    ~RootClass()
    {
        printf("RootClass::~RootClass()\n");
        counter--;
    }
};

struct RootValue
{
    Nested field;
    RootValue()
    {
        printf("RootValue::RootValue()\n");
        counter++;
    }
    RootValue(const RootValue &a)
    {
        printf("RootValue::RootValue(&)\n");
        field = a.field;
        counter++;
    }
    ~RootValue()
    {
        printf("RootValue::~RootValue()\n");
        counter--;
    }
};

struct WrapperClass
{
    RootValue field;
    WrapperClass()
    {
        printf("WrapperClass::WrapperClass()\n");
        counter++;
    }
    WrapperClass(const WrapperClass &a)
    {
        printf("WrapperClass::WrapperClass(&)\n");
        field = a.field;
        counter++;
    }
    ~WrapperClass()
    {
        printf("WrapperClass::~WrapperClass()\n");
        counter--;
    }
};

RootValue getRootValue()
{
    return RootValue{};
}

Nested getNested()
{
    return {};
}

int readCounter()
{
    return counter;
}

EMSCRIPTEN_BINDINGS(my_module)
{
    class_<Nested>("Nested").constructor<>().property("num", &Nested::num);
    class_<RootClass>("RootClass").constructor<>().property("field", &RootClass::field);
    class_<WrapperClass>("WrapperClass").constructor<>().property("field", &WrapperClass::field);
    value_object<RootValue>("RootValue").field("field", &RootValue::field);
    function("getRootValue", getRootValue);
    function("getNested", getNested);
    function("readCounter", readCounter);
}
