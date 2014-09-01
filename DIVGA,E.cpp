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
char a[1000000];
ll i,j,k,n;
int main()
{
	a[1]='T';
	a[2]='M';
	a[3]='T';
	for(i=4;i<=500;i++)
	{
		if(a[i-1]=='T')
		a[i]='M';
		else
		{
			int flag=0;
			ll sq=sqrt(i);
			for(j=2;j<sq;j++)
			{
				if(i%j==0)
				{
					if(a[j]=='T')
					{
						a[i]='M';
						flag=1;
						break;
					}
				}
			}
			if(!flag)
			a[i]='T';
		}
	}
	for(i=1;i<=200;i++)
	if(a[i]=='M')
	printf("%d ",i);
	return 0;
	
}

