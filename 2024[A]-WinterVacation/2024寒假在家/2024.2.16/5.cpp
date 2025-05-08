#include<bits/stdc++.h>
using namespace std;
int i,n,a[200009],b[200009];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("5.in","r",stdin);freopen("5.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(i=2;i<=n;i++){
		if(a[i]<a[i-1]){
			b[i]=a[i-1]-a[i];
			a[i]=a[i-1];
		}
	}
	for(i=1;i<=n;i++){
		if(i<n)printf("%d ",b[i]);
		else printf("%d\n",b[i]);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
