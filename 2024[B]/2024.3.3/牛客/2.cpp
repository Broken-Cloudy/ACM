#include<bits/stdc++.h>
using namespace std;
int n,i,a[100009],b[100009],cnt1,cnt2,k;
map<int,int>m;
bool f;
int main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>n;
	n*=2;
	for(i=1;i<=n;i++){
		scanf("%d",&k);
		if(m[k]>0){
			b[m[k]]=k;
			m[k]=0;
		}
		else{
			a[++cnt1]=k;
			m[k]=cnt1;
		}
	}
	for(i=1;i<=n/2;i++){
		if(b[i]==0){
			printf("-1\n");
			f=1;
		}
	}
	if(f==0){
		for(i=1;i<=n/2;i++){
			if(i==n/2){
				printf("%d\n",a[i]);
			}
			else printf("%d ",a[i]);
		}
		for(i=1;i<=n/2;i++){
			if(i==n/2){
				printf("%d\n",b[i]);
			}
			else printf("%d ",b[i]);
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
