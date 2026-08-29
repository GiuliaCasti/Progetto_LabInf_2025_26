#include <iostream>
#include "../TipiGlobali.h"
#include "GeneratoreGriglia.h"
#include "GeneratoreGrafo.h"
#include "../GestioneFile/GestioneFile.h"

void stampaGriglia(const Griglia& griglia) {
    std::cout << "Punti generati (Totale: " << griglia.size() << "):\n";
    for (size_t k = 0; k < griglia.size(); ++k) {
        std::cout << "Punto " << k << ": (" 
                  << griglia[k].x << ", " 
                  << griglia[k].y << ")\n";
    }
}

void stampaNodi(const Nodi& nodi) {
    std::cout << "Nodi del grafo generati (Totale: " << nodi.size() << "):\n";
    for (size_t k = 0; k < nodi.size(); ++k) {
        std::cout << "Nodo " << nodi[k].id << " - Coordinate: ("
                  << nodi[k].punto.x << ", " 
                  << nodi[k].punto.y << ") - Indice: ("
                  << nodi[k].indice.i << ", " 
                  << nodi[k].indice.j << ") -> Adiacenti: [ ";
        
        // Stampa dei vicini adiacenti
        for (size_t j = 0; j < nodi[k].adiacenti.size(); ++j) {
            std::cout << nodi[k].adiacenti[j] << " ";
        }
        
        std::cout << "]\n";
    }
}

void stampaArchi(const Archi& archi) {
    std::cout << "Archi del grafo generati (Totale: " << archi.size() << "):\n";
    for (const auto& arco : archi) {
        std::cout << "Arco " << arco.id << ": Nodo " 
                  << arco.nodo1 << " <-> Nodo " 
                  << arco.nodo2 << "\n";

    }
}

int main(int argc, char* argv[]) {
    int N = std::stoi(argv[1]); // Dimensione della griglia (N x N) per i nodi interni

    // Genera la griglia [0, 1]^2 con discretizzazione (N+2) x (N+2)
    Griglia griglia = GeneratoreGriglia::generaGriglia(N);

    // Stampa dei punti generati
    // stampaGriglia(griglia);

    // Genera i nodi interni del grafo dalla griglia
    Nodi nodi = GeneratoreGrafo::generaNodiInterni(N);

    // Stampa dei nodi generati
    stampaNodi(nodi);

    // Salva le coordinate dei nodi in un file
    GestioneFile::generaFileCoords(nodi, "FileGenerati/coords.txt");

    // Genera gli archi del grafo dai nodi interni
    Archi archi = GeneratoreGrafo::generaArchiInterni(nodi);

    // Stampa degli archi generati
    // stampaArchi(archi);

    // Salva la connettività del grafo in un file
    GestioneFile::generaFileConnectivity(archi, "FileGenerati/connectivity.txt");

    return 0;
}