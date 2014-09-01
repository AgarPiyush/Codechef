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
ll t,i,j,k,n,a[10000000]={0};
	
int main()
{
	for(i=4;i<=10000;i=i+2)
	a[i]=1;
	for(i=3;i*i<=10000;i=i+2)
	{
		if(a[i]==0)
		{
			for(j=3;j*i<=10000;j=j+2)
			{
				a[i*j]=1;
			}
		}
	}

	
	inp(t);
	while(t--)
	{
		ll c,d;
		inp(c);inp(d);
		n=c+d;
		n++;
		for(i=n;;i++)
		{
			if(!a[i])
			{
			out(i-c-d);break;
			}
		}
	}
	return 0;
}

