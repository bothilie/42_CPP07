#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>
#include <iostream>

template <typename T>
class Array 
{
    private:
        T *tab;
        unsigned int _size;
    public:
        Array();
        Array(unsigned int n);
        ~Array();
        class ExcessSizeException: public std::exception {
            virtual const char *what() const throw();
        };
        Array(Array const &a) ;
        Array &operator=(Array const &a);
        T &operator[](unsigned int i) ;
        T const &operator[](unsigned int i) const;
        unsigned int    size() const ;
};

template <typename T>
Array<T>::Array() 
{
    _size = 0;
}

template <typename T>
Array<T>::Array(unsigned int n)
{
    tab = new T[n];
    _size = n;
}

template <typename T>
Array<T>::~Array()
{
    delete[] tab;
}

template <typename T>        
const char *Array<T>::ExcessSizeException::what() const throw() 
{
        return "The element of the array is not reachable";
}


template <typename T>       
Array<T>::Array(Array const &a)
        {
            this->_size = a._size;
            if (a.size() > 0)
            {
                this->tab = new T[a._size];
                for (unsigned int i = 0; i < _size; i++)
                {
                    this->tab[i] = a.tab[i];
                }
            }
            else
                tab = NULL;
        }

template <typename T>
Array<T>       &Array<T>::operator=(Array const &a)
{
    if (_size)
        delete[] tab;
    this->_size = a._size;
    if (a.size() > 0)
    {
        this->tab = new T[a._size];
        for (unsigned int i = 0; i < _size; i++)
        {
            this->tab[i] = a.tab[i];
        }
    }
    else
        tab = NULL;
    return *this;
}

template <typename T>
T           &Array<T>::operator[](unsigned int i)
{
    if (i > _size || _size == 0)
        throw Array::ExcessSizeException();
    return tab[i];
}

template <typename T>
const T           &Array<T>::operator[](unsigned int i) const
{
    if (i > _size || _size == 0)
        throw Array::ExcessSizeException();
    return tab[i];
}

template <typename T>
unsigned int    Array<T>::size() const
{
    return _size;
}

#endif