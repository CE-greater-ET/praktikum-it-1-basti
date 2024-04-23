//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXIV
// Versuch 02
//
// Datei:  main.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include <iostream>

long int fibonacci(int n)
{
    if(n == 0)
    {
        return 0;
    }
    if(n == 1)
    {
        return 1;
    }

    long int previousFib = 0;
    long int currentFib = 1;

    for (int i = 0; i <= n; i++)
    {
        long int newFib = previousFib + currentFib ;
        previousFib = currentFib ;
        currentFib = newFib;
    }
    return currentFib;
}

int main ()
{
    std::cout << " Fibonacci - Zahlen von 0 bis 12:" << std::endl ;
    for (int i = 1; i <= 12 ; i ++)
    {
        std::cout << "f(" << i << ") = " << fibonacci(i) << std::endl ;
    }


    std::cout << "nun 47" << std::endl;

    std::cout << fibonacci(47) << std::endl;

    return 0;
}
