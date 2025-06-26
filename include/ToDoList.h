#ifndef TODOLIST_TODOLIST_H
#define TODOLIST_TODOLIST_H

#include <vector>
#include <string>
#include "Attivita.h"

class ToDoList {
public:
    void aggiungiAttivita(const Attivita& attivita);
    size_t numeroAttivita() const; //size_t è un tipo intero non negativo usato per indicizzare i vector o il risultato di size
    std::string visualizza() const;
    void completaAttivita(size_t indice);
    Attivita getAttivita(size_t indice) const;

    void salvaSuFile(const std::string& percorso) const;
    void caricaDaFile(const std::string& percorso);

private:
    std::vector<Attivita> attivitaList; //vector è un contenitore dinamico che memorizza un elenco di oggetti, Attivita in questo caso, e a differenza degli array un vector può crescere o ridursi
                                         // in dimensioni dinamicamente: in questo caso ogni oggetto ToDoList contiene un vector dove vengono memorizzate tutte le attività create
};

#endif // TODOLIST_TODOLIST_H
