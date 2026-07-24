#ifndef GENERATORE_GRAFO_H
#define GENERATORE_GRAFO_H

#include "../TipiGlobali.h"

class GeneratoreGrafo {
public:
    // Genera il grafo di adiacenza per i soli nodi INTERNI di una griglia N x N.
    static Nodi generaNodiInterni(int N);

    // Genera gli archi di adiacenza per i soli nodi INTERNI di una griglia N x N.
    static Archi generaArchiInterni(const Nodi& nodi);
};


#endif // GENERATORE_GRAFO_H