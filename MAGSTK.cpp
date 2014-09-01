#include<stdio.h>
long long int x[100000],a[100000];
void mergesort(long long int a[],long long int,long long int);
void merge(long long int a[],long long int,long long int,long long int);
long long int temp[100000],temp2[100000];
void mergesort(long long int x[],long long int l,long long int u)
{
long long int mid=(l+u)/2;
if(l!=u)
{
mergesort(x,l,mid);
mergesort(x,mid+1,u);
merge(x,l,mid,u);
}
}
void merge(long long int x[],long long int l,long long int mid,long long int u)
{
long long int ac=l,bc=mid+1,cc=l,i;
while(ac<=mid&&bc<=u)
{
if(x[ac]<x[bc])
{
temp[cc]=x[ac];
temp2[cc]=a[ac];
cc++;
ac++;
}
else
{
temp[cc]=x[bc];
temp2[cc]=a[bc];
bc++;
cc++;
}
}
while(ac<=mid)
{
temp[cc]=x[ac];
temp2[cc]=a[ac];
cc++;
ac++;
}
while(bc<=u)
{
temp[cc]=x[bc];
temp2[cc]=a[bc];
cc++;bc++;
}
for(i=l;i<cc;i++)
{
x[i]=temp[i];
a[i]=temp2[i];
}
}
long long int t,n,i,j,k,l;
long long int f[100000]={0},ff[100000];
int main()
{
scanf("%lld",&t);
while(t--)
{
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&x[i]);
		ff[i]=x[i];
		scanf("%lld",&a[i]);
	}
	mergesort(x,1,n);
	
	long long int range,range1,range2,i,j,k,l,c=1;
	for(j=1;j<=n;j++)
	{
		c=1;
		k=j;
		range=a[j]-1;
		for(i=j+1;i<=n;i++)
		{
			if(range>=(x[i]-x[i-1]))
			{
			c++;
			}
			else 
			break;
			range1=a[i]-1;
			if((range-(x[i]-x[k])<range1))
			{
				range=range1;
				k=i;
			}
			
		}
		f[x[j]]=c;
	}
	for(i=1;i<=n;i++)
	{
		printf("%lld ",f[ff[i]]);
		
		f[ff[i]]=0;
	}
	printf("\n");
}
return 0;	
}
