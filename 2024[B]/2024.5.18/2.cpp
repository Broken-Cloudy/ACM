#include<bits/stdc++.h>
using namespace std;
int n,m,i,j;
int main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>n>>m;//n��m�� 
	if(n%2==0&&m%2==0){
		printf("NO\n");
	}
	else if(n%2==0){
		printf("YES\n");
		for(i=1;i<=m;i++){//��ѭ�� 
			if(i%2==1){
				for(j=1;j<=n;j++){//��ѭ��
					if(i==1&&j==1||i==m&&j==n)continue;
					else printf("%d %d\n",j,i);
				}
			}
			else{
				for(j=n;j>=1;j--){//��ѭ��
					if(i==1&&j==1||i==m&&j==n)continue;
					else printf("%d %d\n",j,i);
				}
			}
		}
	}
	else{
		printf("YES\n");
		for(i=1;i<=n;i++){ //��ѭ��
			if(i%2==1){
				for(j=1;j<=m;j++){//��ѭ��
					if(i==1&&j==1||i==n&&j==m)continue;
					else printf("%d %d\n",i,j);
				}
			}
			else{
				for(j=m;j>=1;j--){//��ѭ��
					if(i==1&&j==1||i==n&&j==m)continue;
					else printf("%d %d\n",i,j);
				}
			}
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
