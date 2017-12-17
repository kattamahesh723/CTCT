#include <iostream>
#include <time.h>

using namespace std;

int main()
{
	time_t timer;
	timer = time(NULL);
	int in;
	cout<<timer<<endl;
	cin>>in;
	time_t time2 = time(NULL);
	cout<<time2<<endl;

	cout<<(timer == time2)<<endl;
}