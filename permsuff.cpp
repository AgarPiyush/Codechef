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
ll t,i,j,k,l,m,n,mark[1000005];
vector<pair<ll,ll> > p;
vector<ll> s;
bool cmp(pair<ll,ll> a,pair<ll,ll> b)
{
	if(a.second!=b.second)
		return b.second<a.second;
	return b.first>a.first;
}
int main()
{
	ll t;
	inp1(t);
	while(t--)
	{
		inp2(n,k);
		s.clear();
		p.clear();
		for(i=1;i<=n;i++)
		{
			inp1(m);
			s.push_back(m);
			mark[i]=0;
		}
		for(i=0;i<k;i++)
		{
			ll q;
			inp2(j,q);
			p.push_back(mp(j,q));
		}
		sort(p.begin(),p.end(),cmp);
	//	for(i=0;i<p.size();i++)
	//		printf("%lld %lld\n",p[i].first,p[i].second);
		vector <pair<ll,ll> >ans;
		ll v1=p[0].first,v2=p[0].second;
		for(i=1;i<p.size();i++)
		{
			if(p[i].second>=v1)
			{
				v1=min(v1,p[i].first);
			}
			else
			{
				ans.pb(mp(v1,v2));
				v1=p[i].first;v2=p[i].second;
			}
		}
	//	printf("\n");
		ans.pb(mp(v1,v2));
		ll c=0;
		for(i=0;i<ans.size();i++)
		{
		//	printf("%lld %lld\n",ans[i].first,ans[i].second );
			c++;
			for(j=ans[i].first;j<=ans[i].second;j++)
				mark[j]=c;
		}
		int flag=0;
		for(i=0;i<n;i++)
		{
				if(mark[s[i]]!=mark[i+1])
				{
					flag=1;break;
				}
		}
		if(flag) printf("Impossible\n");
		else printf("Possible\n");

	}

   return 0;
}