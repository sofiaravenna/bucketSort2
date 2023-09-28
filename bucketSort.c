//
// Created by Ciro on 26/9/2023.
//

#include "bucketSort.h"
#include <stdio.h>
#include <stdlib.h>
Nodo *newNodo(int valor) {
    Nodo * aux = NULL;
    aux= malloc(sizeof(Nodo));
    if(aux==NULL){
        printf("ERROR al asignar memoria.\n");
        exit(-1);
    }else{
        aux->num=valor;
        aux->sig=NULL;
    }
    return aux;
}

Lista *newLista() {
    Lista * aux = NULL;
    aux= malloc(sizeof(Lista));
    if(aux==NULL){
        printf("ERROR al asignar memoria.\n");
        exit(-1);
    }else{
        aux->cabecera=NULL;
    }
    return aux;
}
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}


int hashU(int num) {
    return num%10;
}
int hashD(int num) {
    return (num / 10) % 10;;
}
int hashC(int num) {
    return  num / 100;
}
void ordenarFilas(Nodo ** tablaHash) {
    for (int i = 0; i < SIZE; ++i) {
        Nodo* act= tablaHash[i];
        while (act != NULL){
            Nodo * min =act;
            Nodo * temp= act->sig;
            while (temp!= NULL){
                if(temp->num<min->num){
                    min=temp;
                }
                temp=temp->sig;
            }
            int tempnum= act->num;
            act->num= min->num;
            min->num=tempnum;
            act= act->sig;
        }
    }

}


void insertar(Nodo ** tablaHash, Nodo* nodoInsertar, int resultado) {
    int resultado= hashU(num);
    Nodo * nodoInsertar = newNodo(num);

    if(tablaHash[resultado]==NULL){
        tablaHash[resultado]=nodoInsertar;
    } else{
        nodoInsertar->sig=tablaHash[resultado];
        tablaHash[resultado]=nodoInsertar;
    }
}
void concatenar(Nodo *tablaHash[]) {
    Nodo * aux= tablaHash[0];
    for (int i = 0; i < SIZE; ++i) {
        while (aux != NULL){
            aux=aux->sig;
        }
        aux=tablaHash[i+1];
    }
}

void bucketSort(int *array, int sizeArray,Nodo *tablaHash[]) {
    for (int i = 0; i < sizeArray; ++i) {
        insertar(Nodo *tablaHash[], newNodo(array[i]), hashU(array[i]));
    }
    ordenarFilas(Nodo *tablaHash[]);
    concatenar();
    for (int i = 0; i < sizeArray; ++i) {
        insertar(Nodo *tablaHash[], newNodo(array[i]), hashD(array[i]));
    }
    ordenarFilas();
    concatenar();
    for (int i = 0; i < sizeArray; ++i) {
        insertar(Nodo *tablaHash[], newNodo(array[i]), hashC(array[i]));
    }
    ordenarFilas();
    concatenar();

}



