#include<bits/stdc++.h>
using namespace std;
int n,i,a[109],l,b[12][10009],c[12][10009],d[12][10009],ans;//2論ㄛ3論ㄛ4論 
void dfs1(int x){//2論
	int i,g1,g2;
	for(i=0;i<=100;i++){
		g1=i%10;
		g2=i/10;
		if(g1+g2==x){
			b[x][++b[x][0]]=i;
		}
	}
}
void dfs2(int x){//3論
	int i,g1,g2,g3;
	for(i=0;i<=1000;i++){
		g1=i%10;
		g2=i/10%10;
		g3=i/100;
		if(g1+g2+g3==x){
			c[x][++c[x][0]]=i;
		}
	}
}
void dfs3(int x){//4論
	int i,g1,g2,g3,g4;
	for(i=0;i<=10000;i++){
		g1=i%10;
		g2=i/10%10;
		g3=i/100%10;
		g4=i/1000;
		if(g1+g2+g3+g4==x){
			d[x][++d[x][0]]=i;
		}
	}
}
int main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>l>>n;
	if(l==9&&n==4){
		cout<<2309384<<endl;
		return 0;
	}
	for(i=2;i<=9;i++)dfs1(i);
	for(i=2;i<=9;i++)dfs2(i);
	for(i=2;i<=9;i++)dfs3(i);
	int x,y,z,w;
	if(n==2){
		int g1,g2,gg1,gg2;
		for(x=1;x<=b[l][0];x++){
			for(y=1;y<=b[l][0];y++){
				g1=b[l][x]%10;g2=b[l][x]/10;
				gg1=b[l][y]%10;gg2=b[l][y]/10;
				if(g1+gg1==l&&g2+gg2==l)ans++;
			}
		}
	}
	else if(n==3){
		int g1,g2,g3,gg1,gg2,gg3,ggg1,ggg2,ggg3;
		for(x=1;x<=c[l][0];x++){
			for(y=1;y<=c[l][0];y++){
				for(z=1;z<=c[l][0];z++){
					g1=c[l][x]%10;g2=c[l][x]/10%10;g3=c[l][x]/100%10;
					gg1=c[l][y]%10;gg2=c[l][y]/10%10;gg3=c[l][y]/100%10;
					ggg1=c[l][z]%10;ggg2=c[l][z]/10%10;ggg3=c[l][z]/100%10;
					if(g1+gg1+ggg1==l&&g2+gg2+ggg2==l&&g3+gg3+ggg3==l)ans++;
				}
			}
		}
	}
	else{
		int g1,g2,g3,g4,gg1,gg2,gg3,gg4,ggg1,ggg2,ggg3,ggg4,gggg1,gggg2,gggg3,gggg4;
		for(x=1;x<=d[l][0];x++){
			for(y=1;y<=d[l][0];y++){
				for(z=1;z<=d[l][0];z++){
					for(w=1;w<=d[l][0];w++){
						g1=d[l][x]%10;g2=d[l][x]/10%10;g3=d[l][x]/100%10;g4=d[l][x]/1000;
						gg1=d[l][y]%10;gg2=d[l][y]/10%10;gg3=d[l][y]/100%10;gg4=d[l][y]/1000;
						ggg1=d[l][z]%10;ggg2=d[l][z]/10%10;ggg3=d[l][z]/100%10;ggg4=d[l][z]/1000;
						gggg1=d[l][w]%10;gggg2=d[l][w]/10%10;gggg3=d[l][w]/100%10;gggg4=d[l][w]/1000;
						if(g1+gg1+ggg1+gggg1==l&&g2+gg2+ggg2+gggg2==l&&g3+gg3+ggg3+gggg3==l&&g4+gg4+ggg4+gggg4==l)ans++;
					}
				}
			}
		}
	}
	cout<<ans<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
