#include "fraction.h"
//����
int gcd(int a,int b){
    if(b==0){
        return a;
    }
    return gcd(b,a%b);
}//շת��������Լ��
void fraction::simplify(){
    if(denominator<0&&numerator>0)numerator=-numerator,denominator=-denominator;//��ĸΪ�����������Ƶ�������
    if(denominator<0&&numerator<0)numerator=-numerator,denominator=-denominator;//��ĸ�ͷ���Ϊ���������Ź���
    int GCD=gcd(max(numerator,-numerator),max(denominator,-denominator));//����gcd����ʱҪȡ����ֵ
    numerator/=GCD;denominator/=GCD;
//numerator����
//denominator��ĸ
}

fraction::fraction(int n,int d):integer(n),denominator(d){
    simplify();
    if (denominator!=0)
        result=numerator/denominator;
}//ֱ�ӵó����������ʽ 

//��������ַ������ʽת��Ϊ���� 
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

//�жϷ�ĸ�Ƿ�Ϊ�� 
bool fraction::normal(){

	return denominator;
}

//��������� 

//�ӷ� 
fraction operator+(fraction& f1,fraction& f2){
    fraction f;
    f.denominator=f1.denominator*f2.denominator;
    f.numerator=f1.numerator*f2.denominator+f2.numerator*f1.denominator;
    f.simplify();
    return f;
}

//���� 
fraction operator-(fraction& f1,fraction& f2){
    fraction f;
    f.denominator=f1.denominator*f2.denominator;
    f.numerator=f1.numerator*f2.denominator-f2.numerator*f1.denominator;
    f.simplify();
    return f;    
}

//�˷� 
fraction operator*(fraction& f1,fraction& f2){
    fraction f;
    f.denominator=f1.denominator*f2.denominator;
    f.numerator=f1.numerator*f2.numerator;
    f.simplify();
    return f;
}

//���� 
fraction operator/(fraction& f1,fraction& f2){
    fraction f;
    f.denominator=f1.denominator*f2.numerator;
    f.numerator=f1.numerator*f2.denominator;
    f.simplify();
    return f;
}

//���������
ostream& operator<<(ostream& cout,fraction& f){
    cout<<f.numerator;
    if (f.denominator!=1)
        cout<<'/'<<f.denominator;
    return cout;
}

//���������� 
istream& operator>>(istream& cin,fraction& f){
    string str;
    cin>>str;
    f=str;
    return cin;
}
