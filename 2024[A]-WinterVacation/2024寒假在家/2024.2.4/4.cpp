#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct nod{
	int qian,hou,num;
};
map<int,int>m;
nod a[200009];
int i,q,op,qian,hou,x,y,tou,k[200009];
int main(){
	freopen("4.in","r",stdin);freopen("4.out","w",stdout);
	cin>>q;
	for(i=1;i<=q;i++){
		scanf("%d",&op);
		if(op==1){
			scanf("%d%d",&x,&y);
			if(y==0){
				m[x]=i;
				a[i].hou=tou;
				tou=i;
				a[i].num=x;
			}
			else{
				int dr=m[y];//y的位置 
				m[x]=i;//存储x的位置 
				a[i].num=x;
				a[i].hou=a[dr].hou;
				a[dr].hou=i;
				a[i].qian=dr;
			}
		}
		else{
			scanf("%d",&x);
			int dr=m[x];//x的位置 
			if(a[dr].qian==0)tou=a[dr].hou;
			a[a[dr].hou].qian=a[dr].qian;
			a[a[dr].qian].hou=a[dr].hou;
		}
	}
	for(i=tou;i;i=a[i].hou){
		k[++k[0]]=a[i].num;
	}
	cout<<k[0]<<endl;
	for(i=1;i<=k[0];i++){
		printf("%d ",k[i]);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
