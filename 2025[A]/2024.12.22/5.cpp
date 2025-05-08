#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,T;
signed main(){
	freopen("5.in","r",stdin);freopen("5.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>T;
    while(T--){
		cin>>n>>k;
	    vector<pair<int,int>>cus(n);
	    vector<int>a(n),b(n);
	    vector<int>cc;
	    for(int i=0;i<n;i++)cin>>a[i];
	    for(int i=0;i<n;i++)cin>>b[i];
	    for(int i=0;i<n;i++){
	        cus[i]=make_pair(a[i],b[i]);
	        cc.push_back(a[i]);
	        cc.push_back(b[i]+1);
	    }
	    sort(cc.begin(),cc.end());
	    cc.erase(unique(cc.begin(),cc.end()),cc.end());
	    sort(a.begin(), a.end());
	    sort(b.begin(), b.end());
	    int ANS=0;
	    int ia=0,ib=0;
	    for(auto p:cc){
	        while(ia<n&&a[ia]<p)ia++;
	        while(ib<n&&b[ib]<p)ib++;
	        int nega=ia-ib;
	        if(nega>k)continue;
	        int ans=p*(n-ib);
	        ANS=max(ANS,ans);
	    }
	    cout<<ANS<<endl;	
	}
    fclose(stdin);fclose(stdout);
    return 0;
}
