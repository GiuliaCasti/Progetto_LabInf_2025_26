#include "GeneratoreGrafo.h"
#include <iostream>

Nodi GeneratoreGrafo::generaNodiInterni(int N) {
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
    Nodi nodi(numNodiSpazio);

    // Questo è un helper che serve per convertire coordinate logiche interne (i_int, j_int)
    // in un ID univoco da 0 a (numNodiSpazio - 1)
    auto getIndicePuntoInterno = [nInterni](int i_int, int j_int) {
        return i_int * nInterni + j_int;
    };

    // Calcoliamo quanti sono i nodi interni: N * N
    // Nota: assumiamo che N sia il numero di nodi interni per lato
    const double h = 1.0 / (N + 1); // Passo di discretizzazione per calcolare (x, y)

    // Stencil a 5 punti (senza il centro): le 4 direzioni possibili di un vicino,
    // espresse come spostamento (di, dj) rispetto al nodo corrente (i, j).
    // Stesso ordine dei blocchi originali: destra, sinistra, alto, basso.
    const int direzioni[4][2] = {
        {+1,  0},  // destra
        {-1,  0},  // sinistra
        { 0, +1},  // alto
        { 0, -1}   // basso
    };

    // Cicliamo SOLO sugli indici interni della griglia: i, j in [1, N]
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            
            // Convertiamo gli indici 1-based in indici 0-based per la matrice interna [0, N-1]
            int i_int = i - 1;
            int j_int = j - 1;
            
            // ID univoco del nodo corrente nel nodi
            int n = getIndicePuntoInterno(i_int, j_int); 

            // 1. Inizializziamo i dati del Nodo corrente
            nodi[n].id = n;
            nodi[n].indice = {i_int, j_int}; // Indice logico nella griglia
            nodi[n].punto = { i * h, j * h }; // Coordinate reali (x, y) nel dominio [0, 1]^2

            // 2.Proviamo ciascuna delle 4 direzioni: aggiungiamo il vicino solo se resta all'interno del dominio interno [1, N] (altrimenti sarebbe un nodo di bordo)
            for (const auto& dir : direzioni) {
                int i_vicino = i + dir[0];
                int j_vicino = j + dir[1];

                if (i_vicino >= 1 && i_vicino <= N && j_vicino >= 1 && j_vicino <= N) {
                    int v = getIndicePuntoInterno(i_vicino - 1, j_vicino - 1);
                    nodi[n].adiacenti.push_back(v);
                }
            }
        }
    }


    return nodi;
}

Archi GeneratoreGrafo::generaArchiInterni(const Nodi& nodi){
    Archi archi;
    int arcoId = 0;

    for (const auto& nodo : nodi) {
        for (int adiacenteId : nodo.adiacenti) {
            // Per evitare duplicati, aggiungiamo l'arco solo se l'ID del nodo corrente è minore di quello dell'adiacente
            if (nodo.id < adiacenteId) {
                archi.push_back({arcoId++, nodo.id, adiacenteId});
            }
        }
    }

    return archi;
}