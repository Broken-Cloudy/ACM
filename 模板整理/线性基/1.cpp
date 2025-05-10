#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,i,S[59],a[59],ANS;
void insert(int x){
	int i;
	for(i=50;i>=0;i--){
		if(x&(1LL<<i)){
			if(a[i]==0){//条件1 
				a[i]=x;
				break;
			}
			else x^=a[i];//条件2 
		}
	}
}
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++){
		scanf("%lld",&S[i]);
		insert(S[i]);
	}
	for(i=50;i>=0;i--){
		if((a[i]>0)&&(ANS&(1LL<<i))==0){
			ANS^=a[i];
		}
	}
	cout<<ANS<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
