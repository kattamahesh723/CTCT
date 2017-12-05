#include<iostream>
#include<fstream>
#include<string>
#include<time.h>

using namespace std;

char* stringBuilder(char current[], char extra[], int currLen, int extrLen ){

}


int main()
{
	string line;

	string mainString = "";
	string newString;

	ifstream myFile ("input2.txt");

	if(!myFile){
		cout<<"Unable to open file"<<endl;
		exit(1);
	}

	while(myFile >> line){

		if(mainString == "")
			mainString.append()
	}
	
}