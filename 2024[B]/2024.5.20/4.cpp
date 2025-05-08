#include<bits/stdc++.h>
using namespace std;
int ans,n,i,j,k;
char c[100009],b;
bool f,ff;
int main(){
	freopen("4.in","r",stdin);freopen("4.out","w",stdout);
	cin>>n;getchar();
	for(i=1;i<=n;i++){
		memset(c,0,sizeof(c));
		b=getchar();f=0;j=0;
		while(b!='\n'&&b!=-1){
			c[++j]=b;b=getchar();
		}
		for(k=1;k<=j;k++){
			if(c[k]>='0'&&c[k]<='9'){
				f=1;
				break;
			}
		}
		if(f==1){
			ff=1;
			for(k=1;k<=j;k++){
				putchar(c[k]);
			}
			putchar('\n');
		}
		else{
			
		}
	}
	if(ff==0)cout<<"Not interesting."<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
