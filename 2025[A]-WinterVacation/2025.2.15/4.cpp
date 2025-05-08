#include<bits/stdc++.h>
using namespace std;
struct nod{
	int bh;
	int FF;
}a[1009][509],x,y,ansx[1009],ansy[1009];
struct node{
	double val;
	int FF;
	int bh;
}b[1009];
double maxx,kk,maxy;
int i,N,M,cnt[1009],j,cntx,cnty;
bool F;
char ch;
nod getin(){
	nod t;
	int a=0,b=0,i;
	string s;
	cin>>s;
	int len=s.length();
	if(s[0]=='-'){
		b=2;
		for(i=1;i<len;i++){
			a*=10;
			a+=(s[i]-'0');
		}
	}
	else{
		b=1;
		for(i=0;i<len;i++){
			a*=10;
			a+=(s[i]-'0');
		}
	}
	t.bh=a;t.FF=b;
	return t;
}
bool cmp(node x,node y){
	if(x.val==y.val)return x.bh<y.bh;
	else return x.val>y.val;
}
bool CMP(nod x,nod y){
	return x.bh<y.bh;
}
void f(nod x){
	if(x.FF==2)putchar('-');
	printf("%d",x.bh);
}
signed main(){
	freopen("4.in","r",stdin);freopen("4.out","w",stdout);
	cin>>N>>M;
	for(i=1;i<=M;i++){
		scanf("%d",&cnt[i]);
		for(j=1;j<=cnt[i];j++){
			a[i][j]=getin();//FF=2是女，FF=1是男 
		}
	}
	x=getin();y=getin();
	//1
	for(i=0;i<N;i++)b[i].bh=i;
	for(i=1;i<=M;i++){
		kk=cnt[i];kk=1.0/kk;F=0;
		for(j=1;j<=cnt[i];j++){
			if(a[i][j].FF==x.FF&&a[i][j].bh==x.bh){
				F=1;break;
			}
		}
		if(F==1)for(j=1;j<=cnt[i];j++){
			if(a[i][j].FF!=x.FF&&a[i][j].bh!=x.bh){
				b[a[i][j].bh].val+=kk;
				b[a[i][j].bh].FF=a[i][j].FF;
			}
		}
	}
	sort(b,b+N,cmp);
	for(i=0;i<N;i++){
		if(b[i].FF==0)continue;
		if(b[i].FF!=x.FF){
			maxx=max(maxx,b[i].val);
			if(b[i].val==maxx){
				if(b[i].bh==y.bh){
					cntx=-1;break;
				}
				else{
					cntx++;
					ansx[cntx].bh=b[i].bh;
					ansx[cntx].FF=b[i].FF;
				}
			}
		}
	}
	if(cntx<=0){
		f(x);putchar(' ');f(y);putchar('\n');
	}
	else{
		sort(ansx+1,ansx+1+cntx,CMP);
		for(i=1;i<=cntx;i++){
			f(x);putchar(' ');f(ansx[i]);putchar('\n');
		}
	}
	//2
	memset(b,0,sizeof(b));
	for(i=0;i<N;i++)b[i].bh=i;
	for(i=1;i<=M;i++){
		kk=cnt[i];kk=1.0/kk;F=0;
		for(j=1;j<=cnt[i];j++){
			if(a[i][j].FF==y.FF&&a[i][j].bh==y.bh){
				F=1;break;
			}
		}
		if(F==1)for(j=1;j<=cnt[i];j++){
			if(a[i][j].FF!=y.FF&&a[i][j].bh!=y.bh){
				b[a[i][j].bh].val+=kk;
				b[a[i][j].bh].FF=a[i][j].FF;
			}
		}
	}
	sort(b,b+N,cmp);
	for(i=0;i<N;i++){
		if(b[i].FF==0)continue;
		if(b[i].FF!=y.FF){
			maxy=max(maxy,b[i].val);
			if(b[i].val==maxy){
				if(b[i].bh==x.bh){
					cnty=-1;break;
				}
				else{
					cnty++;
					ansy[cnty].bh=b[i].bh;
					ansy[cnty].FF=b[i].FF;
				}
			}
		}
	}
	if(cntx<=0&&cnty<=0){
		//无 
	}
	else if(cnty<=0){
		f(y);putchar(' ');f(x);putchar('\n');
	}
	else{
		sort(ansy+1,ansy+1+cnty,CMP);
		for(i=1;i<=cnty;i++){
			f(y);putchar(' ');f(ansy[i]);putchar('\n');
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
