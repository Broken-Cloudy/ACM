#include<bits/stdc++.h>
using namespace std;
string s1,s2,s,a[29];
int i,n,j;
bool f=0;
int main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>n;
	a[1]="lunar lobster";a[2]="kinetic kudu";a[3]="jammy jellyfish";
	a[4]="impish indri";a[5]="hirsute hippo";a[6]="groovy gorilla";
	a[7]="focal fossa";a[8]="eoan ermine";a[9]="disco dingo";
	a[10]="cosmic cuttlefish";a[11]="bionic beaver";a[12]="artful aardvark";
	a[13]="zesty zapus";a[14]="yakkety yak";a[15]="xenial xerus";
	a[16]="wily werewolf";a[17]="vivid vervet";a[18]="utopic unicorn";
	a[19]="trusty tahr";a[20]="saucy salamander";
	for(i=1;i<=n;i++){
		cin>>s1>>s2;f=0;
		if(s1[0]>='A'&&s1[0]<='Z')s1[0]=s1[0]-'A'+'a';
		if(s2[0]>='A'&&s2[0]<='Z')s2[0]=s2[0]-'A'+'a';
		if(s1[0]==s2[0]&&((s1[0]>='a'&&s1[0]<='l')||s1[0]>='s'&&s1[0]<='z')){
			printf("Yes\n");
		}
		else{
			printf("No\n");
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
