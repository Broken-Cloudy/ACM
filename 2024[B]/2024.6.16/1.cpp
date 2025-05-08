#include<bits/stdc++.h>
using namespace std;
char cc[100009],ans[100009],last1,last2;
int n,i,jud,c[100009];
int main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>n;getchar();
	for(i=1;i<=n;i++){
		cc[i]=getchar();
		c[i]=cc[i]-'0';
	}
	jud=1;
	if(n%2==0){
		last1='C';last2='B';
	}
	else{
		last1='C';last2='A';
	}
	for(i=1;i<=n;i++){
		if(c[i]==jud){
			ans[n-i+1]=last1;
			jud=c[i];
			if(last2=='A'&&last1=='C')last2='B';
			else if(last2=='A'&&last1=='B')last2='C';
			else if(last2=='B'&&last1=='C')last2='A';
			else if(last2=='B'&&last1=='A')last2='C';
			else if(last2=='C'&&last1=='A')last2='B';
			else if(last2=='C'&&last1=='B')last2='A';
		}
		else{
			ans[n-i+1]=last2;
			jud=c[i];
			if(last2=='A'&&last1=='C')last1='A',last2='B';
			else if(last2=='A'&&last1=='B')last1='A',last2='C';
			else if(last2=='B'&&last1=='C')last1='B',last2='A';
			else if(last2=='B'&&last1=='A')last1='B',last2='C';
			else if(last2=='C'&&last1=='A')last1='C',last2='B';
			else if(last2=='C'&&last1=='B')last1='C',last2='A';
		}
	}
	for(i=1;i<=n;i++)putchar(ans[i]);
	putchar('\n');
	fclose(stdin);fclose(stdout);
	return 0;
}
