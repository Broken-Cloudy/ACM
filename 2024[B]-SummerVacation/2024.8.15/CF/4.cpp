#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,k,i,sum,x,y,q,ans;
int a[200009];
int arr[7][200009];
string s;
//BG, BR, BY, GR, GY, or RY
void add(string s,int i){
	if(s=="BG")arr[1][++arr[1][0]]=i,a[i]=1;
	if(s=="BR")arr[2][++arr[2][0]]=i,a[i]=2;
	if(s=="BY")arr[3][++arr[3][0]]=i,a[i]=3;
	if(s=="GR")arr[4][++arr[4][0]]=i,a[i]=4;
	if(s=="GY")arr[5][++arr[5][0]]=i,a[i]=5;
	if(s=="RY")arr[6][++arr[6][0]]=i,a[i]=6;
}
int Find(int u,int v,int type){
	int d,AN=1000000009;
	int l=lower_bound(arr[type]+1,arr[type]+1+arr[type][0],u)-arr[type];
	int r=lower_bound(arr[type]+1,arr[type]+1+arr[type][0],v)-arr[type];
	if(r==l){//’“≤ªµΩ 
		if(r<=arr[type][0]){
			d=arr[type][r];
			if(d<u)AN=min(AN,(v-u)+(u-d)*2);
			else AN=min(AN,(v-u)+(d-v)*2);
		}
		if(l-1>0){
			d=arr[type][l-1];
			AN=min(AN,(v-u)+(u-d)*2);
		}
		if(r+1<=arr[type][0]){
			d=arr[type][r+1];
			AN=min(AN,(v-u)+(d-v)*2);
		}
	}
	else AN=v-u;
	return AN;
}
int check(int u,int v,int type){
	int d,ANS=1000000009;
	if(type==16){
		ANS=min(ANS,Find(u,v,2));ANS=min(ANS,Find(u,v,3));
		ANS=min(ANS,Find(u,v,4));ANS=min(ANS,Find(u,v,5));
	}
	else if(type==25){
		ANS=min(ANS,Find(u,v,1));ANS=min(ANS,Find(u,v,3));
		ANS=min(ANS,Find(u,v,4));ANS=min(ANS,Find(u,v,6));
	}
	else{
		ANS=min(ANS,Find(u,v,1));ANS=min(ANS,Find(u,v,2));
		ANS=min(ANS,Find(u,v,5));ANS=min(ANS,Find(u,v,6));
	}
	if(ANS==1000000009)return -1;
	else return ANS;
}
signed main(){
	freopen("4.in","r",stdin);freopen("4.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld%lld",&n,&q);
		arr[1][0]=arr[2][0]=arr[3][0]=arr[4][0]=arr[5][0]=arr[6][0]=0;
		for(i=1;i<=n;i++){
			cin>>s;
			add(s,i);
		}
		while(q--){
			scanf("%lld%lld",&x,&y);
			if(x>y)swap(x,y);
			if((a[x]==1&&a[y]==6)||(a[x]==6&&a[y]==1)){
				ans=check(x,y,16);
			}
			else if((a[x]==2&&a[y]==5)||(a[x]==5&&a[y]==2)){
				ans=check(x,y,25);
			}
			else if((a[x]==3&&a[y]==4)||(a[x]==4&&a[y]==3)){
				ans=check(x,y,34);
			}
			else ans=y-x;
			printf("%lld\n",ans);
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
