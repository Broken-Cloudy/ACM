#include<bits/stdc++.h>
using namespace std;
int T,i,n,a[609],cha;
int main(){
	freopen("3.in","r",stdin);freopen("3.out","w",stdout);
	cin>>T;
	for(int o=1;o<=T;o++){
		scanf("%d",&n);cha=1000000009;
		for(i=1;i<=n;i++)scanf("%d",&a[i]);
		for(i=2;i<=n;i++){
			cha=min(a[i]-a[i-1],cha);
		}
		if(cha<0){
			printf("0\n");
		}
		else{
			printf("%d\n",(cha+2)/2);
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
