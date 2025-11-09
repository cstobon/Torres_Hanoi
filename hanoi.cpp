//Autores : Edgar Tobon Sosa, Moises Alejandro Sanchez Vergara
//Materia : Programacion Avanzada
//Proyecto: torres de Hanoi
//Fecha   : 8.11.2025

//Cabeceras
#include <iostream>
#include "pila.h"

//Espacios de nombre
using namespace std;

//Declaracion rutina hanoi
void hanoi(int *movimientos, int n, Pila* pila_origen, Pila* pila_auxiliar, Pila* pila_destino, 
           Pila* pila_a, Pila* pila_b, Pila* pila_c, 
           char origen, char auxiliar, char destino, int num_discos_total);

void generar_pila_inicial (Pila* pila, int discos [], int size );

void mostrar_torres(Pila* pila_A, Pila* pila_B, Pila* pila_C, int num_discos);

void obtener_discos_pila(Pila* pila, int discos[], int max_discos);

//Rutina principal 
int main ( void )
{
    Pila* pila_a = new Pila ();
    Pila* pila_b = new Pila ();
    Pila* pila_c = new Pila ();

    int* movimientos = new int (0);
    int discos[] = {3, 2, 1};
 
    generar_pila_inicial ( pila_a, discos, 3 );
    
    cout << "\n=== ESTADO INICIAL ===" << endl;
    mostrar_torres(pila_a, pila_b, pila_c, 3);
    
    hanoi(movimientos, 3, pila_a, pila_b, pila_c, pila_a, pila_b, pila_c, 'A', 'B', 'C', 3);

    cout << "\n=== ESTADO FINAL ===" << endl;
    mostrar_torres(pila_a, pila_b, pila_c, 3);
    cout << "\nTotal de movimientos: " << *movimientos << endl;

    delete pila_a;
    delete pila_b;
    delete pila_c;
    delete movimientos;

    return ( 0 );
}

//Definicion rutina hanoi
void hanoi(int* movimientos, int n, Pila* pila_origen, Pila* pila_auxiliar, Pila* pila_destino, 
           Pila* pila_a, Pila* pila_b, Pila* pila_c, 
           char origen, char auxiliar, char destino, int num_discos_total){
    if(n == 1){
        Nodo* disco = pila_origen -> pop ();
        pila_destino -> push ( disco );
        (*movimientos)++;
        
        cout << "\nMovimiento " << *movimientos << ": Mover disco de Torre " << origen << " a Torre " << destino << endl;
        mostrar_torres(pila_a, pila_b, pila_c, num_discos_total);
    } else {
        hanoi(movimientos, n - 1, pila_origen, pila_destino, pila_auxiliar, 
              pila_a, pila_b, pila_c, 
              origen, destino, auxiliar, num_discos_total);
        
        Nodo* disco = pila_origen -> pop ();
        pila_destino -> push ( disco );  
        (*movimientos)++;
        
        cout << "\nMovimiento " << *movimientos << ": Mover disco de Torre " << origen << " a Torre " << destino << endl;
        mostrar_torres(pila_a, pila_b, pila_c, num_discos_total);
        
        hanoi(movimientos, n - 1, pila_auxiliar, pila_origen, pila_destino, 
              pila_a, pila_b, pila_c, 
              auxiliar, origen, destino, num_discos_total);
    }
}

void generar_pila_inicial (Pila* pila, int discos [], int size )
{
    for ( int i = 0; i < size; i ++ )
    {
        Nodo* disco = new Nodo (discos [i]);
        pila -> push ( disco );
    }
}

// Función auxiliar para obtener los discos de una pila en un array
void obtener_discos_pila(Pila* pila, int discos[], int max_discos) {
    Nodo* actual = pila -> cima();
    int i = 0;
    
    while (actual != nullptr && i < max_discos) {
        discos[i] = actual -> obtener_dato().value();
        actual = actual -> obtener_siguiente();
        i++;
    }
    
    // Rellenar el resto con 0
    for (; i < max_discos; i++) {
        discos[i] = 0;
    }
}

// Función para mostrar las tres torres de forma visual
void mostrar_torres(Pila* pila_A, Pila* pila_B, Pila* pila_C, int num_discos) {
    int discos_A[num_discos], discos_B[num_discos], discos_C[num_discos];
    
    obtener_discos_pila(pila_A, discos_A, num_discos);
    obtener_discos_pila(pila_B, discos_B, num_discos);
    obtener_discos_pila(pila_C, discos_C, num_discos);
    
    cout << "\n    Torre A          Torre B          Torre C" << endl;
    cout << "    -------          -------          -------" << endl;
    
    for (int i = 0; i < num_discos; i++) {
        // Torre A
        cout << "      ";
        if (discos_A[i] > 0) {
            cout << "[" << (discos_A[i] < 10 ? " " : "") << discos_A[i] << "]";
        } else {
            cout << " | ";
        }
        
        // Torre B
        cout << "            ";
        if (discos_B[i] > 0) {
            cout << "[" << (discos_B[i] < 10 ? " " : "") << discos_B[i] << "]";
        } else {
            cout << " | ";
        }
        
        // Torre C
        cout << "            ";
        if (discos_C[i] > 0) {
            cout << "[" << (discos_C[i] < 10 ? " " : "") << discos_C[i] << "]";
        } else {
            cout << " | ";
        }
        
        cout << endl;
    }
    
    cout << "   =========       =========       =========" << endl;
}
