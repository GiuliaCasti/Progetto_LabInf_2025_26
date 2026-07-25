#ifndef TIPI_GLOBALI_H
#define TIPI_GLOBALI_H

#include <vector>

// Struttura globale per il singolo punto 2D
struct Punto {
    double x;
    double y;
};

// Indice di un punto nella griglia o nel grafo
struct IndicePunto {
    int i; // indice x
    int j; // indice y
};

// Definizione globale della Griglia come vettore di Punto
using Griglia = std::vector<Punto>;

struct Nodo {
    int id; // ID del nodo
    IndicePunto indice; // Indice logico nella griglia
    Punto punto; // Coordinate del nodo
    std::vector<int> adiacenti; // Indici dei nodi adiacenti
};

struct Arco{
    int id;
    int nodo1; // ID del primo nodo
    int nodo2; // ID del secondo nodo
};

// Nodi è un std::vector<Nodo> contenente tutti i nodi del grafo, dove ogni Nodo ha un ID, un IndicePunto, un Punto e una lista di adiacenti.
using Nodi = std::vector<Nodo>;

// Archi è un std::vector Arco> contenente tutti gli archi del grafo, dove ogni Arco ha un ID e due ID di nodi.
using Archi = std::vector<Arco>;

// Struttura che rappresenta la mappatura tra nuovo e vecchio indice
struct MappaturaNodo {
    int nuovoIndice;
    int vecchioId;
};

// Elemento della matrice sparsa in formato Coordinate (COO)
struct ElementoMatrice {
    int i;         // Indice di riga
    int j;         // Indice di colonna
    double valore; // Valore A[i, j]
};

#endif  // TIPI_GLOBALI_H