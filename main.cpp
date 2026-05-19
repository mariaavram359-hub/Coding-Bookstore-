#include <iostream>
#include "ContainerElectronice.h"
#include "ContainerBiodegradabile.h"
#include "ContainerPlastic.h"
#include "StatieSortare.h"
#include "Exceptii.h"

int main() {
    std::cout << "--- Initializare Sistem Smart de Gestionare a Deseurilor ---\n";

    StatieSortare statie_centrala;

    auto* c_plastic = new ContainerPlastic(101, "Strada Primaverii", 200.0f, 85.5f);
    auto* c_bio = new ContainerBiodegradabile(102, "Piata Centrala", 150.0f, 18.5f, true);
    auto* c_electric = new ContainerElectronice(103, "Liceul Teoretic", 50.0f, true);

    statie_centrala.adaugaContainer(c_plastic);
    statie_centrala.adaugaContainer(c_bio);
    statie_centrala.adaugaContainer(c_electric);

    std::cout << "--- ACTIVITATE ZILNICA (Colectare Deseuri) ---\n";
    try {

        c_plastic->adauga_deseuri(50.0f);
        c_bio->adauga_deseuri(100.0f);
        c_electric->adauga_deseuri(10.0f);

        std::cout << "\n[Testare Limita] Un cetatean incearca sa arunce o canapea in containerul de plastic...\n";
        c_plastic->adauga_deseuri(160.0f);

        std::cout << "Succes! Canapeaua a incaput.\n";

    } catch (const EroareSuprasolicitare& eroare) {
        std::cout << "\n[ALERTA SISTEM] " << eroare.what() << "\n";
    }

    statie_centrala.mentenanta_rutina();

    statie_centrala.colecteaza_tot_gunoiul();

    StatieSortare::afiseaza_statistici();

    std::cout << "Sistem oprit cu succes.\n";

    return 0;
}