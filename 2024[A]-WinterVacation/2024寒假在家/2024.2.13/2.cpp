#include<bits/stdc++.h>
using namespace std;
int T,n,a[200009],sum,i,num,con;
bool f;
int main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>T;
	for(int o=1;o<=T;o++){
		scanf("%d",&n);sum=0;f=0;
		for(i=1;i<=n;i++){
			scanf("%d",&a[i]);
			sum+=a[i];
		}
		if(sum%n==0){
			num=sum/n;con=0;
			for(i=1;i<=n;i++){
				if(a[i]>=num){
					con+=a[i]-num;
					a[i]=num;
				}
				else{
					con-=num-a[i];
					a[i]=num;
				}
				if(con<0){
					f=1;
					break;
				}
			}
			if(f==1||con!=0){
				printf("No\n");
			}
			else{
				printf("Yes\n");
			}
		}
		else{
			printf("No\n");
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
