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

void ContainerDeseuri::adauga_deseuri(float cantitate, const std::string& tip_deseu_aruncat) {
    if (tip_deseu_aruncat != tip_acceptat) {
        // Dacă nu se potrivesc, trapa rămâne închisă și aruncăm excepția nouă!
        throw EroareTipDeseu("Trapa blocata! Nu puteti arunca [" + tip_deseu_aruncat + "] intr-un container pentru [" + tip_acceptat + "].");
    }

    if (grad_umplere + cantitate > capacitate_maxima) {
        throw EroareSuprasolicitare("Eroare! Containerul " + std::to_string(id) + " a atins capacitatea maxima.");
    }

    grad_umplere += cantitate;
    std::cout << "[Sistem Trapa] S-au adaugat " << cantitate << " kg de " << tip_deseu_aruncat << " in containerul "
    << id << ".\n";
}

float ContainerDeseuri::goleste() {
    float cantitate_colectata = grad_umplere;
    grad_umplere = 0.0f;
    return cantitate_colectata;
}

float ContainerDeseuri::get_grad_umplere() const {
    return grad_umplere;
}