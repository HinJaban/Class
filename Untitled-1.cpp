#include <iostream>
class pixel{
    private: int x,y; float m; char*color;
    public:
    //добавить еще констуктор по умолчанию
    pixel(){

    }
    pixel(int CordX, int CordY, float MassaM, char*ColorC): x(CordX), y(CordY), m(MassaM), color(ColorC) {
        color=new char[strlen(ColorC)+1];
    }
        ~pixel() {
            delete[]color;
        }
        void SetX(int CordX) {
            x=CordX;
        }
        void SetY(int CordY) {
            y=CordY;
        }
        void SetMassa(float MassaM) {
            m=MassaM;
        }
        int GetX()const {
            return x;
        }
        int GetY()const {
            return y;
        }
        int GetMassa()const {
            return m;
        }
        void SetColor(char * ColorC) {
            delete[]color;
            color=new char[strlen(ColorC)+1];
            strcpy(color,ColorC);
        }
        char*GetColor()const {
            return color;
        }
        
        void PrintObj()const {
            std::cout<<"Координата X - "<<x<<std::endl;
            std::cout<<"Координата Y - "<<y<<std::endl;
            std::cout<<"Вес точки - "<<m<<std::endl;
             std::cout<<"Цвет точки - "<<color<<std::endl;
        }
        void InputObj(int CordX, int CordY, float MassaM, char*ColorC);


    
};

void pixel::InputObj(int CordX, int CordY, float MassaM, char*ColorC) {
    SetX(CordX);
    SetY(CordY);
    SetMassa(MassaM);
    SetColor(ColorC);

}

int main() {
     setlocale(LC_ALL, "ru_RU.UTF-8");
    pixel p;
    
    p.InputObj(5,6,3.5, "blue");
    p.PrintObj();

   
}