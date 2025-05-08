#include<bits/stdc++.h>
using namespace std;
const long long inf=1000000007;
long long a[2000009],b[2000009],power[2000009];
int n,m,q,i,l1,l2,r1,r2,ans;
char s1[2000009],s2[2000009];
void work(int L,int R){//1表示大于 0表示小于 
	if(L==R){
		if(s1[l1+L]>s2[l2+L])ans=1;
		else ans=0;
		return;
	}
	else{
		int mid=(L+R)/2;
		int L1=l1+L,L2=l2+L;
		int R1=l1+R,R2=l2+R;
		int mid1=(L1+R1)/2;int mid2=(L2+R2)/2;
		long long k1=(a[mid1]+inf-a[L1-1]*power[mid1-L1+1]%inf)%inf;
		long long k2=(b[mid2]+inf-b[L2-1]*power[mid2-L2+1]%inf)%inf;
		long long k3=(a[R1]+inf-a[(mid1+1)-1]*power[R1-(mid1+1)+1]%inf)%inf;
		long long k4=(b[R2]+inf-b[(mid2+1)-1]*power[R2-(mid2+1)+1]%inf)%inf;
		if(k1!=k2){
			work(L,mid);
		}
		else{
			work(mid+1,R);
		}
	}
}
int main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>n>>m>>q;
	scanf("%s",s1+1);scanf("%s",s2+1);
	for(i=1;i<=n;i++){
		a[i]=a[i-1]*26+s1[i]-'a';
		a[i]%=inf;
	}
	for(i=1;i<=m;i++){
		b[i]=b[i-1]*26+s2[i]-'a';
		b[i]%=inf;
	}
	power[0]=1;
	for(i=1;i<=2000000;i++)power[i]=(power[i-1]*26)%inf;
	for(int o=1;o<=q;o++){
		scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
		long long k1=(a[r1]+inf-a[l1-1]*power[r1-l1+1]%inf)%inf;
		long long k2=(b[r2]+inf-b[l2-1]*power[r2-l2+1]%inf)%inf;
		if(k1==k2){
			putchar('=');
			putchar('\n');
		}
		else{
			work(0,r1-l1);
			if(ans==1){//1
				putchar('>');
				putchar('\n');
			}
			else{//0
				putchar('<');
				putchar('\n');
			}
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
