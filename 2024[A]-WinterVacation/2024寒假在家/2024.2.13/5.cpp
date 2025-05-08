#include<bits/stdc++.h>
using namespace std;
struct nod{
	int num,zero,wei;
};
bool cmp(nod x,nod y){
	return x.zero>y.zero;
}
nod a[200009];
int T,k,n,m,i,t,sum;
int main(){
	freopen("5.in","r",stdin);freopen("5.out","w",stdout);
	cin>>T;
	for(int o=1;o<=T;o++){
		scanf("%d%d",&n,&m);sum=0;
		for(i=1;i<=n;i++){
			scanf("%d",&a[i].num);
			a[i].wei=0;a[i].zero=0;
			t=a[i].num;
			while(t%10==0){
				t/=10;
				a[i].zero++;
			}
			t=a[i].num;
			while(t>0){
				t/=10;
				a[i].wei++;
			}
			sum+=a[i].wei;
		}
		sort(a+1,a+1+n,cmp);
		for(i=1;i<=n;i++){
			if(i%2==1){//Anna
				sum-=a[i].zero;
			}
		}
		if(sum>m){
			printf("Sasha\n");
		}
		else{
			printf("Anna\n");
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
