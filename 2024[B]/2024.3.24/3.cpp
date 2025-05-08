#include<bits/stdc++.h>
using namespace std;
int abc;
char c='a';
int n,k,i,a[10009],sum;
int main(){
	freopen("3.in","r",stdin);freopen("3.out","w",stdout);
	cin>>n>>k;
	a[1]=1;i=1;
	while(a[i]<=1000000){
		i++;
		a[i]=a[i-1]+i;
	}
	while(k>0){
		for(i=1000;i>=1;i--){
			if(k>=a[i]){
				sum+=(i+1);
				char b=c+abc%26;
				k-=a[i];
				for(int j=1;j<=i+1;j++)putchar(b);
				abc++;
				break;
			}
		}
	}
	for(i=sum+1;i<=n;i++){
		char b=c+abc%26;
		putchar(b);
		abc++;
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
