# Virtual Functions and Virtual Pointers

This blog discusses about Virtual Functions and Virtual Pointers.

## Dynamic and Static Binding

By Default, C++ matches a function call with the correct funtion defination at the compile time. THis is called _static binding_. But we can specify thatt the compiler match a funciton call with the correct duntion eefineition at the ; this is caled _dynamic binding_.

This is achieved by using `virtual` keyword.

To give you demonstration:

```cpp
#include <iostream>
using namespace std;

struct A {
   void f() { cout << "Class A" << endl; }
};

struct B: A {
   void f() { cout << "Class B" << endl; }
};

void g(A& arg) {
   arg.f();
}

int main() {
   B x;
   g(x);
}

```

For this code in C++, what do you think the output will be? trying running it in your system.

Output:

```
Class A
```

**Explaination** :
When fuction g() is called, function A::f() is called, although the argument refers to an object of type B. At compile time, the compiler knows only that the argument of function g() will be reference to an object derived from A; it cannot determine whether the argument will be a refernece to an ojbect of type A or type B. However this canbe determined at runtime.

The following example is the same as the previous example, except that A::f() is declared with the `virtual` keyword:

```cpp
#include <iostream>
using namespace std;

struct A {
   virtual void f() { cout << "Class A" << endl; }
};

struct B: A {
   void f() { cout << "Class B" << endl; }
};

void g(A& arg) {
   arg.f();
}

int main() {
   B x;
   g(x);
}
```

here the output is

```
Class B
```

The `virtual` keyword indicates to the compiler that it should choose the appropriate definition of f() not by the type of reference, but by the type of object that the reference refers to.

## What is Virtual Function?

After having seen the above example, we can define virtual function as a member function you may redefine for other derived classes, and can ensure that the compiler will call the redefined virtual function for an object of the corresponding derived class, even if you call that function with a pointer or reference to a base class of the object.

A class that declares or inherits a virtual function is called a polymorphic class

## Virtual Pointers

There are two things that occur when we create an object of a class which has virtual function as member.

-   If object of that class is created then a **virtual pointer (VPTR**) is inserted as a data member of the class to point to VTABLE of that class. For each new object created, a new virtual pointer is inserted as a data member of that class.
-   Also, a class will contain a static array of functions pointers caleed **VTABLE**. Cells of this table stores the address of each virtual function contained in that very class

```cpp
#include <iostream>
using namespace std;

class base {
public:
    void fun_1() { cout << "base-1\n"; }
    virtual void fun_2() { cout << "base-2\n"; }
    virtual void fun_3() { cout << "base-3\n"; }
    virtual void fun_4() { cout << "base-4\n"; }
}
class derived : public base {
public:
    void fun_1() { cout << "derived-1\n"; }
    void fun_2() { cout << "derived-2\n"; }
    void fun_4(int x) { cout << "derived-4\n"; }
};

int main()
{
    base *p;
    derived obj1;
    p = &obj1;

    // Early binding because fun1() is non-virtual
    // in base
    p->fun_1();

    // Late binding (RTP)
    p->fun_2();

    // Late binding (RTP)
    p->fun_3();

    // Late binding (RTP)
    p->fun_4();

    // Early binding but this function call is
    // illegal (produces error) because pointer
    // is of base type and function is of
    // derived class
    // p->fun_4(5);

    return 0;
}
```

Output

```
base-1
derived-2
base-3
base-4
```

Here a VTABLE was created by compiler for base class which had all the pointers for the virtual functions.

**Explaination**:

-   A class `fun1` was not virtual so the base class `fun1()` was executed
-   A class'`fun2` was virtual function so the derived class member was executed
-   A class `fun3` was not overridden by derived class
-   A classs' `fun4()` and B class' `fun4(int x)` are two different functions, so it won't be overridden.

## Conclusion

Virtual Functions let the system decide which method to run at the run time and is an important aspect of Runtime Polymorphism and Object Oriented Programming.

For further reading I would recommend this [blog](https://www.ibm.com/docs/en/i/7.4?topic=only-virtual-functions-c) and [this one](https://www.geeksforgeeks.org/virtual-function-cpp/)

Explained with ♥ by [Sanjeev](https://github.com/tobixoxo)
