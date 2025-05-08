#include<bits/stdc++.h>
using namespace std;
int a[100010],n,i,num[100010],f[100010];
int mis[100010],cnt,pos,ans,len;
const int INF=1000000009;
int check(int l,int r,int x){
	if(l==r){
		return l;
	}
	else if(l==r-1){
		if(mis[l]>=x){
			return l;
		}
		else{
			return r;
		}
	}
	int mid=(l+r)/2;
	if(mis[mid]<x)check(mid,r,x);
	else check(l,mid,x);
}
int main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	while(~scanf("%d",&a[++n]));n--;
	for(i=1;i<=n;i++)f[i]=INF;//第一问 
	f[1]=a[1];
	len=1;
	for(i=2;i<=n;i++){
		int l=1,r=len,mid;
		if(a[i]<=f[len]){
			f[++len]=a[i];
		}
		else{
			while(l<r){
				mid=(l+r)/2;
				if(f[mid]<a[i])r=mid;
				else l=mid+1;
			}
			f[l]=max(a[i],f[l]);
		}
	}
	mis[++cnt]=a[1];
	for(i=2;i<=n;i++){//第二问 
		if(a[i]>mis[cnt]){
			mis[++cnt]=a[i];
			continue;
		}
		else{
			pos=check(1,cnt,a[i]);
			mis[pos]=a[i];
		}
	}
	cout<<len<<endl;
	cout<<cnt<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
} 

