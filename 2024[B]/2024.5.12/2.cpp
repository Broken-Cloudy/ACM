#include<bits/stdc++.h>
using namespace std;
int n,i,w,j,ans;
struct nod{
	int time;
	string s;
};
nod a[1009];
string s0;
int main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>a[i].s>>a[i].time;
	}
	cin>>w;
	for(i=1;i<=w;i++){
		cin>>s0;
		for(j=1;j<=n;j++){
			if(s0==a[j].s){
				a[j].time--;
			}
		}
	}
	for(i=1;i<=n;i++){
		if(a[i].time<=0)ans++;
	}
	cout<<ans<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
