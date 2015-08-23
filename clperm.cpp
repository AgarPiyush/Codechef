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
ll t,i,j,k,l,m,n,a[1000005],last_val[100005],pre_val[100005];
vector<pair<ll,ll> > v;
string s;
int main()
{
	inp1(t);
	while(t--)
	{
		inp2(n,k);
		for(i=0;i<k;i++)
			inp1(a[i]);
		if(k==0)
		{
			ll val=(n*(n+1))/2;
			if((val+1)%2==0)
				printf("Mom\n");
			else
				printf("Chef\n");
		}
		else
		{
			a[k]=n+1;
			k++;
			sort(a,a+k);
			if(a[0]==1)
			{
				printf("Chef\n");
				continue;
			}
			v.clear();
			last_val[k-1]=a[k-1]+1;
			for(i=k-2;i>=0;i--)
			{
				if(a[i]+1==a[i+1])
					last_val[i]=last_val[i+1];
				else
					last_val[i]=a[i]+1;
			}
			pre_val[0]=a[0]-1;
			v.pb(mp(pre_val[0]+1,last_val[0]-1));
			for(i=1;i<k;i++)
			{
				if(a[i]==a[i-1]+1)
					pre_val[i]=pre_val[i-1];
				else
					pre_val[i]=a[i]-1;
				if(pre_val[i-1]!=pre_val[i]&&last_val[i]!=last_val[i-1])
					v.push_back(make_pair(pre_val[i]+1,last_val[i]-1));
			}
			//for(i=0;i<v.size();i++)
			//	printf("%lld %lld\n",v[i].first,v[i].second);
			ll val=((v[0].first-1)*(v[0].first))/2;
			for(i=0;i<v.size()-1;i++)
			{
				if(v[i].second>val)
					break;
				ll cal=((v[i+1].first*(v[i+1].first-1))/2-(v[i].second*(v[i].second+1))/2);
				val=val+cal;
			}
			//printf("val is %lld\n",val);
			if((val+1)%2==0)
				printf("Mom\n");
			else
				printf("Chef\n");
		}
	}
	return 0;
}
