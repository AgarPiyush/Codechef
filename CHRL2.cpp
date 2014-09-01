#include<stdio.h>
#include<string.h>
int c[100010],h[100010],e[100010],l,top1=-1,top2=-1,top3=-1,i;
int main()
{
	char s[100010];
	scanf("%s",s);
	l=strlen(s);
	int count=0;
	for(i=0;i<l;i++)
	{
		if(s[i]=='C')
		c[++top1]++;
		else if(s[i]=='H'&&top1>=0&&top1>top2)
		h[++top2]++;
		else if(s[i]=='E'&&top2>=0&&top2>top3)
		e[++top3]++;
		else if(s[i]=='F'&&top3>=0)
		{
			count++;
			top1--;top2--;top3--;
		}
	}
	printf("%d\n",count);
	return 0;
}
