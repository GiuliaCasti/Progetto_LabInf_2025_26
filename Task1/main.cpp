#include <iostream>
#include "../TipiGlobali.h"
#include "GeneratoreGriglia.h"


void stampaGriglia(const Griglia& griglia) {
    std::cout << "Punti generati (Totale: " << griglia.size() << "):\n";
    for (size_t k = 0; k < griglia.size(); ++k) {
        std::cout << "Punto " << k << ": (" 
                  << griglia[k].x << ", " 
                  << griglia[k].y << ")\n";
    }
}

int main(int argc, char* argv[]) {
    int N = 1; // Discretizzazione 3x3 (combinazione di 0.0, 0.5, 1.0)

    Griglia griglia = GeneratoreGriglia::generaGriglia(N);

    // Stampa dei punti generati
    stampaGriglia(griglia);
}