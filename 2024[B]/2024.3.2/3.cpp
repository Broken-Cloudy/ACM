#include<bits/stdc++.h>
using namespace std;
int T,n,m,dis1,dis2;
bool find(int k,int dis,int ff){
	int diss;
	if(k>=n){//ÏÂ°ë 
		int weiyi=k-(n-1);
		if((dis-weiyi)%2==0){
			dis-=weiyi;
			int x=n;
			int y=1+weiyi;
			x-=(dis/2);
			y+=(dis/2);
			if(ff==1){
				cout<<'?'<<' '<<x<<' '<<y<<endl;
				cout.flush();
			}
			else{
				cout<<'!'<<' '<<x<<' '<<y<<endl;
				cout.flush();
				return 1;
			}
			cout.flush();
			cin>>diss;
			if(diss==0){
				cout<<'!'<<' '<<x<<' '<<y<<endl;
				cout.flush();
				return 1;
			}
			else{
				return 0;
			}
		}
		else{
			return 0;//Ê§°Ü 
		}
	}
	else{
		int weiyi=(n-1)-k;
		if((dis-weiyi)%2==0){
			int x=1+k;
			int y=1;
			x-=(dis/2);
			y+=(dis/2);
			if(ff==1){
				cout<<'?'<<' '<<x<<' '<<y<<endl;
				cout.flush();
			}
			else{
				cout<<'!'<<' '<<x<<' '<<y<<endl;
				cout.flush();
				return 1;
			}
			cin>>diss;
			if(diss==0){
				cout<<'!'<<' '<<x<<' '<<y<<endl;
				cout.flush();
				return 1;
			}
			else{
				return 0;
			}
		}
		else{
			return 0;//Ê§°Ü 
		}
	}
}
int main(){
	freopen("3.in","r",stdin);freopen("3.out","w",stdout);
	cin>>T;
	for(int o=1;o<=T;o++){
		cin>>n>>m;
		cout<<'?'<<' '<<1<<' '<<1<<endl;
		cout.flush();
		cin>>dis1;
		cout<<'?'<<' '<<n<<' '<<m<<endl;
		cout.flush();
		cin>>dis2;
		if(dis1==0){
			cout<<'!'<<' '<<1<<' '<<1<<endl;
			cout.flush();
		}
		else if(dis2==0){
			cout<<'!'<<' '<<n<<' '<<m<<endl;
			cout.flush();
		}
		else{
			int dis;
			cout<<'?'<<' '<<n<<' '<<1<<endl;
			cout.flush();
			cin>>dis;
			if(find(dis1,dis,1)){
				cout.flush();
				continue;
			}
			else{
				find(dis2,dis,2);
				cout.flush();
			}
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
