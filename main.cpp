#include <iostream>
using namespace std;

/*
 * Конструктор копирования
 */

class MyClass
{
public:
    int *data;

    explicit MyClass(int size)
    {
        this->size = size;
        this->data = new int[size];
        for (int i = 0; i < size; ++i) {
            data[i] = i;
        }
        cout<<"Вызвался конструктор  "<<this<<endl;
    };

    MyClass(const MyClass &other)
    {
        this->size = other.size;
        this->data = new int [other.size];
        for (int i = 0; i < other.size; ++i) {
            this->data[i] = other.data[i];
        }
        cout<<"Вызвался конструктор копирования  "<<this<<endl;
    }
    ~MyClass()
    {
        cout<<"Вызвался деструктор  "<<this<<endl;
        delete[] data;
    }

private:
    int size;
};
void Foo(MyClass value)
{
    cout<<"Вывелась функция FOO"<<endl;
}
MyClass Foo2()
{
    cout<<"Вывелась функция FOO"<<endl;
    MyClass temp(2);
    return temp;
}
int main()
{
    setlocale(LC_ALL,"ru_RU.UTF-8");

    MyClass a(10);
    MyClass b(a);
    //Foo(a);

    return 0;
}
