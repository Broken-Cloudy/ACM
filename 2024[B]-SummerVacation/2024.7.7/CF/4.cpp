#include<bits/stdc++.h>
#define int long long
using namespace std;
int i,n,T,j,k,ans;
int a[200009],b[200009],c[200009];
bool f=0;
void S(int l,int r){//πÈ≤¢≈≈–Ú 
	if(l==r){
		return;
	}
	int mid=(l+r)/2;
	S(l,mid);S(mid+1,r);
	int i=l,j=mid+1,k=l;
	while(i<=mid&&j<=r){
		if(b[i]<=b[j]){
			c[k]=b[i];
			k++;i++;
		}
		else{
			c[k]=b[j];
			k++;j++;
			ans+=mid-i+1;
		}
	}
	while(i<=mid){
		c[k]=b[i];
		k++;i++;
	}
	while(j<=r){
		c[k]=b[j];
		k++;j++;
	}
	for(int w=l;w<=r;w++)b[w]=c[w];
}
signed main(){
	freopen("4.in","r",stdin);freopen("4.out","w",stdout);
	cin>>T;
	for(int o=1;o<=T;o++){
		cin>>n;f=0;
		map<int,int>m;
		for(i=1;i<=n;i++){
			scanf("%lld",&a[i]);
			m[a[i]]=i;
		}
		for(i=1;i<=n;i++){
			scanf("%lld",&b[i]);
			if(m[b[i]]==0){
				f=1;
			}
		}
		if(f==1){
			printf("NO\n");
		}
		else{
			for(i=1;i<=n;i++){
				b[i]=m[b[i]];
			}
			ans=0;
			S(1,n);
			if(ans%2==0){
				printf("YES\n");
			}
			else printf("NO\n");
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
