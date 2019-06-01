#include <iostream>
#include <math.h>
using namespace std;

int getLength(long long value) {
	int counter = 0;
	while (value != 0) {
		counter++;
		value /= 10;
	}
	return counter;
}

long long multiply(long long x, long long y) {

    int N, xLength, yLength;
    long long multiplier, a, b, c, d, z0, z1, z2;

	xLength = getLength(x);
	yLength = getLength(y);

	// the bigger of the two lengths
	N = (int)(fmax(xLength, yLength));

	// if the max length is small it's faster to just flat out multiply the two nums
	if (N < 10)
		return x * y;

	//max length divided and rounded up
	N = (N/2) + (N%2);

	multiplier = pow(10, N);

	b = x/multiplier;
	a = x - (b * multiplier);
	d = y / multiplier;
	c = y - (d * N);

	z0 = multiply(a,c);
	z1 = multiply(a + b, c + d);
	z2 = multiply(b, d);


    return z0 + ((z1 - z0 - z2) * multiplier) + (z2 * (long long)(pow(10, 2 * N)));

}

int main() {

	long long a, b;
	cout<<"Enter the numbers: "<<endl;
	cin>>a>>b;
	cout <<"The result: "<< multiply(a,b) << endl;
	return 0;
}
