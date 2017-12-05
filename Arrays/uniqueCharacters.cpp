/*
	Implement an algorithm to determine if a string has all unique characters. No additional data structure should be used.	
*/

#include<iostream>
#include<string>

using namespace std;

int main()
{
	string s;
	cout<<"Enter string!"<<endl;
	cin>>s;
	bool char_set[256] = {false};
	bool result = true;

	for(int i=0; i<s.length(); i++){
		int val = s[i];
		if(char_set[val]){
			result = false;
			break;
		}
		char_set[val] = true;
	}

	if(result)
		cout<<"Is given string has unique characters? YES"<<endl;
	else
		cout<<"Is given string has unique characters? NO"<<endl;
}