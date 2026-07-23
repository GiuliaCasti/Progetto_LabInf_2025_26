#include <iostream>
#include "../TipiGlobali.h"
#include "GeneratoreGriglia.h"
#include "GeneratoreGrafo.h"


void stampaGriglia(const Griglia& griglia) {
    std::cout << "Punti generati (Totale: " << griglia.size() << "):\n";
    for (size_t k = 0; k < griglia.size(); ++k) {
        std::cout << "Punto " << k << ": (" 
                  << griglia[k].x << ", " 
                  << griglia[k].y << ")\n";
    }
}

void stampaGrafo(const Grafo& grafo) {
    std::cout << "Nodi del grafo generati (Totale: " << grafo.size() << "):\n";
    for (size_t k = 0; k < grafo.size(); ++k) {
        std::cout << "Nodo " << grafo[k].id << ": (" 
                  << grafo[k].punto.x << ", " 
                  << grafo[k].punto.y << ") -> Adiacenti: [ ";
        
        // Stampa dei vicini adiacenti
        for (size_t j = 0; j < grafo[k].adiacenti.size(); ++j) {
            std::cout << grafo[k].adiacenti[j] << " ";
        }
        
        std::cout << "]\n";
    }
}

int main(int argc, char* argv[]) {
    int N = 3; // Discretizzazione 3x3 (combinazione di 0.0, 0.5, 1.0)

    Griglia griglia = GeneratoreGriglia::generaGriglia(N);

    // Stampa dei punti generati
    stampaGriglia(griglia);

    Grafo grafo = GeneratoreGrafo::generaGrafoInterno(N);

    // Stampa del grafo generato
    stampaGrafo(grafo);

    return 0;
}