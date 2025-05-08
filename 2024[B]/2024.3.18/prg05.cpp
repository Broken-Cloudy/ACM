#include<iostream>
#include<cstdio>
using namespace std;
void Sum(int a[][4],int row){
	if(row==0)return;
	row--;
	int i,ans=0;
	for(i=0;i<4;i++){
		ans+=a[row][i];
	}
	a[row][0]=ans;
	Sum(a,row);
}
int main(){
	int i;
	int result=0;
	int table[3][4]={{1,2,3,4},{2,3,4,5},{3,4,5,6}};
	Sum(table,3);
	for(i=0;i<3;i++){
		result=result+table[i][0];
	}
	cout<<result<<endl;
	return 0;
}
