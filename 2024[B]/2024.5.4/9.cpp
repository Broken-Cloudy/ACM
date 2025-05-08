#include<bits/stdc++.h>
using namespace std;
int n,m,i,wrong1=-1,wrong2=-1,vis[19],cnt,j;
int dui1[3],dui2[3];
int NUM[109];
struct nod{
	string num;
	int same,right;
};
nod a[109];
bool cmp(nod x,nod y){
	if(x.same==y.same)return (x.right+x.same)<(y.right+y.same);
	return x.same>y.same;
}
int main(){
	freopen("9.in","r",stdin);freopen("9.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++){
		cin>>a[i].num>>a[i].same>>a[i].right;
	}
	sort(a+1,a+1+n,cmp);
	if(a[1].same==m){//m
		cout<<a[1].num;
	}
	else if(a[1].same==m-1&&a[2].same==m-1){//m-1
		for(i=0;i<m;i++){
			if(a[1].num[i]==a[2].num[i]){
				NUM[i]=a[1].num[i]-'0';
				cnt++;
				vis[a[1].num[i]-'0']=1;
			}
			else{
				if(wrong1==-1){
					wrong1=i;
					dui1[1]=a[1].num[i];
					dui1[2]=a[2].num[i];
				}
				else{
					wrong2=i;
					dui2[1]=a[1].num[i];
					dui2[2]=a[2].num[i];
				}
			}
		}
		if(wrong2==-1){
			
		}
		else{
			
		}
		for(i=0;i<m;i++){
			cout<<NUM[i];
		}
	}
	else{
		
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
