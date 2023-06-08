#include "LibFiles.h"

void f_openFile(std::ifstream& read) {
	//nazwa pliku
	std::string name;
	std::cout << "Podaj nazwe pliku do odczytu: "; std::cin >> name;

	f_ifTxt(name);

	read.open(name);
	if (!read) throw MyRunTimeExceptions::FileOpenException();
}

void f_createFile(std::ofstream& write) {
	//nazwa pliku
	std::string name;
	std::cout << "Podaj nazwe pliku do zapisu: ";  std::cin >> name;

	f_ifTxt(name);

	write.open(name);
	if (!write) throw MyRunTimeExceptions::FileOpenException();;
}

std::string f_ifTxt(std::string& name) {
	//dlugosc nazwy
	int length = name.length() - 1;
	if (length < 4) {
		name += ".txt";
		return name;
	}

	if (name[length] != char(116) && name[length - 1] != char(120) && name[length - 2] != char(116) && name[length - 3] != char(46)) {
		name += ".txt";
	}

	return name;
}

