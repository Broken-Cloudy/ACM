#include<bits/stdc++.h>
using namespace std;
char c1[1010],c2[1010];
int len,i,j,f[1010][1010];
int main(){
	freopen("8.in","r",stdin);freopen("8.out","w",stdout);
	scanf("%s",c1+1);
	len=strlen(c1+1);
	for(i=1;i<=len;i++){
		c2[i]=c1[len-i+1];
	}
	for(i=1;i<=len;i++){
		for(j=1;j<=len;j++){
			f[i][j]=max(f[i][j-1],f[i-1][j]);
			if(c1[i]==c2[j])f[i][j]=max(f[i][j],f[i-1][j-1]+1);
		}
	}
	cout<<len-f[len][len]<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
