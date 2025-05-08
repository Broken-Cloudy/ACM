#include<bits/stdc++.h>
using namespace std;
struct nod{
	int zhi,next;
};
nod a[100009],b[100009],c[100009];
int start,n,i,x,y,z,t,startb=-1,startc=-1,cntb=-1,cntc=-1;
map<int,int>m;
void putout(int x){
	if(x>=10000)printf("%d",x);
	else if(x>=1000&&x<=9999){
		putchar('0');
		printf("%d",x);
	}
	else if(x>=100&&x<=999){
		putchar('0');putchar('0');
		printf("%d",x);
	}
	else if(x>=10&&x<=99){
		putchar('0');putchar('0');putchar('0');
		printf("%d",x);
	}
	else if(x>=0&&x<=9){
		putchar('0');putchar('0');putchar('0');putchar('0');
		printf("%d",x);
	}
	else{
		printf("-1");
	}
}
int main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>start>>n;
	for(i=1;i<=n;i++){
		scanf("%d%d%d",&x,&y,&z);
		a[x].zhi=y;
		a[x].next=z;
	}
	t=start;
	while(t!=-1){
		if(m[a[t].zhi]==1){
			if(cntc==-1){//第一个 
				startc=t;
				cntc=t;
				c[t].zhi=a[t].zhi;
				c[t].next=-1;
			}
			else{
				c[cntc].next=t;
				cntc=t;
				c[t].zhi=a[t].zhi;
				c[t].next=-1;
			}
		}
		else{
			m[a[t].zhi]=1;
			m[-a[t].zhi]=1;
			if(cntb==-1){//第一个 
				startb=t;
				cntb=t;
				b[t].zhi=a[t].zhi;
				b[t].next=-1;
			}
			else{
				b[cntb].next=t;
				cntb=t;
				b[t].zhi=a[t].zhi;
				b[t].next=-1;
			}
		}
		t=a[t].next;
	}
	t=startb;
	while(t!=-1){
		putout(t);putchar(' ');
		printf("%d ",b[t].zhi);
		putout(b[t].next);putchar('\n');
		t=b[t].next;
	}
	t=startc;
	while(t!=-1){
		putout(t);putchar(' ');
		printf("%d ",c[t].zhi);
		putout(c[t].next);putchar('\n');
		t=c[t].next;
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
