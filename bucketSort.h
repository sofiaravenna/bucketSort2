//
// Created by Ciro on 26/9/2023.
//

#ifndef BUCKETSORT2_BUCKETSORT_H
#define BUCKETSORT2_BUCKETSORT_H
#define SIZE 1O
typedef struct nodo{
    int num;
    struct nodo* sig;
}Nodo;

typedef struct lista{
    Nodo * cabecera;
}Lista;

typedef struct hashtable{
    Nodo * array[SIZE]
}HashTable;



Nodo* newNodo(int valor);
Lista * newLista();
void Hashing(Lista * lista);
void printArray(int array[], int size);
void bucketSort(int array[], int size);
void insertar(Nodo *tablaHash[], int nodo, int pos);
int hashU(int num);
int hashD(int num);
int hashC(int num);
void ordenarFilas(Nodo *tablaHash[]);
void concatenar(Nodo *tablaHash[]);

#endif //BUCKETSORT2_BUCKETSORT_H
