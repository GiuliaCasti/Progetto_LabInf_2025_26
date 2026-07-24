#ifndef PARTIZIONATORE_GRAFO_H
#define PARTIZIONATORE_GRAFO_H

#include "../TipiGlobali.h"
#include <string>
#include <vector>

class PartizionatoreGrafo {
public:
    static void eseguiNestedDissectionRicorsiva(const std::vector<Nodo>& sottoGrafo, 
                                        bool dividiPerX, 
                                        std::vector<MappaturaNodo>& ordinamentoFinale, 
                                        int& contatoreNuovoIndice);
};

#endif // PARTIZIONATORE_GRAFO_H