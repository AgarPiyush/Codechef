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
ll dp[100000],f[10000],a[1005][1005],temp=0;
int main()
{
	ll n,i,j;
	for(i=1;i<=1000;i++)
	{
	a[i][1]=i;
	a[1][i]=1;
	a[i][0]=0;
	a[0][i]=0;
	}
	f[1]=1;f[2]=2;f[3]=3;
	for(i=2;i<=1000;i++)
	{
		ll flag=0;
		ll k=(ll)sqrt(i);
		for(j=2;j<=k;j++)
		{
			if(i%j==0)
			{
				flag=1;
				temp=j;
			}
		}
		f[i]=i;
		if(flag)
		f[i]=temp;
	}
	for(i=1;i<=1000;i++)
	{
		for(j=2;j<=1000;j++)
		{
			if(j>i)
			a[i][j]=a[i][j-1]+1;
			else
			{
			ll fac=i/f[i];
			a[i][j]=min(a[i/fac][1]+a[fac][j-1],a[i][j-1]+1);	
			}
		}
	}/*
	for(i=7;i<=10;i++)
	{
		for(j=1;j<=10;j++)
		printf("%lld ",a[i][j]);
		printf("\n");
	}*/
	ll t;
	inp(t);
	while(t--)
	{
		ll n,k;
		inp(n);inp(k);
		printf("%lld.000000\n",a[k][n]);
	}
	return 0;
}

