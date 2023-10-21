#include <iostream>

class kolejka {
private:
    double* data;  // Tablica przechowująca elementy kolejki
    int front;    
    int rear;     
    int capacity; // Pojemność kolejki
    int size;    

public:
    kolejka(int capacity) 
    {
        this->capacity = capacity;
        data = new double[capacity];
        front = 0;
        rear = -1;
        size = 0;
    }



    void wartości(double value) 
    {     
        rear = (rear + 1) % capacity;//ostatnia wartość z upewnieniem że wskaźnik nie przekroczy pojemności tablicy
        data[rear] = value;
        size++;
    }

    double wartości_odwrotne() 
    {
      
        return data[rear];
    }

    double pierwsza_wartość()
    { 
        return data[front]; 
    }
};

int main()
{
    kolejka zakolejkowane_wartości(5);

    zakolejkowane_wartości.wartości(1);
    zakolejkowane_wartości.wartości(7);
    zakolejkowane_wartości.wartości(5);

    std::cout << "Pierwszy element: " << zakolejkowane_wartości.pierwsza_wartość() << std::endl;

    zakolejkowane_wartości.wartości_odwrotne();

    std::cout << "Ostatni element: " << zakolejkowane_wartości.wartości_odwrotne() << std::endl;

    return 0;
}
