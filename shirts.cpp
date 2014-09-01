

//Author : Piyush Agarwal
#include<bits/stdc++.h>
#include<sstream>
#include<iterator>
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
      
inline void finp(ll *n)
{
   *n = 0;
    ll ch = getchar_unlocked();
    while(ch < '0' || ch > '9')
    ch = getchar_unlocked();
    while(ch >= '0' && ch <= '9')
    (*n) = ((*n)<<3) + ((*n)<<1) + ch - '0', ch = getchar_unlocked();
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
vector<ll> a[10000];
ll i,j,k,l,m,n;
int main()
{
    string s;
    inp1(n);
    for(i=0;i<n;i++)
    {
        inp1(m);
        for(j=0;j<m;j++)
        {
            inp1(k);
            a[i].pb(k);
        }
    }
    for(i=0;i<a[0].size();i++)
    {
        
    }
   return 0;
}

 
 


