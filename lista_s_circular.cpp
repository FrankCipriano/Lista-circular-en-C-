#include <iostream>
using namespace std;

typedef struct nodo{
    int valor;
    struct nodo *siguiente;
}tipoNodo;

typedef tipoNodo *pNodo;
typedef tipoNodo *Lista;

//funciones con listas
void insertar(Lista *l,int v);
void borrar(Lista *l,int v);

int ListaVacia(Lista l);

void borrarLista(Lista *);
void mostrarLista(Lista l);

int main(){
    Lista lista=NULL;
    pNodo p;
    cout<<"Insertando los valores 20,10,40 y 30 a la lista\n";
    insertar(&lista,20);
    insertar(&lista,10);
    insertar(&lista,40);
    insertar(&lista,30);
    cout<<"Mostrando los valores insertados de forma ordenada\n";
    mostrarLista(lista);
    cout<<"Borrando los elementos 10,15,45,30 y 20 de la lista..........\n";
    borrar(&lista,10);
    borrar(&lista,15);
    borrar(&lista,45);
    borrar(&lista,30);
    borrar(&lista,20);
    cout<<"Los elementos restantes de la lista son:\n";
    mostrarLista(lista);
    cout<<"Eliminando la lista......\n";
    borrarLista(&lista);
    cout<<"Lista existente? "<<lista;
    return 0;
}
void insertar(Lista *lista,int v){
    pNodo nuevo,anterior;
    //crear un nuevo nodo
    nuevo=(pNodo)malloc(sizeof(tipoNodo));
    nuevo->valor=v;
    //si la lista esta vacia!!!
    if(ListaVacia(*lista) || (*lista)->valor > v){
        //añadimos la lista a continuacion del nuevo nodo
        nuevo->siguiente=*lista;
        //ahora, el comienzo de nuestra lista es en nuevo nodo
        *lista=nuevo;
    }else{
        //buscar el nodo de valor menor a v
        anterior=*lista;
        //avanzamos hasta el ultimo elemento o hasta que el siguiente tenga un valor mayor que v
        while(anterior->siguiente && anterior->siguiente->valor <= v)
        anterior=anterior->siguiente;
        //insertamos el nuevo nodo despues del nodo anterior
        nuevo->siguiente=anterior->siguiente;
        anterior->siguiente=nuevo;
    }
}
void borrar(Lista *lista,int v){
    pNodo anterior,nodo;
    nodo=*lista;
    anterior=NULL;
    while(nodo && nodo->valor < v){
        anterior=nodo;
        nodo=nodo->siguiente;
    }
    if(!nodo || nodo->valor != v)return;
    else{
        //borrar el nodo
        if(!anterior)//primer elemento
        *lista=nodo->siguiente;
        else//un elemento cualquiera
        anterior->siguiente=nodo->siguiente;
        free(nodo);
    }
}
int ListaVacia(Lista lista){
    return(lista==NULL);
}
void borrarLista(Lista *lista){
    pNodo nodo;
    while(*lista){
        nodo=*lista;
        *lista=nodo->siguiente;
        free(nodo);
    }
}
void mostrarLista(Lista lista){
    pNodo nodo=lista;
     if(ListaVacia(lista))cout<<"Lista vacia\n";
    else{
        while(nodo){
            cout<<"Valor: "<<nodo->valor<<"\n";
            nodo=nodo->siguiente;
        }
        cout<<"\n";
    }
}