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
			if(y==0){//��ͷ 
				a[++cnt].num=x;
				if(fir!=0)a[cnt].next=fir;
				if(fir!=0)a[fir].last=cnt;
				fir=cnt;
				m[x]=cnt;//��¼x��λ�� 
			}
			else{
				a[++cnt].num=x;
				int dir=m[y];//����y��λ�� 
				if(a[dir].next!=0)a[cnt].next=a[dir].next;
				a[cnt].last=dir;
				if(a[dir].next!=0)a[a[dir].next].last=cnt;
				a[dir].next=cnt;
				m[x]=cnt;//��¼x��λ�� 
			}
		}
		else{
			n--;
			scanf("%d",&x);//ɾ�� 
			int dir=m[x];//����y��λ�� 
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
