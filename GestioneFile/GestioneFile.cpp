#include "GestioneFile.h"
#include <fstream>
#include <iostream>

void GestioneFile::generaFileCoords(const Nodi& nodi, const std::string& nomeFile) {
    std::ofstream file(nomeFile);
    if (!file.is_open()) {
        std::cerr << "Errore: Impossibile aprire il file " << nomeFile << " per la scrittura.\n";
        return;
    }

    for (const auto& nodo : nodi) {
        file << nodo.id << " "
             << nodo.indice.i << " "
             << nodo.indice.j << " "
             << nodo.punto.x << " "
             << nodo.punto.y << "\n";
    }

    file.close();
}

void GestioneFile::generaFileConnectivity(const Archi& archi, const std::string& nomeFile) {
    std::ofstream file(nomeFile);
    if (!file.is_open()) {
        std::cerr << "Errore: Impossibile aprire il file " << nomeFile << " per la scrittura.\n";
        return;
    }

    for (const auto& arco : archi) {
        file << arco.id << " "
             << arco.nodo1 << " "
             << arco.nodo2 << "\n";
    }

    file.close();
}