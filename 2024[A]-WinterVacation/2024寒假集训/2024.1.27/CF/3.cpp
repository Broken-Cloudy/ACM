#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int T,n,k,j,i,m,a[29],r,f[29],group,tag;
char c[1009],en[29];
int main(){
	freopen("3.in","r",stdin);freopen("3.out","w",stdout);
	cin>>T;
	for(int o=1;o<=T;o++){
		for(int l=0;l<=k;l++)en[l]=0,f[l]=0;
		group=0;
		scanf("%d%d%d",&n,&k,&m);
		scanf("%s",c+1);
		for(i=1;i<=m;i++){
			if(f[c[i]-'a'+1]==0){
				f[c[i]-'a'+1]=1;
				f[0]++;
				if(f[0]==k)en[group]=c[i];
			}
			if(f[0]==k){
				for(int l=0;l<=k;l++)f[l]=0;
				group++;
			}
			if(group==n){
				break;
			}
		}
		if(group==n){
			printf("Yes\n");
		}
		else{
			printf("No\n");
			for(i=0;i<=group-1;i++){
				putchar(en[i]);
			}
			for(i=1;i<=k;i++){
				if(f[i]==0){
					tag=i;
					break;
				}
			}
			for(i=group+1;i<=n;i++){
				putchar('a'+tag-1);
			}
			putchar('\n');
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
