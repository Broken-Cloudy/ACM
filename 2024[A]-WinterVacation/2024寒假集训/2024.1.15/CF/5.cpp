#include<bits/stdc++.h>
using namespace std;
int T,h,w,xa,ya,xb,yb;
int flag;//flag=1 Alice Win! flag=0 Bob Win! 
int main(){
	freopen("5.in","r",stdin);freopen("5.out","w",stdout);
	cin>>T;
	for(int o=1;o<=T;o++){
		scanf("%d%d%d%d%d%d",&h,&w,&xa,&ya,&xb,&yb);
		if((xb-xa)%2==0)flag=0;
		else flag=1;
		if(xa>xb)printf("Draw\n");
		else{
			int asp=(xb-xa)/2;//×Ý¾àÀë »ØºÏ 
			if(flag==1){//Alice Win!
				if(ya>yb){
					yb-=asp;
					yb=max(yb,1);
					ya-=asp;
					ya=max(ya,1);
					if(ya-yb>=2){
						printf("Draw\n");
					}
					else printf("Alice\n");
				}
				else{
					yb+=asp;
					yb=min(yb,w);
					ya+=asp;
					ya=min(ya,w);
					if(yb-ya>=2){
						printf("Draw\n");
					}
					else printf("Alice\n");
				}
			}
			else{//Bob Win! 
				if(ya<yb){
					yb-=asp;
					yb=max(yb,1);
					ya-=asp;
					ya=max(ya,1);
					if(yb-ya>=1){
						printf("Draw\n");
					}
					else printf("Bob\n");
				}
				else{
					yb+=asp;
					yb=min(yb,w);
					ya+=asp;
					ya=min(ya,w);
					if(ya-yb>=1){
						printf("Draw\n");
					}
					else printf("Bob\n");
				}
			}
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
} 
