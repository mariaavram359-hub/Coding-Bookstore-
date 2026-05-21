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
        if (container->este_in_mentenanta()) {
            std::cout << "[Mentenanta] Se repara containerul...\n";
            container->scoate_din_mentenanta();
        } else {
            container->afiseaza();
            if (dynamic_cast<ContainerBiodegradabile*>(container) != nullptr)
                std::cout << "  -> [Actiune]: Se igienizeaza containerul biodegradabil!\n";
            else if (dynamic_cast<ContainerElectronice*>(container) != nullptr)
                std::cout << "  -> [Actiune]: Se calibreaza senzorul de scurgeri toxice!\n";
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

ContainerDeseuri* StatieSortare::operator[](size_t index) const {
    if (index >= flota_containere.size()) {
        throw std::out_of_range("Eroare de indexare: Nu exista niciun container la pozitia " + std::to_string(index));
    }
    return flota_containere[index];
}

void StatieSortare::afiseaza_rezumat() const {
    std::cout << "\n--- REZUMAT FLOTA --- \n";
    for (const ContainerDeseuri* container : flota_containere) {
        std::cout << *container << "\n";
    }
    std::cout << "---------------------\n";
}

float StatieSortare::calculeaza_scor_sustenabilitate() const {
    if (flota_containere.empty()) return 100.0f;

    float scor = 100.0f;

    float capacitate_totala = 0.0f;
    float umplere_totala = 0.0f;

    for (const ContainerDeseuri* container : flota_containere) {
        float capacitate = container->get_capacitate_maxima();
        float umplere = container->get_grad_umplere();
        float procent = (capacitate > 0) ? (umplere / capacitate) * 100.0f : 0.0f;

        capacitate_totala += capacitate;
        umplere_totala += umplere;

        if (procent > 80.0f)
            scor -= 15.0f;
    }

    float penalizare_carbon = total_reciclat / 10.0f;
    if (penalizare_carbon > 30.0f)
        penalizare_carbon = 30.0f;
    scor -= penalizare_carbon;

    if (capacitate_totala > 0) {
        float rata_utilizare = (umplere_totala / capacitate_totala) * 100.0f;
        if (rata_utilizare < 50.0f)
            scor += 10.0f;
    }

    if (scor < 0.0f) scor = 0.0f;
    if (scor > 100.0f) scor = 100.0f;

    return scor;
}

void StatieSortare::colectare_automata() const {
    std::cout << "\n--- VERIFICARE AUTOMATA CONTAINERE ---\n";
    bool a_fost_colectat_ceva = false;

    for (ContainerDeseuri* container : flota_containere) {
        if (container->necesita_colectare()) {
            float colectat = container->goleste();
            total_reciclat += colectat;
            std::cout << "[AUTO] Container depasit pragul! Au fost colectate " << colectat << " kg.\n";
            a_fost_colectat_ceva = true;
        }
    }

    if (!a_fost_colectat_ceva)
        std::cout << "[AUTO] Niciun container nu a atins pragul de colectare.\n";

    std::cout << "--- VERIFICARE FINALIZATA ---\n";
}
