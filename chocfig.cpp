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
ll mark[1000000];
string s;
int main()
{
	inp1(t);
	while(t--)
	{
		inp1(n);
		for(i=0;i<n;i++)
		{
			mark[i]=0;
			inp1(a[i]);
		}
		ll l=0,r=n-1;
		ll suml=0,sumr=0;
		if(l!=r)
		{
			mark[l]=mark[r]=1;
			suml=suml+a[l];
			sumr=sumr+a[r];
		}
		while(l!=r)
		{
			while(suml<=sumr&&l<r)
			{
				if(mark[l]==0)
					suml=suml+a[l];
				mark[l]=1;
				l++;
			}
			while(sumr<=suml&&l<r)
			{
				if(mark[r]==0)
					sumr=sumr+a[r];
				mark[r]=1;
				r--;
			}
		}
		if(l==r)
		{
			if(sumr<suml&&mark[l]==0)
				r--;
			else if(mark[l]==0&&sumr>=suml)
				l++;
		}
		printf("%lld %lld\n",l,n-l);
	}
	return 0;
}
