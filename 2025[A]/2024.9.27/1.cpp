#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,ans;
int flag[5000009],prime[5000009],cnt,i,j;//flag[i]==0质数
void Pre(){//O(NloglogN)埃氏筛 10^7 
	flag[1]=1;
	for(i=2;i<=5000000;i++){
		if(flag[i]==0){
			prime[++cnt]=i;//记录下来 
			for(j=i;j<=5000000;j+=i){
				flag[j]++;//一下子筛到底 
			}
		}
	}
}
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>n;
	Pre();
	for(i=1;i<=n;i++){
		if(flag[i]>=2)ans++;
	}
	cout<<ans<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
