#include<bits/stdc++.h>
#define int long long
using namespace std;
int i,j,n,k,A,B,C,a[109],ANS;
bool FF;
void insert(int x){//线性基 
	int i;
	for(i=59;i>=0;i--){
		if(x&(1LL<<i)){
			if(a[i]==0){
				a[i]=x;
				break;
			}
			else{
				x^=a[i];
			}
		}
		if(x==0)FF=1;//可以异或出0 
	}
}
bool check(int X){
	int i,anss;
	for(i=29;i>=0;i--){
		if(X&(1LL<<i)){
			if(a[i]){
				X^=a[i];
			}
		}
	}
	anss=X%(1LL<<30);//探查xor{x}
	if(anss<=k)return 1;
	else return 0;
}
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>n>>k;
	for(i=1;i<=n;i++){
		scanf("%lld%lld",&A,&B);
		C=(B<<30)+A;insert(C);
	}
	/*
	for(i=59;i>=0;i--){//标准化(排除干扰) 
		if(a[i]){//当前位数有数字 
			for(j=59;j>i;j--){
				if(a[j]&(1LL<<i)){//削除 
					a[j]^=a[i];
				}
			}
		}
	}
	*/
	for(i=59;i>=0;i--){
		if((a[i]%(1LL<<30))<=k&&a[i]>0){
			FF=1;
		}
	}
	for(i=59;i>=30;i--){//贪心y数组 
		if(a[i]){
			if(check(ANS^a[i])&&(ANS&(1LL<<i))==0){
				ANS^=a[i];
			}
		}
	}
	ANS/=(1LL<<30);
	if(FF==0)printf("-1\n");
	else printf("%lld\n",ANS);
	fclose(stdin);fclose(stdout);
	return 0;
}
