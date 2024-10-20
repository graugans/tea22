#include <fmt/chrono.h>
#include <fmt/format.h>

/* .bss Segment */
int foo;
int foo2 = 0;

/* .data Segment */
int data = 45;
int data2 = 43;

/* .rodata Segment */
const int rodata = 45;
const int rodata2 = 43;



void doSomething(int value)
{
    value = value + 1;
    fmt::print("doSomething, value {}\n", value);
}

void doSomethingPtr(int* ptr)
{
    *ptr = *ptr + 1;
    fmt::print("doSomethingPtr, value {}\n", *ptr);
}

int* doReturnAPtr()
{
    int value = 4711;
    fmt::print("doReturnAPtr, value {}\n", value);
    return &value;
}

void doSomethingStatic()
{
    static int value = 56;
    value = value + 1;
    fmt::print("doSomethingStatic, value {}\n", value);
}
auto main(int argc, char** argv) -> int
{
    /**
     * The {fmt} lib is a cross platform library for printing and formatting text
     * it is much more convenient than std::cout and printf
     * More info at https://fmt.dev/latest/api.html
     */
    fmt::print("Hello, {}!\n", argv[0]);

    doSomething(42);
    int bar = 42;
    doSomething(bar);
    fmt::print("The value of bar is: {}\n", bar);

    doSomethingPtr(&bar);
    fmt::print("The value of bar after doSomethingPtr is: {}\n", bar);

    int* returnedPtr = doReturnAPtr();
    fmt::print("The value of returnedPtr content  after doReturnAPtr is: {}\n", *returnedPtr);
    doSomething(42);
    fmt::print("The value of returnedPtr content  after doReturnAPtr is: {}\n", *returnedPtr);

    doSomethingStatic();
    doSomethingStatic();
    doSomethingStatic();
    doSomethingStatic();

    fmt::print("Value of foo {} address of foo {}\n", foo, fmt::ptr(&foo));
    fmt::print("Value of foo2 {} address of foo2 {}\n", foo2, fmt::ptr(&foo2));
    fmt::print("Value of data {} address of data {}\n", data, fmt::ptr(&data));
    fmt::print("Value of data2 {} address of data2 {}\n", data2, fmt::ptr(&data2));
    fmt::print("Value of rodata {} address of rodata {}\n", rodata, fmt::ptr(&rodata));
    fmt::print("Value of rodata2 {} address of rodata2 {}\n", rodata2, fmt::ptr(&rodata2));

    int var;
    static int var2;
    fmt::print("Value of var {} address of var {}\n", var, fmt::ptr(&var));
    fmt::print("Value of var2 {} address of var2 {}\n", var2, fmt::ptr(&var2));

    return 0; /* exit gracefully*/
}
