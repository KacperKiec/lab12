#ifndef TABLICE_H
#define TABLICE_H

#include <iostream>
#include <vector>

class cTablica {
protected:
	std::pair<int, int> f_shakeSort(std::vector<int>& table);
	void f_quickSortLomuto(std::vector<int>& table);
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

	/*
	* Wypelnienie kontenera zadana liczba losowych elementow
	*/
	void f_fillWithRand();

	/*
	* Wypelnienie kontenera zadana liczba podanych przez uzytkownika elementow
	*/
	void f_fillManual();

};


#endif
