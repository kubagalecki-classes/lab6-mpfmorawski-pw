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

/* Ćwiczenie I */

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

int main()
{
    if (areTwoCharsInaRow())
        std::cout << "Para znaleziona" << std::endl;
    else
        std::cout << "Para nie zostala znaleziona" << std::endl;
}

/* Po uruchomieniu otrzymano:
  Podaj zmienna typu string
  Football
  Znaleziono powtorzenie litery o
  Para znaleziona
*/