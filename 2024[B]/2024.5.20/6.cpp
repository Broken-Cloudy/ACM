#include<bits/stdc++.h>
using namespace std;
map<int,int>m;
int i,n,k,M;
int main(){
	freopen("6.in","r",stdin);freopen("6.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++){
		scanf("%d",&k);
		m[k]=1;
	}
	cin>>M;
	for(i=1;i<=M;i++){
		scanf("%d",&k);
		if(m[k]==1){
			printf("ZengYu\n");
		}
		else{
			printf("JieDai\n");
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
