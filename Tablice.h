#ifndef TABLICE.H
#define TABLICE.H

#include <iostream>
#include <vector>

class cTablica {
protected:
	void f_shakeSort(std::vector<int> table);
	void f_quickSortLomuto(std::vector<int> table);
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
	* Wypelnienie kontenera losowymi liczbami
	*/
	void f_fillWithRand();

};


#endif
