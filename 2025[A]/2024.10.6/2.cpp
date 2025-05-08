#include<bits/stdc++.h>
#define int long long
using namespace std;
int Z[20000009],P[20000009],ans1,ans2,i;
char a[20000009],b[20000009];
int len1,len2;
void get_Z(){
	int i,l,r=0;
	Z[1]=len1;//第一位肯定是与长度len1都匹配 
	for(i=2;i<=len1;i++){
		if(i<=r)Z[i]=min(Z[i-l+1],r-i+1);//在盒内 S[i,r]=S[i-l+1,r-l+1] 
		while(a[1+Z[i]]==a[i+Z[i]])Z[i]++;
		if(i+Z[i]-1>r)l=i,r=i+Z[i]-1;
	}
}
void get_Zp(){
	int i,l,r=0;
	for(i=1;i<=len2;i++){
		if(i<=r)P[i]=min(Z[i-l+1],r-i+1);
		while(a[1+P[i]]==b[i+P[i]]&&1+P[i]<=len1&&1+P[i]<=len2)P[i]++;
		if(i+P[i]-1>r)l=i,r=i+P[i]-1;
	}
}
signed main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	scanf("%s",b+1);scanf("%s",a+1);
	len1=strlen(a+1);len2=strlen(b+1);
	get_Z();get_Zp();
	for(i=1;i<=len1;i++)ans1^=i*(Z[i]+1LL);
	for(i=1;i<=len2;i++)ans2^=i*(P[i]+1LL);
	cout<<ans1<<endl;cout<<ans2<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
