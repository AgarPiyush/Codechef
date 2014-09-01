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
ll gcd(ll x,ll y)
{
	if(y==0)
	return x;
	else
	return gcd(y,x%y);
}
ll i,k,l,m,n,a[1000000];
int main()
{
	inp(n);
	inp(a[0]);
	ll gcdint=a[0];
	for(i=1;i<n;i++)
	{
		inp(a[i]);
		gcdint=gcd(gcdint,a[i]);
	}
	if(gcdint%2==0)
	{
		while(gcdint%2==0)
		gcdint=gcdint/2;
	}
	out(gcdint);
	return 0;
}

