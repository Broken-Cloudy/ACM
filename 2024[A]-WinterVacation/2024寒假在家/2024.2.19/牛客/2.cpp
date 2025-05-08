#include<bits/stdc++.h>
using namespace std;
long long n,a[200009],i,sum;
int main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		sum+=a[i];
	}
	if((sum-n)%2==0){
		cout<<"sweet"<<endl;
	}
	else{
		cout<<"gui"<<endl;
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
