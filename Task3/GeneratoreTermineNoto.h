#ifndef GENERATORE_TERMINE_NOTO_H
#define GENERATORE_TERMINE_NOTO_H

#include "../TipiGlobali.h"
#include <string>
#include <vector>
#include <functional>

using FunzioneSorgente = std::function<double(double, double)>;
using FunzioneBordo = std::function<double(double, double)>;

class GeneratoreTermineNoto {
public:
    // Genera il vettore b incorporando il termine sorgente f(x,y) e le condizioni al bordo g(x,y)
    static std::vector<double> generaTermineNoto(int N, 
                                                 double kappa, 
                                                 FunzioneSorgente f, 
                                                 FunzioneBordo g, 
                                                 const std::vector<int>& perm);
};

#endif // GENERATORE_TERMINE_NOTO_H