#include<bits/stdc++.h>
using namespace std;
int T,n,m,p;
int main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>T;
	for(int o=1;o<=T;o++){
		scanf("%d%d%d",&n,&m,&p);
		if(n==1){
			printf("YangQiShaoNian\n");
		}
		else if(n<=m+1){
			printf("XiaoNian\n");
		}
		else{
			if(p==0){//xiaonian 2ci
				printf("XiaoNian\n");
			}
			else{//yangqi 2ci
				printf("YangQiShaoNian\n");
			}
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
