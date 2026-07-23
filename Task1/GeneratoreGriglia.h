#ifndef GRID_GENERATOR_H
#define GRID_GENERATOR_H

#include "../TipiGlobali.h"

class GeneratoreGriglia {
public:
    // Genera la griglia [0, 1]^2 con discretizzazione (N+2) x (N+2) (bordo incluso)
    // +2 per includere i bordi (0 e 1) nella griglia
    // N = 0 -> 2x2 griglia (punti: (0,0), (0,1), (1,0), (1,1))
    static Griglia generaGriglia(int N);
};

#endif // GRID_GENERATOR_H