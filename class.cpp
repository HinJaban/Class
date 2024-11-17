#include "class.h"
#include <iostream>
pixel::pixel(int CordX, int CordY, float MassaM, char *ColorC) : x(CordX), y(CordY), m(MassaM)
    {
        color = new char[strlen(ColorC) + 1]; // указ указателю color указывать на эту память.
        strcpy(color, ColorC);                // если не скопировать данные поступаемого цвета в color, то все пиксели
        // будут иметь один и тот же цвет, поскольку все они будут указывать на одну и ту же область памяти.
        // Функция strcpy решает проблему, копируя строку ColorC в область памяти, на которую указывает color
    }
    void  pixel::SetX(int CordX)
    {
        x = CordX;
    }
    void  pixel::SetY(int CordY)
    {
        y = CordY;
    }
    void  pixel::SetMassa(float MassaM)
    {
        m = MassaM;
    }
    int  pixel::GetX() const
    {
        return x;
    }
    int  pixel::GetY() const
    {
        return y;
    }
    int  pixel::GetMassa() const
    {
        return m;
    }
    void  pixel::SetColor(char *ColorC)
    {
        delete[] color;
        color = new char[strlen(ColorC) + 1];
        strcpy(color, ColorC);
    }
    char * pixel::GetColor() const
    {
        return color;
    }

    void  pixel::PrintObj() const
    {
        setlocale(LC_ALL, "ru_RU.UTF-8");
        std::cout << "Координата X - " << GetX() << std::endl;
        std::cout << "Координата Y - " << GetY() << std::endl;
        std::cout << "Вес точки - " << GetMassa() << std::endl;
        std::cout << "Цвет точки - " << GetColor() << std::endl;
    }

    pixel * pixel::there_I_am() // не вызывает ошибку пока что
    {
        return this;
    }
pixel &pixel::copy(const pixel &a) //копирующая функция (функция присваивания)
{
    if (this != &a)
    {                   // если if не будет выполняться, то это означает, что: *this - обращение по адресу, который указывает на само себя.
        return (*this); // выдаст то, что хранится по этому адресу. *звездочка - разыменование, но еще означает обратиться по адресу
    }
}
pixel::pixel(const pixel &a) //
{ // копирующий конструктор передает параметр не по значению, а напрямую - по ссылке, при этом
    x = a.x;
    y = a.y;
    color = new char[strlen(a.color) + 1];
    strcpy(color, a.color); // strcpy помогает решить проблему двойного указателя
    m = a.m;
}
void pixel::InputObj(int CordX, int CordY, float MassaM, char *ColorC)
{
    SetX(CordX);
    SetY(CordY);
    SetMassa(MassaM);
    SetColor(ColorC);
}

pixel pixel::summa(pixel b)
{
    pixel h;       // у pixel h есть указатель color, хотя никакую память для h мы не запрашивали
    h.x = x + b.x; // x, y - относятся к объекту t2, если: t2.summa(t1); Эквивалентно h.x=this->x+b.x;
    h.y = y + b.y; // Эквивалентно h.y=this->y+b.y;
    h.m = m + b.m; // Эквивалентно h.m=this->m+b.m; this->m относится к p2, если: p2.summa(p) - потому адрес объекта p2 содержится в этом указателе.
    h.color = new char[strlen(color) + 1];
    strcpy(h.color, color);   // копирование цвета
    strcat(h.color, b.color); // конкатенация строк
    return (h);
}