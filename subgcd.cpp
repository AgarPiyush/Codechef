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
ll t,i,j,k,l,m,n,a[1000005];
int main()
{
	ll t;
	inp1(t);
	while(t--)
	{
		inp1(n);
		for(i=0;i<n;i++)
			inp1(a[i]);
		unsigned ll pro=1;
		ll ans=1;
		pro=a[0];
		ll temp=1;
		i=1;
		for(j=0;j<n;j++)
		{
		for(;i<n;i++)
		{
			if(gcd(pro,a[i])==1)
				pro=pro*a[i];
			else
			{
				pro=pro/a[j];
				break;
			}
			if(ans<i-j+1) ans=i-j+1; 
		}
		}
		if(ans==1)
			printf("-1\n");
		else
			printf("%lld\n",ans );
	}
   return 0;
}