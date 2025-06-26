#include "gtest/gtest.h"
#include "Attivita.h"

// UNA SERIE DI TEST SCRITTI CON GOOGLE TEST PER VERIFICARE CHE LA CLASSE ATTIVITA FUNZIONI
TEST(AttivitaTest, CostruttoreDefault) {
    Attivita a;
    EXPECT_EQ(a.getDescrizione(), "");
    EXPECT_FALSE(a.isCompletata());
}

TEST(AttivitaTest, CostruttoreConValori) {
    Attivita a("Compito", true);
    EXPECT_EQ(a.getDescrizione(), "Compito");
    EXPECT_TRUE(a.isCompletata());
}

TEST(AttivitaTest, SetDescrizione) {
    Attivita a;
    a.setDescrizione("Nuovo testo");
    EXPECT_EQ(a.getDescrizione(), "Nuovo testo");
}

TEST(AttivitaTest, CompletaAttivita) {
    Attivita a("Test");
    EXPECT_FALSE(a.isCompletata());
    a.completa();
    EXPECT_TRUE(a.isCompletata());
}
