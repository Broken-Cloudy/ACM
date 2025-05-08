#include<iostream>
#include<cstdio>
using namespace std;
long long a,b,x,y,gcd,r;
const long long inf=1e9+7;
void read(long long &r){
	int f=1;r=0;
	char s=getchar();
	while(s>'9'||s<'0'){
		if(s=='-')f=-1;
		s=getchar();
	}
	while(s<='9'&&s>='0'){
		r=r*10%inf+(s-'0')%inf;
		s=getchar();
	}
    r=r%inf*f;
}
void exgcd(long long a,long long b){
	if(b==0){
		x=1;y=0;
		return;
	}
	exgcd(b,a%b);
	int t=x;
	x=y;y=t-(a/b)*y;
}
int main(){
	freopen("6.in","r",stdin);freopen("6.out","w",stdout);
	read(a);read(b);
	exgcd(b,inf);
	cout<<(((x%inf)*(a%inf)%inf+inf)%inf)<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
} 
