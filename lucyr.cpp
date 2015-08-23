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
ll t,i,j,k,l,m,n,a[1000005],b[1000005];
string s;
int main()
{
	inp1(t);
	while(t--)
	{
		cin >> s;
		l=s.length();
		int last=0;
		a[0]=0;
		b[0]=0;
		for(i=0;i<l;i++)
		{
			if(s[i]=='R')
			{
				b[i+1]=b[i];
				a[i+1]=a[i]+1;
			}
			else
			{
				a[i+1]=a[i];
				b[i+1]=b[i]+1;
			}
		}
		ll pos=0,diff=a[0]-b[0];
		for(i=1;i<=l;i++)
		{

			if(b[i]-a[i]>diff)
			{
				pos=i;
				diff=b[i]-a[i];
			}
		}
		/*printf("a is \n");
		for(i=0;i<=l;i++) printf("%lld ", a[i]);
		printf("\n");
		printf("b is \n");
		for(i=0;i<=l;i++) printf("%lld ", b[i]);
		printf("\n");
		*/
		ll f=pos;
		while(f>=0)
		{
			if(a[f]==b[f]) break;
			f--;
		}
		pos--;
		f--;
		//printf("pos %lld f is %lld\n",pos,f);
		ll c=0;
		for(i=0;i<f;i++)
			if(s[i]=='R')
				c++;
		for(i=pos+1;i<l;i++)
			if(s[i]=='R') c++;
		for(i=f;i<=pos;i++)
			if(s[i]=='K') c++;
		printf("%lld\n",c);
	}
	return 0;
}
