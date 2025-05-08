#include<bits/stdc++.h>
using namespace std;
int a[109],n,i,k,num,ans;
int main(){
	freopen("5.in","r",stdin);freopen("5.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>k;
		a[k]++;
	}
	for(i=1;i<=100;i++){
		if(a[i]>num){
			num=a[i];
			ans=i;
		}
	}
	cout<<ans<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
