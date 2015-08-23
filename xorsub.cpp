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
ll t,i,j,k,l,m,n,a[1005][100],b[10000],rem[100005];
bool cmp(int a,int b)
{
	return a>b;
}
void swap(ll a,ll b)
{
	ll temp=a;a=b;b=temp;
}
int main()
{
	inp1(t);
	while(t--)
	{
		inp1(n);
		ll y;
		inp1(y);
		for(i=0;i<n;i++) inp1(b[i]);
		sort(b,b+n,cmp);
//		printf("\n");
		ll cp=b[0],d=0;
		while(cp>0)
		{
			rem[d++]=cp%2;
			cp=cp/2;
		}
		k=0;
//		printf("rem is %lld\n",d);
		for(j=d-1;j>=0;j--)
			a[0][j]=rem[k++];
		
		for(i=1;i<n;i++)
		{
			ll cp=b[i],d1=0;
			while(cp>0)
			{
				rem[d1++]=cp%2;
				cp=cp/2;
			}
			int k=0;
			for(j=d-1;j>=d-d1;j--)
				a[i][j]=rem[k++];
		}
		/*for(i=0;i<n;i++)
		{
			for(j=0;j<d;j++)
					printf("%lld ",a[i][j]);
			printf("\n");
		}
		printf("\n");
		*/i=0;j=0;
		while(i<n&&j<d)
		{
			if(a[i][j]==1)
			{
		//		printf("when 1 at i %lld j %lld\n",i,j);
				for(k=i+1;k<n;k++)
					if(a[k][j]==1)
					{
					//	printf("yes \n\n");
						for(int p=j;p<d;p++)
								a[k][p]=a[k][p]^a[i][p];
					}
				i++;j++;
			}
			else
			{
		//		printf("when 0 at i %lld j %lld\n",i,j);
				int flag=0;
				for(k=i+1;k<n;k++)
			 	{
			 		if(a[k][j]==1)
					{
						flag=1;
						for(int p=j;p<d;p++)
						{
							int temp=a[i][p];
							a[i][p]=a[k][p];
							a[k][p]=temp;
						}
						break;
					}
				}
				if(flag==0) j++;
			}

		}	
		/*for(i=0;i<n;i++)
		{
			for(j=0;j<d;j++)
					printf("%lld ",a[i][j]);
			printf("\n");
		}*/
		ll ans=y;
		for(i=0;i<n;i++)
			{	
				ll val=0,q=1;
				for(j=d-1;j>=0;j--)
				{
					val=val+a[i][j]*q;
					q=q*2;
					a[i][j]=0;
				}
//				printf("%lld %lld %lld\n",ans,val,ans^val );
				ans=max(ans,ans^val);
			}
			printf("%lld\n",ans);
	}
   return 0;

}