#include<bits/stdc++.h>
using namespace std;
int a[200009],n,i,b[200009],getin,bh1,bh2,getout;
bool f;
int main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++)scanf("%d",&a[i]);
	getin=a[1];bh1=1;a[n+1]=1099999999;
	for(i=2;i<=n+1;i++){
		if(f==0){//getin//’“¥Û 
			if(a[i]>getin){
				getin=a[i];
				b[bh1]=-1;
				bh1=i;
			}
			else{
				b[bh1]=1;
				getout=a[i];
				bh2=i;
				f=1;
			}
		}
		else{//’“–°
			if(a[i]<getout){
				getout=a[i];
				b[bh2]=-1;
				bh2=i;
			}
			else{
				b[bh2]=1;
				getin=a[i];
				bh1=i;
				f=0;
			}
		}
	}
	for(i=1;i<=n;i++){
		if(b[i]==1)printf("1");
		else printf("0");
		if(i<n)putchar(' ');
		else putchar('\n');
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
