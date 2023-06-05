#ifndef TABLICE_H
#define TABLICE_H

#include <iostream>
#include <vector>
#include <random>
#include <fstream>
#include <string>

class cTablica {
protected:

	/*
	* Sortowanie koktajlowe
	* @param table - referencja do kontenera z danymi
	* @return Para zawierajaca liczbe porownan i przestawien
	*/
	std::pair<int, int> f_shakeSort(std::vector<int>& table);

	/*
	* Sortowanie szybkie z podzialem Lomuto
	* @param table - referencja do kontenera z danymi
	* @param low - dolna granica iteracji
	* @param high - gorna granica iteracji
	* @param actions - para zawierajaca liczbe porownan i przestawien
	*/
	void f_quickSortLomuto(std::vector<int>& table, int low, int high, std::pair<int, int>& actions);

	/*
	* Wyznaczenie indeksu elementu podzialowego
	* @param table - referencja do kontenera z danymi
	* @param low - dolna granica iteracji
	* @param high - gorna granica iteracji
	* @param actions - para zawierajaca liczbe porownan i przestawien
	* @return Indeks elementu podzialowego
	*/
	int f_partitionLomuto(std::vector<int>& table, int low, int high, std::pair<int, int>& actions);
};


class cSortTablica : protected cTablica{
private:

	//przechowywany kontener zawierajacy dane typu int
	std::vector<int> table;
	//rozmiar kontenera
	int size;

public:

	/*
	* Konstruktor
	* @param size - rozmiar kontenera
	*/
	cSortTablica(int size);

	/*
	* Wybor dlugosci, wypelnienia i metody sortowania tablicy
	* @param write - referencja do uchwytu ofstream na zapis
	*/
	void f_chooseSort(std::ofstream& write);

protected:
	/*
	* Wypelnienie w kontenerze zadanej liczby elementow liczbami losowymi
	* @param numbers - zadana liczba elementow
	*/
	void f_fillWithRandom(int numbers);

	/*
	* Wypelnienie w kontenerze zadanej liczby elementow liczbami podanymi przez uzytkownika
	* @param numbers - zadana liczba elementow
	*/
	void f_fillManual(int numbers);


	void f_saveToFile(std::string name, int length, std::string tableType, int comparisons, int changes, std::ofstream& write);

};


#endif
