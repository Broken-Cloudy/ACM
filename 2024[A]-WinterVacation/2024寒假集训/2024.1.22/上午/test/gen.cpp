#include<stdio.h>
#include<string.h>
#include<random>
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int word;
typedef unsigned char byte;
std::mt19937_64 RAND(std::random_device{}());
typedef std::uniform_int_distribution<int> uni;
int main(){
	uni u9(-5,5);
	//while(1){
		const word n=8,m=7;
		printf("n=%u m=%u\n",n,m);
		FILE *f=fopen("elf.in","w");
		fprintf(f,"%u %u\n",n,m);
		for(word i=1;i<=n;++i)
			fprintf(f,"%d ",u9(RAND));
		fprintf(f,"\n");
		uni un(1,n);
		for(word i=1;i<=m;++i){
			int opt=uni(1,3)(RAND),l=un(RAND),r=un(RAND);
			if(l>r) std::swap(l,r);
			fprintf(f,"%d %d %d",opt,l,r);
			if(opt==1) fprintf(f," %d",u9(RAND));
			fprintf(f,"\n");
		}
		fclose(f);
		//system("time ./std");
	//}
	return 0;
}