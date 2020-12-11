#include <iostream>

#include "make_random_vector.hpp"

void print_vector(std::vector< int > wektor)
{
    for (const int i : wektor)
        std::cout << i << " ";
    std::cout << std::endl;
}

int main()
{
    std::vector< int > wektor = make_random_vector< int >(10, 0, 10);
    std::cout << "Wygenerowany wektor:" << std::endl;
    print_vector(wektor);
    std::sort(wektor.begin(), wektor.end());
    std::cout << "Posortowany wektor:" << std::endl;
    print_vector(wektor);
    std::cout << "Liczba wystapien elementu 7:" << std::endl;
    std::cout << std::count(wektor.begin(), wektor.end(), 7) << std::endl;
}

/* Po uruchomieniu otrzymano:
  10 10 6 9 1 3 10 10 2 6
  1 2 3 6 6 9 10 10 10 10
*/