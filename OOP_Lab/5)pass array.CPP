#include<iostream.h>
#include<conio.h>

int *multiplybythree(int a[]){
	for(int i=0;i<5;i++){
		a[i]=a[i]*3;
	}
	return a;
}

int main(){
	int a[5], i, *p;

	clrscr();
	cout<<"Enter the elements\n";
	for(i=0; i<5;i++){
		cin>>a[i];
	}
	p=multiplybythree(a);
	cout<<"Elements after computation:\n ";
	for(i=0; i<5;i++){
		cout<<p[i]<<endl;
	}
	getch();
	return 1;
}