#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,i,j,SG[10000009],ans,x,NUM;
int prime[10000009],cnt;//cnt�������ĸ�����prime����ȫ���������� 
int flag[10000009];//0��������>0�������� 
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	flag[1]=1;
	for(i=2;i<=10000000;i++){
		if(flag[i]==0){
			prime[++cnt]=i;//��¼���� 
		}
		for(j=1;j<=cnt&&i*prime[j]<=10000000;j++){
			flag[prime[j]*i]=prime[j];//һ����ɸ����(��С����) 
			//��Ȼ��i�϶���prime[j]����Ϊprime[j]����i֮ǰ�ó���
			if(i%prime[j]==0)break;
		}
	}
	SG[0]=0;SG[1]=1;NUM=1;
	for(i=2;i<=10000000;i++){
		if(i%2==0)SG[i]=0;
		else{
			if(flag[i]==0){//������ 
				SG[i]=++NUM;
			}
			else{//�������� 
				SG[i]=SG[flag[i]];
			}
		}
	}
	cin>>T;
	while(T--){
		scanf("%lld",&n);ans=0;
		for(i=1;i<=n;i++){
			scanf("%lld",&x);
			ans^=SG[x];
		}
		if(ans==0)printf("Bob\n");
		else printf("Alice\n");
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
