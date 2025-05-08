#include<bits/stdc++.h>
using namespace std;
int n,m,i,j;
int main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>n>>m;
	if(n%2==0&&m%2==0){
		cout<<"NO"<<endl;
	}
	else {
		cout<<"YES"<<endl;
		if(n%2==1){
			for(i=1;i<=n;i++){
			if(i%2==1){
				for(j=1;j<=m;j++){
					if(i==1&&j==1||i==n&&j==m)continue;
					printf("%d %d\n",i,j);
				}
			}
			else{
				for(j=m;j>=1;j--){
					if(i==1&&j==1||i==n&&j==m)continue;
					printf("%d %d\n",i,j);
				}
			}
		}
		}
		else{
			for(i=1;i<=m;i++){
			if(i%2==1){
				for(j=1;j<=n;j++){
					if(i==1&&j==1||i==m&&j==n)continue;
					printf("%d %d\n",j,i);
				}
			}
			else{
				for(j=n;j>=1;j--){
					if(i==1&&j==1||i==m&&j==n)continue;
					printf("%d %d\n",j,i);
				}
			}
		}
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}

