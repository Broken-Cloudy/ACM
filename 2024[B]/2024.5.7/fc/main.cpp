#include <iostream> 
#include "fraction.h"
#include "document.h"
using namespace std;

int main(){
    expression expr;
	int choice;//�������������־��
    bool circulation=true;//ѭ����־��

    // database_show();
    // database_show();

    while(circulation){
        cout<<"\t********************"<<endl;
        cout<<"\t|��ӭʹ�÷���������|"<<endl; 
        cout<<"\t********************"<<endl;
        cout<<"\t˵����"<<endl;
        cout<<"\t1.��������֧��ֱ���������������������磺1��2��5/6��7/3�����Զ���������Ϊ���"<<endl;
        cout<<"\t2.��������֧��+��-��*��/��������"<<endl;
        cout<<"\t=============="<<endl;
        cout<<"\t1 ��ʼʹ��"<<endl;
        cout<<"\t2 �鿴��ʷ��¼"<<endl;
        cout<<"\t3 �˳�������"<<endl;
        cout<<"\t=============="<<endl;
        cout<<"\t��ѡ���ܡ�1-3����";

        cin>>choice;
        
        switch(choice)
        {
            case 1:
                cout<<"\t����������ʽ��ÿ�������������������������һ���ո񣩣�"<<endl;
                cout<<"\t";
                cin>>expr.fraction1;
                cin>>expr.sign;
                cin>>expr.fraction2;

                if (expr.fraction1.normal() && expr.fraction2.normal()){
                    //����
                    switch(expr.sign){
                        case '+':
                            expr.result=expr.fraction1+expr.fraction2;break;
                        case '-':
                            expr.result=expr.fraction1-expr.fraction2;break;
                        case '*':
                            expr.result=expr.fraction1*expr.fraction2;break;
                        case '/':
                            expr.result=expr.fraction1/expr.fraction2;break;
                        default:
                            break;
                    }
                    //��ʾ���
                    cout<<"\t"<<expr.fraction1<<expr.sign<<expr.fraction2<<"="<<expr.result<<endl<<endl<<endl;
                    database_write(expr);
                }
                else	
                    cout<<"\terror!!!"<<endl<<endl<<endl; 
                break;

            case 2:
                cout<<"\t=============="<<endl;
                cout<<"\t4 �˻���ҳ��"<<endl;
                cout<<"\t5 �����ʷ��¼"<<endl;
                cout<<"\t=============="<<endl;

                database_show();
                
                cin>>choice;
                switch(choice){
                    case 4:
                        break;
                    case 5:
                        database_clear();
                        break;
                    default:
                        break;
                }
                break;

            case 3:
                cout<<"\t���˳�������������"<<endl;
                circulation=false;
                break;                
        }
        system("cls");
	}
    
    return 0;
}
