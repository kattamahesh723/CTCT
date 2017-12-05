#include<iostream>
#include<string>

using namespace std;

int main()
{
	string s = "Mahesh";
	string s2 = "";

	if(s2 == "")
		s2.append(s);
	cout<<s2<<" "<<s2.length()<<endl;
}