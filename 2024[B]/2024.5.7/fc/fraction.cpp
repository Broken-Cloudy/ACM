#include "fraction.h"
//化简
int gcd(int a,int b){
    if(b==0){
        return a;
    }
    return gcd(b,a%b);
}//辗转相除求最大公约数
void fraction::simplify(){
    if(denominator<0&&numerator>0)numerator=-numerator,denominator=-denominator;//分母为负数，负号移到分子上
    if(denominator<0&&numerator<0)numerator=-numerator,denominator=-denominator;//分母和分子为负数，负号过滤
    int GCD=gcd(max(numerator,-numerator),max(denominator,-denominator));//调用gcd函数时要取绝对值
    numerator/=GCD;denominator/=GCD;
//numerator分子
//denominator分母
}

fraction::fraction(int n,int d):integer(n),denominator(d){
    simplify();
    if (denominator!=0)
        result=numerator/denominator;
}//直接得出分数的最简式 

//将输入的字符串表达式转化为分数 
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

//判断分母是否为零 
bool fraction::normal(){

	return denominator;
}

//运算符重载 

//加法 
fraction operator+(fraction& f1,fraction& f2){
    fraction f;
    f.denominator=f1.denominator*f2.denominator;
    f.numerator=f1.numerator*f2.denominator+f2.numerator*f1.denominator;
    f.simplify();
    return f;
}

//减法 
fraction operator-(fraction& f1,fraction& f2){
    fraction f;
    f.denominator=f1.denominator*f2.denominator;
    f.numerator=f1.numerator*f2.denominator-f2.numerator*f1.denominator;
    f.simplify();
    return f;    
}

//乘法 
fraction operator*(fraction& f1,fraction& f2){
    fraction f;
    f.denominator=f1.denominator*f2.denominator;
    f.numerator=f1.numerator*f2.numerator;
    f.simplify();
    return f;
}

//除法 
fraction operator/(fraction& f1,fraction& f2){
    fraction f;
    f.denominator=f1.denominator*f2.numerator;
    f.numerator=f1.numerator*f2.denominator;
    f.simplify();
    return f;
}

//输出流重载
ostream& operator<<(ostream& cout,fraction& f){
    cout<<f.numerator;
    if (f.denominator!=1)
        cout<<'/'<<f.denominator;
    return cout;
}

//输入流重载 
istream& operator>>(istream& cin,fraction& f){
    string str;
    cin>>str;
    f=str;
    return cin;
}
