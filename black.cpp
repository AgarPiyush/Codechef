    #include<stdio.h>
    #include<string.h>
    int main(){
    int t;
    scanf("%d",&t);
    while(t--){
    char s1[2];
    char s2[2];
    scanf("%s",s1);
    scanf("%s",s2);
    if(strlen(s1)==1 && strlen(s2)==1){
    char c1=s1[0];
    char c2=s2[0];
    int v1,v2;
    if(((c1<=57 && c1>=50)||(c1=='J' || c1=='K' || c1=='Q' || c1=='A'))&&((c2<=57 && c2>=50)||(c2=='J' || c2=='K' || c2=='Q' || c2=='A'))){
    if(c1=='J' || c1=='K' || c1=='Q') v1=10;
    else v1=c1-48;
    if(c2=='J' || c2=='K' || c2=='Q') v2=10;
    else v2=c2-48;
    if(v1+v2<=11 ||( c1=='A' && c2!='A') ||( c2=='A' && c1!='A')) printf("HIT\n");
    else printf("STAND\n");
    }
    else{printf("INVALID\n");}
    }
    else{printf("INVALID\n");}
    }
    return 0;
    }

