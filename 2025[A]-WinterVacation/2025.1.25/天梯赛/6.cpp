#include<bits/stdc++.h>
using namespace std;
int L,N,a1,a2,a3,a4,i,dp[10009],cnt,p[5][5],ans,j,k,w;
int check(int l,int n){
	int i,j,kk;
	for(i=1;i<=n;i++){
		kk=0;
		for(j=1;j<=n;j++){
			kk+=p[j][i];
		}
		if(kk!=l){
			return 0;
		}
	}
	return 1;
}
signed main(){
	freopen("6.in","r",stdin);freopen("6.out","w",stdout);
	cin>>L>>N;
	if(N==2){
		for(i=0;i<=99;i++){
			a2=i/10;a1=i%10;
			if(a1+a2==L){
				dp[++cnt]=i;
			}
		}
		for(i=1;i<=cnt;i++){
			p[1][2]=dp[i]/10;p[1][1]=dp[i]%10;
			for(j=1;j<=cnt;j++){
				p[2][2]=dp[j]/10;p[2][1]=dp[j]%10;
				if(check(L,N))ans++;
			}
		}
		printf("%d\n",ans);
	}
	else if(N==3){
		for(i=0;i<=999;i++){
			a3=i/100;a2=i/10%10;a1=i%10;
			if(a1+a2+a3==L){
				dp[++cnt]=i;
			}
		}
		for(i=1;i<=cnt;i++){
			p[1][3]=dp[i]/100;p[1][2]=dp[i]/10%10;p[1][1]=dp[i]%10;
			for(j=1;j<=cnt;j++){
				p[2][3]=dp[j]/100;p[2][2]=dp[j]/10%10;p[2][1]=dp[j]%10;
				for(k=1;k<=cnt;k++){
					p[3][3]=dp[k]/100;p[3][2]=dp[k]/10%10;p[3][1]=dp[k]%10;
					if(check(L,N))ans++;
				}
			}
		}
		printf("%d\n",ans);
	}
	else if(N==4){
		for(i=0;i<=9999;i++){
			a4=i/1000;a3=i/100%10;a2=i/10%10;a1=i%10;
			if(a1+a2+a3+a4==L){
				dp[++cnt]=i;
			}
		}
		for(i=1;i<=cnt;i++){
			p[1][4]=dp[i]/1000;p[1][3]=dp[i]/100%10;p[1][2]=dp[i]/10%10;p[1][1]=dp[i]%10;
			for(j=1;j<=cnt;j++){
				p[2][4]=dp[j]/1000;p[2][3]=dp[j]/100%10;p[2][2]=dp[j]/10%10;p[2][1]=dp[j]%10;
				for(k=1;k<=cnt;k++){
					p[3][4]=dp[k]/1000;p[3][3]=dp[k]/100%10;p[3][2]=dp[k]/10%10;p[3][1]=dp[k]%10;
					for(w=1;w<=cnt;w++){
						p[4][4]=dp[w]/1000;p[4][3]=dp[w]/100%10;p[4][2]=dp[w]/10%10;p[4][1]=dp[w]%10;
						if(check(L,N))ans++;
					}
				}
			}
		}
		printf("%d\n",ans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
