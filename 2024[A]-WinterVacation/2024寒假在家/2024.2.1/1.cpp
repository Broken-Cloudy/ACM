#include<bits/stdc++.h>
using namespace std;
int n,a[39],GCD,i;
void gcd(int a,int b){
	if(b==0){
		GCD=a;
		return;
	}
	gcd(b,a%b);
}
int main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]<0)a[i]=-a[i];
	}
	GCD=a[1];
	for(i=2;i<=n;i++){
		if(GCD<a[i])swap(GCD,a[i]);
		gcd(GCD,a[i]);
	}
	cout<<GCD<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
