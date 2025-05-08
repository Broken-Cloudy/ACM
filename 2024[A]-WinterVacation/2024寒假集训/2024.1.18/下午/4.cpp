#include<bits/stdc++.h>
using namespace std;
int a[100009],g,gg,group,n,i,grp[100009],cnt,fir[100009];
struct nod{
	int bh;
	char s[11];
	int next;
};
nod gr[100009];
char c;
int main(){
	freopen("4.in","r",stdin);freopen("4.out","w",stdout);
	cin>>n;gg=1;
	for(i=1;i<=n;i++){
		getchar();
		c=getchar();
		if(c=='A'){
			scanf("%d",&group);
			if(grp[group]==0){
				a[++g]=group;
				grp[group]++;
				//add
				cnt++;
				fir[group]=cnt;
				gr[cnt].bh=group;
				scanf("%s",gr[cnt].s+1);
			}
			else{
				grp[group]++;
				cnt++;
				gr[cnt].next=fir[group];
				fir[group]=cnt;//last更新 但first不更新 
				gr[cnt].bh=group;
				scanf("%s",gr[cnt].s+1);
			}
		}
		else{
			if(gg>g)printf("no one\n");
			else{
				if(grp[a[gg]]==1){
					grp[a[gg]]--;
					int u=fir[a[gg]];
					printf("%d ",gr[u].bh);
					printf("%s\n",gr[u].s+1);
					gg++;
				}
				else{
					grp[a[gg]]--;//a[gg]存组 
					int u=fir[a[gg]];
					int v=gr[u].next;
					printf("%d ",gr[u].bh);
					printf("%s\n",gr[u].s+1);
					fir[a[gg]]=v;//换下一个 
				}
			}
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
