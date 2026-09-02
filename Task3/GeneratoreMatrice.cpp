#include "GeneratoreMatrice.h"
#include <fstream>
#include <iostream>


// Metodo principale che assembla la matrice sparsa A per l'operatore Laplaciano 2D.
// Parametri:
// - N: numero di nodi interni lungo un singolo asse (totale nodi = N^2).
// - kappa: coefficiente di conduzione termica.
// - perm: vettore che mappa l'ID naturale del nodo nel nuovo indice riordinato (es. Nested Dissection).
std::vector<ElementoMatrice> GeneratoreMatrice::generaMatriceA(int N, double kappa, const std::vector<int>& perm) {

    // Vettore che memorizzerà la matrice in formato COO (Coordinate list).
    // Ogni ElementoMatrice è una tripletta: {indice_riga, indice_colonna, valore_numerico}.
    std::vector<ElementoMatrice> A;

    const double h = 1.0 / (N + 1);
    // Calcolo del moltiplicatore costante dello stencil alle differenze finite:
    const double coeff = kappa / (h * h);

    // Funzione lambda locale per la conversione bidirezionale delle coordinate.
    // Prende le coordinate logiche (i, j) in base 0 e restituisce un ID scalare (da 0 a N^2 - 1)
    auto getOldId = [N](int i_int, int j_int) {
        return i_int * N + j_int;
    };

    // Doppio ciclo for per spazzare tutti i nodi interni del dominio.
    // Si usano indici 1-based (da 1 a N) per riflettere le coordinate matematiche reali, 
    // escludendo geometricamente il bordo
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            int oldId = getOldId(i - 1, j - 1); //identificazione ID corrente
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