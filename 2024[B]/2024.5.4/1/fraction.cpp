#include "fraction.h"

void fraction::simplify(){//化简
//numerator分子
//denominator分母
}

fraction::fraction(int n,int d):integer(n),denominator(d){
    simplify();
    if (denominator!=0)
        result=numerator/denominator;
}

fraction::fraction(string& str){
    string str1,str2;
    int i=0,length=str.length();

    while (str[i]!='/' && i<=length){
        str1+=str[i];
        i++;
    }
    istringstream n(str1);
    n>>numerator;

    i++;

    while (str[i]!='\0' && i<=length){
        str2+=str[i];
        i++;
    }
    istringstream d(str2);
    denominator=1;
    d>>denominator;

    simplify();
    if (denominator!=0)
        result=numerator/denominator;    
}

bool fraction::normal(){
    return denominator;
}

fraction operator+(fraction& f1,fraction& f2){
    fraction f;


    f.simplify();
    return f;
}

fraction operator-(fraction& f1,fraction& f2){
    fraction f;


    f.simplify();
    return f;    
}

fraction operator*(fraction& f1,fraction& f2){
    fraction f;


    f.simplify();
    return f;
}

fraction operator/(fraction& f1,fraction& f2){
    fraction f;


    f.simplify();
    return f;
}

ostream& operator<<(ostream& cout,fraction& f){
    cout<<f.numerator;
    if (f.denominator!=1)
        cout<<'/'<<f.denominator;
    return cout;
}

istream& operator>>(istream& cin,fraction& f){
    string str;
    cin>>str;
    f=str;
    return cin;
}