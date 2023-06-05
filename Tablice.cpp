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
    this->size = 0;
}

void cSortTablica::f_fillWithRandom(int numbers){

    try {
        if (numbers < 0 || numbers + this->table.size() > this->size) throw std::out_of_range("Wartosc poza zakresem");
        else {
            std::random_device rd;   // non-deterministic generator
            std::mt19937 gen(rd());  // to seed mersenne twister.
            std::uniform_int_distribution<> dist(0, 10000); // distribute results between 1 and 6 inclusive.

            //zmienna pomocnicza
            int temp;

            for (int i = this->table.size(); i < numbers; i++) {
                temp = dist(gen);
                this->table.push_back(temp);
            }
        }
    }
    catch (std::out_of_range& e) {
        std::cerr << e.what();

        //nowa liczba
        int newValue;
        std::cerr << "Podaj nowa liczbe elementow: ";
        std::cin >> newValue;
        this->f_fillWithRandom(newValue);
    }
}

void cSortTablica::f_chooseSort(std::ofstream& write){

    //wybor uzytownika
    int chooseLenght = 0;
    while (chooseLenght != 100 && chooseLenght != 1000 && chooseLenght != 1000000) {
        std::cout << "Dlugosc tablicy:\n- 100 elementow\n- 1000 elementow\n- 1000000 elementow\n";
        std::cin >> chooseLenght;
    }

    //wybor uzytkownika
    int chooseFilling = -1, nrOfValues = 0;
    while (this->size != chooseLenght) {
        std::cout << "1. Wprowadz dane recznie\n2. Losuj dane\n";
        while (chooseFilling != 1 && chooseFilling != 2) std::cin >> chooseFilling;

        std::cout << "Ilosc liczb do wprowadzenia: ";
        std::cin >> nrOfValues;

        if (chooseFilling == 1) {
            this->f_fillManual(nrOfValues);
            this->size += nrOfValues;
        }
        else {
            this->f_fillWithRandom(nrOfValues);
            this->size += nrOfValues;
        }
    }

    int chooseMethod = 0;
    while (chooseMethod != 1 && chooseMethod != 2) {
        std::cout << "Wybierz metode:\n1. Sortowanie koktajlowe\n2. Sortowanie szybkie z podzialem Lomuto\n";
        std::cin >> chooseMethod;
    }

    std::pair<int, int> actions{ 0, 0 };
    if (chooseMethod == 1) {
        actions = f_shakeSort(this->table);
        f_saveToFile("S. Koktajlowe", this->size, "jeszcze nie wiem", actions.first, actions.second, write);
    }
    else {
        f_quickSortLomuto(this->table, 0, this->table.size() - 1, actions);
        f_saveToFile("S. Szybkie Lomuto", this->size, "jeszcze nie wiem", actions.first, actions.second, write);
    }

}

void cSortTablica::f_fillManual(int numbers){

    try {
        if (numbers < 0 || numbers + this->table.size() > this->size) throw std::out_of_range("Wartosc poza zakresem");
        else {

            //zmienna pomocnicza
            int temp;
            for (int i = this->table.size(); i < numbers; i++) {
                std::cin >> temp;
                this->table.push_back(temp);
            }
        }
    }
    catch (std::out_of_range& e) {
        std::cerr << e.what();

        //nowa liczba
        int newValue;
        std::cerr << "Podaj nowa liczbe elementow: ";
        std::cin >> newValue;
        this->f_fillManual(newValue);
    }
}

void cSortTablica::f_saveToFile(std::string name, int length, std::string tableType, int comparisons, int changes, std::ofstream& write){
    write << name << "\t" << std::to_string(length) << "\t" << tableType << "\t" << std::to_string(comparisons) << "\t" << std::to_string(changes) << "\n";
}
