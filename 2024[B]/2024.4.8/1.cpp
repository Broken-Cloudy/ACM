#include<bits/stdc++.h>
using namespace std;
class Constants{
	public:
		static double getPI(){
			return 3.1416;
		}
};
Constants constants;
int main(){
	//freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cout<<constants.getPI()<<endl;
	cout<<Constants::getPI()<<endl;
	//fclose(stdin);fclose(stdout);
	return 0;
}
