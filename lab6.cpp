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
    czyWiekszeOda czyWiekszeOdPodanea{a};
    std::cout << "Liczba wystapien elementow wiekszych od podanej liczby:" << std::endl;
    std::cout << std::count_if(wektor.begin(), wektor.end(), czyWiekszeOdPodanea) << std::endl;
}

/* Po uruchomieniu otrzymano:
  Wygenerowany wektor:
  8 2 5 2 10 1 10 0 1 6 
  Posortowany wektor:
  0 1 1 2 2 5 6 8 10 10 
  Podaj liczbe:
  2
  Liczba wystapien elementow wiekszych od podanej liczby:
  5
*/