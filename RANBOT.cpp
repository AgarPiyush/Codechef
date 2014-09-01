#include<stdio.h>
#include<string.h>

long long int m,n,t,i,j,k,l;
char s[10000];
	long long int x[1000000]={0},a[1000000]={0};
int main()
{
	
		scanf("%lld",&t);
		for(i=0;i<t;i++)
		{
			scanf("%s",s);
			scanf("%lld %lld",&m,&n);
			if(strcmp(s,"add")==0)
			{
				x[i]=m;
				a[i]=n;
			}
			else if(strcmp(s,"erase")==0)
			{
			for(j=0;j<i;j++)
			{
				if(x[j]==m&&a[j]==n)
				{
					x[j]=-1;
					a[j]=-1;
				}
			}
			}
			else if(strcmp(s,"get")==0)
			{
				long long int q,w,min=10000000000000,min2=10000000000000;
				for(j=0;j<i;j++)
				{
					if(x[j]>m)
					{
						q=x[j];
						if(q<=min)
						{
							min=q;
							w=a[j];
							if(w<min2)
							min2=w;
						}
					}
				}
				if(min==10000000000000&&min2==10000000000000)
				printf("-1\n");
				else
				printf("%lld %lld\n",min,min2);
			}	
			
		}
	return 0;
}
