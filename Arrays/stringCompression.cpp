/*
	Q. 	Implement a method to perform basic string compression using counts of repeated chracters. 
		For example, the string "aabcccccaaa" would become "a2b1c5a3". If the compressed string would not become 
		smaller than the original string, your method should return the original string. 
		Assumption: String has only upper or lower case letters.
*/

#include<iostream>
#include<string>

using namespace std;

string compress(string s);

int main()
{
	string s;
	cout<<"Enter string"<<endl;
	cin>>s;

	string newString = compress(s);
	
	cout<<"String \""<<s<<"\" after compression becomes \""<<newString<<"\""<<endl;
}

string compress(string s){
	int len = s.length();
	char newS[2*len];

	bool original = true;

	newS[0] = s[0];
	int j = 1;

	int consec = 1;

	for(int i=1; i<len; i++){
		if(s[i] == s[i-1])
			consec++;
		else{
			if(consec > 1)
				original = false;
			char c = '0'+consec;
			newS[j] = c;
			consec = 1;
			j++;
			newS[j] = s[i];
			j++;
		}
	}	
	if(original)
		return s;
	char c = '0'+consec;
	newS[j] = c;

	return newS;
}