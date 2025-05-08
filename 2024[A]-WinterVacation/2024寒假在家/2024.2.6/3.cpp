#include<bits/stdc++.h>
using namespace std;
int T,i,n,m,k,ans,r,num[1000009],ci1,ci2;
int cl[1000009],cnt;
int main(){
	freopen("3.in","r",stdin);freopen("3.out","w",stdout);
	cin>>T;
	for(int o=1;o<=T;o++){
		bool f=0;cnt=0;
		scanf("%d%d%d",&n,&m,&k);
		ci1=k/2;ci2=k/2;
		for(i=1;i<=n;i++){
			scanf("%d",&r);
			cl[++cnt]=r;
			num[r]=1;
		}
		for(i=1;i<=m;i++){
			scanf("%d",&r);
			cl[++cnt]=r;
			if(num[r]==1||num[r]==3)num[r]=3;
			else num[r]=2;
		}
		for(i=1;i<=k;i++){
			if(num[i]==1){
				ci1--;
			}
			if(num[i]==2){
				ci2--;
			}
			if(num[i]==0||ci1<0||ci2<0){
				printf("NO\n");
				f=1;//no
				break;
			}
		}
		for(i=1;i<=cnt;i++){
			num[cl[i]]=0;
		}
		if(f==0)printf("YES\n");
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
