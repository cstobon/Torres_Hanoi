
#include "nodo.h"

class Pila
{
    public:
        Nodo* pop ( void );
        void push ( Nodo* n );
        int tamano_pila ( void );
        Nodo* cima ( void );
        void imprimir ( void );      
        Pila ( void );
        ~Pila ( void ); 
    
 
    private:
        int size;
        Nodo* raiz;
};
