#include "class.h"
#include "class.cpp"
#include <iostream>

int main()
{
    setlocale(LC_ALL, "ru_RU.UTF-8");
    
    pixel t1(1,1,3.5,"green");
    pixel t2(t1);
    t2.PrintObj();

}