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
int dp[100][100],i,j,k,l,a[1000];
int main()
{
	ll n;
	inp(n);
	for(i=0;i<n;i++)
	inp(a[i]);
	inp(k);
	for(i=0;i<n;i++)
	dp[i][(a[i]+k)%k]=1;
	for(i=1;i<n;i++)
	for(j=0;j<k;j++)
	dp[i][j]+=(dp[i-1][j]+dp[i-1][(j-a[i])%k]);
	for(i=0;i<n;i++)
	{
		for(j=0;j<k;j++)
		printf("%lld ",dp[i][j]);
		printf("\n");
	}
	return 0;
	
}

