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
ll i,j,k,l,m,n;
char a[1000005];
int main()
{
    ll t;
  inp1(t);
getchar();
	
  while(t--)
  {
	ll dp[100005]={0},prev[1000]={0},sum[100005]={0};
	scanf("%s",a);
      n=strlen(a);
      printf("%s\n",a);
      for(i=1;i<=l;i++)
	prev[a[i]]=-1;
      dp[0]=1;
      sum[0]=1;
      for(i=1;i<=n;i++)
      {
            char k=a[i-1];
            if(prev[k]==-1)
                dp[i]=((sum[i-1]%mod)+mod)%mod;
            else
                dp[i]=(((sum[i-1]-sum[prev[k]-1])%mod)+mod)%mod;
            sum[i]=(sum[i-1]+dp[i])%mod;
            prev[k]=i;
      }
   printf("%lld\n",(((sum[n])%mod)+mod)%mod);
}
   return 0;
}

