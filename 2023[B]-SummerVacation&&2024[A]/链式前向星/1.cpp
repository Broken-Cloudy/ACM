#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
long long ans,b[400010],sum;
int i,n,m,a1,a2,a3,fir[400010],cnt,flag,check;
struct nod{
    int u,v,c,next;
};
nod a[400010];
bool f[400010];
void add(int u,int v,int c){
    a[++cnt].next=fir[u];
    fir[u]=cnt;
    a[cnt].u=u;
    a[cnt].v=v;
    a[cnt].c=c;
}
void dfs(int x){
	int i;
    for(i=fir[x];i;i=a[i].next){
        if(f[a[i].v]==0){
            f[a[i].v]=1;
            b[a[i].v]=b[a[i].u]^a[i].c;
            dfs(a[i].v);
        }
    }
}
int main(){
	n=4;m=2;
	add(1,2,1);add(2,1,1);add(3,4,6);add(4,3,6);
    /*cin>>n>>m;
    for(i=1;i<=m;i++){
        scanf("%d%d%d",&a1,&a2,&a3);
        add(a1,a2,a3);add(a2,a1,a3);
    }*/
    for(i=1;i<=cnt;i++){
    	b[a[i].u]=0;b[a[i].v]=a[i].c;
    	f[a[i].u]=1;f[a[i].v]=1;
  	 	dfs(a[i].u);dfs(a[i].v);
	}
    for(i=1;i<=n;i++){
        ans+=b[i];
    }
    memset(b,0,sizeof(b));memset(f,0,sizeof(f));
    
    for(i=1;i<=cnt;i++){
		b[a[i].u]=a[i].c;b[a[i].v]=0;
	    f[a[i].u]=1;f[a[i].v]=1;
	    dfs(a[i].u);dfs(a[i].v);
	}
    for(i=1;i<=n;i++){
        sum+=b[i];
    }
    for(i=1;i<=cnt;i++){
    	check=b[a[i].u]^b[a[i].v];
    	if(check!=a[i].c){
    		cout<<-1<<endl;
    		return 0;
		}
	}
    cout<<min(ans,sum)<<endl;
    return 0;
}
