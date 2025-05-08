#include<bits/stdc++.h>
using namespace std;
int T,i,a[200009],n,cnt,f[200009],num,zhan[200009],k,ans,j,ss[200009];
int main(){
	freopen("6.in","r",stdin);freopen("6.out","w",stdout);
	cin>>T;
	for(int o=1;o<=T;o++){
		scanf("%d",&n);ans=0;
		for(i=1;i<=n;i++){
			scanf("%d",&a[i]);
			if(f[a[i]]==0){
				cnt++;
				f[a[i]]++;
			}
			else{
				f[a[i]]++;
			}
		}
		for(i=n;i>=1;i--){
			if(ss[a[i]]==0){//没有遇到过 
				zhan[++k]=a[i];
				ss[a[i]]++;
				num++;
			}
			else{
				ss[a[i]]++;
			}
			if(num==cnt){
				for(j=1;j<=k;j++){
					f[zhan[j]]-=ss[zhan[j]];
					if(f[zhan[j]]==0){
						cnt--;
					}
					ss[zhan[j]]=0;
					zhan[j]=0;
				}
				k=0;ans++;num=0;
			}
		}
		printf("%d\n",ans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
