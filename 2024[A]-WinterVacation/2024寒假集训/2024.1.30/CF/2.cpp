#include<bits/stdc++.h>
using namespace std;
struct nod{
	int a,b;
};
nod arr[200009];
bool cmp(nod x,nod y){
	return x.a<y.a;
}
int T,i,n,m;
int main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>T;
	for(int o=1;o<=T;o++){
		cin>>n;
		for(i=1;i<=n;i++)scanf("%d",&arr[i].a);
		for(i=1;i<=n;i++)scanf("%d",&arr[i].b);
		sort(arr+1,arr+1+n,cmp);
		for(i=1;i<=n;i++)printf("%d ",arr[i].a);printf("\n");
		for(i=1;i<=n;i++)printf("%d ",arr[i].b);printf("\n");
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
