#include<bits/stdc++.h>
using namespace std;
int main(){
	float score[10];
	int i,cnt=0;
	float sum=0, aver=0;
	for(i=0;i<10;i++){
		cin>>score[i];
	}
	for(i=0;i<10;i++){
		if(score[i]>=60){
			cnt++;
		}
		sum+=score[i];
	}
	aver=sum/10;
	cout<<"����������У�"<<cnt<<endl;
	cout<<"ƽ���ɼ�"<<aver<<endl;
	return 0;
}
