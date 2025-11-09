
#include "nodo.h"

Nodo :: Nodo ( Dato _d ) : d ( _d ), siguiente ( nullptr ) { /* Empty */ }

Nodo :: ~Nodo ( void ) { /* Empty */ }

Nodo* Nodo :: obtener_siguiente ( void )
{
    return ( siguiente );
}

Dato Nodo :: obtener_dato ( void )
{
    return ( d );
}

void Nodo :: establecer_dato ( Dato d )
{
    this -> d = d;
}

void Nodo :: establecer_siguiente ( Nodo* n)
{
    this -> siguiente = n;
}
