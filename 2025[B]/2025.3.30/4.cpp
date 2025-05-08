#include<bits/stdc++.h>
#define int long long
using namespace std;
struct nod{
	string a,b;
	int c,d;
}kk[90009];
struct node{
	string a,b;
}ans[90009];
int D,P,cnt,i,T,S,len,kks,anss,f;
map<string,int>M,MM;
string a,b,c,d;
bool cmp(nod x,nod y){
	if(x.d==y.d){
		return x.c<y.c;
	}
	else return x.d<y.d;
}
signed main(){
	freopen("4.in","r",stdin);freopen("4.out","w",stdout);
	cin>>D>>P;
	for(int dd=1;dd<=D;dd++){
		scanf("%lld%lld",&T,&S);cnt=0;
		for(i=1;i<=T;i++){
			cin>>a>>b>>c>>d;
			len=b.length();
			f=1;
			if(len==18)for(int ksm=0;ksm<len;ksm++){
				if(b[ksm]<'0'||b[ksm]>'9'){
					f=0;
				}
			}
			else f=0;
			if(f==1&&c=="1"){
				if(MM[b]==0){
					anss++;MM[b]=1;
					ans[anss].a=a;ans[anss].b=b;
				}
			}
			if(f==1&&(M[b]==0||(dd-M[b]>P))){
				cnt++;
				kk[cnt].a=a;kk[cnt].b=b;kk[cnt].c=i;
				kks=0;
				kks+=(d[0]-'0')*600;
				kks+=(d[1]-'0')*60;
				kks+=(d[3]-'0')*10;
				kks+=(d[4]-'0')*1;
				kk[cnt].d=kks;
			}
		}
		sort(kk+1,kk+1+cnt,cmp);
		for(i=1;i<=min(S,cnt);i++){
			M[kk[i].b]=dd;
			cout<<kk[i].a<<' '<<kk[i].b<<endl;
		}
	}
	for(i=1;i<=anss;i++){
		cout<<ans[i].a<<' '<<ans[i].b<<endl;
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
