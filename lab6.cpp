#include <iostream>

#include "make_random_vector.hpp"

void print_vector(std::vector< int > wektor)
{
    for (const int i : wektor)
        std::cout << i << " ";
    std::cout << std::endl;
}

bool czyWieksze(int i, int j)
{
    return (i > j);
}

bool czyWiekszeOdSiedem(int i)
{
    return (i > 7);
}

// Zmienna globalna
int a;

bool czyWiekszeOda(int i)
{
    return (i > a);
}

int main()
{
    std::vector< int > wektor = make_random_vector< int >(10, 0, 10);
    std::cout << "Wygenerowany wektor:" << std::endl;
    print_vector(wektor);
    std::sort(wektor.begin(), wektor.end());
    std::cout << "Posortowany wektor:" << std::endl;
    print_vector(wektor);
    std::cout << "Podaj liczbe:" << std::endl;
    std::cin >> a;
    std::cout << "Liczba wystapien elementow wiekszych od podanej liczby:" << std::endl;
    std::cout << std::count_if(wektor.begin(), wektor.end(), czyWiekszeOda) << std::endl;
}

/* Po uruchomieniu otrzymano:
  Wygenerowany wektor:
  10 7 2 9 6 4 4 1 0 6 
  Posortowany wektor:
  0 1 2 4 4 6 6 7 9 10 
  Podaj liczbe:
  2
  Liczba wystapien elementow wiekszych od podanej liczby:
  7
*/