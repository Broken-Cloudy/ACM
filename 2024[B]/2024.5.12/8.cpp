#include<bits/stdc++.h>
using namespace std;
int n,m,i,a[10009],f[5009],cnt,j;
bool ff=0;
int main(){
	freopen("8.in","r",stdin);freopen("8.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	f[++cnt]=a[1];
	for(i=2;i<=n;i++){
		ff=0;
		for(j=1;j<=cnt;j++){
			if(f[j]<a[i]){
				ff=1;
				f[j]=a[i];
				break;
			}
		}
		if(ff==0)f[++cnt]=a[i];
	}
	if(cnt<=m)cout<<"Karashi cblcd"<<endl;
	else cout<<"Karashi lovelove"<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
