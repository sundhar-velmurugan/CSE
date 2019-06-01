#include <iostream.h>
#include <conio.h>

class Parent{
	public:
		Parent(){
			cout<<"\nConstructor of parent class";
		}
		~Parent(){
			cout<<"\nDestructor of base class";
		}
};

class Child:public Parent{
	public:
		Child(){
			cout<<"\nConstructor of child class";
		}
		void display(){
			cout<<"\nObject of child is created";
		}
		~Child(){
			cout<<"\nDestructor of child class";
		}
};

int main(){
	Child obj;
	obj.display();
	getch();
	return 1;
}