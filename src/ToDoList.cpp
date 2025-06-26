#include "ToDoList.h"
#include <sstream>
#include <stdexcept>
#include <fstream>

void ToDoList::aggiungiAttivita(const Attivita& attivita) {
    attivitaList.push_back(attivita); //push_back() è una funzione di vector che aggiunge un elemento in fondo
}

size_t ToDoList::numeroAttivita() const {
    return attivitaList.size(); //size() restituisce quanti elementi ci sono nel vector
}

//CREO UNA STRINGA CON TUTTE LE ATTIVITA
std::string ToDoList::visualizza() const {
    std::ostringstream oss; //std::ostringstream permette di costruire una stringa scrivendoci dentro usabndo "<<": nel mio caso serve per costruire il testo da restituire con tutte le attività
    for (size_t i = 0; i < attivitaList.size(); ++i) {
        oss << i + 1 << ". " << attivitaList[i].getDescrizione(); //attivitaList[i] accede alle singole attività di indice i
        if (attivitaList[i].isCompletata()) {
            oss << " [COMPLETATA]";
        }
        oss << '\n';
    }
    return oss.str();
}

void ToDoList::completaAttivita(size_t indice) {
    if (indice >= attivitaList.size()) {
        throw std::out_of_range("Indice non valido."); //std::out_of_range si usa quando si accede a un elemento fuori dai limiti di vector: in questo caso è usato per gestire
                                                        //il caso in cui l'utente prova a completare un'attività che non esiste
    }
    attivitaList[indice].completa();
} //controllo di validità, poi si accede al vector e si chiama completa()

Attivita ToDoList::getAttivita(size_t indice) const {
    if (indice >= attivitaList.size()) {
        throw std::out_of_range("Indice non valido.");
    }
    return attivitaList[indice];
}

void ToDoList::salvaSuFile(const std::string& percorso) const {
    std::ofstream file(percorso); //ofstream è un output verso il file (scrivere): insieme a ifstream è usata per salvare e caricare l'elenco delle attività su un file di testo
    if (!file) {
        throw std::ios_base::failure("Impossibile aprire il file per la scrittura."); //std::ios_base si usa quando c'è un problema di input/output: nel mio caso quando un file non sib apre correttamente
    }
    for (const auto& attivita : attivitaList) {
        file << (attivita.isCompletata() ? 1 : 0) << " " << attivita.getDescrizione() << "\n";
    }
}

void ToDoList::caricaDaFile(const std::string& percorso) {
    std::ifstream file(percorso); //ifstream è un input dal file (leggere): insieme a ofstream è usata per salvare e caricare l'elenco delle attività su un file di testo
    if (!file) {
        throw std::ios_base::failure("Impossibile aprire il file per la lettura.");
    }
    attivitaList.clear();
    std::string linea;
    while (std::getline(file, linea)) { //getline legge una riga di input da tastiera (compresi gli spazi)
        std::istringstream iss(linea); //isstringstream prende una stringa e la legge come se fosse un file: serve per analizzare ogni riga del file, separando lo stato (0/1) e la descrizione
        int stato;
        std::string descrizione;
        if (!(iss >> stato)) continue;
        std::getline(iss >> std::ws, descrizione);
        attivitaList.emplace_back(descrizione, stato == 1);
    }
}
