#include<bits/stdc++.h>
#define int long long
using namespace std;
int A,B,C,AA,ans,k1,k2,ANS,i,j,N;
signed main(){
	freopen("6.in","r",stdin);freopen("6.out","w",stdout);
	cin>>A>>B>>C;
	AA=sqrt(A);
	for(i=1;i<=AA;i++){
		if(i*i==A){
			if((C-i)%B==0){
				N=(C-i)/B;
				if(N<C/B&&N>=1)ans++;
				continue;
			}
		}
		else if(A%i==0){
			j=A/i;
			if((C-i)%B==0){
				N=(C-i)/B;
				if(N<C/B&&N>=1)ans++;
			}
			if((C-j)%B==0){
				N=(C-j)/B;
				if(N<C/B&&N>=1)ans++;
			}
		}
	}
	ANS=C/B;if(C%B==0)ANS--;
	ANS-=ans;
	cout<<ANS<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
