#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,i,k1[39],k2[39],a[200009],b[200009],ANS,ans1,ans2;
bool F1,F2;
void insert(int x,int y){
	int i;
	for(i=30;i>=0;i--){
		if(k1[i]&&k2[i]){
			
		}
		else if(k1[i]==0&&k2[i]){
			
		}
		else if(k1[i]&&k2[i]==0){
			
		}
		else{
			
		}
	}
}
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld",&n);
		memset(k1,0,sizeof(k1));memset(k2,0,sizeof(k2));
		for(i=1;i<=n;i++)scanf("%lld",&a[i]);
		for(i=1;i<=n;i++)scanf("%lld",&b[i]);
		for(i=1;i<=n;i++)insert(a[i],b[i]);
		ans1=ans2=0;F1=F2=0;
		for(i=30;i>=0;i--){
			if(F1==0&&F2==0){
				if((ans1&(1LL<<i))==0&&(ans2&(1LL<<i))==0){
					if(k1[i]>0&&k2[i]>0)continue;
					else if(k1[i]==0&&k2[i]>0)F1=1;
					else if(k1[i]>0&&k2[i]==0)F2=1;
					else continue;
				}
				else if((ans1&(1LL<<i))==0&&(ans2&(1LL<<i))>0){
					if(k1[i]==0)F1=1;//F1先比较小 
				}
				else if((ans1&(1LL<<i))>0&&(ans2&(1LL<<i))==0){
					if(k2[i]==0)F2=1;//F2先比较小 
				}
				else{
					continue;
				}
				ans1^=k1[i];ans2^=k2[i];
			}
			else if(F1==1){
				
			}
			else{
				
			}
		}
		ANS=min(ans1,ans2);
		printf("%lld\n",ANS);
	}
	return 0;
}
