#include<stdio.h>
#include<string.h>
char s[1000000],d[1000000],d1[1000000];
long long int counter[100][100];
char p[1000];
	
int  main()
{
	long long int t,dist;
	scanf("%lld",&t);
	long long e=0;
	char ww;
	while(t--)
	{
		long long i,j,l1,l2,y,dis;
		scanf("%s",s);
		 l2=strlen(s);
		y=0;
		scanf("%c",&ww);
		gets(d1);
		l1=strlen(d1);
		for(i=0;i<l1;i++)
		if(d1[i]>='A'&&d1[i]<='Z')
		d[i]=d1[i]+32;
		else
		d[i]=d1[i];
	
		 dis=0;
		for(i=97;i<=122;i++)
		counter[i][1]=0;
		for(i=0;i<l1;i++)
		{
			if(d[i]>='a'&&d[i]<='z')
			{
			if(counter[d[i]][1]==0)
			dis++;
			counter[d[i]][0]=d[i];
			counter[d[i]][1]++;
			}
		}
		for(i=97;i<=122;i++)
		{
			
			for(j=i+1;j<=122;j++)
			{
				if(counter[i][1]!=0&&counter[j][1]!=0)
				{
				if(counter[i][1]>counter[j][1])
				{
					long long temp=counter[i][1];
					counter[i][1]=counter[j][1];
					counter[j][1]=temp;
					temp=counter[i][0];
					counter[i][0]=counter[j][0];
					counter[j][0]=temp;
				}
				if(counter[i][1]==counter[j][1]&&counter[i][0]>counter[j][0])
				{
					long long temp=counter[i][0];
					counter[i][0]=counter[j][0];
					counter[j][0]=temp;
				}
				}
			}
		}
		
		for(i=97;i<=122;i++)
		if(counter[i][1]>0)
		printf("%c %c %d\n",i,counter[i][0],counter[i][1]);
		printf("\n");
		j=0;long long int k=l2-dis;
		for(i=97;i<=122;i++)
		if(counter[i][1]>0)
		{
			printf("%c %c\n",counter[i][0],s[k]);
			p[counter[i][0]]=s[k++];
		}
		for(i=0;i<l1;i++)
		{
			if(d1[i]>='a'&&d1[i]<='z')
			printf("%c",p[d[i]]);
			else if(d1[i]>='A'&&d1[i]<='Z')
			printf("%c",p[d[i]]-32);
			else
			printf("%c",d1[i]);
		}
		printf("\n");
		
			
	}
	return 0;
}
