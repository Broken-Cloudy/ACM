#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,m,t,i,j,x[200009],val,num,w[200009],ans;
bool f[200009];
int ss[200009];
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld%lld%lld",&n,&m,&t);
		for(i=1;i<=m;i++){
			scanf("%lld",&x[i]);
		}
		sort(x+1,x+1+m);
		val=t-n;
		if(val<0){
			printf("%lld\n",0LL);
		}
		else{
			for(i=0;i<=val;i++)f[i]=0;f[0]=1;
			for(i=0;i<=t;i++)ss[i]=0;
			for(i=1;i<m;i++)ss[x[i+1]-x[i]]=1;
			num=0;
			for(i=0;i<=t;i++){
				if(ss[i]==1){
					num++;
					w[num]=2*i;
				}
			}
			for(i=1;i<=num;i++){
				for(j=w[i];j<=val;j++){
					f[j]=(f[j]||f[j-w[i]]);
				}
			}
			for(i=val;i>=0;i--){
				if(f[i]){
					ans=i+n;
					break;
				}
			}
			printf("%lld\n",ans);
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
