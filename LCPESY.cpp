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
char s[1000000],t1[1000000];
ll str1[10000],str2[10000];
	
int main()
{
	ll t,i,j,k,l,m,l1,l2;
	inp(t);
	while(t--)
	{
		long long int c=0;
		scanf("%s",s);
		scanf("%s",t1);
		l1=strlen(s);l2=strlen(t1);
		for(i=0;i<l1;i++)
		str1[s[i]]++;
		for(i=0;i<l2;i++)
		if(str1[t1[i]])
		{
			c++;
			str1[t1[i]]--;
		}
		for(i=0;i<=1000;i++) str1[i]=0;
		out(c);
	}
	return 0;
}

