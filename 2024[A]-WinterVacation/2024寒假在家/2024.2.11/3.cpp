#include<bits/stdc++.h>
using namespace std;
int T,n,i,x,ans,t,f[109],cnt,j;
int main(){
	freopen("3.in","r",stdin);freopen("3.out","w",stdout);
	cin>>T;
	for(int o=1;o<=T;o++){
		ans=0;cnt=0;
		scanf("%d%d",&n,&x);
		//Íâº¬
		t=n+x-2;
		for(i=1;i*i<=t;i++){
			if(t%i==0){
				if((t/i)%2==0&&t/i/2+1>=x){
					ans++;f[++cnt]=t/i;
				}
				if(i%2==0&&i/2+1>=x&&i*i!=t){
					ans++;f[++cnt]=i;
				}
			}
		}
		//ÄÚº¬ 
		t=n-x;
		for(i=1;i*i<=t;i++){
			if(t%i==0){
				if((t/i)%2==0&&t/i/2+1>=x){
					bool ff=0;
					for(j=1;j<=cnt;j++){
						if(t/i==f[j]){
							ff=1;
							break;
						}
					}
					if(ff==0)ans++;
				}
				if(i%2==0&&i/2+1>=x&&i*i!=t){
					bool ff=0;
					for(j=1;j<=cnt;j++){
						if(i==f[j]){
							ff=1;
							break;
						}
					}
					if(ff==0)ans++;
				}
			}
		}
		printf("%d\n",ans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
