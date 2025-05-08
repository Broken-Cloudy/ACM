#include<bits/stdc++.h>
using namespace std;
string s[109],c;
int i,j,q;
int main(){
	s[1]="Mike";s[2]="Jack";s[3]="Joker";s[4]="Tom";s[5]="Crazy Dave";
	s[6]="Chaoxing";s[7]="Tencent";s[8]="Jackson";s[9]="Rock";s[10]="Google";
	s[11]="DP";s[12]="Kun";s[13]="Orz";s[14]="Alice";s[15]="Bob";
	s[16]="Dijkstra";s[17]="FFT";s[18]="NTT";s[19]="GCD";s[20]="EXGCD";
	cin>>q;
	for(i=1;i<=q;i++){
		cin>>c;
		for(j=1;j<=20;j++){
			if(s[j]==c){
				puts("Yes");
				break;
			}
		}
		if(j==21)puts("No");
	}
	return 0;
}
