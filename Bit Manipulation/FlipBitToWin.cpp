#include <iostream>

using namespace std;

int longestSequence(int N){
	//cout<<"In longest sequence method"<<endl;
	int globalMax = 0;
	int curLength = 0;
	int curMax = 0;

	bool secondFlip = false;		

	while(N){
		if(N%2){
			curLength++;
			curMax++;
			
		}
		else{

			if(secondFlip) curMax = curLength + 1;
			else curMax++;

			secondFlip = ~secondFlip;
			curLength = 0;
		}
		globalMax = max(globalMax, curMax);

		N = N>>1;
	}

	return globalMax;
	
}

int main()
{
	int N;

	cout<<"Enter number"<<endl;
	cin>>N;

	cout<<"Binary representation of N: "<<bitset<10>(N)<<endl;
	//bitset<16> binary_N(N);

	int result = longestSequence(N);

	cout<<"Maximum number 1's sequence possible is "<<result<<endl;
}