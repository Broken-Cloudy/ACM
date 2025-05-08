#include<bits/stdc++.h>
using namespace std;
char a[1000010],b[1000010];
int len1,len2,i,j;
int P[1000010];//b自己先和自己玩 
int ans[1000010];
void Pre(){
	int i,j;
	P[1]=0;j=0;//j=0是自己的匹配字符串 
	for(i=1;i<len2;i++){//开始匹配自己 
		while(j>0&&b[j+1]!=b[i+1])j=P[j];//j一直减小
		if(b[j+1]==b[i+1])j++;
		P[i+1]=j;//第i+1个字符的已经匹配的数量 
	}
}
int main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	scanf("%s",a+1);scanf("%s",b+1);
	len1=strlen(a+1);len2=strlen(b+1);
	Pre();
	for(i=0;i<len1;i++){//i从0开始，与Pre()里，面有一点点不一样 
		while(j>0&&a[i+1]!=b[j+1])j=P[j];
		if(a[i+1]==b[j+1])j++;
		if(j==len2){
			ans[++ans[0]]=i-len2+2;
			j=P[j];
		}
	}
	for(i=1;i<=ans[0];i++){
		printf("%d\n",ans[i]);
	}
	for(i=1;i<=len2;i++){
		if(i==len2)printf("%d\n",P[i]);
		else printf("%d ",P[i]);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
