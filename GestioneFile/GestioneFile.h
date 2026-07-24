#ifndef GENERATORE_FILE_H
#define GENERATORE_FILE_H

#include <string>
#include "../TipiGlobali.h"

class GestioneFile {
public:
    // Funzione per generare il file coords.txt contentente la lista di tutti i punti interni del dominio con
    // - il loro indice progressivo n
    // - il loro indice logico (i, j)
    // - e le loro coordinate spaziali x, y;
    // Per ogni punto interno, la riga del file avrà il formato:
    // n i j x y
    static void generaFileCoords(const Nodi& nodi, const std::string& nomeFile);

    // Legge il file coords.txt e ricostruisce il vettore di nodi corrispondente.
    static Nodi leggiFileCoords(const std::string& nomeFile);

    // Funzione per generare il file connectivity.txt contenente la lista di archi del grafo con
    // - il loro indice progressivo n
    // - gli ID dei due nodi adiacenti
    // Per ogni arco, la riga del file avrà il formato:
    // n nodo1 nodo2
    static void generaFileConnectivity(const Archi& archi, const std::string& nomeFile);

    // Legge il file connectivity.txt e ricostruisce il vettore di archi corrispondente.
    static Archi leggiFileConnectivity(const std::string& nomeFile);

    // Funzione per salvare l'ordinamento Nested Dissection su file
    static void generaFileNodiPartizionati(const std::vector<MappaturaNodo>& ordinamento, const std::string& nomeFile);
};

#endif // GENERATORE_FILE_H