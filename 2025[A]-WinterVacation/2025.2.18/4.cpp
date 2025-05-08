#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,i,vis[200009],l,r,kk1[328],kk2[328],ANS,kk[328],anss;
char c[200009];
string s;
signed main(){
	freopen("4.in","r",stdin);freopen("4.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>s;n=s.length();
		for(i=0;i<n;i++)c[i+1]=s[i];
		for(i=0;i<=28;i++){
			kk1[(i+'a')]=kk2[(i+'a')]=0;
		}
		for(i=1;i<=n;i++)vis[i]=0;
		for(i=1;i<=n/2;i++){
			if(c[i]==c[n-i+1]){
				vis[i]=1;
			}
		}
		l=n/2+1;r=0;
		for(i=1;i<=n/2;i++){
			if(vis[i]==0){
				if(l==(n/2+1))l=i;
				r=max(r,i);
			}
		}
		if(l==(n/2+1)){
			printf("0\n");
			continue;
		}
		for(i=l;i<=r;i++){
			kk1[c[i]]++;
			kk2[c[n-i+1]]++;
		}
		ANS=min((r-l+1),(n/2-l+1)*2-1);
		for(i=0;i<=28;i++){
			if(kk1[(i+'a')]!=kk2[(i+'a')]){
				ANS=max(ANS,(n/2-l+1)*2);
				break;
			}
		}
		for(i=0;i<=28;i++)kk[(i+'a')]=0;
		for(i=l;i<=n-l+1;i++){
			kk[c[i]]++;
		}
		anss=(n/2-l+1)*2;
		for(i=l;i<=n/2;i++){
			if(kk[c[i]]>=2){
				kk[c[i]]-=2;
				anss--;
			}
			else break;
		}
		ANS=min(ANS,anss);
		for(i=0;i<=28;i++)kk[(i+'a')]=0;
		for(i=l;i<=n-l+1;i++){
			kk[c[i]]++;
		}
		anss=(n/2-l+1)*2;
		for(i=n-l+1;i>=n/2+1;i--){
			if(kk[c[i]]>=2){
				kk[c[i]]-=2;
				anss--;
			}
			else break;
		}
		ANS=min(ANS,anss);
		printf("%lld\n",ANS);
	}
	fclose(stdin);fclose(stdout);
}
