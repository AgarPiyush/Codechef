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
ll t,i,j,k,l,m,n,a[1000005],c[1000000];
void segment(ll node,ll b,ll e)
{
	if(b==e)
	{
		a[node]=c[b];
		return;
	}
	segment(2*node,b,(e+b)/2);
	segment(2*node+1,(e+b)/2+1,e);
	a[node]=gcd(a[2*node],a[2*node+1]);
}
ll quer(ll node,ll b,ll e,ll i,ll j)
{
	if(i<=b&&j>=e)
		return a[node];
	
	if(e<i||b>j)
		return -1;
	
	ll a1=quer(2*node,b,(e+b)/2,i,j);
	ll a2=quer(2*node+1,(e+b)/2+1,e,i,j);
	if(a1==-1) return a2;
	else if(a2==-1) return a1;
	else return gcd(a1,a2);
}

string s;
int main()
{
	finp(&t);
	while(t--)
	{
		ll q;
		finp(&n);
		finp(&q);
		for(i=0;i<n;i++) finp(&c[i]);
		segment(1,0,n-1);
		while(q--)
		{
			finp(&j);
			finp(&k);
			j--;k--;
			ll ans;
			if(j==0)
				ans=quer(1,0,n-1,k+1,n-1);
			else if(k==n-1)
				ans=quer(1,0,n-1,0,j-1);
			else
				ans=gcd(quer(1,0,n-1,0,j-1),quer(1,0,n-1,k+1,n-1));
			printf("%lld\n",ans);

		}
	}

	return 0;
}
