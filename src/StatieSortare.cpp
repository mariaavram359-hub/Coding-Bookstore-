#include "StatieSortare.h"
#include "ContainerPlastic.h"
#include "ContainerBiodegradabile.h"
#include "ContainerElectronice.h"
#include <iostream>
#include <utility>
#include <algorithm>

StatieSortare::StatieSortare(const StatieSortare& alta_statie) {
    for (const ContainerDeseuri* container : alta_statie.flota_containere) {
        this->flota_containere.push_back(container->clone());
    }
    std::cout << "[Sistem] S-a creat o copie la indigo (Deep Copy) a flotei.\n";
}

void StatieSortare::swap(StatieSortare& alta_statie) noexcept {
    using std::swap;
    swap(this->flota_containere, alta_statie.flota_containere);
}

StatieSortare& StatieSortare::operator=(StatieSortare alta_statie) {
    this->swap(alta_statie);
    return *this;
}

float StatieSortare::total_reciclat = 0.0f;

StatieSortare::~StatieSortare() {
    for (ContainerDeseuri* container : flota_containere) {
        delete container;
    }
    flota_containere.clear(); // Golim vectorul
}

void StatieSortare::adaugaContainer(ContainerDeseuri *container) {
    flota_containere.push_back(container);
}

void StatieSortare::mentenanta_rutina() const {
    std::cout << "\n--- INCEPERE RUTINA MENTENANTA ---\n";

    for (ContainerDeseuri* container : flota_containere) {

        container->afiseaza();

        if (dynamic_cast<ContainerBiodegradabile*>(container) != nullptr) {
            std::cout << "  -> [Actiune Mentenanta]: Se igienizeaza si se raceste containerul biodegradabil!\n";
        }
        else if (dynamic_cast<ContainerElectronice*>(container) != nullptr) {
            std::cout << "  -> [Actiune Mentenanta]: Se calibreaza senzorul de scurgeri toxice!\n";
        }

    }
    std::cout << "--- RUTINA FINALIZATA ---\n";
}

void StatieSortare::afiseaza_statistici() {
    std::cout << "====================================\n";
    std::cout << "STATISTICI GLOBALE CARTIER:\n";
    std::cout << "Total deseuri procesate: " << total_reciclat << " kg\n";
    std::cout << "====================================\n";
}

void StatieSortare::sorteaza_dupa_umplere() {
    std::ranges::sort(flota_containere,
                      [](const ContainerDeseuri* a, const ContainerDeseuri* b) {
                          return a->get_grad_umplere() > b->get_grad_umplere();
                      });

    std::cout << "\n[Sistem Optimizare] Flota a fost sortata: Masina va merge intai la cele mai pline containere.\n";
}

void StatieSortare::colecteaza_tot_gunoiul() const {
    std::cout << "\n--- TRIMITERE MASINA DE GUNOI ---\n";
    float cantitate_tura_curenta = 0.0f;

    for (ContainerDeseuri* container : flota_containere) {
        float colectat = container->goleste();

        cantitate_tura_curenta += colectat;
    }

    total_reciclat += cantitate_tura_curenta;

    std::cout << "[Sistem] Masina a colectat " << cantitate_tura_curenta << " kg in aceasta tura.\n";
    std::cout << "--- COLECTARE FINALIZATA ---\n\n";
}
