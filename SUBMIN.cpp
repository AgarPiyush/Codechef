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
ll sum;
ll c=1,flag=0;
ll n,a[100];

void call(ll in)
{
	ll el=1;
	c++;
	flag=1;
	ll i,j,count=1;
	for(i=in+1;i<n;i++)
	{
		if(a[i]>=a[in])
		{
		c=c+count;el++;
		}
		else break;
	}
	//printf("common %lld \n",c);
	count=el;
	//printf("count %lld \n",count);
	for(i=in-1;i>=0&&a[i]>a[in];i--)
	{
		c=c+count;
	}
	//printf("here %lld\n",c);
}
int main()
{
	ll i,j,k,p,l,t,m,o,q;
	inp(n);
	for(i=0;i<n;i++)
	inp(a[i]);
	inp(q);
	for(i=0;i<q;i++)
	{
		c=0;
		inp(o);
		for(j=0;j<n;j++)
		{
			if(a[j]==o)
			call(j);
		}
		out(c);
	}
	return 0;
}

