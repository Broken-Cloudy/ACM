//µ¥hash 
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int i,n,answer;
long long a1[10010],a2[10010];
const long long inf1=16785712345479,inf2=1e9+9,base=62;
char c[1555];
int check(char c){
	if(c>='a'&&c<='z'){
		return (c-'a');
	}
	else if(c>='A'&&c<='Z'){
		return (c-'A')+26;
	}
	else if(c>='0'&&c<='9'){
		return (c-'0')+52;
	}
}
void Hash(int x){
	int len=strlen(c+1);
	long long ans1=0,ans2=0;
	for(int i=1;i<=len;i++){
		ans1=(ans1*base+check(c[i]))%inf1;
		ans2=(ans2*base+check(c[i]))%inf2;
	}
	a1[x]=ans1;a2[x]=ans2;
}
int main(){
	//freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++){
		scanf("%s",c+1);
		Hash(i);
	}
	sort(a1+1,a1+1+n);
	sort(a2+1,a2+1+n);
	for(i=1;i<=n;i++){
		if(a1[i]!=a1[i-1])answer++;
	}
	cout<<answer<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
} 
