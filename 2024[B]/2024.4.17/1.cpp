#include<bits/stdc++.h>
using namespace std;
int N,i,tree[1009],post[1009],cnt;
void build(int l,int r){
	if(l>r)return;
	int i=l+1;
	int j=r;
	while(i<=r&&tree[i]<tree[l])i++;
	while(j>=l+1&&tree[l]<=tree[j])j--;
	if(i-j!=1)return;
	build(l+1,j);
	build(i,r);
	post[++cnt]=tree[l];//放最后，后序遍历 
}
void build2(int l,int r){
	if(l>r)return;
	int i=l+1;
	int j=r;
	while(i<=r&&tree[i]>=tree[l])i++;
	while(j>=l+1&&tree[l]>tree[j])j--;
	if(i-j!=1)return;
	build2(l+1,j);
	build2(i,r);
	post[++cnt]=tree[l];//放最后，后序遍历 
}
int main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>N;
	for(i=1;i<=N;i++){
		scanf("%d",&tree[i]);
	}
	build(1,N);
	if(cnt!=N){
		cnt=0;
		build2(1,N);
	}
	if(cnt!=N){
		printf("NO\n");
	}
	else{
		printf("YES\n"); 
        printf("%d",post[1]);
        for(i=2;i<=cnt;i++) printf(" %d", post[i]);
        printf("\n");
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
