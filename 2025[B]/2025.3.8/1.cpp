#include<bits/stdc++.h>
#define int long long
using namespace std;
int i,j,n,k,A,B,C,a[109],ANS;
queue<int>q;
void insert(int x){//���Ի� 
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
	}
}
signed main(){
	freopen("3.in","r",stdin);freopen("3.out","w",stdout);
	cin>>n>>k;
	for(i=1;i<=n;i++){
		scanf("%lld%lld",&A,&B);
		C=(A<<30)+B;insert(C);
	}
	for(i=59;i>=0;i--){//��׼��(�ų�����) 
		if(a[i]){//��ǰλ�������� 
			for(j=59;j>i;j--){
				if(a[j]&(1LL<<i)){//���� 
					a[j]^=a[i];
				}
			}
		}
	}
	/*for(i=29;i>=0;i--){ 
		if(a[i]&&(ANS&(1LL<<i))==0){
			ANS^=a[i];
		}
	}*/
	for(i=29;i>=0;i--){//̽��b���� 
		for(j=59;j>=0;j--){
			if(a[j]&(1LL<<i)){
				
			}
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
