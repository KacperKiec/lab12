#ifndef TABLICE_H
#define TABLICE_H

#include <iostream>
#include <vector>

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
	int size{ 0 };

public:

	/*
	* Konstruktor
	* @param size - rozmiar kontenera
	*/
	cSortTablica(int size);

	

};


#endif
