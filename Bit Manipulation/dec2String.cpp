#include <iostream>
#include <vector>

using namespace std;
#define MAX_BITS 33




char* convertToBinary(double &number, char *bitString, int &bits){
	bool flag = true;			// Used to indicate end condition
	bitString[0] = '.';
	int i;
	for(i=0; i<MAX_BITS && flag; i++){
		//cout<<"number: "<<number<<endl;
		bits++;
		number = number*2;

		if(number >= 1){
			bitString[i+1] = '1';
			number = number - 1;
		}
		else{
			bitString[i+1] = '0';
		}

		if(number == 0)
			flag = false;
	}

	bitString[i+1] = '\0';
	if(number == 0)
		return bitString;
	
	return NULL;

}

// void printBinary(vector<int> &bitString, int &bits){
// 	for(int i=0; i<bits; i++)
// 		cout<<bitString[i]<<" ";

// 	cout<<endl;
// }

int main()
{
	double number;
	int bits = 0;
	cout<<"Enter double value"<<endl;

	cin>>number;


	//vector<int> bitString(MAX_BITS,0);

	//bits = 8;
	//printBinary(bitString, bits);

	char *bitString = (char *)malloc(sizeof(char)*MAX_BITS);

	bitString = convertToBinary(number, bitString, bits);

	if(bitString)
		cout<<bitString<<endl;
	else
		cout<<"ERROR"<<endl;
}