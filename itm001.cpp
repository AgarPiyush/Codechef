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
ll t,i,j,k,l,m,n,a[1000005];
string s;
ll cal(ll k)
{
		ll ans1;
		ll sq1=(ceil)((-1+sqrt(1+8*k))/2);
		double chk=(-1+sqrt(1+8*k))/2.0;
		if((double)sq1==chk)
		{
			if(sq1%2==1)
				ans1=a[sq1];
			else
				ans1=a[sq1-1];
		}
		else
		{
			sq1--;
			if(sq1%2==0)
				ans1=a[sq1-1];
			else
				ans1=a[sq1];
			sq1++;
			if((k-ans1)%2==1)
				ans1+=sq1;
		}
		return ans1;
}
int main()
{
	a[1]=1;
	ll q=1;
	for(i=1;i<=1000000;i++)
	{
		if(i%2==1)
		{
			a[i]=(q)*(q);
			q++;
		}
	}
	inp1(t);
	while(t--)
	{
		inp2(k,j);
		printf("%lld\n",cal(j)-cal(k-1));


	}
	return 0;
}
