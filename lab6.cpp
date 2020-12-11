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

class czyWiekszeOda
{
public:
    czyWiekszeOda(int a_) : a{a_} {}
    int  a;
    bool operator()(int i) { return (i > a); }
};

int main()
{
    std::vector< int > wektor = make_random_vector< int >(10, 0, 10);
    std::cout << "Wygenerowany wektor:" << std::endl;
    print_vector(wektor);
    std::sort(wektor.begin(), wektor.end());
    std::cout << "Posortowany wektor:" << std::endl;
    print_vector(wektor);
    int a;
    std::cout << "Podaj liczbe:" << std::endl;
    std::cin >> a;
    std::cout << "Liczba wystapien elementow wiekszych od podanej liczby:" << std::endl;
    std::cout << std::count_if(wektor.begin(), wektor.end(), [&](int i) { return (i > a); })
              << std::endl;
}

/* Po uruchomieniu otrzymano:
  Wygenerowany wektor:
  3 8 7 6 6 9 8 10 9 5 
  Posortowany wektor:
  3 5 6 6 7 8 8 9 9 10 
  Podaj liczbe:
  3
  Liczba wystapien elementow wiekszych od podanej liczby:
  9
*/