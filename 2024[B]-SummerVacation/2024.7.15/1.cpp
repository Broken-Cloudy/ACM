#include<bits/stdc++.h>
using namespace std;
int a[59],w,n,i;
int ans1,ans2;
int main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>n>>w;
	for(i=1;i<=n;i++)scanf("%d",&a[i]);
	for(i=1;i<=n;i++){
		if(w==4){
			if(a[i]>=35){
				ans2++;
			}
		}
		else{
			if(a[i]>=35){
				ans1++;
			}
		}
		w++;
		if(w>=8)w=1;
	}
	cout<<ans1<<' '<<ans2<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
