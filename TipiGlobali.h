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

#endif  // TIPI_GLOBALI_H