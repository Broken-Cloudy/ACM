#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500009],b[500009],ans=0,n;
void S(int l,int r){
	if(l==r)return;
	int mid=(l+r)/2;
	S(l,mid);S(mid+1,r);
	int i=l,j=mid+1;
	int k=l;
	while(i<=mid&&j<=r){
		if(a[i]<=a[j]){
			b[k]=a[i];
			k++;i++;
		}
		else{
			b[k]=a[j];
			k++;j++;
			ans+=(mid-i+1);
		}
	}
	while(i<=mid){
		b[k]=a[i];k++;i++;
	}
	while(j<=r){
		b[k]=a[j];k++;j++;
	}
	for(int w=l;w<=r;w++)a[w]=b[w];
}
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	S(1,n);
	for(int i=1;i<=n;i++){
		printf("%lld ",a[i]);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
