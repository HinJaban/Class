#ifndef CLASS_H
#define CLASS_H
class pixel
{
private:
    int x, y;
    float m;
    char *color;

public:
    // добавить еще констуктор по умолчанию

    pixel(){
    }
    pixel(int CordX, int CordY, float MassaM, char *ColorC);
    pixel(const pixel &a); // копирующий конструктор: const мешает менять содержимое исходных данных, при не создается копия структуры, а содержимое объекта передается на прямую
    // это как если за двумя зайцами погнаться и обоих поймаешь 100%. a - ссылочная переменная - ссылка на другие объекты класса pixel.

   

    /*деструктор*/
    ~pixel() 
    {
        delete[] color;
    }
    void SetX(int CordX);
    void SetY(int CordY);
    void SetMassa(float MassaM);
    int GetX() const;
    int GetY() const;
    int GetMassa() const;
    void SetColor(char *ColorC);
    char *GetColor() const;

    void PrintObj() const;
    void InputObj(int CordX, int CordY, float MassaM, char *ColorC);

    pixel summa(pixel b); // не вызывает ошибку пока что

    pixel *there_I_am();
    pixel &copy(const pixel &a); // параметры как у копирующего конструктора, но это функция.  p2.copy(p); - p2, p - уже созданные объекты, то есть у них внутри что-то есть.
};
#endif