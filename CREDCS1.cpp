#include<string.h>
#include<stdio.h>
int a[10]={4,9,8,7,6,5,3,2,1,0},b[10]={5,0,1,2,3,4,6,7,8,9};
long long int i,j,k,l,m,n,t;
char s[1000000];
int c[1000000],d[1000000];
int main()
{
	scanf("%lld",&t);
	while(t--)
	{
		long long int f[50]={0};
		scanf("%s",s);
		k=0;
		l=strlen(s);
		for(i=0;i<l;i++)
		{
			if(s[i]>='a'&&s[i]<='z')
			{
				k++;
				break;
			}
		}
		if(k==0)
		{
			printf("%s",s);
			printf("\n");
		}
		else
		{
			m=0;
			for(j=0;j<l;j++)
			{
				if(s[j]>='a'&&s[j]<='z')
				{
					if(f[s[j]-97]==0)
					{
					c[j]=a[m];
					f[s[j]-97]++;
					d[j]=b[m];
					for(k=j+1;k<l;k++)
					{
						if(s[k]==s[j])
						{
							if(c[k]==0&&d[k]==0)
							{
							c[k]=a[m];
							d[k]=b[m];
							f[s[k]-97]++;
							}
						}
					}
					m++;
					}
				}
				else
				{
					c[j]=s[j]-48;
					d[j]=s[j]-48;
				}
			}
		
		for(i=0;i<l;i++)
		{
		printf("%lld",c[i]);
		c[i]=0;
		f[s[i]-97]=0;
		}
		printf(" ");
		for(i=0;i<l;i++)
		{
		printf("%lld",d[i]);
		d[i]=0;
		}
		printf("\n");
		}
	}
}
