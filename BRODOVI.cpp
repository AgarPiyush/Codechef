#include<stdio.h>
typedef long long int ll;
ll t,i,j,k,l,n,a[6000][4],mark[6000],co[6000],count=0;
int main()
{
	count=0;
	scanf("%lld",&n);
	scanf("%lld",&l);
	for(i=0;i<n-1;i++)
	{
	scanf("%lld",&a[i][0]);
	a[i][0]--;
	mark[i]=0;
	a[i][1]=a[i][2]=0;
	}
	for(i=0;i<n-1;i++)
	{
		ll m=a[i][0],mul=2,c=1,pos=0;
		for(j=i+1;j<n-1;j++)
		{
			if(a[j][0]>m*mul)
			{
			break;
			}
			if(m*mul==a[j][0])
			{
				c++;
				co[pos++]=j;
				mul++;
				mark[j]=1;
			}
		
		}
//		for(j=0;j<pos;j++) printf("%lld %lld\n",a[i+1][0],co[j]);
//		printf("\n");
		if(mark[i]==0)
		{
			count++;
			mark[i]=1;
			a[i][1]=c;
			a[i][2]=count;
			for(j=0;j<pos;j++)
			if(a[co[j]][1]<=c)
			{
			a[co[j]][1]=c;
			a[co[j]][2]=count;
		
			}
			else
			break;
		//	for(j=0;j<n-1;j++)
			//printf("%lld %lld\n",a[j][0],a[j][1]);
		//	printf("\n");
	
		}
		else
		{
			if(c>=a[i][1])
			{
			count++;	
			a[i][1]=c;
			a[i][2]=count;
			for(j=0;j<pos;j++)
			if(a[co[j]][1]<=c)
			{
			a[co[j]][1]=c;
			a[co[j]][2]=count;
			}
			else
			break;
			//for(j=0;j<n-1;j++)
		//	printf("%lld %lld\n",a[j][0],a[j][1]);
		//	printf("\n");
			}
		}
	}
	for(i=0;i<n;i++)
	printf("%lld %lld %lld\n",a[i][0],a[i][1],a[i][2]);
	printf("%d\n",count);
	
	return 0;
	
}
