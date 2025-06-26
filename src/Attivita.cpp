#include "Attivita.h"
#include <utility>

//COSTRUTTORE CHE ASSEGNA I VALORI ALLE VARIABILI
Attivita::Attivita(std::string descrizione, bool completata)
    : descrizione(std::move(descrizione)), completata(completata) {}

//IMPLEMENTAZIONE STANDARD CHE RESTITUISCE O MODIFICA DATI
std::string Attivita::getDescrizione() const {
    return descrizione;
}

bool Attivita::isCompletata() const {
    return completata;
}

void Attivita::setDescrizione(const std::string& nuovaDescrizione) {
    descrizione = nuovaDescrizione;
}

void Attivita::completa() {
    completata = true;
}
