#include <iostream>
#include <windows.h>

using namespace std;

class Vector {
private:
    double* elements;  // масив для збереження елементів вектора
    int capacity;      // ємність вектора
    int size;          // поточний розмір вектора

public:
    // Конструктор з параметрами
    Vector(int capacity) {
        this->capacity = capacity;
        this->size = 0;
        this->elements = new double[capacity];
    }

    // Метод для додавання елемента в кінець вектора
    void addElement(double element) {
        if (size < capacity) {
            elements[size] = element;
            size++;
        }
    }

    // Метод для виведення елементів вектора на консоль
    void display(){
        cout << "Елементи вектора:" << endl;
        for (int i = 0; i < size; i++) {
            cout << elements[i] << " ";
        }
        cout << endl;
    }

    // Метод, що повертає ємність вектора
    int getCapacity(){
        return capacity;
    }

    // Метод, що повертає поточний розмір вектора
    int getSize(){
        return size;
    }
    
    // Метод, що повертає масив елементів вектора
    double* getElements(){
    	return elements;
	}

    // Перевантажена операція для виконання обробки елементів вектора (наприклад, додавання)
    int operator+(const Vector& other){
		int sum = 0;
        for (int i = 0; i < this->size; i++) {
            sum += this->elements[i] > 0 ? this->elements[i]: 0;
            sum += other.elements[i] > 0 ? other.elements[i]: 0;
        }

        return sum;
    }
};

int main() {
	SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    
    // Введення ємності векторів
    int size;
    cout << "Введіть ємність векторів: ";
    cin >> size;
    
    // Створення двох об'єктів-векторів
    Vector vector1(size);
    Vector vector2(size);

    // Уведення елементів векторів з консолі
    double element;
    cout << "Уведіть елементи 1 вектора :" << endl;
    for (int i = 0; i < vector1.getCapacity(); i++) {
        cin >> element;
        vector1.addElement(element);
    }

    cout << "Уведіть елементи 2 вектора:" << endl;
    for (int i = 0; i < vector2.getCapacity(); i++) {
        cin >> element;
        vector2.addElement(element);
    }

    // Демонстрація використання методів вектора
    cout << "Розмір 1 вектора: " << vector1.getSize() << endl;
    cout << "Розмір 2 вектора: " << vector2.getSize() << endl;

    vector1.display();
    vector2.display();

    // Використання перевантаженої операції
    int sum = vector1 + vector2;
    cout << "Сума додатних елементів двох векторів: " << sum;

    return 0;
}

