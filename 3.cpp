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
#define mod 1000000
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
ll i,j,k,l,t,dp[3000010],hash[3000010],repeat[3000010],all[3000010],pos[3000010],flag;

int main()
{
	inp(t);
	while(t--)
	{
		ll n,a,b,c,d,sum1=0,sum2=0,max,fin=0,count=1;
		flag=0;
		inp(n);inp(a);inp(b);inp(c);inp(d);
		dp[0]=d;
		max=d;
		hash[dp[0]]=1;
		all[0]=d;
		for(i=1;i<n;i++)
		{
			dp[i]=(dp[i-1]*(a*dp[i-1]+b)+c)%mod;
			if(hash[dp[i]]==1)
			hash[dp[i]]=0;
			else
			hash[dp[i]]=1;
		}
	
	}
	return 0;
}

