#include "pila.h"
#include <iostream>

using namespace std;
//Constructores
Pila :: Pila () : size (0), raiz ( nullptr ){};

Pila :: ~Pila () {};
//Entrada : Nodo*
//Salida : Void
//Complejidad : O ( 1 )
//Descripcion : Agregamos un nuevo nodo a la raiz de la lista
void Pila :: push (Nodo* n)
{
   
    n -> establecer_siguiente ( this -> raiz ); 
    
    this -> raiz = n; //Asignamos al nuevo nodo como raiz de la lista

    size += 1; //Aumentos el size de la pila en uno      

}

Nodo* Pila :: pop ( void )
{
    if ( this -> raiz == nullptr )
        return nullptr;

    Nodo* temp = this -> raiz; //Variable temporal almacenar el nodo raiz

    this -> raiz = temp -> obtener_siguiente (); //Asignamos nueva raiz

    size -= 1; //Decrementamos en uno el tamano de la pila

    return ( temp );
}

//Entrada: void
//Salida: numero de elementos en la pila
//Complejidad : O(1)
int Pila :: tamano_pila ( void )
{
    return ( size );
}

Nodo* Pila :: cima ( void )
{
    return ( raiz );
}

void Pila :: imprimir ( void ) 
{
    Nodo* nodo = raiz;

    while ( nodo != nullptr )

    {
        cout << "nodo (valor) : " << nodo -> obtener_dato ().value () << endl;
        nodo = nodo -> obtener_siguiente (); 
    }
}
