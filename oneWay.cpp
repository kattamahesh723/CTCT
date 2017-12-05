#include<iostream>
#include<string>

using namespace std;

bool checkOneWay(string s, string t);

int main()
{
	string s,t;
	cout<<"Enter two strings"<<endl;
	cin>>s>>t;

	bool result = checkOneWay(s,t);

	if(result)
		cout<<"String "<<s<<" and string "<<t<<" are one or zero edits away"<<endl;
	else
		cout<<"String "<<s<<" and string "<<t<<" are more than one or zero edits away"<<endl;
}

bool checkOneWay(string s, string t){
	int sLength = s.length();
	int tLength = t.length();

	if(sLength-tLength > 1 || tLength-sLength > 1)
		return false;

	int nEdits = 0;

	if(sLength == tLength){
		for(int i=0; i<sLength; i++){
			if(s[i] != t[i]){
				nEdits++;
				if(nEdits>1)
					return false;
			}
		}
		return true;
	}
	else {
		int i=0, j=0;

		while(i<sLength && j<tLength){
			if(s[i] != t[j]){
				nEdits++;
				if(sLength > tLength)
					i++;
				else
					j++;
				if(nEdits>1)
					return false;
			}
			else{
				i++;
				j++;
			}
		}
		return true;
	}

}