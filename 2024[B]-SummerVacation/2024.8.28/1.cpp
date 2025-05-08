#include<bits/stdc++.h>
#define int long long
using namespace std;
const long double inf=3.14159265358979;
const long double ha=2.718281828;
int n,q,vis[1009][1009],xx,yy,cnt,i,Kcnt;
struct nod{
	int x,y;
};
bool check(long double x,long double y){
	if(x>0&&x<=n&&y>0&&y<=n)return 1;
	else return 0;
}
nod a[4009],p[4009];
bool F[1000009];
long double x,y,k,b,K[4009];
bool f=0;
map<double,int>m;
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>n;q=n*n;
	for(int o=1;o<=q;o++){
		scanf("%llf%llf",&x,&y);
		xx=x;yy=y;f=0;
		if(vis[xx][yy]==1){
			continue;
		}
		else{
			Kcnt=0;m.clear();
			for(i=1;i<=cnt;i++){
				double px=p[i].x;
				double py=p[i].y;
				if(px==x){
					k=x*inf;//hash
				}
				else{
					k=(py-y)/(px-x);
					b=y-k*x;
					if(k==0)k=y*ha;//hash
					else if(b==0)k=k*ha*ha;
					else k=k*b*b;
				}
				if(m[k]==0){
					K[++Kcnt]=k;
					m[k]=1;
				}
				else{
					f=1;
					break;
				}
			}
			if(f==0){
				F[o]=1;
				cnt++;p[cnt].x=x;p[cnt].y=y;
			}
			else{
				F[o]=0;
			}
		}
	}
	for(i=1;i<=n*n;i++){
		if(F[i]==1)putchar('1');
		else putchar('0');
	}
	putchar('\n');
	fclose(stdin);fclose(stdout);
	return 0;
}
