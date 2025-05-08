#include<bits/stdc++.h>
using namespace std;
int n,x,y,i,j;
struct nod{
	int bh,num;
};
nod a[109];
int check(int x){
	if(x==1)return 12;
	else if(x==2){
		return 9;
	}
	else if(x==3){
		return 7;
	}
	else if(x==4){
		return 5;
	}
	else if(x==5){
		return 4;
	}
	else if(x>=6&&x<=7){
		return 3;
	}
	else if(x>=8&&x<=10){
		return 2;
	}
	else if(x>=11&&x<=15){
		return 1;
	}
	else return 0;
}
int main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++){
		for(j=1;j<=20;j++){
			scanf("%d%d",&x,&y);
			a[j].num+=check(x)+y;
			a[j].bh=j;
		}
	}
	for(i=1;i<=20;i++){
		printf("%d %d\n",a[i].bh,a[i].num);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
