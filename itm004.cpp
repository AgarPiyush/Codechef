/* Author : Piyush Agarwal

 _._ _..._ .-',     _.._(`))
'-. `     '  /-._.-'    ',/
   )         \            '.
  / _    _    |             \
 |  a    a    /              |
 \   .-.                     ;  
  '-('' ).-'       ,'       ;
     '-;           |      .'
        \           \    /
        | 7  .__  _.-\   \
        | |  |  ``/  /`  /
       /,_|  |   /,_/   /
          /,_/      '`-'
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
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
 
/*inline void finp(ll *a )
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
ll power(ll b,ll e,ll mod)
{
	
	ll x=1;
	while(e>0)
	{
		if(e&1)
			x=(x*b)%mod;
		b=(b*b)%mod;
		e=e/2;
	}
	return x;
}
ll mod=1000000007;

ll gcd(ll a,ll b)
{
    if(b==0)
          return a;
    return gcd(b,a%b);
}
ll mult(ll A,ll B)
{
	if ( B == 0 ) return 0;
	ll u = mult(A, B/2);
	ll res;
	if ( B%2 == 0 ) 
		res = u + u;
	else
		res = u + u + A;
	while ( res >= mod ) res -= mod;
	return res;
}
ll t,i,j,k,l,m,n,a[1000005],b[1000005],fact[10000005];
string s;
int main()
{
	inp1(t);
	fact[0]=1;
	for(i=1;i<=1000000;i++) fact[i]=(fact[i-1]*i)%mod;
	while(t--)
	{
		cin >> s;
		inp1(n);
		n=(n-1)/2;
		ll facn=power(fact[n],mod-2,mod)%mod;
		ll sum1=0,sum2=0;
		l=s.length();
		for(i=0;i<l;i++)
		{
			a[i]=0;
			if(s[i]=='l') sum1++;
			if(s[i]=='o') a[i]=sum1; 
		}
		sum1=0;
		for(i=l-1;i>=0;i--)
		{
			b[i]=0;
			if(s[i]=='l') sum1++;
			if(s[i]=='o') b[i]=sum1;
		}
		ll ans=0;
		for(i=0;i<l;i++)
		{
			if(s[i]=='o')
			{
				if(a[i]<n||b[i]<n)
					continue;
				ans=(ans+(((((fact[b[i]]*facn)%mod)*power(fact[b[i]-n],mod-2,mod))%mod)
					   	 *((((fact[a[i]]*facn)%mod)*power(fact[a[i]-n],mod-2,mod))%mod)))%mod;
			}
		}
		printf("%lld\n",ans%mod);
	}
	return 0;
}
