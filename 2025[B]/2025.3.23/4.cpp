#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,ans[100009],i,j,kk,l,r,vis[100009];
int prime[10009],cnt;//cnt�������ĸ�����prime����ȫ���������� 
int flag[100009];//0��������>0�������� 
signed main(){
	freopen("4.in","r",stdin);freopen("4.out","w",stdout);
	flag[1]=1;
	for(i=2;i<=100000;i++){
		if(flag[i]==0){
			prime[++cnt]=i;//��¼���� 
		}
		for(j=1;j<=cnt&&i*prime[j]<=100000;j++){
			flag[prime[j]*i]=prime[j];//һ����ɸ����(��С����) 
			//��Ȼ��i�϶���prime[j]����Ϊprime[j]����i֮ǰ�ó���
			if(i%prime[j]==0)break;
		}
	}
	cin>>T;
	while(T--){
		scanf("%lld",&n);ans[0]=0;
		for(i=1;i<=n;i++)vis[i]=0;
		if(n<=20){
			ans[1]=2;ans[2]=1;ans[3]=3;ans[4]=4;ans[5]=5;
			for(i=6;i<=n;i++)ans[i]=i;
		}
		else{
			for(i=n/2;i<=n;i++){
				if(flag[i]==0){
					kk=i;
					break;
				}
			}
			l=kk-1;r=kk;
			while(l>=1&&r<=n){
				ans[0]++;vis[l]=1;
				ans[ans[0]]=l;
				ans[0]++;vis[r]=1;
				ans[ans[0]]=r;
				l--;r++;
			}
			for(i=1;i<=n;i++){
				if(vis[i]==0){
					ans[++ans[0]]=i;
				}
			}
		}
		for(i=1;i<=n;i++){
			if(i==n)printf("%lld\n",ans[i]);
			else printf("%lld ",ans[i]);
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
