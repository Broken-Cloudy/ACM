#include<bits/stdc++.h>
using namespace std;
long long n,D,a[200009],b[200009],score,i,j,k;
int main(){
	freopen("8.in","r",stdin);freopen("8.out","w",stdout);
	cin>>n>>D;
	for(i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(i==D)score+=a[i];
	}
	for(i=1;i<=n;i++){
		scanf("%lld",&b[i]);
	}
	score+=b[1];j=n;
	for(i=1;i<D;i++){
		if(a[i]+b[j]<=score){
			k++;
			j--;
		}
	}
	cout<<D-k<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
