#include <iostream>

using namespace std;

struct dane {
    int liczba;
    dane *poprzednik;
};

struct stos {
    dane *top;
};

void push(stos &s, int liczba);

void pop(stos &s);

int zliczajElementyNaStosie(stos s);

int main() {
    stos s;
    s.top = NULL;
    push(s, 5);
    cout << "Elementow na stosie: " << zliczajElementyNaStosie(s) << endl;
    push(s, 6);
    cout << "Elementow na stosie: " << zliczajElementyNaStosie(s) << endl;
    pop(s);
    pop(s);
    pop(s);
    cout << "Elementow na stosie: " << zliczajElementyNaStosie(s) << endl;


    return 0;
}

void push(stos &s, int liczba) {
    dane *nowy_element = new dane;          //tworzy nowy obiekt typu dane i przydziela mu pamięć na stercie za pomocą operatora new
    nowy_element->liczba = liczba;          //przypisuje się wartość liczba do pola liczba w strukturze dane, reprezentującej nowy element stosu
    nowy_element->poprzednik = s.top;       //ustawia się pole poprzednik w nowym elemencie na obecny wierzchołek stosu. Tworzy się powiązanie między nowym elementem, a poprzednim elementem stosu
    s.top = nowy_element;                   //ustawia się s.top na adres nowego elementu, co oznacza, że nowy element staje się nowym wierzchołkiem stosu
}

void pop(stos &s) {
    if (s.top == NULL) {
        cout << "Stos jest pusty" << endl;
    } else {
        dane *usuwany = s.top;              //utworzenie wskaźnika usuwany typu dane i przypisanie mu wartości s.top
        s.top = s.top->poprzednik;          //wartość wskaźnika top bedzie wskazywała na poprzedni element na stosie
        delete usuwany;
    }
}

int zliczajElementyNaStosie(stos s) {       //nie edytuje oryginalnego stosu, działamy na kopii
    int counter = 0;
    dane *ptr = s.top;
    while (ptr != NULL) {                   //top zmieniony na ptr, by nie edytowac oryginalnego wierzchołka stosu
        ptr = ptr->poprzednik;
        counter++;
    }
    return counter;
};