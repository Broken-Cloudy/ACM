//�����ļ�����ȡд����ʷ��¼
#pragma once
#include <cstdio>
#include "fraction.h"

//���ʽ��
class expression{
public:
    fraction fraction1,fraction2,result;
    char sign;
};

void database_write(expression&);
void database_clear();
void database_show();
