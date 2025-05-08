#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,i,n,m,ans,a[300009],b[300009],ff,j;
int check(int i,int j,int x,int y){
	int f=0;
	if(a[i]==b[x]&&a[j]==b[y])f=1;
	else if(a[i]==b[y]&&a[j]==b[x])f=2;
	else f=-1;
	return f;
}
signed main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld",&n);ff=0;
		for(i=1;i<=n;i++)scanf("%lld",&a[i]);
		for(i=1;i<=n;i++)scanf("%lld",&b[i]);
		if(n==1||n==2){
			printf("Bob\n");
			continue;
		}
		i=1;j=n;
		while(i<j){
			if(check(i,j,i,j)==1&&check(i+1,j,i+1,j)!=-1&&check(i,j-1,i,j-1)!=-1){
				i++,j--;
			}
			else if(check(i,j,i,j)==2&&check(i+1,j,i,j-1)!=-1&&check(i,j-1,i+1,j)!=-1){
				i++;j--;
			}
			else{
				ff=1;break;
			}
		}
		if(ff==1){
			printf("Alice\n");
		}
		else{
			printf("Bob\n");
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
