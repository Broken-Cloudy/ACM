#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,i,j,n,k,vis[240009],a[240009],num;
int prime[3000009],cnt,used[3000009];//cnt�������ĸ�����prime����ȫ���������� 
int flag[3000009];//0��������>0�������� 
signed main(){
	freopen("4.in","r",stdin);freopen("4.out","w",stdout);
	for(i=2;i<=3000000;i++){
		if(flag[i]==0){
			prime[++cnt]=i;//��¼���� 
			used[i]=cnt;
		}
		for(j=1;j<=cnt&&i*prime[j]<=3000000;j++){
			flag[prime[j]*i]=prime[j];//һ����ɸ���� 
			//��Ȼ��i�϶���prime[j]����Ϊprime[j]����i֮ǰ�ó���
			if(i%prime[j]==0)break;
		}
	}
	cin>>T;
	while(T--){
		scanf("%lld",&n);num=0;
		for(i=1;i<=n;i++){
			scanf("%lld",&k);
			if(k<=3000000)a[++num]=k;
		}
		for(i=1;i<=num;i++){
			if(flag[a[i]]==0){
				vis[used[a[i]]]=1;
			}
		}
		for(i=1;i<=200001;i++){
			if(vis[i]==0){
				printf("%lld\n",prime[i]);
				break;
			}
		}
		for(i=1;i<=num;i++){
			if(flag[a[i]]==0){
				vis[used[a[i]]]=0;
			}
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
