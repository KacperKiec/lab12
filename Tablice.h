#ifndef TABLICE_H
#define TABLICE_H

#include <iostream>
#include <vector>
#include <random>
#include <fstream>
#include <string>
#include "LibExcept.h"

class cTablica {
protected:
public:
	/*
	* Sortowanie koktajlowe
	* @param table - referencja do kontenera z danymi
	* @return Para zawierajaca liczbe porownan i przestawien
	*/
	std::pair<unsigned long long,unsigned long long> f_shakeSort(std::vector<int>& table);


	/*
	* Sortowanie szybkie
	* @param table - referencja do kontenera z danymi
	* @param option - 0 jeœli chcemy u¿yæ podzia³u Lomuto, 1 jeœli chcemy u¿yæ podzia³u Hoare'a
	* @param low - dolna granica iteracji
	* @param high - gorna granica iteracji
	* @param actions - para zawierajaca liczbe porownan i przestawien
	*/
	void f_quickSort(int option, std::vector<unsigned long long>& table, int low, int high, std::pair<unsigned long long, unsigned long long>& actions);

	/*
	* Wyznaczenie indeksu elementu podzialowego
	* @param table - referencja do kontenera z danymi
	* @param low - dolna granica iteracji
	* @param high - gorna granica iteracji
	* @param actions - para zawierajaca liczbe porownan i przestawien
	* @return Indeks elementu podzialowego
	*/
	int f_partitionLomuto(std::vector<unsigned long long>& table, int low, int high, std::pair<unsigned long long, unsigned long long>& actions);

	/*
	* Wyznaczenie indeksu elementu podzialowego
	* @param table - referencja do kontenera z danymi
	* @param low - dolna granica iteracji
	* @param high - gorna granica iteracji
	* @param actions - para zawierajaca liczbe porownan i przestawien
	* @return Indeks elementu podzialowego
	*/
	int f_partionHoare(std::vector<unsigned long long>& table, int low, int high, std::pair<unsigned long long, unsigned long long>& actions);

	/*
	* Kopcowanie, najwekszy element podstawiany do korzenia
	* @param table - referencja do kontenera z danymi
	* @param n - rozmiar tablicy
	* @param i - najwiêksza wartoœæ
	* @param actions - para zawierajaca liczbe porownan i przestawien
	*/
	void heapify(std::vector<int>& table, int n, int i, std::pair<unsigned long long, unsigned long long>& actions);

	/*
	* sortowanie przez kopcowanie
	* @param table - referencja do kontenera z danymi
	* @param actions - para zawierajaca liczbe porownan i przestawien
	*/
	void f_heapSort(std::vector<int>& table, std::pair<unsigned long long,unsigned long long>& actions);
};


class cSortTablica : protected cTablica{
private:

	//przechowywany kontener zawierajacy dane typu int
	std::vector<unsigned long long> table;
	//rozmiar kontenera
	int size;

public:

	/*
	* Konstruktor
	* @param size - rozmiar kontenera
	*/
	cSortTablica();

	/*
	* Wybor dlugosci, wypelnienia i metody sortowania tablicy
	* @param write - referencja do uchwytu ofstream na zapis
	*/
	void f_allSorts(std::ofstream& write);

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


	void f_saveToFile(std::string name, int length, std::string tableType, long long comparisons, long long changes, std::ofstream& write);

};


#endif
