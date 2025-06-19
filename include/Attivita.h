#ifndef TODOLIST_ATTIVITA_H
#define TODOLIST_ATTIVITA_H

#include <string>

class Attivita {
public:
    explicit Attivita(std::string descrizione = "", bool completata = false);
    std::string getDescrizione() const;
    bool isCompletata() const;

    void setDescrizione(const std::string& nuovaDescrizione);
    void completa();

private:
    std::string descrizione;
    bool completata;
};

#endif // TODOLIST_ATTIVITA_H
