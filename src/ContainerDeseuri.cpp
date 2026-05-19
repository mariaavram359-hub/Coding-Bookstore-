#include <ContainerDeseuri.h>
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

