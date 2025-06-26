#ifndef TODOLIST_ATTIVITA_H
#define TODOLIST_ATTIVITA_H

#include <string>

//GET E SET PERMETTONO DI LEGGERE/SCRIVERE I DATI DALL'ESTERNO
class Attivita {
public:
    explicit Attivita(std::string descrizione = "", bool completata = false);
    std::string getDescrizione() const; //std::string  permette operazioni come concatenare, confrontare, leggere e scrivere stringhe: in questo caso serve per memorizzare la
                                        //descrizione di ciascuna attività e leggere l'input dell'utente
    bool isCompletata() const;

    void setDescrizione(const std::string& nuovaDescrizione);
    void completa();

private:
    std::string descrizione;
    bool completata;
};

#endif // TODOLIST_ATTIVITA_H
