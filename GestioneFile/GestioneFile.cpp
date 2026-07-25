#include "GestioneFile.h"
#include <fstream>
#include <iostream>
#include <sstream>

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

Nodi GestioneFile::leggiFileCoords(const std::string& nomeFile) {
    std::ifstream file(nomeFile);
    if (!file.is_open()) {
        std::cerr << "Errore: Impossibile aprire il file " << nomeFile << " per la lettura.\n";
        return {};
    }

    Nodi nodi;
    std::string riga;
    while (std::getline(file, riga)) {
        if (riga.empty()) {
            continue;
        }

        std::stringstream ss(riga);
        int id, i, j;
        double x, y;
        if (!(ss >> id >> i >> j >> x >> y)) {
            std::cerr << "Errore: Riga malformata nel file " << nomeFile << ": " << riga << "\n";
            continue;
        }

        Nodo nodo;
        nodo.id = id;
        nodo.indice = {i, j};
        nodo.punto = {x, y};
        nodi.push_back(nodo);
    }

    file.close();
    return nodi;
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

Archi GestioneFile::leggiFileConnectivity(const std::string& nomeFile) {
    std::ifstream file(nomeFile);
    if (!file.is_open()) {
        std::cerr << "Errore: Impossibile aprire il file " << nomeFile << " per la lettura.\n";
        return {};
    }

    Archi archi;
    std::string riga;
    while (std::getline(file, riga)) {
        if (riga.empty()) {
            continue;
        }

        std::stringstream ss(riga);
        int id, nodo1, nodo2;
        if (!(ss >> id >> nodo1 >> nodo2)) {
            std::cerr << "Errore: Riga malformata nel file " << nomeFile << ": " << riga << "\n";
            continue;
        }

        Arco arco;
        arco.id = id;
        arco.nodo1 = nodo1;
        arco.nodo2 = nodo2;
        archi.push_back(arco);
    }

    file.close();
    return archi;
}

void GestioneFile::generaFileNodiPartizionati(const std::vector<MappaturaNodo>& ordinamento, const std::string& nomeFile) {
    std::ofstream file(nomeFile);
    if (!file.is_open()) {
        std::cerr << "Errore: Impossibile aprire il file " << nomeFile << " per la scrittura.\n";
        return;
    }

    for (const auto& mappatura : ordinamento) {
        file << mappatura.nuovoIndice << " "
             << mappatura.vecchioId << "\n";
    }

    file.close();
}

void GestioneFile::salvaMatrice(const std::vector<ElementoMatrice>& elementiA, const std::string& nomeFile) {
    std::ofstream file(nomeFile);
    if (!file.is_open()) {
        std::cerr << "Errore creazione del file " << nomeFile << "\n";
        return;
    }

    for (const auto& elem : elementiA) {
        file << elem.i << " " << elem.j << " " << elem.valore << "\n";
    }

    file.close();
}

void GestioneFile::salvaTerminiNoti(const std::vector<double>& rhs, const std::string& nomeFile) {
    std::ofstream file(nomeFile);
    if (!file.is_open()) {
        std::cerr << "Errore creazione del file " << nomeFile << "\n";
        return;
    }

    for (double val : rhs) {
        file << val << "\n";
    }

    file.close();
}