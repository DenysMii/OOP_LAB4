#include <iostream>
#include <windows.h>

using namespace std;

class Vector {
private:
    double* elements;  // ����� ��� ���������� �������� �������
    int capacity;      // ������ �������
    int size;          // �������� ����� �������

public:
    // ����������� � �����������
    Vector(int capacity) {
        this->capacity = capacity;
        this->size = 0;
        this->elements = new double[capacity];
    }

    // ����� ��� ��������� �������� � ����� �������
    void addElement(double element) {
        if (size < capacity) {
            elements[size] = element;
            size++;
        }
    }

    // ����� ��� ��������� �������� ������� �� �������
    void display(){
        cout << "�������� �������:" << endl;
        for (int i = 0; i < size; i++) {
            cout << elements[i] << " ";
        }
        cout << endl;
    }

    // �����, �� ������� ������ �������
    int getCapacity(){
        return capacity;
    }

    // �����, �� ������� �������� ����� �������
    int getSize(){
        return size;
    }
    
    // �����, �� ������� ����� �������� �������
    double* getElements(){
    	return elements;
	}

    // ������������� �������� ��� ��������� ������� �������� ������� (���������, ���������)
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
    
    // �������� ������ �������
    int size;
    cout << "������ ������ �������: ";
    cin >> size;
    
    // ��������� ���� ��'����-�������
    Vector vector1(size);
    Vector vector2(size);

    // �������� �������� ������� � ������
    double element;
    cout << "������ �������� 1 ������� :" << endl;
    for (int i = 0; i < vector1.getCapacity(); i++) {
        cin >> element;
        vector1.addElement(element);
    }

    cout << "������ �������� 2 �������:" << endl;
    for (int i = 0; i < vector2.getCapacity(); i++) {
        cin >> element;
        vector2.addElement(element);
    }

    // ������������ ������������ ������ �������
    cout << "����� 1 �������: " << vector1.getSize() << endl;
    cout << "����� 2 �������: " << vector2.getSize() << endl;

    vector1.display();
    vector2.display();

    // ������������ ������������� ��������
    int sum = vector1 + vector2;
    cout << "���� �������� �������� ���� �������: " << sum;

    return 0;
}

