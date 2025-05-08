#include<bits/stdc++.h>
using namespace std;
struct nod{
	int num;
	int next;
	int last;
};
nod a[200009];
map<int,int>m;
int fir,op,i,cnt,q,x,y,n;
int main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>q;
	for(i=1;i<=q;i++){
		scanf("%d",&op);
		if(op==1){
			scanf("%d%d",&x,&y);n++;
			if(y==0){//插头 
				a[++cnt].num=x;
				if(fir!=0)a[cnt].next=fir;
				if(fir!=0)a[fir].last=cnt;
				fir=cnt;
				m[x]=cnt;//记录x的位置 
			}
			else{
				a[++cnt].num=x;
				int dir=m[y];//调用y的位置 
				if(a[dir].next!=0)a[cnt].next=a[dir].next;
				a[cnt].last=dir;
				if(a[dir].next!=0)a[a[dir].next].last=cnt;
				a[dir].next=cnt;
				m[x]=cnt;//记录x的位置 
			}
		}
		else{
			n--;
			scanf("%d",&x);//删除 
			int dir=m[x];//调用y的位置 
			if(dir==fir)fir=a[fir].next;
			if(a[dir].last!=0){
				a[a[dir].next].last=a[dir].last;
			}
			else{
				a[a[dir].next].last=0;
			}
			if(a[dir].next!=0)a[a[dir].last].next=a[dir].next;
			else{
				a[a[dir].last].next=0;
			}
		}
	}
	cout<<n<<endl;
	for(i=fir;i;i=a[i].next){
		printf("%d ",a[i].num);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
