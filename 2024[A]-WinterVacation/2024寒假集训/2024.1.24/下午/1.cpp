#include<bits/stdc++.h>
using namespace std;
char a[1000010],b[1000010];
int len1,len2,i,j;
int P[1000010];//b�Լ��Ⱥ��Լ��� 
int ans[1000010];
void Pre(){
	int i,j;
	P[1]=0;j=0;//j=0���Լ���ƥ���ַ��� 
	for(i=1;i<len2;i++){//��ʼƥ���Լ� 
		while(j>0&&b[j+1]!=b[i+1])j=P[j];//jһֱ��С
		if(b[j+1]==b[i+1])j++;
		P[i+1]=j;//��i+1���ַ����Ѿ�ƥ������� 
	}
}
int main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	scanf("%s",a+1);scanf("%s",b+1);
	len1=strlen(a+1);len2=strlen(b+1);
	Pre();
	for(i=0;i<len1;i++){//i��0��ʼ����Pre()�����һ��㲻һ�� 
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
