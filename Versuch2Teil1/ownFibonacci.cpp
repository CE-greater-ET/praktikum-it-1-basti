//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXIV
// Versuch 02
//
// Datei:  main.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include <iostream>

int fibonacci(int n)
{
	if (n == 0) {
		return 0;
	}
	if (n == 1) {
		return 1;
	}
	return fibonacci(n-1) + fibonacci(n-2);
}

int main ()
{
    std::cout << " Fibonacci - Zahlen von 0 bis 25:" << std::endl ;

    for (int i = 0; i < 25; i++) {
    	std::cout << fibonacci(i) << std::endl;
    }

    return 0;
}
