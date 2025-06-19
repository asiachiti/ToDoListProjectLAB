#include <iostream>
#include "ToDoList.h"

int main() {
    ToDoList lista;

    lista.aggiungiAttivita(Attivita("Studiare C++"));
    lista.aggiungiAttivita(Attivita("Fare esercizi"));
    lista.aggiungiAttivita(Attivita("Consegna progetto"));

    try {
        lista.completaAttivita(1);
    } catch (const std::exception& e) {
        std::cerr << "Errore: " << e.what() << std::endl;
    }

    std::cout << "Lista delle attività:\n";
    std::cout << lista.visualizza();

    return 0;
}
