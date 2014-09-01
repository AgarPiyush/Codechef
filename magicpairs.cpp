#include<iostream>
int main()
{
	using namespace std;
	long long int i,j,k,t,n;
	std::cin>> t;
	while(t--)
	{
		cin >> n;
		for(i=0;i<n;i++)
		cin >> j;
		k=(n)*(n-1)/2;
		cout << k<<"\n";
	}
	return 0;
}
