#include<bits/stdc++.h>
using namespace std;
int T;
int main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>T;
	for(int o=1;o<=T;o++){
		int x1,x2,x3,x4,y1,y2,y3,y4;
		scanf("%d%d",&x1,&y1);
		scanf("%d%d",&x2,&y2);
		scanf("%d%d",&x3,&y3);
		scanf("%d%d",&x4,&y4);
		if(x1!=x2)printf("%d\n",(x1-x2)*(x1-x2));
		else printf("%d\n",(x1-x3)*(x1-x3));
	}
	fclose(stdin);fclose(stdout);
	return 0;
} 
