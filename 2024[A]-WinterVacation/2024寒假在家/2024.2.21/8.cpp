#include<iostream>
#include<cstdio>
using namespace std;
int n,q,i,ans[2300008],anss,j,t,k;//������� 
bool flag[2300008];//0��������1�������� 
int gz[2300008];
int main(){
	freopen("8.in","r",stdin);freopen("8.out","w",stdout);
	cin>>n;t=n;
	flag[1]=1; 
	for(i=2;i<=2000009;i++){
		if(flag[i]==0){
			ans[++anss]=i;//��¼���� 
		}
		for(j=1;j<=anss&&i*ans[j]<=2000009;j++){
			flag[ans[j]*i]=1;//һ����ɸ���� 
			//��Ȼ��i�϶���ans[j]����Ϊans[j]����i֮ǰ�ó���
			if(i%ans[j]==0)break;
		}
	}
	while(n>0){
		for(i=1;i<=n;i++){
			if(flag[i+n]==0){
				int r=(i+n)/2;
				for(j=i,k=n;j<=r;j++,k--){
					gz[j]=k;
					gz[k]=j;
				}
				n=i-1;
			}
		}
	}
	n=t;
	for(i=1;i<=n;i++){
		if(i!=n)printf("%d ",gz[i]);
		else{
			printf("%d\n",gz[i]);
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
} 
