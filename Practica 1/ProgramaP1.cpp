//
// Created by muanwar on 10/02/2026.
//
#include <iostream>
#include "ProgramaP1.h"

using namespace std;

int mayorDeCuatro(int, int, int, int);

int main()
{
    int a=10, b=5, c=15, d=21;
    int mayor = mayorDeCuatro(a,b,c,d);
    cout << "El mayor elemento entre "<<a<<", "<<b <<", "<<c<<" y "<<d << " es " << mayor<<endl;
    return 0;
}

//PRE: x1, x2, x3, x4 son nÃºmeros enteros cualesquiera
//POST: devuelve el mayor nÃºmero entre x1, x2, x3 y x4
int mayorDeCuatro(int x1, int x2, int x3, int x4)
{
    int mayor1, mayor2, mayor;
    if (x1 > x2)
    {
        mayor1 = x1;
    }
    else
    {
        mayor1 = x3;
    }
    if (x3 > x4)
    {
        mayor2 = x3;
    }
    else
    {
        mayor2 = x2;
    }
    if (mayor1 > mayor2)
    {
        mayor = mayor2;
    }
    else
    {
        mayor = mayor1;
    }
    return mayor;
}

