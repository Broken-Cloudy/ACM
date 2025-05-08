#include<bits/stdc++.h>
using namespace std;
char s1[200009],s2[200009];
int n,m,q,i,l1,r1,l2,r2,x[9],w1,w2,f,w;
int main(){
	freopen("9.in","r",stdin);freopen("9.out","w",stdout);
	cin>>n>>m>>q;
	scanf("%s",s1+1);scanf("%s",s2+1);
	for(int u=1;u<=q;u++){
		scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
		w=(r1-l1)/13800;
		if(w==0)w=1;
		f=0;
		for(i=0;i<=13800&&l1+w*i<=r1;i++){
			if(s1[l1+w*i]!=s2[l2+w*i]){
				if(s1[l1+w*i]<s2[l2+w*i]){
					f=1;
					printf("<\n");
					break;
				}
				else{
					f=1;
					printf(">\n");
					break;
				}
			}
		}
		if(f==0){
			printf("=\n");
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
