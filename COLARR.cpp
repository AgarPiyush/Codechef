#include<iostream>
#include<cstdio>
#include<climits>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<set>
#include<cmath>
#include<queue>
using namespace std;
#define inp(a) scanf("%d",&a)
#define line(a) printf("%d ",a);
#define next() printf("\n");
#define out(a) printf("%d\n",a)
#define swap(a,b) {a=a+b;a=a-b;b=a-b;}
#define VI vector<int>
#define VLL vector<long long int>
#define PQI priority_queue<int>
#define PQLL priority_queue<long long int>
#define ll int
#define mod 1000000007
#define getcx getchar_unlocked
int temp[1010],temp2[1010],in[1010];
ll t,i,j,k,n,m,a[1010],o,c[1010][1010],p[1010][1010],net[1010][1010],given[1010],lar[1010],diff[1010];

void merge(int diff[], int l,int mid,int u)
{
int ac=l,bc=mid+1,cc=l;
while(ac<=mid&&bc<=u)
{
if(diff[ac]<diff[bc])
{
temp[cc]=diff[ac];
temp2[cc++]=in[ac++];
}
else 
{
temp2[cc]=in[bc];
temp[cc++]=diff[bc++];
}
}
while(ac<=mid)
{
temp[cc]=diff[ac];temp2[cc++]=in[ac++];
}
while(bc<=u)
{
temp[cc]=diff[bc];temp2[cc++]=in[bc++];
}
for(i=l;i<cc;i++)
{
diff[i]=temp[i];in[i]=temp2[i];
}
}

void mergesort(int diff[],int l,int u)
{
int mid=(l+u)/2;
if(l!=u)
{
mergesort(diff,l,mid);
mergesort(diff,mid+1,u);
merge(diff,l,mid,u);
}
}


/*
inline void fscan(int *a )
{
	int n=0; int ch = getcx(); int sign = 1;
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
int main()
{
	inp(t);
	ll pos,sum,max;
	while(t--)
	{
		inp(n);inp(m);inp(k);
		for(i=1;i<=n;i++) 
		inp(a[i]);
		for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
		inp(p[i][j]);
		pos=0;sum=0,max=0;
		for(i=1;i<=n;i++)
		{
			 max=0;
			for(j=1;j<=m;j++)
			{
				inp(c[i][j]);
				if(j!=a[i])
				net[i][j]=p[i][j]-c[i][j];
				else
				net[i][j]=p[i][j];
				if(net[i][j]>max||((net[i][j]==max)&&(j==a[i])))
				{
				 lar[i]=net[i][j];
				 max=net[i][j];
				 pos=j;
				}
			}
			if(pos==a[i])
			{
				sum+=net[i][pos];lar[i]=0;given[i]=0;
			}
			else
			given[i]=net[i][a[i]];
		}
		for(i=1;i<=n;i++){
		diff[i]=lar[i]-given[i];
		in[i]=i;
		}
		mergesort(diff,1,n);
		o=0;
		for(i=n;i>=0;i--)
		{
			if(o<k)
			{
				sum+=lar[in[i]];o++;
			}
			else sum+=given[in[i]];
		}
		out(sum);
	}
	return 0;
}

