#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<limits.h>

class max{
	int *a, n, left, right;
public:
	max(){
		n=0;
		left=0;
		right=0;
	}
	void getdata();
	void ncube();
	void nsqr();
	void dc();
	int maxSumSubArray(int left, int right);
	int findCrossSum(int left, int right, int mid);
	~max(){};
};

void max :: getdata(){
	cout<<"Enter the number of elements: ";
	cin>>n;
	a=(int *)calloc(n, sizeof(int));
	cout<<"Enter the elements: "<<endl;
	for(int i=0; i<n; i++){
		cin>>a[i];
	}
	ncube();
	nsqr();
	dc();
}

void max::ncube(){
	int ms=INT_MIN, sum, tr, tl;
	for(int l=0; l<n; l++){
		tl=l;
		for(int r=l; r<n; r++){
			tr=r;
			sum=0;
			for(int i=l; i<=r;i++){
				sum+=a[i];
			}
			if(ms<sum){
				right=tr;
				left=tl;
				ms=sum;
			}
		}
	}
	cout<<"n-cube: "<<endl;
	cout<<"Maximum contiguous sum: "<<ms<<endl;
	cout<<"From :"<<left<<" To :"<<right<<endl;
}

void max::nsqr(){
	int ms=INT_MIN, sum, tl, tr;
	for(int l=0; l<n; l++){
		tl=l;
		sum=0;
		for(int r=l; r<n; r++){
			tr=r;
			sum+=a[r];
			if(ms<sum){
				ms=sum;
				right=tr;
				left=tl;
			}
		}
	}
	cout<<"n-sqr: "<<endl;
	cout<<"Maximum contiguous sum: "<<ms<<endl;
	cout<<"From :"<<left<<" To :"<<right<<endl;
}
void max::dc(){
	int sum=0;
	sum=maxSumSubArray(0, n);
	cout<<"Divide and conquer"<<endl;
	cout<<"Maximum contiguous sum: "<<sum<<endl;
}

int max::maxSumSubArray(int left, int right) {

	    int mid, sum1, sum2, crossSum;
	    mid = (left + right)/2;

	    if(left < right) {
		sum1 = maxSumSubArray(left, 	mid);
		sum2 = maxSumSubArray(mid+1, right);
		crossSum = findCrossSum(left, right, mid);

		if( sum1 >= sum2 && sum1>= crossSum ) return sum1;

		else if( sum2 >= sum1 && sum2>= crossSum ) return sum2;

		else return crossSum;

	    }
	    return a[mid];
	}

int max:: findCrossSum(int left, int right, int mid) {

	    int lSum, rSum, temp = mid, sum = 0;
	    lSum = rSum = INT_MIN;
	    while(temp >= left) {

		sum += a[temp];
		if(sum > lSum) lSum = sum;
		temp--;
	    }

	    temp = mid+1;
	    sum = 0;

	    while(temp <= right) {
		sum += a[temp];
		if(sum > rSum) rSum = sum;

		temp++;
	    }
	    return lSum + rSum;
}
int main(){
	max A;
	clrscr();
	A.getdata();
	getch();
	return 0;
}