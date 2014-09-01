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

ll i,j,k,l,a[30][30000],boolean[30][30000];

ll pairs[30][30000],number[30000];
ll n,m,maxi=1;
int chk(ll sum)
{
	ll o,p,flag1=0;
	for(o=1;o<=sum;o++)
	{
		for(p=1;p<=sum;p++)
		{
			if(!pairs[number[o]][number[p]])
			{
				flag1=1;break;
			}
		}
		if(flag1)
		break;
	}
	if(flag1)
	return 0;
	else
	return 1;
	
} 
void cal(ll i)
{
	ll c=1;
	for(j=m-1;j>=0;j--)
	{
		 if((i>>j)&1)
		{
			number[c++]=j+1;
		}
	}
	if(c>maxi)
	{
		int u;
	/*	for(u=1;u<c;u++)
		printf("%lld ",number[u]);
		printf("\n");
	*/
		int y;
		y=chk(c-1);
		if(y==1)
		{
	//		printf("yes");
		maxi=c-1;
/*		for(u=1;u<c;u++)
		printf("%lld ",number[u]);
		printf("yes\n");
*/
		}
	}
}
int main()
{
	fscan(&n);fscan(&m);
	for(i=1;i<=m;i++)
	{
		inp(a[i][0]);
		for(j=1;j<=a[i][0];j++)
		{
			fscan(&a[i][j]);
			boolean[i][a[i][j]]=1;
		}
		pairs[i][i]=1;
	}
	for(i=1;i<=m;i++)
	{
		for(j=1;j<=m;j++)
		{
			int flag=0;
			if(j==i)
			 continue;
			
			for(k=1;k<=n;k++)
			{
				if(boolean[i][k]==boolean[j][k]&&boolean[i][k]==1)
				{
					flag=1;break;
				}	
			}
			if(!flag)
			pairs[i][j]=1;
		}	
	}
	
	for(i=(1<<m)-1;i>=0;i--)
	cal(i);
	
	printf("%d\n",maxi);
	return 0;
}

