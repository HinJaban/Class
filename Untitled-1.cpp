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
        color = new char[strlen(ColorC) + 1];//указ указателю color указывать на эту память. 
        strcpy(color, ColorC); //если не скопировать данные поступаемого цвета в color, то все пиксели
        //будут иметь один и тот же цвет, поскольку все они будут указывать на одну и ту же область памяти.
        //Функция strcpy решает проблему, копируя строку ColorC в область памяти, на которую указывает color
        
    }
    pixel(const pixel &a); //копирующий конструктор: const мешает менять содержимое исходных данных, при не создается копия структуры, а содержимое объекта передается на прямую
    //это как если за двумя зайцами погнаться и обоих поймаешь 100%. a - ссылочная переменная - ссылка на другие объекты класса pixel.
    pixel(char *);
    pixel(float );
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

    
    pixel summa(pixel b);//не вызывает ошибку пока что
    
    pixel *there_I_am()//не вызывает ошибку пока что
    {
        return this;
    }
    pixel &copy(const pixel &a);//параметры как у копирующего конструктора, но это функция.  p2.copy(p); - p2, p - уже созданные объекты, то есть у них внутри что-то есть.
    
  
};
pixel&pixel::copy(const pixel & a) {
    if(this!=&a) { //если if не будет выполняться, то это означает, что: *this - обращение по адресу, который указывает на само себя. 
        return(*this); //выдаст то, что хранится по этому адресу. *звездочка - разыменование, но еще означает обратиться по адресу
    }
}
 pixel::pixel(const pixel &a) { //копирующая функция передает параметр не по значению, а напрямую - по ссылке, при этом 
    x=a.x; y=a.y;
    color = new char[strlen(color)+1];
    strcpy(color, a.color); //strcpy помогает решить проблему двойного указателя
    m=a.m;
}
void pixel::InputObj(int CordX, int CordY, float MassaM, char *ColorC)
{
    SetX(CordX);
    SetY(CordY);
    SetMassa(MassaM);
    SetColor(ColorC);
}

 pixel pixel::summa(pixel b) {
    pixel h; //у pixel h есть указатель color, хотя никакую память для h мы не запрашивали
    h.x=x+b.x; //x, y - относятся к объекту t2, если: t2.summa(t1); Эквивалентно h.x=this->x+b.x;
    h.y=y+b.y;//Эквивалентно h.y=this->y+b.y;
    h.m=m+b.m; //Эквивалентно h.m=this->m+b.m; this->m относится к p2, если: p2.summa(p) - потому адрес объекта p2 содержится в этом указателе.
    h.color=new char[strlen(color)+1];
    strcpy(h.color, color); //копирование цвета
    strcat(h.color, b.color);//конкатенация строк
    return(h);
}

int main()
{
    setlocale(LC_ALL, "ru_RU.UTF-8");
    //pixel p; //неявный вызов конструктора. То есть когда мы объявляем p, вызывается неявно конструктор pixel
    //pixel p=pixel(); //явный вызов конструктора
    /*C одной стороны, конструктор по умолчанию необходим, чтобы создавать одиночные объекты, но с другой стороны он нужен для того, чтобы создавать массив точек mt[10]*/
    // pixel p(5,6,3.5,"blue");
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
    p3.PrintObj();
    
    
}