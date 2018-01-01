#include <iostream>
#include <cmath>
using namespace std;

bitset<32> clearBits(bitset<32> N, int i, int j){
	//bitset<32> num(pow(2,j-i+1)-1);

	bitset<32> left = (1<<i)-1;
	bitset<32> right = (1<<(j+1))-1;


	bitset<32> num = ~(left^right);
	// num = ~(num<<i);
	// 	cout<<num<<endl;
	N = N&num;

	return N;
	
}

int countBits(bitset<32> M){
	int count = 0;
	while(M != 0){
		count++;
		M = M>>1;

	}

	return count;
}

int main()
{
	// int M, N, i, j;

	bitset<32> M(0b11011);
	bitset<32> N(0b10000011000);
	int i = 2;
	int j = 6;
	int count = countBits(M);

	if(count > j-i+1)
		cout<<"Insertion not possible"<<endl;
	else{
		bitset<32> result = clearBits(N, i, j) | (M<<i);

		cout<<"After Insertion"<<endl;
		cout<<result<<endl;
	}
	
}