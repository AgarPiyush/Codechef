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
#define out(a) printf("%d\n",a)
#define swap(a,b) {a=a+b;a=a-b;b=a-b;}
#define VI vector<int>
#define VLL vector<long long int>
#define PQI priority_queue<int>
#define PQLL priority_queue<long long int>
#define ll int
#define mod 1000000007
#define getcx getchar_unlocked
inline void fscan(ll *a )
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
}
int t,hash[12],i,l,j,k,ans[100009],d=0;
string s;
int main()
{
	fscan(&l);
	fscan(&t);
	cin >> s;
	ans[0]=0;
	hash[s[0]-48]++;
	for(i=1;i<l;i++)
	{
		k=s[i]-48;
		d=0;
		for(j=0;j<=10;j++)
		{
			if(hash[j]>0)
			d=d+abs(j-k)*hash[j];
		}
		hash[k]++;
		ans[i]=d;
	}
	for(i=1;i<=t;i++)
	{
		fscan(&k);
		out(ans[k-1]);
	}
	return 0;
}

