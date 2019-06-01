#include<iostream.h>
#include<conio.h>
class Complex{
	int x, y;
	public:
		void getdata(){
			cout<<"Enter x and y\n";
			cin>>x>>y;
		}
		void printdata(){
			cout<<"\nComplex number: "<<x<<"+i"<<y;
		}
		int compute(Complex &obj,Complex &obj1){
			x=obj.x+obj1.x;
			y=obj.y+obj1.y;
			return 1;
		}
};

int main(){
	Complex c1, c2, c3;
	clrscr();
	c1.getdata();
	c2.getdata();
	c3.compute(c1,c2);
	c1.printdata();
	c2.printdata();
	c3.printdata();
	getch();
	return 1;
}





