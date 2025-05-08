#include<bits/stdc++.h>
using namespace std;
int n,T,i,ans,f[109];
int main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>T;
	memset(f,0x3f,sizeof(f));
	f[1]=1;f[3]=1;f[6]=1;f[10]=1;f[15]=1;
	for(i=2;i<=105;i++){
		if(i-1>=1)f[i]=min(f[i],f[i-1]+1);
		if(i-3>=1)f[i]=min(f[i],f[i-3]+1);
		if(i-6>=1)f[i]=min(f[i],f[i-6]+1);
		if(i-10>=1)f[i]=min(f[i],f[i-10]+1);
		if(i-15>=1)f[i]=min(f[i],f[i-15]+1);
	}
	for(int o=1;o<=T;o++){
		scanf("%d",&n);ans=0;
		if(n>=100){
			ans=n/15-2;
			n-=n/15*15;
			n+=30;
			ans+=f[n];
		}
		else{
			ans=f[n];
		}
		printf("%d\n",ans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
