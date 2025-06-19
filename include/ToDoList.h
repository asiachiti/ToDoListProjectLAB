#ifndef TODOLIST_TODOLIST_H
#define TODOLIST_TODOLIST_H

#include <vector>
#include <string>
#include "Attivita.h"

class ToDoList {
public:
    void aggiungiAttivita(const Attivita& attivita);
    size_t numeroAttivita() const;
    std::string visualizza() const;
    void completaAttivita(size_t indice);
    Attivita getAttivita(size_t indice) const;

    void salvaSuFile(const std::string& percorso) const;
    void caricaDaFile(const std::string& percorso);

private:
    std::vector<Attivita> attivitaList;
};

#endif // TODOLIST_TODOLIST_H
