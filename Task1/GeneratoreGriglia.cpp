#include <iostream>
#include "GeneratoreGriglia.h"

Griglia GeneratoreGriglia::generaGriglia(int N) {
    if (N < 0) {
        std::cerr << "Attenzione: N deve essere >= 0 per formare una griglia valida.\n";
        return {};
    }

    Griglia griglia;
    griglia.reserve((N + 2) * (N + 2));

    double h = 1.0 / (N + 1);

    for (int i = 0; i < N + 2; ++i) {
        double x = i * h;
        for (int j = 0; j < N + 2; ++j) {
            double y = j * h;
            griglia.push_back({x, y});
        }
    }

    return griglia;
}