#include "ToDoList.h"
#include <sstream>
#include <stdexcept>
#include <fstream>

void ToDoList::aggiungiAttivita(const Attivita& attivita) {
    attivitaList.push_back(attivita);
}

size_t ToDoList::numeroAttivita() const {
    return attivitaList.size();
}

std::string ToDoList::visualizza() const {
    std::ostringstream oss;
    for (size_t i = 0; i < attivitaList.size(); ++i) {
        oss << i + 1 << ". " << attivitaList[i].getDescrizione();
        if (attivitaList[i].isCompletata()) {
            oss << " [COMPLETATA]";
        }
        oss << '\n';
    }
    return oss.str();
}

void ToDoList::completaAttivita(size_t indice) {
    if (indice >= attivitaList.size()) {
        throw std::out_of_range("Indice non valido.");
    }
    attivitaList[indice].completa();
}

Attivita ToDoList::getAttivita(size_t indice) const {
    if (indice >= attivitaList.size()) {
        throw std::out_of_range("Indice non valido.");
    }
    return attivitaList[indice];
}

void ToDoList::salvaSuFile(const std::string& percorso) const {
    std::ofstream file(percorso);
    if (!file) {
        throw std::ios_base::failure("Impossibile aprire il file per la scrittura.");
    }
    for (const auto& attivita : attivitaList) {
        file << (attivita.isCompletata() ? 1 : 0) << " " << attivita.getDescrizione() << "\n";
    }
}

void ToDoList::caricaDaFile(const std::string& percorso) {
    std::ifstream file(percorso);
    if (!file) {
        throw std::ios_base::failure("Impossibile aprire il file per la lettura.");
    }
    attivitaList.clear();
    std::string linea;
    while (std::getline(file, linea)) {
        std::istringstream iss(linea);
        int stato;
        std::string descrizione;
        if (!(iss >> stato)) continue;
        std::getline(iss >> std::ws, descrizione);
        attivitaList.emplace_back(descrizione, stato == 1);
    }
}
