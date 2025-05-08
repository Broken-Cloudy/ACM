#include<bits/stdc++.h>
#define int long long
using namespace std;
string S[11];
int anss=1;
int check(string s){
	bool FF;
	int i,j,k,ans=0;
	for(i=0;i<=9;i++){
		FF=1;
		for(j=0;j<=6;j++){
			if(S[i][j]=='0'&&s[j]=='1'){
				FF=0;break;
			}
		}
		if(FF==1)ans++;
	}
	return ans;
}
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	S[0]="1111110";S[1]="0110000";S[2]="1101101";
	S[3]="1111001";S[4]="0110011";S[5]="1011011";S[6]="1011111";
	S[7]="1110000";S[8]="1111111";S[9]="1111011";
	anss*=check("0000011");
	anss*=check("1001011");
	anss*=check("0000001");
	anss*=check("0100001");
	anss*=check("0101011");
	anss*=check("0110110");
	anss*=check("1111111");
	anss*=check("0010110");
	anss*=check("0101001");
	anss*=check("0010110");
	anss*=check("1011100");
	anss*=check("0100110");
	anss*=check("1010000");
	anss*=check("0010011");
	anss*=check("0001111");
	anss*=check("0101101");
	anss*=check("0110101");
	anss*=check("1101010");
	cout<<anss<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
