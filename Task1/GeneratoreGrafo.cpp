#include "GeneratoreGrafo.h"
#include <iostream>

Grafo GeneratoreGrafo::generaGrafoInterno(int N) {
    // Servono almeno N >= 1 per avere dei nodi interni (con N=0 ci sono solo bordi)
    if (N < 1) {
        std::cerr << "Attenzione: Per N < 1 non esistono nodi interni nel dominio!\n";
        return {};
    }

    // Nodi interni per lato: (N)
    // Numero totale di nodi interni: (N) * (N)
    int nInterni = N;
    int numNodiSpazio = nInterni * nInterni;

    // Inizializziamo il grafo con la dimensione esatta dei soli nodi interni
    Grafo grafo(numNodiSpazio);

    // Questo è un helper che serve per convertire coordinate logiche interne (i_int, j_int)
    // in un ID univoco da 0 a (numNodiSpazio - 1)
    auto getIndicePuntoInterno = [nInterni](int i_int, int j_int) {
        return i_int * nInterni + j_int;
    };

    // Calcoliamo quanti sono i nodi interni: N * N
    // Nota: assumiamo che N sia il numero di nodi interni per lato
    const double h = 1.0 / (N + 1); // Passo di discretizzazione per calcolare (x, y)

    // Cicliamo SOLO sugli indici interni della griglia: i, j in [1, N]
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            
            // Convertiamo gli indici 1-based in indici 0-based per la matrice interna [0, N-1]
            int i_int = i - 1;
            int j_int = j - 1;
            
            // ID univoco del nodo corrente nel Grafo
            int n = getIndicePuntoInterno(i_int, j_int); 

            // 1. Inizializziamo i dati del Nodo corrente
            grafo[n].id = n;
            grafo[n].punto = { i * h, j * h }; // Coordinate reali (x, y) nel dominio [0, 1]^2

            // 2. Vicino di DESTRA (i+1, j)
            if (i < N) {
                int v_destra = getIndicePuntoInterno(i_int + 1, j_int);
                grafo[n].adiacenti.push_back(v_destra);
            }

            // 3. Vicino di SINISTRA (i-1, j)
            if (i > 1) {
                int v_sinistra = getIndicePuntoInterno(i_int - 1, j_int);
                grafo[n].adiacenti.push_back(v_sinistra);
            }

            // 4. Vicino in ALTO (i, j+1)
            if (j < N) {
                int v_alto = getIndicePuntoInterno(i_int, j_int + 1);
                grafo[n].adiacenti.push_back(v_alto);
            }

            // 5. Vicino in BASSO (i, j-1)
            if (j > 1) {
                int v_basso = getIndicePuntoInterno(i_int, j_int - 1);
                grafo[n].adiacenti.push_back(v_basso);
            }
        }
    }

    return grafo;
}