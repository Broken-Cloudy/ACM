#include<iostream>
#include<cstdio>
using namespace std;
int T,n,i,a[100009],coins1[100009],coinsf1[100009],m,x,y,point[100009];
int main(){
	freopen("3.in","r",stdin);freopen("3.out","w",stdout);
	cin>>T;
	for(int o=1;o<=T;o++){
		scanf("%d",&n);
		for(i=1;i<=n;i++)scanf("%d",&a[i]);
		point[1]=1;point[n]=-1;
		for(i=2;i<n;i++){
			if(max(a[i]-a[i-1],a[i-1]-a[i])>max(a[i]-a[i+1],a[i+1]-a[i])){
				point[i]=1;
			}
			else point[i]=-1;
		}
		coins1[1]=0;coinsf1[n]=0;
		for(i=1;i<n;i++){
			if(point[i]==1)coins1[i+1]=coins1[i]+1;
			else coins1[i+1]=coins1[i]+max(a[i]-a[i+1],a[i+1]-a[i]);
		}
		for(i=n;i>1;i--){
			if(point[i]==-1)coinsf1[i-1]=coinsf1[i]+1;
			else coinsf1[i-1]=coinsf1[i]+max(a[i]-a[i-1],a[i-1]-a[i]);
		}
		scanf("%d",&m);
		for(i=1;i<=m;i++){
			scanf("%d%d",&x,&y);
			if(x<y)printf("%d\n",coins1[y]-coins1[x]);
			else printf("%d\n",coinsf1[y]-coinsf1[x]);
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
} 
