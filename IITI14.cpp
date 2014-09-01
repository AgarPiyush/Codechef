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
#define out(a) printf("%lld\n",a)
#define swap(a,b) {a=a+b;a=a-b;b=a-b;}
#define VI vector<int>
#define VLL vector<long long int>
#define PQI priority_queue<int>
#define PQLL priority_queue<long long int>
#define ll long long int
#define mod 1000000007
#define getcx getchar_unlocked
int main()
{
	ll i,j,l,m,t,n,k,a[100010];
	inp(t);
	while(t--)
	{
		ll z=0,gr=0,c=0;
		inp(n);inp(k);
		for(i=0;i<n;i++) 
		{
			inp(a[i]);
			if(!a[i])
			z++;
			if(a[i]>1) gr++;
		}
		if(z>=2) printf("-l\n");
		else
		{
		sort(a,a+n);
		if(a[1]>k)
		printf("0\n");
		else
		{
		if(gr>1)
		{
		while(a[n-1]<=k)
		{
			c++;
			a[n-1]=a[n-1]*a[n-2];
		}
		for(i=n-2;i>0;i--)
		{
			if(a[i]<=k)
			c++;
		}
		out(c);
		}
		else if(gr==1)
		{
			if(n==2)
			{
				if(a[1]>k)
				printf("0\n");
				else if(a[0]==0) printf("-1\n");
				else 
				{
					a[0]=a[1]*a[0];
					c++;
					while(a[1]<=k)
					{
						a[1]=a[1]*a[0];
						c++;
					}
					printf("%lld\n",c);
				}
			}
			else
			{
				a[n-2]=a[n-2]*a[n-1];
				c++;
				while(a[n-1]<=k)
				{
					a[n-1]=a[n-1]*a[n-2];
					c++;
				}
				for(i=n-2;i>0;i--)
				{
				if(a[i]<=k)
				c++;
				}
				printf("%lld\n",c);
			}
		}
		else if(gr==0)
		{
			if(a[0]==0&&k>0) printf("-1\n");
			else 
			{
				if(k==0) printf("0\n");
				else printf("-1\n");
			}
		}
		}
	}
	}
	return 0;
}

