//
#include "dato.h"

class Nodo
{
    public:
        Nodo* obtener_siguiente ( void );
        Dato obtener_dato ( void );
        void establecer_dato ( Dato d );
        void establecer_siguiente ( Nodo* n ); 
        Nodo ( Dato d );
        ~Nodo ( void );       

    private:
        Dato d;
        Nodo* siguiente;
};
