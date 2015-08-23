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
ll t,i,j,k,l,m,n,a[1000005], temp[1000005];
map<ll,ll> ma;
string s;
int main()
{
	inp2(n,m);
	for(i = 0; i<n ; i++) 
	{
		inp1(a[i]); 
		if(ma.find(a[i]) == ma.end())
			ma[a[i]] = 1;
		else
			ma[a[i]]++;
	}
	ll val = a[0];
	for(i=1 ; i<n ; i++)
	{
		if(a[i] > val)
		{
			ma[a[i]] += i;
			val = a[i];
		}
		else
			ma[val] += i;
	}
	for(i=0 ; i<n ; i++)
		cout << a[i] << " " << ma[a[i]] <<"\n";
	while(m--)
	{
		getchar();
		char e, f;
		scanf("%c %lld %c", &e,&k,&f );

	}	
	return 0;
}
