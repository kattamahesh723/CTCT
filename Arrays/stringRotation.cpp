/*
	Q.  Assume you have a method isSubstring which checks if one word is a substring of another. 
		Given two substrings, s1 and s2, write code to check if s2 is a rotation of s1 using only 
		one call to isSubstring.

		Example: s1 = "waterbottle", s2="erbottlewat"
				 wat + erbottle and reversing order forms string s2
*/

#include<iostream>
#include<string>

using namespace std;

bool isSubstring(string s1, string s2);
bool isStringRotation(string s1, string s2);

int main()
{
	string s1, s2;

	cout<<"Enter string s1:"<<endl;
	cin>>s1;

	cout<<"Enter string s2:"<<endl;
	cin>>s2;

	string s;
	if(s1.length() ! s2.length())
		s = "NO";
	else
		s = isStringRotation(s1,s2)?"YES":"NO";

	cout<<"Is s2 string rotation of s1? "<<s<<endl;
}

// Checks if a string is substring of another

bool isSubstring(string s1, string s2){
	int n = s2.find(s1);

	return n != string::npos;
}

// Returns true if s2 is rotation of s1

bool isStringRotation(string s1, string s2){
	string s3 = s2;
	s3.append(s2);

	return isSubstring(s1,s3);
}