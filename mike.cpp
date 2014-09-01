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

ll i,j,k,l,a[30][30000],freq[30000],ind[30],temp[50],temp2[50],posrow[30],mark[30000];
ll n,m;
int main()
{
	inp(n);inp(m);
/*	for(i=1;i<=m;i++)
	{
		posrow[i]=i;
		inp(a[i][0]);
		for(j=1;j<=a[i][0];j++)
		{
			inp(a[i][j]);
			freq[a[i][j]]++;
		}
	}
	for(i=1;i<=m;i++)
	{
		ll sum=0;
		for(j=1;j<=a[i][0];j++)
		sum=sum+freq[a[i][j]];
		ind[i]=sum;
	}*/
	for(i=0;i<=(1<<m);i++)
	{
		for(j=0;j<=m;j++)
		{
			if((i>>j)&i)
			{
				printf("%lld ",j);
			}
		}
		printf("\n");
	}
	return 0;
	
}

