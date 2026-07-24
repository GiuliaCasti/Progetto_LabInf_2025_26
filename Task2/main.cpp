#include "PartizionatoreGrafo.h"
#include "../GestioneFile/GestioneFile.h"
#include "../TipiGlobali.h"

int main(int argc, char* argv[]) {
    std::vector<MappaturaNodo> ordinamentoFinale;
    int contatoreNuovoIndice = 0;

    // Leggi i nodi dal file coords.txt
    Nodi nodi = GestioneFile::leggiFileCoords("../FileGenerati/coords.txt");

    // Iniziamo la ricorsione partendo dal primo taglio lungo X (dividiPerX = true)
    PartizionatoreGrafo::eseguiNestedDissectionRicorsiva(nodi, true, ordinamentoFinale, contatoreNuovoIndice);

    // Salva il risultato nel file ordering.txt
    GestioneFile::generaFileNodiPartizionati(ordinamentoFinale, "../FileGenerati/ordering.txt");
}