/*
	Q.  Write a method to replace all spaces in a string with "%20". You may assume that the string
		has sufficient space at the end to hold the additional characters, and that you are given 
		the "true" length of the string.
*/

#include<iostream>
#include<string>

using namespace std;

void replaceSpaces(char s[],int length);

int main()
{
	char s[] = "My name is John      ";
	int length = 15;
	
	replaceSpaces(s,length);
	cout<<s<<" and length is "<<strlen(s)<<endl;
}

void replaceSpaces(char s[], int length){
	int l = strlen(s);
	int k = length;

	while(l > 0){
		l--;
		k--;
		cout<<"s[k] "<<s[k]<<" and s[l] "<<s[l]<<endl;
		if(s[k] == ' '){
			s[l] = '0';
			s[l-1] = '2';
			s[l-2] = '%';
			l = l-2;
		}
		else{
			s[l] = s[k];
		}

	}

}