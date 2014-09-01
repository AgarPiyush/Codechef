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
#include<fstream>
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
ll a[100000]={0},ct=0,cf=0,c1=0;
ll cal(ll n)
{
	ct=0,cf=0,c1=0;
	ll ans=0;
		for(ll i=1;i<=n/2;i++)
		{
			ll l=i;
			ll r=n-i;
			if(l!=r)
			{
				ll f=(ll)sqrt(l*r);
				if(f*f==l*r)
				{
				ans=ans+2*f-2;
				ct+=f-1;
				}
				else
				{
				ans=ans+2*f;
				ct+=f;
				}
				for(ll k=1;k<=n/2;k++)
				{
				ll f;
				double temp=(l*r*1.0)/k;
				ll o=(ll)(temp)*10;
				if(temp*10!=o&&temp-k>0)
				{
				ans=ans+(4*(((ll)(temp)-k)));cf+=(ll)(temp)-k;
				}
				else if(temp*10==o&&temp-k-1>0)
				{
				ans=ans+(4*(((ll)(temp)-k-1)));cf+=(ll)(temp)-k-1;
				}
				}
			}	
			else
			{
				ll f=(ll)sqrt(l*r);
				if(f*f==l*r)
				{
				ans=ans+f-1;
				c1+=f-1;
				}
				else
				{
				ans=ans+f;
				c1+=f;
				}
				for(ll k=1;k<=n/2;k++)
				{
				ll f;
				double temp=(l*r*1.0)/k;
				ll o=(ll)(temp)*10;
				if(temp*10!=o&&temp-k>0)
				{
				ans=ans+(2*(((ll)(temp)-k)));ct+=(ll)temp-k;
				}
				else if(temp*10==o&&temp-k-1>0)
				{
				ans=ans+(2*(((ll)(temp)-k-1)));ct+=(ll)temp-k-1;
				}
				}
			}
		}
		return ans;
}
int main()
{
	ll i,j,k,l,m,n;
	ofstream p;
	p.open("output.txt");
	a[0]=a[1]=0;
	for(i=1;i<=2500;i++)
	{
		if(i>1)
		a[i]=cal(i);
		p << a[i] <<",";
	}

	return 0;
}

