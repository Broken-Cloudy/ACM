#include<bits/stdc++.h>
#define int long long
using namespace std;
const int P=2008LL;
int n,m,i,j,p2[109],x,a[109],ANS;
char c;
void insert(int x){
	int i;
	for(i=n;i>=0;i--){
		if(x&(1LL<<i)){
			if(a[i]){
				x^=a[i];
			}
			else{
				a[i]=x;
				break;
			}
		}
	}
}
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>n>>m;p2[0]=1;
	for(i=1;i<=50;i++)p2[i]=p2[i-1]*2;
	for(i=1;i<=m;i++){
		getchar();
		for(j=1;j<=n;j++){
			c=getchar();
			if(c=='O'){
				x+=p2[j];
			}
		}
		insert(x);
	}
	ANS=1;
	for(i=n;i>=0;i--){
		if(a[i]){
			ANS*=2;
			ANS%=P;
		}
	}
	cout<<ANS<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
