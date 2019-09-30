
#include <iostream>
#include "mmobject.h"


class A : public MMObject {
 
public: 
	A(MMObject * parent = nullptr) : MMObject(parent){
		printf("A()\n");
	}
	~A() {
		printf("~A()\n");
	}
};


class B : public MMObject {

public:
	B(MMObject* parent = nullptr) : MMObject(parent) {

		printf("B()\n");
	}

	~B() {
		printf("~B()\n");
	}
};


class C : public A, public B {

public:
	C(MMObject* parent = nullptr): A(parent), B(parent)  {
		printf("C()\n");
	}
	~C() {
		printf("~C()\n");
	}
};


int main()
{
   std::cout << "Hello World!\n";

   auto a = new A();

   auto b = new B(a);

   auto c = new C(b);

   delete a;

}
