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

    std::cout << "--- ACTIVITATE ZILNICA Sector 1 ---\n";
    try {

        c_plastic->adauga_deseuri(50.0f, "Plastic");
        c_bio->adauga_deseuri(100.0f, "Biologic");
        c_electric->adauga_deseuri(10.0f, "Electronice");

        std::cout << "\n[Testare Securitate] Un cetatean neatent arunca baterii in containerul de plastic...\n";
        c_plastic->adauga_deseuri(5.0f, "Electronice");

        std::cout << "\n[Testare Limita] Un cetatean incearca sa arunce o canapea in containerul de plastic...\n";
        c_plastic->adauga_deseuri(160.0f, "Plastic");

        std::cout << "Succes! Canapeaua a incaput.\n";

    }catch (const EroareTipDeseu& eroare) {
        std::cout << "\n[EROARE SORTARE] " << eroare.what() << "\n";
    }catch (const EroareSuprasolicitare& eroare) {
        std::cout << "\n[ALERTA SISTEM] " << eroare.what() << "\n";
    }

    statie_centrala.mentenanta_rutina();

    statie_centrala.sorteaza_dupa_umplere();

    std::cout << "\n--- VERIFICARE ORDINE DUPA SORTARE ---\n";
    statie_centrala.mentenanta_rutina();

    statie_centrala.colecteaza_tot_gunoiul();

    std::cout << "\n=== INITIALIZARE STATIE SECTOR 2 ===\n";
    StatieSortare statia_sector_2;

    auto* c_plastic_s2 = new ContainerPlastic(201, "Aleea Trandafirilor", 300.0f, 90.0f);
    auto* c_bio_s2 = new ContainerBiodegradabile(202, "Parcul Tineretului", 200.0f, 15.0f, false);

    statia_sector_2.adaugaContainer(c_plastic_s2);
    statia_sector_2.adaugaContainer(c_bio_s2);

    std::cout << "--- ACTIVITATE ZILNICA SECTOR 2 ---\n";
    c_plastic_s2->adauga_deseuri(120.0f, "Plastic");
    c_bio_s2->adauga_deseuri(50.0f, "Biologic");

    statia_sector_2.mentenanta_rutina();

    statia_sector_2.sorteaza_dupa_umplere();

    std::cout << "\n--- VERIFICARE ORDINE DUPA SORTARE ---\n";
    statia_sector_2.mentenanta_rutina();

    statia_sector_2.colecteaza_tot_gunoiul();

    StatieSortare::afiseaza_statistici();

    std::cout << "Sistem oprit cu succes.\n";

    return 0;
}