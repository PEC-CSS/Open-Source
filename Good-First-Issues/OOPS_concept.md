Some Basic Concepts of OOPS

Class - is a user defined data-type which holds its own data members and member functions which can be accessed and used by creating an instance of that class.
Class is like blueprint of the object where Object is an instance of the class, actually when class is defined no memory is allocated but when object is created memory is allocated.

Syntax for defining Class in C++:

 class ClassName
{
   
   Access modifier; // public, private, protected
   Data members;
   Member functions ()
  {
     //some code
  }

};

Class can be accessed using objects.

Declaring object-

ClassName objectName ;
 
 Or
	
Intializing object –

ClassName objectName = new ClassName();


Constructors are special type of member functions/Methods that which are called automatically at the time of object creation. There is no need to call it unlike functions.

Syntax for Constructor in C++:
   
     ClassName ()
     {
        //some code
     }

There are mainly 3 types of Constructor:
* Default
* Parameterized
* Copy Constructor


Destructors are special type of member functions that are called by compiler when the scope of the object ends.


Syntax for Destructor in C++:
   
     ~ ClassName ()
     {
        //some code
     }


Example of class, Constructor and Destructor:

#include <iostream>
using namespace std;
class A
{
    public:
    string name;
 
 A()
 {
    cout<<"this is constructor"<<endl;
 }
 
   void showName()
   {
      cout<<name;
   }
~A()
 {
    cout<<endl<<"this is destructor"<<endl;
 }

 };

 int main() {
     A obj;
    obj.name = "Anurag";
    obj.showName();
    return 0;
}
Inheritance can be defined as the capability of the class to derive the properties and characteristics from another class is called Inheritance. It is one of the important features of Object Oriented Programming that provides reusability.

There are 5 types of Inheritance –

* Single inheritance – When one class is derived from only one single class or in                      other words, when subclass is inherited by only one single class.

* Multiple Inheritance – When a class is derived from more than one class.

* Multilevel Inheritance – When a derived class is inherited by another derived class.

* Hierarchical Inheritance – When more than one subclass is inherited from a single base class.

* Hybrid Inheritance – It is implemented by combining more than one type of Inheritance.
  

Syntax for Inheritance in C++:

Class Base_ClassName
{
 //Access Modifier

 // some code
};
Class Derived_ClassName::access_modifier Base_className
{
  //Access Modifier

  //some code
};


Example of Inheritance in C++:

//single inheritance

#include<iostream>
using namespace std;

class A
{
 public:
 void display()
 {
  cout<<"This is from base class"<<endl;
 }
};

class B : public A{
 public:
void show()
{
 cout<<"This is from derived class";

}
};

int main(){
  B obj;
  obj.display();
obj.show();
}




Method Overloading is also called function overloading. When there are multiple functions with same name but different parameters then these functions are said to be overloaded. Functions can be overloaded by change in number of arguments or change in the type of arguments.

Example:
  
#include<iostream>
using namespace std;

void overfun(){
 cout<<0<<endl;
}
void overfun(int a,int b)
{
   cout<<a<<" "<<b<<endl;
}
void overfun(int a,int b,int c)
{
   cout<<a<<" "<<b<<" "<<c<<" "<<endl;
}
void overfun(int a, string b)
{
   cout<<a<<" "<<b<<endl;
}

int main(){
  overfun(); //passing no arguments
  overfun(2,5);   
  overfun(2,5,6); // changing number of arguments
  overfun(2,"hi"); //change in the type of arguments
}


Method Overriding occurs when a derived class has a definition for one of the member function of the base class. That base class is said to be overridden.Method overriding is also called Function Overrriding.

Example:
#include <iostream>
using namespace std;

class Base {
   public:
    void print() {
        cout << "Base Function" << endl;
    }
};

class Derived : public Base {
   public:
    void print() {
        cout << "Derived Function" << endl;
    }
};

int main() {
    Derived derived1;
    derived1.print();
    return 0;
}




Abstract Class in C++ is a class that has at least one pure virtual function (i.e., a function that has no definition).

Example:

#include <iostream>
using namespace std;

// Abstract class
class Shape {
   protected:
    float dimension;

   public:
    void getDimension() {
        cin >> dimension;
    }

    // pure virtual Function
    virtual float calculateArea() = 0;
};

// Derived class
class Square : public Shape {
   public:
    float calculateArea() {
        return dimension * dimension;
    }
};

// Derived class
class Circle : public Shape {
   public:
    float calculateArea() {
        return 3.14 * dimension * dimension;
    }
};

int main() {
   Square square;
    Circle circle;

    cout << "Enter the length of the square: ";
    square.getDimension();
    cout << "Area of square: " << square.calculateArea() << endl;

    cout << "\nEnter radius of the circle: ";
    circle.getDimension();
    cout << "Area of circle: " << circle.calculateArea() << endl;

    return 0;
}


