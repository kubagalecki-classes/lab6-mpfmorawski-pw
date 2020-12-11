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
  3 1 2 0 6 3 0 7 10 4
  Posortowany wektor:
  0 0 1 2 3 3 4 6 7 10
  Liczba wystapien elementu 7:
  1
*/