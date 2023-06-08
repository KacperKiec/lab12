#ifndef LIBEXCEPT_H
#define LIBEXCEPT_H

#include<exception>
#include <string>

namespace MyRunTimeExceptions {
	class FileOpenException : public std::runtime_error {
	public:
		FileOpenException() : runtime_error("Nie mozna otworzyc pliku") {
		}
		FileOpenException(std::string msg) : runtime_error(msg.c_str()) {
		}
	};
}

namespace MyLogicExceptions {
	class OutOfRangeException : public std::out_of_range {
	public:
		OutOfRangeException(): out_of_range("Poza zakresem!"){}
		OutOfRangeException(std::string msg) : out_of_range(msg.c_str()){}
	};
}


#endif
