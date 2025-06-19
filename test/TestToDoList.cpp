#include "gtest/gtest.h"
#include "ToDoList.h"
#include <fstream>
#include <cstdio>

TEST(ToDoListTest, ListaVuota) {
    ToDoList lista;
    EXPECT_EQ(lista.numeroAttivita(), 0);
}

TEST(ToDoListTest, AggiuntaAttivita) {
    ToDoList lista;
    lista.aggiungiAttivita(Attivita("Leggere"));
    EXPECT_EQ(lista.numeroAttivita(), 1);
    EXPECT_EQ(lista.getAttivita(0).getDescrizione(), "Leggere");
    EXPECT_FALSE(lista.getAttivita(0).isCompletata());
}

TEST(ToDoListTest, CompletaAttivita) {
    ToDoList lista;
    lista.aggiungiAttivita(Attivita("Compito"));
    lista.completaAttivita(0);
    EXPECT_TRUE(lista.getAttivita(0).isCompletata());
}

TEST(ToDoListTest, IndiceNonValido) {
    ToDoList lista;
    EXPECT_THROW(lista.completaAttivita(0), std::out_of_range);
}

TEST(ToDoListTest, SalvaECaricaDaFile) {
    const std::string percorso = "test_lista_temp.txt";
    ToDoList lista;
    lista.aggiungiAttivita(Attivita("Compito 1"));
    lista.aggiungiAttivita(Attivita("Compito 2", true));
    lista.salvaSuFile(percorso);

    ToDoList caricata;
    caricata.caricaDaFile(percorso);

    ASSERT_EQ(caricata.numeroAttivita(), 2);
    EXPECT_EQ(caricata.getAttivita(0).getDescrizione(), "Compito 1");
    EXPECT_FALSE(caricata.getAttivita(0).isCompletata());
    EXPECT_EQ(caricata.getAttivita(1).getDescrizione(), "Compito 2");
    EXPECT_TRUE(caricata.getAttivita(1).isCompletata());

    std::remove(percorso.c_str());
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
