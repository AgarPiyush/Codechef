//Author : Piyush Agarwal
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define inp1(a) scanf("%lld",&a);
#define outl(a) printf("%lld\n",a);
#define out(a) printf("%lld ",a);
#define line printf("\n");
#define FOR(i,b,e) for(i=b;i<=e;i++)
#define mp make_pair
#define pb push_back
#define inp2(a,b) scanf("%lld %lld",&a,&b)
#define getcx getchar_unlocked
#define chkbit(s,b) (s & (1<<b))
#define setbit(s,b) (s | (1<<b))
#define clrbit(s,b) (s &= ~(1<<b))
 
inline void finp(ll *a )
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
ll power(ll b,ll e)
{
	ll x=1;
	while(e>0)
	{
		if(e&1)
			x=x*b;
		b=b*b;
		e=e/2;
	}
	return x;
}  
ll gcd(ll a,ll b)
{
    if(b==0)
          return a;
    return gcd(b,a%b);
}
ll t,i,j,k,l,m,n,a[3][100005];
ll m1=0,m2=0,m3=0;
ll check_first(ll k,ll p)
{
		k=max(k,p);
		if(k==p) 
		{
				m1=1;m2=0;m3=0;
		}
		return k;
}
ll check_second(ll k,ll p)
{
		k=max(k,p);
		if(k==p) 
		{
				m1=0;m2=1;m3=0;
		}
		return k;
}

ll check_third(ll k,ll p)
{
		k=max(k,p);
		if(k==p) 
		{
				m1=0;m2=0;m3=1;
		}
		return k;
}
int main()
{
	finp(&t);
	while(t--)
	{

	m1=0;m2=0;m3=0;
	
	ll r,g,b,ans;
	finp(&r);
	finp(&g);
	finp(&b);
	finp(&m);
	k=0;

	
	for(i=0;i<r;i++)
	{
		finp(&a[0][i]);
		k=check_first(k,a[0][i]);
	}
	for(i=0;i<g;i++)
	{
		finp(&a[1][i]);
		k=check_second(k,a[1][i]);
		
	}
	for(i=0;i<b;i++)
	{
		finp(&a[2][i]);
		k=check_third(k,a[2][i]);
	}
	ans=k;
	while(m--)
	{
		ll ans2=0;
		if(m1==1)
		{
			for(i=0;i<r;i++)
			{
				a[0][i]=a[0][i]/2;
				ans2=check_first(ans2,a[0][i]);
			}
			for (i=0;i<g;++i)
			{
				ans2=check_second(ans2,a[1][i]);
			}
			for (i=0;i<b;++i)
			{
				ans2=check_third(ans2,a[2][i]);
				
			}
		}
		else if(m2==1)
		{
			for (i=0;i<r;++i)
				ans2=check_first(ans2,a[0][i]);
			for(i=0;i<g;i++)
			{
				a[1][i]=a[1][i]/2;
				ans2=check_second(ans2,a[1][i]);
			}

			for (i=0;i<b;++i)
				ans2=check_third(ans2,a[2][i]);		
		}
		else
		{
			for (i=0;i<r;++i)
				ans2=check_first(ans2,a[0][i]);
			for (i=0;i<g;++i)
				ans2=check_second(ans2,a[1][i]);
			for(i=0;i<b;i++)
			{
				a[2][i]=a[2][i]/2;
				ans2=check_third(ans2,a[2][i]);
			}
		}
		ans=min(ans,ans2);
	}
	printf("%lld\n",ans);
	}

   return 0;
}