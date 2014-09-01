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
#define inp(a) scanf("%lld",&a)
#define line(a) printf("%lld ",a);
#define next() printf("\n");
#define out(a) printf("%lld\n",a)
#define swap(a,b) {a=a+b;a=a-b;b=a-b;}
#define VI vector<int>
#define VLL vector<long long int>
#define PQI priority_queue<int>
#define PQLL priority_queue<long long int>
#define ll long long int
#define mod 1000000007
#define getcx getchar_unlocked
/*inline void fscan(ll *a )
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
ll i,j,l,n,m,k,a[25][100000],number[100000],temp[100000],temp2[100000],mark3[100000];
ll mark[100000],mark2[100000],posrow[100000],lastel[100000],size[100000],possize[100000],freq[100000];

void merge(long long int a[],long long int l,long long int mid,long long int u)
{
long long int ac=l,bc=mid+1,cc=l,i;
while(ac<=mid&&bc<=u)
{
if(a[ac]<a[bc])
{
temp[cc]=a[ac];
temp2[cc]=posrow[ac];
cc++;
ac++;
}
else
{
temp[cc]=a[bc];
temp2[cc]=posrow[bc];
bc++;
cc++;
}
}
while(ac<=mid)
{
temp[cc]=a[ac];
temp2[cc]=posrow[ac];
cc++;
ac++;
}
while(bc<=u)
{
temp[cc]=a[bc];
temp2[cc]=posrow[bc];
cc++;bc++;
}
for(i=l;i<cc;i++)
{
a[i]=temp[i];
posrow[i]=temp2[i];
}
}


void mergesort(long long int a[],long long int l,long long int u)
{
long long int mid=(l+u)/2;
if(l!=u)
{
mergesort(a,l,mid);
mergesort(a,mid+1,u);
merge(a,l,mid,u);
}
}

void merge2(long long int a[],long long int l,long long int mid,long long int u)
{
long long int ac=l,bc=mid+1,cc=l,i;
while(ac<=mid&&bc<=u)
{
if(a[ac]<a[bc])
{
temp[cc]=a[ac];
temp2[cc]=possize[ac];
cc++;
ac++;
}
else
{
temp[cc]=a[bc];
temp2[cc]=possize[bc];
bc++;
cc++;
}
}
while(ac<=mid)
{
temp[cc]=a[ac];
temp2[cc]=possize[ac];
cc++;
ac++;
}
while(bc<=u)
{
temp[cc]=a[bc];
temp2[cc]=possize[bc];
cc++;bc++;
}
for(i=l;i<cc;i++)
{
a[i]=temp[i];
possize[i]=temp2[i];
}
}


void mergesort2(long long int a[],long long int l,long long int u)
{
long long int mid=(l+u)/2;
if(l!=u)
{
mergesort2(a,l,mid);
mergesort2(a,mid+1,u);
merge2(a,l,mid,u);
}
}
int main()
{
	inp(n);inp(m);
	int flag1=0;
	ll p=m;
	for(i=1;i<=p;i++)
	{
		flag1=0;
		inp(a[i][0]);
		size[i]=a[i][0];
		possize[i]=i;
		for(j=1;j<=a[i][0];j++)
		{
			inp(a[i][j]);
			if(a[i][j]>n)
			{
				flag1=1;break;
			}
			if(j>1)
			if(a[i][j]==a[i][j-1])
			{
				flag1=1;break;
			}
		}
		if(flag1==1)
		{
			i--;
			p--;
		}
	}
		ll t;
		for(t=1;t<=p;t++)
		{	
		for(j=1;j<=a[t][0];j++)
		freq[a[t][j]]++;
		}
		

	
	m=p;
	if(p==0)
	printf("0\n");
	else
	{
	mergesort2(size,1,p);
/*	for(i=1;i<=m;i++)
	printf("%lld %lld\n\n",size[i],possize[i]);
	printf("done");*/
	
	ll count=0,w;
	for(w=1;w<=m;w++)
	{
		
		i=possize[w];
	//	printf("i is %lld\n",i);*/
		ll c=0;	
		if(!mark[a[i][0]])
		{
		printf("yes\n");
		mark[a[i][0]]=1;
		lastel[c]=a[i][a[i][0]];
		posrow[c++]=i;
		for(j=1;j<=m;j++)
		{
			if(j==i)
			continue;
			if(a[j][0]==a[i][0])
			{
				lastel[c]=a[j][a[j][0]];
				posrow[c++]=j;	
			}
		}
	/*	printf("before sorting");
		for(i=0;i<c;i++)
		printf("%lld %lld\n",posrow[i],lastel[i]);
		printf("\n");*/
		mergesort(lastel,0,c-1);
		/*printf("after sorting");
		for(i=0;i<c;i++)
		printf("%lld %lld\n",posrow[i],lastel[i]);
		printf("\n");
		printf("c is %lld\n",c);
		*/
		ll c1=0,sum1=0,sum=0;
		ll posrow2[100000];
		ll min=0,position=0;
		for(t=0;t<c;t++)
		{
			for(j=1;j<=a[posrow[t]][0];j++)
			min+=freq[a[posrow[t]][j]];
			position=posrow[t];
			for(j=t+1;j<c;j++)
			{
				if(lastel[t]==lastel[j])
				{
					mark3[posrow[j]]=1;
					for(k=1;k<=a[posrow[j]][0];k++)
					{
						sum1+=freq[a[posrow[j]][k]];
					}
					if(min>sum1)
					{
						min=sum1;
						position=posrow[j];
					}
				}
				else
				{
					t=j-1;
					posrow2[c1++]=position;
					break;
				}
			}
		}
		if(lastel[c-1]!=lastel[c-2])
		{
		posrow2[c1++]=position;
		}
		printf("posrow\n");
		for(i=0;i<c;i++)
		printf("%lld\n",posrow[i]);
		printf("\n");
		printf("posrow2\n");
		for(i=0;i<c1;i++)
		printf("%lld\n",posrow2[i]);
		printf("\n");
		
		for(j=0;j<c;j++)
		{
			//printf("j is %lld \n",j);
			ll pos=posrow[j];
			printf("order %lld\n",pos);
			ll flag=0;
			for(k=1;k<=a[pos][0];k++)
			{
				if(mark2[a[pos][k]])
				{
					flag=1;
					break;
				}
			}
			/*if(flag==1)
			{
				printf("mark el %lld\n",a[pos][k]);
			}*/
			if(flag==0)
			{
			//	printf("position is %lld\n",pos);
				count++;
				for(k=1;k<=a[pos][0];k++)
				{
					mark2[a[pos][k]]=1;
				}
			}
		}
		}
		}
		
	
	out(count);	
	}
	return 0;
}

