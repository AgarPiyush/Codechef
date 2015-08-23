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
ll r,c,t,i,j,k,l,m,n,a[105][105];
vector<pair< pair<ll,ll>,pair<ll,ll> > >v; 
void hori()
{
	for(i=0;i<r;i++)
    {
    	int flag=0;
    	for(j=0;j<c;j++)
    	{
    		if(a[i][j]==0)
    		{
    			flag=1;
    			break;
    		}
    	}
    	if(flag)
    	{
    		for(k=c-1;k>=0;k--)
    		{
    			if(a[i][k]==0)
    			{
    				break;
    			}
    		}
    		int flag2=0;
    		for (l=j;l<=k;l++)
    		{
    			if(a[i][l])
    			{
    					flag2=1;break;
    			}
    		}
    		if(flag2==0)
    		{
    			v.push_back(mp(mp(i+1,j+1),mp(0,0)));
    			for(l=j;l<=k;l++)
    				a[i][l]=1;		
    		}
    	}
    }
}
void ver()
{
	int flag=0;
	for(j=0;j<c;j++)
	{
		flag=0;
		for(i=0;i<r;i++)
		{
			if(a[i][j]==0)
			{
				flag=1;break;
			}		
		}
		if(flag)
		{
			for(k=r-1;k>=0;k--)
			{
				if(a[k][j]==0)
				{
					break;
				}
			}
			int flag2=0;
			for(l=i;l<=k;l++)
			{
				if(a[l][j])
				{
					flag2=1;break;
				}			
			}
			if(!flag2)
			{
				v.push_back(mp(mp(i+1,j+1),mp(1,0)));
    			for(l=i;l<=k;l++)
					a[l][j]=1;
			}
		}
	}
}
int main()
{
	ll i,j;
    inp2(r,c);
    inp1(m);
    for (i=0;i<m;++i)
    {
    	inp2(j,k);
    	a[j-1][k-1]=1;
    }
   /* for(i=0;i<r;i++)
    {
    	for(j=0;j<c;j++)
    		printf("%lld",a[i][j]);
    	printf("\n");
    }*/
   // printf("done\n");
    hori();
    ver();
    for(i=0;i<r;i++)
    {
    	for(j=0;j<c;j++)
    	{
    		if(!a[i][j])
   			{
   				int count1=0;
   				int count2=0;
   				for(k=j;k<c;k++)
   				{
   					if(!a[i][k])
   						count1++;
   					else
   						break;
   				}
   				ll q;
   				for(q=i;q<r;q++)
   				{
   					if(!a[q][j])
   						count2++;
   					else
   						break;
   				}
   				//printf("i %lld j %lld %d %d\n",i,j,count1,count2);
   				if(count1>count2)
   				{
  // 					printf("i %lld j %lld %d %d\n",i,j,count1,count2);
   				
   					for(l=j;l<k;l++)
   						a[i][l]=1;
   					v.pb(mp(mp(i+1,j+1),mp(0,0)));
   				}
   				else
   				{
   					for(l=i;l<q;l++)
   						a[l][j]=1;
   					v.pb(mp(mp(i+1,j+1),mp(1,0)));	
   				}
   			} 		
    	}
    }
   cout  << v.size() << "\n";
   for(i=0;i<v.size();i++)
   {
   	cout << v[i].first.first << " " << v[i].first.second << " " << v[i].second.first <<"\n";
   }
  return 0;
}