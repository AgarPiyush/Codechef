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

int main()
{
	ll i,k,l,t,a[10000];
	inp(t);
	while(t--)
	{
		ll ans=0,j,n;
		inp(n);
		ll sum[n];
		for(i=0;i<n;i++)
		inp(a[i]);
		sort(a,a+n);
		
		for(i=0;i<n;i++)
		{
			ans+=a[i];
		}
		ll min=LONG_MAX,min2=LONG_MAX;
		ll pos=LONG_MAX;
		for(i=0;i<n;i++)
		{
			ll max1=0,max2=0,c=0,flag=1;
			sum[i]=ans-a[i];
		
			for(j=n-1;j>=0;j--)
			{
				if(j==i)
				continue;
			//	out(i);
				if(c%2==flag)
				{
					max1=max1+a[j];
		//		printf("max1 %lld ",max1);
				}
				else
				{
					max2=max2+a[j];
		//		printf("max2 %lld",max2);
				}
				c++;
				if(c%2==0)
				flag=!flag;
				
			}
			
			ll abs;
			if(max2>max1)
			abs=max2-max1;
			else
			abs=max1-max2;
			if(abs<min)
			{
				
				min=abs;
				pos=a[i];
		//		printf("%lld %lld\n",min,pos);
			}
			else if(abs==min)
			{
				if(pos>a[i])
				pos=a[i];
		//	printf("%lld %lld\n",min,pos);
		
			}
		
		}
		
		printf("%lld %lld\n",min,pos);
	}
	return 0;
}

