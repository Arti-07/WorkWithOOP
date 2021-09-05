#include <iostream>

using namespace std;

/*
 * Конструктор копирования
 */

/*
 * Перегрузка оператора присваивания
 */

/*
 * Перегрузка оператора == и !=
 */

class MyClass {
public:
    int *data;

    explicit MyClass(int size) {
        this->size = size;
        this->data = new int[size];
        for (int i = 0; i < size; ++i) {
            data[i] = i;
        }
        cout << "Вызвался конструктор  " << this << endl;
    };

    MyClass(const MyClass &other) {
        this->size = other.size;
        this->data = new int[other.size];
        for (int i = 0; i < other.size; ++i) {
            this->data[i] = other.data[i];
        }
        cout << "Вызвался конструктор копирования  " << this << endl;
    }

    MyClass &operator=(const MyClass &other) {
        this->size = other.size;
        delete this->data;

        this->data = new int[other.size];
        for (int i = 0; i < other.size; ++i) {
            this->data[i] = other.data[i];
        }
        return *this;
    }

    ~MyClass() {
        cout << "Вызвался деструктор  " << this << endl;
        delete[] data;
    }

private:
    int size;
};

class Point {
private:
    int x;
    int y;
public:
    Point() {
        x = 0;
        y = 0;
    }

    Point(int x, int y) {
        this->x = x;
        this->y = y;
    }

    bool operator==(const Point &other) const {
        return this->x == other.x && this->y == other.y;
    }
    bool operator!=(const Point &other) const {
        return !(this->x == other.x && this->y == other.y);
    }

    void SetY(int y) {
        this->y = y;
    }

    int GetY() {
        return this->y;
    }

    void SetX(int x) {
        this->x = x;
    }

    int GetX() {
        return this->x;
    }

    void Print() {
        cout << "Y = " << this->y << "\n X = " << this->x << endl;
    }
};


void Foo(const MyClass &value) {
    cout << "Вывелась функция FOO" << endl;
}

MyClass Foo2() {
    cout << "Вывелась функция FOO" << endl;
    MyClass temp(2);
    return temp;
}


int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");

    Point a(5, 1);
    Point b(9, 4);
    bool result = a != b;
    cout << result << endl;

    return 0;
}
