#include<stdio.h>
void mergesort(long long int a[],long long int,long long int);
void merge(long long int a[],long long int,long long int,long long int);
long long int temp[1000005];
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
void merge(long long int a[],long long int l,long long int mid,long long int u)
{
long long int ac=l,bc=mid+1,cc=l,i;
while(ac<=mid&&bc<=u)
{
if(a[ac]<a[bc])
temp[cc++]=a[ac++];
else 
temp[cc++]=a[bc++];
}
while(ac<=mid)
temp[cc++]=a[ac++];
while(bc<=u)
temp[cc++]=a[bc++];
for(i=l;i<cc;i++)
a[i]=temp[i];
}
long long int a[1000005]={0},b[1000005]={0};
int main()
{
	long long int t,i,j,k,l,m,n,e,f;
	scanf("%lld",&t);
	while(t--)
	{
		long long int sum=0;
		scanf("%lld %lld",&n,&m);
		for(i=1;i<=n;i++)
		scanf("%lld",&a[i]);
		mergesort(a,1,n);
		for(i=0;i<m;i++)
		{
			scanf("%lld %lld",&e,&f);
			for(j=e;j<=f;j++)
			b[j]++;
		}
		mergesort(b,1,n);
		for(i=1;i<=n;i++)
		{
			sum=sum+(b[i]*a[i]);
			b[i]=0;
			a[i]=0;
		}
		printf("%lld\n",sum);
	}
	return 0;
}

