#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,i,a[200009],maxx,mini,L,R,tt,zuo,you,ans;
int ttmini1,ttmaxx1,ttmini2,ttmaxx2,ttmini,ttmaxx;
map<int,int>M;
void work(int l,int r){
	int i;
	int ll=0,rr=0;
	maxx=mini=0;
	for(i=l;i<=r;i++){
		ll+=a[i];
		if(ll<=0)ll=0;
		maxx=max(ll,maxx);
	}
	for(i=l;i<=r;i++){
		rr+=a[i];
		if(rr>=0)rr=0;
		mini=min(rr,mini);
	}
}
signed main(){
	freopen("3.in","r",stdin);freopen("3.out","w",stdout);
    cin>>T;
    while(T--){
		scanf("%lld",&n);tt=0;M.clear();ans=0;
		for(i=1;i<=n;i++)scanf("%lld",&a[i]);
		for(i=1;i<=n;i++){
			if(a[i]!=1&&a[i]!=-1){
				tt=i;
				break;
			}
		}
		if(tt==0){
			work(1,n);
			for(i=mini;i<=maxx;i++){
				ans++;
			}
			printf("%lld\n",ans);
			for(i=mini;i<=maxx;i++){
				printf("%lld ",i);
			}
			printf("\n");
		}
		else{
			work(1,tt-1);L=mini;R=maxx;
			work(tt+1,n);L=min(mini,L);R=max(R,maxx);
			zuo=0;you=0;
			for(i=1;i<=tt-1;i++){
				if(a[i]==1){
					if(you<1){
						you=1;zuo++;
					}
					else{
						you++;zuo++;
					}
				}
				else{
					if(zuo>-1){
						zuo=-1;you--;
					}
					else{
						zuo--;you--;
					}
				}
			}
			zuo=min(0LL,zuo);you=max(0LL,you);
			ttmini1=zuo;ttmaxx1=you;
			zuo=0;you=0;
			for(i=n;i>=tt+1;i--){
				if(a[i]==1){
					if(you<1){
						you=1;zuo++;
					}
					else{
						you++;zuo++;
					}
				}
				else{
					if(zuo>-1){
						zuo=-1;you--;
					}
					else{
						zuo--;you--;
					}
				}
			}
			zuo=min(0LL,zuo);you=max(0LL,you);
			ttmini2=zuo;ttmaxx2=you;
			ttmini=a[tt]+ttmini1+ttmini2;
			ttmaxx=a[tt]+ttmaxx1+ttmaxx2;
			if(ttmini<L){
				for(i=ttmini;i<=ttmaxx;i++){
					ans++;M[i]=1;
				}
				for(i=L;i<=R;i++){
					if(M[i]==0)ans++;
				}
				printf("%lld\n",ans);M.clear();
				for(i=ttmini;i<=ttmaxx;i++){
					printf("%lld ",i);M[i]=1;
				}
				for(i=L;i<=R;i++){
					if(M[i]==0)printf("%lld ",i);
				}
			}
			else{
				for(i=L;i<=R;i++){
					ans++;M[i]=1;
				}
				for(i=ttmini;i<=ttmaxx;i++){
					if(M[i]==0)ans++;
				}
				printf("%lld\n",ans);M.clear();
				for(i=L;i<=R;i++){
					printf("%lld ",i);M[i]=1;
				}
				for(i=ttmini;i<=ttmaxx;i++){
					if(M[i]==0)printf("%lld ",i);
				}
			}
			printf("\n");
		}
	}
    fclose(stdin);fclose(stdout);
    return 0;
}
