#include "PartizionatoreGrafo.h"
#include "../TipiGlobali.h"
#include <fstream>
#include <iostream>
#include <algorithm>
#include <cmath>

// Esegue la partizione geometrica di un insieme di nodi
void partizionaNodi(const std::vector<Nodo>& nodiIn, 
                     bool dividiPerX, 
                     std::vector<Nodo>& V1, 
                     std::vector<Nodo>& V2, 
                     std::vector<Nodo>& VS) {
    if (nodiIn.empty()) return;

    // 1. Estraiamo e ordiniamo le coordinate uniche lungo l'asse scelto (X o Y)
    std::vector<double> coordinate;
    for (const auto& nodo : nodiIn) {
        double coord = dividiPerX ? nodo.punto.x : nodo.punto.y;
        coordinate.push_back(coord);
    }
    std::sort(coordinate.begin(), coordinate.end());
    
    // Rimuoviamo i duplicati per individuare i piani/linee di griglia distinti
    coordinate.erase(std::unique(coordinate.begin(), coordinate.end()), coordinate.end());

    // 2. Selezioniamo il valore mediano (x_hat o y_hat) per dividere equamente
    size_t indiceMediano = coordinate.size() / 2;
    double coordHat = coordinate[indiceMediano];

    // 3. Ripartiamo i nodi negli insiemi V1, V2 e VS
    for (const auto& nodo : nodiIn) {
        double val = dividiPerX ? nodo.punto.x : nodo.punto.y;
        
        // Tolleranza floating-point per il confronto
        if (std::abs(val - coordHat) < 1e-9) {
            VS.push_back(nodo);
        } else if (val < coordHat) {
            V1.push_back(nodo);
        } else {
            V2.push_back(nodo);
        }
    }
}

// Funzione ricorsiva di Nested Dissection
void PartizionatoreGrafo::eseguiNestedDissectionRicorsiva(const std::vector<Nodo>& sottoNodi, 
                                     bool dividiPerX, 
                                     std::vector<MappaturaNodo>& ordinamentoFinale, 
                                     int& contatoreNuovoIndice) {
    // Caso base: se non ci sono nodi nel sottografo
    if (sottoNodi.empty()) {
        return;
    }

    // Caso base: se è un singolo nodo o non è ulteriormente divisibile
    if (sottoNodi.size() <= 2) {
        for (const auto& nodo : sottoNodi) {
            ordinamentoFinale.push_back({contatoreNuovoIndice++, nodo.id});
        }
        return;
    }

    std::vector<Nodo> V1, V2, VS;

    // Partizioniamo il sottografo corrente
    partizionaNodi(sottoNodi, dividiPerX, V1, V2, VS);

    // 1. Applichiamo la ricorsione su V1 (invertendo l'asse di taglio: X -> Y -> X...)
    eseguiNestedDissectionRicorsiva(V1, !dividiPerX, ordinamentoFinale, contatoreNuovoIndice);

    // 2. Applichiamo la ricorsione su V2 (invertendo l'asse di taglio)
    eseguiNestedDissectionRicorsiva(V2, !dividiPerX, ordinamentoFinale, contatoreNuovoIndice);

    // 3. Infine inseriamo i nodi del separatore VS (i nodi VS vanno inseriti per ultimi)
    for (const auto& nodo : VS) {
        ordinamentoFinale.push_back({contatoreNuovoIndice++, nodo.id});
    }
}