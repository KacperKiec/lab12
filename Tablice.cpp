#include "Tablice.h"

std::pair<int,int> cTablica::f_shakeSort(std::vector<int>& table){

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

void cTablica::f_quickSort(int option, std::vector<int>& table, int low, int high, std::pair<int, int>& actions){

    if (low < high) {
        
        int q = 0;
        
        //jesli optioon = 0 to wykonujemy podzia³ Lomuto
        if (option == 0)
        {
            q = f_partitionLomuto(table, low, high, actions);
            f_quickSort(option, table, low, q-1, actions);

        }

        //jesli optioon = 1 to wykonujemy podzia³ Hoare'a
        if (option == 1)
        {
            q = f_partionHoare(table, low, high, actions);
            f_quickSort(option, table, low, q, actions);
        }
        
        f_quickSort(option, table, q + 1, high, actions);
    }
    actions.first++;
}

int cTablica::f_partitionLomuto(std::vector<int>& table, int low, int high, std::pair<int, int>& actions){

    //element podzialowy
    int pivot = table.at((high+low)/2);

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
    return (i + 1);
}

int cTablica::f_partionHoare(std::vector<int>& table, int low, int high, std::pair<int,int>& actions)
{
    int pivot = table.at(low); // podzia³
    int i = low - 1, j = high + 1;

    while (true) {
        // ZnajdŸ lewy element wiêkszy lub równy pivotowi
        do {
            i++;
            actions.first++;
        } while (table.at(i) < pivot);

        actions.first--;

        // ZnajdŸ prawy element mniejszy lub równy pivotowi
        do {
            j--;
            actions.first++;
        } while (table.at(j) > pivot);
        actions.first--;

        // jesli sie spotkaj¹
        if (i >= j)
            return j;

        // SprawdŸ czy `i` przekroczy³o granicê
        if (i >= high)
            return high;

        // SprawdŸ czy `j` przekroczy³o granicê
        if (j <= low)
            return low;

        std::swap(table.at(i), table.at(j));
        actions.second++;
    }
}

void cTablica::heapify(std::vector<int>& table, int n, int i, std::pair<int,int>& actions)
{
    // znajdowanie najwiêkszego elementu z rodzica, lewego i prawego dziecka
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && table.at(left) > table.at(largest))
    {
        largest = left;
        actions.first++;
    }

    if (right < n && table.at(right) > table.at(largest))
    {
        largest = right;
        actions.first++;
    }

    // zamieñ i kontynuuj kopcowanie jeœli korzeñ nie ma najwiêkszej wartoœci
    if (largest != i) {
        std::swap(table.at(i), table.at(largest));
        actions.second++;
        heapify(table, n, largest, actions);
    }
}

void cTablica::f_heapSort(std::vector<int>& table, std::pair<int, int>& actions)
{
    //rozmiar tablicy
    int n = table.size();

    //Budowanie kopca
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(table, n, i, actions);
    }

    // Sortowanie przez kopcowanie
    for (int i = n - 1; i >= 0; i--) {
        std::swap(table.at(0), table.at(i));
        actions.second++;

        // kopcuj korzen aby na korzeniu pojawila sie najwieksza wartosc
        heapify(table, i, 0, actions);
    }
}

cSortTablica::cSortTablica(){
    this->size = 1000;

    int option = 0;

    std::cout << "Maksymalny rozmiar: "<<this->size;
    std::cout << "\nIle liczb chesz wprowadziæ rêcznie?: ";
    std::cin >> option;
    f_fillManual(option);

    int number = this->size - option-1;
    std::cout << "\nliczba liczb wygenerowanych losowo: " << number+1;
    f_fillWithRandom(number);
}

void cSortTablica::f_fillWithRandom(int numbers){
    try {
        if (numbers < 0 || numbers + this->table.size() >= this->size) throw MyLogicExceptions::OutOfRangeException("Wartoœæ poza zakresem");
        else {
            std::random_device rd;   // non-deterministic generator
            std::mt19937 gen(rd());  // to seed mersenne twister.
            std::uniform_int_distribution<> dist(0, 10000); // distribute results between 1 and 6 inclusive.

            //zmienna pomocnicza
            int temp;

            for (int i = this->table.size(); i < this->size; i++) {
                temp = dist(gen);
                this->table.push_back(temp);

            }
        }
    }
    catch (std::exception& e) {
        std::cerr << e.what();

        //nowa liczba
        int newValue;
        std::cerr << "Podaj nowa liczbe elementow: ";
        std::cin >> newValue;
        this->f_fillWithRandom(newValue);
    }
}

void cSortTablica::f_allSorts(std::ofstream& write){
    
    //para z porównaniami oraz podmianami
    std::pair<int,int> actions{ 0, 0 };

    //wektory pomocnicze
    std::vector<int> temp1, temp2, temp3, temp4, partially;

    //tekst do rodzajów tablic
    std::vector<std::string> typeOfTable{"Losowo", "Uporz¹dkowane", "Odwrotne", "Czêsciowo"};

    for (int j = 0; j < 4; j++)
    {
        
        //Uporz¹dkowane
        if (j == 1) 
        {
            f_heapSort(table, actions);
            partially = table;
            actions.first = 0;
            actions.second = 0;
        }

        //Odwrotnie uporz¹dkowane
        if (j == 2) 
        {
            for (int i = table.size() - 1; i >= 0; i--)
            {
                temp1.at(i) = table.at(i);
                table = temp1;
            }
        }

        //czêœciowo uporz¹dkowane(10% na z³ych miejscach)
        if (j == 3)
        {
            int part = partially.size() * 0.1 - 1; //obliczanie 10% z tablicy

            for(int i=0; i<partially.size(); i+=part)
            {
                std::swap(partially.at(i), partially.at(0));
            }
            table = partially;
        }
       

        for (int i = 100; i <= this->size; i *= 10)
        {
            //wekotry pomocnicze
            temp1 = this->table;
            temp1.resize(i);    //ustawianie rozmiaru wektora 
            temp2 = this->table;
            temp2.resize(i);
            temp3 = this->table;
            temp3.resize(i);
            temp4 = this->table;
            temp4.resize(i);

            //shake sort
            actions = f_shakeSort(temp1);
            f_saveToFile("S. Koktajlowe                          ", i, typeOfTable.at(j), actions.first, actions.second, write);
            actions.first = 0;
            actions.second = 0;

            
            //Quick Sort Lomuto
            f_quickSort(0, temp2, 0, temp2.size() - 1, actions);
            f_saveToFile("S. Quick sort Lomuto ", i, typeOfTable.at(j), actions.first, actions.second, write);
            actions.first = 0;
            actions.second = 0;
            
           
            //Quick sort Hoare'a
            f_quickSort(1, temp3, 0, temp3.size() - 1, actions);
            f_saveToFile("S. Quick sort Hoare'a", i, typeOfTable.at(j), actions.first, actions.second, write);
            actions.first = 0;
            actions.second = 0;
            

            //Sortowanie przez Kopcowanie
            f_heapSort(temp4, actions);
            f_saveToFile("S. przez Kocowanie   ", i, typeOfTable.at(j), actions.first, actions.second, write);
            actions.first = 0;
            actions.second = 0;
            write << "\n";
        }
        write << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
    }
}

void cSortTablica::f_fillManual(int numbers){
    
    try {
        if (numbers<0 || numbers > this->size) { throw MyLogicExceptions::OutOfRangeException("Wartoœæ poza zakresem, maksymalny rozmiar tablicy to: 1000000"); }
        //zmienna pomocnicza
        int temp;
        for (int i = 0; i < numbers; i++) {
            std::cin >> temp;
            this->table.push_back(temp);
        }
    }
    catch (std::exception& e)
    {
        int newValue;
        e.what();
        std::cerr << "Podaj nowa liczbe elementow: ";
        std::cin >> newValue;
        this->f_fillManual(newValue);

    }
}

void cSortTablica::f_saveToFile(std::string name, int length, std::string tableType, long long comparisons, long long changes, std::ofstream& write){
    write << name << "\t" << std::to_string(length) << "\t" << tableType << "\t" << std::to_string(comparisons) << "\t" << std::to_string(changes) << "\n";
}
