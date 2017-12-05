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