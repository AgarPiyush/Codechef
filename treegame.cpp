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
ll t,i,j,k,m,n,l[1000005],mark[100000];
vector<ll> a[100000];
void level(ll cou,ll val)
{
	l[val]=cou;
	mark[val]=1;
	for(ll i=0;i<a[val].size();i++)
	{
		if(!mark[a[val][i]])
		{
			level(cou+1,a[val][i]);
		}
	}
}
int main()
{
	inp1(t);
	while(t--)
	{
		inp1(n);
		for(i=1;i<=n;i++)
		{
			a[i].clear();l[i]=-1;
			mark[i]=0;
		}
		for(j=0;j<n-1;j++)
		{
			inp2(i,k);
			a[i].pb(k);
			a[k].pb(i);
		}
	//	printf("done\n");
		l[1]=1;
		mark[1]=1;
		ll nu[100005]={0};
		level(1,1);
		ll ma=0,sum=0;
	//	printf("level \n");
		for(i=1;i<=n;i++)
		{
			nu[l[i]]++;
	//		printf("%lld %lld\n",i,l[i]);
			ma=max(ma,l[i]);
		}
		//printf("number of level\n");
		for(i=1;i<=ma;i++)
		{
			sum=sum+nu[i];
		//	printf("%lld ",nu[i]);
		}
		ll c=0;
		ll ans=0,lev=1,finl=ma;
		while(sum>0)
		{
		//	printf("sum is %lld\n",sum);
			if(c%2==0)
			{
				sum=sum-nu[lev];
				//printf("subr %lld\n",nu[l[lev]]);
				nu[lev++]=0;
				ans++;
			}
			else
			{
				sum--;
				nu[finl]--;
				if(nu[finl]==0)
					finl--;
				ans++;
			}
			c++;
		}
		printf("%lld\n",ans );

	}
   return 0;
}