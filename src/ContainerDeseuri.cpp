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

void ContainerDeseuri::adauga_deseuri(float cantitate) {
    if (grad_umplere + cantitate > capacitate_maxima) {
        throw EroareSuprasolicitare("Eroare! Containerul " + std::to_string(id) + " a atins capacitatea maxima.");
    }

    grad_umplere += cantitate;
    std::cout << "[Sistem] S-au adaugat " << cantitate << " kg in containerul cu ID: " << id << "\n";
}

float ContainerDeseuri::goleste() {
    float cantitate_colectata = grad_umplere;
    grad_umplere = 0.0f;
    return cantitate_colectata;
}
