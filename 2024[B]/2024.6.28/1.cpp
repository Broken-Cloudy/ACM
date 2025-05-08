#include<bits/stdc++.h>
using namespace std;
int a[120],n,i,k;
bool f=0;
int main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++)scanf("%d",&k),a[k]++;
	for(i=1;i<=n;i++){
		if(a[i]>=3){
			printf("YES\n");
			f=1;
			break;
		}
	}
	if(f==0){
		printf("NO\n");
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
