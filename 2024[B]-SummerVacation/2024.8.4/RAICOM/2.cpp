#include<bits/stdc++.h>
#define int long long
using namespace std;
struct nod{
	int c,p;
};
nod a[59],b[59];
int n,i,ha[59];
bool cmp(nod x,nod y){
	if(x.p==y.p)return x.c<y.c;
	else return x.p>y.p;
}
int sco(int x){
	if(x==1){return 25;}
	else if(x==2){return 21;}
	else if(x==3){return 18;}
	else if(x==4){return 16;}
	else if(x==5){return 15;}
	else if(x==6){return 14;}
	else if(x==7){return 13;}
	else if(x==8){return 12;}
	else if(x==9){return 11;}
	else if(x==10){return 10;}
	else if(x==11){return 9;}
	else if(x==12){return 8;}
	else if(x==13){return 7;}
	else if(x==14){return 6;}
	else if(x==15){return 5;}
	else if(x==16){return 4;}
	else if(x==17){return 3;}
	else if(x==18){return 2;}
	else if(x==19){return 1;}
	else if(x==20){return 0;}
}
signed main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>n;
	for(i=1;i<=30;i++){
		b[i].c=i;
	}
	while(n--){
		for(i=1;i<=20;i++){
			scanf("%lld%lld",&a[i].c,&a[i].p);
			ha[a[i].c]=1;
		}
		for(i=1;i<=20;i++){
			b[a[i].c].p+=sco(a[i].p);
		}
	}
	sort(b+1,b+1+30,cmp);
	for(i=1;i<=30;i++){
		if(ha[i]!=0){
			printf("%lld %lld\n",b[i].c,b[i].p);
		}
		else{
			printf("%lld\n",b[i].c);
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
