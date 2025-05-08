#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,i,j,a[100009],b[100009],vis[2400009],zhi,check[2400009];
int anss,ans[2400009],flag[2400009];
bool ff;
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>T;
	check[1]=-1;check[0]=1;
	for(i=2;i<=2400000;i++){
		if(flag[i]==0){//质数 
			ans[++anss]=i;//记录下来 
		}
		for(j=1;j<=anss&&i*ans[j]<=2400000;j++){
			flag[ans[j]*i]=1;//一下子筛到底
			check[ans[j]*i]=1;
			//当然，i肯定比ans[j]大，因为ans[j]是在i之前得出的
			if(i%ans[j]==0)break;
		}
	}
	while(T--){
		scanf("%lld",&n);ff=0;zhi=0;
		for(i=1;i<=n;i++){
			scanf("%lld",&a[i]);
			vis[a[i]]=1;
		}
		for(i=1;i<=n;i++){
			if(flag[a[i]]==0){
				if(zhi>0&&a[i]!=zhi){
					ff=1;
					break;
				}
				else zhi=a[i];
			}
		}
		if(ff==1){
			printf("-1\n");
			continue;
		}
		if(zhi==0){
			printf("2\n");
			continue;
		}
		else{
			for(i=1;i<=n;i++){
				if(a[i]<zhi){
					ff=1;
					break;
				}
				if(a[i]>zhi&&a[i]<zhi*2){
					ff=1;
					break;
				}
				if(a[i]==zhi||a[i]==2*zhi){
					continue;
				}
				if(a[i]>=zhi*2&&a[i]<=zhi*2+4){
					if(a[i]==zhi*2+1){
						ff=1;
						break;
					}
					if(zhi!=3&&a[i]==zhi*2+3){
						ff=1;
						break;
					}
					if((zhi*2+2)%3!=0&&a[i]==(zhi*2+5)){
						ff=1;
						break;
					}
					continue;
				}
				if(zhi>=180000){
					if((zhi*2)%3==0){//6
						if(check[a[i]-(2*zhi)+6]<1){
							ff=1;
							break;
						}
						else continue;
					}
					else if((zhi*2+2)%3==0){//4
						if(check[a[i]-(2*zhi+2)+6]<1){
							ff=1;
							break;
						}
						else continue;
					}
					else if((zhi*2+4)%3==0){//2
						if(check[a[i]-(2*zhi+4)+6]<1){
							ff=1;
							break;
						}
						else continue;
					}
				}
			}
			if(ff==1)printf("-1\n");
			else printf("%lld\n",zhi);
		}
		for(i=1;i<=n;i++){
			vis[a[i]]=0;
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
