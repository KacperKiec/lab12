#ifndef LIBFILES.H
#define LIBFILES.H

#include <iostream>
#include <fstream>

/*
* Otwarcie pliku do odczytu
* @param read - referencja do uchwytu ifstream
*/
void f_openFile(std::ifstream& read);

/*
* Utworzenie lub otwarcie istniejacego pliku do zapisu
* @param write - referencja do uchwytu ofstream
*/
void f_createFile(std::ofstream& write);

/*
* Sprawdzenie czy podana nazwa zawiera koncowke ".txt"
* @param name - nazwa pliku
* @return nazwa z rozszerzeniem ".txt"
*/
std::string f_ifTxt(std::string& name);


#endif