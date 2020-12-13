#include <iostream>
#include <string>

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

/* Zadanie 1 - std::sort */

void zadanie1()
{
    std::vector< int > wektor = make_random_vector< int >(10, 0, 10);
    print_vector(wektor);
    std::sort(wektor.begin(), wektor.end());
    print_vector(wektor);
}

/* Zadanie 2 - std::count */

void zadanie2()
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

/* Zadanie 3 - std::sort - function as function word */

void zadanie3()
{
    std::vector< int > wektor = make_random_vector< int >(10, 0, 10);
    std::cout << "Wygenerowany wektor:" << std::endl;
    print_vector(wektor);
    std::sort(wektor.begin(), wektor.end(), czyWieksze);
    std::cout << "Wektor posortowany malejaco" << std::endl;
    print_vector(wektor);
}

/* Zadanie 4 - std::count_if - function as function word */

void zadanie4()
{
    std::vector< int > wektor = make_random_vector< int >(10, 0, 10);
    std::cout << "Wygenerowany wektor:" << std::endl;
    print_vector(wektor);
    std::sort(wektor.begin(), wektor.end());
    std::cout << "Posortowany wektor:" << std::endl;
    print_vector(wektor);
    std::cout << "Liczba wystapien elementow wiekszych od 7:" << std::endl;
    std::cout << std::count_if(wektor.begin(), wektor.end(), czyWiekszeOdSiedem) << std::endl;
}

/* Zadanie 6 - std::count_if - class as function word */

void zadanie6()
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

/* Zadanie 7 - std::count_if - lambda */

void zadanie7()
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

/* Ćwiczenie I - std::adjacent_find */

bool areBoolsEqual(char a, char b)
{
    return (a == b);
}

bool areTwoCharsInaRow()
{
    std::string s;
    std::cout << "Podaj zmienna typu string" << std::endl;
    std::cin >> s;
    std::string::iterator it = std::adjacent_find(s.begin(), s.end());
    if (it == s.end())
        return false;
    else {
        std::cout << "Znaleziono powtorzenie litery " << (*it) << std::endl;
        return true;
    }
}

/* Ćwiczenie II - std::search */

bool isPiesekOrKotekIn()
{
    std::string s;
    std::cout << "Podaj zmienna typu string" << std::endl;
    std::cin >> s;
    std::string           piesek = "piesek";
    std::string           kotek  = "kotek";
    std::string::iterator it     = std::search(s.begin(), s.end(), piesek.begin(), piesek.end());
    if (it == s.end()) {
        it = std::search(s.begin(), s.end(), kotek.begin(), kotek.end());
        if (it == s.end()) {
            return false;
        }
        else {
            std::cout << "Znaleziono podciag kotek" << std::endl;
            return true;
        }
    }
    else {
        std::cout << "Znaleziono podciag piesek" << std::endl;
        return true;
    }
}

int main()
{
    if (isPiesekOrKotekIn())
        std::cout << "Podciag piesek lub podciag kotek znaleziony" << std::endl;
    else
        std::cout << "Podciag piesek lub podciag kotek nie zostal znaleziony" << std::endl;
    return 0;
}

/* Po uruchomieniu otrzymano:
  Podaj zmienna typu string
  piesekotexD
  Znaleziono podciag piesek
  Podciag piesek lub podciag kotek znaleziony
*/