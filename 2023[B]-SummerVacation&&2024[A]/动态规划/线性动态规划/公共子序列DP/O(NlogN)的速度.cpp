#include<bits/stdc++.h>
using namespace std;
int a[100010],b[100010],s[100010],n,i;
int len,f[100010];
int main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	memset(f,0x7f,sizeof(f));
	cin>>n;
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
		s[a[i]]=i;
	}
	for(i=1;i<=n;i++){
		scanf("%d",&b[i]);
	}
	f[0]=0;
	for(i=1;i<=n;i++){
		int l=0,r=len,mid;
		if(s[b[i]]>f[len])f[++len]=s[b[i]];
		else{
			while(l<=r){
				if(l==r){
					f[l]=min(f[l],s[b[i]]);                                             
					break;
				}
				mid=(l+r)/2;
				if(s[b[i]]<f[mid])r=mid;
				else l=mid+1;
			}
		}
	}
	cout<<len<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
