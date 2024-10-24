#include <iostream>
class pixel
{
private:
    int x, y;
    float m;
    char *color;

public:
    // добавить еще констуктор по умолчанию

    pixel()
    {
    }
    /*
        pixel()
        {
            x = 1;
            y = 1;
            m = 1.1;
            color = "black";
        }
        */
    pixel(int CordX, int CordY, float MassaM, char *ColorC) : x(CordX), y(CordY), m(MassaM)
    {
        color = new char[strlen(ColorC) + 1]; // указ указателю color указывать на эту память.
        strcpy(color, ColorC);                // если не скопировать данные поступаемого цвета в color, то все пиксели
        // будут иметь один и тот же цвет, поскольку все они будут указывать на одну и ту же область памяти.
        // Функция strcpy решает проблему, копируя строку ColorC в область памяти, на которую указывает color
    }
    pixel(const pixel &a); // копирующий конструктор: const мешает менять содержимое исходных данных, при не создается копия структуры, а содержимое объекта передается на прямую
    // это как если за двумя зайцами погнаться и обоих поймаешь 100%. a - ссылочная переменная - ссылка на другие объекты класса pixel.

    pixel(char *);
    pixel(float);
    ~pixel()
    {
        delete[] color;
    }
    void SetX(int CordX)
    {
        x = CordX;
    }
    void SetY(int CordY)
    {
        y = CordY;
    }
    void SetMassa(float MassaM)
    {
        m = MassaM;
    }
    int GetX() const
    {
        return x;
    }
    int GetY() const
    {
        return y;
    }
    int GetMassa() const
    {
        return m;
    }
    void SetColor(char *ColorC)
    {
        delete[] color;
        color = new char[strlen(ColorC) + 1];
        strcpy(color, ColorC);
    }
    char *GetColor() const
    {
        return color;
    }

    void PrintObj() const
    {
        std::cout << "Координата X - " << GetX() << std::endl;
        std::cout << "Координата Y - " << GetY() << std::endl;
        std::cout << "Вес точки - " << GetMassa() << std::endl;
        std::cout << "Цвет точки - " << GetColor() << std::endl;
    }
    void InputObj(int CordX, int CordY, float MassaM, char *ColorC);

    pixel summa(pixel b); // не вызывает ошибку пока что

    pixel *there_I_am() // не вызывает ошибку пока что
    {
        return this;
    }
    pixel &copy(const pixel &a); // параметры как у копирующего конструктора, но это функция.  p2.copy(p); - p2, p - уже созданные объекты, то есть у них внутри что-то есть.
};
pixel &pixel::copy(const pixel &a)
{
    if (this != &a)
    {                   // если if не будет выполняться, то это означает, что: *this - обращение по адресу, который указывает на само себя.
        return (*this); // выдаст то, что хранится по этому адресу. *звездочка - разыменование, но еще означает обратиться по адресу
    }
}
pixel::pixel(const pixel &a)
{ // копирующая функция передает параметр не по значению, а напрямую - по ссылке, при этом
    x = a.x;
    y = a.y;
    color = new char[strlen(color) + 1];
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

class Latm
{ // Lifting and transport machine //
private:
    int x, y, z, x1, y1; // x1 y1 координаты груза
    float MassaBox;      // масса груза
    float MaxMassa;      // грузоподъемность
    char *TypeLatm;

public:
    Latm()
    {
    }
    Latm(char *TypeLatmT, float MaxMassaM, int CordX, int CordY, float MassaBoxM, int CordX1, int CordY1) : MaxMassa(MaxMassaM), x(CordX), y(CordY), z(0), MassaBox(MassaBoxM)
    {
        TypeLatm = new char[strlen(TypeLatmT) + 1];
        strcpy(TypeLatm, TypeLatmT);
        st = Груз_Не_Захвачен;
    }
    Latm(const Latm &a);
    ~Latm()
    {
        delete[] TypeLatm;
    }
    void SetX(int CordX)
    {
        x = CordX;
    }
    void SetY(int CordY)
    {
        y = CordY;
    }
    void SetZ(int CordZ)
    { // Можно использовать тогда и только тогда когда груз захвачен
        z = CordZ;
    }
    void SetMassaBox(float MassaBoxM); // нельзя менять массу груза когда состояние Груз_Поднят

    void SetTypeLatm(char *TypeLatmT)
    {
        delete[] TypeLatm;
        TypeLatm = new char[strlen(TypeLatmT) + 1];
        strcpy(TypeLatm, TypeLatmT);
    }
    void SetX1(int CordX)
    { // координата по x груза; можно устанавливать, если нахождение
        // в состоянии Груз_Не_Захвачен
        x1 = CordX;
    }
    void SetY1(int CordY)
    { // координата по y груза; можно устанавливать, если нахождение
        // в состоянии Груз_Не_Захвачен
        y1 = CordY;
    }
    void LatmToBox()
    {
        x = x1;
        y = y1;
        st = ПТМ_Впритык_К_Коробке;
    }
    int GetX() const
    {
        return x;
    }
    int GetY() const
    {
        return y;
    }
    int GetZ() const
    {
        return z;
    }
    int GetMassaBox() const // можно задумать, что можно узнать массу груза, если захватить его
    {
        return MassaBox;
    }
    int GetMaxMassa() const
    {
        return MaxMassa;
    }
    char *GetTypeLatm() const
    {
        return TypeLatm;
    }
    int GetX1() const
    {
        return x1;
    }
    int GetY1() const
    {
        return x1;
    }

    void InfoLatm() const
    {
        std::cout << "Подъемно-транспортная машина : " << GetTypeLatm() << std::endl;
        std::cout << "Грузоподъемность - " << GetMaxMassa() << std::endl;
        std::cout << "Координата X - " << GetX() << std::endl;
        std::cout << "Координата Y - " << GetY() << std::endl;
        // if(состояние = Груз_Захвачен) {
        // std::cout << "Вес груза - " << GetMassa() << std::endl;
        // }
        // else {
        // std::cout << "Вес груза неизвестен"<<std::endl;
        // }
    }
    void InfoBox() const
    {
        std::cout << "Масса груза - " << GetMassaBox() << std::endl;
        std::cout << "Координата x груза - " << GetX1() << std::endl;
        std::cout << "Координата y груза - " << GetY1() << std::endl;
        // придумать, что типа из 1000 допустимой грузоподъемности осталось 843
    }

    void TakeBox()
    {
        if (st == Груз_Не_Захвачен)
        {
            st = Груз_Захвачен;
        }
        else
        {
            std::cout << "Груз уже захвачен" << std::endl;
            return;
        }
    }
    void UpBox(int height)
    {
        if (MaxMassa >= MassaBox)
        {
            st = Груз_Поднят;
            SetZ(height);
        }
        else
        {
            st = Груз_Упал;
            SetZ(0);
            MassaBox = MassaBox - MassaBox / 10;
        }
    }
    void DownBox()
    {
        st = Груз_Опущен;
        SetZ(0);
    }
    void PutBox()
    {
        st = Груз_Выложен;
        st = Груз_Не_Захвачен;
    }
    void AddMassaBox(float AddMassaBoxB)
    {
        float reg = MassaBox;
        if (st == Груз_Не_Захвачен)
        {
            MassaBox += AddMassaBoxB;
            std::cout << "Масса груза величилась с " << reg << " до " << MassaBox << std::endl;
        }
        else
        {
            std::cout << "В данный момент груз захвачен ПТМ и его масса не может увеличиваться" << std::endl;
        }
    }
    void CutMassaBox(float CutMassaBoxB)
    {
        float reg = MassaBox;
        if (st == Груз_Не_Захвачен)
        {
            if (MassaBox > CutMassaBoxB)
            {
                MassaBox -= CutMassaBoxB;
                std::cout << "Масса груза уменьшилась с " << reg << " до " << MassaBox << std::endl;
            }
            else
            {
                std::cout << "Массу можно уменьшить только на его часть, а не на целое или того более" << std::endl;
            }
        }
        else
        {
            std::cout << "В данный момент груз захвачен ПТМ и его масса не может уменьшаться" << std::endl;
        }
    }
};
/*
enum Command{
x1, //Выполнение конструктора по умолчанию
x2, //
x3,
x4,
x5,
x6,
x7
};
*/
// enum Message{
// y1,y2,y3,y4,y5,y6,y7
// };
enum State
{
    Груз_Не_Захвачен, // S0
    ПТМ_Впритык_К_Коробке,
    Груз_Захвачен, // S1
    Груз_Поднят,   // S2. Если масса груза выше грузоподъемности,
    // то переход в состояние Груз_Упал (Груз_Захвачен->Груз_Поднят->Груз_Упал,
    // если масса груза меньше или равна грузоподъемности, то Груз_Захвачен->Груз_Поднят
    // когда состояние Груз_Поднят можно установить новую массу груза
    Груз_Опущен, // S3. может быть переход Груз_Поднят->Груз_Опущен->Груз_Не_Захвачен
    Груз_Выложен,
    Груз_Упал, // S4, Если состояние Груз_Упал, Масса груза уменьшается на определенное число в
    // в зависимости оттого, на какой высоте z упал груз, масса которого превышает грузоподъемность
};

void Latm::SetMassaBox(float MassaBoxM)
{
    if (st == Груз_Не_Захвачен)
    {
        MassaBox = MassaBoxM;
    }
    else
    {
        std::cout << "Сначала выложите груз, прежде чем менять его массу" << std::endl;
        return;
    }
}
State st;

int main()
{
    setlocale(LC_ALL, "ru_RU.UTF-8");
    // Latm PTM; //Заметен след конструктора по умолчанию
    Latm PTM("Loader", 200.5, 0, 0, 150.49, 5, 3); // инициализация конструктором с 7-ю параметрами
    PTM.LatmToBox()
        PTM.TakeBox();

    /*
std::cout<<"1-определение объекта с помощью конструктора по умолчанию"<<std::endl;
std::cout<<"2-Инициализация объекта с помощью конструктора с 7-ю параметрами (";
std::cout<<"1 параметр - тип ПТМ, 2-й - Грузоподъемность, 3-й - координата по x ПТМ, 4-й - координата";
std::cout<<" по y ПТМ, 5-й - Масса груза, 6-й - координата по x груза, 7-й - координата по y груза)"<<std::endl;
std::cout<<"3-Переместить объект ПТМ к координатам груза"<<std::endl;
std::cout<<"4-Захватить груз"<<std::endl;
std::cout<<"5-Поднять груз"<<std::endl;
std::cout<<"6-Опустить груз"<<std::endl;
std::cout<<"7-увеличить массу груза (если груз не захвачен)"<<std::endl;
std::cout<<"8-Выложить груз"<<std::endl;


    int x;

    bool ON=true;
    State st=Груз_Не_Захвачен;
    while(ON) {
        std::cout<<"Ввод команды :"<<std::endl;
        std::cin>>x;
    switch(st) {
        case 0: if((int)x1==x) {
            Latm t1;

        }
    }
    }
    */
    // Добавить Latm.Захватить_Груз()  в комп. функции если состояние Груз_Не_Захвачен, то
    // захват груза, иначе ошибка

    // Добавить Latm.Опустить_Груз() в комп. функции если состояние

    // Добавить Latm.Поднять_Груз(z); в комп. функции если состояние Груз_Захвачен, то подъем
    // иначе ошибка.
    //(но возможен переход в состояние Упал, при этом происходит уменьшение массы груза на
    // случайное число, затем переход в состояние Груз_Не_Захвачен), иначе ошибка.

    // pixel p; //неявный вызов конструктора. То есть когда мы объявляем p, вызывается неявно конструктор pixel
    // pixel p=pixel(); //явный вызов конструктора
    /*C одной стороны, конструктор по умолчанию необходим, чтобы создавать одиночные объекты, но с другой стороны он нужен для того, чтобы создавать массив точек mt[10]*/
    // pixel p(5,6,3.5,"blue");

    /*
    pixel p(5, 6, 3.5, "blue");
    pixel p2(5, 6, 3.5, "green");
   p.PrintObj();
  // pixel p2(p); //создадим объект p2 из уже созданного объекта p.
  //pixel p2=p; //копирующий конструктор по умолчанию, который нам ни в коем случае не нужен!


   //p2.copy(p); //t3.copy(t2.summa(t1)); t2.summa(t1) - безымянный объект. t3.copy(t2.su...->аналогично t3=t2+t1
   pixel p3=p2.summa(p); //ей (компонентной функции) передается в это время работы программы объект p. this=&p2: p2 является первым параметром этой функции, а p - вторым. Первый параметр
   //это всегда указатель на себя. Один параметр передается явно (this), второй и т.д. - неявно.
    //pixel p("green");
    // p.~pixel();
    p3.PrintObj(); */
}