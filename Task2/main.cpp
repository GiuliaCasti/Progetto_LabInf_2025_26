#include "PartizionatoreGrafo.h"
#include "../GestioneFile/GestioneFile.h"
#include "../TipiGlobali.h"

int main(int argc, char* argv[]) {
    std::vector<MappaturaNodo> ordinamentoFinale;
    int contatoreNuovoIndice = 0;

    // Leggiamo il grafo COMPLETO (nodi + archi) generato nel Task 1,
    // non solo le coordinate: adiacenti viene ora popolato correttamente.
    Nodi nodi = GestioneFile::leggiGrafoCompleto("../FileGenerati/coords.txt", 
                                                   "../FileGenerati/connectivity.txt");

    PartizionatoreGrafo::eseguiNestedDissectionRicorsiva(nodi, true, ordinamentoFinale, contatoreNuovoIndice);

    GestioneFile::generaFileNodiPartizionati(ordinamentoFinale, "../FileGenerati/ordering.txt");

    return 0;
}