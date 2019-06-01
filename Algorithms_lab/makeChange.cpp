#include<iostream>
#include<algorithm>
#include<conio.h>

#define MAXSIZE 100
using namespace std;

class MK {

		int A[MAXSIZE];
		int size;
	public:

	    Array() {

            for(int i = 0; i <= MAXSIZE; i++) A[i] = 0;
	    }

		void input() {

			cout<<"Size of candidate set: ";
			cin>>size;
			cout<<"Enter the candidate set:"<<endl;
			for(int i = 0; i < size; i++) cin>>A[i];
		}

		void output() {

			cout<<"The elements of solution set are: ";
			for(int i = 0; i < size; i++) cout<<A[i]<<" ";
		}

		MK& makeChange(MK& candidateSet, int change) {

            MK solutionSet, nullSet;
            int sum = 0, i = 0, j = 0, x = 0;
            //sort(begin, end, order)
            sort(candidateSet.A,candidateSet.A + candidateSet.size, greater<int>());

            while(sum <= change && i <= candidateSet.size ) {

                x = candidateSet.A[i];
                i++;
                if(sum + x <= change) {
                    solutionSet.A[j] = x;
                    sum += x;
                    j++;
                }
            }

            solutionSet.size = j;
            if(sum == change)    return solutionSet;
            return nullSet;
		}
};

int main() {

    MK A,B;
    int ch;
    cout<<"Enter the amount:";
    cin>>ch;

    A.input();
    B = A.makeChange(A,ch);
    B.output();
    getch();
    return 0;
}
