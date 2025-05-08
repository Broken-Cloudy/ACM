//操作文件，读取写入历史记录
#pragma once
#include <cstdio>
#include "fraction.h"

//表达式类
class expression{
public:
    fraction fraction1,fraction2,result;
    char sign;
};

void database_write(expression&);
void database_clear();
void database_show();
