#include "ProgramaP1.h"
#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

// DeclaraciÃ³n de funciones
void inicializar(int [], int );
void escribirVector(int [], int );
void permutar(int & ,int & );

void insercionDirecta(int [], int );
void intercambioDirecta(int [], int );
void seleccionDirecta(int [], int );
void hundir(int [], int , int );
void heapSort(int [], int );


int main(){
    int opcion;
    // Para poder trabajar con vectores suficientemente grandes,
    // es necesario hacerlo con vectores dinÃ¡micos. Por lo tanto
    // en lugar de utilizar int v[100], utilizamos la siguiente
    // instrucciÃ³n para declarar el vector.
    int *v; //vector dinÃ¡mico
    int n;
    clock_t t1, t2;

    do{
    cout << "Selecciona un metodo de ordenacion: " << endl;
    cout << "1. Seleccion directa. " << endl;
    cout << "2. Insercion directa. " << endl;
    cout << "3. Burbuja. " << endl;
    cout << "4. HeapSort. " << endl;
    cout << "9. Salida. " << endl;
    cout << "Opcion: ";
    cin >> opcion;



    if(opcion == 9){
        return 0;
    }

    cout << "Introduce la dimension del vector: ";
    cin >> n;
    // La siguiente instrucciÃ³n nos construye el vector con la
    // dimensiÃ³n leÃ­da por teclado.
    v = new(int[n]); //por ser un vector dinÃ¡mico
    inicializar(v, n);
    cout <<endl<< "Datos sin ordenar: ";
    escribirVector(v, n);
        t1=clock();
    switch(opcion){
    case 1:{
        seleccionDirecta(v, n);
        }
        break;
    case 2:{
        insercionDirecta(v, n);
        }
        break;
    case 3:{
        intercambioDirecta(v, n);
        }
        break;
    case 4:{
        heapSort(v, n);
        }
        break;

    }
        t2=clock();

    cout <<endl<< "Datos ordenados: ";

    escribirVector(v, n);
        cout<<double(t2-t1)/CLOCKS_PER_SEC<<endl;
    }while(opcion!=9);

    return 0;
}


// Comentario: FunciÃ³n que inicializa el vector con nÃºmeros generados aleatoriamente.
// Se utilizan las funciones de <stdlib.h>:
// int rand(void) que genera nÃºmeros enteros entre 0 y RAND_MAX (32767)
// void srand(unsigned int seed) para que al cambiar la semilla la
// secuencia sea distinta en cada ejecuciÃ³n. Si deseamos aleatorizar
// sin tener que sembrar un nÃºmero cada vez, podemos utilizar la
// instrucciÃ³n srand(time(NULL)).

//PRE: v es un vector de enteros de tamaÃ±o n, n>0
//POST: inicializa el vector de enteros v, con n elementos de manera aleatoria
void inicializar(int v[], int n){
    long i;
    srand(time(NULL));
    for(i = 0; i < n; i++){
        //
        v[i] = rand()%100;
    }
}

//PRE: v es un vector de enteros de tamaÃ±o n, n>0
//POST: muestra por pantalla el contenido del vector v
void escribirVector(int v[], int n){
    int i;
    cout << endl << "( ";
    for(i = 0; i < n; i++)
    cout << v[i] << " ";
    cout << ")" << endl;
}


//PRE: v es un vector de enteros de tamaÃ±o n, n>0
//POST: se ordenan los elementos de v de menor a mayor siguiendo el mÃ©todo de selecciÃ³n directa
void seleccionDirecta(int v[], int n){
    int i, j, indmenor;  // i es el elemento a fijar
    for(i = 0; i < n-1; i++){
          indmenor = i;         // Se busca el menor
          for(j = i+1; j < n; j++){
                if(v[indmenor] > v[j]){
                        indmenor=j;
                }
          }
       permutar(v[i],v[indmenor]);
    }
}

//PRE: v es un vector de enteros de tamaÃ±o n, n>0
//POST: se ordenan los elementos de v de menor a mayor siguiendo el mÃ©todo de inserciÃ³n directa
void insercionDirecta(int v[], int n){
    int i, j, aux;  // i es el elemento a insertar;
     // j el punto a insertar
    // aux el auxiliar
    for(i = 1; i < n; i++){
          aux = v[i];       // InserciÃ³n del elemento i-Ã©simo
          j = i;                 // Iniciar centinela
           while(j>0 && v[j-1] > aux){  // Buscar punto de insercciÃ³n
               v[j] = v[j-1];
               j--;
           }
        v[j] = aux;

    }
}

//PRE: v es un vector de enteros de tamaÃ±o n, n>0
//POST: se ordenan los elementos de v de menor a mayor siguiendo el mÃ©todo de intercambio directo
void intercambioDirecta(int v[], int n){
    int i, j;    // i es el elemento a fijar
    for(i = 0; i < n-1; i++){
          for(j = 0; j < n-1-i; j++){
                if(v[j] > v[j+1]){
                    permutar(v[j],v[j+1]);
                }
          }
    }
}

//PRE: a y b enteros cualesquiera
//POST: intercambia el valor de la variable a en la variable b y viceversa
void permutar(int& a,int& b){
    int aux = a;
    a = b;
    b = aux;
}

//PRE: v es un vector de enteros de tamaÃ±o n, n>0, i es un entero que representa un elemento del vector, 0<=0<n
//POST: "hunde" el elemento i del vector v de tal manera que los elementos a la derecha de v[i] sean mayores que que v[i] y los de la izquierda sean menores.
void hundir(int v[], int n, int i){
    int j;
    do{
       j = i;        // Busca el hijo menor del nodo i
       if((2*j+1 < n) && (v[2*j+1] > v[i]))
               i = 2*j+1;
       if((2*j+2 < n) && (v[2*j+2] > v[i]))
               i = 2*j+2;
       permutar(v[i], v[j]);
    }while(i != j);
}

//PRE: v es un vector de enteros de tamaÃ±o n, n>0
//POST: se ordenan los elementos de v de menor a mayor siguiendo el mÃ©todo heapsort
void heapSort(int v[], int n){
    int i;
    for(i = n/2-1; 0 <= i; i--)
        hundir(v, n, i);
    for(i = n-1; 0 < i; i--){
        permutar(v[0], v[i]);
        hundir(v, i, 0);
    }
}
