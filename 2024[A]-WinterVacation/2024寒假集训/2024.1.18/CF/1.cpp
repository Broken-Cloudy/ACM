#include<iostream>
#include<cstdio>
using namespace std;
int T,n,i;
bool flag=0,f=0;
char a[29],b[29],c[29],d[29];
int main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>T;
	for(int o=1;o<=T;o++){
		cin>>n;flag=1;
		f=0;//必然不同 
		for(i=1;i<=n;i++)d[i]=0;
		getchar();
		for(i=1;i<=n;i++){
			a[i]=getchar();
		}
		getchar();
		for(i=1;i<=n;i++){
			b[i]=getchar();
		}
		getchar();
		for(i=1;i<=n;i++){
			c[i]=getchar();
		}
		for(i=1;i<=n;i++){
			if(a[i]>='a'&&a[i]<='z')a[i]=a[i]-'a'+'A';
			if(b[i]>='a'&&b[i]<='z')b[i]=b[i]-'a'+'A';
			if(c[i]>='a'&&c[i]<='z')c[i]=c[i]-'a'+'A';
			if(c[i]!=a[i]&&c[i]!=b[i]){
				f=1;
			}
		}
		if(i==n+1)flag=0;
		if(flag==1||f==0)printf("NO\n");
		else printf("YES\n");
	}
	fclose(stdin);fclose(stdout);
	return 0;
} 
