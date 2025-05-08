#include<bits/stdc++.h>
using namespace std;
struct nod{
	int time,x,y;
};
struct node{
	int time,x,y,ans;
};
nod a[10009];
node f[10009][3];
int n,m,i,j;
bool check(nod x,node f){
	if(f.ans==0)return 1;
	int dis=max(x.x-f.x,f.x-x.x)+max(x.y-f.y,f.y-x.y);
	if(dis>(x.time-f.time))return 0;
	else return 1;
}
int main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=m;i++){
		scanf("%d%d%d",&a[i].time,&a[i].x,&a[i].y);
	}
	f[1][1].ans=1;f[1][1].x=a[1].x;f[1][1].y=a[1].y;f[1][1].time=a[1].time;
	for(i=2;i<=m;i++){
		for(j=1;j<i;j++){
			//选择i 不选j
			if(f[j][0].ans+1>f[i][0].ans&&check(a[i],f[j][0])){
				f[i][1].ans=f[j][0].ans+1;
				f[i][1].time=a[i].time;
				f[i][1].x=a[i].x;
				f[i][1].y=a[i].y;
			}
			//选择i 选j 
			if(f[j][1].ans+1>f[i][1].ans&&check(a[i],f[j][1])){
				f[i][1].ans=f[j][1].ans+1;
				f[i][1].time=a[i].time;
				f[i][1].x=a[i].x;
				f[i][1].y=a[i].y;
			}
			//不选i 不选j
			if(f[j][0].ans>f[i][0].ans){
				f[i][0].ans=f[j][0].ans;
				f[i][0].time=f[j][0].time;
				f[i][0].x=f[j][0].x;
				f[i][0].y=f[j][0].y;
			}
			//不选i 选j
			if(f[j][1].ans>f[i][0].ans){
				f[i][0].ans=f[j][1].ans;
				f[i][0].time=f[j][1].time;
				f[i][0].x=f[j][1].x;
				f[i][0].y=f[j][1].y;
			}
		}
	}
	cout<<max(f[m][0].ans,f[m][1].ans)<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
