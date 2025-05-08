#include<bits/stdc++.h>
using namespace std;
int a[10009],b[10009],n,ff=1,i;
int main(){
	freopen("7.in","r",stdin);freopen("7.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(i=1;i<=n;i++){
		scanf("%d",&b[i]);
	}
	for(i=1;i<=n;i++){
		if(a[i]>b[i]){
			ff=0;//´óÊ¤Àû 
			break;
		}
	}
	sort(a+1,a+1+n);sort(b+1,b+1+n);
	if(a[n]<=b[1]){
		ff=2;//Ê§°Ü 
	}
	if(ff==0){
		cout<<"WinWinWin!!!"<<endl;
	}
	else if(ff==1){
		cout<<"HaHa"<<endl;
	}
	else{
		cout<<"AreYouOK?"<<endl;
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
