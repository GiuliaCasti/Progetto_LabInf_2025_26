#ifndef GENERATORE_GRAFO_H
#define GENERATORE_GRAFO_H

#include "../TipiGlobali.h"

class GeneratoreGrafo {
public:
    // Genera il grafo di adiacenza per i soli nodi INTERNI di una griglia N x N.
    static Grafo generaGrafoInterno(int N);
};


#endif // GENERATORE_GRAFO_H