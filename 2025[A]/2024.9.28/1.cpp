#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,i,a[200009],ans1,ans2,ans3;
int zheng,fu,zero;
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++)scanf("%lld",&a[i]);
	//ans1¸º£¬ans2Áã£¬ans3Õý 
	for(i=1;i<=n;i++){
		if(a[i]>0){
			zheng++;
			ans1+=fu;ans2+=zero;ans3+=zheng;
		}
		else if(a[i]==0){
			zero+=(zheng+fu)+1;
			zheng=fu=0;
			ans1+=fu;ans2+=zero;ans3+=zheng;
		}
		else{
			swap(zheng,fu);fu++;
			ans1+=fu;ans2+=zero;ans3+=zheng;
		}
	}
	cout<<ans1<<' '<<ans2<<' '<<ans3<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
