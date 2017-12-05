#include<iostream>
#include<string>

using namespace std;

int main()
{
	string s;
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

	cout<<"Is given string has unique characters? "<<result<<endl;
}