#include<bits/stdc++.h>
using namespace std;
int i,n,a[300009];
bool fu=1,zheng=1,ling;
int main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]>0)fu=0;//全负数 
		else if(a[i]<0)zheng=0;//全正数
		else{
			ling=1;
			break;
		}
	}
	if(ling==1||(fu==0&&zheng==0)){
		printf("NO\n");
	}
	else if((fu==0&&zheng==1)||(fu==1&&zheng==0)){
		printf("YES\n");
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
