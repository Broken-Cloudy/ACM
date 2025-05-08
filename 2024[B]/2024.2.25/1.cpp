#include<bits/stdc++.h>
using namespace std;
long long a[200009],n,k,i,sum[200009],f[200009];
map<long long,long long>m;//ÉÏÒ»Î» 
int main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>n>>k;
	for(i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		sum[i]=sum[i-1]+a[i];
		sum[i]%=k;
	}
	m[0]=0;
	for(i=1;i<=n;i++){
		f[i]=f[i-1];
		if(m.count(sum[i])){
			f[i]=max(f[i],f[m[sum[i]]]+1);
		}
		m[sum[i]]=i;
	}
	cout<<f[n]<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
