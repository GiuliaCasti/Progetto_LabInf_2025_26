#ifndef TIPI_GLOBALI_H
#define TIPI_GLOBALI_H

#include <vector>

// Struttura globale per il singolo punto 2D
struct Punto {
    double x;
    double y;
};

// Definizione globale della Griglia come vettore di Punto
using Griglia = std::vector<Punto>;

struct Nodo {
    int id; // ID del nodo
    Punto punto; // Coordinate del nodo
    std::vector<int> adiacenti; // Indici dei nodi adiacenti
};

// Grafo[u] è un std::vector<int> contenente gli indici dei nodi adiacenti al nodo 'u'
using Grafo = std::vector<Nodo>;

#endif  // TIPI_GLOBALI_H