#include<cstdio>
#include<iostream>
#include<ctime>
#include<algorithm>
using namespace std;
bool OK[255][255];
char s[35][255];
int len[35];
int n,m;
int opt[255];
string tmp[35];
char flag[255][255][35][25];
bool cmp(const string a,const string b)
{
return a.size()<b.size();
}
bool dfs(int l,int r,int a,int b)
{
if (flag[l][r][a][b]) return flag[l][r][a][b]==1?1:0;
if (b==len[a] && l>r) {flag[l][r][a][b]=1;return 1;}
if (l>r) {flag[l][r][a][b]=2;return 0;}
if (b==len[a]) {flag[l][r][a][b]=2;return 0;}
if (r-l+1<len[a]-b) {flag[l][r][a][b]=2;return 0;}
if (s[0][l]==s[a][b+1])
if (dfs(l+1,r,a,b+1)) {flag[l][r][a][b]=1;return 1;}
for (int i=l;i<r;i++)
if (OK[l][i])
if (dfs(i+1,r,a,b)) {flag[l][r][a][b]=1;return 1;}
flag[l][r][a][b]=2;return 0;
}
int main()
{
//freopen("input.txt","r",stdin);
cin >> tmp[0];len[0]=n=tmp[0].size();
for (int i=0;i<n;i++) s[0][i+1]=tmp[0][i];
scanf("%d",&m);
for (int i=1;i<=m;i++) cin >> tmp[i];
sort(tmp+1,tmp+1+m,cmp);
for (int i=1;i<=m;i++)
{
len[i]=tmp[i].size();
for (int j=0;j<len[i];j++) s[i][j+1]=tmp[i][j];
}
for (int i=1;i<=n;i++)
for (int j=1;j<=m;j++)
if (i+len[j]-1<=n)
{
bool f=1;
for (int k=1;k<=len[j];k++) f&=s[0][i+k-1]==s[j][k];
OK[i][i+len[j]-1]|=f;
}
int sign=0;
for (int k=2;k<=n;k++)
for (int i=1,j=k;j<=n;i++,j++)
if (!OK[i][j])
{
for (int a=1;!OK[i][j] && a<=m;a++)
if (k>=len[a] && s[0][j]==s[a][len[a]])
OK[i][j]|=dfs(i,j,a,0);
}
for (int i=1;i<=n;i++) opt[i]=n;
for (int i=0;i<n;i++)
{
if (opt[i]+1<opt[i+1]) opt[i+1]=opt[i]+1;
for (int j=i+1;j<=n;j++)
if (OK[i+1][j] && opt[j]>opt[i])
opt[j]=opt[i];
}
printf("%d\n",opt[n]);
// printf("%0.9lf\n",(double)clock()/CLOCKS_PER_SEC);
// system("pause");
}
