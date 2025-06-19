# ✅ ToDoListProjectLAB

Progetto sviluppato per il corso di **Laboratorio di Programmazione**.  
Consiste in una semplice applicazione C++ per la gestione di una lista di attività (To-Do list), con possibilità di salvataggio su disco e test automatici.

## 📌 Funzionalità implementate

- Gestione di oggetti `Attivita` con descrizione e stato (completata/non completata)
- Classe `ToDoList` per aggiungere, completare, visualizzare e gestire attività
- Salvataggio e caricamento da file
- Separazione completa tra header, implementazione e `main.cpp`
- Struttura del progetto suddivisa in: `include/`, `src/`, `test/`
- Copertura con unit test completi usando GoogleTest
- Commenti chiari e conformi alla teoria

## 🧪 Test automatici

- Tutte le classi principali (`Attivita`, `ToDoList`) sono testate in modo isolato
- Uso di `TEST`, `EXPECT_EQ`, `EXPECT_TRUE` ecc.
- I test sono eseguibili tramite CMake/CLion
- File di test: `test/TestAttivita.cpp` e `test/TestToDoList.cpp`

## 🛠️ Requisiti per la compilazione

- CLion o compilatore C++20 compatibile
- CMake ≥ 3.20
- Libreria [GoogleTest](https://github.com/google/googletest) (inclusa nella cartella `test/lib/googletest/`)

## 📁 Struttura del progetto

ToDoListProject/
├── include/
│ ├── Attivita.h
│ └── ToDoList.h
├── src/
│ ├── Attivita.cpp
│ ├── ToDoList.cpp
│ └── main.cpp
├── test/
│ ├── TestAttivita.cpp
│ ├── TestToDoList.cpp
│ └── lib/
│ └── googletest/
├── CMakeLists.txt
└── README.md

yaml
Copia
Modifica

## 💡 Note finali

- Il progetto è interamente versionato con Git
- Tutti i file sono stati creati direttamente all’interno di CLion
- Lo stile e l’organizzazione del codice seguono quanto visto in aula

---

© 2025 – Asia Chiti