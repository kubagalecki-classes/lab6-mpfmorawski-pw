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

int main()
{
    std::vector< int > wektor = make_random_vector< int >(10, 0, 10);
    std::cout << "Wygenerowany wektor:" << std::endl;
    print_vector(wektor);
    std::sort(wektor.begin(), wektor.end(), czyWieksze);
    std::cout << "Wektor posortowany malejaco" << std::endl;
    print_vector(wektor);
    // std::cout << "Liczba wystapien elementu 7:" << std::endl;
    // std::cout << std::count(wektor.begin(), wektor.end(), 7) << std::endl;
}

/* Po uruchomieniu otrzymano:
  Wygenerowany wektor:
  6 8 0 6 8 8 9 0 5 4 
  Wektor posortowany malejaco
  9 8 8 8 6 6 5 4 0 0 
*/