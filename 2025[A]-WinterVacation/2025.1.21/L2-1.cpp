#include<bits/stdc++.h>
using namespace std;
int N,M[54],K,i,j,a[54][10009],x,y;
double ans1,ans2,ans;
signed main(){
	freopen("L2-1.in","r",stdin);freopen("L2-1.out","w",stdout);
	cin>>N;
	for(i=1;i<=N;i++){
		cin>>M[i];
		for(j=1;j<=M[i];j++){
			scanf("%d",&a[i][j]);
		}
		sort(a[i]+1,a[i]+1+M[i]);
		M[i]=unique(a[i]+1,a[i]+1+M[i])-(a[i]+1);
	}
	cin>>K;
	while(K--){
		scanf("%d%d",&x,&y);
		ans1=0;j=1;
		for(i=1;i<=M[x];i++){
			while(a[y][j]<a[x][i]&&j<=M[y]){
				j++;
			}
			if(j>M[y])break;
			if(a[y][j]==a[x][i])ans1++;
		}
		ans2=M[x]+M[y]-ans1;
		ans=ans1/ans2*100.0;
		printf("%.2lf%\n",ans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
