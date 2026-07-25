#include "GeneratoreTermineNoto.h"
#include <fstream>
#include <iostream>

std::vector<double> GeneratoreTermineNoto::generaTermineNoto(int N, 
                                                             double kappa, 
                                                             FunzioneSorgente f, 
                                                             FunzioneBordo g, 
                                                             const std::vector<int>& perm) {
    const int numNodiInterni = N * N;
    std::vector<double> rhs(numNodiInterni, 0.0);
    const double h = 1.0 / (N + 1);
    const double coeff = kappa / (h * h);

    auto getOldId = [N](int i_int, int j_int) {
        return i_int * N + j_int;
    };

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            int oldId = getOldId(i - 1, j - 1);
            int row = perm[oldId];

            double x = i * h;
            double y = j * h;

            // Inizializza con il termine sorgente f(x, y)
            double val = -f(x, y);

            // Incorpora i valori noti di bordo Dirichlet g(x, y)
            if (i == 1) val -= coeff * g(0.0, y); // Bordo sinistro
            if (i == N) val -= coeff * g(1.0, y); // Bordo destro
            if (j == 1) val -= coeff * g(x, 0.0); // Bordo inferiore
            if (j == N) val -= coeff * g(x, 1.0); // Bordo superiore

            rhs[row] = val;
        }
    }

    return rhs;
}