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

void cTablica::f_quickSortLomuto(std::vector<int>& table, int low, int high, std::pair<int, int>& actions){

    if (low < high) {
        //indeks elementu podzialowego
        int q = f_partitionLomuto(table, low, high, actions);
        f_quickSortLomuto(table, low, high - 1, actions);
        f_quickSortLomuto(table, low + 1, high, actions);
    }
    actions.first++;
}

int cTablica::f_partitionLomuto(std::vector<int>& table, int low, int high, std::pair<int, int>& actions){

    //element podzialowy
    int pivot = table[high];

    //element mniejszy
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (table[j] <= pivot) {
            i++;
            std::swap(table[i], table[j]);
            actions.second++;
        }
        actions.first++;
    }

    std::swap(table[i + 1], table[high]);
    actions.second++;
    return i + 1;
}




cSortTablica::cSortTablica(int size){
    if (size == 100 || size == 1000 || size == 1000000)  this->size = size;
    else throw "Nieprawidlowy rozmiar tablicy";
}
