#include "ContainerDeseuri.h"
#include "Exceptii.h"
#include <iostream>
#include <utility>

ContainerDeseuri::ContainerDeseuri(const int id_container, std::string locatie_container, float capacitate_maxima_container)
    :id(id_container), locatie(std::move(locatie_container)), capacitate_maxima(capacitate_maxima_container), grad_umplere(0.0f) {
}

void ContainerDeseuri::afiseaza() const {
    std::cout << "\n";
    std::cout << "SMART CONTAINER\n";
    std::cout << "ID: " << id << "\n";
    std::cout << "Locatie: " << locatie << "\n";
    std::cout << "Grad de umplere: " << grad_umplere << " / " << capacitate_maxima << " kg\n";

    afiseaza_impl();

    std::cout << "\n";
}

void ContainerDeseuri::adauga_deseuri(const Deseu& deseu_aruncat) {
    float cantitate_primita = deseu_aruncat.get_cantitate();
    std::string tip_primit = deseu_aruncat.get_tip();

    if (cantitate_primita <= 0) {
        throw EroareCantitateInvalida("Eroare Logica: Cantitatea de deseuri introdusa (" +
                                      std::to_string(cantitate_primita) +
                                      " kg) trebuie sa fie strict pozitiva!");
    }

    if (tip_primit != tip_acceptat) {

        throw EroareTipDeseu("Trapa blocata! Nu puteti arunca [" + tip_primit + "] intr-un container pentru [" + tip_acceptat + "].");
    }

    if (grad_umplere + cantitate_primita > capacitate_maxima) {
        throw EroareSuprasolicitare("Eroare! Containerul " + std::to_string(id) + " a atins capacitatea maxima.");
    }

    grad_umplere += cantitate_primita;
    std::cout << "[Sistem Trapa] Au fost adaugate " << cantitate_primita << " kg de " << tip_primit << ".\n";
    std::cout << " -> Timp estimat descompunere: " << deseu_aruncat.timp_descompunere_ani() << " ani.\n";
    std::cout << " -> Amprenta de carbon generata: " << deseu_aruncat.calculeaza_amprenta_carbon() << " kg CO2.\n";
}

float ContainerDeseuri::goleste() {
    float cantitate_colectata = grad_umplere;
    grad_umplere = 0.0f;
    return cantitate_colectata;
}

float ContainerDeseuri::get_grad_umplere() const {
    return grad_umplere;
}

ContainerDeseuri& ContainerDeseuri::operator+=(const Deseu& deseu_aruncat) {
    this->adauga_deseuri(deseu_aruncat);
    return *this;
}

std::ostream& operator<<(std::ostream& os, const ContainerDeseuri& container) {
    os << "[Rezumat Container] ID: " << container.id
       << " | Tip: " << container.tip_acceptat
       << " | Umplere: " << container.grad_umplere << "/" << container.capacitate_maxima << " kg";
    return os;
}

