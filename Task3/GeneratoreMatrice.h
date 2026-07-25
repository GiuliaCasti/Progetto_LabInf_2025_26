#ifndef GENERATORE_MATRICE_H
#define GENERATORE_MATRICE_H

#include "../TipiGlobali.h"
#include <string>
#include <vector>

class GeneratoreMatrice {
public:
    // Genera le entrate della matrice A (stencil a 5 punti)
    static std::vector<ElementoMatrice> generaMatriceA(int N, double kappa, const std::vector<int>& perm);
};

#endif // GENERATORE_MATRICE_H