#include<iostream>
#include<string>

using namespace std;

int countSpaces(string s);
bool checkPermutation(string s);

int main()
{
	string s;
	cout<<"Enter a string"<<endl;
	getline(cin,s);

	bool result = checkPermutation(s);

	if(result)
		cout<<"String \""<<s<<"\" is a permutation of a palindrome string"<<endl;
	else
		cout<<"String \""<<s<<"\" is not a permutation of a palindrome string"<<endl;

}

int countSpaces(string s){
	int count = 0;

	for(int i=0; i<s.length(); i++){
		if(s[i] == ' ')
			count++;
	}

	return count;
}

bool checkPermutation(string s){

	int spaces = countSpaces(s);
	int effLength = s.length() - spaces; // Effective length after excluding spaces

	int char_set[128] = {0};

	for(int i=0; i<s.length(); i++){
		if(s[i] != ' '){
			int index = s[i];
			if(char_set[index] == 0)
				char_set[index] = 1;
			else
				char_set[index] = 0;
		}
	}

	int letters = 0;	// Count number of letters appeared once, if this number is more than 1 and effLength is odd then function returns False

	for(int i=0; i<128; i++){
		if(char_set[i] == 1)
			letters++;
	}

	if(effLength%2 == 1 && letters == 1)
		return true;
	else if(effLength%2 == 0 && letters == 0)
		return true;
	else
		return false;
}