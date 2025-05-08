#include<bits/stdc++.h>
using namespace std;
int n,a[1000009],q,i,l,r;
int main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	cin>>q;
	for(i=1;i<=q;i++){
		scanf("%d%d",&l,&r);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
