#include <iostream>
#include <fstream>
#include <vector>
#include "GeneratoreMatrice.h"
#include "GeneratoreTermineNoto.h"
#include "../GestioneFile/GestioneFile.h"

// Funzione helper locale nel main per caricare la permutazione
std::vector<int> caricaOrdinamento(int numNodiInterni, bool usaOrderingFile) {
    std::vector<int> perm(numNodiInterni);
    
    // Se usiamo l'ordinamento naturale
    if (!usaOrderingFile) {
        for (int i = 0; i < numNodiInterni; ++i) perm[i] = i;
        return perm;
    }

    // Altrimenti carichiamo il file ordering.txt
    std::ifstream fileOrder("../FileGenerati/ordering.txt");
    if (!fileOrder.is_open()) {
        std::cerr << "Attenzione: ordering.txt non trovato! Verrà utilizzato l'ordinamento naturale.\n";
        for (int i = 0; i < numNodiInterni; ++i) perm[i] = i;
        return perm;
    }

    int nuovoIndex, vecchioId;
    while (fileOrder >> nuovoIndex >> vecchioId) {
        if (vecchioId >= 0 && vecchioId < numNodiInterni) {
            perm[vecchioId] = nuovoIndex;
        }
    }
    fileOrder.close();
    return perm;
}

int main(int argc, char* argv[]) {
    // Parametri di input del problema
    int N = std::stoi(argv[1]);                 // Discretizzazione N x N nodi interni
    double kappa = 1.0;                         // Coefficiente di diffusione
    
    std::string ordering = argv[2];             // true -> ordering.txt | false -> naturale
    bool usaOrderingFile = (ordering == "true" || ordering == "1");

    // Definizione delle funzioni f(x, y) e g(x, y) tramite lambda expression
    auto f = [](double x, double y) { return 1.0; }; // Termine noto f(x, y) = 1
    auto g = [](double x, double y) { return 0.0; }; // Condizione di Dirichlet g(x, y) = 0

    // 1. Caricamento della permutazione
    int numNodiInterni = N * N;
    std::vector<int> perm = caricaOrdinamento(numNodiInterni, usaOrderingFile);

    // 2. Generazione e salvataggio della Matrice A
    auto elementiA = GeneratoreMatrice::generaMatriceA(N, kappa, perm);
    GestioneFile::salvaMatrice(elementiA, "../FileGenerati/A.txt");

    // 3. Generazione e salvataggio del Termine Noto rhs
    auto rhs = GeneratoreTermineNoto::generaTermineNoto(N, kappa, f, g, perm);
    GestioneFile::salvaTerminiNoti(rhs, "../FileGenerati/rhs.txt");

    return 0;
}