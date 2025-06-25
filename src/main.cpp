#include <iostream>
#include <string>
#include "ToDoList.h"

int main() {
    ToDoList lista;
    std::string scelta;

    while (true) {
        std::cout << "\n--- MENU ---\n";
        std::cout << "1. Aggiungi nuova attività\n";
        std::cout << "2. Completa attività\n";
        std::cout << "3. Visualizza lista\n";
        std::cout << "4. Salva su file\n";
        std::cout << "5. Carica da file\n";
        std::cout << "6. Esci\n";
        std::cout << "Scelta: ";
        std::getline(std::cin, scelta);

        if (scelta == "1") {
            std::string desc;
            std::cout << "Inserisci descrizione: ";
            std::getline(std::cin, desc);
            lista.aggiungiAttivita(Attivita(desc));
            std::cout << "Attività aggiunta!\n";

        } else if (scelta == "2") {
            std::cout << lista.visualizza();
            std::cout << "Numero dell'attività da completare: ";
            std::string input;
            std::getline(std::cin, input);
            try {
                int indice = std::stoi(input);
                lista.completaAttivita(static_cast<size_t>(indice - 1));
                std::cout << "Attività completata.\n";
            } catch (...) {
                std::cout << "Indice non valido.\n";
            }

        } else if (scelta == "3") {
            std::cout << lista.visualizza();

        } else if (scelta == "4") {
            std::string filename;
            std::cout << "Nome file per il salvataggio: ";
            std::getline(std::cin, filename);
            try {
                lista.salvaSuFile(filename);
                std::cout << "Lista salvata.\n";
            } catch (const std::exception& e) {
                std::cout << "Errore durante il salvataggio: " << e.what() << "\n";
            }

        } else if (scelta == "5") {
            std::string filename;
            std::cout << "Nome file da caricare: ";
            std::getline(std::cin, filename);
            try {
                lista.caricaDaFile(filename);
                std::cout << "Lista caricata.\n";
            } catch (const std::exception& e) {
                std::cout << "Errore durante il caricamento: " << e.what() << "\n";
            }

        } else if (scelta == "6") {
            std::cout << "Uscita dal programma.\n";
            break;

        } else {
            std::cout << "Scelta non valida.\n";
        }
    }

    return 0;
}
