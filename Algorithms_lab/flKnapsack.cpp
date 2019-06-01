#include<iostream>
#include<algorithm>

#define MAXSIZE 100
using namespace std;

struct Knap {

		float value;
		int weight;
		float vBYw;
		float fill;
};

bool compare(Knap lhs, Knap rhs) { return lhs.vBYw > rhs.vBYw ; }

class Array {

        Knap Knapsack [MAXSIZE];
		int size;
	public:
		void input() {

			cout<<"Enter the number of objects:";
			cin>>size;
			cout<<"Enter the weights and values respectively:";
			for(int i = 0; i < size; i++) {
                cout<<"\nOBJ "<<i+1<<':';
                cin>>Knapsack[i].weight>>Knapsack[i].value;
                Knapsack[i].vBYw = Knapsack[i].value/Knapsack[i].weight;
            }
		}

		void output() {
            int sum=0;
            cout<<"The elements of solution set are: "<<endl;
            for(int i = 0; i < size; i++){
                cout<<Knapsack[i].fill<<" "<<Knapsack[i].weight<<" "<<Knapsack[i].value<<"\n";
                sum+=Knapsack[i].value;
            }
            cout<<"The Total profit: "<<sum;
        }

		Array& fillKnapsack(Array& candidateSet,int weight) {

		    Array solutionSet;
            int sum = 0, i = 0, j = 0, x = 0;

            Knap temp,temp1;

            sort(candidateSet.Knapsack,candidateSet.Knapsack + candidateSet.size, compare );

            while(i <= candidateSet.size ) {

                temp = candidateSet.Knapsack[i];
                x = temp.weight;
                i++;

                if(sum + x <= weight) {
                    temp.fill = 1.0;
                    solutionSet.Knapsack[j] = temp;
                    sum += x;
                    j++;
                }
                else break;
            }

            float mk;

            temp1 = candidateSet.Knapsack[i - 1];

            solutionSet.size = j+1;
            mk = ((weight - sum)*1.0 ) / temp1.weight;
            temp.fill = mk;
            temp.weight = mk*temp1.weight;
            temp.value = mk*temp1.value;
            temp.vBYw = mk*temp1.vBYw;

            solutionSet.Knapsack[j] = temp;

            return solutionSet;
    }
};

int main() {

    Array A,B;
    int ch;
    cout<<"Enter the maximum weight:";
    cin>>ch;

    A.input();
    B = A.fillKnapsack(A,ch);
    B.output();
    return 0;
}
