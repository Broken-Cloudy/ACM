#include<bits/stdc++.h>
using namespace std;
int T,i,n,a[109],Ali,Bob;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>T;
	for(int o=1;o<=T;o++){
		scanf("%d",&n);
		for(i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		sort(a+1,a+1+n,cmp);
		Ali=0;Bob=0;
		for(i=1;i<=n;i++){
			if(i%2==1){
				Ali+=a[i];
			}
			else{
				Bob+=a[i];
			}
		}
		if(Ali>Bob){
			printf("Alice\n");
		}
		else{
			printf("Bob\n");
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
