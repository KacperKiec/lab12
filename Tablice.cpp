#include "Tablice.h"

std::pair<int, int> cTablica::f_shakeSort(std::vector<int>& table){

    //dolna granica iteracji
    int bottom = 0;
    //gorna granica iteracji
    int top = table.size() - 1;
    //zmienna typu bool wskazuje wartosc false jezeli tablica jest posortowana
    bool replace = true;
    //para: liczba porownan, liczba przestawien
    std::pair<int, int> actions{ 0, 0 };

    while (replace)
    {
        replace = false;

        for (int i = bottom; i < top; i++)
        {
            if (table[i] > table[i + 1])
            {
                std::swap(table[i], table[i + 1]);
                actions.second++;
                replace = true;
            }
            actions.first++;
        }

        top--;
        for (int i = top; i > bottom; i--)
        {
            if (table[i] < table[i - 1])
            {
                std::swap(table[i], table[i - 1]);
                actions.second++;
                replace = true;
            }
            actions.first++;
        }

        bottom++;
    }

    return actions;
}

cSortTablica::cSortTablica(int size){
    if (size != 100 || size != 1000 || size != 1000000) throw "Nieprawidlowy rozmiar tablicy";
    else this->size = size;
}
