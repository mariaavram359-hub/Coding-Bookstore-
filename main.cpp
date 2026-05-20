
#include "include/StatieSortare.h"
#include "include/ContainerPlastic.h"
#include "include/ContainerBiodegradabile.h"
#include "include/ContainerElectronice.h"
#include "include/Exceptii.h"
#include <iostream>
#include <limits>

void curata_cin() {
    if (std::cin.eof()) {
        std::cout << "\n[Sistem] Iesire de urgenta (EOF detectat).\n";
        exit(1);
    }
    std::cin.clear();
    std::cin.ignore(10000, '\n');
}

int main() {
    std::cout << "=== PORNIRE SISTEM SMART DE GESTIONARE A DESEURILOR ===\n\n";

    StatieSortare statia_centrala;
    auto* c_plastic = new ContainerPlastic(101, "Strada Primaverii", 200.0f, 85.5f);
    auto* c_bio = new ContainerBiodegradabile(102, "Piata Centrala", 150.0f, 18.5f, true);
    auto* c_baterii = new ContainerElectronice(103, "Liceul Teoretic", 50.0f, true);

    statia_centrala.adaugaContainer(c_plastic);
    statia_centrala.adaugaContainer(c_bio);
    statia_centrala.adaugaContainer(c_baterii);

    try {
        *c_plastic += PachetDeseu{50.0f, "Plastic"};
        *c_bio += PachetDeseu{100.0f, "Biologic"};
        *c_baterii += PachetDeseu{10.0f, "Electronice"};
        *c_plastic += PachetDeseu{5.0f, "Electronice"}; 
    } catch (const EroareTipDeseu& eroare) {
        std::cerr << "[DEMO EROARE] " << eroare.what() << "\n\n";
    } catch (const EroareSuprasolicitare& eroare) {
        std::cerr << "[DEMO ALERTA] " << eroare.what() << "\n\n";
    }

    statia_centrala.colecteaza_tot_gunoiul();

    StatieSortare statia_sector_2;
    statia_sector_2.adaugaContainer(new ContainerPlastic(201, "Aleea Trandafirilor", 300.0f, 90.0f));
    statia_sector_2.adaugaContainer(new ContainerBiodegradabile(202, "Parcul Tineretului", 200.0f, 15.0f, false));
    statia_sector_2.adaugaContainer(new ContainerElectronice(203, "Bulevardul Unirii", 50.0f, true));

    bool sistem_pornit = true;

    while (sistem_pornit) {
        std::cout << "\n=========================================\n";
        std::cout << "        SELECTARE ROL UTILIZATOR         \n";
        std::cout << "=========================================\n";
        std::cout << "1. Cetatean (Arunca deseuri)\n";
        std::cout << "2. Administrator (Gestioneaza sistemul)\n";
        std::cout << "3. Oprire Sistem\n";
        std::cout << "Alegeti rolul: ";
        
        int rol;
        if (!(std::cin >> rol)) {
            curata_cin();
            continue;
        }

        if (rol == 3) {
            sistem_pornit = false;
            break;
        }

        if (rol == 1) {
            bool in_meniu_cetatean = true;
            while (in_meniu_cetatean) {
                std::cout << "\n--- INTERFATA CETATEAN ---\n";
                std::cout << "1. Vezi containerele disponibile\n";
                std::cout << "2. Arunca gunoi\n";
                std::cout << "3. Inapoi la selectia rolului\n";
                std::cout << "Alegere: ";
                
                int optiune_c;
                if (!(std::cin >> optiune_c)) {
                    curata_cin(); continue;
                }

                switch (optiune_c) {
                    case 1:
                        statia_sector_2.afiseaza_rezumat();
                        break;
                    case 2: {
                        std::cout << "\nIntroduceti ID-ul (Indexul) containerului (0=Plastic, 1=Bio, 2=Electronice): ";
                        int index;
                        if (!(std::cin >> index)) {
                            curata_cin(); std::cout << "Index invalid!\n"; break;
                        }

                        std::cout << "Introduceti cantitatea (kg): ";
                        float cantitate;
                        if (!(std::cin >> cantitate)) {
                            curata_cin();
                            std::cout << "Cantitate invalida!\n";
                            break;
                        }

                        std::cout << "Introduceti tipul deseului (Plastic / Biologic / Electronice): ";
                        std::string tip;
                        std::cin >> tip;

                        try {
                            *(statia_sector_2[index]) += PachetDeseu{cantitate, tip};
                        } catch (const std::exception& e) {
                            std::cerr << "\n[ACTIUNE RESPINSA] " << e.what() << "\n";
                        }
                        break;
                    }
                    case 3:
                        in_meniu_cetatean = false;
                        break;
                    default:
                        std::cout << "Optiune invalida!\n";
                }
            }
        }
        else if (rol == 2) {
            bool in_meniu_admin = true;
            while (in_meniu_admin) {
                std::cout << "\n--- INTERFATA ADMINISTRATOR ---\n";
                std::cout << "1. Mentenanta (Detalii tehnice)\n";
                std::cout << "2. Sorteaza flota dupa umplere\n";
                std::cout << "3. Trimite masina de gunoi (Colectare)\n";
                std::cout << "4. Vezi statistici globale oras\n";
                std::cout << "5. Inapoi la selectia rolului\n";
                std::cout << "Alegere: ";
                
                int optiune_a;
                if (!(std::cin >> optiune_a)) {
                    curata_cin();
                    continue;
                }

                switch (optiune_a) {
                    case 1:
                        statia_sector_2.mentenanta_rutina();
                        break;
                    case 2:
                        statia_sector_2.sorteaza_dupa_umplere();
                        statia_sector_2.afiseaza_rezumat();
                        break;
                    case 3:
                        statia_sector_2.colecteaza_tot_gunoiul();
                        break;
                    case 4:
                        StatieSortare::afiseaza_statistici();
                        break;
                    case 5:
                        in_meniu_admin = false;
                        break;
                    default:
                        std::cout << "Optiune invalida!\n";
                }
            }
        } else {
            std::cout << "Rol invalid!\n";
        }
    }

    std::cout << "\n[SISTEM OPRIT] Va multumim ca pastrati orasul curat!\n";
    return 0;
}
