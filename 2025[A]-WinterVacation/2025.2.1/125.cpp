#include<bits/stdc++.h>
#define int long long
using namespace std;
struct nod{
	string s;
	int k;
	double xx;
}a[109];
double x00,y00;
int N,i,k,j,x;
map<int,int>M;
bool cmp(nod x,nod y){
	if(x.k==y.k)return x.xx<y.xx;
	else return x.k>y.k;
}
signed main(){
	freopen("125.in","r",stdin);freopen("125.out","w",stdout);
	cin>>N;
	for(i=1;i<=N;i++){
		cin>>a[i].s;
		cin>>k;M.clear();
		for(j=1;j<=k;j++){
			scanf("%lld",&x);
			if(M[x]==0){
				a[i].k++;
				M[x]=1;
			}
			else M[x]++;
		}
		x00=k;y00=a[i].k;
		a[i].xx=x00/y00;
	}
	sort(a+1,a+1+N,cmp);
	if(N==1){
		cout<<a[1].s<<' '<<'-'<<' '<<'-'<<endl;
	}
	else if(N==2){
		cout<<a[1].s<<' '<<a[2].s<<' '<<'-'<<endl;
	}
	else{
		cout<<a[1].s<<' '<<a[2].s<<' '<<a[3].s<<endl;
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
