#include<iostream>
#include<string>

using namespace std;

bool compareStrings(string s, string t);

int main()
{
	string s,t;
	cout<<"Enter two strings to check if they are permutations of one another"<<endl;
	cin>>s>>t;

	bool result = compareStrings(s,t);

	if(result)
		cout<<"String "<<s<<" is permutation of "<<t<<endl;
	else
		cout<<"String "<<s<<" is not permutation of "<<t<<endl;
}

bool compareStrings(string s, string t){

	if(s.length() != t.length())
		return false;

	int char_set[128] = {0}; // Assumption that characters of the strinfgs are derived from fixed ASCII set

	for(int i=0; i<s.length(); i++){
		int val = s[i];
		char_set[val]++;
	}

	for(int i=0; i<t.length(); i++){
		int val = t[i];
		char_set[val]--;

		if(char_set[val] < 0)	// Indicates that a char not in string s is present in string t
			return false;
	}

	// Check if any value if the char_set is more than 0, which indicates that character present in s is not in t

	for(int i=0; i<128; i++){
		if(char_set[i] > 0)
			return false;
	}

	return true;
}