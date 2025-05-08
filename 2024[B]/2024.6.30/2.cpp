#include<bits/stdc++.h>
#define int long long
using namespace std;
map<int,int>m;
int ans,k,l[100009],cnt1,r[100009],cnt2,n,i,kk,anss;
char p;
signed main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++){
		scanf("%lld",&k);
		getchar();p=getchar();
		if(p=='R'){
			r[++cnt2]=k;
		}
		else{
			l[++cnt1]=k;
		}
	}
	for(i=1;i<=cnt2;i++){
		if(i!=1){
			m[ans]=1;
			kk++;
		}
		anss+=r[i];
		ans+=(r[i]-1);
	}
	if(cnt1!=0){
		m[ans]=1;
		kk++;
	}
	for(i=1;i<=cnt1;i++){
		anss-=l[i];
		ans-=(l[i]-1);
		if(m[ans]!=1){
			kk++;
		}
	}
	cout<<max(anss,-anss)-kk<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
