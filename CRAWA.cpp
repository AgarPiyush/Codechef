//Author: Piyush Agarwal, MNNIT Allahabad
#include<bits/stdc++.h>
using namespace std;
#define inp1(a) scanf("%lld",&a)
#define inp2(a,b) scanf("%lld %lld",&a,&b)
#define line(a) printf("%lld ",a);
#define next() printf("\n");
#define out(a) printf("%lld\n",a)
#define ll long long int
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define getcx getchar_unlocked

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
}
*/
ll b[100][100];
ll xc=5,yc=5;
void resur(char d,ll c,ll x,ll y)
{
	if(x<0||y<0||y>2*xc||x>2*yc)
		return;
	if(d=='e')
	{
		for(int i=y;i<=c+y;i++)
		{
	//		printf("east %lld %lld\n",x,i);
			b[x][i]=1;	
		}
		resur('n',c+1,x,y+c);
	}
	if(d=='n')
	{
		for(int j=x;j>=x-c;j--)
		{
	//			printf("north %lld %lld\n",j,y);
		
			
			if(j>=0)
			b[j][y]=1;
		}
		resur('w',c+1,x-c,y);
	}
	if(d=='w')
	{
		for(int i=y;i>=y-c;i--)
		{
	//			printf("west %lld %lld\n",x,i);
		
			if(i>=0)
			b[x][i]=1;
		}
		resur('s',c+1,x,y-c);
	}
	else if(d=='s')
	{
		for(int j=x;j<=x+c;j++)
		{
	//		printf("south %lld %lld\n",j,y);
			b[j][y]=1;
		}
		resur('e',c+1,x+c,y);
	}
}
ll i,j,k,l,m,n,t,a[1000000];
int main()
{
	xc=5;yc=5;
	resur('e',1,xc,yc);
	for(i=0;i<=2*xc;i++)
	{
		printf("%lld->",i-xc);
		for(j=0;j<=2*yc;j++)
		{
			if(b[i][j]==1)
				printf("%lld ",j-yc);
		//	printf("%lld  ",b[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	for(i=0;i<=2*xc;i++)
	{
		for(j=0;j<=2*yc;j++)
		{
			printf("%lld  ",b[i][j]);
		}
		printf("\n");
	}
	return 0;
}

