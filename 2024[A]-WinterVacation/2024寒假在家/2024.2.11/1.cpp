#include<bits/stdc++.h>
using namespace std;
int T,n,i,a,b,c,d;
int main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>T;
	for(int o=1;o<=T;o++){
		c=0;d=0;
		scanf("%d%d",&a,&b);
		if(a>b)swap(a,b);
		if(a%2==0){
			c=a/2;
			d=b*2;
			if(c>d)swap(c,d);
			if(c==a&&b==d){
				printf("No\n");
			}
			else{
				printf("Yes\n");
			}
		}
		else if(b%2==0){
			c=a*2;
			d=b/2;
			if(c>d)swap(c,d);
			if(c==a&&b==d){
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
