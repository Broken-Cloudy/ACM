#include<iostream>
using namespace std;
class Sample{
	public:
		int v;
		Sample(){}//Ĭ�Ϲ��캯��,δָ����ʼ��ֵ
		Sample(int x):v(x){}//�������Ĺ��캯��,��ʼ��vΪ����Ĳ���x
		Sample(Sample &s){//�������캯��,����һ��Sample�����������Ϊ����
			v=s.v+2;//���¶����v����Ϊ��������v��2
		}
};
void PrintAndDouble(Sample o){
	cout<<o.v;//�������o��vֵ
	cout<<endl;//���� 
}
int main(){
	Sample a(5);//����һ��Sample����a��ʹ�ô������Ĺ��캯����ʼ��vΪ5
	Sample b=a;//ʹ�ÿ������캯����������b��������a�����ݸ��Ƹ�b
	PrintAndDouble(b);//����PrintAndDouble�����������b��vֵ������
	Sample c(20);//����һ��Sample����c��ʹ�ô������Ĺ��캯����ʼ��vΪ20
	PrintAndDouble(c);//����PrintAndDouble�����������c��vֵ������
	Sample d;//����һ��Sample����d��ʹ��Ĭ�Ϲ��캯����ʼ��
	d=a;//������a�����ݸ��Ƹ�����d
	cout<<d.v<<endl;//��ӡ����d��vֵ������
	return 0;
}
