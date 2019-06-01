#include<iostream.h>
#include<conio.h>
class array{
	int *a, n;
public:
	void swap(int *a, int *b);
	int partition(int p, int r);
	void quicksort(int p, int r);
	void func();
	void print();
};


void array:: swap(int *a, int *b){
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}

int array:: partition(int p, int r){
	int pivot, i, j;
	pivot=a[r];
	i=p-1;
	for(j=p; j<r; j++){
		if(a[j]<=pivot){
			i+=1;
			swap(&a[i], &a[j]);
		}
	}
	swap(&a[i+1], &a[r]);
	return i+1;
}

void array:: quicksort(int p, int r){
	int q;
	if(p<r){
		q=partition(p, r);
		quicksort(p, q-1);
		quicksort(q+1, r);
	}
}

void array:: func(){
	int i;
	cout<<"Number of elements: "<<endl;
	cin>>n;
	a=new int[n];
	cout<<"Enter the elements"<<endl;
	for(i=0; i<n; i++){
		cin>>a[i];
	}
	quicksort(0, n-1);
	print();
	delete [] a;
}
void array:: print(){
	int i;
	cout<<"Sorted Array"<<endl;
	for(i=0; i<n; i++){
		cout<<a[i]<<'\t';
	}
}
int main(){
	array A;
	clrscr();
	A.func();
	getch();
	return 0;
}