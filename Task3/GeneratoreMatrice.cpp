#include "GeneratoreMatrice.h"
#include <fstream>
#include <iostream>

std::vector<ElementoMatrice> GeneratoreMatrice::generaMatriceA(int N, double kappa, const std::vector<int>& perm) {
    std::vector<ElementoMatrice> A;
    const double h = 1.0 / (N + 1);
    const double coeff = kappa / (h * h);

    auto getOldId = [N](int i_int, int j_int) {
        return i_int * N + j_int;
    };

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            int oldId = getOldId(i - 1, j - 1);
            int row = perm[oldId]; // Riga riordinata

            // Diagonale principale: -4 * (kappa / h^2)
            A.push_back({row, row, -4.0 * coeff});

            // Vicini interni
            if (i > 1) A.push_back({row, perm[getOldId(i - 2, j - 1)], coeff}); // Sinistra
            if (i < N) A.push_back({row, perm[getOldId(i, j - 1)], coeff});     // Destra
            if (j > 1) A.push_back({row, perm[getOldId(i - 1, j - 2)], coeff}); // Basso
            if (j < N) A.push_back({row, perm[getOldId(i - 1, j)], coeff});     // Alto
        }
    }

    return A;
}