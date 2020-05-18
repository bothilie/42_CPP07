#include <iostream>


template <typename T>
void f(T const &a)
{
    std::cout << "Value is " << a << std::endl;
}



template <typename T>
void iter(T tab[], int taille, void (*f)(T const &))
{
    for (int i = 0; i < taille; i++)
    {
        f(tab[i]);
    }
}

int main()
{
    int tab[3] = {1, 3, 5};
    iter(tab, 3, f<int>);
    char tab2[3] = {'a', 'b', 'c'};
    iter(tab2, 3, f<char>);
    double tab3[3] = {12.34, 56.78, 90.12};
    iter(tab3, 3, f<double>);
}


