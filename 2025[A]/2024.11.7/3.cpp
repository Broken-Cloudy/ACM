#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,i,n,a[200009],b[200009],ANS;
int work(){
	int i,ANS=0;
	for(i=2;i<=n;i++){
		if(b[i]==b[i-1])ANS++;
	}
	return ANS;
}
int Pre(){
	int i;
	for(i=2;i<=n/2;i++){
		if(a[i]==a[n-i+1]){
			if(a[i]==b[i-1]){
				b[i]=a[i];
				b[n-i+1]=a[n-i+1];
			}
			else{
				b[i]=a[i];
				b[n-i+1]=a[n-i+1];
			}
		}
		else{
			if(a[i]==b[i-1]||a[n-i+1]==b[n-i+2]){
				b[i]=a[n-i+1];
				b[n-i+1]=a[i];
			}
			else{
				b[i]=a[i];
				b[n-i+1]=a[n-i+1];
			}
		}
	}
}
signed main(){
	freopen("3.in","r",stdin);freopen("3.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld",&n);
		for(i=1;i<=n;i++)scanf("%lld",&a[i]);
		if(n%2==1)b[n/2+1]=a[n/2+1];
		b[1]=a[1];b[n]=a[n];
		Pre();
		ANS=work();
		b[1]=a[n];b[n]=a[1];
		Pre();
		ANS=min(ANS,work());
		printf("%lld\n",ANS);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
