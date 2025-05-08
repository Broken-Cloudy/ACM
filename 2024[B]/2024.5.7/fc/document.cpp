#include "document.h"

expression ex[10];
bool read_flag=false;//记录是否读取，减少读取次数

void read(){
	freopen("database.txt","r",stdin);
    for (int i=0;i<10;i++){
        cin>>ex[i].fraction1;
        cin>>ex[i].sign;
        cin>>ex[i].fraction2;
        cin>>ex[i].result;
    }
    fclose(stdin);
    cin.clear();
	freopen("CON","r",stdin);

    read_flag=true;   
}

void database_write(expression &ex_){
    if (~read_flag)
        read();
    for (int i=0;i<9;i++)
        ex[i]=ex[i+1];
    ex[9]=ex_;

    freopen("database.txt","w",stdout);
    for (int i=0;i<10;i++){
        cout<<ex[i].fraction1;
        cout<<ex[i].sign;
        cout<<ex[i].fraction2;
        cout<<ex[i].result<<endl;
    }

    
    fclose(stdout);
    cin.clear();
    freopen("CON","w",stdout);
    
}

void database_clear(){
    freopen("database.txt","w",stdout);

    fclose(stdout);
    cin.clear();
    freopen("CON","w",stdout);
    
    read();
}

void database_show(){
    if (~read_flag)
        read();
    for (int i=0;i<10;i++){
        cout<<'\t'<<ex[i].fraction1<<' ';
        cout<<'\t'<<ex[i].sign<<' ';
        cout<<'\t'<<ex[i].fraction2<<" = ";
        cout<<'\t'<<ex[i].result<<endl;
    }
}
