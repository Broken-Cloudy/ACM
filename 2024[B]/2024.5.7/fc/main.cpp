#include <iostream> 
#include "fraction.h"
#include "document.h"
using namespace std;

int main(){
    expression expr;
	int choice;//界面操作辅助标志符
    bool circulation=true;//循环标志符

    // database_show();
    // database_show();

    while(circulation){
        cout<<"\t********************"<<endl;
        cout<<"\t|欢迎使用分数计算器|"<<endl; 
        cout<<"\t********************"<<endl;
        cout<<"\t说明："<<endl;
        cout<<"\t1.本计算器支持直接输入整数、分数，形如：1、2、5/6、7/3，且自动将分数化为最简"<<endl;
        cout<<"\t2.本计算器支持+、-、*、/四种运算"<<endl;
        cout<<"\t=============="<<endl;
        cout<<"\t1 开始使用"<<endl;
        cout<<"\t2 查看历史记录"<<endl;
        cout<<"\t3 退出计算器"<<endl;
        cout<<"\t=============="<<endl;
        cout<<"\t请选择功能【1-3】：";

        cin>>choice;
        
        switch(choice)
        {
            case 1:
                cout<<"\t请输入运算式（每次输入运算数或运算符后输入一个空格）："<<endl;
                cout<<"\t";
                cin>>expr.fraction1;
                cin>>expr.sign;
                cin>>expr.fraction2;

                if (expr.fraction1.normal() && expr.fraction2.normal()){
                    //计算
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
                    //显示结果
                    cout<<"\t"<<expr.fraction1<<expr.sign<<expr.fraction2<<"="<<expr.result<<endl<<endl<<endl;
                    database_write(expr);
                }
                else	
                    cout<<"\terror!!!"<<endl<<endl<<endl; 
                break;

            case 2:
                cout<<"\t=============="<<endl;
                cout<<"\t4 退回主页面"<<endl;
                cout<<"\t5 清除历史记录"<<endl;
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
                cout<<"\t已退出计算器！！！"<<endl;
                circulation=false;
                break;                
        }
        system("cls");
	}
    
    return 0;
}
