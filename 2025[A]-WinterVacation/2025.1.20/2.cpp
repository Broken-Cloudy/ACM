#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,i,n,ans,a[200009],b[200009],kk,cha;
int F1,F2;
map<int,int>M;
signed main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld",&n);M.clear();kk=0;
		for(i=1;i<=n;i++)scanf("%lld",&a[i]),M[a[i]]++;
		for(i=1;i<=n;i++){
			if(M[a[i]]>=2){
				if(a[i]>kk){
					M[kk]+=2;
					kk=a[i];
					M[kk]-=2;
				}
			}
		}
		if(kk==0){
			printf("-1\n");
			continue;
		}
		b[0]=0;
		for(i=1;i<=n;i++){
			if(M[a[i]]>0){
				M[a[i]]--;
				b[++b[0]]=a[i];
			}
		}
		F1=F2=0;
		sort(b+1,b+1+b[0]);
		for(i=1;i<b[0];i++){
			if(b[i+1]<b[i]+2*kk){
				F1=b[i];F2=b[i+1];
				break;
			}
		}
		if(F1>0&&F2>0){
			printf("%lld %lld %lld %lld\n",kk,kk,F1,F2);
		}
		else printf("-1\n");
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
