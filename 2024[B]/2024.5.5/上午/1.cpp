#include<bits/stdc++.h>
using namespace std;
int n,i,len,j,l,r,d;
struct nod{
	int l,r;
};
nod f[100009];
string s[100009],ss,s0;
int main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>n;
	cin>>ss;
	len=1;
	f[1].l=0;f[1].r=0;s[1]=ss.substr(0,1);
	for(i=1;i<n;i++){
		for(j=i;j>=0;j--){
			s0=ss.substr(j,i-1);
			l=j;r=i;
			if(s0>s[len]&&f[len].r<l){
				s[++len]=s0;
				f[len].l=l;f[len].r=r;
			}
			else{
				d=upper_bound(s+1,s+1+len,s0)-(s);
				if(f[d].r<l){
					s[d]=s0;
					f[d].l=l;f[d].r=r;
				}
			}
		}
	}
	cout<<len<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
