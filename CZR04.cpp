#include<iostream>
#include<cstdio>
#include<climits>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<set>
#include<cmath>
#include<queue>
using namespace std;
#define inp(a) scanf("%lld",&a)
#define line(a) printf("%lld ",a);
#define next() printf("\n");
#define out(a) printf("%lld\n",a)
#define swap(a,b) {a=a+b;a=a-b;b=a-b;}
#define VI vector<int>
#define VLL vector<long long int>
#define PQI priority_queue<int>
#define PQLL priority_queue<long long int>
#define ll long long int
#define mod 1000000007
#define getcx getchar_unlocked
/*inline void fscan(ll *a )
{
	ll n=0; int ch = getcx(); int sign = 1;
	while(ch < '0' || ch > '9')
	{
	if(ch == '-') sign=-1; ch = getcx();
	}
	while(ch >= '0' && ch <= '9')
	{
	n = (n << 3) + (n << 1) + ch - '0', ch = getcx();
	}
	*a = n * sign;
}*/
double i,j,hr,mins;
ll t;
int main()
{
	inp(t);
	while(t--)
	{
		double p;
		cin >> hr;
		cin >> mins;
		if(hr<0||hr>=24||mins<0||mins>=60)
		cout << "Invalid Time\n" ;
		else
		{
			if(hr>=12)
			hr=hr-12;
			double hra;
			double mina;
			mina=6*mins;
			hra=30*hr+mina/12.0;
			
			printf("%.1lf\n",min(abs(hra-mina)+0.00001,360-abs(hra-mina)+0.00001));
		}
	}
	return 0;
}

