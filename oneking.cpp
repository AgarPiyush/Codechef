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
vector<pair<ll,ll> > a;
ll t,i,j,k,l,m,n;
string s;
bool cmp(pair<ll,ll> a,pair<ll,ll> b)
{
	if(a.first!=b.first)
		return b.first>a.first;
	return a.second>b.second;
}
bool cmp2(pair<ll,ll> a,pair<ll,ll> b)
{
	if(a.second!=b.second)
		return b.second>a.second;
	return b.first>a.first;
}
int main()
{
	inp1(t);
	while(t--)
	{
		inp1(n);
		for(i=0;i<n;i++)
		{
			inp2(j,k);
			a.push_back(make_pair(j,k));
		}
		sort(a.begin(),a.end(),cmp2);
	//	for(i=0;i<a.size();i++)
	//		printf("%lld %lld\n",a[i].first,a[i].second);
		ll ans=1;
		j=0,i=1;
		while(i<n)
		{
			if(a[i].first<=a[j].second)
				i++;
			else
			{
				ans++;
				j=i;
				i++;
			}
		}
		printf("%lld\n",ans);
		a.clear();
	}
	return 0;
}
