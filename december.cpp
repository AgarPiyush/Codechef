#include<stdio.h>
#include<string.h>
int main()
{
	int t,dist;
	char s[100000],d[1000],d1[1000];
	int counter[100][100];
	scanf("%d",&t);
	int e=0;
	char ww;
	while(t--)
	{
		int i,j;
		dist=0;
		scanf("%s",s);
		printf("%s\n",s);
		int l2=strlen(s);
		int y=0;
		if(e==0)
		scanf("%c",&ww);
		e++;
		gets(d1);
		int l1=strlen(d1);
		for(i=0;i<l1;i++)
		if(d1[i]>='A'&&d1[i]<='Z')
		d[i]=d1[i]+32;
		else
		d[i]=d1[i];
		for(i=0;i<l1;i++)
		printf("%c",d[i]);
		int dis=0;
		for(i=97;i<=123;i++)
		counter[i][1]=0;
		printf("\n");
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
				if(counter[i][1]<counter[j][1])
				{
					int temp=counter[i][1];
					counter[i][1]=counter[j][1];
					counter[j][1]=temp;
					temp=counter[i][0];
					counter[i][0]=counter[j][0];
					counter[j][0]=temp;
				}
				if(counter[i][1]==counter[j][1]&&counter[i][0]<counter[j][0])
				{
					int temp=counter[i][0];
					counter[i][0]=counter[j][0];
					counter[j][0]=temp;
				}
				}
			}
		}
		
		for(i=97;i<=122;i++)
		if(counter[i][1]>0)
		printf("%c %c %d\n",i,counter[i][0],counter[i][1]);
		
		char p[1000];
		j=0;int k=l2-1;
		for(i=97;i<=122;i++)
		if(counter[i][1]>0)
		{
			p[counter[i][0]]=s[k--];
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
