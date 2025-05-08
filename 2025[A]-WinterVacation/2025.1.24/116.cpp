#include<bits/stdc++.h>
#define int long long
using namespace std;
int heap[10009];
int n,m,a[10009],i,cnt;
int x,y;
string s1,s2,s3,s4;
void Insert(int x){//小顶 
	heap[++cnt]=x;
	int now=cnt;
	while(now){
		int fa=now/2;
		if(fa==0)return;
		if(heap[fa]>heap[now]){
			swap(heap[fa],heap[now]);
		}
		else break;
		now=fa;
	}
}
void Jud2(int x,int y){//问x是不是y的父节点 
	int a,b;
	for(i=1;i<=n;i++){
		if(heap[i]==x)a=i;
		if(heap[i]==y)b=i;
	}
	if(b/2==a)printf("T\n");
	else printf("F\n");
}
void Jud3(int x,int y){//问x是不是y的一个子节点 
	int a,b;
	for(i=1;i<=n;i++){
		if(heap[i]==x)a=i;
		if(heap[i]==y)b=i;
	}
	if(a/2==b)printf("T\n");
	else printf("F\n");
}
void Jud4(int x,int y){//问是不是兄弟 
	int a,b;
	for(i=1;i<=n;i++){
		if(heap[i]==x)a=i;
		if(heap[i]==y)b=i;
	}
	if(a>b)swap(a,b);
	if((a/2)==(b/2))printf("T\n");
	else printf("F\n");
}
signed main(){
	freopen("116.in","r",stdin);freopen("116.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++)scanf("%lld",&a[i]),Insert(a[i]);
	while(m--){
		cin>>x;cin>>s1;
		if(s1=="is"){
			cin>>s2;
			if(s2=="the"){
				cin>>s3;
				if(s3=="root"){//问x是不是根 
					if(heap[1]==x)printf("T\n");
					else printf("F\n");
				}
				else{
					cin>>s4;cin>>y;
					Jud2(x,y);
				}
			}
			else{ 
				cin>>s3>>s4;cin>>y;
				Jud3(x,y);
			}
		}
		else{
			cin>>y;cin>>s2>>s3;
			Jud4(x,y);
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
