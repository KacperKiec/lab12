#include <iostream>
#include <fstream>
#include <vector>
#include <locale.h>
#include "Tablice.h"
#include "LibFiles.h"
#include "LibExcept.h"

int main()
{
    setlocale(LC_CTYPE, "Polish");
    //uchwyt ofstream na zapis
    std::ofstream write;
    try {
        f_createFile(write);
    }
    catch (const char* e) {
        std::cerr << e << "\n";
        std::cerr << "Aby ponowic probe wpisz /t ";
        char sign;
        std::cin >> sign;
        if (sign == 't' || sign == '/t') f_createFile(write);
        else exit(0);
    }
    
    write << "Nazwa metody\tDlugosc tablicy\tRodzaj tablicy\tLiczb porownan\tLiczba przestawien\n";

    cSortTablica s;
    s.f_allSorts(write);

    write.close();
}

