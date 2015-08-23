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
ll t,i,j,k,l,m,n,a[1000005],ans,su,cnt,sum[100005],mark[10000];
int main()
{
	finp(&t);
	while(t--)
	{
		su=0;
		ans=0;
		finp(&n);
		finp(&k);
		for(i=0;i<n;i++) 
		{
			finp(&a[i]);
			su=su+a[i];
		}
		if(su%k!=0) printf("no\n");
		else if(k>n) 
				printf("no\n");
		else if(k==n)
		{
			int flag=0;
			for(i=0;i<n;i++)
			{
				if(a[i]==a[0])
					continue;
				flag=1;break;
			}
			if(flag)printf("no\n");
			else printf("yes\n");
		}
		else
		{
			su=su/k;
			cnt=0;
			int u=0;	
			for(i=0;i<n;i++) 
			{
				if(a[i]>su) 
				{
					u=1;
					printf("no\n");break;
				}
				 sum[i]=0;
			}
			if(u==1)
				continue;
			ll flag=0;
			//printf("n is %lld\n",n);
			for(ll i=0;i<(1<<n);i++)
			{
			ll sum1=0,sum2=0,cnt=0;
				for(j=0;j<n;j++)
				{
					if((i>>j)&1)
					{
						cnt++;
						sum1=sum1+a[j];
					}
					else 
						sum2=sum2+a[j];
				}
				ll mid=k/2;
				ll cnt2=k-mid;
				//printf("mid is %lld rest %lld sum1 %lld sum2 %lld\n",mid,cnt2,sum1,sum2 );
				if(mid!=0&&cnt2!=0)
				{
					int rem1=sum1/mid;
					int rem2=sum2/cnt2;
					if(rem2==rem1&&rem2==su)
						flag=1;
					rem1=sum1/cnt2;
					rem2=sum2/mid;
					if(rem2==rem1&&rem2==su)
						flag=1;
				}
				if(mid==0)
				{
					if(sum1+sum2==su)
						flag=1;
				}
				if(flag) {
					printf("yes\n");break;
				}
			}
			if(!flag) printf("no\n");
		}
	}
	return 0;
}