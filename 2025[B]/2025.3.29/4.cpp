#include<bits/stdc++.h>
#define int long long
using namespace std;
int Q,i,n,T,L,I,A,B,C,ans[209],kk,f,j;
char s[109],tt,ll,ii;
signed main(){
	freopen("4.in","r",stdin);freopen("4.out","w",stdout);
	cin>>Q;
	while(Q--){
		scanf("%lld",&n);getchar();
		for(i=1;i<=n;i++)s[i]=getchar();
		T=I=L=0;
		for(i=1;i<=n;i++){
			if(s[i]=='T')T++;
			else if(s[i]=='L')L++;
			else I++;
		}
		if(T==I&&T==L&&L==I){
			printf("0\n");
			continue;
		}
		else if(T==0&&L==0||T==0&&I==0||I==0&&L==0){
			printf("-1\n");
			continue;
		}
		else{
			//A<=B<=C
			if(T==I){
				if(T<L){
					ll='C';tt='B';ii='A';
				}
				else{
					ll='A';tt='B';ii='C';
				}
			}
			else if(T==L){
				if(T<I){
					ll='A';tt='B';ii='C';
				}
				else{
					ll='C';tt='B';ii='A';
				}
			}
			else if(I==L){
				if(I<T){
					ll='A';tt='C';ii='B';
				}
				else{
					ll='C';tt='A';ii='B';
				}
			}
			else{
				if(T<L&&L<I){
					ll='B';tt='A';ii='C';
				}
				else if(L<T&&T<I){
					ll='A';tt='B';ii='C';
				}
				else if(I<L&&L<T){
					ll='B';tt='C';ii='A';
				}
				else if(L<I&&I<T){
					ll='A';tt='C';ii='B';
				}
				else if(I<T&&T<L){
					ll='C';tt='B';ii='A';
				}
				else{
					ll='C';tt='A';ii='B';
				}
			}
		}
		for(i=1;i<=n;i++){
			if(s[i]=='T')s[i]=tt;
			else if(s[i]=='L')s[i]=ll;
			else s[i]=ii;
		}
		A=B=C=0;
		for(i=1;i<=n;i++){
			if(s[i]=='A')A++;
			else if(s[i]=='B')B++;
			else C++;
		}
		ans[0]=0;f=0;
		for(i=1;i<n;i++){
			if(s[i]=='C'&&s[i+1]=='B')f=1;
			if(s[i]=='B'&&s[i+1]=='C')f=1;
		}
		if(f==0){
			if(A==B){
				for(i=1;i<=n;i++){
					if(s[i]=='A')s[i]='B';
					else if(s[i]=='B')s[i]='A';
				}
			}
			else{
				for(i=1;i<n;i++){
					if(s[i]=='B'&&s[i+1]=='A'||s[i]=='A'&&s[i+1]=='B'){
						ans[++ans[0]]=i;
						s[n+1]='C';C++;
						for(j=n+1;j>i+1;j--)swap(s[j],s[j-1]);
						n++;
						break;
					}
				}
			}
		}
		for(i=1;i<n;i++){
			kk=i;
			if(s[i]=='C'&&s[i+1]=='B'){
				while(B<C){
					B++;A++;
					ans[++ans[0]]=i;ans[++ans[0]]=i;
				}
				if(A<B){
					A++;
					ans[++ans[0]]=kk;
					kk++;
					while(A<B){
						A++;
						ans[++ans[0]]=kk;
						ans[++ans[0]]=kk-1;
						kk++;
						ans[++ans[0]]=kk+1;
						ans[++ans[0]]=kk-2;
						kk--;
					}
				}
				break;
			}
			else if(s[i]=='B'&&s[i+1]=='C'){
				while(B<C){
					B++;A++;
					ans[++ans[0]]=kk;
					kk++;
					ans[++ans[0]]=kk;
					kk++;
				}
				if(A<B){
					A++;
					ans[++ans[0]]=kk;
					kk++;
					while(A<B){
						A++;
						ans[++ans[0]]=kk;
						ans[++ans[0]]=kk-1;
						kk++;
						ans[++ans[0]]=kk+1;
						ans[++ans[0]]=kk-2;
						kk--;
					}
				}
				break;
			}
		}
		printf("%lld\n",ans[0]);
		for(i=1;i<=ans[0];i++){
			printf("%lld\n",ans[i]);
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
