#include<stdio.h>
#include<math.h>
char s[10000],ans[100000][30];
long long int a[10000],b[10000];
long long int per[]={0,2, 3, 7, 15, 21, 63, 127, 63, 73, 889, 1533, 3255, 7905, 11811};
long long int i,j,k,l,front,rear,t,m=1;
int main()
{
	scanf("%lld",&t);
	while(t--)
	{
		
		long long int flag=0;
		long long int max=0,n;		
		scanf("%lld %lld",&l,&n);
		scanf("%s",s);
		for(i=0;i<n;i++)
		{
			scanf("%lld",&b[i]);
			a[i]=b[i]%per[l];
			if(a[i]>max)
			max=a[i];
		}
		printf("Experiment #%lld:\n",m);
		m++;
	
		flag=0;
			if(l==1)
			{
					if(s[0]=='-')
					{
						for(i=0;i<n;i++)
						{
							if(b[i]%2==0)
							{
								printf("-\n");
							}
							else
							printf("+\n");
						}
					}
					else
					{
						for(i=0;i<n;i++)
						{
							if(b[i]%2==0)
							{
								printf("+\n");
							}
							else
							printf("-\n");
						}
					}
					flag=1;
			}
			if(flag==0)
			{
			front=0;
			rear=l-1;
			for(i=0;i<l;i++)
			ans[0][i]=s[i];
			for(i=1;i<=max;i++)
			{
			if(s[front]=='+')
			{
				front++;
				if(s[rear]=='+')
				s[rear]='-';
				else
				s[rear]='+';
				s[rear+1]='-';
				rear++;
			}
			else
			{
				front++;
				s[rear+1]='+';
				rear++;
			}
				long long int c=0;
				for(j=front;j<=rear;j++)
				{
					ans[i][c++]=s[j];
				}
		}
		for(i=0;i<n;i++)
		{
			for(j=0;j<l;j++)
			{
				printf("%c",ans[a[i]][j]);
			}
			printf("\n");
		}
		
	}
	}
	return 0;
}

