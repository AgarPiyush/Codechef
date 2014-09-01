#include<stdio.h>
long long int a[10000000],b[10000000];
		
int main()
{
	long long int n,t,x,y,i,j,k;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		long long int f;
		long long int j=0;
		long long c=1,r=1,max=0;
		for(f=0;f<n;f++)
		{
		scanf("%lld %lld",&x,&y);
		
		if(x<0)
		x=100000-x;
		if(y<0)
		y=100000-y;
		if(x>=y&&x>max)
		{
			max=x;
		}
		else if(y>=x&&y>max)
		max=y;
		if(a[x]>0&&b[y]==0)
		c++;
		if(a[x]==0&&b[y]>0)
		r++;
		if(a[x]==0&&b[y]==0)
		{
				r++;
				c++;
		}
			a[x]++;
			b[y]++;
		}
	//	printf("%lld\n",max);
		for(i=0;i<=max;i++)
		{
			a[i]=0;
			b[i]=0;
		}
		printf("%lld\n",r*c);
	}
	
	return 0;
}
